#pragma once

#include "multmatrix.h"
#include "utils.h"

class multMatrix_imp
{
	private:
		multMatrix* mult = nullptr;
		int clientId = -1;
	
	public:
		multMatrix_imp(int clientId);
		~multMatrix_imp();
		
		void recvOp();
		void recvIdentity();
		void recvRandMatrix();
		void recvReadMatrix();
		void recvMultMatrix();
		void recvWriteMatrix();
};