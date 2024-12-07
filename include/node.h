#ifndef NODE_H
#define NODE_H

#include <stdint.h>
#include "common.h"
#include "chip.h"


/**
 * @brief Node structure representing a connection point in the circuit
 *
 * A node represents an electrical connection point that can connect multiple chips
 * and pins together. It maintains the current state and tracks all connected components.
 *
 * @struct node_s
 * @var state Current electrical state of the node
 * @var chips Array of pointers to connected chips
 * @var pins Array of pin numbers corresponding to each connected chip
 * @var registered_count Number of connections currently registered to this node
 */
typedef struct ccpu_node_s {

  ccpu_state_t state;
  char name[NODE_NAME_MAX_SIZE];

  ccpu_pin_t *pins[NODE_MAX_CONNECTIONS];
  unsigned int registered_count;

} ccpu_node_t;

/**
 * @brief Creates a new node instance
 *
 * Allocates and initializes a new node structure with default values.
 * The node starts with no connections and an undefined state.
 * 
 * @return Pointer to the newly created node, or NULL if allocation fails
 */
ccpu_node_t *ccpu_node_create(char *name);

/**
 * @brief Registers a chip connection to this node
 * 
 * Associates a chip's pin with this node, allowing the node to track
 * and update the connected components. The connection is added to the
 * node's internal connection arrays.
 * 
 * @param node Pointer to the node structure
 * @param chip Pointer to the chip to connect
 * @param pin_number The pin number on the chip to connect
 */
void ccpu_node_register_pin(ccpu_node_t *node, ccpu_pin_t *pin);

/**
 * @brief Updates the node's state based on connected components
 * 
 * Evaluates all connected chips and pins to determine the node's new state.
 * Propagates state changes to all connected components.
 * 
 * @param node Pointer to the node to update
 * @return true if the node's state changed, false otherwise
 */
bool ccpu_node_update(ccpu_node_t *node);


void ccpu_node_debug_dump(ccpu_node_t *node);


#endif // !NODE_H
