#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void print_array(float size, float* xs) {
    printf("[ ");
    for(int i=0; i<size; i++) {
        printf("%f ", xs[i]);
    }
    printf("]\n");
}

float uniform(float bound) {
    // geneates random in [0,1] range
    float scale = rand() / (float) RAND_MAX;
    // translates random to [-bound, bound] range
    return (-bound) + scale * ( bound - (-bound) );
}

// float* generate_random_list(int size, float bound) {
//    float values[size];
//    for (int i=0; i < size; i++) {
//        values[i] = uniform(bound);
//    }
//    print_array(size, values);
//    return values;
//}

float * generate_random_list(unsigned sz, float bound) {
	// float list[sz];
	float *list = malloc(sizeof(list) * sz);
	if (!list) { } // bad
	for (unsigned i=0; i < sz; i++) {
		list[i] = uniform(bound);
	}
	return list;
}

void update_coords(int size, float* x, float* y, float* z, float* vx, float* vy, float* vz) {
    for (int i=0; i<size; i++) {
        x[i] = x[i] + vx[i];
        y[i] = y[i] + vy[i];
        z[i] = z[i] + vz[i];
    }
}

float sum(int size, float* xs) {
    float total = 0;
    for (int i=0; i < size; i++) {
	total = total + xs[i];
    }
    printf("total = %f\n", total);
    return total;
}

int main(void) {

    srand((unsigned int)time(NULL));

    // initialized states
    int size = 100;
    float* x = generate_random_list(size, 1.0);
    float* y = generate_random_list(size, 1.0);
    float* z = generate_random_list(size, 1.0);
    float* vx = generate_random_list(size, 1.0);
    float* vy = generate_random_list(size, 1.0);
    float* vz = generate_random_list(size, 1.0);

    // printf("x sum = %f\n", sum(size, x));
    // printf("y sum = %f\n", sum(size, y));
    // printf("z sum = %f\n", sum(size, z));

    // time it
    unsigned iters = 100;
    for (unsigned iter
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    update_coords(size, x, y, z, vx, vy, vz);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("time used = %f\n", cpu_time_used);

    // make sure worked right
    float chksum = sum(size, x) + sum(size, y) + sum(size, z);
    printf("checksum = %f\n", chksum);

    return 0;
}
