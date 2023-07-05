#!/bin/bash

ls | grep -x build > /dev/null
[ $? -eq 0 ] || mkdir build
ls build | grep src > /dev/null
[ $? -eq 0 ] || mkdir build/src

cd build/src

gcc -I../../include -c -lm ../../src/my_normal_dist.c

ar rcs libmy_normal_dist.a my_normal_dist.o

gcc -o show_normal_dist.out ../../src/show_normal_dist.c -I../../include -L. -lmy_normal_dist -lm 