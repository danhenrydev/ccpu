#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "common.h"
#include "node.h"

/**
 * @brief Circuit structure representing a collection of nodes
 *
 * This structure maintains an array of circuit nodes and tracks the number
 * of registered nodes in the circuit.
 */
typedef struct ccpu_circuit_s {

  ccpu_node_t *nodes[CIRCUIT_MAX_NODES];
  unsigned int registered_count;

} ccpu_circuit_t;

/**
 * @brief Creates a new circuit instance
 * 
 * Allocates and initializes a new circuit structure with zero registered nodes.
 * 
 * @return Pointer to the newly created circuit structure
 */
ccpu_circuit_t *circuit_create();

/**
 * @brief Registers a node in the circuit
 * 
 * Adds a node to the circuit's node array and increments the registered count.
 * 
 * @param circuit Pointer to the circuit structure
 * @param node Pointer to the node to register
 */
void circuit_register_node(ccpu_circuit_t *circuit, ccpu_node_t *node);

/**
 * @brief Updates all nodes in the circuit
 * 
 * Iterates through each registered node and calls their update function.
 * 
 * @param circuit Pointer to the circuit structure
 */
void circuit_update_nodes(ccpu_circuit_t *circuit);



#endif // !CIRCUIT_H
