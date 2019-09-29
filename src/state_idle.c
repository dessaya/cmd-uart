#include <string.h>
#include "state_idle.h"
#include "terminal.h"

typedef struct {
    char *cmd;
    signal_t signal;
    char *help;
} cmd_t;

cmd_t commands[] = {
    {"pvpub", SIGNAL_SET_MODE_PV_PUBLISHER, "Switch to Process Variable Publisher mode"},
    {"pvsub", SIGNAL_SET_MODE_PV_SUBSCRIBER, "Switch to Process Variable Subscriber mode"},
    {"msgsend", SIGNAL_SET_MODE_MSG_SENDER, "Switch to Call/Reply Message Sender"},
    {"msgrcv", SIGNAL_SET_MODE_MSG_RECEIVER, "Switch to Call/Reply Message Receiver"},
    {"mulsend", SIGNAL_SET_MODE_MSG_MULTICAST_SENDER, "Switch to Multicast Message Sender"},
    {"mulrcv", SIGNAL_SET_MODE_MSG_MULTICAST_RECEIVER, "Switch to Multicast Message Receiver"},
    {NULL, SIGNAL_NONE, NULL},
};

static cmd_t *cmd_find(char *line) {
    for (cmd_t *cmd = commands; cmd->cmd; cmd++) {
        if (strcmp(cmd->cmd, line) == 0) {
            return cmd;
        }
    }
    return NULL;
}

static void print_help() {
    terminal_println("Commands:");
    for (cmd_t *cmd = commands; cmd->cmd; cmd++) {
        terminal_print("  ");
        terminal_print(cmd->cmd);
        terminal_print(": ");
        terminal_print(cmd->help);
    }
}

signal_t state_idle_enter(tick_t elapsed) {
    terminal_println("Entered idle mode");
    print_help();
}

signal_t state_idle_update(tick_t elapsed) {
    char *line = terminal_readline();
    if (line) {
        cmd_t *cmd = cmd_find(line);
        if (cmd) {
            return cmd->signal;
        } else {
            print_help();
        }
    }
    return SIGNAL_NONE;
}

