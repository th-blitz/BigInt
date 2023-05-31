
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
    
    // An uint2048 array of length 5.
    uint2048_t a_large_num[5]; // a (5 * 2048 = 10,240) bit integer represented as 5 2048 bit int digits.
    
    a_large_num[4] = bigint.u2048_from_string("01", 2); // Initialize the least significant digit as 1.
    for (int i = 3; i > -1; i--) {
        a_large_num[i] = bigint.u2048(); // Initialize the rest of the digits as zeros.
    }

    unsigned int N = 1000;
    unsigned int carry_a = 0;
    unsigned int carry_b = 0;

    while (N > 1) {
        //                                                                                                       1223 (carry) 
        // Below is same as arithmetic multiplication using carrys for a 5 digit number as 12345 x 6 = 74070 i.e 12345 (uint2048 [5]) x 6 (N)
        //                                                                                                       74070 (Result as in uint2048 [5])
        for (int i = 4; i > -1; i--) {
            carry_b = bigint.multiply_by_n(&a_large_num[i], N, &a_large_num[i], uint2048);
            bigint.add_by_n(&a_large_num[i], carry_a, &a_large_num[i], uint2048);
            carry_a = carry_b;
        }
        if (carry_a > 0) {
            printf("overflow \n");
        }
        N -= 1;
    }
    
    // Printing in reverse from the Most significant digit to Least significant digit.
    bigint.print(&a_large_num[0], true, uint2048);
    for (int i = 1; i < 5; i++) { 
        bigint.print(&a_large_num[i], false, uint2048); 
    }

    return 0;

}