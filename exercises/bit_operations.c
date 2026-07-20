#include <stdbool.h>
#include <stdint.h>

uint32_t set_bit(uint32_t value, uint8_t bit_position) {
    return value | (1U << bit_position);
}

uint32_t clear_bit(uint32_t value, uint8_t bit_position) {
    return value & ~(1U << bit_position);
}

uint32_t toggle_bit(uint32_t value, uint8_t bit_position) {
    return value ^ (1U << bit_position);
}

bool is_bit_set(uint32_t value, uint8_t bit_position) {
    return (value & (1U << bit_position)) != 0;
}