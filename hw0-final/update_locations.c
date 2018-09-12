/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: henry
 *
 * Created on September 10, 2018, 8:02 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// which data type to use
// for position/velocity values
#define DATATYPE float

// useful print function
void print_array(float size, float* xs) {
    printf("[ ");
    for(int i=0; i<size; i++) {
        printf("%f ", xs[i]);
    }
    printf("]\n");
}

// returns random DATATYPE within range [-bound,bound] (inclusive)
DATATYPE uniform(float bound) {
    // generates random in [0,1] range
    float scale = rand() / (float) RAND_MAX;
    // translates random to [-bound, bound] range
    return (DATATYPE) ((-bound) + scale * ( bound - (-bound) ));
}

// returns an array[size] of DATATYPEs that are
// random samples generated using `uniform`
DATATYPE* generate_random_list(double size) {
    float bound = 100;
    DATATYPE *list = malloc(sizeof(list) * size);
    if (!list) { } // bad
    for (unsigned i=0; i < size; i++) {
	list[i] = uniform(bound);
    }
    return list;
}

// updates positions using velocities,
// loops through all of positions and velocities
void update_coords(double size, DATATYPE* x, DATATYPE* y, DATATYPE* z, DATATYPE* vx, DATATYPE* vy, DATATYPE* vz) {
    for (int i=0; i<size; i++) {
        x[i] = x[i] + vx[i];
        y[i] = y[i] + vy[i];
        z[i] = z[i] + vz[i];
    }
}

// returns the sum of the entries in xs
DATATYPE sum(double size, float* xs) {
    float total = 0;
    for (int i=0; i < size; i++) {
	total = total + xs[i];
    }
    printf("total = %f\n", total);
    return total;
}

// defined in <math>
double pow(double x, double y);

// gets the number of iterations to do
// for the given size
int get_iters(double size) {
    if (size < 10) {
        return 100;
    } else if(size < 16) {
        return 20;
    } else {
        return 2;
    }
}

int SIZE_P2_MAX = 24; // max power of 2 for number of objects
                      // starts at 2^8

int main(void) {

    srand((unsigned int)time(NULL));
    
    for (double si=8; si<=SIZE_P2_MAX; si++) {
        double size = pow(2, si);
        // time it
        float total_time = 0;
        int iters = get_iters(si);
        for (int i=0; i < iters; i++) {
            // initialized states
            DATATYPE* x = generate_random_list(size);
            DATATYPE* y = generate_random_list(size);
            DATATYPE* z = generate_random_list(size);
            DATATYPE* vx = generate_random_list(size);
            DATATYPE* vy = generate_random_list(size);
            DATATYPE* vz = generate_random_list(size);
            clock_t start, end;
            double cpu_time_used;
            start = clock();
            update_coords(size, x, y, z, vx, vy, vz);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            // printf("time used = %f\n", cpu_time_used);
            total_time += cpu_time_used;
            
            // make sure worked right
            // DATATYPE chksum = sum(size, x) + sum(size, y) + sum(size, z);
            // printf("checksum = %f\n", chksum);
        }
        printf("%i ", (int)size);
        printf("%f\n", total_time/iters);
    }
    return 0;
}

