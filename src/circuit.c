#include <stdlib.h>
#include "circuit.h"



ccpu_circuit_t *circuit_create() {

  ccpu_circuit_t *circuit = malloc(sizeof(ccpu_circuit_t));

  circuit->registered_count = 0;

  return circuit;

}

void circuit_register_node(ccpu_circuit_t *circuit, ccpu_node_t *node) {
  circuit->nodes[circuit->registered_count] = node;
  circuit->registered_count++;
}


void circuit_update_nodes(ccpu_circuit_t *circuit) {

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
