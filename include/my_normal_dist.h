#ifndef __NORMAL_H__
#define __NORMAL_H__

float std_normal_dist_rand();
float normal_dist_rand(float avr, float var);
float* multi_normal_dist_rand(int dim, float* avr, float** var);
float* mixtured_multi_normal_dist_rand(int dim, int normal_dists_size, float* weights, float** avrs, float*** vars);

#endif