#pragma once

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include "utils.h"

#define OP_END 0
#define OP_IDENTIDAD 1
#define OP_RAND 2
#define OP_READ 3
#define OP_MULT 4
#define OP_WRITE 5

class multMatrix_stub
{
	private:
		int serverId = -1;
	
	public:
		multMatrix_stub();
		
		matrix_t* readMatrix(const char* fileName);
		matrix_t *multMatrices(matrix_t* m1, matrix_t *m2);
		void writeMatrix(matrix_t* m, const char *fileName);
		~multMatrix_stub();
		matrix_t *createIdentity(int rows, int cols);
		matrix_t *createRandMatrix(int rows, int cols);
};