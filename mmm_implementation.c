#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

/*
Original values
#define N 50
#define MIN_SIZE 2
#define MAX_SIZE 5000
*/
#define N 10
#define MIN_SIZE 2
#define MAX_SIZE 1000
#define MAX_NUM 10000000.0
#define BLOCK_SIZE 32

int main()
{
    srand((unsigned)time(NULL));
    int size = 1200/*MIN_SIZE + (rand() % MAX_SIZE)*/, iterator = 0;
    double time_spent = 0.0;
    
    double A[size][size] __attribute__((aligned(64)));
    double B[size][size] __attribute__((aligned(64)));
    double C[size][size] __attribute__((aligned(64)));

    while (iterator++ < N)
    {
        printf("Running iteration number: %d\n", iterator);

        clock_t begin_time = clock();

        // Start modifying here

        
        #pragma omp parallel for
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                A[j][i] = 1 + ((double)rand() / RAND_MAX) * MAX_NUM;
                B[j][i] = 1 + ((double)rand() / RAND_MAX) * MAX_NUM;
                C[j][i] = 0; 
            }
        }

        // New ALgorithm Loop Interchanging:

        #pragma omp parallel for
        for (int i = 0; i < size; ++i) {
            for (int k = 0; k < size; ++k) {
                for (int j = 0; j < size; ++j) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }       

        // Stop modifying here

        clock_t end_time = clock();
        time_spent += (double)(end_time - begin_time) / CLOCKS_PER_SEC;
    }

    printf("Size of matrices: %d \n", size);
    printf("Running time: %f \n", (time_spent / N));


    return 0;
}