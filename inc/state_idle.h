#ifndef _state_idle_h_
#define _state_idle_h_

#include "fsm_signals.h"
#include "sapi.h"

void state_idle_enter();
signal_t state_idle_update(tick_t elapsed);

#endif
