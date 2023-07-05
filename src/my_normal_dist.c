#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

#include <my_normal_dist.h>

float std_normal_dist_rand(){
    // 10 * E[ x ] = 0 + 1 + 2 + ... +  9 =  45
    // 10 * E[x^2] = 0 + 1 + 4 + ... + 81 = 285
    // avr =  4.5
    // var = 28.5 - 4.5^2 = 8.25

    int s = 0;
    for(int i  = 0; i < 10000; ++i)
        s += rand() % 10;

    return (float)(s - 45000) / 287.23f;
}

float normal_dist_rand(float avr, float var){
    float x = std_normal_dist_rand();
    x *= sqrtf(var);
    x += avr;
    return x;
}

float* multi_normal_dist(int dim, float* avr, float** var){
    if(dim <= 0)
        return NULL;

    float* z = (float*)malloc(dim * sizeof(float));
    for(int j = 0; j < dim; ++j)
        z[j] = std_normal_dist_rand();

    float* x = (float*)malloc(dim * sizeof(float));
    for(int i = 0; i < dim; ++i){
        x[i] = 0.0f;
        for(int j = 0; j < dim; ++j)
            x[i] += var[i][j] * z[j];
    }

    free(z);

    for(int i = 0; i < dim; ++i)
        x[i] -= avr[i];

    return x;
}
