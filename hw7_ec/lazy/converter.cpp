/*
 * Trivial implementation of converter function.
 * You may override this file or create your own.
 */
#include "converter.h"

void convert_all(unsigned nlines, char* lines[], quote_t nums[]) {
    for (unsigned i = 0; i < nlines; ++i) {
        nums[i] = *(new atoi_lazy(lines[i]));
    }
}
