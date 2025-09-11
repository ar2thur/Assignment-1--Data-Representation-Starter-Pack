#ifndef CONVERSION_H
#define CONVERSION_H

#include <stdint.h>

// Function prototypes
void div_convert(uint32_t n, int base, char *out);
void sub_convert(uint32_t n, int base, char *out);
void print_tables(uint32_t n);

#endif // CONVERSION_H