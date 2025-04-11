#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "monstro.h"
#include "listaMonstros.h"

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



void receberDanoMonstro(Monstro *monstro, int dano) {
    if (monstro->vida > dano) {
        monstro->vida -= dano;
    } else {
        strcpy(monstro->name, "");
        monstro->vida = 0;
        printf("%S morreu!\n");
    }
}

int ataqueMonstro(Monstro *monstro) {
    int dano = 0, ataque = 0;
    char repetir = 'N';

    do {
        ataque = rand() % 3;

        if (monstro->ataque[ataque].nomeAtaque != "") {
            repetir = 'N';
            printf("%s usou %s\n", monstro->name, monstro->ataque[ataque].nomeAtaque);
            dano = monstro->ataque[ataque].quantDado * (rand() % monstro->ataque[ataque].tipoDado) + monstro->ataque[ataque].atributosSomados;
        } else {
            repetir = 'S';
        }

    } while (repetir == 'S');

    return dano;
}

void criarMonstrosIguais(Monstro *monstro[], char objetivo[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        if (strcmp(objetivo, "Campanha") == 0) {
            monstro[i] = campanha();
        } else if (strcmp(objetivo, "Boss") == 0) {
            monstro[i] = boss();
        }
    }
}