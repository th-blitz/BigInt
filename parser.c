#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


#include "DecimalArray.h"
#include "ByteStack.h"



void println(char* string) {

    for (int i = 0; i < strlen(string); i++) {
        printf("%c", string[i]);
    }
    printf("\n");
}

ByteStack from_base10_string(char* string) {

    DecimalArray base10_array = decimal_array_from_string(string);
    ByteStack base10_stack = decimal_to_binary(base10_array);
    free_decimal_array(base10_array);
    return base10_stack;
    
}

bool base10_string_check(char* string, uint64_t string_len) {
    for (uint64_t i = 0; i < string_len; i++) {
        if ((string[i] < '0') & (string[i] > '9')) {
            return false;
        }
    }
    return true;
}



ByteStack String_Check(char* string, uint64_t string_len) {

    if (string_len < 2) {
        println("string len is less than 2."); 
        return Byte_Stack();
    }

    char string_type[2];
    string_type[0] = string[0];
    string_type[1] = string[1];

    ByteStack stack;

    if (strcmp(string_type, "0x")) {
        stack = from_hex_string();
    } else if (strcmp(string_type, "0o")) {
        stack = from_octal_string();
    } else if (strcmp(string_type, "0b")) {
        stack = from_binary_string();
    } else {
        if (base10_string_check(string, string_len) == false) {
            println("base 10 string container other characters apart from 0 to 9"); 
            return;
        }
        stack = from_base10_string(string);
    }
    return stack;
}