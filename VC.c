/* 
 * File:   VC.h
 * Author: Ayman Elhaddad
 * Comments: pure SW file , drives the vacuum cleaner machine.
 * Revision history: 15/1/2020
 */


#include "Main.h"
#include "Port.h"
#include "VC.h"
#include "SW.h"
  
#define VC_PERIOD (20)
#define PRESSURE_PRERIOD (3000)

/*static variable to indicate the target speed*/
static tVC_SPEED TargetSpeed;

void VC_Init(void)
{
    /*this function sets the initial speed value of the motor */
    TargetSpeed = MID_SPEED;
   
    
}
void VC_Update(void)
{
    static tWord VC_counter = 0;
    tByte Index;
    
    /*check the function time*/
    VC_counter += TMR_TICK_MS;
    if(VC_counter != VC_PERIOD)
    {
        return;
        //this not my time . goodbye 
    }
    VC_counter = 0;
    
    /*update the target speed , based on the switches states*/
    for(Index = SW_PLUS ; Index < N_SWITCHES ; Index ++ )
    {
        
        switch(Index)
        {
            case SW_PLUS :
                if(SW_GetState(SW_PLUS) == SW_PRE_RELEASED)
                {
                    if(TargetSpeed == HIGH_SPEED)
                      {
                        continue;
                      }
                    
                    TargetSpeed ++;
                }          
                break;
            
            case SW_MINUS :
                if(SW_GetState(SW_MINUS) == SW_PRE_RELEASED)
                {
                    if(TargetSpeed == LOW_SPEED)
                    {
                        continue;
                    }
                        
                    TargetSpeed --;
                }         
                break;
      
            case SW_PRESSURE :
                if(SW_GetState(SW_PRESSURE) == SW_PRE_RELEASED)
                   {
                        GPIO_WritePortPin(LED_4_PORT_DR, LED_4_PIN, 0 );
                   }         
                break;
                
            default:
                    //do nothing                
                break;
                
        }
        
    
        if(SW_GetState(SW_PRESSURE) == SW_PRESSED)
        {
            /*Enable the pressure indicator LED*/
            GPIO_WritePortPin(LED_4_PORT_DR, LED_4_PIN, 1 );
            
            /*static variable to count the pressure switch period*/
            static tWord PRESSURE_counter = 0;
            PRESSURE_counter += VC_PERIOD;
            if( PRESSURE_counter != PRESSURE_PRERIOD )
            {
                return ;
            }
            PRESSURE_counter = 0;

            
            if(  TargetSpeed == LOW_SPEED)
            {
                return;
            }
            
            TargetSpeed --;
        }
        
}   
    
    //check the switches states
    
   
    //update the speed ,based on the state machine concept
    
    //apply a switch case control flow
    
    /*      
     * If (+) is pre=pressed & speed is not max, speed increases by 1 step
     * If (-) is pre=pressed & speed is not min, speed decreases by 1 step
     * If(P) is pressed & press time == 30 seconds & speed is not min, speed decreases by 1 step.  
     */
    
}
tVC_SPEED VC_GetSpeed(void)
{
    //return the current speed of VC
    return TargetSpeed;
}
