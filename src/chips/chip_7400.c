#include "chips/chip_7400.h"
#include <stdlib.h>
#include <string.h>

chip_t *chip_7400_create() {

  chip_t *chip = malloc(sizeof(chip_t));
  strcpy(chip->name, "7400 - Quad 2 input NAND gates");
  chip->pin_count = 14;
  chip->update = chip_7400_update;
  
  return chip;
}
