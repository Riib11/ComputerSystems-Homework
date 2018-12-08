/*
 * API for converter function--do not change this file!
 */
#include <inttypes.h>
#include "lazy_atoi.h" // necessary to load new #define for uint32_t

typedef uint32_t quote_t;

void convert_all(
    unsigned nlines,  // How many lines do we need to convert?
    char *lines[],    // Array of size nlines pointers to null-terminated strings
    quote_t nums[]    // Array of size nlines for the resulting outputs
);
