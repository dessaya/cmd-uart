#include "sapi.h"
#include "states.h"
#include "terminal.h"

int main()
{
    boardInit();
    terminalInit();
    fsm_loop();
    return 0;
}
