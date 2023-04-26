#include "Lista.h"
#include <cassert>

Lista::Lista(): prim(nullptr), ult(nullptr){
}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
   destruirNodos();
}

Lista& Lista::operator=(const Lista& aCopiar) {
    destruirNodos();
    copiarNodos(aCopiar);
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    Nodo* nuevo = new Nodo(elem, nullptr, nullptr);
    if (prim == nullptr) {
        prim = nuevo;
        ult = nuevo;
    }else{
        prim -> ant = nuevo;
        nuevo-> sig = prim;
        prim = nuevo;
    }
}

void Lista::agregarAtras(const int& elem){
    Nodo* nuevo = new Nodo(elem, nullptr, nullptr);
    if(prim == nullptr){
        prim = nuevo;
        ult = nuevo;
    }else{
        ult->sig = nuevo;
        nuevo->ant = ult;
        ult = nuevo;
    }
}

void Lista::eliminar(Nat i) {
    Nodo* actual = prim;
    for(int j=0; j<i; j++){
        actual=actual->sig;
    }

    Nodo* anterior = actual->ant;
    Nodo* siguiente = actual->sig;
    delete actual;

    if(anterior == nullptr){
        prim = siguiente;
    }else{
        anterior->sig = siguiente;
    }

    if(siguiente == nullptr){
        ult = anterior;
    }else{
        siguiente->ant = anterior;
    }
}

int Lista::longitud() const {
    Nodo* actual = prim;
    int res = 0;
    while (actual != nullptr) {
        actual = actual->sig;
        res++;
    }
    return res;
}

const int& Lista::iesimo(Nat i) const {
    Nodo* actual = prim;
    int j = 0;
    while(j < i){
        actual = actual->sig;
        j++;
    }
    return actual->valor;
}

int& Lista::iesimo(Nat i) {
    Nodo* actual = prim;
    int j = 0;
    while(j < i){
        actual = actual->sig;
        j++;
    }
    return actual->valor;
}

void Lista::mostrar(ostream& o) {
    // Completar
}

void Lista::copiarNodos(const Lista& aCopiar) {
    Nodo* actual = aCopiar.prim;
    while (actual != NULL) {
        agregarAtras(actual->valor);
        actual = actual->sig;
    }
}

void Lista::destruirNodos() {
    Nodo* actual = prim;
    while (actual != nullptr) {
        Nodo* siguiente = actual->sig;
        delete actual;
        actual = siguiente;
    }
    prim = nullptr;
    ult = nullptr;
}