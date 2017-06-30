#!/bin/bash

# -c means to compile the source but do not link. The linking stage is not done
# output is an object file
gcc -c ../src/calc_mean.c -o calc_mean.o 

# invoke the archiver to produce a static library from source
# the library must start with lib and have the suffix .a 
ar rcs libmean.a calc_mean.o

# compile the source file and static library
# -L. tells compiler to search current dir for libs
gcc -static ../src/main.c -L. -lmean -o staticRun

#EOF
