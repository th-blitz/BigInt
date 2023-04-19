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
