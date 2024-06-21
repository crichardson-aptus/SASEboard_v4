/*
 * File:   BasicFunctions.c
 * Author: APTUSM6
 *
 * Created on October 28, 2021, 1:02 PM
 */

#include <xc.h>
#include "../mcc_generated_files/mcc.h"

void __delay32(unsigned long delay);

void delay_ms(int delay) {
    __delay32(delay * 39921);
}

void delay_us(unsigned long delay) {
    __delay32(delay * 40);
}

void LED_FlashAll(int count){
    int x;
    for(x = 0; x<=count; x++){
        LED1_SetHigh();
        LED2_SetHigh();
        LED3_SetHigh();
        delay_ms(200);
        LED1_SetLow();
        LED2_SetLow();
        LED3_SetLow();
        delay_ms(200);
    }
    
}

void LED_Flash(int LED, int msTime, int count){
    int x;
    if(LED == 1){
        for(x = 0; x<=count; x++){
            LED1_SetHigh();
            delay_ms(msTime);
            LED1_SetLow();
            delay_ms(msTime);
        }
    }
    
    else if(LED == 2){
        for(x = 0; x<=count; x++){
            LED2_SetHigh();
            delay_ms(msTime);
            LED2_SetLow();
            delay_ms(msTime);
        }
    }
    
    else if(LED == 3){
        for(x = 0; x<=count; x++){
            LED3_SetHigh();
            delay_ms(msTime);
            LED3_SetLow();
            delay_ms(msTime);
        }
    }
}

void LED_Off(){
    LED1_SetLow();
    LED2_SetLow();
    LED3_SetLow();
}

void LED_Loading(int msTime){
    LED1_SetHigh();
    delay_ms(msTime);
    LED2_SetHigh();
    delay_ms(msTime);
    LED3_SetHigh();
    delay_ms(msTime);
    LED_Off();
}

/**
 End of File
 */