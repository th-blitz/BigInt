
#include <stdio.h>
#include <string.h>

// large factorials: https://people.eecs.berkeley.edu/~fateman/papers/factorial.pdf

#include "BigInt.h"
#include "tests.h"
#include "utils.h"
#include "bigint_parser.h"


int main() {

    BigInt bigint = BigIntModule();

    char* max = "0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff";
    uint2048_t a = bigint.u2048_from_string(max, strlen(max));
    uint2048_t b = bigint.u2048_from_string(max, strlen(max));
    
    bigint.subtract(&b, &a, &a, a.type);
    bigint.print(&a, a.type);

    return 0;

}