#core dumped error: ulimit -s unlimited
ulimit -s unlimited
#Num of threads
OMP_NUM_THREADS=12;
export OMP_NUM_THREADS
gcc -o bin/mmm mmm_implementation.c -fopenmp -O3 && ./bin/mmm 

#Agressive optimizations
#gcc -o bin/mmm mmm_implementation.c -fopenmp -O3 -march=native -mtune=native

