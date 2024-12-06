#include "chip.h"
#include <stddef.h>
#include <stdio.h>


void chip_pin_set(chip_t *chip, unsigned int pin, bool value) {
  if(chip->pin_count < (pin - 1)) {
    return;
  }

  chip->pins[pin - 1] = value;

  for(size_t i = 0; i < chip->pin_count; i++) {
    printf("%d ", chip->pins[i]);
  }

}
