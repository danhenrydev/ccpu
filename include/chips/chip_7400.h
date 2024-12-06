#ifndef CHIP_7400_H
#define CHIP_7400_H

#include "chip.h"

/**
 * @brief Create a chip_t for the 7400 Quad 2 input NAND gate chip
 */
chip_t *chip_7400_create(void);
void chip_7400_update(chip_t *chip);


#endif // !CHIP_7400_H
