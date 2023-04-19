

#ifndef BigInt_H
#define BigInt_H

#include "stdint.h"
// #include "ByteStack.h"

typedef enum BigIntType {
    uint128 = 4,
    uint256 = 8,
    uint512 = 16,
    uint1024 = 32,
    uint2048 = 64
} BigIntType;

typedef struct uint128_tt {
    uint32_t array[uint128];
    BigIntType type;
} uint128_t;

typedef struct uint256_tt {
    uint32_t array[uint256];
    BigIntType type;
} uint256_t;

typedef struct uint512_tt {
    uint32_t array[uint512];
    BigIntType type;
} uint512_t;

typedef struct uint1024_tt {
    uint32_t array[uint1024];
    BigIntType type;
} uint1024_t;

typedef struct uint2048_tt {
    uint32_t array[uint2048];
    BigIntType type;
} uint2048_t;


typedef struct BigInt {
    uint128_t (*u128)();
    uint256_t (*u256)();
    uint512_t (*u512)();
    uint1024_t (*u1024)();
    uint2048_t (*u2048)();

    uint128_t (*u128_from_string)(char* string, uint64_t string_len);
    uint256_t (*u256_from_string)(char* string, uint64_t string_len);
    uint512_t (*u512_from_string)(char* string, uint64_t string_len);
    uint1024_t (*u1024_from_string)(char* string, uint64_t string_len);
    uint2048_t (*u2048_from_string)(char* string, uint64_t string_len);

    uint32_t (*add)(void* a, void* b, void* c, BigIntType type);
    int (*compare)(void* a, void* b, BigIntType type);
    uint32_t (*multiply_by_n)(void* a, uint32_t n, void* b, BigIntType type);
    uint32_t (*subtract)(void* a, void* b, void* c, BigIntType type);
    void (*multiply)(void* a, void* b, void* c, BigIntType type);
    uint32_t (*add_by_n)(void* a, uint32_t n, void* b, BigIntType type);

    void (*print)(void* a, BigIntType type);
    void (*to_string)(void* a, BigIntType type, char* string);

} BigInt;
 
BigInt BigIntModule();

void BigInt_to_string(void* a, BigIntType type, char* string);

#endif