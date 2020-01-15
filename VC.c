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
  
/*static vriable to indicate the target speed*/



void VC_Init(void)
{
    /*this function sets the initial speed value of the motor */
   
    
}
void VC_Update(void)
{
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
}
