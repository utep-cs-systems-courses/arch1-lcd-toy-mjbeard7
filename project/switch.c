#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include <sr.h>
#include "switch.h"

short redrawScreen = 1;
u_int changingColor4 = COLOR_BLUE;
u_int coordinates_x = 5;
 int count = 0;
 int state = 1;
void wdt_c_handler(){
 
  
  count ++;
switch (state){

  case 1:{
    if (count == 5){
    coordinates_x = (coordinates_x == 5) ? 5: 5;
    //if Color is ____, if condition met ____, otherwise : _______
    changingColor4= (changingColor4 == COLOR_RED) ? COLOR_BLUE : COLOR_RED;
    redrawScreen = 1;
      }
  }
  case 2:{
    if (count == 100){
    coordinates_x = (coordinates_x == 40) ? 40: 40;
    changingColor4= (changingColor4 == COLOR_RED) ? COLOR_YELLOW: COLOR_BLUE; 
    redrawScreen = 1;
    }
  }
  case 3:{
    if (count == 250){
    count = 0;
    coordinates_x = (coordinates_x == 5) ? 5: 5;
    changingColor4= (changingColor4 == COLOR_YELLOW) ? COLOR_RED : COLOR_BLUE;
    redrawScreen = 1;
    state = 1;
    }
    break;
  }
  default:{
    count = 0;
    state = 1;
  }
  }//end of switch
  }//end of wtc handler
 
