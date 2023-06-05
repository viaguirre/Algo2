#include"string_map.h"

template <typename T>
string_map<T>::string_map(): raiz(nullptr),_size(0){}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    if (d.raiz != nullptr) {
        destruirNodos(raiz);
        raiz = new Nodo;
        _size = d._size;
        copiarAux(d.raiz, raiz);
    }
    return *this;
}

template <typename T>
void string_map<T>::copiarAux(Nodo* nodo1, Nodo* nodo2){
    if (nodo1->definicion != nullptr) {
        nodo2->definicion = new T;
        *(nodo2->definicion) = *(nodo1->definicion);
    }
    for(int i = 0; i < 256; i++) {
        if(nodo1->siguientes[i] != nullptr){
            if(nodo2->siguientes[i] == nullptr){
                nodo2->siguientes[i] = new Nodo();
            }
            copiarAux(nodo1->siguientes[i], nodo2->siguientes[i]);
        }
    }
}

template <typename T>
string_map<T>::~string_map(){
    destruirNodos(raiz);
}

template <typename T>
void string_map<T>::destruirNodos(Nodo* nodo){
    if (nodo != nullptr) {
        for (int i = 0; i < 256; i++) {
            destruirNodos(nodo->siguientes[i]);
        }
        delete nodo->definicion;
        delete nodo;
    }
}

template <typename T>
void string_map<T>::insert(const pair<string, T>& par){
    if(raiz == nullptr){ // si el nodo está vacío creo un nuevo Nodo al que apunta la raiz
        raiz = new Nodo();
    }
    Nodo* actual = raiz;
    for(char c: par.first){ //recorro el trie para ver donde debe ir la nueva clave
        if(actual->siguientes[c] == nullptr){
            actual->siguientes[c] = new Nodo();
        }
        actual = actual->siguientes[c];
    }
    delete actual->definicion;
    actual->definicion = new T;
    *(actual->definicion) = par.second;//asigno como significado del nodo encontrado el significado recibido por parametro
    _size ++;
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR
}


template <typename T>
int string_map<T>::count(const string& clave) const{
    if (empty()) {
        return 0;
    }
    Nodo* actual = raiz;
    for (char c: clave) {
        if (actual->siguientes[c] == nullptr) {  // si en siguientes del nodo actual ese caracter apunta a null, devuelvo 0
            return 0;
        }
        actual = actual->siguientes[c];
    }
    if(actual->definicion != nullptr){ // pregunto si el nodo que representa la clave tiene un significado definido
        return 1;
    }
}


template <typename T>
const T& string_map<T>::at(const string& clave) const {
    Nodo* actual = raiz;
    for(char c: clave){
        if(actual->siguientes[c] == nullptr){
            actual->siguientes[c] = new Nodo();
        }
        actual = actual->siguientes[c];
    }
    return *(actual->definicion);
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    Nodo* actual = raiz;
    for(char c: clave){
        if(actual->siguientes[c] == nullptr){
            actual->siguientes[c] = new Nodo();
        }
        actual = actual->siguientes[c];
    }
    return *(actual->definicion);
}

/*template <typename T>
void string_map<T>::erase(const string& clave) {
    Nodo* actual = raiz;
    for (int i = 0; i < clave.size(); i++) {
        actual = actual->siguientes[clave[i]];
    }
    delete actual->definicion;
    actual->definicion = nullptr;
    _size--;
}*/


template <typename T>
void string_map<T>::erase(const string& clave) { // sigo paso a paso las diapos
    Nodo* actual = raiz;
    Nodo* ultimo = nullptr;
    int indice_ultimo = -1;
    for(int i = 0; i < clave.size(); i++){
        if(tieneHijos(actual) || actual->definicion != nullptr ){ //Si el nodo actual tiene mas de un hijo o tiene significado, el ultimo nodo es el nodo actual y ultimo ındice es nuestra posicion en la clave.
            ultimo = actual; //ultimo nodo es el ultimo nodo en el camino de la clave que no hay que borrar.
            indice_ultimo = i;
        }
        actual = actual->siguientes[clave[i]]; //Avanzamos el nodo actual bajando por el siguiente caracter de la clave y avanzamos nuestra posicion en la clave.
    }

    delete actual->definicion; // nodo actual es el nodo de la clave. Borramos su significado.
    actual->definicion = nullptr;
    _size--;

    if (!tieneHijos(actual)) { //Si nodo actual no tiene hijos, borramos los descendientes de ultimo nodo
        for (int j = clave.size(); j > indice_ultimo; j--) {
            delete ultimo->siguientes[clave[j]];
            ultimo = ultimo->siguientes[clave[j]];
        }
    }
}

template<typename T>
bool string_map<T>::tieneHijos(Nodo* nodo){
    bool res = false;
    for(int i = 0; i<256; i++){
        if(nodo->siguientes[i] != nullptr){
            res = true;
        }
    }
    return res;
}

template <typename T>
int string_map<T>::size() const{
    return _size;
}

template <typename T>
bool string_map<T>::empty() const{
    return _size == 0;
}

