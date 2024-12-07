#include <stdlib.h>
#include <string.h>
#include "chips/chip_74LS00.h"
#include "chip.h"

void chip_74LS00_update(ccpu_chip_t *chip) {

  ccpu_pin_set_state(chip->pins[3], !(chip->pins[1]->state && chip->pins[2]->state));
  ccpu_pin_set_state(chip->pins[6], !(chip->pins[4]->state && chip->pins[5]->state));
  ccpu_pin_set_state(chip->pins[8], !(chip->pins[9]->state && chip->pins[10]->state));
  ccpu_pin_set_state(chip->pins[11], !(chip->pins[12]->state && chip->pins[13]->state));

}

ccpu_chip_t *chip_74LS00_create(char *name) {

  ccpu_chip_t *chip = malloc(sizeof(ccpu_chip_t));
  if(chip == NULL) {
    return NULL;
  }

  strcpy(chip->type, "74LS00 - Quad 2 input NAND gates");
  strcpy(chip->name, name);

  chip->pin_count = 14;

  // Create the pins, we need 14 of em...

  chip->pins[1]  = ccpu_pin_create(chip, "1A", 1, PIN_TYPE_INPUT);
  chip->pins[2]  = ccpu_pin_create(chip, "1B", 2, PIN_TYPE_INPUT);
  chip->pins[3]  = ccpu_pin_create(chip, "1Y", 3, PIN_TYPE_OUTPUT);

  chip->pins[4]  = ccpu_pin_create(chip, "2A", 4, PIN_TYPE_INPUT);
  chip->pins[5]  = ccpu_pin_create(chip, "2B", 5, PIN_TYPE_INPUT);
  chip->pins[6]  = ccpu_pin_create(chip, "2Y", 6, PIN_TYPE_OUTPUT);

  chip->pins[7]  = ccpu_pin_create(chip, "GND", 7, PIN_TYPE_GROUND);

  chip->pins[8]  = ccpu_pin_create(chip, "3Y", 8, PIN_TYPE_OUTPUT);
  chip->pins[9]  = ccpu_pin_create(chip, "3A", 9, PIN_TYPE_INPUT);
  chip->pins[10] = ccpu_pin_create(chip, "3B", 10, PIN_TYPE_INPUT);

  chip->pins[11]  = ccpu_pin_create(chip, "4Y", 11, PIN_TYPE_OUTPUT);
  chip->pins[12]  = ccpu_pin_create(chip, "4A", 12, PIN_TYPE_INPUT);
  chip->pins[13]  = ccpu_pin_create(chip, "4B", 13, PIN_TYPE_INPUT);

  chip->pins[14]  = ccpu_pin_create(chip, "VCC", 14, PIN_TYPE_VCC);

  chip->update = chip_74LS00_update;

  chip->update(chip);

  return chip;

}
