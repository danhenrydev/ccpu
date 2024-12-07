#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "chip.h"

ccpu_pin_t *ccpu_pin_create(struct ccpu_chip_s *owning_chip, char *name, uint8_t pin_number, ccpu_pin_type_t pin_type) {

  ccpu_pin_t *pin = malloc(sizeof(ccpu_pin_t));
  if (pin == NULL) {
    return NULL;
  }

  strcpy(pin->name, name);
  pin->owning_chip = owning_chip;
  pin->pin_number = pin_number;
  pin->pin_type = pin_type;
  pin->state = LOW;


  return pin;

}

void ccpu_pin_set_state(ccpu_pin_t *pin, ccpu_state_t state) {
  if(pin->state != state) {
    pin->state = state;
    pin->owning_chip->update(pin->owning_chip);
  }
}

void ccpu_chip_debug_dump(ccpu_chip_t *chip) {

  printf("Chip %s is a %s with %d pins total\n", chip->name, chip->type, chip->pin_count);
  printf("--------------------\n");
  printf("Pin # | ");
  for(size_t i = 0; i < chip->pin_count; i++) {
    printf(" %d  | ", (int)i+1);
  }
  printf("\n");
  printf("Value | ");
  for(size_t i = 0; i < chip->pin_count; i++) {
    if(i >= 9) {
      printf(" ");
    }
    printf(" %d  | ", chip->pins[i+1]->state);

  }
  printf("\n");

}
