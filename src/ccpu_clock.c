#include "ccpu_clock.h"

state_t ccpu_clock_hcycle(ccpu_clock_t *clock) {

  clock->state = !clock->state;
  return clock->state;

}


state_t ccpu_clock_cycle(ccpu_clock_t *clock) {
  ccpu_clock_hcycle(clock);
  return ccpu_clock_hcycle(clock);
}
