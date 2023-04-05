#include <stdio.h>


#include "ByteStack.h"
#include "DecimalArray.h"
#include "BigInt.h"



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
    

    uint128_t aa = BigInt128(&a_stack);
    uint128_t bb = BigInt128(&b_stack);

    print_bigint(&aa);
    print_bigint(&bb);

    uint32_t carry = BigInt128_add(&aa, &bb, &aa);
    printf("%08x ", carry);
    print_bigint(&aa);

    
    a_stack.free(&a_stack);
    b_stack.free(&b_stack);
    c_stack.free(&c_stack);

    return 0;
}