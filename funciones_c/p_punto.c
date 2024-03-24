#include <immintrin.h>
#include <stdio.h>
#include <assert.h>

#define VECTORSIZE 4


double dotProduct(double* v1, double* v2, int vSize){
  double result = 0;
  for(int i=0; i<vSize;i++){
    result = result + (v1[i] + v2[i]);
  }
  return result; 
}

double calculateDotPoint() {
    // Example vectors
    int vectorSize;
    int i;
    double *vector1;
    double *vector2;

    vectorSize = VECTORSIZE;

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
    return result;
}
