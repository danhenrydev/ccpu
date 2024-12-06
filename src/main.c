#include <stdio.h>
#include <string.h>
#include "circuit.h"
#include "node.h"
#include "chip.h"
#include "chips/chip_7400.h"


int main(void) {

  // Create a circuit
  circuit_t *circuit_a = circuit_create();
  
  // Create a node and add it to the circuit
  node_t *node_a = node_create();
  circuit_register_node(circuit_a, node_a);

  // Create 2 7400s and add them to the node
  chip_t *chip_a = chip_7400_create("chip_a");
  chip_t *chip_b = chip_7400_create("chip_b");

  node_register_chip(node_a, chip_a, 3);
  node_register_chip(node_a, chip_b, 1);

  circuit_update_nodes(circuit_a);

  printf("Circuit state is: \n");
  printf("node_a state %d\n", node_a->state);
  printf("chip_a pins[1-3] states %d %d %d\n", chip_a->pins_state[1], chip_a->pins_state[2], chip_a->pins_state[3]);
  printf("chip_b pins[1-3] states %d %d %d\n", chip_b->pins_state[1], chip_b->pins_state[2], chip_b->pins_state[3]);

  printf("\n\nSetting pin 3 high on chip_a\n");
  chip_a->pins_state[3] = HIGH;

  printf("Propagating circuit\n\n");
  circuit_update_nodes(circuit_a);

  printf("Circuit state is: \n");
  printf("node_a state %d\n", node_a->state);
  printf("chip_a pins[1-3] states %d %d %d\n", chip_a->pins_state[1], chip_a->pins_state[2], chip_a->pins_state[3]);
  printf("chip_b pins[1-3] states %d %d %d\n", chip_b->pins_state[1], chip_b->pins_state[2], chip_b->pins_state[3]);
   



  return 0;
}
