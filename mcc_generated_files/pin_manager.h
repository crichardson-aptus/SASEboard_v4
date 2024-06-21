/**
  PIN MANAGER Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for PIN MANAGER.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.170.0
        Device            :  dsPIC33EV32GM106
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.61
        MPLAB 	          :  MPLAB X v5.45
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#ifndef _PIN_MANAGER_H
#define _PIN_MANAGER_H
/**
    Section: Includes
*/
#include <xc.h>

/**
    Section: Device Pin Macros
*/
/**
  @Summary
    Sets the GPIO pin, RA0, high using LATA0.

  @Description
    Sets the GPIO pin, RA0, high using LATA0.

  @Preconditions
    The RA0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA0 high (1)
    R_Sdata_SetHigh();
    </code>

*/
#define R_Sdata_SetHigh()          (_LATA0 = 1)
/**
  @Summary
    Sets the GPIO pin, RA0, low using LATA0.

  @Description
    Sets the GPIO pin, RA0, low using LATA0.

  @Preconditions
    The RA0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA0 low (0)
    R_Sdata_SetLow();
    </code>

*/
#define R_Sdata_SetLow()           (_LATA0 = 0)
/**
  @Summary
    Toggles the GPIO pin, RA0, using LATA0.

  @Description
    Toggles the GPIO pin, RA0, using LATA0.

  @Preconditions
    The RA0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA0
    R_Sdata_Toggle();
    </code>

*/
#define R_Sdata_Toggle()           (_LATA0 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RA0.

  @Description
    Reads the value of the GPIO pin, RA0.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA0
    postValue = R_Sdata_GetValue();
    </code>

*/
#define R_Sdata_GetValue()         _RA0
/**
  @Summary
    Configures the GPIO pin, RA0, as an input.

  @Description
    Configures the GPIO pin, RA0, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA0 as an input
    R_Sdata_SetDigitalInput();
    </code>

*/
#define R_Sdata_SetDigitalInput()  (_TRISA0 = 1)
/**
  @Summary
    Configures the GPIO pin, RA0, as an output.

  @Description
    Configures the GPIO pin, RA0, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA0 as an output
    R_Sdata_SetDigitalOutput();
    </code>

*/
#define R_Sdata_SetDigitalOutput() (_TRISA0 = 0)
/**
  @Summary
    Sets the GPIO pin, RA1, high using LATA1.

  @Description
    Sets the GPIO pin, RA1, high using LATA1.

  @Preconditions
    The RA1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA1 high (1)
    RightWheelDir_SetHigh();
    </code>

*/
#define RightWheelDir_SetHigh()          (_LATA1 = 1)
/**
  @Summary
    Sets the GPIO pin, RA1, low using LATA1.

  @Description
    Sets the GPIO pin, RA1, low using LATA1.

  @Preconditions
    The RA1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA1 low (0)
    RightWheelDir_SetLow();
    </code>

*/
#define RightWheelDir_SetLow()           (_LATA1 = 0)
/**
  @Summary
    Toggles the GPIO pin, RA1, using LATA1.

  @Description
    Toggles the GPIO pin, RA1, using LATA1.

  @Preconditions
    The RA1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA1
    RightWheelDir_Toggle();
    </code>

*/
#define RightWheelDir_Toggle()           (_LATA1 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RA1.

  @Description
    Reads the value of the GPIO pin, RA1.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA1
    postValue = RightWheelDir_GetValue();
    </code>

*/
#define RightWheelDir_GetValue()         _RA1
/**
  @Summary
    Configures the GPIO pin, RA1, as an input.

  @Description
    Configures the GPIO pin, RA1, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA1 as an input
    RightWheelDir_SetDigitalInput();
    </code>

*/
#define RightWheelDir_SetDigitalInput()  (_TRISA1 = 1)
/**
  @Summary
    Configures the GPIO pin, RA1, as an output.

  @Description
    Configures the GPIO pin, RA1, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA1 as an output
    RightWheelDir_SetDigitalOutput();
    </code>

*/
#define RightWheelDir_SetDigitalOutput() (_TRISA1 = 0)
/**
  @Summary
    Sets the GPIO pin, RA10, high using LATA10.

  @Description
    Sets the GPIO pin, RA10, high using LATA10.

  @Preconditions
    The RA10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA10 high (1)
    Motor_Enable_SetHigh();
    </code>

*/
#define Motor_Enable_SetHigh()          (_LATA10 = 1)
/**
  @Summary
    Sets the GPIO pin, RA10, low using LATA10.

  @Description
    Sets the GPIO pin, RA10, low using LATA10.

  @Preconditions
    The RA10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA10 low (0)
    Motor_Enable_SetLow();
    </code>

*/
#define Motor_Enable_SetLow()           (_LATA10 = 0)
/**
  @Summary
    Toggles the GPIO pin, RA10, using LATA10.

  @Description
    Toggles the GPIO pin, RA10, using LATA10.

  @Preconditions
    The RA10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA10
    Motor_Enable_Toggle();
    </code>

*/
#define Motor_Enable_Toggle()           (_LATA10 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RA10.

  @Description
    Reads the value of the GPIO pin, RA10.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA10
    postValue = Motor_Enable_GetValue();
    </code>

*/
#define Motor_Enable_GetValue()         _RA10
/**
  @Summary
    Configures the GPIO pin, RA10, as an input.

  @Description
    Configures the GPIO pin, RA10, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA10 as an input
    Motor_Enable_SetDigitalInput();
    </code>

*/
#define Motor_Enable_SetDigitalInput()  (_TRISA10 = 1)
/**
  @Summary
    Configures the GPIO pin, RA10, as an output.

  @Description
    Configures the GPIO pin, RA10, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA10 as an output
    Motor_Enable_SetDigitalOutput();
    </code>

*/
#define Motor_Enable_SetDigitalOutput() (_TRISA10 = 0)
/**
  @Summary
    Sets the GPIO pin, RA11, high using LATA11.

  @Description
    Sets the GPIO pin, RA11, high using LATA11.

  @Preconditions
    The RA11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA11 high (1)
    Man_start_SetHigh();
    </code>

*/
#define Man_start_SetHigh()          (_LATA11 = 1)
/**
  @Summary
    Sets the GPIO pin, RA11, low using LATA11.

  @Description
    Sets the GPIO pin, RA11, low using LATA11.

  @Preconditions
    The RA11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA11 low (0)
    Man_start_SetLow();
    </code>

*/
#define Man_start_SetLow()           (_LATA11 = 0)
/**
  @Summary
    Toggles the GPIO pin, RA11, using LATA11.

  @Description
    Toggles the GPIO pin, RA11, using LATA11.

  @Preconditions
    The RA11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA11
    Man_start_Toggle();
    </code>

*/
#define Man_start_Toggle()           (_LATA11 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RA11.

  @Description
    Reads the value of the GPIO pin, RA11.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA11
    postValue = Man_start_GetValue();
    </code>

*/
#define Man_start_GetValue()         _RA11
/**
  @Summary
    Configures the GPIO pin, RA11, as an input.

  @Description
    Configures the GPIO pin, RA11, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA11 as an input
    Man_start_SetDigitalInput();
    </code>

*/
#define Man_start_SetDigitalInput()  (_TRISA11 = 1)
/**
  @Summary
    Configures the GPIO pin, RA11, as an output.

  @Description
    Configures the GPIO pin, RA11, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA11 as an output
    Man_start_SetDigitalOutput();
    </code>

*/
#define Man_start_SetDigitalOutput() (_TRISA11 = 0)
/**
  @Summary
    Sets the GPIO pin, RA12, high using LATA12.

  @Description
    Sets the GPIO pin, RA12, high using LATA12.

  @Preconditions
    The RA12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA12 high (1)
    Manual_EN_SetHigh();
    </code>

*/
#define Manual_EN_SetHigh()          (_LATA12 = 1)
/**
  @Summary
    Sets the GPIO pin, RA12, low using LATA12.

  @Description
    Sets the GPIO pin, RA12, low using LATA12.

  @Preconditions
    The RA12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA12 low (0)
    Manual_EN_SetLow();
    </code>

*/
#define Manual_EN_SetLow()           (_LATA12 = 0)
/**
  @Summary
    Toggles the GPIO pin, RA12, using LATA12.

  @Description
    Toggles the GPIO pin, RA12, using LATA12.

  @Preconditions
    The RA12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA12
    Manual_EN_Toggle();
    </code>

*/
#define Manual_EN_Toggle()           (_LATA12 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RA12.

  @Description
    Reads the value of the GPIO pin, RA12.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA12
    postValue = Manual_EN_GetValue();
    </code>

*/
#define Manual_EN_GetValue()         _RA12
/**
  @Summary
    Configures the GPIO pin, RA12, as an input.

  @Description
    Configures the GPIO pin, RA12, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA12 as an input
    Manual_EN_SetDigitalInput();
    </code>

*/
#define Manual_EN_SetDigitalInput()  (_TRISA12 = 1)
/**
  @Summary
    Configures the GPIO pin, RA12, as an output.

  @Description
    Configures the GPIO pin, RA12, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA12 as an output
    Manual_EN_SetDigitalOutput();
    </code>

*/
#define Manual_EN_SetDigitalOutput() (_TRISA12 = 0)
/**
  @Summary
    Sets the GPIO pin, RA4, high using LATA4.

  @Description
    Sets the GPIO pin, RA4, high using LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA4 high (1)
    Lights_SetHigh();
    </code>

*/
#define Lights_SetHigh()          (_LATA4 = 1)
/**
  @Summary
    Sets the GPIO pin, RA4, low using LATA4.

  @Description
    Sets the GPIO pin, RA4, low using LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA4 low (0)
    Lights_SetLow();
    </code>

*/
#define Lights_SetLow()           (_LATA4 = 0)
/**
  @Summary
    Toggles the GPIO pin, RA4, using LATA4.

  @Description
    Toggles the GPIO pin, RA4, using LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA4
    Lights_Toggle();
    </code>

*/
#define Lights_Toggle()           (_LATA4 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RA4.

  @Description
    Reads the value of the GPIO pin, RA4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA4
    postValue = Lights_GetValue();
    </code>

*/
#define Lights_GetValue()         _RA4
/**
  @Summary
    Configures the GPIO pin, RA4, as an input.

  @Description
    Configures the GPIO pin, RA4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA4 as an input
    Lights_SetDigitalInput();
    </code>

*/
#define Lights_SetDigitalInput()  (_TRISA4 = 1)
/**
  @Summary
    Configures the GPIO pin, RA4, as an output.

  @Description
    Configures the GPIO pin, RA4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA4 as an output
    Lights_SetDigitalOutput();
    </code>

*/
#define Lights_SetDigitalOutput() (_TRISA4 = 0)
/**
  @Summary
    Sets the GPIO pin, RA7, high using LATA7.

  @Description
    Sets the GPIO pin, RA7, high using LATA7.

  @Preconditions
    The RA7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA7 high (1)
    LeftWheelDir_SetHigh();
    </code>

*/
#define LeftWheelDir_SetHigh()          (_LATA7 = 1)
/**
  @Summary
    Sets the GPIO pin, RA7, low using LATA7.

  @Description
    Sets the GPIO pin, RA7, low using LATA7.

  @Preconditions
    The RA7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA7 low (0)
    LeftWheelDir_SetLow();
    </code>

*/
#define LeftWheelDir_SetLow()           (_LATA7 = 0)
/**
  @Summary
    Toggles the GPIO pin, RA7, using LATA7.

  @Description
    Toggles the GPIO pin, RA7, using LATA7.

  @Preconditions
    The RA7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA7
    LeftWheelDir_Toggle();
    </code>

*/
#define LeftWheelDir_Toggle()           (_LATA7 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RA7.

  @Description
    Reads the value of the GPIO pin, RA7.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA7
    postValue = LeftWheelDir_GetValue();
    </code>

*/
#define LeftWheelDir_GetValue()         _RA7
/**
  @Summary
    Configures the GPIO pin, RA7, as an input.

  @Description
    Configures the GPIO pin, RA7, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA7 as an input
    LeftWheelDir_SetDigitalInput();
    </code>

*/
#define LeftWheelDir_SetDigitalInput()  (_TRISA7 = 1)
/**
  @Summary
    Configures the GPIO pin, RA7, as an output.

  @Description
    Configures the GPIO pin, RA7, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA7 as an output
    LeftWheelDir_SetDigitalOutput();
    </code>

*/
#define LeftWheelDir_SetDigitalOutput() (_TRISA7 = 0)
/**
  @Summary
    Sets the GPIO pin, RA8, high using LATA8.

  @Description
    Sets the GPIO pin, RA8, high using LATA8.

  @Preconditions
    The RA8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA8 high (1)
    PowerOn_SetHigh();
    </code>

*/
#define PowerOn_SetHigh()          (_LATA8 = 1)
/**
  @Summary
    Sets the GPIO pin, RA8, low using LATA8.

  @Description
    Sets the GPIO pin, RA8, low using LATA8.

  @Preconditions
    The RA8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA8 low (0)
    PowerOn_SetLow();
    </code>

*/
#define PowerOn_SetLow()           (_LATA8 = 0)
/**
  @Summary
    Toggles the GPIO pin, RA8, using LATA8.

  @Description
    Toggles the GPIO pin, RA8, using LATA8.

  @Preconditions
    The RA8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA8
    PowerOn_Toggle();
    </code>

*/
#define PowerOn_Toggle()           (_LATA8 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RA8.

  @Description
    Reads the value of the GPIO pin, RA8.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA8
    postValue = PowerOn_GetValue();
    </code>

*/
#define PowerOn_GetValue()         _RA8
/**
  @Summary
    Configures the GPIO pin, RA8, as an input.

  @Description
    Configures the GPIO pin, RA8, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA8 as an input
    PowerOn_SetDigitalInput();
    </code>

*/
#define PowerOn_SetDigitalInput()  (_TRISA8 = 1)
/**
  @Summary
    Configures the GPIO pin, RA8, as an output.

  @Description
    Configures the GPIO pin, RA8, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA8 as an output
    PowerOn_SetDigitalOutput();
    </code>

*/
#define PowerOn_SetDigitalOutput() (_TRISA8 = 0)
/**
  @Summary
    Sets the GPIO pin, RA9, high using LATA9.

  @Description
    Sets the GPIO pin, RA9, high using LATA9.

  @Preconditions
    The RA9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA9 high (1)
    HeadCurrent_SetHigh();
    </code>

*/
#define HeadCurrent_SetHigh()          (_LATA9 = 1)
/**
  @Summary
    Sets the GPIO pin, RA9, low using LATA9.

  @Description
    Sets the GPIO pin, RA9, low using LATA9.

  @Preconditions
    The RA9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA9 low (0)
    HeadCurrent_SetLow();
    </code>

*/
#define HeadCurrent_SetLow()           (_LATA9 = 0)
/**
  @Summary
    Toggles the GPIO pin, RA9, using LATA9.

  @Description
    Toggles the GPIO pin, RA9, using LATA9.

  @Preconditions
    The RA9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA9
    HeadCurrent_Toggle();
    </code>

*/
#define HeadCurrent_Toggle()           (_LATA9 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RA9.

  @Description
    Reads the value of the GPIO pin, RA9.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA9
    postValue = HeadCurrent_GetValue();
    </code>

*/
#define HeadCurrent_GetValue()         _RA9
/**
  @Summary
    Configures the GPIO pin, RA9, as an input.

  @Description
    Configures the GPIO pin, RA9, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA9 as an input
    HeadCurrent_SetDigitalInput();
    </code>

*/
#define HeadCurrent_SetDigitalInput()  (_TRISA9 = 1)
/**
  @Summary
    Configures the GPIO pin, RA9, as an output.

  @Description
    Configures the GPIO pin, RA9, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA9 as an output
    HeadCurrent_SetDigitalOutput();
    </code>

*/
#define HeadCurrent_SetDigitalOutput() (_TRISA9 = 0)
/**
  @Summary
    Sets the GPIO pin, RB0, high using LATB0.

  @Description
    Sets the GPIO pin, RB0, high using LATB0.

  @Preconditions
    The RB0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB0 high (1)
    SDI2_SetHigh();
    </code>

*/
#define SDI2_SetHigh()          (_LATB0 = 1)
/**
  @Summary
    Sets the GPIO pin, RB0, low using LATB0.

  @Description
    Sets the GPIO pin, RB0, low using LATB0.

  @Preconditions
    The RB0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB0 low (0)
    SDI2_SetLow();
    </code>

*/
#define SDI2_SetLow()           (_LATB0 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB0, using LATB0.

  @Description
    Toggles the GPIO pin, RB0, using LATB0.

  @Preconditions
    The RB0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB0
    SDI2_Toggle();
    </code>

*/
#define SDI2_Toggle()           (_LATB0 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB0.

  @Description
    Reads the value of the GPIO pin, RB0.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB0
    postValue = SDI2_GetValue();
    </code>

*/
#define SDI2_GetValue()         _RB0
/**
  @Summary
    Configures the GPIO pin, RB0, as an input.

  @Description
    Configures the GPIO pin, RB0, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB0 as an input
    SDI2_SetDigitalInput();
    </code>

*/
#define SDI2_SetDigitalInput()  (_TRISB0 = 1)
/**
  @Summary
    Configures the GPIO pin, RB0, as an output.

  @Description
    Configures the GPIO pin, RB0, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB0 as an output
    SDI2_SetDigitalOutput();
    </code>

*/
#define SDI2_SetDigitalOutput() (_TRISB0 = 0)
/**
  @Summary
    Sets the GPIO pin, RB1, high using LATB1.

  @Description
    Sets the GPIO pin, RB1, high using LATB1.

  @Preconditions
    The RB1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB1 high (1)
    PowerConnected_SetHigh();
    </code>

*/
#define PowerConnected_SetHigh()          (_LATB1 = 1)
/**
  @Summary
    Sets the GPIO pin, RB1, low using LATB1.

  @Description
    Sets the GPIO pin, RB1, low using LATB1.

  @Preconditions
    The RB1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB1 low (0)
    PowerConnected_SetLow();
    </code>

*/
#define PowerConnected_SetLow()           (_LATB1 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB1, using LATB1.

  @Description
    Toggles the GPIO pin, RB1, using LATB1.

  @Preconditions
    The RB1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB1
    PowerConnected_Toggle();
    </code>

*/
#define PowerConnected_Toggle()           (_LATB1 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB1.

  @Description
    Reads the value of the GPIO pin, RB1.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB1
    postValue = PowerConnected_GetValue();
    </code>

*/
#define PowerConnected_GetValue()         _RB1
/**
  @Summary
    Configures the GPIO pin, RB1, as an input.

  @Description
    Configures the GPIO pin, RB1, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB1 as an input
    PowerConnected_SetDigitalInput();
    </code>

*/
#define PowerConnected_SetDigitalInput()  (_TRISB1 = 1)
/**
  @Summary
    Configures the GPIO pin, RB1, as an output.

  @Description
    Configures the GPIO pin, RB1, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB1 as an output
    PowerConnected_SetDigitalOutput();
    </code>

*/
#define PowerConnected_SetDigitalOutput() (_TRISB1 = 0)
/**
  @Summary
    Sets the GPIO pin, RB2, high using LATB2.

  @Description
    Sets the GPIO pin, RB2, high using LATB2.

  @Preconditions
    The RB2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB2 high (1)
    Input2_SetHigh();
    </code>

*/
#define Input2_SetHigh()          (_LATB2 = 1)
/**
  @Summary
    Sets the GPIO pin, RB2, low using LATB2.

  @Description
    Sets the GPIO pin, RB2, low using LATB2.

  @Preconditions
    The RB2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB2 low (0)
    Input2_SetLow();
    </code>

*/
#define Input2_SetLow()           (_LATB2 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB2, using LATB2.

  @Description
    Toggles the GPIO pin, RB2, using LATB2.

  @Preconditions
    The RB2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB2
    Input2_Toggle();
    </code>

*/
#define Input2_Toggle()           (_LATB2 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB2.

  @Description
    Reads the value of the GPIO pin, RB2.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB2
    postValue = Input2_GetValue();
    </code>

*/
#define Input2_GetValue()         _RB2
/**
  @Summary
    Configures the GPIO pin, RB2, as an input.

  @Description
    Configures the GPIO pin, RB2, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB2 as an input
    Input2_SetDigitalInput();
    </code>

*/
#define Input2_SetDigitalInput()  (_TRISB2 = 1)
/**
  @Summary
    Configures the GPIO pin, RB2, as an output.

  @Description
    Configures the GPIO pin, RB2, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB2 as an output
    Input2_SetDigitalOutput();
    </code>

*/
#define Input2_SetDigitalOutput() (_TRISB2 = 0)
/**
  @Summary
    Sets the GPIO pin, RB3, high using LATB3.

  @Description
    Sets the GPIO pin, RB3, high using LATB3.

  @Preconditions
    The RB3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB3 high (1)
    LED1_SetHigh();
    </code>

*/
#define LED1_SetHigh()          (_LATB3 = 1)
/**
  @Summary
    Sets the GPIO pin, RB3, low using LATB3.

  @Description
    Sets the GPIO pin, RB3, low using LATB3.

  @Preconditions
    The RB3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB3 low (0)
    LED1_SetLow();
    </code>

*/
#define LED1_SetLow()           (_LATB3 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB3, using LATB3.

  @Description
    Toggles the GPIO pin, RB3, using LATB3.

  @Preconditions
    The RB3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB3
    LED1_Toggle();
    </code>

*/
#define LED1_Toggle()           (_LATB3 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB3.

  @Description
    Reads the value of the GPIO pin, RB3.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB3
    postValue = LED1_GetValue();
    </code>

*/
#define LED1_GetValue()         _RB3
/**
  @Summary
    Configures the GPIO pin, RB3, as an input.

  @Description
    Configures the GPIO pin, RB3, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB3 as an input
    LED1_SetDigitalInput();
    </code>

*/
#define LED1_SetDigitalInput()  (_TRISB3 = 1)
/**
  @Summary
    Configures the GPIO pin, RB3, as an output.

  @Description
    Configures the GPIO pin, RB3, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB3 as an output
    LED1_SetDigitalOutput();
    </code>

*/
#define LED1_SetDigitalOutput() (_TRISB3 = 0)
/**
  @Summary
    Sets the GPIO pin, RB4, high using LATB4.

  @Description
    Sets the GPIO pin, RB4, high using LATB4.

  @Preconditions
    The RB4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB4 high (1)
    SCK2OUT_SetHigh();
    </code>

*/
#define SCK2OUT_SetHigh()          (_LATB4 = 1)
/**
  @Summary
    Sets the GPIO pin, RB4, low using LATB4.

  @Description
    Sets the GPIO pin, RB4, low using LATB4.

  @Preconditions
    The RB4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB4 low (0)
    SCK2OUT_SetLow();
    </code>

*/
#define SCK2OUT_SetLow()           (_LATB4 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB4, using LATB4.

  @Description
    Toggles the GPIO pin, RB4, using LATB4.

  @Preconditions
    The RB4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB4
    SCK2OUT_Toggle();
    </code>

*/
#define SCK2OUT_Toggle()           (_LATB4 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB4.

  @Description
    Reads the value of the GPIO pin, RB4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB4
    postValue = SCK2OUT_GetValue();
    </code>

*/
#define SCK2OUT_GetValue()         _RB4
/**
  @Summary
    Configures the GPIO pin, RB4, as an input.

  @Description
    Configures the GPIO pin, RB4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB4 as an input
    SCK2OUT_SetDigitalInput();
    </code>

*/
#define SCK2OUT_SetDigitalInput()  (_TRISB4 = 1)
/**
  @Summary
    Configures the GPIO pin, RB4, as an output.

  @Description
    Configures the GPIO pin, RB4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB4 as an output
    SCK2OUT_SetDigitalOutput();
    </code>

*/
#define SCK2OUT_SetDigitalOutput() (_TRISB4 = 0)
/**
  @Summary
    Sets the GPIO pin, RB7, high using LATB7.

  @Description
    Sets the GPIO pin, RB7, high using LATB7.

  @Preconditions
    The RB7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB7 high (1)
    HeadSpeed_SetHigh();
    </code>

*/
#define HeadSpeed_SetHigh()          (_LATB7 = 1)
/**
  @Summary
    Sets the GPIO pin, RB7, low using LATB7.

  @Description
    Sets the GPIO pin, RB7, low using LATB7.

  @Preconditions
    The RB7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB7 low (0)
    HeadSpeed_SetLow();
    </code>

*/
#define HeadSpeed_SetLow()           (_LATB7 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB7, using LATB7.

  @Description
    Toggles the GPIO pin, RB7, using LATB7.

  @Preconditions
    The RB7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB7
    HeadSpeed_Toggle();
    </code>

*/
#define HeadSpeed_Toggle()           (_LATB7 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB7.

  @Description
    Reads the value of the GPIO pin, RB7.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB7
    postValue = HeadSpeed_GetValue();
    </code>

*/
#define HeadSpeed_GetValue()         _RB7
/**
  @Summary
    Configures the GPIO pin, RB7, as an input.

  @Description
    Configures the GPIO pin, RB7, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB7 as an input
    HeadSpeed_SetDigitalInput();
    </code>

*/
#define HeadSpeed_SetDigitalInput()  (_TRISB7 = 1)
/**
  @Summary
    Configures the GPIO pin, RB7, as an output.

  @Description
    Configures the GPIO pin, RB7, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB7 as an output
    HeadSpeed_SetDigitalOutput();
    </code>

*/
#define HeadSpeed_SetDigitalOutput() (_TRISB7 = 0)
/**
  @Summary
    Sets the GPIO pin, RB8, high using LATB8.

  @Description
    Sets the GPIO pin, RB8, high using LATB8.

  @Preconditions
    The RB8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB8 high (1)
    Output1_SetHigh();
    </code>

*/
#define Output1_SetHigh()          (_LATB8 = 1)
/**
  @Summary
    Sets the GPIO pin, RB8, low using LATB8.

  @Description
    Sets the GPIO pin, RB8, low using LATB8.

  @Preconditions
    The RB8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB8 low (0)
    Output1_SetLow();
    </code>

*/
#define Output1_SetLow()           (_LATB8 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB8, using LATB8.

  @Description
    Toggles the GPIO pin, RB8, using LATB8.

  @Preconditions
    The RB8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB8
    Output1_Toggle();
    </code>

*/
#define Output1_Toggle()           (_LATB8 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB8.

  @Description
    Reads the value of the GPIO pin, RB8.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB8
    postValue = Output1_GetValue();
    </code>

*/
#define Output1_GetValue()         _RB8
/**
  @Summary
    Configures the GPIO pin, RB8, as an input.

  @Description
    Configures the GPIO pin, RB8, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB8 as an input
    Output1_SetDigitalInput();
    </code>

*/
#define Output1_SetDigitalInput()  (_TRISB8 = 1)
/**
  @Summary
    Configures the GPIO pin, RB8, as an output.

  @Description
    Configures the GPIO pin, RB8, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB8 as an output
    Output1_SetDigitalOutput();
    </code>

*/
#define Output1_SetDigitalOutput() (_TRISB8 = 0)
/**
  @Summary
    Sets the GPIO pin, RB9, high using LATB9.

  @Description
    Sets the GPIO pin, RB9, high using LATB9.

  @Preconditions
    The RB9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB9 high (1)
    REV_SetHigh();
    </code>

*/
#define REV_SetHigh()          (_LATB9 = 1)
/**
  @Summary
    Sets the GPIO pin, RB9, low using LATB9.

  @Description
    Sets the GPIO pin, RB9, low using LATB9.

  @Preconditions
    The RB9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB9 low (0)
    REV_SetLow();
    </code>

*/
#define REV_SetLow()           (_LATB9 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB9, using LATB9.

  @Description
    Toggles the GPIO pin, RB9, using LATB9.

  @Preconditions
    The RB9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB9
    REV_Toggle();
    </code>

*/
#define REV_Toggle()           (_LATB9 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB9.

  @Description
    Reads the value of the GPIO pin, RB9.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB9
    postValue = REV_GetValue();
    </code>

*/
#define REV_GetValue()         _RB9
/**
  @Summary
    Configures the GPIO pin, RB9, as an input.

  @Description
    Configures the GPIO pin, RB9, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB9 as an input
    REV_SetDigitalInput();
    </code>

*/
#define REV_SetDigitalInput()  (_TRISB9 = 1)
/**
  @Summary
    Configures the GPIO pin, RB9, as an output.

  @Description
    Configures the GPIO pin, RB9, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB9 as an output
    REV_SetDigitalOutput();
    </code>

*/
#define REV_SetDigitalOutput() (_TRISB9 = 0)
/**
  @Summary
    Sets the GPIO pin, RC0, high using LATC0.

  @Description
    Sets the GPIO pin, RC0, high using LATC0.

  @Preconditions
    The RC0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC0 high (1)
    LED2_SetHigh();
    </code>

*/
#define LED2_SetHigh()          (_LATC0 = 1)
/**
  @Summary
    Sets the GPIO pin, RC0, low using LATC0.

  @Description
    Sets the GPIO pin, RC0, low using LATC0.

  @Preconditions
    The RC0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC0 low (0)
    LED2_SetLow();
    </code>

*/
#define LED2_SetLow()           (_LATC0 = 0)
/**
  @Summary
    Toggles the GPIO pin, RC0, using LATC0.

  @Description
    Toggles the GPIO pin, RC0, using LATC0.

  @Preconditions
    The RC0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC0
    LED2_Toggle();
    </code>

*/
#define LED2_Toggle()           (_LATC0 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RC0.

  @Description
    Reads the value of the GPIO pin, RC0.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC0
    postValue = LED2_GetValue();
    </code>

*/
#define LED2_GetValue()         _RC0
/**
  @Summary
    Configures the GPIO pin, RC0, as an input.

  @Description
    Configures the GPIO pin, RC0, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC0 as an input
    LED2_SetDigitalInput();
    </code>

*/
#define LED2_SetDigitalInput()  (_TRISC0 = 1)
/**
  @Summary
    Configures the GPIO pin, RC0, as an output.

  @Description
    Configures the GPIO pin, RC0, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC0 as an output
    LED2_SetDigitalOutput();
    </code>

*/
#define LED2_SetDigitalOutput() (_TRISC0 = 0)
/**
  @Summary
    Sets the GPIO pin, RC1, high using LATC1.

  @Description
    Sets the GPIO pin, RC1, high using LATC1.

  @Preconditions
    The RC1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC1 high (1)
    LED3_SetHigh();
    </code>

*/
#define LED3_SetHigh()          (_LATC1 = 1)
/**
  @Summary
    Sets the GPIO pin, RC1, low using LATC1.

  @Description
    Sets the GPIO pin, RC1, low using LATC1.

  @Preconditions
    The RC1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC1 low (0)
    LED3_SetLow();
    </code>

*/
#define LED3_SetLow()           (_LATC1 = 0)
/**
  @Summary
    Toggles the GPIO pin, RC1, using LATC1.

  @Description
    Toggles the GPIO pin, RC1, using LATC1.

  @Preconditions
    The RC1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC1
    LED3_Toggle();
    </code>

*/
#define LED3_Toggle()           (_LATC1 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RC1.

  @Description
    Reads the value of the GPIO pin, RC1.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC1
    postValue = LED3_GetValue();
    </code>

*/
#define LED3_GetValue()         _RC1
/**
  @Summary
    Configures the GPIO pin, RC1, as an input.

  @Description
    Configures the GPIO pin, RC1, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC1 as an input
    LED3_SetDigitalInput();
    </code>

*/
#define LED3_SetDigitalInput()  (_TRISC1 = 1)
/**
  @Summary
    Configures the GPIO pin, RC1, as an output.

  @Description
    Configures the GPIO pin, RC1, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC1 as an output
    LED3_SetDigitalOutput();
    </code>

*/
#define LED3_SetDigitalOutput() (_TRISC1 = 0)
/**
  @Summary
    Sets the GPIO pin, RC10, high using LATC10.

  @Description
    Sets the GPIO pin, RC10, high using LATC10.

  @Preconditions
    The RC10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC10 high (1)
    VFD_Speed_SetHigh();
    </code>

*/
#define VFD_Speed_SetHigh()          (_LATC10 = 1)
/**
  @Summary
    Sets the GPIO pin, RC10, low using LATC10.

  @Description
    Sets the GPIO pin, RC10, low using LATC10.

  @Preconditions
    The RC10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC10 low (0)
    VFD_Speed_SetLow();
    </code>

*/
#define VFD_Speed_SetLow()           (_LATC10 = 0)
/**
  @Summary
    Toggles the GPIO pin, RC10, using LATC10.

  @Description
    Toggles the GPIO pin, RC10, using LATC10.

  @Preconditions
    The RC10 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC10
    VFD_Speed_Toggle();
    </code>

*/
#define VFD_Speed_Toggle()           (_LATC10 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RC10.

  @Description
    Reads the value of the GPIO pin, RC10.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC10
    postValue = VFD_Speed_GetValue();
    </code>

*/
#define VFD_Speed_GetValue()         _RC10
/**
  @Summary
    Configures the GPIO pin, RC10, as an input.

  @Description
    Configures the GPIO pin, RC10, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC10 as an input
    VFD_Speed_SetDigitalInput();
    </code>

*/
#define VFD_Speed_SetDigitalInput()  (_TRISC10 = 1)
/**
  @Summary
    Configures the GPIO pin, RC10, as an output.

  @Description
    Configures the GPIO pin, RC10, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC10 as an output
    VFD_Speed_SetDigitalOutput();
    </code>

*/
#define VFD_Speed_SetDigitalOutput() (_TRISC10 = 0)
/**
  @Summary
    Sets the GPIO pin, RC13, high using LATC13.

  @Description
    Sets the GPIO pin, RC13, high using LATC13.

  @Preconditions
    The RC13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC13 high (1)
    FWD_SetHigh();
    </code>

*/
#define FWD_SetHigh()          (_LATC13 = 1)
/**
  @Summary
    Sets the GPIO pin, RC13, low using LATC13.

  @Description
    Sets the GPIO pin, RC13, low using LATC13.

  @Preconditions
    The RC13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC13 low (0)
    FWD_SetLow();
    </code>

*/
#define FWD_SetLow()           (_LATC13 = 0)
/**
  @Summary
    Toggles the GPIO pin, RC13, using LATC13.

  @Description
    Toggles the GPIO pin, RC13, using LATC13.

  @Preconditions
    The RC13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC13
    FWD_Toggle();
    </code>

*/
#define FWD_Toggle()           (_LATC13 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RC13.

  @Description
    Reads the value of the GPIO pin, RC13.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC13
    postValue = FWD_GetValue();
    </code>

*/
#define FWD_GetValue()         _RC13
/**
  @Summary
    Configures the GPIO pin, RC13, as an input.

  @Description
    Configures the GPIO pin, RC13, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC13 as an input
    FWD_SetDigitalInput();
    </code>

*/
#define FWD_SetDigitalInput()  (_TRISC13 = 1)
/**
  @Summary
    Configures the GPIO pin, RC13, as an output.

  @Description
    Configures the GPIO pin, RC13, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC13 as an output
    FWD_SetDigitalOutput();
    </code>

*/
#define FWD_SetDigitalOutput() (_TRISC13 = 0)
/**
  @Summary
    Sets the GPIO pin, RC3, high using LATC3.

  @Description
    Sets the GPIO pin, RC3, high using LATC3.

  @Preconditions
    The RC3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC3 high (1)
    Input3_SetHigh();
    </code>

*/
#define Input3_SetHigh()          (_LATC3 = 1)
/**
  @Summary
    Sets the GPIO pin, RC3, low using LATC3.

  @Description
    Sets the GPIO pin, RC3, low using LATC3.

  @Preconditions
    The RC3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC3 low (0)
    Input3_SetLow();
    </code>

*/
#define Input3_SetLow()           (_LATC3 = 0)
/**
  @Summary
    Toggles the GPIO pin, RC3, using LATC3.

  @Description
    Toggles the GPIO pin, RC3, using LATC3.

  @Preconditions
    The RC3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC3
    Input3_Toggle();
    </code>

*/
#define Input3_Toggle()           (_LATC3 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RC3.

  @Description
    Reads the value of the GPIO pin, RC3.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC3
    postValue = Input3_GetValue();
    </code>

*/
#define Input3_GetValue()         _RC3
/**
  @Summary
    Configures the GPIO pin, RC3, as an input.

  @Description
    Configures the GPIO pin, RC3, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC3 as an input
    Input3_SetDigitalInput();
    </code>

*/
#define Input3_SetDigitalInput()  (_TRISC3 = 1)
/**
  @Summary
    Configures the GPIO pin, RC3, as an output.

  @Description
    Configures the GPIO pin, RC3, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC3 as an output
    Input3_SetDigitalOutput();
    </code>

*/
#define Input3_SetDigitalOutput() (_TRISC3 = 0)
/**
  @Summary
    Sets the GPIO pin, RC4, high using LATC4.

  @Description
    Sets the GPIO pin, RC4, high using LATC4.

  @Preconditions
    The RC4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC4 high (1)
    Input4_SetHigh();
    </code>

*/
#define Input4_SetHigh()          (_LATC4 = 1)
/**
  @Summary
    Sets the GPIO pin, RC4, low using LATC4.

  @Description
    Sets the GPIO pin, RC4, low using LATC4.

  @Preconditions
    The RC4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC4 low (0)
    Input4_SetLow();
    </code>

*/
#define Input4_SetLow()           (_LATC4 = 0)
/**
  @Summary
    Toggles the GPIO pin, RC4, using LATC4.

  @Description
    Toggles the GPIO pin, RC4, using LATC4.

  @Preconditions
    The RC4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC4
    Input4_Toggle();
    </code>

*/
#define Input4_Toggle()           (_LATC4 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RC4.

  @Description
    Reads the value of the GPIO pin, RC4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC4
    postValue = Input4_GetValue();
    </code>

*/
#define Input4_GetValue()         _RC4
/**
  @Summary
    Configures the GPIO pin, RC4, as an input.

  @Description
    Configures the GPIO pin, RC4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC4 as an input
    Input4_SetDigitalInput();
    </code>

*/
#define Input4_SetDigitalInput()  (_TRISC4 = 1)
/**
  @Summary
    Configures the GPIO pin, RC4, as an output.

  @Description
    Configures the GPIO pin, RC4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC4 as an output
    Input4_SetDigitalOutput();
    </code>

*/
#define Input4_SetDigitalOutput() (_TRISC4 = 0)
/**
  @Summary
    Sets the GPIO pin, RC5, high using LATC5.

  @Description
    Sets the GPIO pin, RC5, high using LATC5.

  @Preconditions
    The RC5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC5 high (1)
    HandlePot_SetHigh();
    </code>

*/
#define HandlePot_SetHigh()          (_LATC5 = 1)
/**
  @Summary
    Sets the GPIO pin, RC5, low using LATC5.

  @Description
    Sets the GPIO pin, RC5, low using LATC5.

  @Preconditions
    The RC5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC5 low (0)
    HandlePot_SetLow();
    </code>

*/
#define HandlePot_SetLow()           (_LATC5 = 0)
/**
  @Summary
    Toggles the GPIO pin, RC5, using LATC5.

  @Description
    Toggles the GPIO pin, RC5, using LATC5.

  @Preconditions
    The RC5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC5
    HandlePot_Toggle();
    </code>

*/
#define HandlePot_Toggle()           (_LATC5 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RC5.

  @Description
    Reads the value of the GPIO pin, RC5.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC5
    postValue = HandlePot_GetValue();
    </code>

*/
#define HandlePot_GetValue()         _RC5
/**
  @Summary
    Configures the GPIO pin, RC5, as an input.

  @Description
    Configures the GPIO pin, RC5, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC5 as an input
    HandlePot_SetDigitalInput();
    </code>

*/
#define HandlePot_SetDigitalInput()  (_TRISC5 = 1)
/**
  @Summary
    Configures the GPIO pin, RC5, as an output.

  @Description
    Configures the GPIO pin, RC5, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC5 as an output
    HandlePot_SetDigitalOutput();
    </code>

*/
#define HandlePot_SetDigitalOutput() (_TRISC5 = 0)
/**
  @Summary
    Sets the GPIO pin, RC6, high using LATC6.

  @Description
    Sets the GPIO pin, RC6, high using LATC6.

  @Preconditions
    The RC6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC6 high (1)
    Dip1_SetHigh();
    </code>

*/
#define Dip1_SetHigh()          (_LATC6 = 1)
/**
  @Summary
    Sets the GPIO pin, RC6, low using LATC6.

  @Description
    Sets the GPIO pin, RC6, low using LATC6.

  @Preconditions
    The RC6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC6 low (0)
    Dip1_SetLow();
    </code>

*/
#define Dip1_SetLow()           (_LATC6 = 0)
/**
  @Summary
    Toggles the GPIO pin, RC6, using LATC6.

  @Description
    Toggles the GPIO pin, RC6, using LATC6.

  @Preconditions
    The RC6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC6
    Dip1_Toggle();
    </code>

*/
#define Dip1_Toggle()           (_LATC6 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RC6.

  @Description
    Reads the value of the GPIO pin, RC6.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC6
    postValue = Dip1_GetValue();
    </code>

*/
#define Dip1_GetValue()         _RC6
/**
  @Summary
    Configures the GPIO pin, RC6, as an input.

  @Description
    Configures the GPIO pin, RC6, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC6 as an input
    Dip1_SetDigitalInput();
    </code>

*/
#define Dip1_SetDigitalInput()  (_TRISC6 = 1)
/**
  @Summary
    Configures the GPIO pin, RC6, as an output.

  @Description
    Configures the GPIO pin, RC6, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC6 as an output
    Dip1_SetDigitalOutput();
    </code>

*/
#define Dip1_SetDigitalOutput() (_TRISC6 = 0)
/**
  @Summary
    Sets the GPIO pin, RC7, high using LATC7.

  @Description
    Sets the GPIO pin, RC7, high using LATC7.

  @Preconditions
    The RC7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC7 high (1)
    Dip2_SetHigh();
    </code>

*/
#define Dip2_SetHigh()          (_LATC7 = 1)
/**
  @Summary
    Sets the GPIO pin, RC7, low using LATC7.

  @Description
    Sets the GPIO pin, RC7, low using LATC7.

  @Preconditions
    The RC7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC7 low (0)
    Dip2_SetLow();
    </code>

*/
#define Dip2_SetLow()           (_LATC7 = 0)
/**
  @Summary
    Toggles the GPIO pin, RC7, using LATC7.

  @Description
    Toggles the GPIO pin, RC7, using LATC7.

  @Preconditions
    The RC7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC7
    Dip2_Toggle();
    </code>

*/
#define Dip2_Toggle()           (_LATC7 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RC7.

  @Description
    Reads the value of the GPIO pin, RC7.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC7
    postValue = Dip2_GetValue();
    </code>

*/
#define Dip2_GetValue()         _RC7
/**
  @Summary
    Configures the GPIO pin, RC7, as an input.

  @Description
    Configures the GPIO pin, RC7, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC7 as an input
    Dip2_SetDigitalInput();
    </code>

*/
#define Dip2_SetDigitalInput()  (_TRISC7 = 1)
/**
  @Summary
    Configures the GPIO pin, RC7, as an output.

  @Description
    Configures the GPIO pin, RC7, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC7 as an output
    Dip2_SetDigitalOutput();
    </code>

*/
#define Dip2_SetDigitalOutput() (_TRISC7 = 0)
/**
  @Summary
    Sets the GPIO pin, RC8, high using LATC8.

  @Description
    Sets the GPIO pin, RC8, high using LATC8.

  @Preconditions
    The RC8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC8 high (1)
    Dip3_SetHigh();
    </code>

*/
#define Dip3_SetHigh()          (_LATC8 = 1)
/**
  @Summary
    Sets the GPIO pin, RC8, low using LATC8.

  @Description
    Sets the GPIO pin, RC8, low using LATC8.

  @Preconditions
    The RC8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC8 low (0)
    Dip3_SetLow();
    </code>

*/
#define Dip3_SetLow()           (_LATC8 = 0)
/**
  @Summary
    Toggles the GPIO pin, RC8, using LATC8.

  @Description
    Toggles the GPIO pin, RC8, using LATC8.

  @Preconditions
    The RC8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC8
    Dip3_Toggle();
    </code>

*/
#define Dip3_Toggle()           (_LATC8 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RC8.

  @Description
    Reads the value of the GPIO pin, RC8.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC8
    postValue = Dip3_GetValue();
    </code>

*/
#define Dip3_GetValue()         _RC8
/**
  @Summary
    Configures the GPIO pin, RC8, as an input.

  @Description
    Configures the GPIO pin, RC8, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC8 as an input
    Dip3_SetDigitalInput();
    </code>

*/
#define Dip3_SetDigitalInput()  (_TRISC8 = 1)
/**
  @Summary
    Configures the GPIO pin, RC8, as an output.

  @Description
    Configures the GPIO pin, RC8, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC8 as an output
    Dip3_SetDigitalOutput();
    </code>

*/
#define Dip3_SetDigitalOutput() (_TRISC8 = 0)
/**
  @Summary
    Sets the GPIO pin, RC9, high using LATC9.

  @Description
    Sets the GPIO pin, RC9, high using LATC9.

  @Preconditions
    The RC9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC9 high (1)
    Dip4_SetHigh();
    </code>

*/
#define Dip4_SetHigh()          (_LATC9 = 1)
/**
  @Summary
    Sets the GPIO pin, RC9, low using LATC9.

  @Description
    Sets the GPIO pin, RC9, low using LATC9.

  @Preconditions
    The RC9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC9 low (0)
    Dip4_SetLow();
    </code>

*/
#define Dip4_SetLow()           (_LATC9 = 0)
/**
  @Summary
    Toggles the GPIO pin, RC9, using LATC9.

  @Description
    Toggles the GPIO pin, RC9, using LATC9.

  @Preconditions
    The RC9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC9
    Dip4_Toggle();
    </code>

*/
#define Dip4_Toggle()           (_LATC9 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RC9.

  @Description
    Reads the value of the GPIO pin, RC9.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC9
    postValue = Dip4_GetValue();
    </code>

*/
#define Dip4_GetValue()         _RC9
/**
  @Summary
    Configures the GPIO pin, RC9, as an input.

  @Description
    Configures the GPIO pin, RC9, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC9 as an input
    Dip4_SetDigitalInput();
    </code>

*/
#define Dip4_SetDigitalInput()  (_TRISC9 = 1)
/**
  @Summary
    Configures the GPIO pin, RC9, as an output.

  @Description
    Configures the GPIO pin, RC9, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC9 as an output
    Dip4_SetDigitalOutput();
    </code>

*/
#define Dip4_SetDigitalOutput() (_TRISC9 = 0)
/**
  @Summary
    Sets the GPIO pin, RD5, high using LATD5.

  @Description
    Sets the GPIO pin, RD5, high using LATD5.

  @Preconditions
    The RD5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD5 high (1)
    CAN_STBY_SetHigh();
    </code>

*/
#define CAN_STBY_SetHigh()          (_LATD5 = 1)
/**
  @Summary
    Sets the GPIO pin, RD5, low using LATD5.

  @Description
    Sets the GPIO pin, RD5, low using LATD5.

  @Preconditions
    The RD5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD5 low (0)
    CAN_STBY_SetLow();
    </code>

*/
#define CAN_STBY_SetLow()           (_LATD5 = 0)
/**
  @Summary
    Toggles the GPIO pin, RD5, using LATD5.

  @Description
    Toggles the GPIO pin, RD5, using LATD5.

  @Preconditions
    The RD5 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD5
    CAN_STBY_Toggle();
    </code>

*/
#define CAN_STBY_Toggle()           (_LATD5 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RD5.

  @Description
    Reads the value of the GPIO pin, RD5.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD5
    postValue = CAN_STBY_GetValue();
    </code>

*/
#define CAN_STBY_GetValue()         _RD5
/**
  @Summary
    Configures the GPIO pin, RD5, as an input.

  @Description
    Configures the GPIO pin, RD5, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD5 as an input
    CAN_STBY_SetDigitalInput();
    </code>

*/
#define CAN_STBY_SetDigitalInput()  (_TRISD5 = 1)
/**
  @Summary
    Configures the GPIO pin, RD5, as an output.

  @Description
    Configures the GPIO pin, RD5, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD5 as an output
    CAN_STBY_SetDigitalOutput();
    </code>

*/
#define CAN_STBY_SetDigitalOutput() (_TRISD5 = 0)
/**
  @Summary
    Sets the GPIO pin, RD6, high using LATD6.

  @Description
    Sets the GPIO pin, RD6, high using LATD6.

  @Preconditions
    The RD6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD6 high (1)
    SafetyInput_SetHigh();
    </code>

*/
#define SafetyInput_SetHigh()          (_LATD6 = 1)
/**
  @Summary
    Sets the GPIO pin, RD6, low using LATD6.

  @Description
    Sets the GPIO pin, RD6, low using LATD6.

  @Preconditions
    The RD6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD6 low (0)
    SafetyInput_SetLow();
    </code>

*/
#define SafetyInput_SetLow()           (_LATD6 = 0)
/**
  @Summary
    Toggles the GPIO pin, RD6, using LATD6.

  @Description
    Toggles the GPIO pin, RD6, using LATD6.

  @Preconditions
    The RD6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD6
    SafetyInput_Toggle();
    </code>

*/
#define SafetyInput_Toggle()           (_LATD6 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RD6.

  @Description
    Reads the value of the GPIO pin, RD6.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD6
    postValue = SafetyInput_GetValue();
    </code>

*/
#define SafetyInput_GetValue()         _RD6
/**
  @Summary
    Configures the GPIO pin, RD6, as an input.

  @Description
    Configures the GPIO pin, RD6, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD6 as an input
    SafetyInput_SetDigitalInput();
    </code>

*/
#define SafetyInput_SetDigitalInput()  (_TRISD6 = 1)
/**
  @Summary
    Configures the GPIO pin, RD6, as an output.

  @Description
    Configures the GPIO pin, RD6, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD6 as an output
    SafetyInput_SetDigitalOutput();
    </code>

*/
#define SafetyInput_SetDigitalOutput() (_TRISD6 = 0)
/**
  @Summary
    Sets the GPIO pin, RD8, high using LATD8.

  @Description
    Sets the GPIO pin, RD8, high using LATD8.

  @Preconditions
    The RD8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD8 high (1)
    Output2_SetHigh();
    </code>

*/
#define Output2_SetHigh()          (_LATD8 = 1)
/**
  @Summary
    Sets the GPIO pin, RD8, low using LATD8.

  @Description
    Sets the GPIO pin, RD8, low using LATD8.

  @Preconditions
    The RD8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD8 low (0)
    Output2_SetLow();
    </code>

*/
#define Output2_SetLow()           (_LATD8 = 0)
/**
  @Summary
    Toggles the GPIO pin, RD8, using LATD8.

  @Description
    Toggles the GPIO pin, RD8, using LATD8.

  @Preconditions
    The RD8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD8
    Output2_Toggle();
    </code>

*/
#define Output2_Toggle()           (_LATD8 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RD8.

  @Description
    Reads the value of the GPIO pin, RD8.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD8
    postValue = Output2_GetValue();
    </code>

*/
#define Output2_GetValue()         _RD8
/**
  @Summary
    Configures the GPIO pin, RD8, as an input.

  @Description
    Configures the GPIO pin, RD8, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD8 as an input
    Output2_SetDigitalInput();
    </code>

*/
#define Output2_SetDigitalInput()  (_TRISD8 = 1)
/**
  @Summary
    Configures the GPIO pin, RD8, as an output.

  @Description
    Configures the GPIO pin, RD8, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD8 as an output
    Output2_SetDigitalOutput();
    </code>

*/
#define Output2_SetDigitalOutput() (_TRISD8 = 0)
/**
  @Summary
    Sets the GPIO pin, RE15, high using LATE15.

  @Description
    Sets the GPIO pin, RE15, high using LATE15.

  @Preconditions
    The RE15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE15 high (1)
    BatVoltage_SetHigh();
    </code>

*/
#define BatVoltage_SetHigh()          (_LATE15 = 1)
/**
  @Summary
    Sets the GPIO pin, RE15, low using LATE15.

  @Description
    Sets the GPIO pin, RE15, low using LATE15.

  @Preconditions
    The RE15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE15 low (0)
    BatVoltage_SetLow();
    </code>

*/
#define BatVoltage_SetLow()           (_LATE15 = 0)
/**
  @Summary
    Toggles the GPIO pin, RE15, using LATE15.

  @Description
    Toggles the GPIO pin, RE15, using LATE15.

  @Preconditions
    The RE15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE15
    BatVoltage_Toggle();
    </code>

*/
#define BatVoltage_Toggle()           (_LATE15 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RE15.

  @Description
    Reads the value of the GPIO pin, RE15.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE15
    postValue = BatVoltage_GetValue();
    </code>

*/
#define BatVoltage_GetValue()         _RE15
/**
  @Summary
    Configures the GPIO pin, RE15, as an input.

  @Description
    Configures the GPIO pin, RE15, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE15 as an input
    BatVoltage_SetDigitalInput();
    </code>

*/
#define BatVoltage_SetDigitalInput()  (_TRISE15 = 1)
/**
  @Summary
    Configures the GPIO pin, RE15, as an output.

  @Description
    Configures the GPIO pin, RE15, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE15 as an output
    BatVoltage_SetDigitalOutput();
    </code>

*/
#define BatVoltage_SetDigitalOutput() (_TRISE15 = 0)
/**
  @Summary
    Sets the GPIO pin, RG6, high using LATG6.

  @Description
    Sets the GPIO pin, RG6, high using LATG6.

  @Preconditions
    The RG6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG6 high (1)
    L_Sdata_SetHigh();
    </code>

*/
#define L_Sdata_SetHigh()          (_LATG6 = 1)
/**
  @Summary
    Sets the GPIO pin, RG6, low using LATG6.

  @Description
    Sets the GPIO pin, RG6, low using LATG6.

  @Preconditions
    The RG6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG6 low (0)
    L_Sdata_SetLow();
    </code>

*/
#define L_Sdata_SetLow()           (_LATG6 = 0)
/**
  @Summary
    Toggles the GPIO pin, RG6, using LATG6.

  @Description
    Toggles the GPIO pin, RG6, using LATG6.

  @Preconditions
    The RG6 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG6
    L_Sdata_Toggle();
    </code>

*/
#define L_Sdata_Toggle()           (_LATG6 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RG6.

  @Description
    Reads the value of the GPIO pin, RG6.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG6
    postValue = L_Sdata_GetValue();
    </code>

*/
#define L_Sdata_GetValue()         _RG6
/**
  @Summary
    Configures the GPIO pin, RG6, as an input.

  @Description
    Configures the GPIO pin, RG6, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG6 as an input
    L_Sdata_SetDigitalInput();
    </code>

*/
#define L_Sdata_SetDigitalInput()  (_TRISG6 = 1)
/**
  @Summary
    Configures the GPIO pin, RG6, as an output.

  @Description
    Configures the GPIO pin, RG6, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG6 as an output
    L_Sdata_SetDigitalOutput();
    </code>

*/
#define L_Sdata_SetDigitalOutput() (_TRISG6 = 0)
/**
  @Summary
    Sets the GPIO pin, RG7, high using LATG7.

  @Description
    Sets the GPIO pin, RG7, high using LATG7.

  @Preconditions
    The RG7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG7 high (1)
    SD_CS_SetHigh();
    </code>

*/
#define SD_CS_SetHigh()          (_LATG7 = 1)
/**
  @Summary
    Sets the GPIO pin, RG7, low using LATG7.

  @Description
    Sets the GPIO pin, RG7, low using LATG7.

  @Preconditions
    The RG7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG7 low (0)
    SD_CS_SetLow();
    </code>

*/
#define SD_CS_SetLow()           (_LATG7 = 0)
/**
  @Summary
    Toggles the GPIO pin, RG7, using LATG7.

  @Description
    Toggles the GPIO pin, RG7, using LATG7.

  @Preconditions
    The RG7 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG7
    SD_CS_Toggle();
    </code>

*/
#define SD_CS_Toggle()           (_LATG7 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RG7.

  @Description
    Reads the value of the GPIO pin, RG7.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG7
    postValue = SD_CS_GetValue();
    </code>

*/
#define SD_CS_GetValue()         _RG7
/**
  @Summary
    Configures the GPIO pin, RG7, as an input.

  @Description
    Configures the GPIO pin, RG7, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG7 as an input
    SD_CS_SetDigitalInput();
    </code>

*/
#define SD_CS_SetDigitalInput()  (_TRISG7 = 1)
/**
  @Summary
    Configures the GPIO pin, RG7, as an output.

  @Description
    Configures the GPIO pin, RG7, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG7 as an output
    SD_CS_SetDigitalOutput();
    </code>

*/
#define SD_CS_SetDigitalOutput() (_TRISG7 = 0)
/**
  @Summary
    Sets the GPIO pin, RG8, high using LATG8.

  @Description
    Sets the GPIO pin, RG8, high using LATG8.

  @Preconditions
    The RG8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG8 high (1)
    SDO2_SetHigh();
    </code>

*/
#define SDO2_SetHigh()          (_LATG8 = 1)
/**
  @Summary
    Sets the GPIO pin, RG8, low using LATG8.

  @Description
    Sets the GPIO pin, RG8, low using LATG8.

  @Preconditions
    The RG8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RG8 low (0)
    SDO2_SetLow();
    </code>

*/
#define SDO2_SetLow()           (_LATG8 = 0)
/**
  @Summary
    Toggles the GPIO pin, RG8, using LATG8.

  @Description
    Toggles the GPIO pin, RG8, using LATG8.

  @Preconditions
    The RG8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RG8
    SDO2_Toggle();
    </code>

*/
#define SDO2_Toggle()           (_LATG8 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RG8.

  @Description
    Reads the value of the GPIO pin, RG8.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RG8
    postValue = SDO2_GetValue();
    </code>

*/
#define SDO2_GetValue()         _RG8
/**
  @Summary
    Configures the GPIO pin, RG8, as an input.

  @Description
    Configures the GPIO pin, RG8, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG8 as an input
    SDO2_SetDigitalInput();
    </code>

*/
#define SDO2_SetDigitalInput()  (_TRISG8 = 1)
/**
  @Summary
    Configures the GPIO pin, RG8, as an output.

  @Description
    Configures the GPIO pin, RG8, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RG8 as an output
    SDO2_SetDigitalOutput();
    </code>

*/
#define SDO2_SetDigitalOutput() (_TRISG8 = 0)

/**
    Section: Function Prototypes
*/
/**
  @Summary
    Configures the pin settings of the dsPIC33EV32GM106
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    void SYSTEM_Initialize(void)
    {
        // Other initializers are called from this function
        PIN_MANAGER_Initialize();
    }
    </code>

*/
void PIN_MANAGER_Initialize (void);

/**
  @Summary
    Callback for IOC Pins.

  @Description
    This routine is callback for IOC Pins.

  @Param
    None.

  @Returns
    None
 
  @Example 
    <code>
        CN_SetInterruptHandler(&CN_CallBack);
    </code>
*/
void CN_CallBack(void);

/**
  @Summary
    Assigns a function pointer with a callback address.

  @Description
    This routine assigns a function pointer with a callback address.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        CN_SetInterruptHandler(&CN_CallBack);
    </code>
*/
void CN_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Assigns a function pointer with a callback address.

  @Description
    This routine assigns a function pointer with a callback address.

  @Param
    Address of the callback routine.

  @Returns
    None
 
  @Example 
    <code>
        CN_SetIOCInterruptHandler(&CN_CallBack);
    </code>
*/
void __attribute__((deprecated("\nThis will be removed in future MCC releases. \nUse CN_SetInterruptHandler instead."))) CN_SetIOCInterruptHandler(void *handler);

#endif
