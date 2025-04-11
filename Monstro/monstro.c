#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "monstro.h"
#include "listaMonstros.h"

// Zera todos os atributos de um monstro, útil para inicialização ou "reset"
void zerarMonstro(Monstro *monstro) {
    if (monstro == NULL) return;

    strcpy(monstro->name, "");
    monstro->vida = 0;
    monstro->escudo = 0;
    monstro->iniciativa = 0;

    for (int i = 0; i < 3; i++) {
        strcpy(monstro->ataque[i].nomeAtaque, "");
        strcpy(monstro->ataque[i].tipoAtaque, "");
        monstro->ataque[i].tipoDado = 0;
        monstro->ataque[i].quantDado = 0;
        monstro->ataque[i].atributosSomados = 0;
    }
}

// Reduz a vida do monstro ao receber dano. Se a vida zerar, exibe mensagem de morte.
void receberDanoMonstro(Monstro *monstro, int dano) {
    if (monstro->vida > dano) {
        monstro->vida -= dano;
    } else {
        monstro->vida = 0;
        printf("%s morreu!\n", monstro->name);
    }
}

// Realiza um ataque aleatório do monstro e calcula o dano com base nos dados e atributos
int ataqueMonstro(Monstro *monstro) {
    int dano = 0, ataque = 0;
    char repetir = 'S';

    while (repetir == 'S') {
        ataque = rand() % 3;

        if (strcmp(monstro->ataque[ataque].nomeAtaque, "") != 0) {
            repetir = 'N';
            printf("%s usou %s\n", monstro->name, monstro->ataque[ataque].nomeAtaque);
            int dado = (rand() % monstro->ataque[ataque].tipoDado) + 1;
            dano = monstro->ataque[ataque].quantDado * dado + monstro->ataque[ataque].atributosSomados;
        }
    }

    return dano;
}

// Cria um vetor de ponteiros para monstros iguais, do tipo "Campanha" ou "Boss"
void criarMonstrosIguais(Monstro *monstro[], const char objetivo[], int quantidade) {
    if (quantidade <= 0) return; // Garante que a função não rode com quantidade inválida

    for (int i = 0; i < quantidade; i++) {
        if (strcmp(objetivo, "Campanha") == 0) {
            monstro[i] = campanha();
        } else if (strcmp(objetivo, "Boss") == 0) {
            monstro[i] = boss();
        }
    }
}
