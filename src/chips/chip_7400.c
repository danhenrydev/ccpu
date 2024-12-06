#include "chips/chip_7400.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void chip_7400_update(ccpu_chip_t *chip) {

  chip->pins_state[3] = !(chip->pins_state[1] && chip->pins_state[2]);
  chip->pins_state[5] = !(chip->pins_state[6] && chip->pins_state[7]);
  chip->pins_state[8] = !(chip->pins_state[9] && chip->pins_state[10]);
  chip->pins_state[14] = !(chip->pins_state[12] && chip->pins_state[13]);
  
}

ccpu_chip_t *chip_7400_create(char *name) {

  ccpu_chip_t *chip = malloc(sizeof(ccpu_chip_t));
  strcpy(chip->type, "7400 - Quad 2 input NAND gates");
  strcpy(chip->name, name);
  chip->pin_count = 14;
  chip->pin_designation[1] = INPUT;
  chip->pin_designation[2] = INPUT;
  chip->pin_designation[3] = OUTPUT;
  chip->pin_designation[4] = INPUT;
  chip->pin_designation[5] = OUTPUT;
  chip->pin_designation[6] = INPUT;
  chip->pin_designation[7] = INPUT;
  chip->pin_designation[8] = OUTPUT;
  chip->pin_designation[9] = INPUT;
  chip->pin_designation[10] = INPUT;
  chip->pin_designation[11] = INPUT;
  chip->pin_designation[12] = INPUT;
  chip->pin_designation[13] = INPUT;
  chip->pin_designation[14] = OUTPUT;

  chip->update = chip_7400_update;
  
  if(chip != NULL) {
    return chip;
  }

  return NULL;
}
