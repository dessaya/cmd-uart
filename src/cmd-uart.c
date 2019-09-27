/*=============================================================================
 * Copyright (c) 2019, Diego Essaya <dessaya@gmail.com>
 * All rights reserved.
 * License: apache-2.0 (see LICENSE.txt)
 * Date: 2019/09/27
 * Version: 0.1
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "cmd-uart.h"
#include "sapi.h"

/*=====[Definition macros of private constants]==============================*/

/*=====[Definitions of extern global variables]==============================*/

/*=====[Definitions of public global variables]==============================*/

/*=====[Definitions of private global variables]=============================*/

/*=====[Main function, program entry point after power on or reset]==========*/

int main( void )
{
   // ----- Setup -----------------------------------
   boardInit();

   // ----- Repeat for ever -------------------------
   while( true ) {
      gpioToggle(LED);
      delay(500);
   }

   // YOU NEVER REACH HERE, because this program runs directly or on a
   // microcontroller and is not called by any Operating System, as in the 
   // case of a PC program.
   return 0;
}
