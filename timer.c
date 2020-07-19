
#include "timer.h"

void SysTimer_init() {
    /*
     * F_cpu = 8MHZ 
     * 
     *f_timer = (F_cpu /4 ) * PREscaler = 8MHZ / (8 *4 )= 0.25 Mhz
     *tick = 1/f_timer =1 /0.25MHZ = 4 Micro Seconds 
     *  
     *delay required = tick * count 
     * 1ms = 4MS * x 
     * x = (1 *10^-3) * (4 *10^-6) = 250
     * 
     * register reload Value = MAX_register - x 
     *                       = 65535 -250 = 65285
     **/

    TMR1CS = 0; // internal Clock Source 
    
    /* F_timer = F_CPu / 8 */
    T1CKPS0 = 1;
    T1CKPS1 = 1;
}

void SysTimer_start()
{
    TMR1L = 0x05 ;
    TMR1H = 0xFF ; 
    TMR1ON = 1 ;
}