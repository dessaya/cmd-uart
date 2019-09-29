#include "sapi.h"
#include "fsm.h"
#include "terminal.h"

int main()
{
    boardInit();
    terminal_init();
    fsm_loop();
    return 0;
}
