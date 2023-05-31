
#include <stdio.h>
#include <string.h>

// large factorials: https://people.eecs.berkeley.edu/~fateman/papers/factorial.pdf

#include "BigInt.h"
#include "tests.h"
#include "utils.h"
#include "bigint_parser.h"
#include "unittest.h"


int main() {

    // (1) import the bigint module.
    BigInt bigint = BigIntModule();

    // (2) create an array of uint2048_t of size 750.
    uint2048_t a_large_num[750];

    // (3) set the least significant bit as 1 & initialize rest of the array with u2048 type.
    a_large_num[749] = bigint.u2048_from_string("01", 2);
    for (int i = 748; i > -1; i--) {
        a_large_num[i] = bigint.u2048();
    }

    // (4) N = 100,000.
    unsigned int N = 100000;
    unsigned int carry_a = 0;
    unsigned int carry_b = 0;
    unsigned int overflow = 0;

    // (5) perform [ bigint_array *= n ] for n from 1 to 100,000 ( Calculate factorial )
    while (N > 1) {
        for (int i = 749; i > -1; i--) {
            carry_b = bigint.multiply_by_n(&a_large_num[i], N, &a_large_num[i], uint2048);
            bigint.add_by_n(&a_large_num[i], carry_a, &a_large_num[i], uint2048);
            carry_a = carry_b;
        }
        N -= 1;
    }
    
    // (6) print the whole array ( result of 100,000 factorial )
    int i = 0;
    // manually truncate leading zeros.
    while (a_large_num[i].len == 1) {
        i += 1;
    }
    // truncate leading zeros in uint2048 for the first digit.
    bigint.print( &a_large_num[i], true, uint2048);
    for (i = i + 1; i < 750; i++) {
        // print rest of the digits without truncating leading zeros.
        bigint.print( &a_large_num[i], false, uint2048);
    }
    
    return 0;

}