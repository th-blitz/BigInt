
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

// large factorials: https://people.eecs.berkeley.edu/~fateman/papers/factorial.pdf

#include "BigInt.h"
#include "tests.h"
#include "utils.h"
#include "bigint_parser.h"
#include "unittest.h"
#include "BigInt_c.h"



int main() {
    
    BigInt bigint = BigIntModule();

    srand(223);

    uint2048_t a = u2048_rand();
    printlnint(rand());
    bigint.println(&a, a.type, base_10);


    return 0;

}