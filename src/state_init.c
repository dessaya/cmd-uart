#include "state_init.h"
#include "terminal.h"

void state_init_enter() {
    terminal_println("Initializing...");
}

signal_t state_init_update(tick_t elapsed) {
    // blink led every 50ms, for 500ms
    gpioWrite(LED, elapsed % 50 == 0);
    if (elapsed < 500) {
        return SIGNAL_NONE;
    }
    gpioWrite(LED, false);

    terminal_println("Initialized");
    return SIGNAL_DONE;
}

