#include <stdlib.h>
#include "circuit.h"



circuit_t *circuit_create() {

  circuit_t *circuit = malloc(sizeof(circuit_t));

  circuit->registered_count = 0;

  return circuit;

}

void circuit_register_node(circuit_t *circuit, node_t *node) {
  circuit->nodes[circuit->registered_count] = node;
  circuit->registered_count++;
}


void circuit_update_nodes(circuit_t *circuit) {

  bool updated = false;
  do {
    updated = false;
    for(size_t i = 0; i < circuit->registered_count; i++) {
      if(node_update(circuit->nodes[i])) {
        updated = true;
      }
    }
  }while (updated);
}
