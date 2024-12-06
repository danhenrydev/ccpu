#ifndef CHIP_74LS74_H
#define CHIP_74LS74_H

#include "chip.h"


/**
 * @brief Creates a new 74LS74 dual D-type flip-flop chip instance
 *
 * @param name The identifier name for the chip instance
 * @return ccpu_chip_t* Pointer to the newly created chip instance, NULL if creation fails
 *
 * @details The 74LS74 contains two independent D-type positive-edge-triggered 
 *          flip-flops with direct preset and clear inputs. Each flip-flop has
 *          complementary Q and Q-bar outputs.
 *
 * The chip has the following pins:
 * - Pin 1: /PRE1 (Active low preset for FF1)
 * - Pin 2: D1 (Data input for FF1) 
 * - Pin 3: CLK1 (Clock input for FF1)
 * - Pin 4: /CLR1 (Active low clear for FF1)
 * - Pin 5: Q1 (Q output for FF1)
 * - Pin 6: /Q1 (Q-bar output for FF1)
 * - Pin 7: GND
 * - Pin 8: /Q2 (Q-bar output for FF2)
 * - Pin 9: Q2 (Q output for FF2)
 * - Pin 10: /CLR2 (Active low clear for FF2)
 * - Pin 11: CLK2 (Clock input for FF2)
 * - Pin 12: D2 (Data input for FF2)
 * - Pin 13: /PRE2 (Active low preset for FF2)
 * - Pin 14: VCC
 */
ccpu_chip_t *chip_74LS74_create(char *name);
void chip_74LS74_update(ccpu_chip_t *chip);

#endif // !CHIP_74LS74_H
