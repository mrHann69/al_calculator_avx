/**
Este código fue desarrollado en colaboración con ChatGPT

Fecha: 05/03/2024
Autor: John Sanabria - john.sanabria@correounivalle.edu.co
*/
#include <immintrin.h>
#include <stdio.h>
#include <assert.h>

#define VECTORSIZE 4

// Function to perform vector-scalar multiplication
void vectorScalarMultiply(const double* vector, double scalar, double* result, int length) {
    // Ensure the length is a multiple of 4 for proper alignment
    int alignedLength = (length + 3) & ~3;

    // Loop through the vector in 4-element chunks
    for (int i = 0; i < alignedLength; i += 4) {
        // Load the vector chunk into AVX register
        __m256d vec = _mm256_loadu_pd(vector + i);

        // Broadcast the scalar value to all elements of another AVX register
        __m256d scalarVec = _mm256_broadcast_sd(&scalar);

        // Perform element-wise multiplication
        __m256d resultVec = _mm256_mul_pd(vec, scalarVec);

        // Store the result back to memory
        _mm256_storeu_pd(result + i, resultVec);
    }
}

int main(int argc, char* argv[]) {
    // Example data
    int vectorSize;
    double *vector;
    double scalar = 2.0;
    double *result;

    if (argc == 1) {
        vectorSize = VECTORSIZE;
    } else {
        vectorSize = atoi(argv[1]);
    }
    vector = (double*)malloc(sizeof(double)*vectorSize);
    assert(vector != NULL);
    result = (double*)malloc(sizeof(double)*vectorSize);
    assert(result != NULL);

    // Initialize the vector with some values
    for (int i = 0; i < vectorSize; ++i) {
        vector[i] = i + 1;
    }

    // Perform vector-scalar multiplication
    vectorScalarMultiply(vector, scalar, result, vectorSize);

#ifdef DEBUG
    // Print the result
    printf("Original Vector:\n");
    for (int i = 0; i < vectorSize; ++i) {
        printf("%lf ", vector[i]);
    }

    printf("\nScalar: %lf\n", scalar);

    printf("Result:\n");
    for (int i = 0; i < vectorSize; ++i) {
        printf("%lf ", result[i]);
    }
#endif

    free(vector);
    free(result);

    return 0;
}
