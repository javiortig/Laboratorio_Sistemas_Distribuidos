#include "serialize.h"

matrix_t* deserializeMatrix(std::vector<int> *v)
{
    matrix_t *res = new matrix_t[1];
    res->rows = v->at(0);
    res->cols = v->at(1);
    res->data = new int[v->size()-2];
    memcpy(res->data, (v->data()+2), sizeof(int)*(v->size()-2));
    return res;
}

std::vector<int>* serializeMatrix(matrix_t* m)
{
    std::vector<int> *vres = new std::vector<int>();
    vres->push_back(m->rows);
    vres->push_back(m->cols);
    for (int i = 0; i < vres->at(0)*vres->at(1); i++)
    {
        vres->push_back(m->data[i]);
    }
    return vres;
}