

#include "ByteStack.h"
#include "DecimalArray.h"
#include "stdio.h"



int main() {

    ByteStack stack = Byte_Stack();

    stack.append(&stack, 53);
    stack.append(&stack, 22);
    stack.append(&stack, 99);

    for (int i = 0; i < 3; i++) {
        printf("%d \n", stack.peek(&stack));
        stack.pop(&stack);
    }

    stack.free(&stack);

    char a_string[] = "123457098236913267897032375049738542375834890794838754274873845742735893274985704389758484879092437702347850475083758834087328970540298470285375407295834849243";
    char b_string[] = "1234";
    
    DecimalArray a = decimal_array_from_string(a_string);
    DecimalArray b = decimal_array_from_string(b_string);

    print_decimal_array(a);
    print_decimal_array(b);

    ByteStack a_stack = decimal_to_binary(a);

    while (a_stack.size != 0) {
        printf("%02x", a_stack.peek(&a_stack));
        a_stack.pop(&a_stack);
    }
    printf("\n");

    a_stack.free(&a_stack);
    free_decimal_array(a);
    free_decimal_array(b);
    

    uint8_t byte = 0b10001100;
    printf("%x\n", byte);

    byte = update_byte(byte, 0, 2);
    printf("%x\n", byte);

    return 0;
}