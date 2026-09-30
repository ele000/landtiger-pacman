#include <string.h>
#include "LPC17xx.h"
#include "timer.h"
#include "GLCD/GLCD.h"
#include <stdio.h> /*for sprintf*/
#include "../elementi/elementi.h"
#include "../RIT/RIT.h"


/******************************************************************************
** Function name:		Timer0_IRQHandler
******************************************************************************/

#ifdef SIMULATOR
extern uint8_t ScaleFlag; // <- ScaleFlag needs to visible in order for the emulator to find the symbol (can be placed also inside system_LPC17xx.h but since it is RO, it needs more work)
#endif

static int N = 59;
extern int i;
extern int punteggio;
extern int pillsMangiate;

void TIMER0_IRQHandler (void)
{
	if(LPC_TIM0->IR & 1) // MR0
	{ 
		
		if(pillsMangiate==240){    
			disable_timer(0);
			disable_timer(3);
			GUI_Text(65,120,(uint8_t *) "   VICTORY!   " , Black , Green);
		}
		
		char tempo[4];
		sprintf(tempo,"%02ds", N);

		if(N>0){ //continuo il countdown
			GUI_Text(40, 15,(uint8_t *) tempo, White, Black);
			N--;
			}else if(pillsMangiate!=240){ 
			GUI_Text(40, 15,(uint8_t *) tempo, White, Black);
			disable_timer(0);
			disable_timer(3);
			GUI_Text(65,120,(uint8_t *) "   GAME OVER   " , White , Red);
			}
			
		LPC_TIM0->IR = 1;			//clear interrupt flag
	}

  return;
}

/******************************************************************************
** Function name:		Timer1_IRQHandler
******************************************************************************/
void TIMER1_IRQHandler (void)
{
	
	if(LPC_TIM1->IR & 1) // MR0
	{ 
		power_pills();
		LPC_TIM1->IR = 1;	
	}
	disable_timer(1);

	return;
}

/******************************************************************************
** Function name:		Timer2_IRQHandler
******************************************************************************/
void TIMER2_IRQHandler (void)
{
	LPC_TIM2->IR = 1;	
  return;
}


/******************************************************************************
** Function name:		Timer2_IRQHandler
******************************************************************************/
void TIMER3_IRQHandler (void)
{
 	if(LPC_TIM3->IR & 1){// MR0
		switch(i){   
			case 1:
				if(N%2==1){move_up();
				}else{move_up2();}
				break;
			case 2:
				if(N%2==1){move_down();
				}else{move_down2();}
				break;
			case 3:
				if(N%2==1){move_left();
				}else{move_left2();}
				break;
			case 4:
				if(N%2==1){move_right();
				}else{move_right2();}
				break;
		}	
		
		LPC_TIM3->IR = 1;			//clear interrupt flag
	}
	
	
	enable_RIT();
  return;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
