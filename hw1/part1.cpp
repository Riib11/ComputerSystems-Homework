
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

#include <vector>
#include <iostream>
#include <chrono>
#include <ctime>
#include <math.h>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <random>

typedef std::chrono::duration<double> duration;
typedef __int32_t bufferunit; // big enough so that each
                              // entry in the buffer can
                              // represent an index of the buffer

// number of trials to use in calculating
// the average latency
//const int TRIALS = std::pow(2,28);
const unsigned TRIALS = std::pow(2,25);

// buffer size constants
const unsigned BUFFER_SIZE_BYTES_EXP_MIN = 10; // min exponent
const unsigned BUFFER_SIZE_BYTES_EXP_MAX = 31; // 30 // max exponent
const unsigned BUFFER_UNIT_SIZE_BYTES    = 32/8; // size of buffer entries

// 2^i is the number of bytes in buffer
// 2^i/BUFFER_UNIT_SIZE_BYTES is the number of entries in buffer
bufferunit buffer_size_bytes_exp_to_buffer_units(
    unsigned buffer_size_bytes_exp) {
    return std::pow(2,buffer_size_bytes_exp)
               / BUFFER_UNIT_SIZE_BYTES;
}

unsigned buffer_units_to_bytes(bufferunit x) {
    return x * BUFFER_UNIT_SIZE_BYTES;
} 

// gets a random int in the range [0..n-1]
bufferunit random_index(bufferunit n) {
    return bufferunit(n * (rand() / (RAND_MAX + 1.0)));
}

/*
 * measure_latency:
 * 
 * measures the mean latency in accessing a byte
 * of memory from a `n`-bufferunit buffer.
 * 
 * `readable` flags the output to be formatted in a
 * human-readable way. otherwise, catered to gnuplot
*/
void measure_latency(bufferunit n, bool readable) {

    // create a buffer of `n` bufferunits
    std::vector<bufferunit> buffer(n);
    for (bufferunit i = 0; i < n; i++)
        buffer[i] = i;

    // shuffle values
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(buffer), std::end(buffer), rng);


    // `volatile` makes sure this var
    // and the following loop is not optimized away
    volatile bufferunit index = 0;
    
    // start timer
    auto start = std::chrono::steady_clock::now();

    // measure the latency TRIALS times
    for (unsigned i = 0; i < TRIALS; i++) {
        // access an entry of the buffer,
        // also setting the next entry index
        // (yielded from previous random generation)
        index = buffer.at(index);
        asm(""); // makes sure loop not optimized away
    }

    // end timer
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration = end - start;
    
    // record latency
    auto latency_avg_nanosecs = duration.count() / TRIALS * std::pow(10,9);
    auto buffer_size_kilobytes = buffer_units_to_bytes(n)/1000;
    
    // print in human readable format
    if (readable) {
        std::cout
            << "size of buffer (rounded): "
                << buffer_size_kilobytes << " kb\n"
            << "average latency: "
                << latency_avg_nanosecs << " ns\n\n";
    
    // print in gnuplot-friendly format
    } else {
        std::cout
            << buffer_size_kilobytes << " "
            << latency_avg_nanosecs << "\n";
    }
}

/*
 * measure_range_latencies:
 * 
 * runs `measure_latency` over a range of buffer sizes
 * defined by the above constants.
 * 
 * see `measure_latency` for description of `readable`
 */
void measure_range_latencies(bool readable) {
    for (unsigned i = BUFFER_SIZE_BYTES_EXP_MIN; i <= BUFFER_SIZE_BYTES_EXP_MAX; i++) {
        measure_latency(
            buffer_size_bytes_exp_to_buffer_units(i),
            readable);
    }
}