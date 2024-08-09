# Final Workshop

To run the program, you should execute the runCompile.sh script to compile the source code with all the optimization flags of GCC. After that, you can run the command sbatch job.sh to place the program in the queue in the learning partition.

## Optimization

The OpenMP API reduces the execution time using parallel programming techniques.

I implemented the #pragma omp parallel for collapse(2) directive to apply parallelization in the for loop. The collapse(2) option provided better performance in an experimental setting compared to collapse(3), possibly due to the shared memory usage by the caches.

#pragma omp parallel for collapse(2)

I also implemented a more efficient multiplication algorithm that uses loop interchange.

The program is compiled with several GCC optimization flags, including:

-fopenmp: Enables OpenMP to generate parallel code.
-O3: Merges and eliminates dead code, performs common subexpression elimination, strict aliasing, function inlining, and vectorization.
-fprefetch-loop-arrays: Enables the speculation of data into the cache before it is needed, improving memory access.
-march=native: Generates code for the specific CPU architecture of the machine.
-mtune=native: Generates code optimized for the specific CPU model.

I prefer to use double C[size][size] __attribute__((aligned(64))) because it provides better performance on modern CPUs than malloc.