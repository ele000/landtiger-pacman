/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_RIT.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    RIT.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "LPC17xx.h"
#include "RIT.h"
#include "GLCD/GLCD.h"
#include "timer/timer.h"
#include "stdio.h"

/******************************************************************************
** Function name:		RIT_IRQHandler
**
** Descriptions:		REPETITIVE INTERRUPT TIMER handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/

volatile int i=0;

volatile int down_0=0;

void RIT_IRQHandler (void)
{				
	static int status_gioco=0;
	//BUTTON

if(down_0 !=0){
	down_0++;
	if((LPC_GPIO2->FIOPIN & (1<<10)) == 0){
		switch(down_0){
			case 2:
				if(status_gioco==0){
				enable_timer(0);
				enable_timer(1);
				enable_timer(3);
				GUI_Text(95,150,(uint8_t *) "      ",Black,Black);
				status_gioco=1;
			}else{
				disable_timer(0);
				disable_timer(1);
				disable_timer(3);
				GUI_Text(95,150,(uint8_t *) " PAUSE",Yellow,Black);
				status_gioco=0;
			}
				break;
			default:
				break;
		}
	
		enable_RIT();
	}
	else {	/* button released */
		down_0=0;			
		NVIC_EnableIRQ(EINT0_IRQn);							 /* disable Button interrupts			*/
		LPC_PINCON->PINSEL4    |= (1 << 20);     /* External interrupt 0 pin selection */
		enable_RIT();
	}
} // end INT0
	
	//JOYSTICK

if(status_gioco==1){
	
	if((LPC_GPIO1->FIOPIN & (1<<29)) == 0){	
		/* Joytick UP pressed */
		i=1;
		}

	if((LPC_GPIO1->FIOPIN & (1<<26)) == 0){	
		/* Joytick DOWN pressed */
			i=2;
		}

	if((LPC_GPIO1->FIOPIN & (1<<27)) == 0){	
		/* Joytick LEFT pressed */
				i=3;
			}
		
	if((LPC_GPIO1->FIOPIN & (1<<28)) == 0){	
		/* Joytick RIGHT pressed */
			i=4;
			}
		}

	reset_RIT();
  LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
	enable_RIT();
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
