#ifndef CHIP_H
#define CHIP_H

#include <stdbool.h>
#include "common.h"


/** @brief represents a single pin within a chip */
typedef bool pin_t;

struct chip_s;
typedef void (*chip_update_fn_t)(struct chip_s *chip);

/**
  * @brief represents a single 'chip'
  * 
  * Represents a single chip that has a name and a set
  * number of pins.  A chip may reflect a real world
  * chip such as a 74xx series TTL logic chip or it can
  * represnt a 'generic' chip like a built in 
  * 'generic register'
  */
typedef struct chip_s {

  char name[CHIP_MAX_NAME_LENGTH];

  pin_t pins[CHIP_MAX_PINS];
  unsigned int pin_count;
  chip_update_fn_t update;

} chip_t;

/** @brief Set the value of a pin for a given chip */
void chip_pin_set(chip_t *chip, unsigned int pin, bool value);

#endif
