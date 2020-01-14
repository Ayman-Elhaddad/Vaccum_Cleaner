



#include <stdio.h>
#include <stdlib.h>
#include "Main.h"
#include "Port.h"
#include "SW.h"

int main()
{
    void SW_Init();
    GPIO_InitPortPin(LED_4_PORT_CR, LED_4_PIN, GPIO_OUT);
    
    while(1)
    {
        __delay_ms(1);
        SW_Update();
        GPIO_WritePortPin(LED_4_PORT_DR, LED_4_PIN, 1 );
        
        if( SW_GetState(SW_PRESURE) == SW_PRESSED )
        
        {
        
             
          GPIO_WritePortPin(LED_4_PORT_DR, LED_4_PIN, 0 );
        }
    
    }
    return 0;
}
