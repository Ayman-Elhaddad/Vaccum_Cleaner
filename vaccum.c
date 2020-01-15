
#include <stdio.h>
#include <stdlib.h>
#include "Main.h"
#include "Port.h"
#include "SW.h"
#include "SSD.h"

int main()
{
    SW_Init();
    SSD_Init();
    
   // GPIO_InitPortPin(LED_4_PORT_CR, LED_4_PIN, GPIO_OUT);
    
    while(1)
    {
        __delay_ms(1);
        SW_Update();
        SSD_Update();
        GPIO_WritePortPin(LED_4_PORT_DR, LED_4_PIN, 1 );
        
        if( SW_GetState(SW_PLUS) == SW_PRESSED )
        
        {
        
             
          SSD_SetValue(SSD_FIRST,SSD_LOW);
          SSD_SetValue(SSD_SECOND,SSD_NULL);
          SSD_SetValue(SSD_THIRD,SSD_NULL);
        }
        else if( SW_GetState(SW_MINUS) == SW_PRESSED )
        
        {
        
             
          SSD_SetValue(SSD_FIRST,SSD_LOW);
          SSD_SetValue(SSD_SECOND,SSD_MID);
          SSD_SetValue(SSD_THIRD,SSD_NULL);
          
        }
        else if( SW_GetState(SW_PRESURE) == SW_PRESSED )
        
        {
        
             
          SSD_SetValue(SSD_FIRST,SSD_LOW);
          SSD_SetValue(SSD_SECOND,SSD_MID);
          SSD_SetValue(SSD_THIRD,SSD_HIGH);
        }
    
    }
    return 0;
}
