#ifndef _terminal_h_
#define _terminal_h_

void terminalInit();
void terminalPrint(const char* str);
void terminalPrintLn(const char* str);
const char *terminalReceivedCommand();

#endif
