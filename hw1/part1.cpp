
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
typedef __int32 bufferunit;

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

    // TODO: write outputs

    // TODO: remove the rest of this function
    // ---------------------------------------
    // calculate average latency
    duration average_elapsed_seconds = total_elapsed_seconds / TRIALS;
    duration average_elapsed_nanosecs = average_elapsed_seconds * std::pow(10,9);
    
    // for a human-readable output format
    if (readable) {
        std::cout << "size of buffer: "
                        << std::to_string(n/1000) << " kb\n"
                  << "average latency: "
                        << average_elapsed_nanosecs.count() << " ns\n\n";    
    // for a gnuplot-readable output format
    } else {
        std::cout << std::to_string(n/1000) << " "
                  << average_elapsed_nanosecs.count() << "\n";
    }
    // ---------------------------------------
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