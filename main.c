/* SASE Machine Control Program */

//#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/mcc.h"
#include "SASE/BasicFunctions.h"
#include "SASE/SASE.h"

void GetDip(void);
void Testing(void);

uint16_t Dip = 0x00;

//GIT TEST 2

/*
                         Main application
 */
int main(void) {
    //Initialize system and start interrupt
    SYSTEM_Initialize();
    TMR1_SetInterruptHandler(Tmr1_ISR);
    TMR3_SetInterruptHandler(Tmr3_ISR);
    //FatFsDemo_Tasks();
    
    
    
    //Main loop
    while(1){
        //Flash LEDs 
        LED_Loading(200);
        LED1_SetHigh();
        GetDip();
        
        
        switch (Dip){
            case 0x00:
                M_8KR();
                break;
            case 0x01:
                M_3K();
                break;
            case 0x02:
                Testing();
                break;
            default:
                LED_FlashAll(3);
                delay_ms(5000);
        }
    }
    return 1;
}



//Testing
void Testing(void){
    while(1){
        PWM_DutyCycleSet(HeadSpeed_PWM, 0x55);
        delay_ms(200);
        PWM_DutyCycleSet(HeadSpeed_PWM, 0xEE);
        delay_ms(200);
              
    }
}

void GetDip(void){
    
    Dip = 0x00;
    if(!Dip1_GetValue())
    {
        Dip = 0x01;
    }
    
    if(!Dip2_GetValue())
    {
        Dip = Dip + 0x02;
    }
    
    if(!Dip3_GetValue())
    {
        Dip = Dip + 0x04;
    }
    
    if(!Dip4_GetValue())
    {
        Dip = Dip + 0x08;
    } 
}



/**
 End of File
 */

