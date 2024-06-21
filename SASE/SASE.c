/*
 * File:   M_8kR.c
 * Author: APTUSM6
 *
 * Created on April 14, 2021, 1:02 PM
 */


#include <xc.h>
#include "../mcc_generated_files/mcc.h"
#include "BasicFunctions.h"
#include "GrayhillKeypad.h"



bool Forward, Backward, TurnRight, TurnLeft, Start, Reset, Jog, TransportMode, 
        GrindMode, GrindModeOld, ForwardS, ReverseS, LightSW, GrindLeft, 
        GrindRight, SwitchActive, JoystickActive, 
        DriveBack, flag, Grinding, TxFlag, GrindChangeDirR, GrindChangeDirL, 
        CAN_Received, StartRamp, GrindCW, GrindCCW, TrimR, TrimL, TorqueFault, 
        MotorReset, ManualGrinding, ManualGrindL, ManualGrindR, TxRx, MachSafe,
        EStopFlash;


uint8_t FeetPerMin, MachID, MachineControl, MotorStatus, MotorTemp, MotorRPM, 
        MotorFault, ControllerTemp, Acceleration, MotorSpeedLT, GrayhillBtn,
        GrayhillLts;
uint16_t JoystickY, JoystickX, GrindSpeed, YSpeed, XSpeed, Trim, 
        HeadSpeedHz, freq, TorqueFaultTmr, DriveSpeedOG, 
        HeadAmps, RPM, HeadSpeed3k;

uint16_t RemoteLEDs[2] = {0};

int LeftDrive, RightDrive, RampTM, CAN_RxTmr, LeftMotorToque, RightMotorToque,
        LowVoltageTMR, BatteryV, HeadSpeed;

float DriveSpeedPer, DriveSpeed, DriveSpeedRamp, X_Percent;

uint32_t i, TMR_1us, ActiveTMR, OnTimeMs, FlashMS, StartDelayTmr, Tmr3Time, 
        CAN_Tmr, GetCAN;

CAN_MSG_OBJ RxMsg;
GRAYHILL_KEYPAD_OBJ keypad;


uint8_t Packet1[8] = {0};
uint16_t Packet2[8] = {0};
uint16_t Packet3[8] = {0};
uint8_t data[8] = {0};




void SASE_Initialize(void) {
    OnTimeMs = 0;
   
    RxMsg.msgId = 0x0000;
    RxMsg.data = data;
    
    // drive the CAN STANDBY driver pin low
    _TRISG9 = 0;
    _LATG9 = 0;
    _TRISF1 = 0;
    _TRISF0 = 1;
    
    MachSafe = true;
    CAN1_ReceiveEnable();  
    CAN1_TransmitEnable();
    ADC1_Enable();
    ADC1_SoftwareTriggerEnable();
    CAN1_OperationModeSet(CAN_CONFIGURATION_MODE);
    if (CAN_CONFIGURATION_MODE == CAN1_OperationModeGet()) {
        CAN1_OperationModeSet(CAN_NORMAL_2_0_MODE);
    }
    keypad.brightness = 0xFF;
    return;
}



//Functions
void MachineLogic(void) {
    //Get Estop input
    if(SafetyInput_GetValue()){
        if(((Start || Reset) && !TransportMode && !GrindMode)){
            MachSafe = true;
        }
    } else {
        MachSafe = false;     
    }
    
    
    //Flash lights on remote if Mach not safe
    if((MachSafe == false) && (OnTimeMs > FlashMS)){
        FlashMS = OnTimeMs + 500;
        RemoteLEDs[0] = ~RemoteLEDs[0];
        RemoteLEDs[1] = ~RemoteLEDs[1];
//        EStopFlash = !EStopFlash;
    }  
    
    //Turn off lights on remote if Mach safe
    if(MachSafe){
        RemoteLEDs[0] = 0x00;
        RemoteLEDs[1] = 0x00;
        EStopFlash = 0;
    }
    
    
    //Light switch
    if (LightSW || EStopFlash) {
        Lights_SetHigh();
    } else {
        Lights_SetLow();
    }

    //Enable Servos
    if (MachSafe && (TransportMode || GrindMode) && !Reset && (LeftDrive >= 0x0A || RightDrive >= 0x0A)){ 
        Motor_Enable_SetHigh();
    } else {
        Motor_Enable_SetLow();
    }

    //Switch Active
    if (ForwardS || ReverseS) {
        SwitchActive = 1;
    } else {
        SwitchActive = 0;
    }

    //Joystick Active
    if (Forward || Backward || TurnRight || TurnLeft) {
        JoystickActive = true;
    } else {
        JoystickActive = false;
    }

    //Drive in reverse
    if ((ReverseS && !Forward) || Backward) {
        DriveBack = true;
    } else {
        DriveBack = false;
    }
    
    //Motor Power
    LeftMotorToque = ADC1_ConversionResultGet(L_Sdata);
    RightMotorToque = ADC1_ConversionResultGet(R_Sdata);
    BatteryV = ADC1_ConversionResultGet(BatVoltage);

    //Drive Motor fault
    if (LeftDrive > 0x0A && (LeftMotorToque > 0x126 && LeftMotorToque < 0x128)) {
        TorqueFault = true;
    } else if (RightDrive > 0x0A && (RightMotorToque > 0x126 && RightMotorToque < 0x128)) {
        TorqueFault = true;
    } else{
        TorqueFault = false;
    }
        

    //Fault debouncer
    if (TorqueFault) {
        TorqueFaultTmr++;
    } else {
        TorqueFaultTmr = 0;
    }
        
    if (TorqueFaultTmr >= 500) {
        TorqueFaultTmr = 0;
        MotorReset = true;
    } else {
        MotorReset = false;
    }
    
    //Power off
    if(ActiveTMR > InactiveTime){
        PowerOn_SetLow();
    }
        
}

void JoystickLogic(void) {
    //Normalize X and Y Speed
    DriveSpeed = abs(DriveSpeedOG - 0x007F) * 2;
    
    //Logic for if it needs to ramp speed
    if (GrindMode && !GrindModeOld || Reset || Start) {
        StartRamp = 1;
        RampTM = 0;
        DriveSpeedRamp = 0;
    }
    GrindModeOld = GrindMode;
    
    if(!JoystickActive && (TrimL || TrimR)){
        JoystickX = Trim;
    }
    
    DriveSpeedPer = DriveSpeed / 255;
    FeetPerMin = 63 * DriveSpeedPer;
    YSpeed = abs(JoystickY - 0x007F)*2 * DriveSpeedPer;
    XSpeed = abs(JoystickX - 0x007F)*2 * DriveSpeedPer;

    if (YSpeed >= 0xF0){
        YSpeed = 0xF0;
    }
    if (YSpeed <= 0x00){
        YSpeed = 0x00;
    }

    if (XSpeed >= 0xF0){
        XSpeed = 0xF0;
    }
    if (XSpeed <= 0x00){
        XSpeed = 0x00;
    }


    //Set Y direction speed
    if ((TransportMode || GrindMode) && (Forward || Backward)) {
        LeftDrive = YSpeed;
        RightDrive = YSpeed;
    }//Set drive speed for normal grinding operation
    else if (GrindMode && !JoystickActive && SwitchActive && !TrimL && !TrimR) {
        if(StartRamp){
            LeftDrive = DriveSpeedRamp;
            RightDrive = DriveSpeedRamp;
        } else{
            LeftDrive = DriveSpeed;
            RightDrive = DriveSpeed;
        }
        GrindChangeDirL = false;
        GrindChangeDirR = false;
    }//Set turning speed for grinding 
    else if (GrindMode && !Forward && !Backward && (TurnRight || TurnLeft || TrimL || TrimR)) {
        if ((ForwardS && (TurnRight || (TrimR && !JoystickActive))) || (ReverseS && (TurnLeft || (TrimL && !JoystickActive)))) {
            
            LeftDrive = DriveSpeed;
            RightDrive = DriveSpeed - XSpeed * 2;
            if (RightDrive < 0) {
                RightDrive = abs(RightDrive);
                GrindChangeDirR = true;
            } else
                GrindChangeDirR = false;
        } else if ((ForwardS && (TurnLeft || (TrimL && !JoystickActive))) || (ReverseS && (TurnRight || (TrimR && !JoystickActive)))) {
            
            RightDrive = DriveSpeed;
            LeftDrive = DriveSpeed - XSpeed * 2;
            if (LeftDrive < 0) {
                LeftDrive = abs(LeftDrive);
                GrindChangeDirL = true;
            } else
                GrindChangeDirL = false;
        }
    }//Set turning speed
    else if (!Forward && !Backward && TransportMode) {
        if (TurnRight){
            LeftDrive = XSpeed;
            RightDrive = 0x00;
        }
        else if (TurnLeft){
            RightDrive = XSpeed;
            LeftDrive = 0x00;
        }
        else {
            LeftDrive = 0x00;
            RightDrive = 0x00;
        }
    }//Set speed back to 0
    else {
        LeftDrive = 0x00;
        RightDrive = 0x00;
    }
    
    //Set multi direction speed
    if ((TransportMode || GrindMode) && ((Forward && TurnRight) || (Backward && TurnLeft))) {
        LeftDrive = YSpeed + XSpeed;
        if (LeftDrive >= 0xF0){
            LeftDrive = 0xF0;
            RightDrive = YSpeed - XSpeed;
        }
    }
    else if ((TransportMode || GrindMode) && ((Forward && TurnLeft) || (Backward && TurnRight))) {
        RightDrive = YSpeed + XSpeed;
        if (RightDrive >= 0xF0){
            RightDrive = 0xF0;
            LeftDrive = YSpeed - XSpeed;
        }
    }

    if (LeftDrive <= 0){
        LeftDrive = 0;
    }
    if (RightDrive <= 0){
        RightDrive = 0;
    }
}

void SetDriveSpeed(void) {

    //Left Drive
    if (MachSafe && (TransportMode || GrindMode) && LeftDrive >= 0x0A) {
        if (LeftDrive >= 0xF0){
            LeftDrive = 0xF0;
        }
        PWM_Enable();
        PWM_DutyCycleSet(LeftMotor_PWM, LeftDrive);
    } else{
        PWM_DutyCycleSet(LeftMotor_PWM, 0x00);
    }

    //Right Drive
    if (MachSafe && (TransportMode || GrindMode) && RightDrive >= 0x0A) {
        if (RightDrive >= 0xF0){
            RightDrive = 0xF0;
        }
        PWM_Enable();
        PWM_DutyCycleSet(RightMotor_PWM, RightDrive);
    } else{
        PWM_DutyCycleSet(RightMotor_PWM, 0x00);
        
    }
}

void SetWheelDirection(void) {
    //Right wheel direction
    if ((DriveBack && !GrindChangeDirR) || (ForwardS && GrindChangeDirR)){
        RightWheelDir_SetLow();
    } else{
        RightWheelDir_SetHigh();
    }

    //Left wheel direction
    if ((DriveBack && !GrindChangeDirL) || (ForwardS && GrindChangeDirL)){
        LeftWheelDir_SetLow();
    } else{
        LeftWheelDir_SetHigh();
    }
}

void VFDlogic(void) {
    //Normalize HeadSpeed
    if(!Manual_EN_GetValue()){
//        LED1_SetHigh();
        HeadSpeed = ADC1_ConversionResultGet(HandlePot);
        if(HeadSpeed > 0x1AC){ //was 0xAA
            ManualGrindR = 1;
            ManualGrindL = 0;
        } else if(HeadSpeed < 0x1AC){   //0xAA
            ManualGrindL = 1;
            ManualGrindR = 0;
        } else {
            ManualGrindL = 0;
            ManualGrindR = 0;
        }
        HeadSpeed = abs(HeadSpeed - 0x1AC); //0xAA
        
        //Start and stop manual grinding
        if(!Man_start_GetValue() && (StartDelayTmr < OnTimeMs)){
            ManualGrinding = !ManualGrinding;
            StartDelayTmr = OnTimeMs + 2000;
        } 
    }else{
        HeadSpeed = abs(GrindSpeed - 0x007F)*2;
        ManualGrinding = 0;
        ManualGrindL = 0;
        ManualGrindR = 0;
    }
    if(HeadSpeed < 5){
        HeadSpeed = 0x00;
    }
    
    //Calc rpm speed for remote
    RPM = abs(GrindSpeed - 0x007F)/18;
 
    //Read head current
    HeadAmps = ADC1_ConversionResultGet(HeadCurrent);
    
    //Set head speed
    if(MachSafe && Jog){
        PWM_DutyCycleSet(HeadSpeed_PWM, 0x14);
    } else
        PWM_DutyCycleSet(HeadSpeed_PWM, HeadSpeed);

    //Set head direction and start motor
    if ((MachSafe && ((GrindCW && (GrindMode || Jog) && (ForwardS || ReverseS)))) || (ManualGrinding && ManualGrindR)){//((GrindCW && (GrindMode || Jog) && (ForwardS || ReverseS)) || (ManualGrinding && ManualGrindR)){
        FWD_SetHigh(); 
    } else{
        FWD_SetLow(); 
    }
    
    if ((MachSafe && ((GrindCCW && (GrindMode || Jog) && (ForwardS || ReverseS)))) || (ManualGrinding && ManualGrindL)){//((GrindCCW && (GrindMode || Jog) && (ForwardS || ReverseS))|| (ManualGrinding && ManualGrindL)){
        REV_SetHigh(); 
    } else{
        REV_SetLow(); 
    }
    
}

void CAN_Rx(void) {
    i = 0;
    while (i < 50) {
        if (CAN1_ReceivedMessageCountGet() > 0) {
            if (true == CAN1_Receive(&RxMsg)) {
                CAN_Received = true;
                CAN_RxTmr = 0;
                break;
            }
        }
        i++;
    }

    //Clear out CAN message after half a second of no new messages
//    if(OnTimeMs >(CAN_Tmr + 500)){
//        CAN_Received = true;
//        uint8_t ClearData[8] = {0};
//        RxMsg.data = ClearData;
//    }
    
    if (CAN_Received) {
        switch(RxMsg.msgId){
//            case AutecAddress1:
//                for (i = 0; i < 8; i++) {
//                    Packet1[i] = *(RxMsg.data + i);
//                }
//
//                Forward = Packet1[0] & 0x01;
//                TurnRight = (Packet1[0] & 0x02) >> 0x01;
//
//                Backward = Packet1[1] & 0x01;
//                TurnLeft = (Packet1[1] & 0x02) >> 0x01;
//
//                Start = Packet1[2] & 0x01;
//                Reset = (Packet1[2] & 0x02) >> 0x01;
//                Jog = (Packet1[2] & 0x04) >> 0x02;
//                TransportMode = (Packet1[2] & 0x08) >> 0x03;
//                GrindMode = (Packet1[2] & 0x10) >> 0x04;
//                ForwardS = (Packet1[2] & 0x20) >> 0x05;
//                ReverseS = (Packet1[2] & 0x40) >> 0x06;
//                LightSW = (Packet1[2] & 0x80) >> 0x07;
//
//                GrindCW = Packet1[3] & 0x01;
//                GrindCCW = (Packet1[3] & 0x02) >> 0x01;
//                TrimR = (Packet1[3] & 0x04) >> 0x02;
//                TrimL = (Packet1[3] & 0x08) >> 0x03;
//                break;
                
            case AutecAddress2:
                for (i = 0; i < 8; i++) {
                    Packet2[i] = *(RxMsg.data + i);
                }
                JoystickY = Packet2[0];
                JoystickX = Packet2[1];
                GrindSpeed = Packet2[2];
                Trim = Packet2[3];
                break;
                
            case AutecAddress3:
                for (i = 0; i < 8; i++) {
                    Packet3[i] = *(RxMsg.data + i);
                }
                DriveSpeedOG = Packet3[0];
                break;
                
            case ATOaddress1:
                for (i = 0; i < 8; i++) {
                    Packet1[i] = *(RxMsg.data + i);
                }
                BatteryV = Packet1[0];      //1V/bit
                HeadAmps = Packet1[1];      //1A/bit
                MotorStatus = Packet1[2];   //see manual
                MotorTemp = Packet1[3];     //1C/bit with -40C offset
                MotorRPM = Packet1[4] >> 0x08;  //Probably not right, 1RPM/bit
                MotorRPM = Packet1[5];      
                MotorFault = Packet1[6];    //see manual
                ControllerTemp = Packet1[7];    //1C/bit with -40C offset
                break;
                
            case GrayhilladdressRX1:
                for (i = 0; i < 8; i++) {
                    Packet1[i] = *(RxMsg.data + i);
                }
                GrayhillBtn = Packet1[0];
                keypad.upButton = Packet1[0] & 0x01;
                keypad.downButton = Packet1[0] & 0x10;
                keypad.clockwiseButton = Packet1[0] & 0x02;
                keypad.counterClockwiseButton = Packet1[0] & 0x20;
                keypad.stopButton = Packet1[0] & 0x04;
                
                if(keypad.upButton){
                    HeadSpeed++;
                    keypad.lights = keypad.lights << 0x0001;
                    keypad.lights++;
                }
                
                if(keypad.downButton){
                    HeadSpeed--;
                    keypad.lights = keypad.lights >> 0x0001;
//                    keypad.lights--;
                }
                
//                 Start = Packet1[2] & 0x01;
//                Reset = (Packet1[2] & 0x02) >> 0x01;
//                Jog = (Packet1[2] & 0x04) >> 0x02;
//                TransportMode = (Packet1[2] & 0x08) >> 0x03;
//                GrindMode = (Packet1[2] & 0x10) >> 0x04;
//                ForwardS = (Packet1[2] & 0x20) >> 0x05;
//                ReverseS = (Packet1[2] & 0x40) >> 0x06;
//                LightSW = (Packet1[2] & 0x80) >> 0x07;
                
               
                break;
                
            case 0x18FF11F2:
                LED3_SetHigh();
                break;
                
                
                
            default:
                LED_Flash(2, 100, 3);         
        }
        
        CAN_Received = false;
    }
}

void CAN_Tx(int MachID){
    
    CAN_MSG_OBJ TxMsg;
    uint8_t TxData[8] = {0};
    
    if(GrindCW){
        TxMsg.msgId = 0x18EF0007;
        TxData[0] = 0xb0;   //Battery Voltage
        TxData[1] = 0x01; //Head Current
        TxData[2] = 0x01; //Feet Per Min
        TxMsg.field.frameType = CAN_FRAME_DATA;
        TxMsg.field.idType = CAN_FRAME_EXT;
        TxMsg.field.dlc = CAN_DLC_8;
        TxMsg.data = TxData;
        
        CAN1_Transmit(CAN_PRIORITY_HIGH, &TxMsg);
        
    }
   

    switch(MachID){
        case 1:
//            TxFlag = 1;
            if(TxFlag){
                
                TxMsg.msgId = 0x20A; //AutecAddress4;
                TxData[0] = (30 * BatteryV / 1024)+3;   //Battery Voltage
                TxData[1] = HeadAmps;                   //Head Current
                TxData[2] = FeetPerMin;                 //Feet Per Min
                TxData[3] = RPM >> 0x08;                //Head Speed(0-3)
                TxData[4] = RPM;                        //Head Speed(4-7)
                //////////////////////////////
                TxData[0] = keypad.lights;
                TxData[1] = keypad.lights >> 0x08;
                TxData[2] = 0xFE;  
                TxData[3] = 0x00;
                TxData[4] = 0x00;
                TxData[5] = 0x00;                       
                TxData[6] = 0x00;
                TxData[7] = 0x00;
                //////////////////////////////
                TxMsg.field.frameType = CAN_FRAME_DATA;
                TxMsg.field.idType = CAN_FRAME_STD;
                TxMsg.field.dlc = CAN_DLC_8;
                TxMsg.data = TxData;
            } else {
                //Tx LED data
                TxMsg.msgId = 0x18A; //AutecAddress5;
                TxData[0] = RemoteLEDs[0]; //LEDs on the left
                TxData[1] = RemoteLEDs[1]; //LEDs on the right
                TxData[0] = 0x00; //LEDs on the left
                TxData[1] = 0x00;
                TxData[2] = 0x00;
                TxData[3] = 0x00;
                TxData[4] = 0x00;
                TxData[5] = 0x00;
                TxData[6] = 0x00;
                TxMsg.field.frameType = CAN_FRAME_DATA;
                TxMsg.field.idType = CAN_FRAME_STD;
                TxMsg.field.dlc = CAN_DLC_8;
                TxMsg.data = TxData;
            }
            
            
            TxFlag = !TxFlag;
            
            CAN1_Transmit(CAN_PRIORITY_HIGH, &TxMsg);
            break;
            
        case 2:
            if(TxFlag){
                TxMsg.msgId = ATOaddress2;
                TxData[0] = HeadSpeed3k;            //Speed(low byte)
                TxData[1] = HeadSpeed3k >> 0x08;    //Speed(high byte)
                TxData[2] = Acceleration;           //Acceleration: 20RPM/bit
                TxData[3] = MachineControl;         //0-1output enable, 2-3 direction control
                /////////////////////////////////////////////////////
                TxMsg.msgId = GrayhilladdressTX2;
                TxData[0] = keypad.brightness;
                
                TxMsg.field.frameType = CAN_FRAME_DATA;
                TxMsg.field.idType = CAN_FRAME_STD;
                TxMsg.field.dlc = CAN_DLC_8;
                TxMsg.data = TxData;
            }
            else{
                TxMsg.msgId = GrayhilladdressTX1; //AutecAddress4;
                TxData[0] = (30 * BatteryV / 1024)+3;   //Battery Voltage
                TxData[1] = HeadAmps;                   //Head Current
                TxData[2] = FeetPerMin;                 //Feet Per Min
                TxData[3] = RPM >> 0x08;                //Head Speed(0-3)
                TxData[4] = RPM;                        //Head Speed(4-7)
                //////////////////////////////
                TxData[0] = keypad.lights;
                TxData[1] = keypad.lights >> 0x08;
                TxData[2] = 0x00;  
                TxData[3] = 0x00;
                TxData[4] = 0x00;
                TxData[5] = 0x00;                       
                TxData[6] = 0x00;
                TxData[7] = 0x00;
                //////////////////////////////
                TxMsg.field.frameType = CAN_FRAME_DATA;
                TxMsg.field.idType = CAN_FRAME_STD;
                TxMsg.field.dlc = CAN_DLC_8;
                TxMsg.data = TxData;
            }

                TxFlag = !TxFlag;
            
            CAN1_Transmit(CAN_PRIORITY_HIGH, &TxMsg);
            break;
            
        case 3:
            TxMsg.msgId = 0x000;
            TxData[0] = 0x01;
            TxData[1] = 0x00;
            TxMsg.field.frameType = CAN_FRAME_DATA;
            TxMsg.field.idType = CAN_FRAME_STD;
            TxMsg.field.dlc = CAN_DLC_2;
            TxMsg.data = TxData;
            CAN1_Transmit(CAN_PRIORITY_HIGH, &TxMsg);
            
        default:
            LED_Flash(3,100,3);
    }
    
        
}

void Tmr1_ISR(void) {
    //Running Tmr
    OnTimeMs++;
    
    //RampUp Head speed
    if (StartRamp) {
        RampTM++;
        if (RampTM > 1000){ //wait for 1sec, then start ramp
            DriveSpeedRamp = DriveSpeed*(RampTM-1000)/4000;
        }

        if (RampTM > 5000){ //Stop ramp after 4sec
            StartRamp = 0;
        }
    }
    
    //Power off timer
    if(GrindMode || JoystickActive){
        ActiveTMR = 0;
    } else {
        ActiveTMR++;
    }
    
    //Low Voltage timer
    if(BatteryV < 0xF5){
        LowVoltageTMR++; 
    } else {
        LowVoltageTMR = 0;
    }
}

void Tmr3_ISR(void){
    Tmr3Time++;
}



//8KR
void M_8KR(void){
    LED_Flash(1, 100, 3);
    MachID = 1;

    SASE_Initialize();
    CAN1_ReceiveEnable();  
    CAN1_TransmitEnable();
    
    PowerOn_SetHigh();
    
    CAN_Tx(3);
    

    //Main loop
    while (1) {

        //Get CAN Message and set variables 
        if(GetCAN <= OnTimeMs){
            GetCAN = OnTimeMs + 250;
            CAN_Tx(MachID); 
                        
        }
        
        
        
        //CAN
        CAN_Rx();
        

        //Machine Logic
        MachineLogic();

        //Joystick Logic
        JoystickLogic();

        //Set Wheel Direction
        SetWheelDirection();

        //Set Drive Speed
        SetDriveSpeed();

        //Set VFD Logic
        VFDlogic();

    }
}


//3K
void M_3K(void){
    LED_Flash(2, 100, 3);
    LED_FlashAll(5);
    MachID = 2;
    
    SASE_Initialize();
    CAN1_ReceiveEnable();  
    CAN1_TransmitEnable();
    
    bool StartPBflag = 0;
    CAN_Tx(3);
    
    
    while(1){
        
        //Get CAN Message and set variables 
        if(GetCAN <= OnTimeMs){
            GetCAN = OnTimeMs + 50;
            CAN_Rx();
            CAN_Tx(MachID);
            
        }
        
//        if(GrayhillBtn == 0x01){
//            LED1_SetHigh();
//        } else{
//            LED1_SetLow();
//        }
        
        //MotorSpeed indicator
//        if(HeadSpeed3k < 400){
//            MotorSpeedLT = 0x00;
//        } 
//        else if(HeadSpeed3k >= 400 && HeadSpeed3k < 550){
//            MotorSpeedLT = 0x01;
//        }
//        else if(HeadSpeed3k >= 550 && HeadSpeed3k < 700){
//            MotorSpeedLT = 0x02;
//        }
//        else if(HeadSpeed3k >= 700 && HeadSpeed3k < 850){
//            MotorSpeedLT = 0x03;
//        }
//        else if(HeadSpeed3k >= 850 && HeadSpeed3k < 1000){
//            MotorSpeedLT = 0x04;
//        }
//        else if(HeadSpeed3k >= 1000 && HeadSpeed3k < 1150){
//            MotorSpeedLT = 0x05;
//        }
//        else if(HeadSpeed3k >= 1150 && HeadSpeed3k < 1300){
//            MotorSpeedLT = 0x06;
//        }
//        else if(HeadSpeed3k >= 1300){
//            MotorSpeedLT = 0x07;
//        }
        
//        bool LT = 0;
//        LT = MotorSpeedLT & 0x01;
//        if(LT){
//            LED1_SetHigh();
//        } else{
//            LED1_SetLow();
//        }
//        LT = (MotorSpeedLT & 0x02) >> 0x01;
//        if(LT){
//            
//        } else{
//            
//        }
//        LT = (MotorSpeedLT & 0x04) >> 0x02;
//        if(LT){
//            LED3_SetHigh();
//        } else{
//            LED3_SetLow();
//        }
        
            
//        Start = Packet1[2] & 0x01;
//                Reset = (Packet1[2] & 0x02) >> 0x01;
//                Jog = (Packet1[2] & 0x04) >> 0x02;
//                TransportMode = (Packet1[2] & 0x08) >> 0x03;
//                GrindMode = (Packet1[2] & 0x10) >> 0x04;
//                ForwardS = (Packet1[2] & 0x20) >> 0x05;
//                ReverseS = (Packet1[2] & 0x40) >> 0x06;
//                LightSW = (Packet1[2] & 0x80) >> 0x07;

        
//       if(BatteryV >= 0x35){
//            LED1_SetHigh();
//        }
//        else{
//            LED1_SetLow();            
//        }
        
    
        //Debounce and latch in grinding mode
//        if(!Man_start_GetValue() && StartPBflag == false && BatteryV >= BatteryVcutoff){
//            StartPBflag = true;
//            if(Grinding){
//                Grinding = 0;
//            }
//            else{
//                Grinding = 1;
//            }
//            delay_ms(100);
//        }
        
        if(Man_start_GetValue() && StartPBflag == true){
            StartPBflag = false;
        }
        
        if(keypad.clockwiseButton || keypad.counterClockwiseButton){
            Grinding = 1;
            
        }
        
        if(keypad.clockwiseButton){
            GrindCW = 1;
        }
        
        if(keypad.counterClockwiseButton){
            GrindCW = 0;
        }
        
        if(keypad.stopButton){
            Grinding = 0;
            GrindCW = 0;
        }


        //Get pot speed setting
//        HeadSpeed3k = ADC1_ConversionResultGet(HandlePot);
        HeadSpeed3k = HeadSpeed * 15;
        HeadSpeed3k = HeadSpeed3k * 12;
        if(HeadSpeed3k <= 100){
            HeadSpeed3k = 100;
        }
        
        if(HeadSpeed3k > 2000){
            HeadSpeed3k = 2000;
        }
        
        //Limit battery voltage for grinding
//        if(BatteryV < BatteryVcutoff){
//            Grinding = false;
//        }
        
        //Start grinder and set direction
        if(Grinding){
//            if(Manual_EN_GetValue() || GrindCW){
//                MachineControl = 0b00000001;
//                LED1_SetHigh();
//            }
            
            if(GrindCW){
                MachineControl = 0b00000001;
                LED1_SetHigh();
            }
            else{
                MachineControl = 0b00000101;
                LED2_SetHigh();
            }
        }
        else{
            MachineControl = 0x00;
            LED1_SetLow();
            LED2_SetLow();
        }
    }
}


/**
 End of File
 */