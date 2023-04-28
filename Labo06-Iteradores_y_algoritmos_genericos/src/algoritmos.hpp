#ifndef ALGO2_LABO_CLASE5_ALGORITMOS_H
#define ALGO2_LABO_CLASE5_ALGORITMOS_H

#include <utility>
#include <iterator>
#include <vector>

// Ejercicio 1
template<class Contenedor>
typename Contenedor::value_type minimo(const Contenedor& c){
    auto min = c.begin();
    for(auto it = c.begin(); it != c.end(); it++){
        if(*it < *min){
            min = it;
        }
    }
    return *min;
}

// Ejercicio 2
template<class Contenedor>
typename Contenedor::value_type promedio(const Contenedor& c){
    typename Contenedor::value_type suma = 0, n = 0;
    for(auto it = c.begin(); it != c.end(); it++){
        suma = suma + *it;
        n++;
    }
    typename Contenedor::value_type prom = suma/n;
    return prom;
}

// Ejericicio 3
template<class Iterator>
typename Iterator::value_type minimoIter(const Iterator& desde, const Iterator& hasta){
    typename Iterator::value_type min = *desde;
    for(auto it = desde; it != hasta; it++){
        if(*it <= min){
            min = *it;
        }
    }
    return min;
}

template<class Iterator>
typename Iterator::value_type promedioIter(const Iterator& desde, const Iterator& hasta){
    typename Iterator::value_type suma = 0, n = 0;
    for(auto it = desde; it != hasta; it++){
        suma = suma + *it;
        n++;
    }
    typename Iterator::value_type prom = suma/n;
    return prom;
}

// Ejercicio 4
template<class Contenedor>
void filtrar(Contenedor &c, const typename Contenedor::value_type& elem){
    for(auto it = c.begin(); it != c.end(); it++){
        if(*it == elem){
            it = c.erase(it);
            it--;
        }
    }
}

// Ejercicio 5
template<class Contenedor>
bool ordenado(Contenedor &c){
    // la coleccion vacia es ordenada
    if(c.begin() == c.end()){
        return true;
    }

    auto actual = c.begin();
    bool res =  true;
    for(auto it = c.begin(); it != --c.end(); it++){
        actual++;
        if(*actual < *it){
            res = false;
            break;
        }
    }
    return res;
}

// Ejercicio 6
template<class Contenedor>
std::pair<Contenedor, Contenedor> split(const Contenedor & c, const typename Contenedor::value_type& elem){
    Contenedor men;
    Contenedor may;
    for(auto it = c.begin(); it != c.end(); it++){
        if(*it < elem){
            men.insert(men.end(), *it);
        }else{
            may.insert(may.end(), *it);
        }
    }
    return make_pair(men, may);
}


// Ejercicio 7
template <class Contenedor>
void merge(const Contenedor& c1, const Contenedor & c2, Contenedor & res){
    auto it_1 = c1.begin(), it_2 = c2.begin();
    while(it_1 != c1.end() && it_2 != c2.end()){
        if(*it_1 < *it_2){
            res.insert(res.end(), *it_1);
            it_1++;
        }else{
            res.insert(res.end(), *it_2);
            it_2++;
        }
    }

    // ahora analizo los casos para cuando mis contenedores tienen distinto tamaño
    while(it_1 != c1.end()){
        res.insert(res.end(), *it_1);
        it_1++;
    }

    while(it_2 != c2.end()){
        res.insert(res.end(), *it_2);
        it_2++;
    }

}

#endif //ALGO2_LABO_CLASE5_ALGORITMOS_H