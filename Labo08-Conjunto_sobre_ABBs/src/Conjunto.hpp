#include"Conjunto.h"

template <class T>
Conjunto<T>::Conjunto(): _raiz(nullptr) {}

template <class T>
Conjunto<T>::~Conjunto() {
    if(_raiz != nullptr){
        destruirNodos(_raiz);
    }
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    Nodo* actual = _raiz;
    bool res = false;
    while(actual != nullptr && !res){
        if(clave == actual->valor){
            res = true;
        }else{
            if(clave < actual->valor) {
                actual = actual->izq;
            }else{
                actual = actual->der;
            }
        }
    }
    return res;
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    if (!pertenece(clave)) {
        Nodo* actual = _raiz;
        Nodo* anterior = nullptr;
        while (actual != nullptr) {
            anterior = actual;
            if (clave < actual->valor) {
                actual = actual->izq;
            } else {
                actual = actual->der;
            }
        }
        Nodo* nuevoNodo = new Nodo(clave);
        if (anterior == nullptr) {
            _raiz = nuevoNodo;
        } else {
            if (clave < anterior->valor) {
                anterior->izq = nuevoNodo;
            } else {
                anterior->der = nuevoNodo;
            }
        }
    }
}

template <class T>
void Conjunto<T>::remover(const T& clave) {
    if(pertenece(clave)){
        Nodo* actual = _raiz;
        Nodo* padre = nullptr;
        while(actual->valor != clave){//busco el nodo que tiene la clave y a su padre
            padre = actual;
            if(clave < actual->valor){
                actual = actual->izq;
            }else{
                actual = actual->der;
            }
        }
        if(actual->izq == nullptr && actual->der == nullptr){ //caso hoja
            if (actual == _raiz) { //por si el nodo que quiero borrar es raiz y hoja
                _raiz = nullptr;
            }else{
                if(padre->izq == actual){
                    padre->izq = nullptr;
                }else{
                    padre->der = nullptr;
                }
            }
            delete actual;
        }else{
            if(actual->izq == nullptr || actual->der == nullptr){ // caso 1 solo hijo
                Nodo* hijo = nullptr;
                if(actual->izq == nullptr){
                    hijo = actual->der; //caso solo hijo derecho
                }else{
                    hijo = actual->izq; // caso solo hijo izquierdo
                }
                if(actual == _raiz){ // reestructuro el arbol
                    _raiz = hijo;
                }else{
                    if(actual == padre->izq){
                        padre->izq = hijo;
                    }else{
                        padre->der = hijo;
                    }
                }
                delete actual;
            }else{ // caso 2 hijos
                Nodo* sucesor = actual->der;
                padre = actual;
                while (sucesor->izq != nullptr) {
                    padre = sucesor;
                    sucesor = sucesor->izq;
                }
                actual->valor = sucesor->valor; //copio el nodo
                if (padre == actual) {
                    padre->der = sucesor->der;
                } else {
                    padre->izq = sucesor->der;
                }
                delete sucesor;
            }
        }
    }
}


template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    Nodo* actual = _raiz;
    vector<Nodo*> anteriores;
    while(clave != actual->valor){ //itero hasta llegar al nodo que tiene como valor a la clave
        anteriores.push_back(actual);
        if(clave < actual->valor){
            actual = actual->izq;
        }else{
            actual = actual->der;
        }
    }
    if(actual->der != nullptr){
        actual = actual->der;
        while(actual->izq != nullptr){
            actual = actual->izq;
        }
        return actual->valor;
    }else{
        Nodo* anterior = actual;
        while (anteriores.size() != 0 && !(clave < anterior->valor)) {
            anterior =  anteriores[anteriores.size()-1];
            anteriores.pop_back();
        }
        return anterior->valor;
    }
}


template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo* actual = _raiz;
    while(actual->izq != nullptr){
        actual = actual->izq;
    }
    return actual->valor;
}

template <class T>
const T& Conjunto<T>::maximo() const {
    Nodo* actual = _raiz;
    while(actual->der != nullptr){
        actual = actual->der;
    }
    return actual->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return _cardinal(_raiz);
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

template <class T>
void Conjunto<T>::destruirNodos(Nodo* nodo){
    if(nodo == nullptr){
        return;
    }
    destruirNodos(nodo->izq);
    destruirNodos(nodo->der);
    delete nodo;
}

template <class T>
unsigned int Conjunto<T>::_cardinal(Nodo* nodo) const{
    if(nodo == nullptr){
        return 0;
    }
    unsigned int res = 1;
    res = res + _cardinal(nodo->izq) + _cardinal(nodo->der);
    return res;
}

