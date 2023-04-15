#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "unittest.h"
#include "ByteQueue.h"
#include "BigInt.h"
#include "utils.h"


// https://www.mobilefish.com/services/big_number/big_number.php


static char* uint128_MAX = "340282366920938463463374607431768211455";
static char* uint256_MAX = "115792089237316195423570985008687907853269984665640564039457584007913129639935";
static char* uint512_MAX = "13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084095";
static char* uint1024_MAX = "179769313486231590772930519078902473361797697894230657273430081157732675805500963132708477322407536021120113879871393357658789768814416622492847430639474124377767893424865485276302219601246094119453082952085005768838150682342462881473913110540827237163350510684586298239947245938479716304835356329624224137215";
static char* uint2048_MAX = "32317006071311007300714876688669951960444102669715484032130345427524655138867890893197201411522913463688717960921898019494119559150490921095088152386448283120630877367300996091750197750389652106796057638384067568276792218642619756161838094338476170470581645852036305042887575891541065808607552399123930385521914333389668342420684974786564569494856176035326322058077805659331026192708460314150258592864177116725943603718461857357598351152301645904403697613233287231227125684710820209725157101726931323469678542580656697935045997268352998638215525166389437335543602135433229604645318478604952148193555853611059596230655";

static char* uint128_OVERFLOW = "340282366920938463463374607431768211456";
static char* uint256_OVERFLOW = "115792089237316195423570985008687907853269984665640564039457584007913129639936";
static char* uint512_OVERFLOW = "13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084096";
static char* uint1024_OVERFLOW = "179769313486231590772930519078902473361797697894230657273430081157732675805500963132708477322407536021120113879871393357658789768814416622492847430639474124377767893424865485276302219601246094119453082952085005768838150682342462881473913110540827237163350510684586298239947245938479716304835356329624224137216";
static char* uint2048_OVERFLOW = "32317006071311007300714876688669951960444102669715484032130345427524655138867890893197201411522913463688717960921898019494119559150490921095088152386448283120630877367300996091750197750389652106796057638384067568276792218642619756161838094338476170470581645852036305042887575891541065808607552399123930385521914333389668342420684974786564569494856176035326322058077805659331026192708460314150258592864177116725943603718461857357598351152301645904403697613233287231227125684710820209725157101726931323469678542580656697935045997268352998638215525166389437335543602135433229604645318478604952148193555853611059596230656";

bool unittest_uint128_init(char* input_string, char* output_string) {
    BigInt bigint = BigIntModule();
    char check_string[uint2048 * 8];
    uint128_t a = bigint.u128_from_string(input_string, strlen(input_string));
    bigint.to_string(&a, a.type, check_string);
    return hex_string_compare(output_string, check_string);
}

bool unittest_uint256_init(char* input, char* output) {
    BigInt bigint = BigIntModule();
    char check_string[uint2048 * 8];
    uint256_t a = bigint.u256_from_string(input, strlen(input));
    bigint.to_string(&a, a.type, check_string);
    return hex_string_compare(output, check_string);
}

bool unittest_uint512_init(char* input, char* output) {
    BigInt bigint = BigIntModule();
    char check_string[uint2048 * 8];
    uint512_t a = bigint.u512_from_string(input, strlen(input));
    bigint.to_string(&a, a.type, check_string);
    return hex_string_compare(output, check_string);
}

bool unittest_uint1024_init(char* input, char* output) {
    BigInt bigint = BigIntModule();
    char check_string[uint2048 * 8];
    uint1024_t a = bigint.u1024_from_string(input, strlen(input));
    bigint.to_string(&a, a.type, check_string);
    return hex_string_compare(output, check_string);
}

bool unittest_uint2048_init(char* input, char* output) {
    BigInt bigint = BigIntModule();
    char check_string[uint2048 * 8];
    uint2048_t a = bigint.u2048_from_string(input, strlen(input));
    bigint.to_string(&a, a.type, check_string);
    return hex_string_compare(output, check_string);
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

void test_uint256_init() {
    char inputs[100][100] = {
        "0000", "000001", "9037208479874057835479", "115792089237316195423570985008687907853269984665640564039457584007913129639935",
        "115792089237316195423570985008687907853269984665640564039457584007913129639937", "115792089237316195423570985008687907853269984665640564039457584007913129639936",
        "0x00", "0x001", "0x8fafbb5b3d7", "0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",
        "0x10000000000000000000000000000000000000000000000000000000000000000", "0x10000000000000000000000000000000000000000000000000000000000000001",
        "0b00", "0b001", "0b110101001", "0b1000000000000100000000000000000111000100000000000000000001110000001",
    };

    char outputs[100][100] = {
        "00", "001", "1e9e8762f43491d13d7", "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",
        "001", "000",
        "00", "01", "8fafbb5b3d7", "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",
        "000", "0001",
        "00", "001", "1a9", "40020000e20000381"
    };

    int number_of_tests = 16;
    unittest module = malloc_UnitTest_Module(number_of_tests);
    bool pass = false;


    for (int i = 0; i < number_of_tests; i++) {
        pass = unittest_uint256_init(inputs[i], outputs[i]);
        module.update(&module, pass);
    }
    module.finalize(&module);
    module.free(&module);

}

void test_uint512_init() {
    char inputs[][200] = {
        "000", "00001", "9037208479874057835479", "13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084095",
        "13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084096",
        "13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084097",
        "0x00", "0x0001", "0x8fafbb5b3d7", "0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
    };

    char outputs[][200] = {
        "000", "001", "1e9e8762f43491d13d7", "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",
        "000", "0001", "000", "001", "08fafbb5b3d7", "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",
    };

    int number_of_tests = 10;
    unittest module = malloc_UnitTest_Module(number_of_tests);
    bool pass = false;


    for (int i = 0; i < number_of_tests; i++) {
        pass = unittest_uint512_init(inputs[i], outputs[i]);
        module.update(&module, pass);
    }
    module.finalize(&module);
    module.free(&module);
}

void test_uint1024_init() {
    
    char inputs[][400] = {
        "000", "00001", "9037208479874057835479", "13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084095",
        "13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084096",
        "13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084097",
        "179769313486231590772930519078902473361797697894230657273430081157732675805500963132708477322407536021120113879871393357658789768814416622492847430639474124377767893424865485276302219601246094119453082952085005768838150682342462881473913110540827237163350510684586298239947245938479716304835356329624224137215",
        "179769313486231590772930519078902473361797697894230657273430081157732675805500963132708477322407536021120113879871393357658789768814416622492847430639474124377767893424865485276302219601246094119453082952085005768838150682342462881473913110540827237163350510684586298239947245938479716304835356329624224137216",
        "179769313486231590772930519078902473361797697894230657273430081157732675805500963132708477322407536021120113879871393357658789768814416622492847430639474124377767893424865485276302219601246094119453082952085005768838150682342462881473913110540827237163350510684586298239947245938479716304835356329624224137217",
        "0x001", "0x000", "0x8fafbb5b3d7", "0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",
        "0x123456789afffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
    };

    char outputs[][400] = {
        "000", "001", "1e9e8762f43491d13d7", "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",
        "100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
        "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",
        "000000000000000000",
        "00000001",
        "0001", "000", "08fafbb5b3d7", "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",
        "0123456789afffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
    };

    int number_of_tests = 14;
    unittest module = malloc_UnitTest_Module(number_of_tests);
    bool pass = false;

    for (int i = 0; i < number_of_tests; i++) {
        pass = unittest_uint1024_init(inputs[i], outputs[i]);
        module.update(&module, pass);
    }
    module.finalize(&module);
    module.free(&module);
}

void test_uint2048_init() {
    
    char inputs[][800] = {
        "000", "00001", "9037208479874057835479", "13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084095",
        "13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084096",
        "13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084097",
        "179769313486231590772930519078902473361797697894230657273430081157732675805500963132708477322407536021120113879871393357658789768814416622492847430639474124377767893424865485276302219601246094119453082952085005768838150682342462881473913110540827237163350510684586298239947245938479716304835356329624224137215",
        "32317006071311007300714876688669951960444102669715484032130345427524655138867890893197201411522913463688717960921898019494119559150490921095088152386448283120630877367300996091750197750389652106796057638384067568276792218642619756161838094338476170470581645852036305042887575891541065808607552399123930385521914333389668342420684974786564569494856176035326322058077805659331026192708460314150258592864177116725943603718461857357598351152301645904403697613233287231227125684710820209725157101726931323469678542580656697935045997268352998638215525166389437335543602135433229604645318478604952148193555853611059596230656",
        "32317006071311007300714876688669951960444102669715484032130345427524655138867890893197201411522913463688717960921898019494119559150490921095088152386448283120630877367300996091750197750389652106796057638384067568276792218642619756161838094338476170470581645852036305042887575891541065808607552399123930385521914333389668342420684974786564569494856176035326322058077805659331026192708460314150258592864177116725943603718461857357598351152301645904403697613233287231227125684710820209725157101726931323469678542580656697935045997268352998638215525166389437335543602135433229604645318478604952148193555853611059596230657",
        "32317006071311007300714876688669951960444102669715484032130345427524655138867890893197201411522913463688717960921898019494119559150490921095088152386448283120630877367300996091750197750389652106796057638384067568276792218642619756161838094338476170470581645852036305042887575891541065808607552399123930385521914333389668342420684974786564569494856176035326322058077805659331026192708460314150258592864177116725943603718461857357598351152301645904403697613233287231227125684710820209725157101726931323469678542580656697935045997268352998638215525166389437335543602135433229604645318478604952148193555853611059596230655",
        "0x001", "0x000", "0x8fafbb5b3d7", "0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",
        "0x123456789afffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
    };

    char outputs[][800] = {
        "000", "001", "1e9e8762f43491d13d7", "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",
        "100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
        "100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001",
        "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",
        "000000000000000000",
        "00000001",
        "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",
        "0001", "000", "08fafbb5b3d7", "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",
        "0123456789afffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff"
    };

    int number_of_tests = 15;
    unittest module = malloc_UnitTest_Module(number_of_tests);
    bool pass = false;

    for (int i = 0; i < number_of_tests; i++) {
        pass = unittest_uint2048_init(inputs[i], outputs[i]);
        module.update(&module, pass);
    }
    module.finalize(&module);
    module.free(&module);
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

bool unittest_uint256_addition(char* input_string_a, char* input_string_b, char* output_string, uint32_t output_carry) {
    BigInt bigint = BigIntModule();
    uint256_t a = bigint.u256_from_string(input_string_a, strlen(input_string_a));
    uint256_t b = bigint.u256_from_string(input_string_b, strlen(input_string_b));
    uint256_t d = bigint.u256_from_string(output_string, strlen(output_string));
    uint256_t c = bigint.u256();
    uint32_t carry = bigint.add(&a, &b, &c, a.type);
    return ((bigint.compare(&c, &d, d.type) == 0) && carry == output_carry);
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

void test_uint256_addition() {

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
        "0x8ad356",
        "0x100000000000000000000000000000000",
        "0x100000000000000000000000000000001",
        "0x1bdadd77306fbd4578d",
        "0x100000000000000000000fffffffffffffffe"
    };

    char carry[100] = {
        0, 0, 0, 0, 0, 0, 0, 0
    };

    uint32_t number_of_tests = 16;
    uint32_t i = 0;
    bool pass = false;
    unittest testing = malloc_UnitTest_Module(8);
    while (i < number_of_tests) {
        pass = unittest_uint256_addition(inputs[i], inputs[i + 1], outputs[i / 2], carry[i / 2]);
        testing.update(&testing, pass);
        i += 2;
    }
    testing.finalize(&testing);
    testing.free(&testing);
}

void run_tests() {

    enum PrintColors test_colors = bright_magenta;

    printlnc("1. bigint uint128_t declaration test.", test_colors);
    test_uint128_init();
    printlnc("2. bigint uint256_t declaration test.", test_colors);
    test_uint256_init();
    printlnc("3. bigint uint512_t declaration test.", test_colors);
    test_uint512_init();
    printlnc("4. bigint uint1024_t declaration test.", test_colors);
    test_uint1024_init();
    printlnc("5. bigint uint2048_t declaration test.", test_colors);
    test_uint2048_init();
    printlnc("6. bigint uint128_t addition test:", test_colors);
    test_uint128_addition();
    printlnc("7. bigint uint256_t addition test.", test_colors);
    test_uint256_addition();

}