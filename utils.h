#ifndef utils_H
#define utils_H


#include <stdbool.h>
#include <stdint.h>


enum PrintColors {
    white = 0,
    red,
    green,
    yellow,
    blue,
    magenta,
    cyan,
};


void println(char* string);
void printlnc(char* string, enum PrintColors color);
void print(char* string, enum PrintColors colors);
bool hex_string_compare(char* s1, char* s2);
void printint(uint64_t i);
void printlnint(uint64_t i);
void printchar(char a, enum PrintColors color);

#endif