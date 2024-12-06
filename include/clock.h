#ifndef CCPU_CLOCK_H
#define CCPU_CLOCK_H

#include "common.h"

/**
 * @brief Clock structure for CCPU
 */
typedef struct ccpu_clock_s {

  /**
   * @brief Current state of the clock
   */
  ccpu_state_t state;

} ccpu_clock_t;

/**
 * @brief Executes half a clock cycle
 * @param clock Pointer to the clock structure
 * @return Current state after half cycle execution
 */
ccpu_state_t ccpu_clock_hcycle(ccpu_clock_t *clock);

/**
 * @brief Executes a full clock cycle
 * @param clock Pointer to the clock structure
 * @return Current state after full cycle execution
 */
ccpu_state_t ccpu_clock_cycle(ccpu_clock_t *clock);

#endif
