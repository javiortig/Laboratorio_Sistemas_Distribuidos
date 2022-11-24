// Javier Orti Jose Delgado
#include "serialize.h"

matrix_t* deserializeMatrix(std::vector<int> *vec)
{
    matrix_t *deserialized = new matrix_t[1];
	
    deserialized->rows = v->at(0);
    deserialized->cols = v->at(1);
	
	// Los datos no incluyen a rows ni cols luego restamos 2
    deserialized->data = new int[vec->size() - 2];
    memcpy(deserialized->data, (vec->data() + 2), sizeof(int)*(vec->size() - 2));
    return deserialized;
}

std::vector<int>* serializeMatrix(matrix_t* mat)
{
    std::vector<int> *serialized = new std::vector<int>();
	
    serialized->push_back(mat->rows);
    serialized->push_back(mat->cols);
	
	// iteramos copiando mientras i sea menor que rows*cols
    for (int i = 0; i < serialized->at(0)*serialized->at(1); i++) {
        serialized->push_back(mat->data[i]);
    }
	
    return serialized;
}