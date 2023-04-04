#include "stdint.h"
#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"



#include "ByteStack.h"
#include "BigInt.h"




uint128 BigInt128(ByteStack* bytes) {
    uint128 integer = {.array = {0}, .type = uint128t};
    ByteStack_node* node_pointer = bytes -> head;
    for (uint8_t i = 0; i < uint128t; i++) {
        integer.array[uint128t - 1 - i] = node_pointer -> value;
        node_pointer = node_pointer -> next;
    }
    return integer;
}

uint16_t BigInt128_add(uint128 * a, uint128 * b, uint128 * c) {
    uint16_t carry = 0;
    for (uint8_t i = 0; i < uint128t; i++) {
        carry = a -> array[i] + b -> array[i] + carry;
        c -> array[i] = carry;
        carry >>= 8;
    }
    return carry;
}

void print_bigint(uint128 * a) {
    for (uint8_t i = 0; i < a -> type; i++) {
        printf("%02x", a -> array[uint128t - 1 - i]);
    }
    printf("\n");
}