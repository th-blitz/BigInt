#ifndef bigint_parser_H
#define bigint_parser_H

#include <stdint.h>

#include "ByteQueue.h"

ByteQueue one_time_string_to_bytequeue(char* string, uint64_t string_len);

#endif