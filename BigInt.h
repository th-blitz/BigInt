

#ifndef BigInt_H
#define BigInt_H

#include "stdint.h"
#include "ByteStack.h"

typedef enum BigIntType {
    uint128 = 4,
    uint256 = 8,
    uint512 = 16,
    uint1024 = 32,
} BigIntType;



typedef struct uint128_t {
    uint32_t array[uint128];
    BigIntType type;
} uint128_t;


uint128_t BigInt128(ByteStack* bytes);
uint32_t BigInt128_add(uint128_t* a, uint128_t* b, uint128_t* c);
void print_bigint(uint128_t* a);


#endif