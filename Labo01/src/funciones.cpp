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
        res[j]= apariciones(j,s);
    }
    return res;
}



// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    set<int> set_s;
    for(int i : s){
        set_s.insert(i);
    }
    vector<int> res;
    for(int j : set_s){
        if(contar_apariciones(s)[j]==1){
            res.push_back(j);
        }
    }
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res;
    for(int i : a){
        if(a.count(i)==b.count(i)){
            res.insert(i);
        }
    }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> res;
    for(int i = 0; i < 10; i++){
        for(int j : s){
            if(j % 10 == i){
                res[i].insert(j);
            }
        }
    }
    return res;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> res;
    for(char i : str){
        bool as = false;
        for(auto j: tr){
            if(get<0>(j) == i){
                res.push_back(get<1>(j));
                as = true;
            }
        }
        if(as == false){
            res.push_back(i);
        }
    }
    return res;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    bool res = false;
    for(Mail i: s) {
        for (Mail j: s) {
            if (i.libretas() != j.libretas()) {
                for (LU l: i.libretas()) {
                    if (j.libretas().count(l) == 1) {
                        res = true;
                    }
                }
            }
        }
    }
    return res;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<set<LU>, Mail> res;
    set<Mail> s_asunto;
    for(Mail m : s){
        if(m.adjunto() &&  m.fecha() > res[m.libretas()].fecha()){
            res[m.libretas()] = m;
        }
    }
    return res;
}