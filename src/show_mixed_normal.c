#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <my_normal_dist.h>

int main(void){
    srand(time(NULL));

    int data_size;
    scanf("%d", &data_size);

    int dim;
    scanf("%d", &dim);

    int dists_size;
    scanf("%d", &dists_size);

    float* weights = (float*)malloc(sizeof(float) * dists_size);
    for(int i = 0; i < dists_size; ++i)
        scanf("%f", &weights[i]);

    float** avrs = (float**)malloc(sizeof(float*) * dists_size);
    for(int i = 0; i < dists_size; ++i){
        avrs[i] = (float*)malloc(sizeof(float) * dim);
        for(int j = 0; j < dim; ++j)
            scanf("%f", &avrs[i][j]);
    }

    float*** vars = (float***)malloc(sizeof(float**) * dists_size);
    for(int i = 0; i < dists_size; ++i){
        vars[i] = (float**)malloc(sizeof(float*) * dim);
        for(int j = 0; j < dim; ++j){
            vars[i][j] = (float*)malloc(sizeof(float) * dim);
            for(int k = 0; k < dim; ++k)
                scanf("%f", &vars[i][j][k]);
        }
    }

    for(int i = 0; i < data_size; ++i){
        float* data = mixtured_multi_normal_dist_rand(dim, dists_size, weights, avrs, vars);

        printf("%f", data[0]);
        for(int j = 1; j < dim; ++j)
            printf(" %f", data[j]);
        printf("\n");

        free(data);
    }

    for(int i = 0; i < dists_size; ++i){
        for(int j = 0; j < dim; ++j)
            free(vars[i][j]);
        free(vars[i]);
        free(avrs[i]);
    }
    free(vars);
    free(avrs);
    free(weights);

    return 0;
}