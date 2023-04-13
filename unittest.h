#ifndef unittest_H
#define unittest_H



#include <stdint.h>

typedef struct unittest {
    uint64_t count;
    uint64_t total_tests;
    void (*reset)(struct unittest*);
    void (*update)(struct unittest*, bool pass_or_fail);
    void (*finalize)(struct unittest*);
    void (*free)(struct unittest*);
    uint64_t passes;
    uint64_t fails;
    uint8_t* tests;
} unittest;



void run_tests();

#endif