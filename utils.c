#include <stdio.h>
#include <string.h>
#include <stdint.h>


#include "utils.h"


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


void println(char* string) {
    for (uint64_t i = 0; i < strlen(string); i++) {
        printf("%c", string[i]);
    }
    printf("\n");
}

void printlnc(char* string, enum PrintColors color) {
    print(string, color);
    println("");
}


void print(char* string, enum PrintColors colors) {
    
    switch (colors) {
        case 0:
            printf(ANSI_COLOR_RESET);
            break;
        case 1:
            printf(ANSI_COLOR_RED);
            break;
        case 2:
            printf(ANSI_COLOR_GREEN);
            break;
        case 3:
            printf(ANSI_COLOR_YELLOW);
            break;
        case 4:
            printf(ANSI_COLOR_BLUE);
            break;
        case 5:
            printf(ANSI_COLOR_MAGENTA);
            break;
        case 6:
            printf(ANSI_COLOR_CYAN);
            break;
        default:
            break;
    }
    
    
    for (uint64_t i = 0; i < strlen(string); i++) {
        printf("%c", string[i]);
    }
    printf(ANSI_COLOR_RESET);
}