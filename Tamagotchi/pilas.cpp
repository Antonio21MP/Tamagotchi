#include "pilas.h"

Pilas::Pilas()
{
    Tope = NULL;
    cont = 1;
}

Pilas::~Pilas()
{

}
Nodo* Pilas::getTope(){
    return Tope;
}

bool Pilas::Sacar(){
    if(Tope){
        Nodo* temp = Tope;
        Tope = Tope->ant;
        delete temp;
        cont--;
        return true;
    }
    return false;
}
void Pilas::Meter(Nodo* obj){
    if(cont<=5){
    if(Tope)
        obj->ant = Tope;
    Tope = obj;
    cont++;
    }
}

bool Pilas::Vacia(){
    if(Tope)
        return false;
    return true;
}
void Pilas::Anular(){
    while(Sacar());
}


