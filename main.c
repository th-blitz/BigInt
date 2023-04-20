
#include <stdio.h>

// large factorials: https://people.eecs.berkeley.edu/~fateman/papers/factorial.pdf

#include "BigInt.h"
#include "tests.h"
#include "utils.h"



int main() {

    run_tests();

    BigInt bigint = BigIntModule();

    // uint2048_t a_large_num[750];
    // int digits = 750;

    // a_large_num[digits - 1] = bigint.u2048_from_string("01", 2);
    // for (int i = digits - 2; i > -1; i--) {
    //     a_large_num[i] = bigint.u2048();
    // }

    // unsigned int N = 100000;
    // unsigned int carry_a = 0;
    // unsigned int carry_b = 0;
    // unsigned int overflow = 0;

    // while (N > 1) {
    //     for (int i = digits - 1; i > -1; i--) {
    //         carry_b = bigint.multiply_by_n(&a_large_num[i], N, &a_large_num[i], uint2048);
    //         bigint.add_by_n(&a_large_num[i], carry_a, &a_large_num[i], uint2048);
    //         carry_a = carry_b;
    //     }
    //     N -= 1;
    // }
    
    // char a_large_string[digits][(uint2048 * 8) + 1];

    // for (int i = 0; i < digits; i++) {
    //     bigint.to_string(&a_large_num[i], uint2048, a_large_string[i]); // the bigint.to_string() method to copy the bigint to a string in hexadecimal format.
    // }

    // for (int i = 0; i < digits; i++) {
    //     for (int j = 0; j < uint2048 * 8; j++) {
    //         if (a_large_string[i][j] == '\0') {
    //             break;
    //         }
    //         printf("%c", a_large_string[i][j]); // printing the whole string on terminal.
    //     }
    // }
    // printf("\n");


}