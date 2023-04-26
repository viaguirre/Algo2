#include "SistemaDeMensajes.h"

SistemaDeMensajes::SistemaDeMensajes():_conns(){}

SistemaDeMensajes::~SistemaDeMensajes(){
    for (int id = 0; id < 4; id++) {
        delete _conns[id];
    }
}

void SistemaDeMensajes::registrarJugador(int id, string ip){
    desregistrarJugador(id);
    _conns[id] = new ConexionJugador(ip);
}

void SistemaDeMensajes::desregistrarJugador(int id){
    if(registrado(id)){
        delete _conns[id];
        _conns[id] = nullptr;
    }
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje){
    _conns[id]->enviarMensaje(mensaje);
}

bool SistemaDeMensajes::registrado(int id) const{
    return _conns[id] != nullptr;
}

string SistemaDeMensajes::ipJugador(int id) const{
    return _conns[id]->ip();
}