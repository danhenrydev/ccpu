#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "common.h"

ccpu_node_t *node_create() {

  ccpu_node_t *node = malloc(sizeof(ccpu_node_t));
  node->registered_count = 0;
  node->state = LOW;

  return node;
}

void node_register_chip(ccpu_node_t *node, ccpu_chip_t *chip, unsigned int pin_number) {

  node->chips[node->registered_count] = chip;
  node->pins[node->registered_count] = pin_number;
  node->registered_count++;

}

bool node_update(ccpu_node_t *node) {

  bool updated = false;

  bool set_high = false;
  for(size_t i = 0; i < node->registered_count; i++) {
    if(node->chips[i]->pin_designation[node->pins[i]] == OUTPUT && node->chips[i]->pins_state[node->pins[i]] == HIGH) {
      set_high = true;
    }
  }

  if(set_high) {
    if(node->state == LOW){
      updated = true;
    }
    node->state = HIGH;
  }else{
    if(node->state == HIGH) {
      updated = true;
    }
    node->state = LOW;
  }

  for(size_t i = 0; i < node->registered_count; i++) {
    if(node->chips[i]->pin_designation[node->pins[i]] == INPUT)
    {
      if(node->chips[i]->pins_state[node->pins[i]] != node->state) {
        updated = true;
      }
      node->chips[i]->pins_state[node->pins[i]] = node->state;
    }
  }

  for(size_t i = 0; i < node->registered_count; i++) {
    node->chips[i]->update(node->chips[i]);
  }

  return updated;

}
