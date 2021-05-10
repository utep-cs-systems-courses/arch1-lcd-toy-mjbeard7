#include <msp430.h>
#include "stateMachines.h"
#include "p2switches.h"
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"

void state_advance(){
  static char sm1 = 0;
  
  void wdt_c_handler()
{
  static int secCount = 0;
  secCount ++;
  
  if (secCount == 250) {/* once/sec */
  } 
  switch(sm1){
  case 0:/* red_on = 0; green_on = 1;*/ sm1++; break;
  case 1:break;
  default: sm1 = 0;
    
    }
  }
}
