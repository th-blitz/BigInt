#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// #include "ByteStack.h"
#include "BigInt.h"
#include "ByteQueue.h"
#include "bigint_parser.h"
#include "utils.h"


#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)


static int is_bigendian() {
    int i = 1;
    return *(char*)&i; // if returns 1 (big endian) else 0 (little endian).
}

static uint32_t word_mask[] = {
    0xf, 0xf0, 0xf00, 0xf000, 0xf0000, 0xf00000, 0xf000000, 0xf0000000
};

BigInt BigIntModule();

uint128_t BigInt128();
uint256_t BigInt256();
uint512_t BigInt512();
uint1024_t BigInt1024();
uint2048_t BigInt2048();

uint128_t BigInt128_from_bytequeue(ByteQueue* queue);
uint128_t BigInt128_from_string(char* string, uint64_t string_len);

uint256_t BigInt256_from_bytequeue(ByteQueue* queue);
uint256_t BigInt256_from_string(char* string, uint64_t string_len);

uint512_t BigInt512_from_bytequeue(ByteQueue* queue);
uint512_t BigInt512_from_string(char* string, uint64_t string_len);

uint1024_t BigInt1024_from_bytequeue(ByteQueue* queue);
uint1024_t BigInt1024_from_string(char* string, uint64_t string_len);

uint2048_t BigInt2048_from_bytequeue(ByteQueue* queue);
uint2048_t BigInt2048_from_string(char* string, uint64_t string_len);

uint32_t BigInt128_add(uint128_t* a, uint128_t* b, uint128_t* c);
uint32_t BigInt256_add(uint256_t* a, uint256_t* b, uint256_t* c);
uint32_t BigInt512_add(uint512_t* a, uint512_t* b, uint512_t* c);
uint32_t BigInt1024_add(uint1024_t* a, uint1024_t* b, uint1024_t* c);
uint32_t BigInt2048_add(uint2048_t* a, uint2048_t* b, uint2048_t* c);
uint32_t BigInt_Addition(void* a, void* b, void* c, BigIntType type);

int BigInt128_cmp(uint128_t* a, uint128_t* b);
int BigInt256_cmp(uint256_t* a, uint256_t* b);
int BigInt512_cmp(uint256_t* a, uint256_t* b);
int BigInt1024_cmp(uint1024_t* a, uint1024_t* b);
int BigInt2048_cmp(uint2048_t* a, uint2048_t* b);
int BigInt_Compare(void* a, void* b, BigIntType type);

uint32_t BigInt128_subtract(uint128_t* a, uint128_t* b, uint128_t* c);
uint32_t BigInt256_subtract(uint256_t* a, uint256_t* b, uint256_t* c);
uint32_t BigInt512_subtract(uint512_t* a, uint512_t* b, uint512_t* c);
uint32_t BigInt1024_subtract(uint1024_t* a, uint1024_t* b, uint1024_t* c);
uint32_t BigInt2048_subtract(uint2048_t* a, uint2048_t* b, uint2048_t* c);
uint32_t BigInt_Subtract(void* a, void* b, void* c, BigIntType type);

uint32_t BigInt128_multiplication_by_N(uint128_t* a, uint64_t n, uint128_t* b);
uint32_t BigInt256_multiplication_by_N(uint256_t* a, uint64_t n, uint256_t* b);
uint32_t BigInt512_multiplication_by_N(uint512_t* a, uint64_t n, uint512_t* b);
uint32_t BigInt1024_multiplication_by_N(uint1024_t* a, uint64_t n, uint1024_t* b);
uint32_t BigInt2048_multiplication_by_N(uint2048_t* a, uint64_t n, uint2048_t* b);
uint32_t BigInt_Multiply_by_N(void* a, uint32_t N, void* b, BigIntType type);

uint32_t BigInt128_add_by_N(uint128_t* a, uint64_t carry, uint128_t* b);
uint32_t BigInt256_add_by_N(uint256_t* a, uint64_t carry, uint256_t* b);
uint32_t BigInt512_add_by_N(uint512_t* a, uint64_t carry, uint512_t* b);
uint32_t BigInt1024_add_by_N(uint1024_t* a, uint64_t carry, uint1024_t* b);
uint32_t BigInt2048_add_by_N(uint2048_t* a, uint64_t carry, uint2048_t* b);
uint32_t BigInt_Add_by_N(void* a, uint32_t N, void* b, BigIntType type);

void BigInt128_mulitplication(uint128_t* a, uint128_t* b, uint256_t* c);
void BigInt256_mulitplication(uint256_t* a, uint256_t* b, uint512_t* c);
void BigInt512_mulitplication(uint512_t* a, uint512_t* b, uint1024_t* c);
void BigInt1024_mulitplication(uint1024_t* a, uint1024_t* b, uint2048_t* c);
void BigInt_Multiplication(void* a, void* b, void* c, BigIntType type);

void print_bigint(void* a, BigIntType type);
void BigInt_to_string(void* a, BigIntType type, char* string);


BigInt BigIntModule() {
    
    BigInt opp;
    
    opp.u128 = BigInt128;
    opp.u256 = BigInt256;
    opp.u512 = BigInt512;
    opp.u1024 = BigInt1024;
    opp.u2048 = BigInt2048;

    opp.u128_from_string = BigInt128_from_string;
    opp.u256_from_string = BigInt256_from_string;
    opp.u512_from_string = BigInt512_from_string;
    opp.u1024_from_string = BigInt1024_from_string;
    opp.u2048_from_string = BigInt2048_from_string;
    
    opp.add = BigInt_Addition;
    opp.compare = BigInt_Compare;

    opp.print = print_bigint;
    opp.to_string = BigInt_to_string;
    opp.multiply_by_n = BigInt_Multiply_by_N;
    opp.subtract = BigInt_Subtract;
    opp.multiply = BigInt_Multiplication;
    opp.add_by_n = BigInt_Add_by_N;
    
    return opp;
}



uint128_t BigInt128() {
    uint128_t type = {.array = {0}, .type = uint128, .len = 1};
    return type;
}

uint256_t BigInt256() {
    uint256_t type = {.array = {0}, .type = uint256, .len = 1};
    return type;
}

uint512_t BigInt512() {
    uint512_t type = {.array = {0}, .type = uint512, .len = 1};
    return type;
}

uint1024_t BigInt1024() {
    uint1024_t type = {.array = {0}, .type = uint1024, .len = 1};
    return type;
}

uint2048_t BigInt2048() {
    uint2048_t type = {.array = {0}, .type = uint2048, .len = 1};
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
    integer.len = (i == 0) ? 1: i;
    return integer;
}

uint128_t BigInt128_from_string(char* string, uint64_t string_len) {
    ByteQueue queue = one_time_string_to_bytequeue(string, string_len);
    uint128_t integer = BigInt128_from_bytequeue(&queue);
    queue.free(&queue);
    return integer;
}

uint256_t BigInt256_from_bytequeue(ByteQueue* queue) {
    uint256_t integer = BigInt256();
    ByteQueue_node* node_pointer = queue -> right;
    uint32_t word;

    uint8_t iters = MIN(uint256 * 4, queue -> size);
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
    integer.len = (i == 0) ? 1: i;
    return integer;
}

uint256_t BigInt256_from_string(char* string, uint64_t string_len) {
    ByteQueue queue = one_time_string_to_bytequeue(string, string_len);
    uint256_t integer = BigInt256_from_bytequeue(&queue);
    queue.free(&queue);
    return integer;
}

uint512_t BigInt512_from_bytequeue(ByteQueue* queue) {
    uint512_t integer = BigInt512();
    ByteQueue_node* node_pointer = queue -> right;
    uint32_t word;

    uint8_t iters = MIN(uint512 * 4, queue -> size);
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
    integer.len = (i == 0) ? 1: i;
    return integer;
}

uint512_t BigInt512_from_string(char* string, uint64_t string_len) {
    ByteQueue queue = one_time_string_to_bytequeue(string, string_len);
    uint512_t integer = BigInt512_from_bytequeue(&queue);
    queue.free(&queue);
    return integer;
}


uint1024_t BigInt1024_from_bytequeue(ByteQueue* queue) {
    uint1024_t integer = BigInt1024();
    ByteQueue_node* node_pointer = queue -> right;
    uint32_t word;

    uint32_t iters = MIN(uint1024 * 4, queue -> size);
    uint32_t j = 0;
    uint32_t k = 0;
    uint32_t i = 0;

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
    integer.len = (i == 0) ? 1: i;
    return integer;
}

uint1024_t BigInt1024_from_string(char* string, uint64_t string_len) {
    ByteQueue queue = one_time_string_to_bytequeue(string, string_len);
    uint1024_t integer = BigInt1024_from_bytequeue(&queue);
    queue.free(&queue);
    return integer;
}


uint2048_t BigInt2048_from_bytequeue(ByteQueue* queue) {
    uint2048_t integer = BigInt2048();
    ByteQueue_node* node_pointer = queue -> right;
    uint32_t word;

    uint32_t iters = MIN(uint2048 * 4, queue -> size);
    uint32_t j = 0;
    uint32_t k = 0;
    uint32_t i = 0;
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
    integer.len = (i == 0) ? 1: i;
    return integer;
}

uint2048_t BigInt2048_from_string(char* string, uint64_t string_len) {
    ByteQueue queue = one_time_string_to_bytequeue(string, string_len);
    uint2048_t integer = BigInt2048_from_bytequeue(&queue);
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


uint32_t BigInt_Addition(void* a, void* b, void* c, BigIntType type) {
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
            printlnc("BigInt type error; at BigInt.c/BigInt_Addition()", red);
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

int BigInt256_cmp(uint256_t* a, uint256_t* b) {
    for (uint32_t i = uint256; i > 0; i--) {
        if ((a -> array[i - 1]) > (b -> array[i - 1])) {
            return 1;
        } else if ((a -> array[i - 1]) < (b -> array[i - 1])) {
            return -1;
        }
    }
    return 0;
}

int BigInt512_cmp(uint256_t* a, uint256_t* b) {
    for (uint32_t i = uint512; i > 0; i--) {
        if ((a -> array[i - 1]) > (b -> array[i - 1])) {
            return 1;
        } else if ((a -> array[i - 1]) < (b -> array[i - 1])) {
            return -1;
        }
    }
    return 0;
}

int BigInt1024_cmp(uint1024_t* a, uint1024_t* b) {
    for (uint32_t i = uint1024; i > 0; i--) {
        if ((a -> array[i - 1]) > (b -> array[i - 1])) {
            return 1;
        } else if ((a -> array[i - 1]) < (b -> array[i - 1])) {
            return -1;
        }
    }
    return 0;
}

int BigInt2048_cmp(uint2048_t* a, uint2048_t* b) {
    for (uint32_t i = uint2048; i > 0; i--) {
        if ((a -> array[i - 1]) > (b -> array[i - 1])) {
            return 1;
        } else if ((a -> array[i - 1]) < (b -> array[i - 1])) {
            return -1;
        }
    }
    return 0;
}

int BigInt_Compare(void* a, void* b, BigIntType type) {
    int cmp = 9;
    switch (type) {
        case uint128:
            cmp = BigInt128_cmp(a, b);
            break;
        case uint256:
            cmp = BigInt256_cmp(a, b);
            break;
        case uint512:
            cmp = BigInt512_cmp(a, b);
            break;
        case uint1024:
            cmp = BigInt1024_cmp(a, b);
            break;
        case uint2048:
            cmp = BigInt2048_cmp(a, b);
            break;
        default:
            printlnc("BigInt type error: at BigInt.c/BigInt_Compare()", red);
            break;
    }
    return cmp;
}

uint32_t BigInt128_subtract(uint128_t* a, uint128_t* b, uint128_t* c) {
    uint64_t borrow = 0;
    uint64_t borrow_mask = 0x100000000;
    uint64_t aa;
    uint64_t bb;
    uint8_t i, leading_zeros;
    uint8_t steps = MAX(a -> len, b -> len);
    for (i = 0; i < steps || (borrow != 0 && i < uint128); i++) {
        aa = (uint64_t)(a -> array[i]); 
        bb = (uint64_t)(b -> array[i]);
        
        (borrow == 1) ? ((aa > 0) ? (aa -= 1, borrow -= 1) : (aa = 0xffffffff)): 0; 

        if (aa >= bb) {
            c -> array[i] = (uint32_t)(aa - bb);
        } else {
            c -> array[i] = (uint32_t)((aa | borrow_mask) - bb);
            borrow += 1;
        }
        (c -> array[i] == 0) ? (leading_zeros += 1): (leading_zeros = 0);
    }
    c -> len = (uint128 - leading_zeros) > 0 ? (uint128 - leading_zeros) : 1;
    return (uint32_t)borrow;
}

uint32_t BigInt256_subtract(uint256_t* a, uint256_t* b, uint256_t* c) {
    uint64_t borrow = 0;
    uint64_t borrow_mask = 0x100000000;
    uint64_t aa;
    uint64_t bb;
    uint8_t i, leading_zeros;
    uint8_t steps = MAX(a -> len, b -> len);
    for (i = 0; i < steps || (borrow != 0 && i < uint256); i++) {
        aa = (uint64_t)(a -> array[i]); 
        bb = (uint64_t)(b -> array[i]);
        
        (borrow == 1) ? ((aa > 0) ? (aa -= 1, borrow -= 1) : (aa = 0xffffffff)): 0; 

        if (aa >= bb) {
            c -> array[i] = (uint32_t)(aa - bb);
        } else {
            c -> array[i] = (uint32_t)((aa | borrow_mask) - bb);
            borrow += 1;
        }
        (c -> array[i] == 0) ? (leading_zeros += 1): (leading_zeros = 0);
    }
    c -> len = (uint256 - leading_zeros) > 0 ? (uint256 - leading_zeros) : 1;
    return (uint32_t)borrow;
}

uint32_t BigInt512_subtract(uint512_t* a, uint512_t* b, uint512_t* c) {
    uint64_t borrow = 0;
    uint64_t borrow_mask = 0x100000000;
    uint64_t aa;
    uint64_t bb;
    uint8_t i, leading_zeros;
    uint8_t steps = MAX(a -> len, b -> len);
    for (i = 0; i < steps || (borrow != 0 && i < uint512); i++) {
        aa = (uint64_t)(a -> array[i]); 
        bb = (uint64_t)(b -> array[i]);
        
        (borrow == 1) ? ((aa > 0) ? (aa -= 1, borrow -= 1) : (aa = 0xffffffff)): 0; 

        if (aa >= bb) {
            c -> array[i] = (uint32_t)(aa - bb);
        } else {
            c -> array[i] = (uint32_t)((aa | borrow_mask) - bb);
            borrow += 1;
        }
        (c -> array[i] == 0) ? (leading_zeros += 1): (leading_zeros = 0);
    }
    c -> len = (uint512 - leading_zeros) > 0 ? (uint512 - leading_zeros) : 1;
    return (uint32_t)borrow;
}

uint32_t BigInt1024_subtract(uint1024_t* a, uint1024_t* b, uint1024_t* c) {
    uint64_t borrow = 0;
    uint64_t borrow_mask = 0x100000000;
    uint64_t aa;
    uint64_t bb;
    uint8_t i, leading_zeros;
    uint8_t steps = MAX(a -> len, b -> len);
    for (i = 0; i < steps || (borrow != 0 && i < uint1024); i++) {
        aa = (uint64_t)(a -> array[i]); 
        bb = (uint64_t)(b -> array[i]);
        
        (borrow == 1) ? ((aa > 0) ? (aa -= 1, borrow -= 1) : (aa = 0xffffffff)): 0; 

        if (aa >= bb) {
            c -> array[i] = (uint32_t)(aa - bb);
        } else {
            c -> array[i] = (uint32_t)((aa | borrow_mask) - bb);
            borrow += 1;
        }
        (c -> array[i] == 0) ? (leading_zeros += 1): (leading_zeros = 0);
    }
    c -> len = (uint1024 - leading_zeros) > 0 ? (uint1024 - leading_zeros) : 1;
    return (uint32_t)borrow;
}

uint32_t BigInt2048_subtract(uint2048_t* a, uint2048_t* b, uint2048_t* c) {
    uint64_t borrow = 0;
    uint64_t borrow_mask = 0x100000000;
    uint64_t aa;
    uint64_t bb;
    uint8_t i, leading_zeros;
    uint8_t steps = MAX(a -> len, b -> len);
    for (i = 0; i < steps || (borrow != 0 && i < uint2048); i++) {
        aa = (uint64_t)(a -> array[i]); 
        bb = (uint64_t)(b -> array[i]);
        
        (borrow == 1) ? ((aa > 0) ? (aa -= 1, borrow -= 1) : (aa = 0xffffffff)): 0; 

        if (aa >= bb) {
            c -> array[i] = (uint32_t)(aa - bb);
        } else {
            c -> array[i] = (uint32_t)((aa | borrow_mask) - bb);
            borrow += 1;
        }
        (c -> array[i] == 0) ? (leading_zeros += 1): (leading_zeros = 0);
    }
    c -> len = (uint2048 - leading_zeros) > 0 ? (uint2048 - leading_zeros) : 1;
    return (uint32_t)borrow;
}

uint32_t BigInt_Subtract(void* a, void* b, void* c, BigIntType type) {
    uint32_t borrow = 0;
    switch (type) {
        case uint128:
            borrow = BigInt128_subtract((uint128_t*)a, (uint128_t*)b, (uint128_t*)c);
            break;
        case uint256:
            borrow = BigInt256_subtract((uint256_t*)a, (uint256_t*)b, (uint256_t*)c);
            break;
        case uint512:
            borrow = BigInt512_subtract((uint512_t*)a, (uint512_t*)b, (uint512_t*)c);
            break;
        case uint1024:
            borrow = BigInt1024_subtract((uint1024_t*)a, (uint1024_t*)b, (uint1024_t*)c);
            break;
        case uint2048:
            borrow = BigInt2048_subtract((uint2048_t*)a, (uint2048_t*)b, (uint2048_t*)c);
            break;
        default:
            printlnc("err: BigInt type error: at BigInt.c/BigInt_Subtract()", red);
    }

    return borrow;
}

uint32_t BigInt128_multiplication_by_N(uint128_t* a, uint64_t n, uint128_t* b) {
    uint64_t carry = 0;
    uint8_t i;
    for (uint8_t i = 0; (i < a -> len) || (carry != 0 && i < uint128); i++) {
        carry = ((uint64_t)(a -> array[i]) * n) + carry;
        b -> array[i] = (uint32_t)carry;
        carry >>= 32;
    }
    (n > 0) ? (b -> len = i): (b -> len = 1);
    return (uint32_t)carry;
}

uint32_t BigInt256_multiplication_by_N(uint256_t* a, uint64_t n, uint256_t* b) {
    uint64_t carry = 0;
    uint8_t i;
    for (uint8_t i = 0; (i < a -> len) || (carry != 0 && i < uint256); i++) {
        carry = ((uint64_t)(a -> array[i]) * n) + carry;
        b -> array[i] = (uint32_t)carry;
        carry >>= 32;
    }
    (n > 0) ? (b -> len = i): (b -> len = 1);
    return (uint32_t)carry;
}

uint32_t BigInt512_multiplication_by_N(uint512_t* a, uint64_t n, uint512_t* b) {
    uint64_t carry = 0;
    uint8_t i;
    for (i = 0; (i < a -> len) || (carry != 0 && i < uint512); i++) {
        carry = ((uint64_t)(a -> array[i]) * n) + carry;
        b -> array[i] = (uint32_t)carry;
        carry >>= 32;
    }
    (n > 0) ? (b -> len = i): (b -> len = 1);
    return (uint32_t)carry;
}

uint32_t BigInt1024_multiplication_by_N(uint1024_t* a, uint64_t n, uint1024_t* b) {
    uint64_t carry = 0;
    uint8_t i;
    for (i = 0; (i < a -> len) || (carry != 0 && i < uint1024); i++) {
        carry = ((uint64_t)(a -> array[i]) * n) + carry;
        b -> array[i] = (uint32_t)carry;
        carry >>= 32;
    }
    (n > 0) ? (b -> len = i): (b -> len = 1);
    return (uint32_t)carry;
}

uint32_t BigInt2048_multiplication_by_N(uint2048_t* a, uint64_t n, uint2048_t* b) {
    uint64_t carry = 0;
    uint8_t i;
    for (i = 0; (i < a -> len) || (carry != 0 && i < uint2048); i++) {
        carry = ((uint64_t)(a -> array[i]) * n) + carry;
        b -> array[i] = (uint32_t)carry;
        carry >>= 32;
    }
    (n > 0) ? (b -> len = i): (b -> len = 1);
    return (uint32_t)carry;
}

uint32_t BigInt_Multiply_by_N(void* a, uint32_t N, void* b, BigIntType type) {
    uint64_t carry = (uint64_t)N;
    switch (type) {
        case uint128:
            carry = BigInt128_multiplication_by_N( (uint128_t*)a, carry, (uint128_t*)b);
            break;
        case uint256:
            carry = BigInt256_multiplication_by_N( (uint256_t*)a, carry, (uint256_t*)b);
            break;
        case uint512:
            carry = BigInt512_multiplication_by_N( (uint512_t*)a, carry, (uint512_t*)b);
            break;
        case uint1024:
            carry = BigInt1024_multiplication_by_N( (uint1024_t*)a, carry, (uint1024_t*)b);
            break;
        case uint2048:
            carry = BigInt2048_multiplication_by_N( (uint2048_t*)a, carry, (uint2048_t*)b);
            break;
        default:
            printlnc("err: BigInt type error: at BigInt.c/BigInt_Multiply_by_N()", red);
    }

    return carry;
}

uint32_t BigInt128_add_by_N(uint128_t* a, uint64_t carry, uint128_t* b) {
    
    for (uint8_t i = 0; (i < uint128) && (carry > 0); i++) {
        carry += (uint64_t)(a -> array[i]);
        b -> array[i] = (uint32_t)carry;
        carry >>= 32;
    }
    return (uint32_t)carry;
}

uint32_t BigInt256_add_by_N(uint256_t* a, uint64_t carry, uint256_t* b) {
    
    for (uint8_t i = 0; (i < uint256) && (carry > 0); i++) {
        carry += (uint64_t)(a -> array[i]);
        b -> array[i] = (uint32_t)carry;
        carry >>= 32;
    }
    return (uint32_t)carry;
}

uint32_t BigInt512_add_by_N(uint512_t* a, uint64_t carry, uint512_t* b) {
    
    for (uint8_t i = 0; (i < uint512) && (carry > 0); i++) {
        carry += (uint64_t)(a -> array[i]);
        b -> array[i] = (uint32_t)carry;
        carry >>= 32;
    }
    return (uint32_t)carry;
}

uint32_t BigInt1024_add_by_N(uint1024_t* a, uint64_t carry, uint1024_t* b) {
    
    for (uint8_t i = 0; (i < uint1024) && (carry > 0); i++) {
        carry += (uint64_t)(a -> array[i]);
        b -> array[i] = (uint32_t)carry;
        carry >>= 32;
    }
    return (uint32_t)carry;
}

uint32_t BigInt2048_add_by_N(uint2048_t* a, uint64_t carry, uint2048_t* b) {
    
    for (uint8_t i = 0; (i < uint2048) && (carry > 0); i++) {
        carry += (uint64_t)(a -> array[i]);
        b -> array[i] = (uint32_t)carry;
        carry >>= 32;
    }
    return (uint32_t)carry;
}

uint32_t BigInt_Add_by_N(void* a, uint32_t N, void* b, BigIntType type) {
    uint64_t carry = (uint64_t)N;
    switch (type) {
        case uint128:
            carry = BigInt128_add_by_N( (uint128_t*)a, carry, (uint128_t*)b);
            break;
        case uint256:
            carry = BigInt256_add_by_N( (uint256_t*)a, carry, (uint256_t*)b);
            break;
        case uint512:
            carry = BigInt512_add_by_N( (uint512_t*)a, carry, (uint512_t*)b);
            break;
        case uint1024:
            carry = BigInt1024_add_by_N( (uint1024_t*)a, carry, (uint1024_t*)b);
            break;
        case uint2048:
            carry = BigInt2048_add_by_N( (uint2048_t*)a, carry, (uint2048_t*)b);
            break;
        default:
            printlnc("err: BigInt type error: at BigInt.c/BigInt_Add_by_N()", red);
    }

    return carry;
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

void BigInt256_mulitplication(uint256_t* a, uint256_t* b, uint512_t* c) {
    
    uint64_t carry = 0;
    uint64_t carries[uint512] = {0};
    uint64_t aa;
    uint64_t bb;

    for (uint32_t i = 0; i < uint256; i++) {
        for (uint32_t j = 0; j < uint256; j++) {
            aa = (uint64_t)(a -> array[i]);
            bb = (uint64_t)(b -> array[j]);
            carry = carries[i + j];
            carry = (aa * bb) + carry;
            carries[i + j] = (carry & 0x00000000ffffffff);
            carries[i + j + 1] += (carry >> 32);
        }
    }

    for (uint8_t i = 0; i < uint512; i++) {
        c -> array[i] = (uint32_t)carries[i];
    }
}

void BigInt512_mulitplication(uint512_t* a, uint512_t* b, uint1024_t* c) {
    
    uint64_t carry = 0;
    uint64_t carries[uint1024] = {0};
    uint64_t aa;
    uint64_t bb;

    for (uint32_t i = 0; i < uint512; i++) {
        for (uint32_t j = 0; j < uint512; j++) {
            aa = (uint64_t)(a -> array[i]);
            bb = (uint64_t)(b -> array[j]);
            carry = carries[i + j];
            carry = (aa * bb) + carry;
            carries[i + j] = (carry & 0x00000000ffffffff);
            carries[i + j + 1] += (carry >> 32);
        }
    }

    for (uint8_t i = 0; i < uint1024; i++) {
        c -> array[i] = (uint32_t)carries[i];
    }
}

void BigInt1024_mulitplication(uint1024_t* a, uint1024_t* b, uint2048_t* c) {
    
    uint64_t carry = 0;
    uint64_t carries[uint2048] = {0};
    uint64_t aa;
    uint64_t bb;

    for (uint32_t i = 0; i < uint1024; i++) {
        for (uint32_t j = 0; j < uint1024; j++) {
            aa = (uint64_t)(a -> array[i]);
            bb = (uint64_t)(b -> array[j]);
            carry = carries[i + j];
            carry = (aa * bb) + carry;
            carries[i + j] = (carry & 0x00000000ffffffff);
            carries[i + j + 1] += (carry >> 32);
        }
    }

    for (uint8_t i = 0; i < uint2048; i++) {
        c -> array[i] = (uint32_t)carries[i];
    }
}

void BigInt_Multiplication(void* a, void* b, void* c, BigIntType type) {
    
    switch (type) {
        case uint128:
            BigInt128_mulitplication((uint128_t*) a, (uint128_t*) b, (uint256_t*) c);
            break;
        case uint256:
            BigInt256_mulitplication((uint256_t*) a, (uint256_t*) b, (uint512_t*) c);
            break;
        case uint512:
            BigInt512_mulitplication((uint512_t*) a, (uint512_t*) b, (uint1024_t*) c);
            break;
        case uint1024:
            BigInt1024_mulitplication((uint1024_t*) a, (uint1024_t*) b, (uint2048_t*) c);
            break;
        default:
            printlnc("err: BigInt type error: at BigInt.c/BigInt_Multiplication()", red);
    }
}



void print_bigint(void* a, BigIntType type) {
    bool leading_zeros_flag = true;
    switch (type) {
        case uint128:
            for (uint8_t i = type; i > 0; i--) {
                if ((leading_zeros_flag == true) && ((((uint128_t*)a) -> array[i - 1]) != 0)) {
                    leading_zeros_flag = false;
                } 
                if ((i - 1 == 0) || (leading_zeros_flag == false)) {
                    printf("%08x", ((uint128_t*)a) -> array[i - 1]);
                }
            }
            break;
        case uint256:
            for (uint8_t i = type; i > 0; i--) {
                if ((leading_zeros_flag == true) && ((((uint256_t*)a) -> array[i - 1]) != 0)) {
                    leading_zeros_flag = false;
                } 
                if ((i - 1 == 0) || (leading_zeros_flag == false)) {
                    printf("%08x", ((uint256_t*)a) -> array[i - 1]);
                }
            }
            break;
        case uint512:
            for (uint8_t i = type; i > 0; i--) {
                if ((leading_zeros_flag == true) && ((((uint512_t*)a) -> array[i - 1]) != 0)) {
                    leading_zeros_flag = false;
                } 
                if ((i - 1 == 0) || (leading_zeros_flag == false)) {
                    printf("%08x", ((uint512_t*)a) -> array[i - 1]);
                }
            }
            break;
        case uint1024:
            for (uint8_t i = type; i > 0; i--) {
                if ((leading_zeros_flag == true) && ((((uint1024_t*)a) -> array[i - 1]) != 0)) {
                    leading_zeros_flag = false;
                } 
                if ((i - 1 == 0) || (leading_zeros_flag == false)) {
                    printf("%08x", ((uint1024_t*)a) -> array[i - 1]);
                }
            }
            break;
        case uint2048:
            for (uint8_t i = type; i > 0; i--) {
                if ((leading_zeros_flag == true) && ((((uint2048_t*)a) -> array[i - 1]) != 0)) {
                    leading_zeros_flag = false;
                } 
                if ((i - 1 == 0) || (leading_zeros_flag == false)) {
                    printf("%08x", ((uint2048_t*)a) -> array[i - 1]);
                }
            }
            break;
        default:
            printf("err: at BigInt.c/print_bigint(): none type received\n");
            break;
    }
    printf("\n");
}

void BigInt_to_string(void* a, BigIntType type, char* string) {
    
    char* hex_to_char = "0123456789abcdef";

    uint32_t i = 0;
    uint8_t index = 0;
    uint32_t idx;
    
    switch (type) {
        case uint128:
            idx = (uint32_t)(uint128 * 8);
            string[idx] = '\0';
            while (i < idx) {
                index = ((((uint128_t*)a) -> array[i / 8]) & word_mask[i % 8]) >> ((i % 8) * 4); 
                string[idx - i - 1] = hex_to_char[index]; 
                i += 1;       
            }
            break;
        case uint256:
            idx = (uint32_t)(uint256 * 8);
            string[idx] = '\0';
            while (i < idx) {
                index = ((((uint256_t*)a) -> array[i / 8]) & word_mask[i % 8]) >> ((i % 8) * 4); 
                string[idx - i - 1] = hex_to_char[index]; 
                i += 1;  
            }
            break;
        case uint512:
            idx = (uint32_t)(uint512 * 8);
            string[idx] = '\0';
            while (i < idx) {
                index = ((((uint512_t*)a) -> array[i / 8]) & word_mask[i % 8]) >> ((i % 8) * 4); 
                string[idx - i - 1] = hex_to_char[index];  
                i += 1;      
            }
            break;
        case uint1024:
            idx = (uint32_t)(uint1024 * 8);
            string[idx] = '\0';
            while (i < idx) {
                index = ((((uint1024_t*)a) -> array[i / 8]) & word_mask[i % 8]) >> ((i % 8) * 4); 
                string[idx - i - 1] = hex_to_char[index]; 
                i += 1;       
            }
            break;
        case uint2048:
            idx = (uint32_t)(uint2048 * 8);
            string[idx] = '\0';
            while (i < idx) {
                index = ((((uint2048_t*)a) -> array[i / 8]) & word_mask[i % 8]) >> ((i % 8) * 4); 
                string[idx - i - 1] = hex_to_char[index]; 
                i += 1;       
            }
            break;
        default:
            printlnc("err: at BigInt.c/BigInt_to_string(): none type received", red);
            break;
    }
}




// void print_bigint(uint128_t* a) {
//     for (uint8_t i = a -> type; i > 0; i--) {
//         printf("%08x", a -> array[i - 1]);
//     }
//     printf("\n");
// }