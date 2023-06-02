
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

    char* string = "00000000000000000000011001101011100001";
    uint128_t num = BigInt.u128_from_string(string, strlen(string));
    BigInt.print(&num, num.type, true);
    println("");
    return 0;

}