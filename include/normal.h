#ifndef __NORMAL_H__
#define __NORMAL_H__

float std_normal_dist_rand();
float normal_dist_rand(float avr, float var);
float* multi_normal_dist(int dim, float* avr, float** var);

#endif