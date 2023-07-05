#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <normal.h>

int main(void){
    srand(time(NULL));

    int cnt[41];
    for(int j = 0; j < 41; ++j)
        cnt[j] = 0;

    for(int i = 0; i < 1000; ++i){
        float sample = std_normal_dist_rand();

        if(sample > 4.0f){
            ++cnt[40];
            continue;
        }

        float a = -4.0f;
        for(int j = 0; j < 40;++j){
            if(sample <= a){
                ++cnt[j];
                break;
            }
            a += 0.2f;
        }
    }

    int s1 = 0;
    for(int j = 15; j < 25; ++j)
        s1 += cnt[j];
    printf("1sigma %.3f%%\n", (float)s1 / 10.0f);

    int s2 = 0;
    for(int j = 10; j < 30; ++j)
        s2 += cnt[j];
    printf("2sigma %.3f%%\n", (float)s2 / 10.0f);

    int s3 = 0;
    for(int j = 5; j < 35; ++j)
        s3 += cnt[j];
    printf("3sigma %.3f%%\n", (float)s3 / 10.0f);

    for(int j = 0; j < 41; ++j){
        for(int k = 0; k < cnt[j]; ++k)
            printf("-");
        printf("\n");
    }

    return 0;
}