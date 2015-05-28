#ifndef NODO_H
#define NODO_H
#include <iostream>
using namespace std;

class Nodo
{
public:
    Nodo(int v);
    int valor;
    Nodo* ant;
    ~Nodo();
};

#endif // NODO_H
