//
// Created by Luiz Evangelista on 20/09/2021.
//

#ifndef LABIRINTO_PILHA_H
#define LABIRINTO_PILHA_H

#include <iostream>
#include <string>
#include <array>

using namespace std;

constexpr int MAXPILHA = 100;
using TipoDado = char;

class Pilha {
private:
    array<TipoDado, MAXPILHA> dados_;
    int topo_;
public:
    Pilha();
    void push(TipoDado elem);
    void pop();
    TipoDado topo();
    bool vazia();
    bool cheia();
};

#endif //LABIRINTO_PILHA_H
