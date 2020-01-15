
#include <stdio.h>
#include <stdlib.h>
#include "Main.h"
#include "Port.h"
#include "SW.h"
#include "SSD.h"
#include "VC.h"

int main()
{
    SW_Init();
    SSD_Init();
    VC_Init();
    GPIO_InitPortPin(LED_4_PORT_CR, LED_4_PIN, GPIO_OUT);
    GPIO_WritePortPin(LED_4_PORT_DR, LED_4_PIN, 0 );
   
    
    while(1)
    {
       
        __delay_ms(1);
        SW_Update();
        SSD_Update();
        VC_Update();
       
        // GPIO_WritePortPin(LED_4_PORT_DR, LED_4_PIN, 0 );
      //  GPIO_WritePortPin(LED_4_PORT_DR, LED_4_PIN, 1 );
        
        if( VC_GetSpeed() == LOW_SPEED )
        
        {
        
             
          SSD_SetValue(SSD_FIRST,SSD_LOW);
          SSD_SetValue(SSD_SECOND,SSD_NULL);
          SSD_SetValue(SSD_THIRD,SSD_NULL);
        }
        else if( VC_GetSpeed() == MID_SPEED )
        
        {
        
             
          SSD_SetValue(SSD_FIRST,SSD_LOW);
          SSD_SetValue(SSD_SECOND,SSD_MID);
          SSD_SetValue(SSD_THIRD,SSD_NULL);
          
        }
        else if( VC_GetSpeed() == HIGH_SPEED )
        
        {
        
             
          SSD_SetValue(SSD_FIRST,SSD_LOW);
          SSD_SetValue(SSD_SECOND,SSD_MID);
          SSD_SetValue(SSD_THIRD,SSD_HIGH);
        }
    
    }
    return 0;
}
