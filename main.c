
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
    
    BigInt BigInt = BigIntModule();

    char* string = "0x111f001001";
    uint128_t zero = BigInt.u128();
    uint128_t num = BigInt.u128_from_string(string, strlen(string));

    uint32_t remainder = 0;
    char string10[100];
    int i = 0;
    while (BigInt.compare(&num, &zero, num.type) == 1) {
        remainder = BigInt.divide_by_n(&num, 10, &num, num.type); 
        string10[i] = (uint8_t)remainder + '0';
        i += 1;
    }
    print("red : ", red);
    for ( ; i > 0; i--) {
        printf("%c", string10[i - 1]);
    }
    println(""); 
    print("gre : ", green);
    println(string);

    return 0;

}