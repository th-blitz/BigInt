

#include "ByteStack.h"
#include "DecimalArray.h"
#include "stdio.h"
#include "BigInt.h"



int main() {

    char a_string[] = "44718955064374544454463347970854264333";
    char b_string[] = "6451689080233393001889558865618767112";
    
    DecimalArray a = decimal_array_from_string(a_string);
    DecimalArray b = decimal_array_from_string(b_string);

    print_decimal_array(a);
    print_decimal_array(b);

    ByteStack a_stack = decimal_to_binary(a);
    ByteStack b_stack = decimal_to_binary(b);

    free_decimal_array(a);
    free_decimal_array(b);

    a_stack.print(&a_stack);
    b_stack.print(&b_stack);
    

    uint128 aa = BigInt128(&a_stack);
    uint128 bb = BigInt128(&b_stack);

    print_bigint(&aa);
    print_bigint(&bb);

    uint16_t carry = BigInt128_add(&aa, &bb, &aa);
    print_bigint(&aa);

    a_stack.free(&a_stack);
    b_stack.free(&b_stack);

    return 0;
}