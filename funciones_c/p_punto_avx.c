#include <immintrin.h>
#include <stdio.h>
#include <assert.h>

#define VECTORSIZE 4

// Function to calculate the dot product of two vectors
double dotProduct(const double* vec1, const double* vec2, int length) {
    // Ensure the length is a multiple of 4 for proper alignment
    int alignedLength = (length + 3) & ~3;

    // Initialize accumulators
    __m256d sumVec = _mm256_setzero_pd();

    // Loop through the vectors in 4-element chunks
    for (int i = 0; i < alignedLength; i += 4) {
        // Load 4 elements from each vector into AVX registers
        __m256d vec1Chunk = _mm256_loadu_pd(vec1 + i);
        __m256d vec2Chunk = _mm256_loadu_pd(vec2 + i);

        // Multiply corresponding elements
        __m256d product = _mm256_mul_pd(vec1Chunk, vec2Chunk);

        // Accumulate the product
        sumVec = _mm256_add_pd(sumVec, product);
    }

    // Sum the elements in the accumulator
    double result[4];
    _mm256_storeu_pd(result, sumVec);
    return result[0] + result[1] + result[2] + result[3];
}

int main(int argc, char* argv[]) {
    // Example vectors
    int vectorSize;
    int i;
    double *vector1;
    double *vector2;

    if (argc == 1)
        vectorSize = VECTORSIZE;
    else
        vectorSize = atoi(argv[1]);

    vector1 = (double*)malloc(sizeof(double) * vectorSize);
    assert(vector1 != NULL);
    vector2 = (double*)malloc(sizeof(double) * vectorSize);
    assert(vector2 != NULL);

    for (i = 0; i < vectorSize; i++) {
        vector1[i] = 1;
        vector2[i] = i + 1;
    }

    // Calculate the dot product
    double result = dotProduct(vector1, vector2, vectorSize);

    // Print the result
    printf("Dot Product: %lf\n", result);

    return 0;
}
