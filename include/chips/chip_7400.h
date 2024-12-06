#ifndef CHIP_7400_H
#define CHIP_7400_H

#include "chip.h"

/**
 * @brief Creates a new 7400 Quad 2-input NAND gate chip instance
 * 
 * @details The 7400 contains four independent 2-input NAND gates. Each gate performs
 * the logical NAND operation on its two inputs. 
 *
 * @param name Unique identifier string for this chip instance
 * @return chip_t* Pointer to the newly created chip instance, or NULL if creation fails
 */
ccpu_chip_t *chip_7400_create(char *name);
void chip_7400_update(ccpu_chip_t *chip);


#endif // !CHIP_7400_H
