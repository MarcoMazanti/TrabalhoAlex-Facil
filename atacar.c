#include <stdlib.h>
#include "atacar.h"

void playerAtaca(Jogador *jogador, Monstro *monstro) {
    if (((rand() % 20) + jogador->iniciativa) > monstro->escudo) {
        receberDanoMonstro(monstro, ataqueJogador(jogador));
    }
}

void monstroAtaca(Monstro *monstro, Jogador *jogador) {
    if (((rand() % 20) + monstro->iniciativa) > jogador->escudo) {
        receberDanoJogador(jogador, ataqueMonstro(monstro));
    }
}