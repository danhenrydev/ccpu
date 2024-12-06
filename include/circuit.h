#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "common.h"
#include "node.h"

typedef struct ccpu_circuit_s {

  ccpu_node_t *nodes[CIRCUIT_MAX_NODES];
  unsigned int registered_count;

} ccpu_circuit_t;

ccpu_circuit_t *circuit_create();

void circuit_register_node(ccpu_circuit_t *circuit, ccpu_node_t *node);
void circuit_update_nodes(ccpu_circuit_t *circuit);



#endif // !CIRCUIT_H
