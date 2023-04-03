#include "stdint.h"
#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"


typedef enum BigIntType {
    uint128_t = 16,
} BigIntType;

typedef struct uint32_Stack {
    uint32_t node;
    struct uint32_Stack* next;
} uint32_Stack;

typedef struct uint8_Stack {
    uint8_t node;
    struct uint8_Stack* next;
} uint8_Stack;

typedef struct uBigInt128_t {
    uint8_t array[uint128_t];
    BigIntType type;
} uBigInt128_t;


uBigInt128_t uBigInt128() {
    uBigInt128_t integer = {.array = {0}, .type = uint128_t};
    return integer;
}


int main() {

    uBigInt128_t a = uBigInt128();
    uBigInt128_t b = uBigInt128();

    return 0;
}