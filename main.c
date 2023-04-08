#include <stdio.h>


#include "ByteStack.h"
#include "DecimalArray.h"
#include "BigInt.h"
#include "unittest.h"


int main() {

    char a_string[] = "340282366920938463463374607431768211455";
    char b_string[] = "340282366920938463463374607431768211455";
    
    DecimalArray a = decimal_array_from_string(a_string);
    DecimalArray b = decimal_array_from_string(b_string);
    DecimalArray c = decimal_array_addition(a, b);

    print_decimal_array(a);
    print_decimal_array(b);
    print_decimal_array(c);
    printf("\n");

    ByteStack a_stack = decimal_to_binary(a);
    ByteStack b_stack = decimal_to_binary(b);
    ByteStack c_stack = decimal_to_binary(c);

    free_decimal_array(a);
    free_decimal_array(b);
    free_decimal_array(c);

    a_stack.print(&a_stack);
    b_stack.print(&b_stack);
    c_stack.print(&c_stack);    
    
    uint128_t bb = BigInt128_from_bytes(&b_stack);
    uint128_t aa = BigInt128_from_bytes(&a_stack);
    
    uint128_t cc = BigInt128();

    print_bigint(&aa, aa.type);
    print_bigint(&bb, bb.type);

    uint32_t carry = BigInt128_subtract(&aa, &bb, &cc);
    printf("%d ", carry);
    print_bigint(&cc, cc.type);

    uint256_t dd = BigInt256();

    BigInt128_mulitplication(&aa, &bb, &dd);
    print_bigint(&dd, dd.type);
    
    a_stack.free(&a_stack);
    b_stack.free(&b_stack);
    c_stack.free(&c_stack);

    printf("%d\n", BigInt128_cmp(&aa, &bb));

    run_tests();

    return 0;
}