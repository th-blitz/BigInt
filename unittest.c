#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>


#include "ByteQueue.h"
#include "utils.h"
#include "bigint_parser.h"
#include "BigInt.h"

#include "unittest.h"

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

void unittest_finalize(unittest* module) {
    print("- tests (", white);
    if (module -> fails == 0) {
        printintc(module -> passes, green);
        print("/", white);
        printintc(module -> total_tests, green);
        print(") ", white);
        printlnc("all passed", green);
    } else if ((module -> fails != 0) && (module -> passes != 0)) {
        printintc(module -> passes, yellow);
        print("/", white);
        printintc(module -> total_tests, yellow);
        print(") ", white);
        print("passed", yellow);
        print(" and ", white);
        print("(", white);
        printintc(module -> fails, red);
        print("/", white);
        printintc(module -> total_tests, red);
        print(") ", white);
        printlnc("failed", red);
        print("  | fails: ", white);
        for (uint64_t i = 0; i < module -> count; i++) {
            if (module -> tests[i] == 1) {
                printintc(i + 1, yellow);
                print(" ", white);
            }
        }
        println("");
    } else if (module -> passes == 0) {
        printintc(module -> passes, red);
        print("/", white);
        printintc(module -> total_tests, red);
        print(") ", white);
        printlnc("passes (all failed)", red);
    }
}

void unittest_reset(unittest* module) {
    module -> count = 0;
    module -> passes = 0;
    module -> fails = 0;
    for (uint64_t i = 0; i < module -> total_tests; i++) {
        module -> tests[i] = 0;
    }
}

void unittest_update(unittest* module, bool pass_or_fail) {
    module -> passes += (pass_or_fail == true) ? 1 : 0;
    module -> fails += (pass_or_fail == false) ? 1 : 0;
    module -> tests[module -> count] = (pass_or_fail == false) ? 1: 0;
    module -> count += 1;
}

void unittest_free(unittest* module) {
    free(module -> tests);
}

unittest malloc_UnitTest_Module(uint64_t total_tests) {
    unittest module = {
        .count = 0,
        .total_tests = total_tests,
        .passes = 0,
        .fails = 0,
    };
    module.tests = (uint8_t*)malloc(total_tests * sizeof(uint8_t));
    module.reset = unittest_reset;
    module.update = unittest_update;
    module.finalize = unittest_finalize;
    module.free = unittest_free;
    return module;
}



bool unittest_uint128_init(char* input_string, char* output_string) {
    BigInt bigint = BigIntModule();
    char check_string[uint2048 * 8];
    uint128_t a = bigint.u128_from_string(input_string, strlen(input_string));
    bigint.to_string(&a, a.type, check_string);
    return hex_string_compare(output_string, check_string);
}

void test_uint128_init() {

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
    unittest testing = malloc_UnitTest_Module(16);
    while (i < number_of_tests) {
        pass = unittest_uint128_init(inputs[i], outputs[i]);
        testing.update(&testing, pass);
        i += 1;
    }
    testing.finalize(&testing);
    testing.free(&testing);
}

bool unittest_uint128_addition(char* input_string_a, char* input_string_b, char* output_string_a, uint32_t output_carry) {
    BigInt bigint = BigIntModule();
    char check_string[uint2048 * 8];
    uint128_t a = bigint.u128_from_string(input_string_a, strlen(input_string_a));
    uint128_t b = bigint.u128_from_string(input_string_b, strlen(input_string_b));
    uint128_t c = bigint.u128();
    uint32_t carry = bigint.add(&a, &b, &c, a.type);
    bigint.to_string(&c, c.type, check_string);
    return hex_string_compare(check_string, output_string_a) && (carry == output_carry);
}

void test_uint128_addition() {

    char inputs[100][100] = {
        "000", "000",
        "000", "0001",
        "0001", "0001",
        "0007987", "0x8ab423",
        "0xffffffffffffffffffffffffffffffff", "0001",
        "0xffffffffffffffffffffffffffffffff", "0b00010",
        "8217834017289347038978", "3493702873789749387",
        "0xffffffffffffffff", "0xffffffffffffffffffffffffffffffffffff"
    };

    char outputs[100][100] = {
        "000",
        "001",
        "002",
        "8ad356",
        "000",
        "0001",
        "1bdadd77306fbd4578d",
        "fffffffffffffffe"
    };

    char carry[100] = {
        0, 0, 0, 0, 1, 1, 0, 1
    };

    uint32_t number_of_tests = 16;
    uint32_t i = 0;
    bool pass = false;
    unittest testing = malloc_UnitTest_Module(8);
    while (i < number_of_tests) {
        pass = unittest_uint128_addition(inputs[i], inputs[i + 1], outputs[i / 2], carry[i / 2]);
        testing.update(&testing, pass);
        i += 2;
    }
    testing.finalize(&testing);
    testing.free(&testing);
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
    test_uint128_init();
    i += 1;

    printlnc("test 2. bigint uint128_t addition:", cyan);
    test_uint128_addition();

}