#include "elementi.h"
#include "GLCD/GLCD.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "timer/timer.h"
#include "../RIT/RIT.h"

#define Orange 0xFC00

int N=240;
int m[240][2]= /*linea 46*/{{10,46},{23,46},{30,46},{37,46},{44,46},{57,46},{70,46},{76,46},{82,46},{88,46},{94,46},{108,46},
														{130,46},{144,46},{151,46},{158,46},{165,46},{172,46},{185,46},{198,46},{204,46},{210,46},{216,46},{229,46},
							
							/*linea 57*/ {10,57},{57,57},{108,57},{130,57},{185,57},{229,57},
							/*linea 63*/ {10,63},{57,63},{108,63},{130,63},{185,63},{229,63},
							/*linea 69*/ {10,69},{57,69},{108,69},{130,69},{185,69},{229,69},
															
							/*linea 82*/{10,82},{23,82},{30,82},{37,82},{44,82},{57,82},{185,82},{198,82},{204,82},{210,82},{216,82},{229,82},
												{69,82},{81,82},{94,82},{108,82},{130,82},{144,82},{159,82}, {172,82},{119,82},
								
							/*linea 95*/ {10,95},{57,95},{81,95},{159,95},{185,95},{229,95},
							
							/*linea 107*/ {10,107},{23,107},{30,107},{37,107},{44,107},{57,107},{185,107},{198,107},{204,107},{210,107},{216,107},{229,107},
														{81,107},{94,107},{108,107},{130,107},{145,107},{159,107},
								
							/*linea 119*/ {57,119},{185,119},{108,119},{130,119},
							/*linea 125*/ {57,125},{185,125},
							/*linea 131*/ {57,131},{185,131},
							/*linea 137*/ {57,137},{185,137},
							/*linea 143*/ {57,143},{185,143},
							
							/*linea 145*/ {81,145},{159,145},
							/*linea 169*/ {81,169},{159,169},
							/*linea 175*/ {81,175},{159,175},
							
							/*linea 158*/ {57,158},{185,158},{69,158},{171,158},{81,158},{159,158},
							              {7,158},{13,158},{19,158},{25,158},{31,158},{37,158},{43,158},
														{195,158},{201,158},{207,158},{213,158},{219,158},{225,158},{231,158},
							
							/*linea 170*/ {57,170},{185,170},
							/*linea 177*/ {57,177},{185,177},
							/*linea 184*/ {57,184},{185,184},
							/*linea 187*/ {81,187},{92,187},{101,187},{110,187},{119,187},{128,187},{137,187},{148,187},{159,187},
							/*linea 191*/ {57,191},{185,191},
							/*linea 198*/ {57,198},{185,198},{81,198},{159,198},
							
							/*linea 212*/{10,212},{23,212},{30,212},{37,212},{44,212},{57,212},{185,212},{198,212},{204,212},{210,212},{216,212},{229,212},
                            {69,212},{81,212},{94,212},{108,212},{130,212},{145,212},{159,212},{172,212},
								
							/*linea 225*/ {10,225},{57,225},{108,225},{130,225},{185,225},{229,225},	
							
							/*linea 238*/ {10,238},{20,238},{32,238},{57,238},{69,238},{81,238},{94,238},{108,238},
								            {130,238},{143,238},{159,238},{172,238},{185,238},{209,238},{229,238},{119,238},
							
							/*linea 250*/ {32,250},{57,250},{81,250},{159,250},{185,250},{209,250},	
							
							/*linea 265*/ {10,265},{20,265},{32,265},{44,265},{57,265},{81,265},{94,265},{108,265},
								            {130,265},{143,265},{159,265},{185,265},{197,265},{209,265},{229,265},
							
							/*linea 276*/ {10,276},{108,276},{130,276},{229,276},
							
							/*linea 287*/{10,287},{24,287},{31,287},{38,287},{45,287},{52,287},{59,287},{66,287},{73,287},{80,287},{87,287},
														{94,287},{108,287},{130,287},{144,287},{153,287},{160,287},{167,287},{174,287},{181,287},
                            {188,287},{195,287},{202,287},{209,287},{216,287},{229,287},{119,287},
													};


volatile int x=120;
volatile int y=135;
						 
static int numVite=1;
						 
extern int i;
						 
volatile int punteggio=0;
						 
volatile int pillsMangiate=0;
						 
/*************CREA LABIRINTO*************/				 
void crea_labirinto(void)
{
	//bordi
	LCD_DrawLine(0,35,240,35,Blue);
	LCD_DrawLine(0,36,240,36,Blue);
	LCD_DrawLine(0,37,240,37,Blue);
	LCD_DrawLine(0,38,240,38,Blue);
	
	LCD_DrawLine(0,295,240,295,Blue);
	LCD_DrawLine(0,296,240,296,Blue);
	LCD_DrawLine(0,297,240,297,Blue);
	LCD_DrawLine(0,298,240,298,Blue);
	
	LCD_DrawLine(0,35,0,117,Blue);
	LCD_DrawLine(1,35,1,117,Blue);
	LCD_DrawLine(2,35,2,117,Blue);
	
	LCD_DrawLine(239,35,239,117,Blue);
	LCD_DrawLine(238,35,238,117,Blue);
	LCD_DrawLine(237,35,237,117,Blue);
	
	LCD_DrawLine(0,204,0,295,Blue);
	LCD_DrawLine(1,204,1,295,Blue);
	LCD_DrawLine(2,204,2,295,Blue);	
		
	LCD_DrawLine(239,204,239,295,Blue);
	LCD_DrawLine(238,204,238,295,Blue);
	LCD_DrawLine(237,204,237,295,Blue);
	
	//rettangolo centrale
	LCD_DrawLine(90,143,150,143,Blue);
	LCD_DrawLine(89,142,151,142,Blue);
	
	LCD_DrawLine(90,178,150,178,Blue);
	LCD_DrawLine(89,179,151,179,Blue);
	
	LCD_DrawLine(89,142,89,179,Blue);
	LCD_DrawLine(90,143,90,178,Blue);
	
	LCD_DrawLine(150,143,150,178,Blue);
	LCD_DrawLine(151,142,151,179,Blue);
	
	//corridoio centrale
	LCD_DrawLine(0,147,49,147,Blue);
	LCD_DrawLine(0,148,49,148,Blue);
	LCD_DrawLine(0,149,49,149,Blue);
	LCD_DrawLine(0,150,49,150,Blue);
	
	LCD_DrawLine(0,166,49,166,Blue);
	LCD_DrawLine(0,167,49,167,Blue);
	LCD_DrawLine(0,168,49,168,Blue);
	LCD_DrawLine(0,169,49,169,Blue);
	
	
	LCD_DrawLine(193,147,240,147,Blue);
	LCD_DrawLine(193,148,240,148,Blue);
	LCD_DrawLine(193,149,240,149,Blue);
	LCD_DrawLine(193,150,240,150,Blue);
	
	LCD_DrawLine(193,166,240,166,Blue);
	LCD_DrawLine(193,167,240,167,Blue);
	LCD_DrawLine(193,168,240,168,Blue);
	LCD_DrawLine(193,169,240,169,Blue);
	
	
	//contiuazione bordo
	LCD_DrawLine(0,115,49,115,Blue);
	LCD_DrawLine(0,116,49,116,Blue);
	LCD_DrawLine(0,117,49,117,Blue);
	
	LCD_DrawLine(49,115,49,150,Blue);
	LCD_DrawLine(48,115,48,150,Blue);
	LCD_DrawLine(47,115,47,150,Blue);
	
	LCD_DrawLine(193,115,240,115,Blue);
	LCD_DrawLine(193,116,240,116,Blue);
	LCD_DrawLine(193,117,240,117,Blue);
	
	LCD_DrawLine(193,115,193,150,Blue);
	LCD_DrawLine(194,115,194,150,Blue);
	LCD_DrawLine(195,115,195,150,Blue);
	
	LCD_DrawLine(49,166,49,204,Blue);
	LCD_DrawLine(48,166,48,204,Blue);
	LCD_DrawLine(47,166,47,204,Blue);
	
	LCD_DrawLine(0,204,49,204,Blue);
	LCD_DrawLine(0,203,49,203,Blue);
	LCD_DrawLine(0,202,49,202,Blue);


	LCD_DrawLine(193,166,193,204,Blue);
	LCD_DrawLine(194,166,194,204,Blue);
	LCD_DrawLine(195,166,195,204,Blue);

	LCD_DrawLine(193,204,240,204,Blue);
	LCD_DrawLine(193,203,240,203,Blue);
	LCD_DrawLine(193,202,240,202,Blue);
	
		// | in alto
	LCD_DrawLine(117,37,117,74,Blue);
	LCD_DrawLine(118,37,118,74,Blue);
	LCD_DrawLine(119,37,119,74,Blue);
	LCD_DrawLine(122,37,122,74,Blue);
	LCD_DrawLine(121,37,121,74,Blue);
	LCD_DrawLine(120,37,120,74,Blue);
	LCD_DrawLine(117,74,122,74,Blue);

	
	//quadratini in alto a sx e dx
	LCD_DrawLine(18,54,49,54,Blue);
	LCD_DrawLine(18,55,49,55,Blue);
	LCD_DrawLine(18,74,49,74,Blue);
	LCD_DrawLine(18,73,49,73,Blue);
	LCD_DrawLine(18,54,18,74,Blue);
	LCD_DrawLine(19,54,19,74,Blue);
	LCD_DrawLine(49,54,49,74,Blue);
	LCD_DrawLine(48,54,48,74,Blue);
	
	LCD_DrawLine(193,54,221,54,Blue);
	LCD_DrawLine(193,55,221,55,Blue);
	LCD_DrawLine(193,74,221,74,Blue);
	LCD_DrawLine(193,73,221,73,Blue);
	LCD_DrawLine(221,54,221,74,Blue);
	LCD_DrawLine(220,54,220,74,Blue);
	LCD_DrawLine(193,54,193,74,Blue);
	LCD_DrawLine(194,54,194,74,Blue);
	
		
	//rettangolini in alto centrali
	LCD_DrawLine(65,54,100,54,Blue);
	LCD_DrawLine(65,55,100,55,Blue);
	LCD_DrawLine(65,74,100,74,Blue);
	LCD_DrawLine(65,73,100,73,Blue);
	LCD_DrawLine(65,54,65,74,Blue);
	LCD_DrawLine(66,54,66,74,Blue);
	LCD_DrawLine(100,54,100,74,Blue);
	LCD_DrawLine(99,54,99,74,Blue);
	
	LCD_DrawLine(139,54,177,54,Blue);
	LCD_DrawLine(139,55,177,55,Blue);
	LCD_DrawLine(139,74,177,74,Blue);
	LCD_DrawLine(139,73,177,73,Blue);
	LCD_DrawLine(139,54,139,74,Blue);
	LCD_DrawLine(140,54,140,74,Blue);
	LCD_DrawLine(177,54,177,74,Blue);
	LCD_DrawLine(176,54,176,74,Blue);
	
	//rettangolini a sx e dx , parte alta
	LCD_DrawLine(18,90,49,90,Blue);
	LCD_DrawLine(18,91,49,91,Blue);
	LCD_DrawLine(18,99,49,99,Blue);
	LCD_DrawLine(18,98,49,98,Blue);
	LCD_DrawLine(18,90,18,99,Blue);
	LCD_DrawLine(19,90,19,99,Blue);
	LCD_DrawLine(49,90,49,99,Blue);
	LCD_DrawLine(48,90,48,99,Blue);
	
	LCD_DrawLine(193,90,221,90,Blue);
	LCD_DrawLine(193,91,221,91,Blue);
	LCD_DrawLine(193,99,221,99,Blue);
	LCD_DrawLine(193,98,221,98,Blue);
	LCD_DrawLine(221,90,221,99,Blue);
	LCD_DrawLine(220,90,220,99,Blue);
	LCD_DrawLine(193,90,193,99,Blue);
	LCD_DrawLine(194,90,194,99,Blue);
	
	//T in alto centrale
	LCD_DrawLine(89,90,151,90,Blue);
	LCD_DrawLine(89,91,151,91,Blue);
	LCD_DrawLine(89,90,89,99,Blue);
	LCD_DrawLine(90,90,90,99,Blue);
	LCD_DrawLine(151,90,151,99,Blue);
	LCD_DrawLine(150,90,150,99,Blue);
	LCD_DrawLine(89,99,117,99,Blue);
	LCD_DrawLine(89,98,117,98,Blue);
	LCD_DrawLine(122,99,151,99,Blue);
	LCD_DrawLine(122,98,151,98,Blue);
	LCD_DrawLine(117,123,122,123,Blue);
	LCD_DrawLine(117,122,122,122,Blue);
	LCD_DrawLine(117,99,117,123,Blue);
	LCD_DrawLine(118,99,118,123,Blue);
	LCD_DrawLine(122,99,122,123,Blue);
	LCD_DrawLine(121,99,121,123,Blue);
	
		//T laterale a sx
	LCD_DrawLine(65,90,65,150,Blue);
	LCD_DrawLine(66,90,66,150,Blue);
	LCD_DrawLine(65,90,73,90,Blue);
	LCD_DrawLine(65,89,73,89,Blue);
	LCD_DrawLine(65,150,73,150,Blue);
	LCD_DrawLine(65,149,73,149,Blue);
	LCD_DrawLine(73,90,73,115,Blue);
	LCD_DrawLine(72,90,72,115,Blue);
	LCD_DrawLine(73,123,73,150,Blue);
	LCD_DrawLine(72,123,72,150,Blue);
	LCD_DrawLine(73,115,100,115,Blue);
	LCD_DrawLine(73,116,100,116,Blue);
	LCD_DrawLine(73,123,100,123,Blue);
	LCD_DrawLine(73,122,100,122,Blue);
	LCD_DrawLine(100,115,100,123,Blue);
	LCD_DrawLine(99,115,99,123,Blue);
	
	//T laterale a dx
	LCD_DrawLine(177,90,177,150,Blue);
	LCD_DrawLine(176,90,176,150,Blue);
	LCD_DrawLine(167,90,177,90,Blue);
	LCD_DrawLine(167,91,177,91,Blue);
	LCD_DrawLine(167,150,177,150,Blue);
	LCD_DrawLine(167,149,177,149,Blue);
	LCD_DrawLine(167,90,167,115,Blue);
	LCD_DrawLine(168,90,168,115,Blue);
	LCD_DrawLine(167,123,167,150,Blue);
	LCD_DrawLine(168,123,168,150,Blue);
	LCD_DrawLine(167,115,139,115,Blue);
	LCD_DrawLine(167,116,139,116,Blue);
	LCD_DrawLine(167,123,139,123,Blue);
	LCD_DrawLine(167,122,139,122,Blue);
	LCD_DrawLine(139,115,139,123,Blue);
	LCD_DrawLine(140,115,140,123,Blue);
	
	// | a sx
	LCD_DrawLine(65,166,65,204,Blue);
	LCD_DrawLine(66,166,66,204,Blue);
	LCD_DrawLine(73,166,73,204,Blue);
	LCD_DrawLine(72,166,72,204,Blue);
	LCD_DrawLine(65,166,73,166,Blue);
	LCD_DrawLine(65,167,73,167,Blue);
	LCD_DrawLine(65,204,73,204,Blue);
	LCD_DrawLine(65,203,73,203,Blue);
	
	// | a dx
	LCD_DrawLine(167,166,167,204,Blue);
	LCD_DrawLine(168,166,168,204,Blue);
	LCD_DrawLine(177,166,177,204,Blue);
	LCD_DrawLine(176,166,176,204,Blue);
	LCD_DrawLine(167,166,177,166,Blue);
	LCD_DrawLine(167,167,177,167,Blue);
	LCD_DrawLine(167,204,177,204,Blue);
	LCD_DrawLine(167,203,177,203,Blue);
	
	//L rovesciata in basso a sx
	LCD_DrawLine(18,220,18,230,Blue);
	LCD_DrawLine(19,220,19,230,Blue);
  LCD_DrawLine(18,230,41,230,Blue);
	LCD_DrawLine(18,229,41,229,Blue);
	LCD_DrawLine(41,230,41,257,Blue);
	LCD_DrawLine(42,230,42,257,Blue);
	LCD_DrawLine(42,257,49,257,Blue);
	LCD_DrawLine(41,256,49,256,Blue);
  LCD_DrawLine(49,220,49,257,Blue);
	LCD_DrawLine(48,220,48,257,Blue);
	LCD_DrawLine(18,220,49,220,Blue);
	LCD_DrawLine(18,221,49,221,Blue);
	
	//L rovesciata in basso a dx
	LCD_DrawLine(221,220,221,230,Blue);
	LCD_DrawLine(220,220,220,230,Blue);
  LCD_DrawLine(201,230,221,230,Blue);
	LCD_DrawLine(201,229,221,229,Blue);
	LCD_DrawLine(201,230,201,257,Blue);
	LCD_DrawLine(200,230,200,257,Blue);
	LCD_DrawLine(193,257,201,257,Blue);
	LCD_DrawLine(193,256,201,256,Blue);
  LCD_DrawLine(193,220,193,257,Blue);
	LCD_DrawLine(194,220,194,257,Blue);
	LCD_DrawLine(193,220,221,220,Blue);
	LCD_DrawLine(193,221,221,221,Blue);
	
		//1 T della parte inferiore
	LCD_DrawLine(89,195,151,195,Blue);
	LCD_DrawLine(89,196,151,196,Blue);
	LCD_DrawLine(89,195,89,204,Blue);
	LCD_DrawLine(90,195,90,204,Blue);
	LCD_DrawLine(151,195,151,204,Blue);
	LCD_DrawLine(150,195,150,204,Blue);
	LCD_DrawLine(89,204,117,204,Blue);
	LCD_DrawLine(89,203,117,203,Blue);
	LCD_DrawLine(122,204,151,204,Blue);
	LCD_DrawLine(122,203,151,203,Blue);
  LCD_DrawLine(117,204,117,230,Blue);
	LCD_DrawLine(118,204,118,230,Blue);
	LCD_DrawLine(122,204,122,230,Blue);
	LCD_DrawLine(121,204,121,230,Blue);
	LCD_DrawLine(117,230,122,230,Blue);
	LCD_DrawLine(117,229,122,229,Blue);
	
	//rettangolo orizzontale basso sx
	LCD_DrawLine(65,220,100,220,Blue);
	LCD_DrawLine(65,221,100,221,Blue);
	LCD_DrawLine(65,230,100,230,Blue);
	LCD_DrawLine(65,229,100,229,Blue);
	LCD_DrawLine(65,220,65,230,Blue);
	LCD_DrawLine(66,220,66,230,Blue);
	LCD_DrawLine(100,220,100,230,Blue);
	LCD_DrawLine(99,220,99,230,Blue);
	
	//rettangolo orizzontale basso dx
	LCD_DrawLine(139,220,177,220,Blue);
	LCD_DrawLine(139,221,177,221,Blue);
  LCD_DrawLine(139,230,177,230,Blue);
	LCD_DrawLine(139,229,177,229,Blue);
	LCD_DrawLine(139,220,139,230,Blue);
	LCD_DrawLine(140,220,140,230,Blue);
	LCD_DrawLine(177,220,177,230,Blue);
	LCD_DrawLine(176,220,176,230,Blue);
	
	//2 T della parte inferiore
	LCD_DrawLine(89,246,151,246,Blue);
	LCD_DrawLine(89,247,151,247,Blue);
	LCD_DrawLine(89,246,89,257,Blue);
	LCD_DrawLine(90,246,90,257,Blue);
	LCD_DrawLine(151,246,151,257,Blue);
	LCD_DrawLine(150,246,150,257,Blue);
	LCD_DrawLine(89,257,117,257,Blue);
	LCD_DrawLine(89,256,117,256,Blue);
	LCD_DrawLine(122,257,151,257,Blue);
	LCD_DrawLine(122,256,151,256,Blue);
  LCD_DrawLine(117,257,117,279,Blue);
	LCD_DrawLine(118,257,118,279,Blue);
	LCD_DrawLine(122,257,122,279,Blue);
	LCD_DrawLine(121,257,121,279,Blue);
	LCD_DrawLine(117,279,122,279,Blue);
	LCD_DrawLine(117,278,122,278,Blue);
	
	//
	LCD_DrawLine(0,246,24,246,Blue);
	LCD_DrawLine(0,247,24,247,Blue);
	LCD_DrawLine(0,248,24,248,Blue);
  LCD_DrawLine(0,257,24,257,Blue);
	LCD_DrawLine(0,256,24,256,Blue);
	LCD_DrawLine(0,255,24,255,Blue);
	LCD_DrawLine(24,246,24,257,Blue);
	LCD_DrawLine(23,246,23,257,Blue);
	LCD_DrawLine(22,246,22,257,Blue);
	
	LCD_DrawLine(218,246,240,246,Blue);
	LCD_DrawLine(218,247,240,247,Blue);
	LCD_DrawLine(218,248,240,248,Blue);
  LCD_DrawLine(218,257,240,257,Blue);
	LCD_DrawLine(218,256,240,256,Blue);
	LCD_DrawLine(218,255,240,255,Blue);
	LCD_DrawLine(218,246,218,257,Blue);
	LCD_DrawLine(219,246,219,257,Blue);
	LCD_DrawLine(220,246,220,257,Blue);
	
		
	//forma strana a sx
	LCD_DrawLine(65,246,65,273,Blue);
	LCD_DrawLine(66,246,66,273,Blue);
	LCD_DrawLine(65,246,73,246,Blue);
	LCD_DrawLine(65,247,73,247,Blue);
	LCD_DrawLine(73,246,73,273,Blue);
	LCD_DrawLine(72,246,72,273,Blue);
	LCD_DrawLine(73,273,100,273,Blue);
	LCD_DrawLine(73,274,100,274,Blue);
  LCD_DrawLine(100,273,100,279,Blue);
	LCD_DrawLine(99,273,99,279,Blue);
	LCD_DrawLine(18,279,100,279,Blue);
	LCD_DrawLine(18,278,100,278,Blue);
	LCD_DrawLine(18,273,18,279,Blue);
	LCD_DrawLine(19,273,19,279,Blue);
	LCD_DrawLine(18,273,65,273,Blue);
	LCD_DrawLine(18,274,65,274,Blue);
	
	//forma strana a dx
	LCD_DrawLine(177,246,177,273,Blue);
	LCD_DrawLine(176,246,176,273,Blue);
	LCD_DrawLine(167,246,177,246,Blue);
	LCD_DrawLine(167,247,177,247,Blue);
	LCD_DrawLine(167,246,167,273,Blue);
	LCD_DrawLine(168,246,168,273,Blue);
	LCD_DrawLine(139,273,167,273,Blue);
	LCD_DrawLine(139,274,167,274,Blue);
  LCD_DrawLine(139,273,139,279,Blue);
	LCD_DrawLine(140,273,140,279,Blue);
	LCD_DrawLine(139,279,221,279,Blue);
	LCD_DrawLine(139,278,221,278,Blue);
	LCD_DrawLine(221,273,221,279,Blue);
	LCD_DrawLine(220,273,220,279,Blue);
	LCD_DrawLine(177,273,221,273,Blue);	
	LCD_DrawLine(177,274,221,274,Blue);	
	
	//

	
	return;	
}


/************* CREA VITA *************/
void crea_vita(void)
{
int pos=numVite*15;
	
LCD_DrawLine(pos-2,300,pos+2,300,Yellow);
LCD_DrawLine(pos-4,301,pos+4,301,Yellow);
LCD_DrawLine(pos-4,302,pos+5,302,Yellow);
LCD_DrawLine(pos-5,303,pos+3,303,Yellow);
LCD_DrawLine(pos-5,304,pos+1,304,Yellow);
LCD_DrawLine(pos-5,305,pos,305,Yellow);
LCD_DrawLine(pos-5,306,pos+1,306,Yellow);
LCD_DrawLine(pos-5,307,pos+3,307,Yellow);
LCD_DrawLine(pos-4,308,pos+5,308,Yellow);
LCD_DrawLine(pos-4,309,pos+4,309,Yellow);
LCD_DrawLine(pos-2,310,pos+2,310,Yellow);

numVite=numVite+1;	
	
return;
}

/************* *************/
void conf_schermo(void)
{
	GUI_Text(0, 0,(uint8_t *) " Game Over in ", White, Black);
	GUI_Text(120, 0,(uint8_t *) " SCORE ", White, Black);
	GUI_Text(120, 15,(uint8_t *) " 00 ", White, Black);
	GUI_Text(95,150,(uint8_t *) " PAUSE" , Yellow, Black);
	GUI_Text(40, 15,(uint8_t *) "60s", White, Black);
	
LCD_DrawLine(x-5,y-2,x-5,y+2,Yellow);
LCD_DrawLine(x-4,y-4,x-4,y+4,Yellow);
LCD_DrawLine(x-3,y-4,x-3,y+4,Yellow);
LCD_DrawLine(x-2,y+5,x-2,y-5,Yellow);
LCD_DrawLine(x-1,y+5,x-1,y-5,Yellow);
LCD_DrawLine(x,y+5,x,y-5,Yellow);
LCD_DrawLine(x+1,y+5,x+1,y-5,Yellow);
LCD_DrawLine(x+2,y+5,x+2,y-5,Yellow);
LCD_DrawLine(x+3,y-4,x+3,y+4,Yellow);
LCD_DrawLine(x+4,y-4,x+4,y+4,Yellow);
LCD_DrawLine(x+5,y-2,x+5,y+2,Yellow);
	
	return;
}





/************** CREAZIONE PILLS *************/

/************** STANDARD PILLS *************/
void standard_pills(void)
{
int i;

	for(i=0;i<N;i++){
		LCD_DrawLine(m[i][0],m[i][1],m[i][0],m[i][1]+1,Yellow);
		LCD_DrawLine(m[i][0]+1,m[i][1],m[i][0]+1,m[i][1]+1,Yellow);
	}

	return;
}



/************* POWER PILLS *************/

int presente(int v[],int cont , int n){
	int i;
	for(i=0;i<cont;i++){
		if(v[i]==n){
			return 1;
		}
	}
	return 0;
}

void power_pills(void){
int i;
int n;
int x1;
int y1;
int cont=0;
int v[6];

	for(i=0;i<6;i++){
		do{
			srand(LPC_TIM2->TC);
			n=rand()%240;
			x1=m[n][0];
			y1=m[n][1];
			}while(LCD_GetPoint(x1-6,y1)==Black || presente(v,cont,n)==1);
		
			v[cont]=n;
			cont++;

		LCD_DrawLine(m[n][0]-1,m[n][1]-2,m[n][0]-1,m[n][1]+1,Orange);
		LCD_DrawLine(m[n][0],m[n][1]-2,m[n][0],m[n][1]+1,Orange);
		LCD_DrawLine(m[n][0]+1,m[n][1]-2,m[n][0]+1,m[n][1]+1,Orange);
		LCD_DrawLine(m[n][0]+2,m[n][1]-2,m[n][0]+2,m[n][1]+1,Orange);
		}
	
	disable_timer(1);
	
	return;
}



/************* MOVIMENTI PACMAN *************/

/************* UP *************/
void move_up(){

uint16_t color1=LCD_GetPoint(x-5,y-6);
uint16_t color2=LCD_GetPoint(x-11,y-6);
uint16_t color3=LCD_GetPoint(x,y-6);
uint16_t color4=LCD_GetPoint(x-10,y-6);
	
uint16_t color5=LCD_GetPoint(x,y-6);
uint16_t color6=LCD_GetPoint(x-2,y-6);
uint16_t color7=LCD_GetPoint(x-4,y-6);
uint16_t color8=LCD_GetPoint(x-6,y-6);
uint16_t color9=LCD_GetPoint(x-8,y-6);
uint16_t color10=LCD_GetPoint(x-10,y-6);
	
if(color1==Blue || color2==Blue || color3==Blue){  //controllo se c'è un muro , se la risposta è sì pacman si ferma
	i=0;
	
}else{

	if(color5==Yellow || color6==Yellow || color7==Yellow || color8==Yellow || color9==Yellow || color10==Yellow){ //controllo se c'è una standard pills
		char score[3];
		punteggio=punteggio+10;
		sprintf(score," %d",punteggio);
		LCD_DrawLine(x-5,y-6,x+5,y-6,Black);
		LCD_DrawLine(x-5,y-7,x+5,y-7,Black);
		GUI_Text(120, 15,(uint8_t *) score, White, Black);
		
		pillsMangiate++;
		
		if(punteggio==1000 || punteggio==2000){
			crea_vita();
		}
	}else if(color5==Orange || color6==Orange || color7==Orange || color8==Orange || color9==Orange || color10==Orange){ //controllo se c'è una power pills
		char score[3];
		int prec=punteggio;
		punteggio=punteggio+50;
		sprintf(score," %d",punteggio);
		LCD_DrawLine(x-5,y-6,x+5,y-6,Black);
		LCD_DrawLine(x-5,y-7,x+5,y-7,Black);
		LCD_DrawLine(x-5,y-8,x+5,y-8,Black);
		LCD_DrawLine(x-5,y-9,x+5,y-9,Black);
		GUI_Text(120, 15,(uint8_t *) score, White, Black);
		
		pillsMangiate++;
	
			if((punteggio>=1000 && prec<1000) || (punteggio>=2000 && prec<2000)){
				crea_vita();
			}
	}		
	
	//pacman si muove
	
	LCD_DrawLine(x-5,y+5,x+5,y+5,Black);
	LCD_DrawLine(x-5,y+4,x+5,y+4,Black);
	LCD_DrawLine(x-2,y+4,x+2,y+4,Yellow);	
	LCD_DrawLine(x-4,y+3,x+4,y+3,Yellow);
	LCD_DrawLine(x-5,y+2,x+5,y+2,Black);
	LCD_DrawLine(x-4,y+2,x+4,y+2,Yellow);	
	LCD_DrawLine(x-5,y+1,x+5,y+1,Yellow);
	LCD_DrawLine(x-5,y,x+5,y,Yellow);
	LCD_DrawLine(x-5,y-1,x+5,y-1,Yellow);
	LCD_DrawLine(x-5,y-2,x+5,y-2,Yellow);
	LCD_DrawLine(x-5,y-3,x+5,y-3,Yellow);
	LCD_DrawLine(x-4,y-4,x+4,y-4,Yellow);
	LCD_DrawLine(x-4,y-5,x+4,y-5,Yellow);	
	LCD_DrawLine(x-2,y-6,x+2,y-6,Yellow);

	y=y-1; 
}
	return;
}



void move_up2(){

uint16_t color1=LCD_GetPoint(x-5,y-6);
uint16_t color2=LCD_GetPoint(x-11,y-6);
uint16_t color3=LCD_GetPoint(x,y-6);
uint16_t color4=LCD_GetPoint(x-10,y-6);
	
uint16_t color5=LCD_GetPoint(x,y-6);
uint16_t color6=LCD_GetPoint(x-2,y-6);
uint16_t color7=LCD_GetPoint(x-4,y-6);
uint16_t color8=LCD_GetPoint(x-6,y-6);
uint16_t color9=LCD_GetPoint(x-8,y-6);
uint16_t color10=LCD_GetPoint(x-10,y-6);
	
if(color1==Blue || color2==Blue || color3==Blue){
	i=0;
}else{

	if(color5==Yellow || color6==Yellow || color7==Yellow || color8==Yellow || color9==Yellow || color10==Yellow){
		char score[3];
		punteggio=punteggio+10;
		sprintf(score," %d",punteggio);
		LCD_DrawLine(x-5,y-6,x+5,y-6,Black);
		LCD_DrawLine(x-5,y-7,x+5,y-7,Black);
		GUI_Text(120, 15,(uint8_t *) score, White, Black);
	
		pillsMangiate++;
		
		if(punteggio==1000 || punteggio==2000){
			crea_vita();
		}
	}else if(color5==Orange || color6==Orange || color7==Orange || color8==Orange || color9==Orange || color10==Orange){
		char score[3];
		int prec=punteggio;
		punteggio=punteggio+50;
		sprintf(score," %d",punteggio);
		LCD_DrawLine(x-5,y-6,x+5,y-6,Black);
		LCD_DrawLine(x-5,y-7,x+5,y-7,Black);
		LCD_DrawLine(x-5,y-8,x+5,y-8,Black);
		LCD_DrawLine(x-5,y-9,x+5,y-9,Black);
		GUI_Text(120, 15,(uint8_t *) score, White, Black);
		
		pillsMangiate++;
	
			if((punteggio>=1000 && prec<1000) || (punteggio>=2000 && prec<2000)){
				crea_vita();
			}
	}		
	
	LCD_DrawLine(x-5,y+5,x+5,y+5,Black);
	LCD_DrawLine(x-5,y+4,x+5,y+4,Black);
	LCD_DrawLine(x-2,y+4,x+2,y+4,Yellow);	
	LCD_DrawLine(x-4,y+3,x+4,y+3,Yellow);
	LCD_DrawLine(x-5,y+2,x+5,y+2,Black);
	LCD_DrawLine(x-4,y+2,x+4,y+2,Yellow);	
	LCD_DrawLine(x-5,y+1,x+5,y+1,Yellow);
	LCD_DrawLine(x-5,y,x+5,y,Yellow);
	LCD_DrawLine(x-5,y-1,x+5,y-1,Yellow);
	LCD_DrawLine(x-5,y-2,x+5,y-2,Yellow);
	LCD_DrawLine(x,y-2,x,y-2,Black);
	LCD_DrawLine(x-5,y-3,x+5,y-3,Yellow);
	LCD_DrawLine(x-1,y-3,x+1,y-3,Black);
	LCD_DrawLine(x-4,y-4,x+4,y-4,Yellow);
	LCD_DrawLine(x-1,y-4,x+1,y-4,Black);
	LCD_DrawLine(x-4,y-5,x+4,y-5,Yellow);	
	LCD_DrawLine(x-2,y-5,x+3,y-5,Black);	
	LCD_DrawLine(x-3,y-6,x+3,y-6,Yellow);
	LCD_DrawLine(x-2,y-6,x+2,y-6,Black);

	y=y-1;
}
	return;
}


/************* DOWN *************/
void move_down(){
	
uint16_t color1=LCD_GetPoint(x-5,y+6);
uint16_t color2=LCD_GetPoint(x,y+6);
uint16_t color3=LCD_GetPoint(x-11,y+6);
uint16_t color4=LCD_GetPoint(x-10,y+6);

uint16_t color5=LCD_GetPoint(x,y+6);
uint16_t color6=LCD_GetPoint(x-2,y+6);
uint16_t color7=LCD_GetPoint(x-4,y+6);
uint16_t color8=LCD_GetPoint(x-6,y+6);
uint16_t color9=LCD_GetPoint(x-8,y+6);
uint16_t color10=LCD_GetPoint(x-10,y+6);
	
if(color1==Blue || color2==Blue || color3==Blue || color4==Blue){
	i=0;
}else{
	
	if(color5==Yellow || color6==Yellow || color7==Yellow || color8==Yellow || color9==Yellow || color10==Yellow){
		char score[3];
		punteggio=punteggio+10;
		sprintf(score," %d",punteggio);
		LCD_DrawLine(x-5,y+6,x+5,y+6,Black);
		LCD_DrawLine(x-5,y+7,x+5,y+7,Black);
		GUI_Text(120, 15,(uint8_t *) score, White, Black);
		
		pillsMangiate++;
	
			if(punteggio==1000 || punteggio==2000){
			crea_vita();
			}
	}else if(color5==Orange || color6==Orange || color7==Orange || color8==Orange || color9==Orange || color10==Orange){
		char score[3];
		int prec=punteggio;
		punteggio=punteggio+50;
		sprintf(score," %d",punteggio);
		LCD_DrawLine(x-5,y+6,x+5,y+6,Black);
		LCD_DrawLine(x-5,y+7,x+5,y+7,Black);
		LCD_DrawLine(x-5,y+8,x+5,y+8,Black);
		LCD_DrawLine(x-5,y+9,x+5,y+9,Black);
		GUI_Text(120, 15,(uint8_t *) score, White, Black);
		
		pillsMangiate++;
	
			if((punteggio>=1000 && prec<1000) || (punteggio>=2000 && prec<2000)){
				crea_vita();
			}
	}	
	
	LCD_DrawLine(x-5,y-5,x+5,y-5,Black);
	LCD_DrawLine(x-5,y-4,x+5,y-4,Black);
	LCD_DrawLine(x-2,y-4,x+2,y-4,Yellow);
	LCD_DrawLine(x-4,y-3,x+4,y-3,Yellow);
	LCD_DrawLine(x-5,y-2,x+5,y-2,Black);
	LCD_DrawLine(x-4,y-2,x+4,y-2,Yellow);
	LCD_DrawLine(x-5,y-1,x+5,y-1,Yellow);
	LCD_DrawLine(x-5,y,x+5,y,Yellow);
	LCD_DrawLine(x-5,y+1,x+5,y+1,Yellow);
	LCD_DrawLine(x-5,y+2,x+5,y+2,Yellow);
	LCD_DrawLine(x-5,y+3,x+5,y+3,Yellow);
	LCD_DrawLine(x-4,y+4,x+4,y+4,Yellow);
	LCD_DrawLine(x-4,y+5,x+4,y+5,Yellow);
	LCD_DrawLine(x-2,y+6,x+2,y+6,Yellow);

	y=y+1;
	}
	return;
}

void move_down2(){
	
uint16_t color1=LCD_GetPoint(x-5,y+6);
uint16_t color2=LCD_GetPoint(x,y+6);
uint16_t color3=LCD_GetPoint(x-11,y+6);
uint16_t color4=LCD_GetPoint(x-10,y+6);

uint16_t color5=LCD_GetPoint(x,y+6);
uint16_t color6=LCD_GetPoint(x-2,y+6);
uint16_t color7=LCD_GetPoint(x-4,y+6);
uint16_t color8=LCD_GetPoint(x-6,y+6);
uint16_t color9=LCD_GetPoint(x-8,y+6);
uint16_t color10=LCD_GetPoint(x-10,y+6);
	
if(color1==Blue || color2==Blue || color3==Blue || color4==Blue){
	i=0;
}else{
	
	if(color5==Yellow || color6==Yellow || color7==Yellow || color8==Yellow || color9==Yellow || color10==Yellow){
		char score[3];
		punteggio=punteggio+10;
		sprintf(score," %d",punteggio);
		LCD_DrawLine(x-5,y+6,x+5,y+6,Black);
		LCD_DrawLine(x-5,y+7,x+5,y+7,Black);
		GUI_Text(120, 15,(uint8_t *) score, White, Black);
		
		pillsMangiate++;
	
			if(punteggio==1000 || punteggio==2000){
			crea_vita();
			}
	}else if(color5==Orange || color6==Orange || color7==Orange || color8==Orange || color9==Orange || color10==Orange){
		char score[3];
		int prec=punteggio;
		punteggio=punteggio+50;
		sprintf(score," %d",punteggio);
		LCD_DrawLine(x-5,y+6,x+5,y+6,Black);
		LCD_DrawLine(x-5,y+7,x+5,y+7,Black);
		LCD_DrawLine(x-5,y+8,x+5,y+8,Black);
		LCD_DrawLine(x-5,y+9,x+5,y+9,Black);
		GUI_Text(120, 15,(uint8_t *) score, White, Black);
		
		pillsMangiate++;
	
			if((punteggio>=1000 && prec<1000) || (punteggio>=2000 && prec<2000)){
				crea_vita();
			}
	}	
	
	LCD_DrawLine(x-5,y-5,x+5,y-5,Black);
	LCD_DrawLine(x-5,y-4,x+5,y-4,Black);
	LCD_DrawLine(x-2,y-4,x+2,y-4,Yellow);
	LCD_DrawLine(x-4,y-3,x+4,y-3,Yellow);
	LCD_DrawLine(x-5,y-2,x+5,y-2,Black);
	LCD_DrawLine(x-4,y-2,x+4,y-2,Yellow);
	LCD_DrawLine(x-5,y-1,x+5,y-1,Yellow);
	LCD_DrawLine(x-5,y,x+5,y,Yellow);
	LCD_DrawLine(x-5,y+1,x+5,y+1,Yellow);
	LCD_DrawLine(x-5,y+2,x+5,y+2,Yellow);
	LCD_DrawLine(x-1,y+2,x+1,y+2,Black);
	LCD_DrawLine(x-5,y+3,x+5,y+3,Yellow);
	LCD_DrawLine(x-1,y+3,x+1,y+3,Black);
	LCD_DrawLine(x-4,y+4,x+4,y+4,Yellow);
	LCD_DrawLine(x-1,y+4,x+1,y+4,Black);
	LCD_DrawLine(x-4,y+5,x+4,y+5,Yellow);
	LCD_DrawLine(x-2,y+5,x+2,y+5,Black);
	LCD_DrawLine(x-3,y+6,x+3,y+6,Yellow);
	LCD_DrawLine(x-2,y+6,x+2,y+6,Black);

	y=y+1;
	}
	return;
}

/************* LEFT *************/
void move_left(){

uint16_t color1=LCD_GetPoint(x-12,y);
uint16_t color2=LCD_GetPoint(x-12,y-5);
uint16_t color3=LCD_GetPoint(x-12,y+5);
	
	
uint16_t color5=LCD_GetPoint(x-12,y-5);
uint16_t color6=LCD_GetPoint(x-12,y-3);
uint16_t color7=LCD_GetPoint(x-12,y-1);
uint16_t color8=LCD_GetPoint(x-12,y+1);
uint16_t color9=LCD_GetPoint(x-12,y+3);
uint16_t color10=LCD_GetPoint(x-12,y+5);
	
if(color1==Blue || color2==Blue || color3==Blue || (((x-9)<=2) && (((y-5)<146) || ((y+5)>173))) ){
	i=0;
}else{
	
	if(color5==Yellow || color6==Yellow || color7==Yellow || color8==Yellow || color9==Yellow || color10==Yellow){
		char score[3];
		punteggio=punteggio+10;
		sprintf(score," %d",punteggio);
		LCD_DrawLine(x-6,y-5,x-6,y+5,Black);
		LCD_DrawLine(x-7,y-5,x-7,y+5,Black);
		GUI_Text(120, 15,(uint8_t *) score, White, Black);
		
		pillsMangiate++;
	
		if(punteggio==1000 || punteggio==2000){
			crea_vita();
		}
	}else if(color5==Orange || color6==Orange || color7==Orange || color8==Orange || color9==Orange || color10==Orange){
		char score[3];
		int prec=punteggio;
		punteggio=punteggio+50;
		sprintf(score," %d",punteggio);
		LCD_DrawLine(x-6,y-5,x-6,y+5,Black);
		LCD_DrawLine(x-7,y-5,x-7,y+5,Black);
		LCD_DrawLine(x-8,y-5,x-8,y+5,Black);
		LCD_DrawLine(x-9,y-5,x-9,y+5,Black);
		GUI_Text(120, 15,(uint8_t *) score, White, Black);
		
		pillsMangiate++;
	
			if((punteggio>=1000 && prec<1000) || (punteggio>=2000 && prec<2000)){
				crea_vita();
			}
	}

	LCD_DrawLine(((x+5)+240)%240,y-5,((x+5)+240)%240,y+5,Black);
	LCD_DrawLine(((x+4)+240)%240,y-5,((x+4)+240)%240,y+5,Black);
	LCD_DrawLine(((x+4)+240)%240,y-2,((x+4)+240)%240,y+2,Yellow);	
	LCD_DrawLine(((x+3)+240)%240,y-4,((x+3)+240)%240,y+4,Yellow);
	LCD_DrawLine(((x+2)+240)%240,y+5,((x+2)+240)%240,y-5,Black);
	LCD_DrawLine(((x+2)+240)%240,y-4,((x+2)+240)%240,y+4,Yellow);
	LCD_DrawLine(((x+1)+240)%240,y+5,((x+1)+240)%240,y-5,Yellow);
	LCD_DrawLine(((x)+240)%240,y+5,((x)+240)%240,y-5,Yellow);
	LCD_DrawLine(((x-1)+240)%240,y+5,((x-1)+240)%240,y-5,Yellow);
	LCD_DrawLine(((x-2)+240)%240,y+5,((x-2)+240)%240,y-5,Yellow);
	LCD_DrawLine(((x-3)+240)%240,y+5,((x-3)+240)%240,y-5,Yellow);
	LCD_DrawLine(((x-4)+240)%240,y-4,((x-4)+240)%240,y+4,Yellow);
	LCD_DrawLine(((x-5)+240)%240,y-4,((x-5)+240)%240,y+4,Yellow);
	LCD_DrawLine(((x-6)+240)%240,y-2,((x-6)+240)%240,y+2,Yellow);

	x=((x-1)+240)%240;
}
return;
}



void move_left2(){

uint16_t color1=LCD_GetPoint(x-12,y);
uint16_t color2=LCD_GetPoint(x-12,y-5);
uint16_t color3=LCD_GetPoint(x-12,y+5);
	
	
uint16_t color5=LCD_GetPoint(x-12,y-5);
uint16_t color6=LCD_GetPoint(x-12,y-3);
uint16_t color7=LCD_GetPoint(x-12,y-1);
uint16_t color8=LCD_GetPoint(x-12,y+1);
uint16_t color9=LCD_GetPoint(x-12,y+3);
uint16_t color10=LCD_GetPoint(x-12,y+5);
	
if(color1==Blue || color2==Blue || color3==Blue || (((x-9)<=2) && (((y-5)<146) || ((y+5)>173))) ){
	i=0;
}else{
	
	if(color5==Yellow || color6==Yellow || color7==Yellow || color8==Yellow || color9==Yellow || color10==Yellow){
		char score[3];
		punteggio=punteggio+10;
		sprintf(score," %d",punteggio);
		LCD_DrawLine(x-6,y-5,x-6,y+5,Black);
		LCD_DrawLine(x-7,y-5,x-7,y+5,Black);
		GUI_Text(120, 15,(uint8_t *) score, White, Black);
		
		pillsMangiate++;
	
		if(punteggio==1000 || punteggio==2000){
			crea_vita();
		}
	}else if(color5==Orange || color6==Orange || color7==Orange || color8==Orange || color9==Orange || color10==Orange){
		char score[3];
		int prec=punteggio;
		punteggio=punteggio+50;
		sprintf(score," %d",punteggio);
		LCD_DrawLine(x-6,y-5,x-6,y+5,Black);
		LCD_DrawLine(x-7,y-5,x-7,y+5,Black);
		LCD_DrawLine(x-8,y-5,x-8,y+5,Black);
		LCD_DrawLine(x-9,y-5,x-9,y+5,Black);
		GUI_Text(120, 15,(uint8_t *) score, White, Black);
		
		pillsMangiate++;
	
			if((punteggio>=1000 && prec<1000) || (punteggio>=2000 && prec<2000)){
				crea_vita();
			}
	}

	LCD_DrawLine(((x+5)+240)%240,y-5,((x+5)+240)%240,y+5,Black);
	LCD_DrawLine(((x+4)+240)%240,y-5,((x+4)+240)%240,y+5,Black);
	LCD_DrawLine(((x+4)+240)%240,y-2,((x+4)+240)%240,y+2,Yellow);	
	LCD_DrawLine(((x+3)+240)%240,y-4,((x+3)+240)%240,y+4,Yellow);
	LCD_DrawLine(((x+2)+240)%240,y+5,((x+2)+240)%240,y-5,Black);
	LCD_DrawLine(((x+2)+240)%240,y-4,((x+2)+240)%240,y+4,Yellow);
	LCD_DrawLine(((x+1)+240)%240,y+5,((x+1)+240)%240,y-5,Yellow);
	LCD_DrawLine(((x)+240)%240,y+5,((x)+240)%240,y-5,Yellow);
	LCD_DrawLine(((x-1)+240)%240,y+5,((x-1)+240)%240,y-5,Yellow);
	LCD_DrawLine(((x-2)+240)%240,y+5,((x-2)+240)%240,y-5,Yellow);
	LCD_DrawLine(((x-2)+240)%240,y,((x-2)+240)%240,y,Black);
	LCD_DrawLine(((x-3)+240)%240,y+5,((x-3)+240)%240,y-5,Yellow);
	LCD_DrawLine(((x-3)+240)%240,y-1,((x-3)+240)%240,y+1,Black);
	LCD_DrawLine(((x-4)+240)%240,y-4,((x-4)+240)%240,y+4,Yellow);
	LCD_DrawLine(((x-4)+240)%240,y-1,((x-4)+240)%240,y+1,Black);
	LCD_DrawLine(((x-5)+240)%240,y-4,((x-5)+240)%240,y+4,Yellow);
	LCD_DrawLine(((x-5)+240)%240,y-2,((x-5)+240)%240,y+2,Black);
	LCD_DrawLine(((x-6)+240)%240,y-3,((x-6)+240)%240,y+3,Yellow);
	LCD_DrawLine(((x-6)+240)%240,y-2,((x-6)+240)%240,y+2,Black);

	x=((x-1)+240)%240;
}
return;
}

/************* RIGHT *************/
void move_right(){
	
uint16_t color1=LCD_GetPoint(x,y);
uint16_t color2=LCD_GetPoint(x,y-5);
uint16_t color3=LCD_GetPoint(x,y+5);
uint16_t color4=LCD_GetPoint(x+1,y);
	
uint16_t color5=LCD_GetPoint(x,y-5);
uint16_t color6=LCD_GetPoint(x,y-3);
uint16_t color7=LCD_GetPoint(x,y-1);
uint16_t color8=LCD_GetPoint(x,y+1);
uint16_t color9=LCD_GetPoint(x,y+3);
uint16_t color10=LCD_GetPoint(x,y+5);
	
if(color1==Blue || color2==Blue || color3==Blue || color4==Blue){
	i=0;
}else{

	if(color5==Yellow || color6==Yellow || color7==Yellow || color8==Yellow || color9==Yellow || color10==Yellow){
		char score[3];
		punteggio=punteggio+10;
		sprintf(score," %d",punteggio);
		LCD_DrawLine(x+6,y-5,x+6,y+5,Black);
		LCD_DrawLine(x+7,y-5,x+7,y+5,Black);
		GUI_Text(120, 15,(uint8_t *) score, White, Black);
		
		pillsMangiate++;
	
			if(punteggio==1000 || punteggio==2000){
				crea_vita();
			}
	}else if(color5==Orange || color6==Orange || color7==Orange || color8==Orange || color9==Orange || color10==Orange){
		char score[3];
		int prec=punteggio;
		punteggio=punteggio+50;
		sprintf(score," %d",punteggio);
		LCD_DrawLine(x+6,y-5,x+6,y+5,Black);
		LCD_DrawLine(x+7,y-5,x+7,y+5,Black);
		LCD_DrawLine(x+8,y-5,x+8,y+5,Black);
		LCD_DrawLine(x+9,y-5,x+9,y+5,Black);
		GUI_Text(120, 15,(uint8_t *) score, White, Black);
		
		pillsMangiate++;
	
			if((punteggio>=1000 && prec<1000) || (punteggio>=2000 && prec<2000)){
				crea_vita();
			}
	}


	LCD_DrawLine((x-5),y-5,(x-5),y+5,Black);
	LCD_DrawLine((x-4),y-5,(x-4),y+5,Black);
	LCD_DrawLine((x-4)%240,y-2,(x-4)%240,y+2,Yellow);
	LCD_DrawLine((x-3)%240,y-4,(x-3)%240,y+4,Yellow);
	LCD_DrawLine((x-2),y-5,(x-2),y+5,Black);
	LCD_DrawLine((x-2)%240,y-4,(x-2)%240,y+4,Yellow);
	LCD_DrawLine((x-1)%240,y+5,(x-1)%240,y-5,Yellow);
	LCD_DrawLine((x)%240,y+5,(x)%240,y-5,Yellow);
	LCD_DrawLine((x+1)%240,y+5,(x+1)%240,y-5,Yellow);
	LCD_DrawLine((x+2)%240,y+5,(x+2)%240,y-5,Yellow);
	LCD_DrawLine((x+3)%240,y+5,(x+3)%240,y-5,Yellow);
	LCD_DrawLine((x+4)%240,y-4,(x+4)%240,y+4,Yellow);
	LCD_DrawLine((x+5)%240,y-4,(x+5)%240,y+4,Yellow);
	LCD_DrawLine((x+6)%240,y-2,(x+6)%240,y+2,Yellow);


	x=(x+1)%240;
	
	if(x==0){
		LCD_DrawLine(235,y-5,235,y+5,Black);
		LCD_DrawLine(236,y-5,236,y+5,Black);
		LCD_DrawLine(237,y-5,237,y+5,Black);
		LCD_DrawLine(238,y-5,238,y+5,Black);
		LCD_DrawLine(239,y-5,239,y+5,Black);
		}

	}

return;
}


void move_right2(){
	
uint16_t color1=LCD_GetPoint(x,y);
uint16_t color2=LCD_GetPoint(x,y-5);
uint16_t color3=LCD_GetPoint(x,y+5);
uint16_t color4=LCD_GetPoint(x+1,y);
	
uint16_t color5=LCD_GetPoint(x,y-5);
uint16_t color6=LCD_GetPoint(x,y-3);
uint16_t color7=LCD_GetPoint(x,y-1);
uint16_t color8=LCD_GetPoint(x,y+1);
uint16_t color9=LCD_GetPoint(x,y+3);
uint16_t color10=LCD_GetPoint(x,y+5);
	
if(color1==Blue || color2==Blue || color3==Blue || color4==Blue){
	i=0;
}else{

	if(color5==Yellow || color6==Yellow || color7==Yellow || color8==Yellow || color9==Yellow || color10==Yellow){
		char score[3];
		punteggio=punteggio+10;
		sprintf(score," %d",punteggio);
		LCD_DrawLine(x+6,y-5,x+6,y+5,Black);
		LCD_DrawLine(x+7,y-5,x+7,y+5,Black);
		GUI_Text(120, 15,(uint8_t *) score, White, Black);
		
		pillsMangiate++;
	
			if(punteggio==1000 || punteggio==2000){
				crea_vita();
			}
	}else if(color5==Orange || color6==Orange || color7==Orange || color8==Orange || color9==Orange || color10==Orange){
		char score[3];
		int prec=punteggio;
		punteggio=punteggio+50;
		sprintf(score," %d",punteggio);
		LCD_DrawLine(x+6,y-5,x+6,y+5,Black);
		LCD_DrawLine(x+7,y-5,x+7,y+5,Black);
		LCD_DrawLine(x+8,y-5,x+8,y+5,Black);
		LCD_DrawLine(x+9,y-5,x+9,y+5,Black);
		GUI_Text(120, 15,(uint8_t *) score, White, Black);
		
		pillsMangiate++;
	
			if((punteggio>=1000 && prec<1000) || (punteggio>=2000 && prec<2000)){
				crea_vita();
			}
	}


	LCD_DrawLine((x-5),y-5,(x-5),y+5,Black);
	LCD_DrawLine((x-4),y-5,(x-4),y+5,Black);
	LCD_DrawLine((x-4)%240,y-2,(x-4)%240,y+2,Yellow);
	LCD_DrawLine((x-3)%240,y-4,(x-3)%240,y+4,Yellow);
	LCD_DrawLine((x-2),y-5,(x-2),y+5,Black);
	LCD_DrawLine((x-2)%240,y-4,(x-2)%240,y+4,Yellow);
	LCD_DrawLine((x-1)%240,y+5,(x-1)%240,y-5,Yellow);
	LCD_DrawLine((x)%240,y+5,(x)%240,y-5,Yellow);
	LCD_DrawLine((x+1)%240,y+5,(x+1)%240,y-5,Yellow);
	LCD_DrawLine((x+2)%240,y+5,(x+2)%240,y-5,Yellow);
	LCD_DrawLine((x+2)%240,y,(x+2)%240,y,Black);
	LCD_DrawLine((x+3)%240,y+5,(x+3)%240,y-5,Yellow);
	LCD_DrawLine((x+3)%240,y-1,(x+3)%240,y+1,Black);
	LCD_DrawLine((x+4)%240,y-4,(x+4)%240,y+4,Yellow);
	LCD_DrawLine((x+4)%240,y-1,(x+4)%240,y+1,Black);
	LCD_DrawLine((x+5)%240,y-4,(x+5)%240,y+4,Yellow);
	LCD_DrawLine((x+5)%240,y-2,(x+5)%240,y+2,Black);
	LCD_DrawLine((x+6)%240,y-3,(x+6)%240,y+3,Yellow);
	LCD_DrawLine((x+6)%240,y-2,(x+6)%240,y+2,Black);
	

	x=(x+1)%240;
	
	if(x==0){
		LCD_DrawLine(235,y-5,235,y+5,Black);
		LCD_DrawLine(236,y-5,236,y+5,Black);
		LCD_DrawLine(237,y-5,237,y+5,Black);
		LCD_DrawLine(238,y-5,238,y+5,Black);
		LCD_DrawLine(239,y-5,239,y+5,Black);
		}

	}

return;
}


