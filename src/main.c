#include <stdio.h>
#include <string.h>
#include "chips/chip_74LS00.h"
#include "node.h"

int main(void) {

  ccpu_node_t *node_a = ccpu_node_create("node_a");
   
  ccpu_chip_t *chip_a = chip_74LS00_create("chip_a");
  ccpu_chip_t *chip_b = chip_74LS00_create("chip_b");

  ccpu_node_register_pin(node_a, chip_a->pins[3]);
  ccpu_node_register_pin(node_a, chip_b->pins[1]);

  ccpu_node_update(node_a);
  ccpu_node_debug_dump(node_a);

  ccpu_chip_debug_dump(chip_a);
  ccpu_chip_debug_dump(chip_b);

  return 0;
}
