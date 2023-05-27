
#include <stdio.h>
#include <string.h>

// large factorials: https://people.eecs.berkeley.edu/~fateman/papers/factorial.pdf

#include "BigInt.h"
#include "tests.h"
#include "utils.h"
#include "bigint_parser.h"
#include "unittest.h"


int main() {

    BigInt bigint = BigIntModule();

    // char* max = "0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff";
    // uint2048_t a = bigint.u2048_from_string(max, strlen(max));
    // uint2048_t b = bigint.u2048_from_string(max, strlen(max));
    
    // bigint.subtract(&b, &a, &a, a.type);
    // bigint.print(&a, a.type);

    uint128_t a = bigint.u128_from_string("0b1", 3);

    unittest tester = malloc_UnitTest_Module(1);

    tester.index(&tester, "start: ");
    BigInt128_left_shift(&a, 31, &a);
    tester.index(&tester, "end: ");
    bigint.print(&a, a.type);
    return 0;

}