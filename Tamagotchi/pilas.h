#ifndef PILAS_H
#define PILAS_H
#include "nodo.h"
#include <iostream>
using namespace std;

class Pilas
{
public:
    Pilas();
    Nodo* Tope;
    Nodo* getTope();
    bool Sacar();
    void Meter(Nodo*obj);
    bool Vacia();
    void Anular();
    int cont;
    ~Pilas();
};

#endif // PILAS_H
