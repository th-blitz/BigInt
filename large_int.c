#include "stdint.h"
#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"

uint64_t power_of(uint64_t number, uint64_t exponent) {
    if (exponent == 0) {
        return 1;
    } else if (exponent == 1) {
        return number;
    }
    uint64_t result = number;
    while (exponent != 1) {
        result *= number;
        exponent -= 1;
    }
    return result;
}

void xor_bit_array(uint8_t* a, uint8_t* b, uint8_t* c, size_t array_size) {
    for (size_t i = 0; i < array_size; i++) {
        c[i] = a[i] ^ b[i];
    }
}

void and_bit_array(uint8_t* a, uint8_t* b, uint8_t* c, size_t array_size) {
    for (size_t i = 0; i < array_size; i++) {
        c[i] = a[i] & b[i];
    }
}

void left_shift_bit_array(uint8_t* array, size_t array_size, size_t shift) {
    
    uint8_t left_buffer = 0;
    uint8_t right_buffer = 0;

    uint64_t cycles = (shift / 8);
    shift = shift % 8;
    while (cycles != 0) {
        for (int i = array_size - 1; i > -1; i--) {
            left_buffer = array[i];
            array[i] = right_buffer;
            right_buffer = left_buffer;
        }
        cycles -= 1;
    }

    left_buffer = 0;
    right_buffer = 0;

    if (shift > 0) {

        uint8_t mask = ((power_of(2, shift) - 1) << (8 - shift));

        for (int i = array_size - 1; i > -1; i--) {
            left_buffer |= (array[i] & mask);
            left_buffer >>= (8 - shift);
            array[i] <<= shift;
            array[i] |= right_buffer;
            right_buffer = left_buffer;
            left_buffer = 0;
        }
    }
    
}

bool is_bit_array_zero(uint8_t* array, size_t array_size) {
    for (int i = 0; i < array_size; i++) {
        if (array[i] != 0) {
            return false;
        }
    }
    return true;
}

uint8_t add_bit_array(uint8_t* a, uint8_t* b, size_t array_size) {

    uint8_t end_carry = 0;
    uint8_t* temp = (uint8_t*)malloc(sizeof(uint8_t) * array_size);

    while(is_bit_array_zero(b, array_size) == false) {
        
        xor_bit_array(a, b, temp, array_size);
        and_bit_array(a, b, b, array_size);

        if ((b[0] & 0x80) == 0x80) {
            end_carry <<= 1;
            end_carry |= 0b00000001;
        }

        left_shift_bit_array(b, array_size, 1);
        for (int i = 0; i < array_size; i++) {
            a[i] = temp[i];
        }
    }
    free(temp);
    return end_carry;
}

void add(uint8_t* a, uint8_t* b, uint8_t* c) {
    uint8_t temp;
    while(*b != 0) {
        temp = *a ^ *b;
        *b = (*a & *b);
        if ((*b & 0x80) == 0x80) {
            *c = *c << 1;
            *c = *c | 0b00000001;
        }
        *b = *b << 1;
        *a = temp;
    }
    return;
}

void print_bit_array(uint8_t a[], size_t a_len) {
    
    uint64_t mask[8];
    for (uint64_t i = 0; i < 8; i++) {
        mask[i] = power_of(2, 7 - i);
    }

    for (int i = 0; i < a_len; i++) {
        for (int j = 0; j < 8; j++) {
            ((a[i] & mask[j]) == mask[j]) ? (printf("1")) : printf("0");
        }        
    }
    printf("\n");
}


int main() {

    uint8_t a = 255;
    uint8_t b = 1;
    uint8_t c = 0x00;
    uint8_t temp;

    printf("%d %d %d \n", a, b, c);

    while (b != 0) {
        temp = a ^ b;
        b = (a & b);
        if ((b & 0x80) == 0x80) {
            c = c << 1;
            c = c | 0b00000001;
        }
        b = b << 1;
        a = temp;
    }


    printf("%d %d %d \n", a, b, c);


    uint8_t aa[9] = { 122, 199, 141, 72, 201, 35, 202, 121, 11};
    uint8_t bb[9] = { 255, 197, 46, 149, 67, 242, 213, 67, 12};
    size_t array_size = 9;
    uint8_t cc = 0x00;

    // print_bit_array(aa, 4);
    // print_bit_array(bb, 4);

    // for (int i = 3; i > -1; i--) {
    //     bb[i] &= cc;
    //     add(&aa[i], &bb[i], &cc);
    // }    
    // printf("\n");
    // print_bit_array(aa, 4);
    // print_bit_array(bb, 4);
    // printf("%d\n", cc);


    // print_bit_array(aa, 4);
    // left_shift_bit_array(aa, 4, 9);
    // print_bit_array(aa, 4);

    printf("a     : ");
    print_bit_array(aa, array_size);
    printf("    b : ");
    print_bit_array(bb, array_size);

    cc = add_bit_array(aa, bb, array_size);

    printf("a + b : ");
    print_bit_array(aa, array_size);
    printf("cc : %d\n", cc);


    return 0;
}