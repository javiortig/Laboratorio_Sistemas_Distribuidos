#include "serialize.h"

//serializa con filas columnas data
int* serializeMatrix(matrix_t * m){
    int *result = nullptr;
    int len = m->cols * m->rows;

    result = (int*) malloc(sizeof(int) * (len + 2));
    result[0] = m->rows;
    result[1] = m->cols;
    for (int i = 0; i < len; i++)
    {
        result[i + 2] = m->data[i];
    }
    
    return result;
}

matrix_t* deserializeMatrix(int* arr){
    matrix_t *result = new matrix_t();
    int len = -1;

    result->rows = arr[0];
    result->cols = arr[1];

    len = result->rows * result->cols;

    result->data = (int*) malloc(sizeof(int) * len);

    for (int i = 0; i < len; i++)
    {
        result->data[i] = arr[i + 2];
    }

    return result;
}