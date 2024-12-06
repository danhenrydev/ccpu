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

  ccpu_chip_t *chips[NODE_MAX_CONNECTIONS];
  unsigned int pins[NODE_MAX_CONNECTIONS];
  unsigned int registered_count;

} ccpu_node_t;

ccpu_node_t *node_create();
void node_register_chip(ccpu_node_t *node, ccpu_chip_t *chip, unsigned int pin_number);
bool node_update(ccpu_node_t *node);


#endif // !NODE_H
