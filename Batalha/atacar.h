#ifndef ATACAR_H
#define ATACAR_H

#include "../Jogador/jogador.h"
#include "../Ajudante/ajudante.h"
#include "../Monstro/monstro.h"

void playerAtaca(Jogador *jogador, Monstro *monstro);
void NPCAtaca(Jogador *ajudante, Monstro *monstro);
void monstroAtaca(Monstro *monstro, Jogador *jogador);

#endif