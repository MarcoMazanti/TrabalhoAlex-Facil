#include <stdlib.h>
#include "atacar.h"

// Função responsável por fazer o jogador atacar o monstro
void playerAtaca(Jogador *jogador, Monstro *monstro) {
    if (((rand() % 20) + jogador->iniciativa + 1) > monstro->escudo) {
        receberDanoMonstro(monstro, ataqueJogador(jogador));
    }
}

// Função responsável por fazer o monstro atacar o jogador
void monstroAtaca(Monstro *monstro, Jogador *jogador) {
    if (((rand() % 20) + monstro->iniciativa + 1) > jogador->escudo) {
        receberDanoJogador(jogador, ataqueMonstro(monstro));
    }
}
