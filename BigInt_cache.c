

#include <stdint.h>
#include <stdlib.h>


#include "BigInt.h"



static uint128_t u128_MAX_VAL = {
    .array = {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
    },
    .type = uint128
};

static uint256_t u256_MAX_VAL = {
    .array = {
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
    },
    .type = uint256
};

static uint512_t u512_MAX_VAL = {
    .array = {
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
    },
    .type = uint512
};
    
static uint1024_t u1024_MAX_VAL = {
    .array = {
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
    },
    .type = uint1024
};

static uint2048_t u2048_MAX_VAL = {
    .array = {
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
    },
    .type = uint2048
};

uint128_t BigInt_get_u128_MAX() {
    return u128_MAX_VAL;
}

uint256_t BigInt_get_u256_MAX() {
    return u256_MAX_VAL;
}

uint512_t BigInt_get_u512_MAX() {
    return u512_MAX_VAL;
}

uint1024_t BigInt_get_u1024_MAX() {
    return u1024_MAX_VAL;
}

uint2048_t BigInt_get_u2048_MAX() {
    return u2048_MAX_VAL;
}


uint128_t BigInt_get_u128_RAND() {
    uint128_t u128_rand;
    for (uint8_t i = 0; i < uint128; i++) {
        u128_rand.array[i] = rand();     
    }
    u128_rand.type = uint128;
    return u128_rand;
}

uint256_t BigInt_get_u256_RAND() {
    uint256_t u256_rand;
    for (uint8_t i = 0; i < uint256; i++) {
        u256_rand.array[i] = rand();     
    }
    u256_rand.type = uint256;
    return u256_rand;
}

uint512_t BigInt_get_u512_RAND() {
    uint512_t u512_rand;
    for (uint8_t i = 0; i < uint512; i++) {
        u512_rand.array[i] = rand();     
    }
    u512_rand.type = uint512;
    return u512_rand;
}

uint1024_t BigInt_get_u1024_RAND() {
    uint1024_t u1024_rand;
    for (uint8_t i = 0; i < uint1024; i++) {
        u1024_rand.array[i] = rand();     
    }
    u1024_rand.type = uint1024;
    return u1024_rand;
}

uint2048_t BigInt_get_u2048_RAND() {
    uint2048_t u2048_rand;
    for (uint8_t i = 0; i < uint2048; i++) {
        u2048_rand.array[i] = rand();     
    }
    u2048_rand.type = uint2048;
    return u2048_rand;
}


