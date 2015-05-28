#ifndef PTAMAGOTCHI_H
#define PTAMAGOTCHI_H
#include <iostream>
#include <QString>
#include <QTimer>
#include "pilas.h"
#include "nodo.h"
#include "colas.h"
#include <stdlib.h>
#include <ctime>
using namespace std;

class PTamagotchi
{
public:
    PTamagotchi(QString Name, QString Resist);
    int estado, E, S, D, H, Logllenado;
    QString nombre;
    QString resistencia;
    Pilas* Sueno;
    Pilas* Hambre;
    Pilas* Enfermedad;
    Pilas* Desechos;
    Colas* Regalos;
    Colas* Monedas;
    Colas* LOG;
    void Sacar(char V);
    void Hambruna();
    void Cansancio();
    void Enfermo();
    void CC();
    void AbrirRegalo();
    void EnviarMoneda(PTamagotchi* tamagotchi);
    void Regalar();
    void TipoRegalo(int tipo);
    void Danio(int tipo);
    void LlenandoLOG(bool VD);
    void Derrotas();
    void Victorias();

    ~PTamagotchi();
};

#endif // PTAMAGOTCHI_H
