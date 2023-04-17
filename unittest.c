#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>


#include "utils.h"

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
    
    enum PrintColors whites = bright_white;
    enum PrintColors reds = bright_red;
    enum PrintColors yellows = bright_yellow;
    enum PrintColors greens = bright_green;

    print(" |", bright_cyan);
    print(" tests (", whites);
    if (module -> fails == 0) {
        printintc(module -> passes, greens);
        print("/", whites);
        printintc(module -> count, greens);
        print(") ", whites);
        printlnc("all passed", greens);
    } else if ((module -> fails != 0) && (module -> passes != 0)) {
        printintc(module -> passes, yellows);
        print("/", whites);
        printintc(module -> count, yellows);
        print(") ", whites);
        print("passed", yellows);
        print(" and ", whites);
        print("(", whites);
        printintc(module -> fails, reds);
        print("/", whites);
        printintc(module -> count, reds);
        print(") ", whites);
        printlnc("failed", reds);
        print("  | fails: ", whites);
        for (uint64_t i = 0; i < module -> count; i++) {
            if (module -> tests[i] == 1) {
                printintc(i + 1, yellows);
                print(" ", whites);
            }
        }
        println("");
    } else if (module -> passes == 0) {
        printintc(module -> passes, reds);
        print("/", whites);
        printintc(module -> count, reds);
        print(") ", whites);
        printlnc("passes (all failed)", reds);
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

void unittest_clock(unittest* module) {
    print("|", bright_cyan);
    print(" time: ", bright_white);
    printf("%f", (double)(clock() - (module -> clock_start)) / CLOCKS_PER_SEC);
}

void unittest_index(unittest* module, char* index) {
    module -> index_count += 1;
    print("[", bright_white);
    printintc(module -> index_count, bright_blue);
    print("]", bright_white);
    print(" ", white);
    print(index, white);
    print(" ", white);
    unittest_clock(module);
    unittest_finalize(module);
    unittest_reset(module);
    module -> clock_start = clock();
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
        .index_count = 0,
        .count = 0,
        .total_tests = total_tests,
        .passes = 0,
        .fails = 0,
        .clock_start = clock()
    };
    module.tests = (uint8_t*)malloc(total_tests * sizeof(uint8_t));
    module.reset = unittest_reset;
    module.update = unittest_update;
    module.finalize = unittest_finalize;
    module.free = unittest_free;
    module.index = unittest_index;
    return module;
}


