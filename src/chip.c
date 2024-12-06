#include <stddef.h>
#include <stdio.h>
#include "chip.h"


void chip_debug_dump(chip_t *chip) {
  
  printf("Chip %s is a %s with %d pins total\n", chip->name, chip->type, chip->pin_count);
  printf("--------------------\n");
  printf("Pin # |");
  for(size_t i = 0; i < chip->pin_count; i++) {
    printf(" %d |", (int)i+1);
  }
  printf("\n");
  printf("Value |");
  for(size_t i = 0; i < chip->pin_count; i++) {
    if(i >= 9) {
      printf(" ");
    }
    printf(" %d |", chip->pins_state[i+1]);
  }
  printf("\n");

}
