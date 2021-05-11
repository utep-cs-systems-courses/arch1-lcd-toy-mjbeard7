#include <msp430.h>
#include "stateMachines.h"
#include "p2switches.h"

void state_advance()		
{

  static char sm1 = 0;

  switch(sm1){
  case 0:/* red_on = 0; green_on = 1;*/ sm1++; break;
  default: sm1 = 0;
  }
}
