#include <stdlib.h>
#include <stdbool.h>
#include "fsm.h"
#include "state_init.h"
#include "state_idle.h"
#include "states_tcn.h"

typedef enum {
    STATE_INIT,
    STATE_IDLE,
    STATE_PV_PUBLISHER,
    STATE_PV_SUBSCRIBER,
    STATE_MSG_SENDER,
    STATE_MSG_RECEIVER,
    STATE_MSG_MULTICAST_SENDER,
    STATE_MSG_MULTICAST_RECEIVER,
} state_id_t;

typedef struct {
    void (*enter)();
    signal_t (*update)(tick_t elapsed);
} state_t;

static void noop_enter() {}
static signal_t noop_update(tick_t elapsed) { return SIGNAL_NONE; }

static state_t states[] = {
    [STATE_INIT] = {noop_enter, state_init_update},
    [STATE_IDLE] = {state_idle_enter, state_idle_update},
    [STATE_PV_PUBLISHER] = {state_pvpub_enter, state_pvpub_update},
    [STATE_PV_SUBSCRIBER] = {state_pvsub_enter, state_pvsub_update},
    [STATE_MSG_SENDER] = {state_msgsend_enter, state_msgsend_update},
    [STATE_MSG_RECEIVER] = {state_msgrcv_enter, state_msgrcv_update},
    [STATE_MSG_MULTICAST_SENDER] = {state_mulsend_enter, state_mulsend_update},
    [STATE_MSG_MULTICAST_RECEIVER] = {state_mulrcv_enter, state_mulrcv_update},
};

typedef struct {
    state_id_t state_id;
    signal_t signal;
    state_id_t next_state_id;
} transition_t;

static transition_t transitions[] = {
    {STATE_INIT, SIGNAL_DONE, STATE_IDLE},

    {STATE_IDLE, SIGNAL_SET_MODE_PV_PUBLISHER, STATE_PV_PUBLISHER},
    {STATE_IDLE, SIGNAL_SET_MODE_PV_SUBSCRIBER, STATE_PV_SUBSCRIBER},
    {STATE_IDLE, SIGNAL_SET_MODE_MSG_SENDER, STATE_MSG_SENDER},
    {STATE_IDLE, SIGNAL_SET_MODE_MSG_RECEIVER, STATE_MSG_RECEIVER},
    {STATE_IDLE, SIGNAL_SET_MODE_MSG_MULTICAST_SENDER, STATE_MSG_MULTICAST_SENDER},
    {STATE_IDLE, SIGNAL_SET_MODE_MSG_MULTICAST_RECEIVER, STATE_MSG_MULTICAST_RECEIVER},

    {STATE_PV_PUBLISHER, SIGNAL_DONE, STATE_IDLE},

    {STATE_PV_SUBSCRIBER, SIGNAL_DONE, STATE_IDLE},

    {STATE_MSG_SENDER, SIGNAL_DONE, STATE_IDLE},

    {STATE_MSG_RECEIVER, SIGNAL_DONE, STATE_IDLE},

    {STATE_MSG_MULTICAST_SENDER, SIGNAL_DONE, STATE_IDLE},

    {STATE_MSG_MULTICAST_RECEIVER, SIGNAL_DONE, STATE_IDLE},

    {0, 0, 0},
};

static transition_t *find_transition(state_id_t state_id, signal_t signal) {
    for (transition_t *t = transitions; t->signal; t++) {
        if (t->state_id == state_id && t->signal == signal) {
            return t;
        }
    }
    return NULL;
}

void fsm_loop() {
    state_id_t state_id = STATE_INIT;

    while (true) {
        state_t *state = &states[state_id];
        tick_t entered = tickRead();

        state->enter();
        while (true) {
            tick_t now = tickRead();
            signal_t signal = state->update(now - entered);
            if (signal) {
                transition_t *transition = find_transition(state_id, signal);
                if (transition) {
                    state_id = transition->next_state_id;
                    break;
                }
            }

            // wait at least 1ms for next call to update()
            while (tickRead() == now)
                ;
        }
    }
}
