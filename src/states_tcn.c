#include "states_tcn.h"

#include "terminal.h"
#include "command_line.h"

static cmd_t commands[] = {
    {"back", SIGNAL_DONE, "Go back to idle mode"},
    {NULL, SIGNAL_NONE, NULL},
};

void state_pvpub_enter() {
    terminal_println("Entered Process Variable Publisher mode");
    cmd_print_help(commands);
}

signal_t state_pvpub_update(tick_t elapsed) {
    return cmd_readline(commands);
}


void state_pvsub_enter() {
    terminal_println("Entered Process Variable Subscriber mode");
    cmd_print_help(commands);
}

signal_t state_pvsub_update(tick_t elapsed) {
    return cmd_readline(commands);
}


void state_msgsend_enter() {
    terminal_println("Entered Call/Reply Message Sender mode");
    cmd_print_help(commands);
}

signal_t state_msgsend_update(tick_t elapsed) {
    return cmd_readline(commands);
}


void state_msgrcv_enter() {
    terminal_println("Entered Call/Reply Message Receiver mode");
    cmd_print_help(commands);
}

signal_t state_msgrcv_update(tick_t elapsed) {
    return cmd_readline(commands);
}


void state_mulsend_enter() {
    terminal_println("Entered Multicast Message Sender mode");
    cmd_print_help(commands);
}

signal_t state_mulsend_update(tick_t elapsed) {
    return cmd_readline(commands);
}


void state_mulrcv_enter() {
    terminal_println("Entered Multicast Message Receiver mode");
    cmd_print_help(commands);
}

signal_t state_mulrcv_update(tick_t elapsed) {
    return cmd_readline(commands);
}

