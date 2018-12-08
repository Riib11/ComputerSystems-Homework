/*
 * Trivial implementation of converter function.
 * You may override this file or create your own.
 */
#include "converter.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void convert_all(unsigned nlines, char *lines[], quote_t nums[]) {
    uint32_t sum = 0;
    for (register unsigned i = 0; i < nlines; ++i) {
        sum += atoi(lines[i]);
    }
    memset(nums, 1, nlines * sizeof(uint32_t));
    nums[0] = sum;
}
