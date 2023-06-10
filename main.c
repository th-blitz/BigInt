
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
    
    BigInt bigint = BigIntModule();

    uint2048_t a = bigint.u2048_from_string("1", 1);
    uint32_t n = 300;
    while (n > 1) {
        bigint.multiply_by_n(&a, n, &a, a.type);
        n -= 1;
    }

    bigint.println(&a, a.type, base_10);

    return 0;

}