#ifndef JUGAR_H
#define JUGAR_H
#include <QDialog>
#include "ptamagotchi.h"
#include "pilas.h"
#include "nodo.h"
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
namespace Ui {
class Jugar;
}

class Jugar : public QDialog
{
    Q_OBJECT

public:
    explicit Jugar(QWidget *parent = 0);
    ~Jugar();
    QTimer* timer;
    vector<PTamagotchi> Granja;
    int interacciones, espera, cont, cont2;
    void Llenar(char w);
    void Estado();
    bool buscar();
    void limpiarlist();
    void Desactivar();
    int Resistencia();
    void llenarMR();
    void log();
    bool MuerteT();
public slots:
    void Transcurso();

private slots:
    void on_Crear_clicked();

    void on_Elegir_clicked();

    void on_Alimentar_clicked();

    void on_Dormir_clicked();

    void on_Curar_clicked();

    void on_Limpiar_clicked();

    void on_Cambiar_clicked();

    void on_Regalar_clicked();

    void on_Abrir_clicked();

    void on_Cargar_clicked();

private:
    Ui::Jugar *ui;
};

#endif // JUGAR_H
