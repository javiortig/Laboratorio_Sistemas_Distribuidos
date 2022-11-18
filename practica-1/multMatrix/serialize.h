#pragma once

#include <string.h>
#include <iostream>
#include "multmatrix.h"

// Convierte una matrix en char*
int* serializeMatrix(matrix_t* m);

// Convierte un char* en una matrix
matrix_t* deserializeMatrix(int* arr);