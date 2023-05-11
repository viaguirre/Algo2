#include <iostream>
#include <list>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
            // ene, feb, mar, abr, may, jun
            31, 28, 31, 30, 31, 30,
            // jul, ago, sep, oct, nov, dic
            31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
public:
    Fecha(int mes, int dia);
    int mes();
    int dia();
#if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
#endif
    void incrementar_dia();

private:
    int mes_;
    int dia_;
};

Fecha::Fecha(int mes, int dia):mes_(mes), dia_(dia){}

int Fecha::mes(){
    return mes_;
}

int Fecha::dia(){
    return dia_;
}

ostream& operator<<(ostream& os, Fecha f) {
    os << f.dia() << "/" << f.mes();
    return os;
}

#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia();
    bool igual_mes = this-> mes() == o.mes();
    return igual_dia && igual_mes;
}
#endif

void Fecha::incrementar_dia(){
    if(dia_<dias_en_mes(mes_)){
        dia_++;
    }else{
        if(mes_<12){
            dia_=1;
            mes_++;
        }else{
            dia_=1;
            mes_=1;
        }
    }
}

// Ejercicio 11, 12

class Horario{
public:
    Horario(uint hora, uint min);
    uint hora();
    uint min();
    bool operator==(Horario o);
    bool operator<(Horario h);

private:
    int hora_;
    int min_;
};

Horario::Horario(uint hora, uint min): hora_(hora), min_(min){}

uint Horario::hora(){
    return hora_;
}

uint Horario::min(){
    return min_;
}

ostream& operator<<(ostream& os, Horario h) {
    os << h.hora() << ":" << h.min();
    return os;
}

bool Horario::operator==(Horario o) {
    bool igual_hora = this->hora() == o.hora();
    bool igual_min = this-> min() == o.min();
    return igual_hora && igual_min;
}

bool Horario::operator<(Horario h) {
    bool res = false;
    if(this->hora()==h.hora()){
        res = this-> min() < h.min();
    }else{
        res = this->hora() < h.hora();
    }
    return res;
}

// Ejercicio 13

class Recordatorio{
public:
    Recordatorio(Fecha fecha, Horario horario, string mensaje);
    Fecha fecha();
    Horario horario();
    string mensaje();
    bool operator<(Recordatorio r);


private:
    Fecha fecha_;
    Horario horario_;
    string mensaje_;
};

Recordatorio::Recordatorio(Fecha fecha, Horario horario, string mensaje):fecha_(fecha), horario_(horario), mensaje_(mensaje){}

Fecha Recordatorio::fecha(){
    return fecha_;
}

Horario Recordatorio::horario(){
    return horario_;
}

string Recordatorio::mensaje(){
    return mensaje_;
}

ostream& operator<<(ostream& os, Recordatorio r) {
    os << r.mensaje() << " @ " << r.fecha().dia() << "/" << r.fecha().mes() << " " << r.horario().hora() << ":" << r.horario().min();
    return os;
}
bool Recordatorio::operator<(Recordatorio r) {
    return this->horario()<r.horario();
}

// Ejercicio 14

class Agenda {
public:
    Agenda(Fecha fecha_inicial);
    void agregar_recordatorio(Recordatorio rec);
    void incrementar_dia();
    list<Recordatorio> recordatorios_de_hoy();
    Fecha hoy();

private:
    Fecha hoy_;
    list<Recordatorio> recordatorios_de_hoy_;
};

Agenda::Agenda(Fecha fecha_inicial): hoy_(fecha_inicial) {}

Fecha Agenda::hoy(){
    return hoy_;
}

list<Recordatorio> Agenda::recordatorios_de_hoy(){
    list<Recordatorio> rec;
    for(Recordatorio r: recordatorios_de_hoy_){
        if(r.fecha() == hoy_){
            rec.push_back(r);
        }
    }
    rec.sort();
    return rec;
}

void Agenda::agregar_recordatorio(Recordatorio rec){
    recordatorios_de_hoy_.push_back(rec);
}

void Agenda::incrementar_dia() {
    if (hoy_.dia() < dias_en_mes(hoy_.mes())) {
        hoy_ = Fecha(hoy_.mes(), hoy_.dia() + 1);
    } else {
        if (hoy_.mes() < 12) {
            hoy_ = Fecha(hoy_.mes() + 1, 1);
        } else {
            hoy_ = Fecha(1, 1);
        }
    }
}

ostream& operator<<(ostream& os, Agenda a) {
    os << a.hoy().dia() << "/" << a.hoy().mes() << endl;
    os << "=====" << endl;
    for(Recordatorio r: a.recordatorios_de_hoy()){
        os << r.mensaje() << " @ " << r.fecha().dia() << "/" << r.fecha().mes() << " " << r.horario().hora() << ":" << r.horario().min() << endl;
    }
    return os;
}