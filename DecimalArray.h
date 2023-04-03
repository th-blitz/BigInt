#ifndef DecimalArray_H
#define DecimalArray_H

#include "ByteStack.h"
#include "stdbool.h"

typedef struct DecimalArray {
    uint8_t* array;
    uint64_t size;
} DecimalArray;

DecimalArray malloc_decimal_array(uint64_t size);
void print_decimal_array(DecimalArray number);
DecimalArray decimal_array_from_string(char* num);
void free_decimal_array(DecimalArray number);
DecimalArray decimal_array_addition(DecimalArray a, DecimalArray b);
int8_t decimal_array_compare(DecimalArray a, DecimalArray b);
bool is_decimal_array_zero(DecimalArray a);
DecimalArray decimal_array_multiplication(DecimalArray a, DecimalArray b);
uint8_t decimal_array_divide_by_2(DecimalArray dividend);
ByteStack decimal_to_binary(DecimalArray a);


#endif