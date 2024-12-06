#ifndef CHIP_H
#define CHIP_H

#include <stdbool.h>
#include "common.h"


struct chip_s;
typedef void (*chip_update_fn_t)(struct chip_s *chip);

/** @brief Represents a chip with pins and update functionality
 *  @details Contains chip type, name, pin array, pin count, pin designations and update function
 *  
 *  @var chip_s::type Array holding the chip type identifier
 *  @var chip_s::name Array holding the chip instance name
 *  @var chip_s::pins_state Array of pin values/states for the chip
 *  @var chip_s::pin_count Number of pins on the chip
 *  @var chip_s::pin_designation Array indicating pin input/output designation
 *  @var chip_s::update Function pointer for updating chip state
 */
typedef struct chip_s {

  char type[CHIP_MAX_NAME_LENGTH];
  char name[CHIP_MAX_NAME_LENGTH];

  state_t pins_state[CHIP_MAX_PINS];
  unsigned int pin_count;
  iodesig_t pin_designation[CHIP_MAX_PINS];
  chip_update_fn_t update;

} chip_t;

#endif
