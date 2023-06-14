
#include <stdio.h>
#include <string.h>
#include <stdint.h>

// large factorials: https://people.eecs.berkeley.edu/~fateman/papers/factorial.pdf

#include "BigInt.h"
#include "tests.h"
#include "utils.h"
#include "bigint_parser.h"
#include "unittest.h"
#include "BigInt_c.h"
    


int main() {
    
    BigInt bigint = BigIntModule();

    uint2048_t a = u2048_MAX;
    uint128_t b = bigint.u128_from_string("340282366920938463463374607431768211455", 39);



    return 0;

}