#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

// Convierte el vector en string
string* serializeStringVector(vector<string*> *v, char separator='&');

//Convierte un string serializado en vector
vector<string*>* deserializeStringVector(string *s, char separator='&');

