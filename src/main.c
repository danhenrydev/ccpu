#include <stdio.h>
#include <string.h>
#include "chip.h"
#include "chips/chip_74LS74.h"

int main(void) {
   
  chip_t *chip_a = chip_74LS74_create("chip_a");

  if(chip_a == NULL) {
    return 1;
  }

  chip_debug_dump(chip_a);


  return 0;
}
