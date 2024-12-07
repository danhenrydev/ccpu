#include <stdlib.h>
#include <string.h>
#include "circuit.h"



ccpu_circuit_t *ccpu_circuit_create(char *name) {

  ccpu_circuit_t *circuit = malloc(sizeof(ccpu_circuit_t));
  strcpy(circuit->name, name);

  circuit->registered_count = 0;

  return circuit;

}

void ccpu_circuit_register_node(ccpu_circuit_t *circuit, ccpu_node_t *node) {
  circuit->nodes[circuit->registered_count] = node;
  circuit->registered_count++;
}


void ccpu_circuit_update_nodes(ccpu_circuit_t *circuit) {

}
