

#ifndef BigInt_H
#define BigInt_H

#include "stdint.h"
#include "ByteStack.h"

typedef enum BigIntType {
    uint128t = 16,
} BigIntType;

typedef struct uint128 {
    uint8_t array[uint128t];
    BigIntType type;
} uint128;

uint128 BigInt128(ByteStack* bytes);
uint16_t BigInt128_add(uint128* a, uint128* b, uint128* c);
void print_bigint(uint128* a);


#endif