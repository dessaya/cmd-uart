#ifndef _cmd_line_h_
#define _cmd_line_h_

#include "fsm_signals.h"

typedef struct {
    char *cmd;
    signal_t signal;
    char *help;
} cmd_t;

void cmd_print_help(cmd_t commands[]);
cmd_t *cmd_find(char *line, cmd_t commands[]);
signal_t cmd_readline(cmd_t commands[]);

#endif
