
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

// TODO: make the indecies and unit buffer size equal to 32 bytes,
//       so that it can hold it's own indecies

typedef std::chrono::duration<double> duration;
typedef __int32_t bufferunit;

// gets a random int in the range [0..n-1]
bufferunit random_index(bufferunit n) {
    return rnd = 0 + int((n * rand()) / (RAND_MAX + 1.0));
}

// number of trials to use in calculating
// the average latency
const int TRIALS = std::pow(2,24);

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
        buffer[i] = random_index(n);
    
    // store the total of the latencies
    std::chrono::duration<double> total_elapsed_seconds
        = duration::zero();

    // start timer
    auto start = std::chrono::steady_clock::now();

    bufferunit index = 0;
    // measure the latency TRIALS times
    for (int i = 0; i < TRIALS; i++) {
        // access an entry of the buffer,
        // also setting the next entry index
        // (yielded from previous random generation)
        index = buffer.at(index);
    }

    // end timer
    auto end = std::chrono::steady_clock::now();

    // calculate average duration
    auto duration_secs = end - start;
    auto duration_secs_avg = duration_secs / TRIALS;
    auto duration_nanosecs_avg = duration_secs_avg * std::pow(10,9);

    
    auto buffer_size_bytes = buffer_units_to_bytes(n)/1000;
    auto average_latency_nanosecs = duration_nanosecs.count();
    if (readable) {
        std::cout
            << "size of buffer: "
                << buffer_size_bytes << " kb\n"
            << "average latency: "
                << average_latency_nanosecs << " ns\n\n";
    } else {
        std::cout
            << buffer_size_bytes << " "
            << average_latency_nanosecs << "\n";
    }
}

// buffer size constants
const unsigned BUFFER_SIZE_BYTES_EXP_MIN = 10; // min exponent
const unsigned BUFFER_SIZE_BYES_EXP_MAX  = 26; // max exponent
const unsigned BUFFER_UNIT_SIZE_BYTES    = 32; // 32 bytes per entry in buffer

bufferunit buffer_size_bytes_exp_to_buffer_units(unsigned buffer_size_bytes_exp) {
    // 2^i gives the number of bytes in buffer
    // 2^i/BUFFER_UNIT_SIZE_BYTES gives the
    //   number of entries in buffer
    return std::pow(2,buffer_size_bytes_exp) / BUFFER_UNIT_SIZE_BYTES;
}

unsigned buffer_unit_to_bytes(bufferunit x) {
    return x * BUFFER_UNIT_SIZE_BYTES;
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
    for (unsigned i = BUFFER_SIZE_EXP_MIN; i <= BUFFER_SIZE_EXP_MAX; i++) {
        measure_latency(buffer_size_bytes_exp_to_buffer_units(i),
            readable);
    }
}