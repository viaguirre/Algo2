#include <vector>
#include "algobot.h"

using namespace std;

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    set<int> set_v;
    for(int i=0; i<s.size();i++){
        set_v.insert(s[i]);
    }
    vector<int> res;
    for(int k : set_v) {
       res.push_back(k);
    }
    return res;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    set<int> set_v;
    for(int i=0; i<s.size();i++){
        set_v.insert(s[i]);
    }
    vector<int> res;
    for(int k : set_v) {
        res.push_back(k);
    }
    return res;
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    bool res = true;
    set<int> set_a;
    for(int i : a){
        set_a.insert(i);
    }
    set<int> set_b;
    for(int j : b){
        set_b.insert(j);
    }

    for(int k: set_a){
        if(set_a.count(k) != set_b.count(k)){
            res = false;
        }
    }
    return res;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    bool res = true;
    set<int> set_a;
    for(int i : a){
        set_a.insert(i);
    }
    set<int> set_b;
    for(int j : b){
        set_b.insert(j);
    }

    for(int k: set_a){
        if(set_a.count(k) != set_b.count(k)){
            res = false;
        }
    }
    return res;
}

// Ejercicio 5
int apariciones (int n, vector<int> s){
    int res = 0;
    for(int i : s){
        if(i==n){
            res++;
        }
    }
    return res;
}

map<int, int> contar_apariciones(vector<int> s) {
    set<int> set_s;
    for(int i : s){
        set_s.insert(i);
    }
    map<int, int> res;
    for(int j : set_s){
        m[j]= apariciones()
        res.push_back(pair<j, apariciones(j,s)>);
    }

    return res;
}



// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    return vector<int>();
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    return set<int>();
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    return map<int, set<int>>();
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    return vector<char>();
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    return true;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
  return map<set<LU>, Mail>();
}
