#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>


#include "ByteQueue.h"
#include "utils.h"
#include "bigint_parser.h"
#include "BigInt.h"


#define is_passing(a) (a == true ? printlnc("- passed.", green) : printlnc("- failed.", red));


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

bool test_uint128() {

    BigInt bigint = BigIntModule();
    char check_string[uint2048 * 8];
    bool passing = false;

    uint128_t a = bigint.u128_from_string("8019837018392", strlen("8019837018392"));
    bigint.to_string(&a, a.type, check_string);
    passing = hex_string_compare("74b43896118", check_string);
    (passing == true) ? printlnc("- passed.", green) : printlnc("- failed.", red);
    
    uint128_t b = bigint.u128_from_string("000000", strlen("000000"));
    bigint.to_string(&b, b.type, check_string);
    passing = hex_string_compare("0", check_string);
    (passing == true) ? printlnc("- passed.", green) : printlnc("- failed.", red);

    char* c_string = "340282366920938463463374607431768211455";
    uint128_t c = bigint.u128_from_string(c_string, strlen(c_string));
    bigint.to_string(&c, c.type, check_string);
    passing = hex_string_compare("00ffffffffffffffffffffffffffffffff", check_string);
    (passing == true) ? printlnc("- passed.", green) : printlnc("- failed.", red);
    
    char* d_string = "340282366920938463463374607431768211456";
    uint128_t d = bigint.u128_from_string(d_string, strlen(d_string));
    bigint.to_string(&d, d.type, check_string);
    passing = hex_string_compare("000", check_string);
    (passing == true) ? printlnc("- passed.", green) : printlnc("- failed.", red);
    
    char* e_string = "340282366920938463463374607431768211457";
    uint128_t e = bigint.u128_from_string(e_string, strlen(e_string));
    bigint.to_string(&e, e.type, check_string);
    passing = hex_string_compare("001", check_string);
    is_passing(passing);

    return passing;   
}


void run_tests() {
    
    int total_tests = 1;    
    int i = 0;
    bool passing = false;

    println("test 1. bytequeue");
    test_ByteQueue();
    i += 1;
    println("");

    println("test 2. parser");
    test_parser();
    i += 1;
    println("");

    println("test 3. bigint uint128_t");
    passing = test_uint128();
    print("test 3: ", cyan);
    is_passing(passing);
    i += 1;
}