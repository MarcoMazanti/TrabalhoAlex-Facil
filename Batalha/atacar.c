#include <stdlib.h>
#include <stdio.h>
#include "atacar.h"

int debuffPlayer(Jogador *player) {
    int x = rand() % 20 + player->iniciativa + 1;
    int menorNum = rand() % 20 + player->iniciativa + 1;

    if (x < menorNum) {
        menorNum = x;
    }

    player->debuff = 'N';
    return menorNum;
}

int debuffMonstro(Monstro *monstro) {
    int x = rand() % 20 + monstro->iniciativa + 1;
    int menorNum = rand() % 20 + monstro->iniciativa + 1;

    if (x < menorNum) {
        menorNum = x;
    }

    monstro->debuff = 'N';
    return menorNum;
}

// Função responsável por fazer o jogador atacar o monstro
void playerAtaca(Jogador *jogador, Monstro *monstro) {
    for (int i = 0; i < 1 + (jogador->ataqueExtra == 'S' ? 1 : 0); i++) {
        if (jogador->debuff == 'S') {
            if (debuffPlayer(jogador) > monstro->escudo) {
                receberDanoMonstro(monstro, ataqueJogador(jogador));
            } else {
                printf("%s errou o ataque!\n", jogador->name);
            }
        } else {
            if (((rand() % 20) + jogador->iniciativa + 1) > monstro->escudo) {
                receberDanoMonstro(monstro, ataqueJogador(jogador));
            } else {
                printf("%s errou o ataque!\n", jogador->name);
            }
        }
    }
}

void NPCAtaca(Jogador *ajudante, Monstro *monstro) {
    for (int i = 0; i < 1 + (ajudante->ataqueExtra == 'S' ? 1 : 0); i++) {
        if (ajudante->debuff == 'S') {
            if (debuffPlayer(ajudante) > monstro->escudo) {
                receberDanoMonstro(monstro, ataqueAjudante(ajudante));
            } else {
                printf("%s errou o ataque!\n", ajudante->name);
            }
        } else {
            if (((rand() % 20) + ajudante->iniciativa + 1) > monstro->escudo) {
                receberDanoMonstro(monstro, ataqueAjudante(ajudante));
            } else {
                printf("%s errou o ataque!\n", ajudante->name);
            }
        }
    }
}

// Função responsável por fazer o monstro atacar o jogador
void monstroAtaca(Monstro *monstro, Jogador *jogador) {
    if (monstro->debuff == 'S') {
        if (debuffMonstro(monstro) > jogador->escudo) {
            receberDanoJogador(jogador, ataqueMonstro(monstro));
        } else {
            printf("%s errou o ataque!\n", monstro->name);
        }
    } else {
        if (((rand() % 20) + monstro->iniciativa + 1) > jogador->escudo) {
            receberDanoJogador(jogador, ataqueMonstro(monstro));
        } else {
            printf("%s errou o ataque!\n", monstro->name);
        }
    }
}
