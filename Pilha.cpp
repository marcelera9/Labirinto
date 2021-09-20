#include <string>
#include <iostream>
#include <array>
#include "Pilha.h"

using namespace std;

Pilha::Pilha() {
    topo_ = -1;
}

bool Pilha::cheia() {
    if (topo_ == MAXPILHA-1)
        return true;
    else
        return false;
}

bool Pilha::vazia() {
    if(topo_ == -1)
        return true;
    else
        return false;
}

void Pilha::push(TipoDado elem) {
    if (!cheia()){
        ++topo_;
        dados_[topo_] = elem;
    } else
        cerr << "Pilha cheia" << endl;
}

void Pilha::pop(){
    if (!vazia())
        --topo_;
    else
        cerr << "Pilha vazia" << endl;
}

TipoDado Pilha::topo() {
    if (!vazia())
        return dados_[topo_];
    else {
        cerr << "Pilha vazia" << endl;
        return -1;
    }
}