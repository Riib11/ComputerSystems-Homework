
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

typedef std::chrono::duration<double> duration;

// gets a random int in the range [0..n-1]
int random_index(int n) { return std::rand() % n; }

// number of trials to use in calculating
// the average latency
const int TRIALS = std::pow(2,24);

/*
 * measure_latency:
 * 
 * measures the mean latency in accessing a byte
 * of memory from a `n`-byte buffer.
 * 
 * `readable` flags the output to be formatted in a
 * human-readable way. otherwise, catered to gnuplot
*/
void measure_latency(int n, bool readable) {
    
    // create a buffer of `n` bytes (chars)
    std::vector<char> buffer(n);
    for (int i = 0; i < n; i++) buffer[i] = 'a';
    
    // store the total of the latencies
    std::chrono::duration<double> total_elapsed_seconds
        = duration::zero();
    
    // measure the latency `n` times
    for (int i = 0; i < TRIALS; i++) {
        // pick a random index to sample,
        // in order to not let any avaliability
        // hueristics implemented by the caches
        // tamper with the measurements
        unsigned index = random_index(n);
        
        // start timer
        auto start = std::chrono::steady_clock::now();      
        // access a byte of the buffer
        buffer.at(index);
        // end timer
        auto end = std::chrono::steady_clock::now();
        // add measured latency to the total
        total_elapsed_seconds += end-start;
    }
    
    // calculate average latency
    duration average_elapsed_seconds = total_elapsed_seconds / TRIALS;
    duration average_elapsed_nanosecs = average_elapsed_seconds * std::pow(10,9);
    
    // for a human-readable output format
    if (readable) {
        std::cout << "size of buffer: " << std::to_string(n/1000) << " kb\n"
                  << "average latency: "
                        << average_elapsed_nanosecs.count() << " ns\n\n";    
    // for a gnuplot-readable output format
    } else {
        std::cout << std::to_string(n/1000) << " "
                  << average_elapsed_nanosecs.count() << "\n";
    }
}

const int BUFFER_SIZE_EXP_MIN = 10;
const int BUFFER_SIZE_EXP_MAX = 26;

/*
 * measure_range_latencies:
 * 
 * runs `measure_latency` over a range of buffer sizes
 * defined by the above constants.
 * 
 * see `measure_latency` for description of `readable`
 */
void measure_range_latencies(bool readable) {
    for (int i = BUFFER_SIZE_EXP_MIN; i <= BUFFER_SIZE_EXP_MAX; i++) {
        measure_latency(std::pow(2,i), readable);
    }
}