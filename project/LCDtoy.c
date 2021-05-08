#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "abCircle.h"
#include <msp430.h>
#include <sr.h>
#include "p2switches.h"

#define LED_GREEN BIT6             // P1.6


short redrawScreen = 1;
u_int fontFgColor = COLOR_WHITE;
u_int changingColor = COLOR_BLUE;
u_int changingColor2 = COLOR_BLUE;
u_int changingColor3 = COLOR_BLUE;
void wdt_c_handler()
{
  static int secCount = 0;

  secCount ++;
  if (secCount == 83) {		/* once/sec */
    //secCount = 0;
    fontFgColor = (fontFgColor == COLOR_GREEN) ? COLOR_BLACK : COLOR_GREEN;
    changingColor = (changingColor == COLOR_WHITE) ? COLOR_BLUE : COLOR_WHITE;
    changingColor2 = (changingColor2 == COLOR_BLUE) ? COLOR_WHITE : COLOR_BLUE;
    changingColor3 = (changingColor3 == COLOR_WHITE) ? COLOR_BLUE : COLOR_WHITE;
    redrawScreen = 1;
  }
  if (secCount == 166){
    changingColor = (changingColor == COLOR_BLUE) ? COLOR_WHITE : COLOR_BLUE;
    changingColor2 = (changingColor2 == COLOR_WHITE) ? COLOR_BLUE : COLOR_WHITE;
    changingColor3 = (changingColor3 == COLOR_BLUE) ? COLOR_WHITE : COLOR_BLUE;
    redrawScreen = 1;
    //secCount = 0;
  }
  if (secCount == 249){
    changingColor = (changingColor == COLOR_WHITE) ? COLOR_BLUE : COLOR_WHITE;
    changingColor2 = (changingColor2 == COLOR_BLUE) ? COLOR_WHITE : COLOR_BLUE;
    changingColor3 = (changingColor3 == COLOR_WHITE) ? COLOR_BLUE : COLOR_WHITE;
    redrawScreen = 1;
    secCount = 0;
    }
    
}
  


void main()
{
  P1DIR |= LED_GREEN;		/**< Green led on when CPU on */		
  P1OUT |= LED_GREEN;
  configureClocks();
  lcd_init();
  
  enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);	              /**< GIE (enable interrupts) */
  
  clearScreen(COLOR_BLUE);
  while (1) {			/* forever */
    if (redrawScreen) {
      redrawScreen = 0;
      drawString5x7(10,10, "Hello!", fontFgColor, COLOR_BLUE);//here is where we draw
      drawString8x12(20,20, "SIDEWAYS", fontFgColor, COLOR_BLUE);
       fillRectangle(20,120, 30,30, changingColor); 
       fillRectangle(50,120, 30,30, changingColor2);
       fillRectangle(80,120, 30,30, changingColor3);
    }
    //fillRectangle(40,100, 30,30, COLOR_RED);
     
    u_char offset_r = 80, offset_c = 50; //first triangle
  for (int r = 0; r < 45; r++){
    for (int c = 0; c <= r; c++){
      drawPixel(offset_c + c, offset_r-r, COLOR_ORANGE);
      drawPixel(offset_c - c, offset_r-r, COLOR_ORANGE);
    }
    }
  
  u_char offset_a = 80, offset_b = 50; //second triangle
  for (int a = 0; a < 45; a++){
    for (int b = 0; b <= a; b++){
      drawPixel(offset_b + b, offset_a-a, COLOR_RED);
      drawPixel(offset_b - b, offset_a-a, COLOR_RED);
    }
    }
  
    P1OUT &= ~LED_GREEN;	/* green off */
    or_sr(0x10);		/**< CPU OFF */
    P1OUT |= LED_GREEN;		/* green on */
  }
}
