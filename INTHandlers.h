/* 
 * File:   isr.h
 * Author: sayed
 *
 * Created on July 16, 2020, 9:26 AM
 */

#ifndef ISR_H
#define	ISR_H

#include "micro_config.h"
#include "std_types.h"
#include "common_marcos.h"


#define SEI()  (GIE=1)
#define CLI()  (GIE=0)
#define PERIPHRAL_INTERRUPT_ENABLE()  (PEIE =1)
#define PERIPHRAL_INTERRUPT_DISABLE()  (PEIE =0)
#define TMR1_INTERRUPT_ENABLE() (TMR1IE=1)
#define TMR1_INTERRUPT_DISABLE() (TMR1IE=0)
#define EXTINT_ENABLE() (INTE=1)
#define EXTINT_DISABLE() (INTE=0)


void Tmr1_setCallback(void (*a_ptr)(void)) ; 
void ExtINT_setCallback(void (*a_ptr)(void)) ;

#endif	/* ISR_H */

