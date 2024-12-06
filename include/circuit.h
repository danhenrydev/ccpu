#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "common.h"
#include "node.h"

typedef struct circuit_s {

  node_t *nodes[CIRCUIT_MAX_NODES];
  unsigned int registered_count;

} circuit_t;

circuit_t *circuit_create();

void circuit_register_node(circuit_t *circuit, node_t *node);
void circuit_update_nodes(circuit_t *circuit);



#endif // !CIRCUIT_H
