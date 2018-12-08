/*
 * Trivial implementation of converter function.
 * You may override this file or create your own.
 */
#include "converter.h"
// #include "lazy_atoi.h" // necessary to load new #define for uint32_t

void convert_all(unsigned nlines, char* lines[], quote_t nums[]) {
    // fill nums[] with atoi_lazy pointers,
    // that lazily uint32_t cast appropriately
    for (unsigned i = 0; i < nlines; ++i) {
        nums[i] = *(new atoi_lazy(lines[i]));
    }
}
