/* 
 * File:   BasicFunctions.h
 * Author: crich
 *
 * Created on October 28, 2021, 1:53 PM
 */

#ifndef BASICFUNCTIONS_H
#define	BASICFUNCTIONS_H

#include "SASE.h"


#ifdef	__cplusplus
extern "C" {
#endif
    
    void delay_ms(int delay);
    void delay_us(unsigned long delay);
    void LED_FlashAll(int count);
    void LED_Flash(int LED, int msTime, int count);
    void LED_Loading(int msTime);




#ifdef	__cplusplus
}
#endif

#endif	/* BASICFUNCTIONS_H */

