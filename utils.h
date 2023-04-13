#ifndef utils_H
#define utils_H


#include <stdbool.h>
#include <stdint.h>


enum PrintColors {
    reset = 0,
    red,
    green,
    yellow,
    blue,
    magenta,
    cyan,
    white,
    bright_black,
    bright_red,
    bright_green,
    bright_yellow,
    bright_blue,
    bright_magenta,
    bright_cyan,
    bright_white,
};


void println(char* string);
void printlnc(char* string, enum PrintColors color);
void print(char* string, enum PrintColors colors);
bool hex_string_compare(char* s1, char* s2);
void printint(uint64_t i);
void printlnint(uint64_t i);
void printchar(char a, enum PrintColors color);
void printc(enum PrintColors colors);
void printintc(uint64_t i, enum PrintColors color); 

#endif