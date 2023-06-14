

#ifndef BigInt_H
#define BigInt_H

#include <stdint.h>
#include <stdbool.h>

// #include "ByteStack.h"

typedef enum BigIntType {
    uint128 = 4,
    uint256 = 8,
    uint512 = 16,
    uint1024 = 32,
    uint2048 = 64
} BigIntType;

typedef enum BaseType {
    base_2 = 2,
    base_8 = 8,
    base_10 = 10,
    base_16 = 16,
} BaseType;

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
    uint32_t (*u128_add)(uint128_t* a, uint128_t* b, uint128_t* c);
    uint32_t (*u256_add)(uint256_t* a, uint256_t* b, uint256_t* c);
    uint32_t (*u512_add)(uint512_t* a, uint512_t* b, uint512_t* c);
    uint32_t (*u1024_add)(uint1024_t* a, uint1024_t* b, uint1024_t* c);
    uint32_t (*u2048_add)(uint2048_t* a, uint2048_t* b, uint2048_t* c);

    int (*compare)(void* a, void* b, BigIntType type);
    int (*u128_compare)(uint128_t* a, uint128_t* b);
    int (*u256_compare)(uint256_t* a, uint256_t* b);
    int (*u512_compare)(uint512_t* a, uint512_t* b);
    int (*u1024_compare)(uint1024_t* a, uint1024_t* b);
    int (*u2048_compare)(uint2048_t* a, uint2048_t* b);

    uint32_t (*multiply_by_n)(void* a, uint32_t n, void* b, BigIntType type);
    uint32_t (*u128_multiply_by_n)(uint128_t* a, uint32_t n, uint128_t* b);
    uint32_t (*u256_multiply_by_n)(uint256_t* a, uint32_t n, uint256_t* b);
    uint32_t (*u512_multiply_by_n)(uint512_t* a, uint32_t n, uint512_t* b);
    uint32_t (*u1024_multiply_by_n)(uint1024_t* a, uint32_t n, uint1024_t* b);
    uint32_t (*u2048_multiply_by_n)(uint2048_t* a, uint32_t n, uint2048_t* b);

    uint32_t (*subtract)(void* a, void* b, void* c, BigIntType type);
    uint32_t (*u128_subtract)(uint128_t* a, uint128_t* b, uint128_t* c);
    uint32_t (*u256_subtract)(uint256_t* a, uint256_t* b, uint256_t* c);
    uint32_t (*u512_subtract)(uint512_t* a, uint512_t* b, uint512_t* c);
    uint32_t (*u1024_subtract)(uint1024_t* a, uint1024_t* b, uint1024_t* c);
    uint32_t (*u2048_subtract)(uint2048_t* a, uint2048_t* b, uint2048_t* c);

    void (*multiply)(void* a, void* b, void* c, BigIntType type);

    uint32_t (*add_by_n)(void* a, uint32_t n, void* b, BigIntType type);
    uint32_t (*u128_add_by_n)(uint128_t* a, uint32_t n, uint128_t* b);
    uint32_t (*u256_add_by_n)(uint256_t* a, uint32_t n, uint256_t* b);
    uint32_t (*u512_add_by_n)(uint512_t* a, uint32_t n, uint512_t* b);
    uint32_t (*u1024_add_by_n)(uint1024_t* a, uint32_t n, uint1024_t* b);
    uint32_t (*u2048_add_by_n)(uint2048_t* a, uint32_t n, uint2048_t* b);
    
    // in BigInt_b.c
    uint32_t (*divide_by_n)(void* a, uint32_t n, void* b, BigIntType type); 
    uint32_t (*u128_divide_by_n)(uint128_t* a, uint32_t n, uint32_t remainder, uint128_t* b);
    uint32_t (*u256_divide_by_n)(uint256_t* a, uint32_t n, uint32_t remainder, uint256_t* b);
    uint32_t (*u512_divide_by_n)(uint512_t* a, uint32_t n, uint32_t remainder, uint512_t* b);
    uint32_t (*u1024_divide_by_n)(uint1024_t* a, uint32_t n, uint32_t remainder, uint1024_t* b);
    uint32_t (*u2048_divide_by_n)(uint2048_t* a, uint32_t n, uint2048_t* b);

    void (*print)(void* a, BigIntType type, BaseType base_type);
    void (*println)(void* a, BigIntType type, BaseType base_type);
    void (*print_hex)(void* a, BigIntType type, bool truncate_zeros);
    void (*println_hex)(void* a, BigIntType type, bool truncate_zeros);
    void (*to_string)(void* a, BigIntType type, char* string);

} BigInt;
 
BigInt BigIntModule();

uint128_t BigInt_get_u128_MAX();
#define u128_MAX BigInt_get_u128_MAX();

uint256_t BigInt_get_u256_MAX();
#define u256_MAX BigInt_get_u256_MAX();

uint512_t BigInt_get_u512_MAX();
#define u512_MAX BigInt_get_u512_MAX();

uint1024_t BigInt_get_u1024_MAX();
#define u1024_MAX BigInt_get_u1024_MAX();

uint2048_t BigInt_get_u2048_MAX();
#define u2048_MAX BigInt_get_u2048_MAX();

#endif