
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
    char* string = "101";
    uint128_t a = bigint.u128_from_string(string, strlen(string));

    BigInt128_left_shift(&a,8, &a);

    bigint.println(&a, a.type, base_2);
    bigint.println_hex(&a, a.type, false);

    BigInt128_right_shift(&a, 12, &a);

    bigint.println(&a, a.type, base_2);
    bigint.println_hex(&a, a.type, false);
    return 0;

}