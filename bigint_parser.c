#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>


#include "ByteQueue.h"
#include "utils.h"
#include "bigint_parser.h"


static uint8_t byte_mask[8] = {
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 
};

static uint8_t byte_hex_mask[] = {
    0xa, 0xb, 0xc, 0xd, 0xe, 0xf
};

static uint64_t pow10[10] = {
    1, 10, 100, 1000, 10000, 
    100000, 1000000, 10000000, 100000000, 1000000000
};

static uint8_t update_byte(uint8_t byte, uint8_t bit, uint64_t index) {
    switch (bit) {
        case 0:
            byte &= (~ byte_mask[index]);
            break;
        case 1:
            byte |= (  byte_mask[index]);
            break;
    }
    return byte;
}

uint8_t* malloc_one_time_base10_array(char* string, uint64_t string_len) {

    uint8_t* array = (uint8_t*)malloc(sizeof(uint8_t) * string_len);
    for (uint64_t i = 0; i < string_len; i++) {
        array[i] = string[i] - '0';
    }
    
    return array;
}

bool is_base10_array_zero(uint8_t* array, uint64_t array_len) {
    for (uint64_t i = 0; i < array_len; i++) {
        if (array[i] != 0) {
            return false;
        }
    }
    return true;
}

uint8_t base10_array_divide_by_2(uint8_t* array, uint64_t array_size) {
    
    uint64_t next_additive = 0;
    uint64_t additive;

    uint8_t remainder = (array[array_size - 1] % 2 == 0) ? 0 : 1;

    for (uint64_t i = 0; i < array_size; i++) {
        additive = next_additive;
        if (array[i] % 2 != 0) {
            next_additive = 5;
        } else {
            next_additive = 0;
        }
        array[i] = (array[i] / 2) + additive;
    }

    return remainder;
}

ByteQueue bytequeue_from_base10_string(uint8_t* array, uint64_t array_len) {
    
    uint64_t i = 0;
    uint8_t remainder = 0;
    uint8_t byte = 0x0;
    ByteQueue queue = Byte_Queue();

    while (is_base10_array_zero(array, array_len) == false) {
        remainder = base10_array_divide_by_2(array, array_len);
        byte = update_byte(byte, remainder, i % 8);
        if (i % 8 == 7) {
            queue.append_left(&queue, byte);
            byte = 0x0;
        }
        i += 1;
    }
    if (byte != 0) { queue.append_left(&queue, byte); }
    return queue;
}

ByteQueue bytequeue_from_hex_string(char* string, uint64_t string_len) {
    
    ByteQueue queue = Byte_Queue();
    uint8_t byte = 0x0;
    uint64_t i = string_len;
    uint64_t even_flag = (string_len % 2 == 0) ? 1 : 0;

    while (i > 0) {
        byte <<= 4;
        if ((string[i - 1] >= 'A') && (string[i - 1] <= 'F')) {
            byte |= byte_hex_mask[string[i - 1] - 'A'];
        } else if ((string[i - 1] >= 'a') && (string[i - 1] <= 'f')) {
            byte |= byte_hex_mask[string[i - 1] - 'a'];
        } else if ((string[i - 1] >= '0') && (string[i - 1] <= '9')) {
            byte |= string[i - 1] - '0';
        } else {
            printlnc("err: at bigintparser.c/bytequeue_from_hex_string():", red);
            printf("%c\n", string[i - 1]);
        }
        if (i % 2 == even_flag) {
            queue.append_left(&queue, byte << 4 | byte >> 4);
            byte = 0x0;
        }
        i -= 1;
    }
    if (byte != 0) { queue.append_left(&queue, byte); }
    return queue;
}

ByteQueue bytequeue_from_binary_string(char* string, uint64_t string_len) {
    
    ByteQueue queue = Byte_Queue();
    uint8_t byte = 0x0;
    uint64_t i = 0;
    uint64_t even_flag = (string_len % 2 == 0) ? 1 : 0;

    while (i < string_len) {
        if ((string[string_len - i - 1] == '0') || (string[string_len - i - 1] == '1')) {
            byte |= (string[string_len - i - 1] - '0') << (i % 8);
        } else {
            printlnc("err: at bigintparser.c/bytequeue_from_binary_string():", red);
            printf("%c\n", string[string_len - i - 1]);
        }
        if (i % 8 == 7) {
            queue.append_left(&queue, byte);
            byte = 0x0;
        }
        i += 1;
    }
    if (byte != 0) {queue.append_left(&queue, byte);}
    return queue;
}

bool base10_string_check(char* string, uint64_t string_len) {
    for (uint64_t i = 0; i < string_len; i++) {
        if (((string[i] >= '0') && (string[i] <= '9')) == false) {
            return false;
        }
    }
    return true;
}

void base10_string_error_check(char* string, uint64_t string_len) {
    print("- ", red);
    uint64_t i = 0;
    while (i < string_len) {
        if (((string[i] >= '0') && (string[i] <= '9')) == false) {
            printf("\x1b[33m%c\x1b[0m", string[i]);
        } else {
            printf("\x1b[32m%c\x1b[0m", string[i]);
        }
        i += 1;
    }
    printf("\n");
}

bool hex_string_check(char* string, uint64_t string_len) {
    for (uint64_t i = 2; i < string_len; i++) {
        if (((string[i] >= '0') && (string[i] <= '9')) || 
        ((string[i] >= 'a') && (string[i] <= 'f')) || 
        ((string[i] >= 'A') && (string[i] <= 'F'))) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

void hex_string_error_check(char* string, uint64_t string_len) {
    print("- ", red);
    uint64_t i = 0;
    while (i < string_len) {
        if (((string[i] >= '0') && (string[i] <= '9')) || 
        ((string[i] >= 'a') && (string[i] <= 'f')) || 
        ((string[i] >= 'A') && (string[i] <= 'F'))) {
            printf("\x1b[32m%c\x1b[0m", string[i]);
        } else {
            printf("\x1b[33m%c\x1b[0m", string[i]);
        }
        i += 1;
    }
    printf("\n");
}

bool binary_string_check(char* string, uint64_t string_len) {
    for (uint64_t i = 2; i < string_len; i++) {
        if ((string[i] == '1') || (string[i] == '0')) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

void binary_string_error_check(char* string, uint64_t string_len) {
    print("- ", red);
    uint64_t i = 0;
    while (i < string_len) {
        if ((string[i] == '1') || (string[i] == '0')) {
            printf("\x1b[32m%c\x1b[0m", string[i]);
        } else {
            printf("\x1b[33m%c\x1b[0m", string[i]);
        }
        i += 1;
    }
    printf("\n");
}

void one_time_string_to_bytequeue_error() {
    print("- err: bad string error: ", red);
    printlnc("at bigint_parser/one_time_string_to_bytequeue().", cyan);
    print("- ", red);
    printlnc("A string with illegal characters has been passed that ", yellow);
    printlnc("  does not match any of the formats like 0x00 (hex) or 0b00 (binary) or base10:", yellow);
}

ByteQueue one_time_string_to_bytequeue(char* string, uint64_t string_len) {

    if (string_len < 2) {
        println("string len is less than 2."); 
        return Byte_Queue();
    }
    uint64_t MAX = 0xffffffffffffffff - 1;
    if (string_len > MAX) {
        println("string len is greater than max.");
        return Byte_Queue();
    }

    char string_type[3];
    string_type[0] = string[0];
    string_type[1] = string[1];

    ByteQueue queue = Byte_Queue();
    queue.size = 0;
    bool empty_queue_flag = true;
    uint64_t i = 0;

    if (string_type[0] == '0' && string_type[1] == 'x') {
        if(hex_string_check(string, string_len) == true) {
            i = 2;
            while ((string[i] == '0') && (i < string_len)) {
                i += 1;
            }
            queue = bytequeue_from_hex_string(string + i, string_len - i);
            empty_queue_flag = false;
        } else {
            one_time_string_to_bytequeue_error();
            hex_string_error_check(string, string_len);
        }
    } else if (string_type[0] == '0' && string_type[1] == 'b') {
        if (binary_string_check(string, string_len) == true) {
            i = 2;
            while ((string[i] == '0') && (i < string_len)) {
                i += 1;
            }
            queue = bytequeue_from_binary_string(string + i, string_len - i);
            empty_queue_flag = false;
        } else {
            one_time_string_to_bytequeue_error();
            binary_string_error_check(string, string_len);
        }
    } else {
        if (base10_string_check(string, string_len) == true) {
            while ((string[i] == '0') && (i < string_len) ) {
                i += 1;
            }
            uint8_t* array = malloc_one_time_base10_array(string + i, string_len - i);
            queue = bytequeue_from_base10_string(array, string_len - i);
            free(array);
            empty_queue_flag = false;
        } else {
            one_time_string_to_bytequeue_error();
            base10_string_error_check(string, string_len);
        } 
    }

    if (empty_queue_flag == true) {
        exit(-1); 
    }

    return queue;
}

bool bigint_string_check(char* string, uint64_t string_len) {

    bool check = false;

    if (string_len <= 0) { 
        return true;
    }
    uint64_t MAX = 0xffffffffffffffff - 1;
    if (string_len > MAX) {
        println("string len is greater than max.");
        return false;
    }

    if (string_len == 1) {
        check = base10_string_check(string, string_len);
        if (check == false) {
            base10_string_error_check(string, string_len);
        }
    } else if (string[0] == '0' && string[1] == 'x') {
        check = hex_string_check(string, string_len);
        if (check == false) {
            hex_string_error_check(string, string_len);
        }
    } else if (string[0] == '0' && string[1] == 'b') {
        check = binary_string_check(string, string_len);
        if (check == false) {
            binary_string_error_check(string, string_len);
        }
    } else {
        check = base10_string_check(string, string_len);
        if (check == false) {
            base10_string_error_check(string, string_len);
        }
    }
    return check;
} 

StringType bigint_string_type_check(char* string, uint64_t string_len) {
    
    if (string_len == 1) {
        return decimal;
    } else if (string[0] == '0' && string[1] == 'x') {
        return hexadecimal;
    } else if (string[0] == '0' && string[1] == 'b') {
        return binary;
    } 
    return decimal;
}