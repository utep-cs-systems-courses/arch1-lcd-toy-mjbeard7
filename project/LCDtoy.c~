#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "abCircle.h"

#define LED_GREEN BIT6             // P1.6


short redrawScreen = 1;
u_int fontFgColor = COLOR_GREEN;

void wdt_c_handler()
{
  static int secCount = 0;

  secCount ++;
  if (secCount == 150) {		/* once/sec */
    secCount = 0;
    fontFgColor = (fontFgColor == COLOR_GREEN) ? COLOR_BLACK : COLOR_GREEN;
    redrawScreen = 1;
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
      
    }
     fillRectangle(40,100, 30,30, COLOR_RED);
     
     u_char offset_r = 80, offset_c = 50; 
  for (int r = 0; r < 25; r++){
    for (int c = 0; c <= r; c++){
      drawPixel(offset_c + c, offset_r-r, COLOR_ORANGE);
      drawPixel(offset_c - c, offset_r-r, COLOR_ORANGE);
    }
    }
    
    P1OUT &= ~LED_GREEN;	/* green off */
    or_sr(0x10);		/**< CPU OFF */
    P1OUT |= LED_GREEN;		/* green on */
  }
}

    
    



