
#include <stdio.h>


#include "BigInt.h"
#include "tests.h"


int main() {

    // run_tests();

    BigInt bigint = BigIntModule();


    uint2048_t a = bigint.u2048_from_string("01", 2);
    uint2048_t b = bigint.u2048();
    unsigned int N = 536;
    unsigned int carry_a = 0;
    unsigned int carry_b = 0;
    unsigned int overflow = 0;
    uint32_t overflow_check = 0;

    while (N > 1) {
        carry_a = bigint.multiply_by_n(&a, N, &a, a.type);
        carry_b = bigint.multiply_by_n(&b, N, &b, b.type);
        bigint.add_by_n(&b, carry_a, &b, b.type);
        if (carry_b > 0) {
            printf("overflow\n");
        }
        N -= 1;
    }
    bigint.print(&b, b.type);
    bigint.print(&a, a.type);

    return 0;
}