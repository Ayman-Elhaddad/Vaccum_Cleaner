
/* 
 * File:   VC.h
 * Author: Ayman Elhaddad
 * Comments: pure SW file , drives the vacuum cleaner machine.
 * Revision history: 15/1/2020
 */

 
#ifndef __VC_H
#define	__VC_H

#include <xc.h> // include processor files - each processor file is guarded.  



typedef enum
{
    LOW_SPEED = 0,
    MID_SPEED = 1,
    HIGH_SPEED = 2        
}tVC_SPEED;



void VC_Init(void);
void VC_Update(void);
tVC_SPEED VC_GetSpeed(void); 



#endif	

