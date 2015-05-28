#include "jugar.h"
#include "ui_jugar.h"
#include <QTimer>

Jugar::Jugar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Jugar)
{
    ui->setupUi(this);
    interacciones = 0;
    espera = 0;
    cont = 0;
    cont2 = 0;
}

void Jugar::Transcurso(){
    //srad();
    if(!MuerteT()){
        llenarMR();
        srand(time(0));
        int aletorio = 1+(rand()%4);
        switch (aletorio) {
        case 1:
            ui->Hambre->clear();
            //Estado();
            Granja[ui->Granja->currentIndex()].Hambruna();
            Llenar('H');

            break;

        case 2:
            ui->Suenio->clear();
            //Estado();
            Granja[ui->Granja->currentIndex()].Cansancio();
            Llenar('S');

            break;

        case 3:
            ui->Desechos->clear();
            //Estado();
            Granja[ui->Granja->currentIndex()].CC();
            Llenar('D');

            break;

        case 4:
            ui->Enfermo->clear();
            //Estado();
            Granja[ui->Granja->currentIndex()].Enfermo();
            Llenar('E');

            break;

        }
        Estado();

        if(interacciones==10){
            Granja[ui->Granja->currentIndex()].Victorias();
            interacciones = 0;
        }
        interacciones++;
        Granja[ui->Granja->currentIndex()].Derrotas();

        if(espera == 0){
            ui->Abrir->setEnabled(true);
            ui->Alimentar->setEnabled(true);
            ui->Dormir->setEnabled(true);
            ui->Limpiar->setEnabled(true);
            ui->Curar->setEnabled(true);
            ui->Regalar->setEnabled(true);
            ui->Cambiar->setEnabled(true);
        }else{
            espera--;
        }
    }
    else{
        ui->Abrir->setEnabled(false);
        ui->Alimentar->setEnabled(false);
        ui->Dormir->setEnabled(false);
        ui->Limpiar->setEnabled(false);
        ui->Curar->setEnabled(false);
        ui->Regalar->setEnabled(false);
        ui->Elegir->setEnabled(false);
        ui->Cambiar->setEnabled(true);
        ui->Estado->setValue(0);
        ui->Imprimir->addItem("TAMAGOCHI MUERTO");
        timer->stop();
    }
}

void Jugar::Llenar(char w){
    if(w=='H'){
        if(Granja[ui->Granja->currentIndex()].Hambre->Tope){
            Nodo* temp = Granja[ui->Granja->currentIndex()].Hambre->Tope;
            //cout<<"entro"<<endl;
            while(temp){
                ui->Hambre->addItem(QString::number(temp->valor));
                temp = temp->ant;
            }
        }
    }
    if(w=='S'){
        if(Granja[ui->Granja->currentIndex()].Sueno->Tope){
            Nodo* temp = Granja[ui->Granja->currentIndex()].Sueno->Tope;
            //cout<<"entro"<<endl;
            while(temp){
                ui->Suenio->addItem(QString::number(temp->valor));
                temp = temp->ant;
            }
        }
    }
    if(w=='E'){
        if(Granja[ui->Granja->currentIndex()].Enfermedad->Tope){
            Nodo* temp = Granja[ui->Granja->currentIndex()].Enfermedad->Tope;
            //cout<<"entro"<<endl;
            while(temp){
                ui->Enfermo->addItem(QString::number(temp->valor));
                temp = temp->ant;
            }
        }
    }
    if(w=='D'){
        if(Granja[ui->Granja->currentIndex()].Desechos->Tope){
            Nodo* temp = Granja[ui->Granja->currentIndex()].Desechos->Tope;
            //cout<<"entro"<<endl;
            while(temp){
                ui->Desechos->addItem(QString::number(temp->valor));
                temp = temp->ant;
            }
        }
    }
}
void Jugar::Estado(){
    ui->Estado->setValue(Granja[ui->Granja->currentIndex()].estado);
    switch (Resistencia()) {
        case 1:
            Granja[ui->Granja->currentIndex()].Danio(1);
        break;

        case 2:
            Granja[ui->Granja->currentIndex()].Danio(2);
        break;

        case 3:
            Granja[ui->Granja->currentIndex()].Danio(3);
        break;

        case 4:
            Granja[ui->Granja->currentIndex()].Danio(4);
        break;
    }
}

void Jugar::limpiarlist(){
    ui->Hambre->clear();
    ui->Suenio->clear();
    ui->Enfermo->clear();
    ui->Desechos->clear();
}

int Jugar::Resistencia(){
    QString temp = Granja[ui->Granja->currentIndex()].resistencia;
    if(temp=="INSOMNIO"){
        //cout<<"S"<<endl;
        return 2;
    }

    if(temp=="INMUNE"){
        //cout<<"E"<<endl;
        return 4;
    }

    if(temp=="AYUNADOR"){
        //cout<<"H"<<endl;
        return 1;
    }

    if(temp=="ESTRENIDO"){
        //cout<<"D"<<endl;
        return 3;
    }

    return -1;
}

Jugar::~Jugar()
{
    delete ui;
}
bool Jugar::buscar(){
    for(vector<PTamagotchi>::iterator p = Granja.begin(); p!= Granja.end(); p++){
        if((*p).nombre==ui->Nombre->text())
            return true;
    }
    return false;
}

void Jugar::Desactivar(){
    ui->Abrir->setEnabled(false);
    ui->Alimentar->setEnabled(false);
    ui->Dormir->setEnabled(false);
    ui->Limpiar->setEnabled(false);
    ui->Curar->setEnabled(false);
    ui->Regalar->setEnabled(false);
    ui->Cambiar->setEnabled(false);
}

void Jugar::llenarMR(){
    if(Granja[ui->Granja->currentIndex()].Monedas->frente){
        Nodo* temp = Granja[ui->Granja->currentIndex()].Monedas->frente;
        //cout<<"entro"<<endl;
        cont = 0;
        while(temp != NULL){
            cont++;
            temp = temp->ant;
        }
        ui->Monedas->setText(QString::number(cont));
    }
    if(Granja[ui->Granja->currentIndex()].Regalos->frente){
        Nodo* temp = Granja[ui->Granja->currentIndex()].Regalos->frente;
        cont2 = 0;
        //cout<<"entro"<<endl;
        while(temp!=NULL){
            cont2++;
            temp = temp->ant;
        }
        ui->Regalos->setText(QString::number(cont2));
    }
}

void Jugar::on_Crear_clicked()
{
    if(ui->Nombre->text()!="" && !buscar()){
    ui->Granja->clear();
    ui->Para->clear();
    Granja.push_back(PTamagotchi(ui->Nombre->text(),ui->Tipo->currentText()));
    for(vector<PTamagotchi>::iterator p = Granja.begin(); p!= Granja.end(); p++){
            ui->Granja->addItem((*p).nombre);
            ui->Para->addItem((*p).nombre);
    }
    ui->Granja->setEnabled(true);
    ui->Elegir->setEnabled(true);
    }
}


void Jugar::on_Elegir_clicked()
{
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(Transcurso()));
    timer->start(5000);
    limpiarlist();
    ui->Abrir->setEnabled(true);
    ui->Alimentar->setEnabled(true);
    ui->Dormir->setEnabled(true);
    ui->Limpiar->setEnabled(true);
    ui->Curar->setEnabled(true);
    ui->Regalar->setEnabled(true);
    ui->Cambiar->setEnabled(true);
    ui->Para->setEnabled(true);
    ui->Granja->setEnabled(false);
    ui->Elegir->setEnabled(false);
    ui->Nombre->setEnabled(false);
    ui->Tipo->setEnabled(false);
    ui->Crear->setEnabled(false);
    ui->Estado->setValue(Granja[ui->Granja->currentIndex()].estado);
    ui->Imprimir->clear();
    Llenar('H');
    Llenar('S');
    Llenar('D');
    Llenar('E');
}


void Jugar::on_Alimentar_clicked()
{
    ui->Hambre->clear();
    Granja[ui->Granja->currentIndex()].Sacar('H');
    Llenar('H');
    espera = 3;
    Desactivar();
}

void Jugar::on_Dormir_clicked()
{
    ui->Suenio->clear();
    Granja[ui->Granja->currentIndex()].Sacar('S');
    Llenar('S');
    espera = 3;
    Desactivar();
}

void Jugar::on_Curar_clicked()
{
    ui->Enfermo->clear();
    Granja[ui->Granja->currentIndex()].Sacar('E');
    Llenar('E');
    espera = 3;
    Desactivar();
}

void Jugar::on_Limpiar_clicked()
{
    ui->Desechos->clear();
    Granja[ui->Granja->currentIndex()].Sacar('D');
    Llenar('D');
    espera = 3;
    Desactivar();
}

void Jugar::on_Cambiar_clicked()
{
    timer->stop();
    ui->Abrir->setEnabled(false);
    ui->Alimentar->setEnabled(false);
    ui->Dormir->setEnabled(false);
    ui->Limpiar->setEnabled(false);
    ui->Curar->setEnabled(false);
    ui->Regalar->setEnabled(false);
    ui->Cambiar->setEnabled(false);
    ui->Para->setEnabled(false);
    ui->Granja->setEnabled(true);
    ui->Elegir->setEnabled(true);
    ui->Nombre->setEnabled(true);
    ui->Tipo->setEnabled(true);
    ui->Crear->setEnabled(true);
    cont = 0;
    cont2 = 0;
    ui->Monedas->clear();
    ui->Regalos->clear();
}

void Jugar::on_Regalar_clicked()
{
    string s1 = Granja[ui->Granja->currentIndex()].nombre.toStdString();
    string s2 = Granja[ui->Para->currentIndex()].nombre.toStdString();
    if(s1!=s2){
        cont--;
        //cout<<cont<<endl;
        Granja[ui->Granja->currentIndex()].EnviarMoneda(&Granja[ui->Para->currentIndex()]);

    }else{
        cout<<"NO SE PUEDE ENVIAR A ESTE DESTINARIO YA QUE SON EL MISMO"<<endl;

    }
    ui->Monedas->clear();
}

void Jugar::on_Abrir_clicked()
{
    Granja[ui->Granja->currentIndex()].AbrirRegalo();
    cont2--;
    ui->Regalos->clear();
}

void Jugar::log(){
    if(Granja[ui->Granja->currentIndex()].LOG->frente){
        Nodo* temp = Granja[ui->Granja->currentIndex()].LOG->frente;
        while(temp){
            if(temp->valor == 1){
                ui->Imprimir->addItem("Victoria");
            }else{
                ui->Imprimir->addItem("Derrota");
            }
            temp = temp->ant;
        }
    }
}

void Jugar::on_Cargar_clicked()
{
    ui->Imprimir->clear();
    log();
}
bool Jugar::MuerteT(){
    if(Granja[ui->Granja->currentIndex()].estado>0){
        return false;
    }
    return true;
}
