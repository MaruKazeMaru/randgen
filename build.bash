#!/bin/bash

ls | grep -x build > /dev/null
[ $? -eq 0 ] || mkdir build
ls build | grep src > /dev/null
[ $? -eq 0 ] || mkdir build/src

cd build/src

gcc -I../../include -c ../../src/normal.c

ar rcs libnormal.a normal.o

gcc -o show_normal_dist.out ../../src/show_normal_dist.c -L. -lnormal -I../../include