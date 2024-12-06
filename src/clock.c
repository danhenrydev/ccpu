#include "clock.h"

ccpu_state_t ccpu_clock_hcycle(ccpu_clock_t *clock) {

  clock->state = !clock->state;
  return clock->state;

}


ccpu_state_t ccpu_clock_cycle(ccpu_clock_t *clock) {
  ccpu_clock_hcycle(clock);
  return ccpu_clock_hcycle(clock);
}
