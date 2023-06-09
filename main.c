
#include <stdio.h>
#include <string.h>
#include <stdint.h>

// large factorials: https://people.eecs.berkeley.edu/~fateman/papers/factorial.pdf

#include "BigInt.h"
#include "tests.h"
#include "utils.h"
#include "bigint_parser.h"
#include "unittest.h"



int main() {
    
    BigInt BigInt = BigIntModule();
    char* string = "0x78978327423abccc";

    uint128_t a = BigInt.u128_from_string(string, strlen(string));
    
    BigInt.println(&a, a.type, base_16);

    return 0;

}