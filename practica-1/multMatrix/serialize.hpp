#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cstring>

#define byte char

typedef enum typeData
{
    t_char  = 0,
    t_float = 1,
    t_int   = 2
}typeData;


using namespace std;

template<typename T>
vector<byte>* serializeVector(vector<T>* v1, typeData t)
{
    vector<byte>* vres = new vector<byte>();

    vres->reserve(sizeof(typeData)+sizeof(int)+sizeof(T)*v1->size());
    vres->resize(sizeof(typeData)+sizeof(int)+sizeof(T)*v1->size());

    int size = v1->size();
    byte* data = vres->data();

    memcpy(data, &t, sizeof(typeData));
    data += sizeof(typeData);

    memcpy(data, &size, sizeof(int));
    data += sizeof(int);

    memcpy(data, v1->data(), sizeof(T)*size);

    return vres;
}

template<typename T>
vector<T>* deserializeVector(vector<byte>* v1, typeData t)
{
    vector<T>* vres = new vector<T>();

    int size = 0;
    typeData tIn;
    byte* data = v1->data();

    memcpy(&tIn, data, sizeof(typeData));
    data += sizeof(typeData);

    if(tIn != t)
    {
        cout << "ERROR: tipo de datos no válidos - Linea " << __LINE__ << " - " << __FILE__ << endl;
        return nullptr;
    }

    memcpy(&size, data, sizeof(int));
    data += sizeof(int);

    vres->reserve(size);
    vres->resize(size);

    memcpy(vres->data(), data, sizeof(T)*size);

    return vres;
}