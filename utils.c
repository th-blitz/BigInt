#include <stdio.h>
#include <string.h>
#include <stdint.h>



void println(char* string) {
    for (uint64_t i = 0; i < strlen(string); i++) {
        printf("%c", string[i]);
    }
    printf("\n");
}