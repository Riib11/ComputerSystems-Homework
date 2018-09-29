
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <random>
#include "part1.h"

/*
 * main
 */
int main() {
    
    // seed random with a cool unsigned
    // in order to make the results more
    // in line with the natural order
    // of the universe
    srand((unsigned) 123456789);
    
    measure_range_latencies(false);
    
    return 0;
}
