#include "state_init.h"
#include "terminal.h"

signal_t state_init_update(tick_t elapsed) {
    // blink led every 50ms
    gpioWrite(LED, elapsed % 50 == 0);
    if (elapsed < 500) {
        return SIGNAL_NONE;
    }
    gpioWrite(LED, false);

    terminalPrintLn("Initialized");
    return SIGNAL_DONE;
}

