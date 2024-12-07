#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "chip.h"
#include "common.h"

ccpu_node_t *ccpu_node_create(char *name) {

  ccpu_node_t *node = malloc(sizeof(ccpu_node_t));
  strcpy(node->name, name);
  node->registered_count = 0;
  node->state = LOW;

  return node;
}

void ccpu_node_register_pin(ccpu_node_t *node, ccpu_pin_t *pin) {

  node->pins[node->registered_count] = pin;
  node->registered_count++;

}

bool ccpu_node_update(ccpu_node_t *node) {

  node->state = LOW;
  for(size_t i = 0; i < node->registered_count; i++) {
    if((node->pins[i]->state == HIGH) && (node->pins[i]->pin_type == PIN_TYPE_OUTPUT)) {
      node->state = HIGH;
    }
  }

  for(size_t i = 0; i < node->registered_count; i++) {
    if(node->pins[i]->pin_type == PIN_TYPE_INPUT) {
      ccpu_pin_set_state(node->pins[i], node->state);
    }
    node->pins[i]->owning_chip->update(node->pins[i]->owning_chip);
  }

  return false;
}


void ccpu_node_debug_dump(ccpu_node_t *node) {
  printf("Node %s is connected to %d pins and has a state of %d\n", node->name, node->registered_count, node->state);

}
