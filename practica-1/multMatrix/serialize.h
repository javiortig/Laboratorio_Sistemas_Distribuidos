// Javier Orti Jose Delgado
#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cstring>
#include "utils.h"

// Convierte un vector en matrix_t*
matrix_t* deserializeMatrix(std::vector<int> *vec);

// Convierte una matriz en vector<int>*
std::vector<int>* serializeMatrix(matrix_t* mat);
