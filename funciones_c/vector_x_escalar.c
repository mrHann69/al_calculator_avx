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

    // Print the result
#ifdef DEBUG
    printf("Original Vector:\n");
    for (int i = 0; i < vectorSize; ++i) {
        printf("%lf ", vector[i]);
    }

    //printf("\nScalar: %lf\n", scalar);

    printf("Result:\n");
    for (int i = 0; i < vectorSize; ++i) {
        printf("%lf ", result[i]);
    }
#endif

    free(vector);
    free(result);

    return 0;
}
