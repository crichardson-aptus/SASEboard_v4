/* 
 * File:   SASE_Init.h
 * Author: APTUSM6
 *
 * Created on April 14, 2021, 3:40 PM
 */

#ifndef SASE_INIT_H
#define	SASE_INIT_H


#define AutecAddress1       0x18A
#define AutecAddress2       0x28A
#define AutecAddress3       0x38A
#define AutecAddress4       0x20A
#define AutecAddress5       0x30A
#define ATOaddress1         0x1801D0E5
#define ATOaddress2         0x1801E5D0
#define VFDaddress          0x400
#define InactiveTime        1800000
#define BatteryVcutoff      38


#ifdef	__cplusplus
extern "C" {
#endif
    
    
    void SASE_Initialize(void);
    void M_8KR(void);
    void M_3K(void);
    
    ///Supporting functions///
    void MachineLogic(void);
    void JoystickLogic(void);
    void SetDriveSpeed(void);
    void SetWheelDirection(void);
    void VFDlogic(void);
    void Tmr1_ISR(void);
    void Tmr3_ISR(void);
    void CAN_Rx(void);
    void CAN_Tx(int MachID);

#ifdef	__cplusplus
}
#endif

#endif	/* SASE_INIT_H */

