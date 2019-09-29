#include <string.h>
#include "command_line.h"
#include "terminal.h"

void cmd_print_help(cmd_t commands[]) {
    terminal_println("Commands:");
    for (cmd_t *cmd = commands; cmd->cmd; cmd++) {
        terminal_print("  ");
        terminal_print(cmd->cmd);
        terminal_print(": ");
        terminal_print(cmd->help);
    }
}

cmd_t *cmd_find(char *line, cmd_t commands[]) {
    for (cmd_t *cmd = commands; cmd->cmd; cmd++) {
        if (strcmp(cmd->cmd, line) == 0) {
            return cmd;
        }
    }
    return NULL;
}

signal_t cmd_readline(cmd_t commands[]) {
    char *line = terminal_readline();
    if (line) {
        cmd_t *cmd = cmd_find(line, commands);
        if (cmd) {
            return cmd->signal;
        } else {
            cmd_print_help(commands);
        }
    }
    return SIGNAL_NONE;
}
