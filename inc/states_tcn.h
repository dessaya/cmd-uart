#ifndef _states_tcn_h_
#define _states_tcn_h_

#include "fsm_signals.h"
#include "sapi.h"

void state_pvpub_enter();
signal_t state_pvpub_update(tick_t elapsed);

void state_pvsub_enter();
signal_t state_pvsub_update(tick_t elapsed);

void state_msgsend_enter();
signal_t state_msgsend_update(tick_t elapsed);

void state_msgrcv_enter();
signal_t state_msgrcv_update(tick_t elapsed);

void state_mulsend_enter();
signal_t state_mulsend_update(tick_t elapsed);

void state_mulrcv_enter();
signal_t state_mulrcv_update(tick_t elapsed);

#endif
