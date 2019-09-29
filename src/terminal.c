#include "sapi.h"
#include "terminal.h"

#define TERMINAL_UART UART_USB

void terminal_init() {
    uartConfig(TERMINAL_UART, 115200);
}

void terminal_print(const char* str) {
    uartWriteString(TERMINAL_UART, str);
}

void terminal_println(const char* str) {
    terminal_print(str);
    uartWriteByte(TERMINAL_UART, '\n');
}

#define READLINE_BUFSIZE 1024

char *terminal_readline() {
    static char buf[READLINE_BUFSIZE];
    static int i = 0;

    uint8_t read;
    while (uartReadByte(TERMINAL_UART, &read)) {
        if (i < READLINE_BUFSIZE - 1) {
            buf[i++] = read;
        }
        if (read == '\n' || read == '\r') {
            buf[i - 1] = '\0';
            i = 0;
            return buf;
        }
    }
    return NULL;
}
