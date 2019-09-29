#include "sapi.h"
#include "terminal.h"

#define TERMINAL_UART UART_USB

void terminalInit() {
    uartConfig(TERMINAL_UART, 115200);
}

void terminalPrint(const char* str) {
    uartWriteString(TERMINAL_UART, str);
}

void terminalPrintLn(const char* str) {
    terminalPrint(str);
    uartWriteByte(TERMINAL_UART, '\n');
}

const char *terminalReceivedCommand() {
    return NULL;
}
