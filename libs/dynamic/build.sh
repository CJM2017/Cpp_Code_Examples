#!/bin/bash

# the fpic option tells gcc to create position ind code which 
# is required for shared libs
# this gens the object file for the library
gcc -c -Wall -Werror -fPIC calc_mean.c -o calc_mean.o    

gcc -shared -o libmean.so calc_mean.o

gcc main.c -o dynamically_linked -L. -lmean

#EOF