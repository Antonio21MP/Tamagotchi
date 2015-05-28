#ifndef COLAS_H
#define COLAS_H
#include "nodo.h"
#include <iostream>
using namespace std;

class Colas
{
public:
    Colas();
    Nodo* frente;
    Nodo* ultimo;
    bool Vacia();
    void PonerCola(Nodo* n);
    bool QuitarCola();
    Nodo* getFrente();
    void Anular();
    ~Colas();
};

#endif // COLAS_H
