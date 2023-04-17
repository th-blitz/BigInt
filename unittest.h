#ifndef unittest_H
#define unittest_H



#include <stdint.h>
#include <time.h>

typedef struct unittest {
    uint64_t index_count;
    uint64_t count;
    uint64_t total_tests;
    void (*reset)(struct unittest*);
    void (*update)(struct unittest*, bool pass_or_fail);
    void (*finalize)(struct unittest*);
    void (*free)(struct unittest*);
    void (*index)(struct unittest*, char* index);
    clock_t clock_start;
    uint64_t passes;
    uint64_t fails;
    uint8_t* tests;
} unittest;



unittest malloc_UnitTest_Module(uint64_t number_of_tests);

#endif