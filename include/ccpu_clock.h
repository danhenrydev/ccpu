#ifndef CCPU_CLOCK_H
#define CCPU_CLOCK_H

#include "common.h"

typedef struct ccpu_clock_s {

  state_t state;

} ccpu_clock_t;

state_t ccpu_clock_hcycle(ccpu_clock_t *clock);
state_t ccpu_clock_cycle(ccpu_clock_t *clock);

#endif
