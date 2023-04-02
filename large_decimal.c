#include "stdint.h"
#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)


typedef struct DecimalArray {
    uint8_t* array;
    uint64_t size;
} DecimalArray;

struct DecimalArray malloc_decimal_array(uint64_t size) {
    struct DecimalArray digit_array;
    digit_array.array = (uint8_t*)malloc(size * sizeof(uint8_t));
    digit_array.size = size;
    return digit_array;
}

void print_decimal_array(DecimalArray number) {
    for (uint64_t i = 0; i < number.size; i++) {
        printf("%d", number.array[number.size - 1 - i]);
    }
    printf("\n");
}

DecimalArray decimal_array_from_string(char* num) {
    DecimalArray number = malloc_decimal_array(strlen(num));
    for (uint64_t i = 0; i < number.size; i++) {
        number.array[number.size - 1 - i] = num[i] - '0';
    }
    return number;
}

void free_decimal_array(DecimalArray number) {
    free(number.array);
}

DecimalArray decimal_array_addition(DecimalArray a, DecimalArray b) {
    uint8_t carry = 0;
    uint8_t sum;
    uint64_t result_size = max(a.size, b.size) + 1;
    DecimalArray result = malloc_decimal_array(result_size);
    for (uint64_t i = 0; i < result_size; i++) {
        sum = ((i < a.size) ? a.array[i] : 0) + ((i < b.size) ? b.array[i] : 0) + carry;
        result.array[i] = sum % 10;
        carry = sum / 10;
    }
    return result;
}

// DecimalArray decimal_array_subtraction(DecimalArray a, DecimalArray b) {
//     uint8_t borrow = 0;
//     uint8_t A, B, sub;
//     DecimalArray c = malloc_decimal_array(a.size);
//     for (uint64_t i = 0; i < a.size - 1; i++ ) {
//         A = a.array[i];
//         B = (i < b.size) ? b.array[i] : 0;
//         sub = a.array[i + 1];
//         borrow = A >= B ? 0 : (sub * 10);  
//         sub = ((borrow + A) - B);
//         c.array[i] = sub % 10;
//         printf("%d ", borrow);
//         if (borrow > 0) {
//              = sub / 10;
//         }
//         print_decimal_array(a);
//         print_decimal_array(c);
//     }
//     A = a.array[a.size - 1];
//     B = ((a.size - 1) < b.size) ? b.array[a.size - 1] : 0;
//     c.array[a.size - 1] = A >= B ? A - B : B - A;
//     return c; 
// }

int8_t decimal_array_compare(DecimalArray a, DecimalArray b) {
    int8_t equal = 0;
    uint64_t max_size = max(a.size, b.size);
    for (uint64_t i = max_size - 1; i > 0; i--) {
        if (((i < a.size) ? a.array[i] : 0) > ((i < b.size) ? b.array[i] : 0)) {
            return 1;
        } else if (((i < a.size) ? a.array[i] : 0) < ((i < b.size) ? b.array[i] : 0)) {
            return -1;
        }
    }
    return equal ? a.array[0] == b.array[0] : (a.array[0] > b.array[0] ? 1 : 0);
}

DecimalArray decimal_array_multiplication(DecimalArray a, DecimalArray b) {
    uint8_t carry = 0;
    uint8_t multiplication = 0;
    uint8_t last_digit = 0;
    DecimalArray c = malloc_decimal_array(a.size + b.size);

    for (uint64_t i = 0; i < a.size; i++) {
        for (uint64_t j = 0; j < b.size; j++) {
            carry = c.array[i + j];
            multiplication = (a.array[i] * b.array[j]) + carry;
            carry = multiplication / 10;
            last_digit = multiplication % 10;
            c.array[i + j] = last_digit;
            c.array[i + j + 1] += carry;
        }
    }
    return c;
}

uint8_t decimal_array_divide_by_2(DecimalArray dividend) {

    uint64_t next_additive = 0;
    uint64_t additive;
    uint64_t size = dividend.size - 1;

    uint8_t remainder = (dividend.array[0] % 2 == 0) ? 0 : 1;

    for (uint64_t i = 0; i < dividend.size; i++) {
        additive = next_additive;
        if (dividend.array[size - i] % 2 != 0) {
            next_additive = 5;
        } else {
            next_additive = 0;
        }
        dividend.array[size - i] = (dividend.array[size - i] / 2) + additive;
    }

    return remainder;
}



int main() {

    char a_string[] = "0001000";
    char b_string[] = "1234";
    
    DecimalArray a = decimal_array_from_string(a_string);
    DecimalArray b = decimal_array_from_string(b_string);

    print_decimal_array(a);
    print_decimal_array(b);



    divide_by_2(a);

    print_decimal_array(a);

    printf("%d \n", decimal_array_compare(b, b));

    free_decimal_array(a);
    free_decimal_array(b);
    // free_decimal_array(c);

    return 0;
}