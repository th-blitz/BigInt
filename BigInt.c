#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// #include "ByteStack.h"
#include "BigInt.h"
#include "ByteQueue.h"
#include "bigint_parser.h"


#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)


static int is_bigendian() {
    int i = 1;
    return *(char*)&i; // if returns 1 (big endian) else 0 (little endian).
}



static uint32_t word_mask[4] = {
    0xff, 0xff00, 0xff0000, 0xff000000,
};




uint128_t BigInt128() {
    uint128_t type = {.array = {0}, .type = uint128};
    return type;
}

uint256_t BigInt256() {
    uint256_t type = {.array = {0}, .type = uint256};
    return type;
}

uint512_t BigInt512() {
    uint512_t type = {.array = {0}, .type = uint512};
    return type;
}

uint1024_t BigInt1024() {
    uint1024_t type = {.array = {0}, .type = uint1024};
    return type;
}

uint2048_t BigInt2048() {
    uint2048_t type = {.array = {0}, .type = uint2048};
    return type;
}


uint128_t BigInt128_from_bytequeue(ByteQueue* queue) {
    uint128_t integer = BigInt128();
    ByteQueue_node* node_pointer = queue -> right;
    uint32_t word;

    uint8_t iters = MIN(uint128 * 4, queue -> size);
    uint8_t j = 0;
    uint8_t k = 0;
    uint8_t i = 0;
    while (k < iters) {
        word = 0;
        j = 0;
        while ((k < iters) && (j < 4)) {
            word |= (uint32_t)(node_pointer -> value) << (j * 8);
            node_pointer = node_pointer -> left;
            j += 1;
            k += 1;
        }
        integer.array[i] = word;
        i += 1;
    }
    return integer;
}

uint128_t BigInt128_from_string(char* string, uint64_t string_len) {
    ByteQueue queue = one_time_string_to_bytequeue(string, string_len);
    uint128_t integer = BigInt128_from_bytequeue(&queue);
    queue.free(&queue);
    return integer;
}




// uint128_t BigInt128_from_bytes(ByteStack* bytes) {
//     uint128_t integer = {.array = {0}, .type = uint128};
//     ByteStack_node* node_pointer = bytes -> head;
//     uint32_t word;
//     for (uint8_t i = uint128; i > 0; i--) {
//         word = 0;
//         for (uint8_t j = 0; j < 4; j++) {
//             word <<= 8;
//             word |= (uint32_t)(node_pointer -> value);
//             node_pointer = node_pointer -> next;
//         }
//         integer.array[i - 1] = word;
//     }
//     return integer;
// }

uint32_t BigInt128_add(uint128_t* a, uint128_t* b, uint128_t* c) {
    uint64_t carry = 0;
    for (uint8_t i = 0; i < uint128; i++) {
        carry = (uint64_t)(a -> array[i]) + (uint64_t)(b -> array[i]) + carry;
        c -> array[i] = (uint32_t)carry;
        carry >>= 32;
    }
    return (uint32_t)carry;
}

uint32_t BigInt256_add(uint256_t* a, uint256_t* b, uint256_t* c) {
    uint64_t carry = 0;
    for (uint8_t i = 0; i < uint256; i++) {
        carry = (uint64_t)(a -> array[i]) + (uint64_t)(b -> array[i]) + carry;
        c -> array[i] = (uint32_t)carry;
        carry >>= 32;
    }
    return (uint32_t)carry;
}

uint32_t BigInt512_add(uint512_t* a, uint512_t* b, uint512_t* c) {
    uint64_t carry = 0;
    for (uint8_t i = 0; i < uint512; i++) {
        carry = (uint64_t)(a -> array[i]) + (uint64_t)(b -> array[i]) + carry;
        c -> array[i] = (uint32_t)carry;
        carry >>= 32;
    }
    return (uint32_t)carry;
}

uint32_t BigInt1024_add(uint1024_t* a, uint1024_t* b, uint1024_t* c) {
    uint64_t carry = 0;
    for (uint8_t i = 0; i < uint1024; i++) {
        carry = (uint64_t)(a -> array[i]) + (uint64_t)(b -> array[i]) + carry;
        c -> array[i] = (uint32_t)carry;
        carry >>= 32;
    }
    return (uint32_t)carry;
}

uint32_t BigInt2048_add(uint2048_t* a, uint2048_t* b, uint2048_t* c) {
    uint64_t carry = 0;
    for (uint8_t i = 0; i < uint2048; i++) {
        carry = (uint64_t)(a -> array[i]) + (uint64_t)(b -> array[i]) + carry;
        c -> array[i] = (uint32_t)carry;
        carry >>= 32;
    }
    return (uint32_t)carry;
}


uint32_t BigInt128_Addition(void* a, void* b, void* c, BigIntType type) {
    uint32_t carry = 0;
    switch (type) {
        case uint128:
            carry = BigInt128_add(a, b, c);
            break;
        case uint256:
            carry = BigInt256_add(a, b, c);
            break;
        case uint512:
            carry = BigInt512_add(a, b, c);
            break;
        case uint1024:
            carry = BigInt1024_add(a, b, c);
            break;
        case uint2048:
            carry = BigInt2048_add(a, b, c);
            break;
        default:
            break;
    }
    return carry;
}


int BigInt128_cmp(uint128_t* a, uint128_t* b) {
    for (uint32_t i = uint128; i > 0; i--) {
        if ((a -> array[i - 1]) > (b -> array[i - 1])) {
            return 1;
        } else if ((a -> array[i - 1]) < (b -> array[i - 1])) {
            return -1;
        }
    }
    return 0;
}

uint32_t BigInt128_subtract(uint128_t* a, uint128_t* b, uint128_t* c) {
    uint64_t borrow = 0;
    uint64_t borrow_mask = 1;
    borrow_mask <<= 32;
    uint64_t aa = 0;
    uint64_t bb = 0;
    for (uint8_t i = 0; i < uint128; i++) {
        aa = (uint64_t)(a -> array[i]);
        bb = (uint64_t)(b -> array[i]);
        if (aa >= borrow) {
            aa -= borrow;
            borrow = 0;
        } else {
            borrow -= aa;
            aa = 0;
        }

        if (aa >= bb) {
            c -> array[i] = (uint32_t)(aa - bb);
        } else {
            c -> array[i] = (uint32_t)((aa | borrow_mask) - bb);
            borrow += 1;
        }
    }
    return (uint32_t)borrow;
}

uint32_t BigInt128_multiplication_by_base_2_pow_32(uint128_t* a, uint32_t N, uint128_t* b) {
    uint64_t carry = 1;
    uint64_t n = (uint64_t)N;
    for (uint8_t i = 0; i < uint128; i++) {
        carry = ((uint64_t)(a -> array[i]) * n) + carry;
        b -> array[i] = (uint32_t)carry;
        carry >>= 32;
    }
    return (uint32_t)carry;
}

void BigInt128_mulitplication(uint128_t* a, uint128_t* b, uint256_t* c) {
    
    uint64_t carry = 0;
    uint64_t carries[uint256] = {0};
    uint64_t aa;
    uint64_t bb;

    for (uint32_t i = 0; i < uint128; i++) {
        for (uint32_t j = 0; j < uint128; j++) {
            aa = (uint64_t)(a -> array[i]);
            bb = (uint64_t)(b -> array[j]);
            carry = carries[i + j];
            carry = (aa * bb) + carry;
            carries[i + j] = (carry & 0x00000000ffffffff);
            carries[i + j + 1] += (carry >> 32);
        }
    }

    for (uint8_t i = 0; i < uint256; i++) {
        c -> array[i] = (uint32_t)carries[i];
    }
}

void print_bigint(void* a, BigIntType type) {
    
    switch (type) {
        case uint128:
            for (uint8_t i = type; i > 0; i--) {
                printf("%08x", ((uint128_t*)a) -> array[i - 1]);
            }
            break;
        case uint256:
            for (uint8_t i = type; i > 0; i--) {
                printf("%08x", ((uint256_t*)a) -> array[i - 1]);
            }
            break;
        default:
            printf("none type received\n");
            break;
    }
    printf("\n");
}

// void print_bigint(uint128_t* a) {
//     for (uint8_t i = a -> type; i > 0; i--) {
//         printf("%08x", a -> array[i - 1]);
//     }
//     printf("\n");
// }