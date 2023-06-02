#ifndef bigint_parser_H
#define bigint_parser_H

#include <stdint.h>

#include "ByteQueue.h"

typedef enum StringType {
    binary = 2,
    octal = 8,
    decimal = 10,
    hexadecimal = 16
} StringType;

ByteQueue one_time_string_to_bytequeue(char* string, uint64_t string_len);
bool bigint_string_check(char* string, uint64_t string_len);
StringType bigint_string_type_check(char* string, uint64_t string_len);

#endif