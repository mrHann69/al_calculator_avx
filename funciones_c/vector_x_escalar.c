#include <immintrin.h>
#include <stdio.h>
#include <assert.h>

#define VECTORSIZE 4

// Function to perform vector-scalar multiplication
void vectorScalarMultiply(const double* vector, double scalar, double* result, int length) {
    for (int i = 0; i < length; i++) {
      result[i] = vector[i] * scalar;
    }
}

double* vectorXescalar(int sizee){
    // Example data
    int vectorSize;
    double* vector;
    double scalar = 2.0;
    double* result;

    vectorSize = VECTORSIZE;
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
    return result;
}
