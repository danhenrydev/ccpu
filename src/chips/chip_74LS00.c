#include "chips/chip_74LS00.h"
#include <stdlib.h>
#include <string.h>

void chip_74LS00_update(chip_t *chip) {

  chip->pins_state[3] = !(chip->pins_state[1] && chip->pins_state[2]);
  chip->pins_state[6] = !(chip->pins_state[4] && chip->pins_state[5]);
  chip->pins_state[8] = !(chip->pins_state[9] && chip->pins_state[10]);
  chip->pins_state[11] = !(chip->pins_state[12] && chip->pins_state[13]);

}

chip_t *chip_74LS00_create() {

  chip_t *chip = malloc(sizeof(chip_t));
  if(chip == NULL) {
    return NULL;
  }

  strcpy(chip->type, "74LS00 - Quad 2 input NAND gates");
  strcpy(chip->name, "");
  chip->pin_count = 14;

  // a1 b1 y1
  chip->pin_designation[1] = INPUT;
  chip->pin_designation[2] = INPUT;
  chip->pin_designation[3] = OUTPUT;
  // a2 b2 y2
  chip->pin_designation[4] = INPUT;
  chip->pin_designation[5] = INPUT;
  chip->pin_designation[6] = OUTPUT;
  // gnd
  chip->pin_designation[7] = OUTPUT;
  // y3 a3 b3
  chip->pin_designation[8] = OUTPUT;
  chip->pin_designation[9] = INPUT;
  chip->pin_designation[10] = INPUT;
  // y4 a4 b4
  chip->pin_designation[11] = OUTPUT;
  chip->pin_designation[12] = INPUT;
  chip->pin_designation[13] = INPUT;
  // vcc
  chip->pin_designation[14] = OUTPUT;

  return chip;

}
