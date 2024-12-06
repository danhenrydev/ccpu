#ifndef CHIP_H
#define CHIP_H

#include "common.h"

struct ccpu_chip_s;
typedef void (*chip_update_fn_t)(struct ccpu_chip_s *chip);

/** 
 * Represents a chip with pins and update functionality.
 * Contains chip type, name, pin array, pin count, pin designations
 * and update function.
 *
 * @struct ccpu_chip_s
 * @var type Array holding the chip type identifier
 * @var name Array holding the chip instance name 
 * @var pins_state Array of pin values/states for the chip
 * @var pin_count Number of pins on the chip
 * @var pin_designation Array indicating pin input/output designation
 * @var update Function pointer for updating chip state
 */
typedef struct ccpu_chip_s {

  char type[CHIP_MAX_NAME_LENGTH];
  char name[CHIP_MAX_NAME_LENGTH];

  ccpu_state_t pins_state[CHIP_MAX_PINS];
  unsigned int pin_count;
  bool pin_designation[CHIP_MAX_PINS];
 chip_update_fn_t update;

} ccpu_chip_t;

/** @brief Dumps debug information about a chip
 *  @details Prints detailed information about the chip's state including type,
 *           name, pin states and designations for debugging purposes
 *  @param chip Pointer to the chip structure to dump debug info for
 */
void chip_debug_dump(ccpu_chip_t *chip);

#endif
