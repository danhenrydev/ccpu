#ifndef CHIP_H
#define CHIP_H

#include <stdint.h>
#include "common.h"

typedef struct ccpu_chip_s ccpu_chip_t;

/**
 * @brief Pin type enumeration defining possible pin configurations
 *
 * This enumeration defines the possible types a pin can be configured as
 * in the CCPU system. Each pin must be one of these types.
 *
 * @enum ccpu_pin_type_t
 * @var PIN_TYPE_INPUT    Pin configured as an input
 * @var PIN_TYPE_OUTPUT   Pin configured as an output
 * @var PIN_TYPE_VCC      Pin configured as power supply (VCC)
 * @var PIN_TYPE_GROUND   Pin configured as ground connection
 */
typedef enum {
  PIN_TYPE_INPUT,
  PIN_TYPE_OUTPUT,
  PIN_TYPE_VCC,
  PIN_TYPE_GROUND
} ccpu_pin_type_t;

/**
 * @brief Pin structure representing a physical pin in the CCPU system
 *
 * This structure defines a pin's properties including its name, type,
 * owning chip and current state. Each pin is associated with a chip
 * and maintains its own state information.
 *
 * @struct ccpu_pin_s
 * @var owning_chip   Pointer to the chip that owns this pin
 * @var name          Null-terminated string containing pin name
 * @var pin_number    The pin number from the IC data sheet
 * @var pin_type      Type configuration of the pin (input/output/vcc/ground)
 * @var state         Current logical state of the pin
 */
typedef struct ccpu_pin_s {

  ccpu_chip_t *owning_chip;
  char name[PIN_MAX_NAME_LENGTH];
  uint8_t pin_number;
  ccpu_pin_type_t pin_type;

  ccpu_state_t state;

} ccpu_pin_t;
 
struct ccpu_chip_s;
typedef void (*chip_update_fn_t)(struct ccpu_chip_s *chip);

/** 
 * Represents a chip with pins and update functionality.
 * Contains chip type, name, pin array, pin count, pin designations
 * and update function.
 *
 * @struct ccpu_chip_s
 * @var type Array holding the chip type identifier
 * @var name Array holding the chip instance name 
 * @var pins_state Array of pin values/states for the chip
 * @var pin_count Number of pins on the chip
 * @var pin_designation Array indicating pin input/output designation
 * @var update Function pointer for updating chip state
 */
typedef struct ccpu_chip_s {

  char type[CHIP_MAX_NAME_LENGTH];
  char name[CHIP_MAX_NAME_LENGTH];

  ccpu_pin_t *pins[CHIP_MAX_PINS];

  unsigned int pin_count;
  chip_update_fn_t update;

} ccpu_chip_t;

/** @brief Dumps debug information about a chip
 *  @details Prints detailed information about the chip's state including type,
 *           name, pin states and designations for debugging purposes
 *  @param chip Pointer to the chip structure to dump debug info for
 */
void ccpu_chip_debug_dump(ccpu_chip_t *chip);
/**
 * @brief Creates a new pin in the CCPU system
 *
 * This function allocates and initializes a new pin structure with the specified
 * parameters. The pin is associated with the provided owning chip and configured
 * according to the given type. The pin's name and number are set based on the
 * input parameters.
 *
 * @param[in] owning_chip  Pointer to the chip that will own this pin
 * @param[in] name         Null-terminated string containing the pin name
 * @param[in] pin_number   The pin number from the IC data sheet
 * @param[in] pin_type     Type configuration for the pin (input/output/vcc/ground)
 *
 * @return Pointer to the newly created pin structure if successful,
 *         NULL if allocation fails or parameters are invalid
 *
 * @note The caller is responsible for eventually freeing the returned pin
 *       structure when it is no longer needed
 */
ccpu_pin_t *ccpu_pin_create(ccpu_chip_t *owning_chip, char *name, uint8_t pin_number, ccpu_pin_type_t pin_type);

/**
 * @brief Sets the logical state of a pin in the CCPU system
 *
 * This function updates the logical state of the specified pin. The pin must be
 * properly initialized and belong to a valid chip before its state can be modified.
 * If the pin is configured as an input, setting its state directly may have no effect
 * as input pins are typically driven by external signals.
 *
 * @param[in,out] pin   Pointer to the pin structure to modify
 * @param[in] state     New logical state to set for the pin
 *
 */
void ccpu_pin_set_state(ccpu_pin_t *pin, ccpu_state_t state);

#endif
