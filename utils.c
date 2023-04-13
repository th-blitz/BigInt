#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>


#include "utils.h"

#define MAX(a, b) (a >= b ? a : b)
#define MIN(a, b) (a <= b ? a : b)

// https://chrisyeh96.github.io/2020/03/28/terminal-colors.html
#define ANSI_COLOR_RED     "\x1b[38;2;204;0;0m"
#define ANSI_COLOR_GREEN   "\x1b[38;2;78;154;6m"
#define ANSI_COLOR_YELLOW  "\x1b[38;2;196;160;0m"
#define ANSI_COLOR_BLUE    "\x1b[38;2;114;159;207m"
#define ANSI_COLOR_MAGENTA "\x1b[38;2;117;80;123m"
#define ANSI_COLOR_CYAN    "\x1b[38;2;6;152;154m"
#define ANSI_COLOR_WHITE    "\x1b[38;2;211;215;207m"
#define ANSI_COLOR_BRIGHT_BLACK    "\x1b[38;2;85;87;83m"
#define ANSI_COLOR_BRIGHT_RED    "\x1b[38;2;239;41;41m"
#define ANSI_COLOR_BRIGHT_GREEN    "\x1b[38;2;138;226;52m"
#define ANSI_COLOR_BRIGHT_YELLOW    "\x1b[38;2;252;233;79m"
#define ANSI_COLOR_BRIGHT_BLUE    "\x1b[38;2;50;175;255m"
#define ANSI_COLOR_BRIGHT_MAGENTA    "\x1b[38;2;173;127;168m"
#define ANSI_COLOR_BRIGHT_CYAN    "\x1b[38;2;52;226;226m"
#define ANSI_COLOR_BRIGHT_WHITE    "\x1b[38;2;255;255;255m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void printc(enum PrintColors colors) {
    switch (colors) {
        case 0:
            printf(ANSI_COLOR_RESET);
            break;
        case red:
            printf(ANSI_COLOR_RED);
            break;
        case green:
            printf(ANSI_COLOR_GREEN);
            break;
        case yellow:
            printf(ANSI_COLOR_YELLOW);
            break;
        case blue:
            printf(ANSI_COLOR_BLUE);
            break;
        case magenta:
            printf(ANSI_COLOR_MAGENTA);
            break;
        case cyan:
            printf(ANSI_COLOR_CYAN);
            break;
        case white:
            printf(ANSI_COLOR_WHITE);
            break;
        case bright_black:
            printf(ANSI_COLOR_BRIGHT_BLACK);
            break;
        case bright_red:
            printf(ANSI_COLOR_BRIGHT_RED);
            break;
        case bright_green:
            printf(ANSI_COLOR_BRIGHT_GREEN);
            break;
        case bright_yellow:
            printf(ANSI_COLOR_BRIGHT_YELLOW);
            break;
        case bright_blue:
            printf(ANSI_COLOR_BRIGHT_BLUE);
            break;
        case bright_magenta:
            printf(ANSI_COLOR_BRIGHT_MAGENTA);
            break;
        case bright_cyan:
            printf(ANSI_COLOR_BRIGHT_CYAN);
            break;
        case bright_white:
            printf(ANSI_COLOR_BRIGHT_WHITE);
            break;
        default:
            printf(ANSI_COLOR_RESET);
    }
}

void printint(uint64_t i) {
    printf("%ld", i);
}

void printintc(uint64_t i, enum PrintColors color) {
    printc(color);
    printf("%ld", i);
    printc(white);
} 

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

bool hex_string_compare(char* s1, char* s2) {

    uint64_t s1_len = strlen(s1);
    uint64_t s2_len = strlen(s2);

    uint64_t i = 0;
    while (i < MAX(s1_len, s2_len)) {
        if (((i < s1_len) ? s1[s1_len - i - 1] : '0') != ((i < s2_len) ? s2[s2_len - i - 1] : '0')) {
            return false;
        }
        i += 1;
    }
    return true;
}

void print(char* string, enum PrintColors colors) {
    
    printc(colors);
    
    
    for (uint64_t i = 0; i < strlen(string); i++) {
        printf("%c", string[i]);
    }
    printf(ANSI_COLOR_RESET);
}

void printlnint(uint64_t i) {
    printint(i);
    println("");
}