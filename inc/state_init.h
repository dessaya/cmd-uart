#ifndef _state_init_h_
#define _state_init_h_

#include "fsm_signals.h"
#include "sapi.h"

void state_init_enter();
signal_t state_init_update(tick_t elapsed);

#endif
