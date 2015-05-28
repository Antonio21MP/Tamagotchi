#include "ptamagotchi.h"

PTamagotchi::PTamagotchi(QString Name, QString Resist)
{
    estado = 100;
    S = 0;
    D = 0;
    H = 0;
    E = 0;
    Logllenado = 0;
    nombre = Name;
    resistencia = Resist;
    Sueno = new Pilas();
    Hambre = new Pilas();
    Enfermedad = new Pilas();
    Desechos = new Pilas();
    Monedas = new Colas();
    Regalos = new Colas();
    LOG = new Colas();
}

PTamagotchi::~PTamagotchi()
{

}
void PTamagotchi::Sacar(char V){
    switch (V) {
    case 'S':
        Sueno->Sacar();
        if(S>0)
        S--;
        break;
    case 'H':
        Hambre->Sacar();
        if(H>0)
        H--;
        break;
    case 'E':
        Enfermedad->Sacar();
        if(E>0)
        E--;
        break;
    case 'D':
        Desechos->Sacar();
        if(D>0)
        D--;
        break;
    }
}

void PTamagotchi::Hambruna(){
    if(H<4){
        H++;
        //cout<<H<<endl;
        Nodo* temp = new Nodo(H);
        Hambre->Meter(temp);

    }
}

void PTamagotchi::Enfermo(){
    if(E<4){
        E++;
        Nodo* temp = new Nodo(E);
        Enfermedad->Meter(temp);
    }
}

void PTamagotchi::Cansancio(){
    if(S<4){
        S++;
        Nodo* temp = new Nodo(S);
        Sueno->Meter(temp);

    }
}

void PTamagotchi::CC(){
    if(D<4){
        D++;
        Nodo* temp = new Nodo(D);
        Desechos->Meter(temp);

    }
}
void PTamagotchi::Regalar(){
    Monedas->QuitarCola();
}

void PTamagotchi::EnviarMoneda(PTamagotchi* tamagotchi){
    if(!Monedas->Vacia()){
        cout<<"enviado"<<endl;
        tamagotchi->Regalos->PonerCola(Monedas->getFrente());
        Regalar();
    }
}
void PTamagotchi::AbrirRegalo(){
    if(!Regalos->Vacia()){
        cout<<"lo abrio"<<endl;
        int temp = Regalos->frente->valor;
        TipoRegalo(temp);
        Regalos->QuitarCola();
    }
}

void PTamagotchi::TipoRegalo(int tipo){
    switch (tipo) {
    //QUITA TODA EL HAMBRE
    case 1:
        Hambre->Anular();
        break;
    //QUITA TODO EL SUEÑO
    case 2:
        Sueno->Anular();
        break;
    //QUITA TODOS LOS DESECHOS
    case 3:
        Desechos->Anular();
        break;
    //QUITA TODAS LAS ENFERMEDADES
    case 4:
        Enfermedad->Anular();
        break;
    }
}
void PTamagotchi::Danio(int tipo){
    if(estado>0){

        switch (tipo) {
        case 1:
            if(!Hambre->Vacia()){
                int temp = H;
                estado -= (temp-1);
            }
            if(!Sueno->Vacia()){
                estado -= S;
            }
            if(!Enfermedad->Vacia()){
                estado -= E;
            }
            if(!Desechos->Vacia()){
                estado -= D;
            }
            break;

        case 2:
            if(!Hambre->Vacia()){
                estado -= H;
            }
            if(!Sueno->Vacia()){
                int temp = S;
                estado -= (temp-1);
            }
            if(!Enfermedad->Vacia()){
                estado -= E;
            }
            if(!Desechos->Vacia()){
                estado -= D;
            }
            break;

        case 3:
            if(!Hambre->Vacia()){
                estado -= H;
            }
            if(!Sueno->Vacia()){
                estado -= S;
            }
            if(!Enfermedad->Vacia()){
                estado -= E;
            }
            if(!Desechos->Vacia()){
                int temp = D;
                estado -= (temp-1);
            }
            break;

        case 4:
            if(!Hambre->Vacia()){
                estado -= H;
            }
            if(!Sueno->Vacia()){
                estado -= S;
            }
            if(!Enfermedad->Vacia()){
                int temp = E;
                estado -= (temp-1);
            }
            if(!Desechos->Vacia()){
                estado -= D;
            }
            break;
        }

    }else{
        estado = 0;
    }
}

void PTamagotchi::Derrotas(){

    if(Sueno->Tope && Sueno->Tope->valor==4){
       cout<<"Derrota"<<endl;
        LlenandoLOG(false);
    }
    if(Hambre->Tope && Hambre->Tope->valor==4){
        cout<<"Derrota"<<endl;
        LlenandoLOG(false);
    }
    if(Desechos->Tope && Desechos->Tope->valor==4){
        cout<<"Derrota"<<endl;
        LlenandoLOG(false);
    }
    if(Enfermedad->Tope && Enfermedad->Tope->valor==4){
        cout<<"Derrota"<<endl;
        LlenandoLOG(false);
    }
}
void PTamagotchi::Victorias(){
    if((!Sueno->Tope || Sueno->Tope->valor<4) && (!Hambre->Tope || Hambre->Tope->valor<4)
      && (!Desechos->Tope || Desechos->Tope->valor<4) && (!Enfermedad->Tope || Enfermedad->Tope->valor<4)){
        cout<<"Victoria"<<endl;
        srand(time(0));
        int aletorio = 1+(rand()%4);
        Monedas->PonerCola(new Nodo(aletorio));
        LlenandoLOG(true);
    }
}

void PTamagotchi::LlenandoLOG(bool VD){
    if(Logllenado<=8){
        if(VD){
            Nodo* temp = new Nodo(1);
            LOG->PonerCola(temp);
            Logllenado++;
        }
        else{
            Nodo* temp = new Nodo(2);
            LOG->PonerCola(temp);
            Logllenado++;
        }
    }else{
        LOG->QuitarCola();
        Logllenado--;
    }
}
