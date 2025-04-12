#ifndef BATALHA_H
#define BATALHA_H

#include "atacar.h"

typedef struct {
    char name[50];
    int iniciativa;
} OrdemJogada;

void batalhar(Jogador *jogador, Jogador *ajudante, Monstro *monstros[], int quantMonstros);

#endif