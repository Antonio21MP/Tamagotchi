#include "colas.h"

Colas::Colas()
{
    frente = NULL;
    ultimo = NULL;
}

Colas::~Colas()
{

}

bool Colas::Vacia(){
    if(frente)
        return false;
    return true;
}
void Colas::PonerCola(Nodo* n){
    if(frente==NULL){
        frente = n;
        ultimo = n;
        return;
    }
    ultimo->ant = n;
    ultimo = n;
}
bool Colas::QuitarCola(){
    Nodo* temp;
    if(frente){
        temp = frente;
        frente = temp->ant;
        delete temp;
        return true;
    }
    return false;
}
Nodo* Colas::getFrente(){
    return frente;

}
void Colas::Anular(){
    while(QuitarCola());
}
