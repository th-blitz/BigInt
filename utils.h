#ifndef utils_H
#define utils_H

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

#endif