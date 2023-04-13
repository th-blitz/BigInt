#ifndef unittest_H
#define unittest_H



#include <stdint.h>

typedef struct unittest {
    uint64_t count;
    uint64_t total_tests;
} unittest;



void run_tests();

#endif