#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

// Convierte un std::vector en un std::string separado por separator
string* serializeStringVector(vector<string*> *v, char separator='&');

// Convierte un std::string en un std::vector separado por separator
vector<string*>* deserializeStringVector(string *s, char separator='&');

