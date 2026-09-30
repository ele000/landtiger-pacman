#include "button.h"
#include "LPC17xx.h"
#include "timer/timer.h"
#include "GLCD/GLCD.h"
#include "RIT/RIT.h"

extern int down_0;
int attiva_timer_power_pills=0;

void EINT0_IRQHandler (void)	  	/* INT0														 */
{	
	
	if(attiva_timer_power_pills==0){
		srand(LPC_TIM2->TC);
		uint32_t tempo=(uint32_t)((rand()%30)*25000000);
		init_timer(1,0,0,1,tempo); //TIMER 1 MR0
		attiva_timer_power_pills=1;
		}
	
	down_0=1;
	NVIC_DisableIRQ(EINT0_IRQn);
	LPC_PINCON->PINSEL4    &= ~(1 << 20);    
	LPC_SC->EXTINT &= (1 << 0); 
}

void EINT1_IRQHandler (void)	  	/* KEY1														 */
{
	LPC_SC->EXTINT &= (1 << 1);     /* clear pending interrupt         */
}

void EINT2_IRQHandler (void)	  	/* KEY2														 */
{
  LPC_SC->EXTINT &= (1 << 2);     /* clear pending interrupt         */    
}


