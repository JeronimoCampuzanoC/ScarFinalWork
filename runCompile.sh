#Compile the mmm_implementation.c file with these flags:
gcc -o bin/mmm mmm_implementation.c -fopenmp -O3 -march=native -mtune=native -fprefetch-loop-arrays