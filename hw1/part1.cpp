
/*
 * Part 1:
 * 
 * Goal: measure the latency of reading a byte from memory
 * out of a buffer of `n` bytes, for `n from 2^10 to 2^26.
 * For each `n`, will record the average time to read a byte
 * from a pre-allocated buffer of size `n` (looping a number
 * of times to get a stable average) and print the result.
 * 
 */

#include <iostream>
#include <memory>

void measure_latency(int n) {
    auto buffer_ptr = std::make_unique<uint8_t[]>(n);
    
    return;
}