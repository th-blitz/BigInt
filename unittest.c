#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>


#include "ByteQueue.h"
#include "utils.h"


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


void run_tests() {
    
    int total_tests = 1;    
    int i = 0;

    println("test 1. bytequeue");
    test_ByteQueue();
    i += 1;
}