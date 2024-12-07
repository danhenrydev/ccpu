#ifndef COMMON_H
#define COMMON_H

#include <stdbool.h>

#define LOW 0
#define HIGH 1
typedef bool ccpu_state_t;

#define CHIP_MAX_PINS 20
#define CHIP_MAX_NAME_LENGTH 127

#define PIN_MAX_NAME_LENGTH 127

#define NODE_MAX_CONNECTIONS 127
#define NODE_NAME_MAX_SIZE 128

#define CIRCUIT_NAME_MAX_LENGTH 128
#define CIRCUIT_MAX_NODES 256

#endif // ifndef COMMON_H
