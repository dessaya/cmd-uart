#include "sapi.h"
#include "fsm.h"
#include "terminal.h"

int main()
{
    boardInit();
    terminalInit();
    fsm_loop();
    return 0;
}
