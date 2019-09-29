#ifndef _states_h_
#define _states_h_

#include "sapi.h"

typedef enum {
    SIGNAL_NONE = 0,
    SIGNAL_DONE,
    SIGNAL_SET_MODE_PV_PUBLISHER,
    SIGNAL_SET_MODE_PV_SUBSCRIBER,
    SIGNAL_SET_MODE_MSG_SENDER,
    SIGNAL_SET_MODE_MSG_RECEIVER,
    SIGNAL_SET_MODE_MSG_MULTICAST_SENDER,
    SIGNAL_SET_MODE_MSG_MULTICAST_RECEIVER,
} signal_t;

void fsm_loop();

#endif
