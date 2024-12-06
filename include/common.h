#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>

#define LOW 0
#define HIGH 1
typedef bool ccpu_state_t;

#define INPUT 0
#define OUTPUT 1

#define CHIP_MAX_PINS 20
#define CHIP_MAX_NAME_LENGTH 127

#define NODE_MAX_CONNECTIONS 127
#define CIRCUIT_MAX_NODES 256

#endif // ifndef COMMON_H
