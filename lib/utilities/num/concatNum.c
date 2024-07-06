/**
 * @file concatNum.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-07-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "concatNum.h"

uint16_t concatenateNumbers(uint16_t a, uint16_t b) {
    // Calculate the number of digits in b
    uint16_t digits = b > 0 ? (uint16_t) log10(b) + 1 : 1;
    // Shift a to the left by the number of digits in b and add b
    return a * pow(10, digits) + b;
}
