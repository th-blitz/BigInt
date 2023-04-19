# A BigInt library in C

- My project to build the best BigInt library focused on *``` design ```* (ease of use) and *``` high performance ```*.
- Available uint types are ``` uint128_t ```, ``` uint256_t ```, ``` uint512_t ```, ``` uint1024_t ``` and ``` uint2048_t ```.
- All uint types are stored on *``` stack memory ```* by default for the *``` best performance ```*. 

# Examples

### 1. Calculate 300 factorial using uint2048.
```c

#include "BigInt.h"


int main() {

    BigInt bigint = BigIntModule();

    uint2048_t a = bigint.u2048_from_string("01", 2); // Declare a uint2048 variable initialized to value 1.
    unsigned int N = 300;

    while (N > 1) {
        bigint.multiply_by_n(&a, N, &a, a.type); // bigint.multiply_by_n() method to multiply bigint types with unsigned 32 bit integers.
        N -= 1;
    }

    bigint.print(&a, a.type); // prints the result in hexadecimal (base10 print format yet to be implemented).

    return 0;
}
```
**Output:**
```sh
026ca8439285c67e3b9e32731120f78b66f85612a4dd1df6c1d2c69a2d7685f85e75b82bf36e22dcb6ca5044f43fef0b3316049241c821e1ec1c63f95685931f87152ced4befc5ddf7b76719a636f68e7054bf28b57d54d40975ab14d65900681c49044d1725031edbf3c1c5c595b871d6864c371b0cc54ef19d42ad02833bcaf5fb1671b523a143b132c7e1971f7bf5ca77505c960f14b330e6c90dc2539431329ef78a1e9f26b2ead7d28a622e6b586bcee22bd0a495442c6a1235588988252cbd4d36975560fb8e7e5c8cf06f29aeb68659c5cb4cf8d011375b00000000000000000000000000000000000000000000000000000000000000000000000000
```

### 2. Calculate 536 factorial using 2 uint2048 variables.
```c

#include "BigInt.h"


int main() {

    BigInt bigint = BigIntModule();

    uint2048_t a = bigint.u2048_from_string("01", 2);
    uint2048_t b = bigint.u2048(); // using 2 uint2048 as digits to represent one 4096 bit int as 2 digit uint2048 ints.
    unsigned int N = 536;
    unsigned int carry_a = 0;
    unsigned int carry_b = 0;

    while (N > 1) {
        carry_a = bigint.multiply_by_n(&a, N, &a, a.type); // same as { ba x N } where ba is nothing but one 4096 bit int represented as 2 2048 bit int digits. 
        carry_b = bigint.multiply_by_n(&b, N, &b, b.type); // eg: 98 x 2 .. where 9 and 8 can be thought of as uint2048 ints and 2 as an unsigned 32 bit int.
        bigint.add_by_n(&b, carry_a, &b, b.type); 
        if (carry_b > 0) {
            printf("overflow\n");
        }
        N -= 1;
    }
    bigint.print(&b, b.type); // b is MSB and a is LSB.
    bigint.print(&a, a.type);

    return 0;
}
```
**Output:**
```sh
0ffb1f702086548f51cf4de42574c8d73bb1b404ad975927b72884f1d80672bfe61ad8adfe7721a4fc7d8854fd37c17e891a9d90e18974c3fb9a690950dd518d7459377443610e2c61546d7c4a0b13945023ba8905d7081bda4677bbcbf8fd9958235da23c44a031b40652abeddeeb99ffe11aacbd440086d7086e78f47f4c656ba89f60cc1ba36943a9b5deccb74b40cfe9fcfc640876bd2598ab6113228c021a71dca583485f7901947be9564fd40e51279ac7b25536421e4d39a860b2304f01a1cad593cc918c5b839f2676ba8741198a7ba43491ecebd1fae1ebbf750cf4f5fe9df70dcf8174103407f2270438fde8057750ec238e60989c7096c452b0b8
264736f89755064f950c281e1a6fa6b78fd8e12ce85ad9c1dcbb9fff7ba3a385ab4bf05a513f0b3685fc3a126fe696dad6236778b3a5c430d74ecf65d960cecf16a399cb4207e6d4da3b67df3e35a6e42d723cf28b804d4fbe1c8b780e51daafa84c219a58b536391a90192dd09035f42f0cfa332d617e764b82c4df26f2f1f5071579ccf2182526c05f07a29a02a71e8f7404ea7cb6acbd8a2ccf9c8fce6107a529f70ec42d367d4061ab230802f52de71805271f743024c940ab4a95a0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
```


### 3. Calculate 1000 factorial using 5 uint2048 variables.
```c

#include "BigInt.h"


int main() {

    BigInt bigint = BigIntModule();
    
    // An uint2048 array of length 5.
    uint2048_t a_large_num[5]; // a (5 * 2048 = 10,240) bit integer represented as 5 2048 bit int digits.
    
    a_large_num[4] = bigint.u2048_from_string("01", 2); // Initialize the least significant digit as 1.
    for (int i = 3; i > -1; i--) {
        a_large_num[i] = bigint.u2048(); // Initialize the rest of the digits as zeros.
    }

    unsigned int N = 1000;
    unsigned int carry_a = 0;
    unsigned int carry_b = 0;

    while (N > 1) {
        //                                                                                                       1223 (carry) 
        // Below is same as arithmetic multiplication using carrys for a 5 digit number as 12345 x 6 = 74070 i.e 12345 (uint2048 [5]) x 6 (N)
        //                                                                                                       74070 (Result as in uint2048 [5])
        for (int i = 4; i > -1; i--) {
            carry_b = bigint.multiply_by_n(&a_large_num[i], N, &a_large_num[i], uint2048);
            bigint.add_by_n(&a_large_num[i], carry_a, &a_large_num[i], uint2048);
            carry_a = carry_b;
        }
        if (carry_a > 0) {
            printf("overflow \n");
        }
        N -= 1;
    }
    
    // Printing in reverse from the Most significant digit to Least significant digit.
    for (int i = 0; i < 5; i++) { 
        bigint.print(&a_large_num[i], uint2048); 
    }

    return 0;
}
```
**Output:**
```sh
0002a2a773338969b740de6e2b291fd8dd6ee62a2b41525ab61cbe52489b6cf344c23231711b6d9f34e0f13a
b50eaf1ad3dd92771ec26b4b9ea80411c866b1ccbd855f8326edab10832755e1682d3e7a91335e3670329bc1571b5208d72f7d6be81483a6e6708abf913b789f41838e9a73c1ba82e3a956570405a660a17e1125838bc810c8d2c63915481914ea202867a563a41b6aefef5feac300a78803a30eb995208842ebeba8729397a8cd9087e28fb155a3de0f18dd90e64a9293af6487a5aabdab855fa254fcbdc9f1116060bc2e2b4410e55e7368b844d9bf0aeca92deb017def69af777e8d4edb1f1b926ae01df3366abb9e4568fc08fe255b68bca0e48382a8e6df1c7b0ba33bc2225cc512b39176a26b13098e733e51417224be36fbd933a8a7d98a08f356cf01
0f0fc59b9f1e32d3fb43209a82fa0e7f69e302fcb0f20362b86cbbeb08b81b1ba07f08ab119ce5e092d09996b710588779327d91ee80eb679a99f0fdca7eb4a50ef174295e94d590e3cf8bf37d23e5b22dcd79a4ac2c1ea7d1d55170789fcd2fcbb3ea52ead4f7116f862578f5e22421c90cd0a7ee095903150631f27305191429a54cace66dd076c51a94034b31bebec406ee460181225e03a9a22c51e6a2a8db4a94fd352605115caf251b14df0cec523c48b79b58b0fc0676792d38a0d61523eb75f5cbc33ebda1b19933878ce7050356bd228ce9327a9916f9ff3bb5b6beedfe5382b861d6c4da52a9754b6feec8a99372b43afa7808836d281c5b2cdf79
1cf76d6c737aad32c5ed7475855fc15c3f45c4705dd0d6b4078656d027cfee6f37772e03c35c0dcbbdaa25ea64d6865c87cac0a9a999eb88d7a16515811a77192071189c353c1e72242a4f3106cef2bad1075549b4efd6885690f3f58c1f4686951cc543118428ec653e3c6fbdb427930f624680672c1e70c25db7e7b67016a95b30dba56d0083759eac93a8e4d0c54853aa43f197b96fd70696ae5750d7d1f0427b8dbcfafc8b9924d51340fbf71bc22780fba76525f5e5b91a2461983b60bf087dfdd89dcbc6f7892d9e4c5d55d106d45f77e4fc1c44a376d693bfb8b160f12ed1bdf5f4f1127e61d9dec2dc1bba43a6ff47d294de7a67cdf3ef9093766709
2517e985642d195031c6f5339c1cea607a699c55e75c5479cbd30ddaccab307472aa67a6a9a547d7e1eba123144193e6d2933556ddeb516151eacf0b48ce08892236abfb74bf0cee3a0e45997301027f2a53990697694f14de4fac0c908eeaeedf3dbb45c4ce9f744fef88ec1068c52056b16da099e1fb620bd90de25534b5e820b367a400000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
```



# BigInt Documentation
 ### 1. **Import the BigInt module :**
```c

#include "BigInt.h"

int main() {
  // Import the BigInt module as a "BigInt" variable inside main:
  BigInt bigint = BigIntModule();

  return 0;
}
```
- *This is to make sure all bigint functions are easily available under one wrapper.*
- *This will provide better auto suggestions by IDEs and also will be easier to implement user defined custom functions.*

### 2. **To create a 128 bit unsigned integer initialized to zero by default use :**
### **The ``` .u128( void ) ``` method.**
```c

uint128_t a = bigint.u128();
uint128_t b = bigint.u128();

bigint.print(&a, a.type);
bigint.print(&b, b.type);
```
*Here we are passing the bigints a and b as references only (ie &a and &b) instead of passing the whole varibales (ie a and b). (passing their addresses only instead of copying the whole variables into the function for better performance and memory management)*

**Output:**
```sh
00000000
00000000
```

### 3. **To create a 128 bit unsigend integer from a string use :**
### **The ``` .u128_from_string( char* str , int str_len ) ``` method.**
```c

uint128_t c = bigint.u128_from_string("9037208479874057835479", 22);
uint128_t d = bigint.u128_from_string("0x1e9e8762f43491d13d7", 21);
uint128_t e = bigint.u128_from_string("0b1111010011110100001110110001011110100001101001001000111010001001111010111", 75);

bigint.print(&c, uint128); // can also be written as "bigint.print(&c, c.type)".
bigint.print(&d, uint128); 
bigint.print(&e, e.type); // The e.type, c.type and d.type are nothing by uint128 enums.
```
*The above method supports all three string formats: base10, hexadecimal ( must start with 0x ) and binary ( also must start with 0b ).*

**Output :**
```sh
000001e9e8762f43491d13d7
000001e9e8762f43491d13d7
000001e9e8762f43491d13d7
```

### 4. **To add two bigint integers use :**
### **The ``` .add( uint128_t* a, uint128_t* b, uint128_t* output, BigIntType type ) ``` method.**
```c

uint128_t output = bigint.u128();
uint32_t carry = bigint.add(&c, &d, &output, uint128); // OR can also be written as "bigint.add(&c, &d, &output, output.type)".

bigint.print(&output, output.type);

```
**Output :**
```sh
000003d3d0ec5e86923a27ae
```
