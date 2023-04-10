#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>


#include "ByteQueue.h"
#include "utils.h"
#include "bigint_parser.h"
#include "BigInt.h"


void test_ByteQueue() {

    println("- create queue.");    
    ByteQueue queue = Byte_Queue();

    uint8_t a = 0x23;
    uint8_t b = 0x32;
    uint8_t c = 0x88;
    uint8_t d = 0x79;

    println("- append operations.");
    queue.append_left(&queue, a);
    queue.append_right(&queue, b);
    queue.append_right(&queue, c);
    queue.append_left(&queue, d);

    println("- print queue.");
    queue.print(&queue);

    println("- free queue.");
    queue.free(&queue);

}

void test_parser() {

    char* hex_string = "0x2848fa3b32c";
    char* base10_string = "128892875023897";

    println("- test base10 to bytequeue");
    println(base10_string);
    ByteQueue queue = one_time_string_to_bytequeue(base10_string, strlen(base10_string));
    queue.print_hex(&queue);
    println("check: 75 3A 36 07 A6 19");
    queue.free(&queue);

    char* base10_string2 = "00000000010000000000";
    println(base10_string2);
    queue = one_time_string_to_bytequeue( base10_string2, strlen(base10_string2));
    queue.print_hex(&queue);
    println("check: 02 54 0B E4 00");
    queue.free(&queue);

    char* base10_string3 = "00000000000000000000000000000000000000000000";
    println(base10_string3);
    queue = one_time_string_to_bytequeue(base10_string3, strlen(base10_string3));
    queue.print_hex(&queue);
    println("check: 00");
    queue.free(&queue);

    char* base10_string4 = "50914859719408375073029878579190748571350987134";
    println(base10_string4);
    queue = one_time_string_to_bytequeue(base10_string4, strlen(base10_string4));
    queue.print_hex(&queue);
    println("check: 8EB19ECEEC4689E4C06C1DE19088992E9B5F17E");
    queue.free(&queue);
}

void test_uint128() {


    println("- test uint128_t from string");
    char* num_string = "003232";
    println("check: 003232");
    uint128_t num = BigInt128_from_string(num_string, strlen(num_string));
    print_bigint(&num, num.type);


    num_string = "000000";
    printf("check: ");
    println(num_string);
    num = BigInt128_from_string(num_string, strlen(num_string));
    print_bigint(&num, num.type);


    num_string = "340282366920938463463374607431768211455";
    printf("check: ");
    println(num_string);
    num = BigInt128_from_string(num_string, strlen(num_string));
    print_bigint(&num, num.type);

    num_string = "340282366920938463463374607431768211456";
    printf("check: ");
    println(num_string);
    num = BigInt128_from_string(num_string, strlen(num_string));
    print_bigint(&num, num.type);

    num_string = "3402823669209384634633746074";
    printf("check: ");
    println(num_string);
    num = BigInt128_from_string(num_string, strlen(num_string));
    print_bigint(&num, num.type);
    println("AFEBFF0BCB24AAFEF78F69A");

}


void run_tests() {
    
    int total_tests = 1;    
    int i = 0;

    println("test 1. bytequeue");
    test_ByteQueue();
    i += 1;
    println("");

    println("test 2. parser");
    test_parser();
    i += 1;
    println("");

    println("test 3. bigint uint128_t");
    test_uint128();
    i += 1;
    println("");
}