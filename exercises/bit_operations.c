#include <stdbool.h>
#include <stdint.h>
#include <assert.h>
#include <stddef.h>

bool set_bit(uint32_t *value, uint8_t bit_position) {
    if ((value == NULL) || (bit_position >= 32U)) {
        return false; // Return false if invalid input
    }
    *value |= (1U << bit_position);
    return true;
}

bool clear_bit(uint32_t *value, uint8_t bit_position) {

    if ((value == NULL) || (bit_position >= 32U)) {
        return false; // Return false if invalid input
    }

    *value &= ~(1U << bit_position);
    return true;
}

bool toggle_bit(uint32_t *value, uint8_t bit_position) {
    if ((value == NULL) || (bit_position >= 32U)) {
        return false; // Return false if invalid input
    }

    *value = *value ^ (1U << bit_position);
    return true;
}

bool is_bit_set(uint32_t value, uint8_t bit_position, bool *result) {

    if ((value == NULL) || (bit_position >= 32U)) {
        return false; // Return false if invalid input
    }

    *result = (value & (1U << bit_position)) != 0;
    return true;
}



int main() {
    uint32_t value = 0U; 
    bool result = false;

    assert(set_bit(&value, 3U) == true);
    assert(value == 8U); // 0000 1000
    assert(is_bit_set(value, 3U, &result) == true);
    assert(result == true);

    assert(toggle_bit(&value, 3U) == true); 
    assert(value == 0U); // 0000 0000
    
    assert(set_bit(&value, 32U) == false); //1 0000 0000 0000 0000 must not work
    assert(set_bit(NULL, 32U) == false); //NULL must not work
    assert(is_bit_set(value, 3U, NULL) == false); //NULL result must not work

    assert(clear_bit(&value, 3U) == true);
    assert(value == 0U); // 0000 0000

    printf("All tests passed successfully.\n");

    return 0;
}