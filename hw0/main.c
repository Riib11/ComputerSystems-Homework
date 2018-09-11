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

void print_array(float size, float* xs) {
    printf("[ ");
    for(int i=0; i<size; i++) {
        printf("%f ", xs[i]);
    }
    printf("]\n");
}

float uniform(float bound) {
    // generates random in [0,1] range
    float scale = rand() / (float) RAND_MAX;
    // translates random to [-bound, bound] range
    return (-bound) + scale * ( bound - (-bound) );
}

float * generate_random_list(unsigned sz, float bound) {
	// float list[sz];
	float *list = malloc(sizeof(list) * sz);
	if (!list) { } // bad
	for (unsigned i=0; i < sz; i++) {
		list[i] = uniform(bound);
	}
	return list;
}

void update_coords(double size, float* x, float* y, float* z, float* vx, float* vy, float* vz) {
    for (int i=0; i<size; i++) {
        x[i] = x[i] + vx[i];
        y[i] = y[i] + vy[i];
        z[i] = z[i] + vz[i];
    }
}

float sum(double size, float* xs) {
    float total = 0;
    for (int i=0; i < size; i++) {
	total = total + xs[i];
    }
    printf("total = %f\n", total);
    return total;
}

double pow(double x, double y);

int get_iters(double si) {
    if (si < 10) {
        return 100;
    } else if(si < 16) {
        return 10;
    } else {
        return 3;
    }
}

int ITERS = 1;
int SIZE_P2_MAX = 24;

int main(void) {

    srand((unsigned int)time(NULL));
    
    for (double si=8; si<=SIZE_P2_MAX; si++) {
        double size = pow(2, si);
        // time it
        float total_time = 0;
        int iters = get_iters(si);
        for (int i=0; i < iters; i++) {
            // initialized states
            float* x = generate_random_list(size, 1.0);
            float* y = generate_random_list(size, 1.0);
            float* z = generate_random_list(size, 1.0);
            float* vx = generate_random_list(size, 1.0);
            float* vy = generate_random_list(size, 1.0);
            float* vz = generate_random_list(size, 1.0);
            clock_t start, end;
            double cpu_time_used;
            start = clock();
            update_coords(size, x, y, z, vx, vy, vz);
            end = clock();
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            // printf("time used = %f\n", cpu_time_used);
            total_time += cpu_time_used;

            // make sure worked right
            // float chksum = sum(size, x) + sum(size, y) + sum(size, z);
            // printf("checksum = %f\n", chksum);
        }
        printf("%i ", (int)size);
        printf("%f\n", total_time/ITERS);
        // printf("average time used: %f\n", total_time/ITERS);
    }
    return 0;
}

