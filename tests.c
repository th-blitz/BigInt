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
static char* uint128_MAX_hex = "0xffffffffffffffffffffffffffffffff";
static char* uint128_MAX_minus_one = "340282366920938463463374607431768211454";

static char* uint256_MAX = "115792089237316195423570985008687907853269984665640564039457584007913129639935";
static char* uint256_MAX_hex = "0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff";
static char* uint256_MAX_minus_one = "115792089237316195423570985008687907853269984665640564039457584007913129639934";


static char* uint512_MAX = "13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084095";
static char* uint512_MAX_hex = "0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff";
static char* uint512_MAX_minus_one = "13407807929942597099574024998205846127479365820592393377723561443721764030073546976801874298166903427690031858186486050853753882811946569946433649006084094";


static char* uint1024_MAX = "179769313486231590772930519078902473361797697894230657273430081157732675805500963132708477322407536021120113879871393357658789768814416622492847430639474124377767893424865485276302219601246094119453082952085005768838150682342462881473913110540827237163350510684586298239947245938479716304835356329624224137215";
static char* uint1024_MAX_hex = "0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff";
static char* uint1024_MAX_minus_one = "179769313486231590772930519078902473361797697894230657273430081157732675805500963132708477322407536021120113879871393357658789768814416622492847430639474124377767893424865485276302219601246094119453082952085005768838150682342462881473913110540827237163350510684586298239947245938479716304835356329624224137214";


static char* uint2048_MAX = "32317006071311007300714876688669951960444102669715484032130345427524655138867890893197201411522913463688717960921898019494119559150490921095088152386448283120630877367300996091750197750389652106796057638384067568276792218642619756161838094338476170470581645852036305042887575891541065808607552399123930385521914333389668342420684974786564569494856176035326322058077805659331026192708460314150258592864177116725943603718461857357598351152301645904403697613233287231227125684710820209725157101726931323469678542580656697935045997268352998638215525166389437335543602135433229604645318478604952148193555853611059596230655";
static char* uint2048_MAX_hex = "0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff";
static char* uint2048_MAX_minus_one = "32317006071311007300714876688669951960444102669715484032130345427524655138867890893197201411522913463688717960921898019494119559150490921095088152386448283120630877367300996091750197750389652106796057638384067568276792218642619756161838094338476170470581645852036305042887575891541065808607552399123930385521914333389668342420684974786564569494856176035326322058077805659331026192708460314150258592864177116725943603718461857357598351152301645904403697613233287231227125684710820209725157101726931323469678542580656697935045997268352998638215525166389437335543602135433229604645318478604952148193555853611059596230654";


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

void test_uint128_init(unittest* module) {

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
        pass = unittest_uint128_init(inputs[i], outputs[i]);
        module -> update(module, pass);
        i += 1;
    }
}

void test_uint256_init(unittest* testing) {
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
    bool pass = false;


    for (int i = 0; i < number_of_tests; i++) {
        pass = unittest_uint256_init(inputs[i], outputs[i]);
        testing -> update(testing, pass);
    }

}

void test_uint512_init(unittest* testing) {
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
    bool pass = false;


    for (int i = 0; i < number_of_tests; i++) {
        pass = unittest_uint512_init(inputs[i], outputs[i]);
        testing -> update(testing, pass);
    }
}

void test_uint1024_init(unittest* testing) {
    
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
    bool pass = false;

    for (int i = 0; i < number_of_tests; i++) {
        pass = unittest_uint1024_init(inputs[i], outputs[i]);
        testing -> update(testing, pass);
    }
}

void test_uint2048_init(unittest* testing) {
    
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
    bool pass = false;

    for (int i = 0; i < number_of_tests; i++) {
        pass = unittest_uint2048_init(inputs[i], outputs[i]);
        testing -> update(testing, pass);
    }
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

bool unittest_uint512_addition(char* input_string_a, char* input_string_b, char* output_string, uint32_t output_carry) {
    BigInt bigint = BigIntModule();
    uint512_t a = bigint.u512_from_string(input_string_a, strlen(input_string_a));
    uint512_t b = bigint.u512_from_string(input_string_b, strlen(input_string_b));
    uint512_t d = bigint.u512_from_string(output_string, strlen(output_string));
    uint512_t c = bigint.u512();
    uint32_t carry = bigint.add(&a, &b, &c, a.type);
    return ((bigint.compare(&c, &d, d.type) == 0) && carry == output_carry);
}

bool unittest_uint1024_addition(char* input_string_a, char* input_string_b, char* output_string, uint32_t output_carry) {
    BigInt bigint = BigIntModule();
    uint1024_t a = bigint.u1024_from_string(input_string_a, strlen(input_string_a));
    uint1024_t b = bigint.u1024_from_string(input_string_b, strlen(input_string_b));
    uint1024_t d = bigint.u1024_from_string(output_string, strlen(output_string));
    uint1024_t c = bigint.u1024();
    uint32_t carry = bigint.add(&a, &b, &c, a.type);
    return ((bigint.compare(&c, &d, d.type) == 0) && carry == output_carry);
}

bool unittest_uint2048_addition(char* input_string_a, char* input_string_b, char* output_string, uint32_t output_carry) {
    BigInt bigint = BigIntModule();
    uint2048_t a = bigint.u2048_from_string(input_string_a, strlen(input_string_a));
    uint2048_t b = bigint.u2048_from_string(input_string_b, strlen(input_string_b));
    uint2048_t d = bigint.u2048_from_string(output_string, strlen(output_string));
    uint2048_t c = bigint.u2048();
    uint32_t carry = bigint.add(&a, &b, &c, a.type);
    return ((bigint.compare(&c, &d, d.type) == 0) && carry == output_carry);
}


void test_uint128_addition(unittest* testing) {

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
    while (i < number_of_tests) {
        pass = unittest_uint128_addition(inputs[i], inputs[i + 1], outputs[i / 2], carry[i / 2]);
        testing -> update(testing, pass);
        i += 2;
    }
}

void test_uint256_addition(unittest* testing) {

    char* inputs[100] = {
        "000", "000",
        "000", "0001",
        "0001", "0001",
        "0007987", "0x8ab423",
        uint256_MAX, "0001",
        uint256_MAX, "0b00010",
        "8217834017289347038978", "3493702873789749387",
        "0xffffffffffffffff", "0xffffffffffffffffffffffffffffffffffff"
    };
                            
    char* outputs[100] = {
        "000",
        "001",
        "002",
        "0x8ad356",
        "0x0000000000000000000000000000",
        "0x00000000000000000000000000000001",
        "0x1bdadd77306fbd4578d",
        "0x100000000000000000000fffffffffffffffe"
    };

    char carry[100] = {
        0, 0, 0, 0, 1, 1, 0, 0
    };

    uint32_t number_of_tests = 16;
    uint32_t i = 0;
    bool pass = false;
    while (i < number_of_tests) {
        pass = unittest_uint256_addition(inputs[i], inputs[i + 1], outputs[i / 2], carry[i / 2]);
        testing -> update(testing, pass);
        i += 2;
    }
}



void test_uint512_addition(unittest* testing) {

    char* inputs[100] = {
        "000", "000",
        "000", "0001",
        "0001", "0001",
        "0007987", "0x8ab423",
        uint512_MAX, "0001",
        "0xffffffffffffffffffffffffffffffff", "0b00010",
        "8217834017289347038978", "3493702873789749387",
        "0xffffffffffffffff", "0xffffffffffffffffffffffffffffffffffff"
    };
                            
    char* outputs[100] = {
        "000",
        "001",
        "002",
        "0x8ad356",
        "0x0000000000000000000000000000",
        "0x100000000000000000000000000000001",
        "0x1bdadd77306fbd4578d",
        "0x100000000000000000000fffffffffffffffe"
    };

    char carry[100] = {
        0, 0, 0, 0, 1, 0, 0, 0
    };

    uint32_t number_of_tests = 16;
    uint32_t i = 0;
    bool pass = false;
    while (i < number_of_tests) {
        pass = unittest_uint512_addition(inputs[i], inputs[i + 1], outputs[i / 2], carry[i / 2]);
        testing -> update(testing, pass);
        i += 2;
    }
}



void test_uint1024_addition(unittest* testing) {

    char* inputs[100] = {
        "000", "000",
        "000", "0001",
        "0001", "0001",
        "0007987", "0x8ab423",
        uint1024_MAX, "0001",
        "0xffffffffffffffffffffffffffffffff", "0b00010",
        "8217834017289347038978", "3493702873789749387",
        "0xffffffffffffffff", "0xffffffffffffffffffffffffffffffffffff"
    };
                            
    char* outputs[100] = {
        "000",
        "001",
        "002",
        "0x8ad356",
        "0x0000000000000000000000000000",
        "0x100000000000000000000000000000001",
        "0x1bdadd77306fbd4578d",
        "0x100000000000000000000fffffffffffffffe"
    };

    char carry[100] = {
        0, 0, 0, 0, 1, 0, 0, 0
    };

    uint32_t number_of_tests = 16;
    uint32_t i = 0;
    bool pass = false;
    while (i < number_of_tests) {
        pass = unittest_uint1024_addition(inputs[i], inputs[i + 1], outputs[i / 2], carry[i / 2]);
        testing -> update(testing, pass);
        i += 2;
    }
}



void test_uint2048_addition(unittest* testing) {

    char* inputs[100] = {
        "000", "000",
        "000", "0001",
        "0001", "0001",
        "0007987", "0x8ab423",
        uint2048_MAX, "0001",
        "0xffffffffffffffffffffffffffffffff", "0b00010",
        "8217834017289347038978", "3493702873789749387",
        "0xffffffffffffffff", "0xffffffffffffffffffffffffffffffffffff",
        uint2048_OVERFLOW, uint2048_MAX,
        uint2048_MAX, "0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe"
    };
                            
    char* outputs[100] = {
        "000",
        "001",
        "002",
        "0x8ad356",
        "0x0000000000000000000000000000",
        "0x100000000000000000000000000000001",
        "0x1bdadd77306fbd4578d",
        "0x100000000000000000000fffffffffffffffe",
        uint2048_MAX,
        "0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffd"
    };

    char carry[100] = {
        0, 0, 0, 0, 1, 0, 0, 0, 0, 1
    };

    uint32_t number_of_tests = 20;
    uint32_t i = 0;
    bool pass = false;
    while (i < number_of_tests) {
        pass = unittest_uint2048_addition(inputs[i], inputs[i + 1], outputs[i / 2], carry[i / 2]);
        testing -> update(testing, pass);
        i += 2;
    }
}

bool unittest_u128_compare(char* input_a, char* input_b, int output) {
    BigInt bigint = BigIntModule();
    uint128_t a = bigint.u128_from_string(input_a, strlen(input_a));
    uint128_t b = bigint.u128_from_string(input_b, strlen(input_b));
    return bigint.compare(&a, &b, a.type) == output;
}

bool unittest_u256_compare(char* input_a, char* input_b, int output) {
    BigInt bigint = BigIntModule();
    uint256_t a = bigint.u256_from_string(input_a, strlen(input_a));
    uint256_t b = bigint.u256_from_string(input_b, strlen(input_b));
    return bigint.compare(&a, &b, a.type) == output;
}

bool unittest_u1024_compare(char* input_a, char* input_b, int output) {
    BigInt bigint = BigIntModule();
    uint1024_t a = bigint.u1024_from_string(input_a, strlen(input_a));
    uint1024_t b = bigint.u1024_from_string(input_b, strlen(input_b));
    return bigint.compare(&a, &b, a.type) == output;
}

bool unittest_u512_compare(char* input_a, char* input_b, int output) {
    BigInt bigint = BigIntModule();
    uint512_t a = bigint.u512_from_string(input_a, strlen(input_a));
    uint512_t b = bigint.u512_from_string(input_b, strlen(input_b));
    return bigint.compare(&a, &b, a.type) == output;
}

bool unittest_u2048_compare(char* input_a, char* input_b, int output) {
    BigInt bigint = BigIntModule();
    uint2048_t a = bigint.u2048_from_string(input_a, strlen(input_a));
    uint2048_t b = bigint.u2048_from_string(input_b, strlen(input_b));
    return bigint.compare(&a, &b, a.type) == output;
}

void test_uint128_compare(unittest * module) {
    char* inputs[100] = {
        "000", "000",
        "0001", "0001",
        uint128_MAX, uint128_MAX,
        uint128_OVERFLOW, uint128_MAX,
        "0020", uint128_MAX,
        uint128_MAX, uint128_MAX_minus_one
    };

    int outputs[100] = {
        0, 
        0,
        0,
        -1,
        -1,
        1,
    };

    int number_of_tests = 12;
    for (int i = 0; i < number_of_tests; i += 2) {
        module -> update(module, unittest_u128_compare(inputs[i], inputs[i + 1], outputs[i / 2]));
    }
}

void test_uint256_compare(unittest * module) {
    char* inputs[100] = {
        "000", "000",
        "0001", "0001",
        uint256_MAX, uint256_MAX,
        uint256_OVERFLOW, uint256_MAX,
        "0020", uint256_MAX,
        uint256_MAX, uint256_MAX_minus_one
    };

    int outputs[100] = {
        0, 
        0,
        0,
        -1,
        -1,
        1,
    };

    int number_of_tests = 12;
    for (int i = 0; i < number_of_tests; i += 2) {
        module -> update(module, unittest_u256_compare(inputs[i], inputs[i + 1], outputs[i / 2]));
    }
}

void test_uint512_compare(unittest * module) {
    char* inputs[100] = {
        "000", "000",
        "0001", "0001",
        uint512_MAX, uint512_MAX,
        uint512_OVERFLOW, uint512_MAX,
        "0020", uint512_MAX,
        uint512_MAX, uint512_MAX_minus_one
    };

    int outputs[100] = {
        0, 
        0,
        0,
        -1,
        -1,
        1,
    };

    int number_of_tests = 12;
    for (int i = 0; i < number_of_tests; i += 2) {
        module -> update(module, unittest_u512_compare(inputs[i], inputs[i + 1], outputs[i / 2]));
    }
}

void test_uint1024_compare(unittest * module) {
    char* inputs[100] = {
        "000", "000",
        "0001", "0001",
        uint1024_MAX, uint1024_MAX,
        uint1024_OVERFLOW, uint1024_MAX,
        "0020", uint1024_MAX,
        uint1024_MAX, uint1024_MAX_minus_one
    };

    int outputs[100] = {
        0, 
        0,
        0,
        -1,
        -1,
        1,
    };

    int number_of_tests = 12;
    for (int i = 0; i < number_of_tests; i += 2) {
        module -> update(module, unittest_u1024_compare(inputs[i], inputs[i + 1], outputs[i / 2]));
    }
}

void test_uint2048_compare(unittest* module) {
    char* inputs[100] = {
        "000", "000",
        "0001", "0001",
        uint2048_MAX_hex, uint2048_MAX_hex,
        uint2048_OVERFLOW, uint2048_MAX_hex,
        "0020", uint2048_MAX_hex,
        uint2048_MAX_hex, uint2048_MAX_minus_one
    };

    int outputs[100] = {
        0, 
        0,
        0,
        -1,
        -1,
        1,
    };

    int number_of_tests = 12;
    for (int i = 0; i < number_of_tests; i += 2) {
        module -> update(module, unittest_u2048_compare(inputs[i], inputs[i + 1], outputs[i / 2]));
    }
}


bool unittest_u128_subtract(char* input_a, char* input_b, char* output, uint32_t borrow) {
    BigInt bigint = BigIntModule();
    uint128_t a = bigint.u128_from_string(input_a, strlen(input_a));
    uint128_t b = bigint.u128_from_string(input_b, strlen(input_b));
    uint128_t c = bigint.u128_from_string(output, strlen(output));
    uint32_t borr = bigint.subtract(&a, &b, &a, c.type);
    return (bigint.compare(&c, &a, a.type) == 0) && (borr == borrow);
}

bool unittest_u256_subtract(char* input_a, char* input_b, char* output, uint32_t borrow) {
    BigInt bigint = BigIntModule();
    uint256_t a = bigint.u256_from_string(input_a, strlen(input_a));
    uint256_t b = bigint.u256_from_string(input_b, strlen(input_b));
    uint256_t c = bigint.u256_from_string(output, strlen(output));
    uint32_t borr = bigint.subtract(&a, &b, &a, c.type);
    return (bigint.compare(&c, &a, a.type) == 0) && (borr == borrow);
}

bool unittest_u512_subtract(char* input_a, char* input_b, char* output, uint32_t borrow) {
    BigInt bigint = BigIntModule();
    uint512_t a = bigint.u512_from_string(input_a, strlen(input_a));
    uint512_t b = bigint.u512_from_string(input_b, strlen(input_b));
    uint512_t c = bigint.u512_from_string(output, strlen(output));
    uint32_t borr = bigint.subtract(&a, &b, &a, c.type);
    return (bigint.compare(&c, &a, a.type) == 0) && (borr == borrow);
}

bool unittest_u1024_subtract(char* input_a, char* input_b, char* output, uint32_t borrow) {
    BigInt bigint = BigIntModule();
    uint1024_t a = bigint.u1024_from_string(input_a, strlen(input_a));
    uint1024_t b = bigint.u1024_from_string(input_b, strlen(input_b));
    uint1024_t c = bigint.u1024_from_string(output, strlen(output));
    uint32_t borr = bigint.subtract(&a, &b, &a, c.type);
    return (bigint.compare(&c, &a, a.type) == 0) && (borr == borrow);
}

bool unittest_u2048_subtract(char* input_a, char* input_b, char* output, uint32_t borrow) {
    BigInt bigint = BigIntModule();
    uint2048_t a = bigint.u2048_from_string(input_a, strlen(input_a));
    uint2048_t b = bigint.u2048_from_string(input_b, strlen(input_b));
    uint2048_t c = bigint.u2048_from_string(output, strlen(output));
    uint32_t borr = bigint.subtract(&a, &b, &a, c.type);
    return (bigint.compare(&c, &a, a.type) == 0) && (borr == borrow);
}

void test_u128_subtract(unittest* module) {
    char* inputs[100] = {
        uint128_MAX, "0001",
        "002", uint128_MAX,
        "0000", "001",
        "0101000", "999",
        "0x100000000100000000", "0xffffffff"

    };

    char* outputs[100] = {
        uint128_MAX_minus_one,
        "0003",
        uint128_MAX,
        "100001",
        "0x100000000000000001"
    };

    uint32_t borrow[100] = {
        0,
        1,
        1,
        0,
        0
    };

    int number_of_tests = 10;
    for (int i = 0; i < number_of_tests; i += 2) {
        module -> update(module, unittest_u128_subtract(inputs[i], inputs[i + 1], outputs[i / 2], borrow[i / 2]));
    }
}

void test_u256_subtract(unittest* module) {
    char* inputs[100] = {
        uint256_MAX, "0001",
        "002", uint256_MAX,
        "0000", "001",
        "0101000", "999",
        "0x100000000100000000", "0xffffffff"

    };

    char* outputs[100] = {
        uint256_MAX_minus_one,
        "0003",
        uint256_MAX,
        "100001",
        "0x100000000000000001"
    };

    uint32_t borrow[100] = {
        0,
        1,
        1,
        0,
        0
    };

    int number_of_tests = 10;
    for (int i = 0; i < number_of_tests; i += 2) {
        module -> update(module, unittest_u256_subtract(inputs[i], inputs[i + 1], outputs[i / 2], borrow[i / 2]));
    }
}

void test_u512_subtract(unittest* module) {
    char* inputs[100] = {
        uint512_MAX, "0001",
        "002", uint512_MAX,
        "0000", "001",
        "0101000", "999",
        "0x100000000100000000", "0xffffffff"

    };

    char* outputs[100] = {
        uint512_MAX_minus_one,
        "0003",
        uint512_MAX,
        "100001",
        "0x100000000000000001"
    };

    uint32_t borrow[100] = {
        0,
        1,
        1,
        0,
        0
    };

    int number_of_tests = 10;
    for (int i = 0; i < number_of_tests; i += 2) {
        module -> update(module, unittest_u512_subtract(inputs[i], inputs[i + 1], outputs[i / 2], borrow[i / 2]));
    }
}

void test_u1024_subtract(unittest* module) {
    char* inputs[100] = {
        uint1024_MAX, "0001",
        "002", uint1024_MAX,
        "0000", "001",
        "0101000", "999",
        "0x100000000100000000", "0xffffffff"

    };

    char* outputs[100] = {
        uint1024_MAX_minus_one,
        "0003",
        uint1024_MAX,
        "100001",
        "0x100000000000000001"
    };

    uint32_t borrow[100] = {
        0,
        1,
        1,
        0,
        0
    };

    int number_of_tests = 10;
    for (int i = 0; i < number_of_tests; i += 2) {
        module -> update(module, unittest_u1024_subtract(inputs[i], inputs[i + 1], outputs[i / 2], borrow[i / 2]));
    }
}

void test_u2048_subtract(unittest* module) {
    char* inputs[100] = {
        uint2048_MAX, "0001",
        "002", uint2048_MAX,
        "0000", "001",
        "0101000", "999",
        "0x100000000100000000", "0xffffffff"

    };

    char* outputs[100] = {
        uint2048_MAX_minus_one,
        "0003",
        uint2048_MAX,
        "100001",
        "0x100000000000000001"
    };

    uint32_t borrow[100] = {
        0,
        1,
        1,
        0,
        0
    };

    int number_of_tests = 10;
    for (int i = 0; i < number_of_tests; i += 2) {
        module -> update(module, unittest_u2048_subtract(inputs[i], inputs[i + 1], outputs[i / 2], borrow[i / 2]));
    }
}


bool unittest_u128_multiply_by_n(char* input, uint32_t n, char* output, uint32_t output_n) {
    BigInt bigint = BigIntModule();
    uint128_t a = bigint.u128_from_string(input, strlen(input));
    uint128_t b = bigint.u128_from_string(output, strlen(output));
    uint32_t out = bigint.multiply_by_n(&a, n, &a, a.type);
    return (out == output_n) && (bigint.compare(&a, &b, a.type) == 0);
}

bool unittest_u256_multiply_by_n(char* input, uint32_t n, char* output, uint32_t output_n) {
    BigInt bigint = BigIntModule();
    uint256_t a = bigint.u256_from_string(input, strlen(input));
    uint256_t b = bigint.u256_from_string(output, strlen(output));
    uint32_t out = bigint.multiply_by_n(&a, n, &a, a.type);
    return (out == output_n) && (bigint.compare(&a, &b, a.type) == 0);
}

bool unittest_u1024_multiply_by_n(char* input, uint32_t n, char* output, uint32_t output_n) {
    BigInt bigint = BigIntModule();
    uint1024_t a = bigint.u1024_from_string(input, strlen(input));
    uint1024_t b = bigint.u1024_from_string(output, strlen(output));
    uint32_t out = bigint.multiply_by_n(&a, n, &a, a.type);
    return (out == output_n) && (bigint.compare(&a, &b, a.type) == 0);
}

bool unittest_u512_multiply_by_n(char* input, uint32_t n, char* output, uint32_t output_n) {
    BigInt bigint = BigIntModule();
    uint512_t a = bigint.u512_from_string(input, strlen(input));
    uint512_t b = bigint.u512_from_string(output, strlen(output));
    uint32_t out = bigint.multiply_by_n(&a, n, &a, a.type);
    return (out == output_n) && (bigint.compare(&a, &b, a.type) == 0);
}

bool unittest_u2048_multiply_by_n(char* input, uint32_t n, char* output, uint32_t output_n) {
    BigInt bigint = BigIntModule();
    uint2048_t a = bigint.u2048_from_string(input, strlen(input));
    uint2048_t b = bigint.u2048_from_string(output, strlen(output));
    uint32_t out = bigint.multiply_by_n(&a, n, &a, a.type);
    return (out == output_n) && (bigint.compare(&a, &b, a.type) == 0);
}


void test_u128_multiply_by_n(unittest* module) {

    char* inputs[100] = {
        "7893187237782",
        uint128_MAX,
        uint128_MAX,
        uint128_MAX,
    };
    uint32_t input_n[100] = {
        2,
        2,
        0,
        0xffffffff,
    }; 
    
    char* outputs[100] = {
        "15786374475564",
        uint128_MAX_minus_one,
        "0000",
        "0xffffffffffffffffffffffff00000001",
    };
    uint32_t output_n[100] = {
        0,
        1,
        0,
        0xfffffffe,
    };

    int number_of_tests = 4;
    for (int i = 0; i < number_of_tests; i += 1) {
        module -> update(module, unittest_u128_multiply_by_n(inputs[i], input_n[i], outputs[i], output_n[i]));
    }
}

void test_u256_multiply_by_n(unittest* module) {

    char* inputs[100] = {
        "7893187237782",
        uint256_MAX,
        uint256_MAX,
        uint256_MAX,
    };
    uint32_t input_n[100] = {
        2,
        2,
        0,
        0xffffffff,
    }; 
    
    char* outputs[100] = {
        "15786374475564",
        uint256_MAX_minus_one,
        "0000",
        "0xffffffffffffffffffffffffffffffffffffffffffffffffffffffff00000001",
    };
    uint32_t output_n[100] = {
        0,
        1,
        0,
        0xfffffffe,
    };

    int number_of_tests = 4;
    for (int i = 0; i < number_of_tests; i += 1) {
        module -> update(module, unittest_u256_multiply_by_n(inputs[i], input_n[i], outputs[i], output_n[i]));
    }
}

void test_u1024_multiply_by_n(unittest* module) {

    char* inputs[100] = {
        "7893187237782",
        uint1024_MAX,
        uint1024_MAX,
        uint1024_MAX,
    };
    uint32_t input_n[100] = {
        2,
        2,
        0,
        0xffffffff,
    }; 
    
    char* outputs[100] = {
        "15786374475564",
        uint1024_MAX_minus_one,
        "0000",
        "0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff00000001",
    };
    uint32_t output_n[100] = {
        0,
        1,
        0,
        0xfffffffe,
    };

    int number_of_tests = 4;
    for (int i = 0; i < number_of_tests; i += 1) {
        module -> update(module, unittest_u1024_multiply_by_n(inputs[i], input_n[i], outputs[i], output_n[i]));
    }
}

void test_u512_multiply_by_n(unittest* module) {

    char* inputs[100] = {
        "7893187237782",
        uint512_MAX,
        uint512_MAX,
        uint512_MAX,
    };
    uint32_t input_n[100] = {
        2,
        2,
        0,
        0xffffffff,
    }; 
    
    char* outputs[100] = {
        "15786374475564",
        uint512_MAX_minus_one,
        "0000",
        "0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff00000001",
    };
    uint32_t output_n[100] = {
        0,
        1,
        0,
        0xfffffffe,
    };

    int number_of_tests = 4;
    for (int i = 0; i < number_of_tests; i += 1) {
        module -> update(module, unittest_u512_multiply_by_n(inputs[i], input_n[i], outputs[i], output_n[i]));
    }
}

void test_u2048_multiply_by_n(unittest* module) {

    char* inputs[100] = {
        "7893187237782",
        uint2048_MAX,
        uint2048_MAX,
        uint2048_MAX,
    };
    uint32_t input_n[100] = {
        2,
        2,
        0,
        0xffffffff,
    }; 
    
    char* outputs[100] = {
        "15786374475564",
        uint2048_MAX_minus_one,
        "0000",
        "0xffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff00000001",
    };
    uint32_t output_n[100] = {
        0,
        1,
        0,
        0xfffffffe,
    };

    int number_of_tests = 4;
    for (int i = 0; i < number_of_tests; i += 1) {
        module -> update(module, unittest_u2048_multiply_by_n(inputs[i], input_n[i], outputs[i], output_n[i]));
    }
}

bool unittest_u128_multiplication(char* input_a, char* input_b, char* output) {
    BigInt bigint = BigIntModule();
    uint128_t a = bigint.u128_from_string(input_a, strlen(input_a));
    uint128_t b = bigint.u128_from_string(input_b, strlen(input_b));
    uint256_t d = bigint.u256_from_string(output, strlen(output));
    uint256_t c = bigint.u256();
    bigint.multiply(&a, &b, &c, a.type);
    return bigint.compare(&c, &d, d.type) == 0;
}

bool unittest_u256_multiplication(char* input_a, char* input_b, char* output) {
    BigInt bigint = BigIntModule();
    uint256_t a = bigint.u256_from_string(input_a, strlen(input_a));
    uint256_t b = bigint.u256_from_string(input_b, strlen(input_b));
    uint512_t d = bigint.u512_from_string(output, strlen(output));
    uint512_t c = bigint.u512();
    bigint.multiply(&a, &b, &c, a.type);
    return bigint.compare(&c, &d, d.type) == 0;
}

bool unittest_u512_multiplication(char* input_a, char* input_b, char* output) {
    BigInt bigint = BigIntModule();
    uint512_t a = bigint.u512_from_string(input_a, strlen(input_a));
    uint512_t b = bigint.u512_from_string(input_b, strlen(input_b));
    uint1024_t d = bigint.u1024_from_string(output, strlen(output));
    uint1024_t c = bigint.u1024();
    bigint.multiply(&a, &b, &c, a.type);
    return bigint.compare(&c, &d, d.type) == 0;
}

bool unittest_u1024_multiplication(char* input_a, char* input_b, char* output) {
    BigInt bigint = BigIntModule();
    uint1024_t a = bigint.u1024_from_string(input_a, strlen(input_a));
    uint1024_t b = bigint.u1024_from_string(input_b, strlen(input_b));
    uint2048_t d = bigint.u2048_from_string(output, strlen(output));
    uint2048_t c = bigint.u2048();
    bigint.multiply(&a, &b, &c, a.type);
    return bigint.compare(&c, &d, d.type) == 0;
}

void test_u128_multiplication(unittest* module) {
    char* inputs[100] = {
        "3927483274392874329287490283", "08900973027140187379828930371804",
        uint128_MAX, "01",
        uint128_MAX, "00",
        uint128_MAX, uint128_MAX,
    };

    char* outputs[100] = {
        "34958422689915197795547752176903269511406264703693227180532",
        uint128_MAX,
        "00",
        "0xfffffffffffffffffffffffffffffffe00000000000000000000000000000001"
    };

    int number_of_tests = 8;
    for (int i = 0; i < number_of_tests; i += 2) {
        module -> update(module, unittest_u128_multiplication(inputs[i], inputs[i + 1], outputs[i / 2]));
    }
}

void test_u256_multiplication(unittest* module) {
    char* inputs[100] = {
        "3927483274392874329287490283", "08900973027140187379828930371804",
        uint256_MAX, "01",
        uint256_MAX, "00",
        uint256_MAX, uint256_MAX,
    };

    char* outputs[100] = {
        "34958422689915197795547752176903269511406264703693227180532",
        uint256_MAX,
        "00",
        "0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe0000000000000000000000000000000000000000000000000000000000000001"
    };

    int number_of_tests = 8;
    for (int i = 0; i < number_of_tests; i += 2) {
        module -> update(module, unittest_u256_multiplication(inputs[i], inputs[i + 1], outputs[i / 2]));
    }
}

void test_u512_multiplication(unittest* module) {
    char* inputs[100] = {
        "3927483274392874329287490283", "08900973027140187379828930371804",
        uint512_MAX, "01",
        uint512_MAX, "00",
        uint512_MAX, uint512_MAX,
    };

    char* outputs[100] = {
        "34958422689915197795547752176903269511406264703693227180532",
        uint512_MAX,
        "00",
        "0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"
    };

    int number_of_tests = 8;
    for (int i = 0; i < number_of_tests; i += 2) {
        module -> update(module, unittest_u512_multiplication(inputs[i], inputs[i + 1], outputs[i / 2]));
    }
}

void test_u1024_multiplication(unittest* module) {
    char* inputs[100] = {
        "3927483274392874329287490283", "08900973027140187379828930371804",
        uint1024_MAX, "01",
        uint1024_MAX, "00",
        uint1024_MAX, uint1024_MAX,
    };

    char* outputs[100] = {
        "34958422689915197795547752176903269511406264703693227180532",
        uint1024_MAX,
        "00",
        "0xfffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"
    };


    int number_of_tests = 8;
    for (int i = 0; i < number_of_tests; i += 2) {
        module -> update(module, unittest_u1024_multiplication(inputs[i], inputs[i + 1], outputs[i / 2]));
    }
}


void run_tests() {

    enum PrintColors test_colors = bright_magenta;
    unittest testing_module = malloc_UnitTest_Module(20);

    test_uint128_init(&testing_module);
    testing_module.index(&testing_module, "u128 init");

    test_uint256_init(&testing_module);
    testing_module.index(&testing_module, "u256 init");

    test_uint512_init(&testing_module);
    testing_module.index(&testing_module, "u512 init");

    test_uint1024_init(&testing_module);
    testing_module.index(&testing_module, "u1024 init"); 

    test_uint2048_init(&testing_module);
    testing_module.index(&testing_module, "u2048 init"); 

    test_uint128_addition(&testing_module);
    testing_module.index(&testing_module, "u128 addition"); 

    test_uint256_addition(&testing_module);
    testing_module.index(&testing_module, "u256 addition");

    test_uint512_addition(&testing_module);
    testing_module.index(&testing_module, "u512 addition");

    test_uint1024_addition(&testing_module);
    testing_module.index(&testing_module, "u1024 addition");

    test_uint2048_addition(&testing_module);
    testing_module.index(&testing_module, "u2048 addition");

    test_uint128_compare(&testing_module);
    testing_module.index(&testing_module, "u128 comparision");

    test_uint256_compare(&testing_module);
    testing_module.index(&testing_module, "u256 comparision");

    test_uint512_compare(&testing_module);
    testing_module.index(&testing_module, "u512 comparision");

    test_uint1024_compare(&testing_module);
    testing_module.index(&testing_module, "u1024 comparision");

    test_uint2048_compare(&testing_module);
    testing_module.index(&testing_module, "u2048 comparision");

    test_u128_subtract(&testing_module);
    testing_module.index(&testing_module, "u128 subtract");

    test_u256_subtract(&testing_module);
    testing_module.index(&testing_module, "u256 subtract");

    test_u512_subtract(&testing_module);
    testing_module.index(&testing_module, "u512 subtract");

    test_u1024_subtract(&testing_module);
    testing_module.index(&testing_module, "u1024 subtract");

    test_u2048_subtract(&testing_module);
    testing_module.index(&testing_module, "u2048 subtract");

    test_u128_multiply_by_n(&testing_module);
    testing_module.index(&testing_module, "u128 multiply by n");

    test_u256_multiply_by_n(&testing_module);
    testing_module.index(&testing_module, "u256 multiply by n");

    test_u512_multiply_by_n(&testing_module);
    testing_module.index(&testing_module, "u512 multiply by n");

    test_u1024_multiply_by_n(&testing_module);
    testing_module.index(&testing_module, "u1024 multiply by n");

    test_u2048_multiply_by_n(&testing_module);
    testing_module.index(&testing_module, "u2048 multiply by n");
    
    test_u128_multiplication(&testing_module);
    testing_module.index(&testing_module, "u128 mulitply");

    test_u256_multiplication(&testing_module);
    testing_module.index(&testing_module, "u256 mulitply");

    test_u512_multiplication(&testing_module);
    testing_module.index(&testing_module, "u512 mulitply");

    test_u1024_multiplication(&testing_module);
    testing_module.index(&testing_module, "u1024 mulitply");
    
    testing_module.free(&testing_module);
}