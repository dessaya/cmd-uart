#include "state_idle.h"
#include "terminal.h"
#include "command_line.h"

static cmd_t commands[] = {
    {"pvpub", SIGNAL_SET_MODE_PV_PUBLISHER, "Switch to Process Variable Publisher mode"},
    {"pvsub", SIGNAL_SET_MODE_PV_SUBSCRIBER, "Switch to Process Variable Subscriber mode"},
    {"msgsend", SIGNAL_SET_MODE_MSG_SENDER, "Switch to Call/Reply Message Sender"},
    {"msgrcv", SIGNAL_SET_MODE_MSG_RECEIVER, "Switch to Call/Reply Message Receiver"},
    {"mulsend", SIGNAL_SET_MODE_MSG_MULTICAST_SENDER, "Switch to Multicast Message Sender"},
    {"mulrcv", SIGNAL_SET_MODE_MSG_MULTICAST_RECEIVER, "Switch to Multicast Message Receiver"},
    {NULL, SIGNAL_NONE, NULL},
};

signal_t state_idle_enter(tick_t elapsed) {
    terminal_println("Entered idle mode");
    cmd_print_help(commands);
}

signal_t state_idle_update(tick_t elapsed) {
    return cmd_readline(commands);
}

