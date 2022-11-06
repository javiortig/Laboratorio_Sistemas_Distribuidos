#pragma once
#include "multmatrix.h"

#include <string.h>
#include <iostream>

// Convierte una matrix en char*
int* serializeMatrix(matrix_t * m);

// Convierte un char* en una matrix
matrix_t* deserializeMatrix(int*s);