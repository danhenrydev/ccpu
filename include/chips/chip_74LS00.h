#ifndef CHIP_74LS00_H
#define CHIP_74LS00_H

#include "chip.h"
 

/**
 * @brief Creates a new instance of a 74LS00 NAND gate chip
 * 
 * The 74LS00 is a quad 2-input NAND gate integrated circuit.
* Each chip contains four independent NAND gates with two inputs each.
 * 
 * @details The chip has 14 pins:
 *          - VCC (Pin 14)
 *          - GND (Pin 7) 
 *          - 4 NAND gates with inputs A,B and output Y:
 *            - Gate 1: 1A(1), 1B(2), 1Y(3)
 *            - Gate 2: 2A(4), 2B(5), 2Y(6)
 *            - Gate 3: 3A(9), 3B(10), 3Y(8)
 *            - Gate 4: 4A(12), 4B(13), 4Y(11)
 *
 * @return ccpu_chip_t* Pointer to the newly created chip structure.
 *                      NULL if memory allocation fails.
 */
ccpu_chip_t *chip_74LS00_create();

void chip_74LS00_update(ccpu_chip_t *chip);

#endif // !CHIP_74LS00_H
