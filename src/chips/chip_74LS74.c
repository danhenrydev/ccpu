#include <stdlib.h>
#include <string.h>
#include "chips/chip_74LS74.h"

void chip_74LS74_update(ccpu_chip_t *chip) {

  // first flip flop
  if(chip->pins_state[3] == HIGH) {
    if(chip->pins_state[4] == LOW) {
      // Were setting the flip flop
      chip->pins_state[6] = chip->pins_state[2];
    }

    if(chip->pins_state[1] == LOW) {
      // We're resetting the flop flop
      chip->pins_state[6] = LOW;
    }
  }

  chip->pins_state[6] = !chip->pins_state[5];
  
  // Second flip flop
  if(chip->pins_state[11] == HIGH) {
    if(chip->pins_state[10] == LOW) {
      // Were setting the flip flop
      chip->pins_state[9] = chip->pins_state[12];
    }

    if(chip->pins_state[13] == LOW) {
      // We're resetting the flop flop
      chip->pins_state[9] = LOW;
    }
  }

  chip->pins_state[8] = !chip->pins_state[9];

}

ccpu_chip_t *chip_74LS74_create(char* name) {

  ccpu_chip_t *chip = NULL;
  chip = malloc(sizeof(ccpu_chip_t));
  if(chip == NULL) {
    return NULL;
  }
  strcpy(chip->type, "74LS74 - Dual D-Type Flip Flop");
  strcpy(chip->name, name);
  chip->pin_count = 14;

  chip->pin_designation[1] = INPUT;
  chip->pin_designation[2] = INPUT;
  chip->pin_designation[3] = INPUT;
  chip->pin_designation[4] = INPUT;
  chip->pin_designation[5] = OUTPUT;
  chip->pin_designation[6] = OUTPUT;
  chip->pin_designation[7] = OUTPUT;

  chip->pin_designation[8] = OUTPUT;
  chip->pin_designation[9] = OUTPUT;
  chip->pin_designation[10] = INPUT;
  chip->pin_designation[11] = INPUT;
  chip->pin_designation[12] = INPUT;
  chip->pin_designation[13] = INPUT;
  chip->pin_designation[14] = OUTPUT;

  chip->update = chip_74LS74_update;

  return chip;

}
