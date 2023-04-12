#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>


#include "ByteQueue.h"
#include "utils.h"
#include "bigint_parser.h"
#include "BigInt.h"


void is_passing(bool pass, uint32_t i, uint32_t n) {
    print("|", white);
    printint(i);
    print("/", white);
    printint(n);
    print("|", white);
    if (pass == true) {
        printlnc(" pass", green);
    } else {
        printlnc(" fail", red);
    }
}


// void test_ByteQueue() {

//     println("- create queue.");    
//     ByteQueue queue = Byte_Queue();

//     uint8_t a = 0x23;
//     uint8_t b = 0x32;
//     uint8_t c = 0x88;
//     uint8_t d = 0x79;

//     println("- append operations.");
//     queue.append_left(&queue, a);
//     queue.append_right(&queue, b);
//     queue.append_right(&queue, c);
//     queue.append_left(&queue, d);

//     println("- print queue.");
//     queue.print(&queue);

//     println("- free queue.");
//     queue.free(&queue);

// }

// void test_parser() {

//     char* hex_string = "0x2848fa3b32c";
//     char* base10_string = "128892875023897";

//     println("- test base10 to bytequeue");
//     println(base10_string);
//     ByteQueue queue = one_time_string_to_bytequeue(base10_string, strlen(base10_string));
//     queue.print_hex(&queue);
//     println("check: 75 3A 36 07 A6 19");
//     queue.free(&queue);

//     char* base10_string2 = "00000000010000000000";
//     println(base10_string2);
//     queue = one_time_string_to_bytequeue( base10_string2, strlen(base10_string2));
//     queue.print_hex(&queue);
//     println("check: 02 54 0B E4 00");
//     queue.free(&queue);

//     char* base10_string3 = "00000000000000000000000000000000000000000000";
//     println(base10_string3);
//     queue = one_time_string_to_bytequeue(base10_string3, strlen(base10_string3));
//     queue.print_hex(&queue);
//     println("check: 00");
//     queue.free(&queue);

//     char* base10_string4 = "50914859719408375073029878579190748571350987134";
//     println(base10_string4);
//     queue = one_time_string_to_bytequeue(base10_string4, strlen(base10_string4));
//     queue.print_hex(&queue);
//     println("check: 8EB19ECEEC4689E4C06C1DE19088992E9B5F17E");
//     queue.free(&queue);
// }

bool unittest_uint128(char* input_string, char* output_string) {
    BigInt bigint = BigIntModule();
    char check_string[uint2048 * 8];
    uint128_t a = bigint.u128_from_string(input_string, strlen(input_string));
    bigint.to_string(&a, a.type, check_string);
    return hex_string_compare(output_string, check_string);
}

void test_uint128() {

    char inputs[100][100] = {
        "0000", "000001", "9037208479874057835479", "340282366920938463463374607431768211455",
        "340282366920938463463374607431768211456", "340282366920938463463374607431768211457",
        "0x00", "0x001", "0x8fafbb5b3d7", "0xffffffffffffffffffffffffffffffff",
        "0x100000000000000000000000000000000", "0x100000000000000000000000000000001",
        "0b00", "0b001", "0b110101001", "0b10000000",
    };

    char outputs[100][100] = {
        "00", "001", "1e9e8762f43491d13d7", "00ffffffffffffffffffffffffffffffff",
        "000", "01",
        "00", "01", "8fafbb5b3d7", "ffffffffffffffffffffffffffffffff",
        "000", "0001",
        "00", "001", "1a9", "80"
    };

    uint32_t number_of_tests = 16;
    uint32_t i = 0;
    bool pass = false;
    while (i < number_of_tests) {
        pass = unittest_uint128(inputs[i], outputs[i]);
        is_passing(pass, i + 1, number_of_tests);
        i += 1;
    }
}


void run_tests() {
    
    int total_tests = 1;    
    int i = 0;
    bool passing = false;

    // println("test 1. bytequeue");
    // test_ByteQueue();
    // i += 1;
    // println("");

    // println("test 2. parser");
    // test_parser();
    // i += 1;
    // println("");

    printlnc("test 1. bigint uint128_t", cyan);
    test_uint128();
    i += 1;
}