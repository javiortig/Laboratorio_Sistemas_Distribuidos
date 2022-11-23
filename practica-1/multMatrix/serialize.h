#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cstring>
#include "utils.h"

// Convierte una matrix en char*
matrix_t* deserializeMatrix(std::vector<int> *v);

// Convierte un char* en una matrix
std::vector<int>* serializeMatrix(matrix_t* m);
