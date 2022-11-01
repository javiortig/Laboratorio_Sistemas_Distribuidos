#include "serialize.h"

// Convierte el vector en string
string* serializeStringVector(vector<string*> *v, char separator){
    string* result = new string("");
    

    for(auto it=v->begin();it!= v->end();++it)
    {
        *result += **it;
        *result += separator;
    }

    return result;
}

vector<string*>* deserializeStringVector(string *s, char separator){
    vector<string*>* result = new vector<string*>; 
    int i, j;

    //i to loop string, j to loop vector array
    result->push_back(new string(""));
    for (i = 0, j=0; i < s->length(); i++)
    {
        if((*s)[i] == separator)
        {
            result->push_back(new string(""));
            j++;
        }
        else{
            *((*result)[j]) += (*s)[i];
        }
    }   

    result->pop_back();
    

    return result;
}

