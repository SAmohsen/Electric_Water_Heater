
#include "INTHandlers.h"
#include "fan.h"

static void (*g_TMR1_callback_ptr)(void) = NULL_PTR;
static void (*g_ExtINT_callback_ptr)(void) = NULL_PTR;

void __interrupt() Main_ISR() {
    /*Checking On Timer Interrupts*/

    if (TMR1IF == 1) {
        if (NULL_PTR != g_TMR1_callback_ptr) {
            (*g_TMR1_callback_ptr)();
        }
        TMR1IF = 0; /* Cleat Interrupt Flag */
    }

    /*Checking On External Interrupts*/
    if (INTF == 1) {
        if (NULL_PTR != g_ExtINT_callback_ptr) {
            (*g_ExtINT_callback_ptr)();
        }
        INTF =0; /* Cleat Interrupt Flag */
    }


}

void Tmr1_setCallback(void (*a_ptr)(void)) {
    g_TMR1_callback_ptr = a_ptr;
}

void ExtINT_setCallback(void (*a_ptr)(void)) {
    g_ExtINT_callback_ptr = a_ptr;
}