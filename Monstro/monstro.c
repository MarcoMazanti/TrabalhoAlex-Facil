#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "monstro.h"
#include "listaMonstros.h"

// Zera todos os atributos de um monstro, útil para inicialização ou "reset"
void zerarMonstro(Monstro *monstro) {
    memset(monstro, 0, sizeof(Monstro));
}

// Reduz a vida do monstro ao receber dano. Se a vida zerar, exibe mensagem de morte.
void receberDanoMonstro(Monstro *monstro, int dano) {
    if (dano > 0) {
        if (monstro->vida > dano) {
            monstro->vida -= dano;
        } else {
            monstro->vida = 0;
            printf("\n%s morreu!\n\n", monstro->name);
        }
    } else if (dano == 0) {
        monstro->debuff = 'S';
    }
}

// Realiza um ataque aleatório do monstro e calcula o dano com base nos dados e atributos
int ataqueMonstro(Monstro *monstro) {
    int dano = 0, numAtaque = 0;
    char repetir = 'S';

    while (repetir == 'S') {
        numAtaque = rand() % 3;

        Ataque ataque = monstro->ataque[numAtaque];

        if (strcmp(ataque.nomeAtaque, "") != 0) {
            repetir = 'N';

            if (strcmp(ataque.tipoAtaque, "Defesa") == 0) {
                dano = 0;   // Causa debuff
            } else if (strcmp(ataque.tipoAtaque, "Cura") == 0) {
                int dado = (rand() % ataque.tipoDado + 1);
                dano = ataque.quantDado * dado + ataque.atributosSomados;

                monstro->vida += dano;
                dano = -1;  // É ignorado
            } else {
                int dado = (rand() % ataque.tipoDado + 1);
                dano = ataque.quantDado * dado + ataque.atributosSomados;
            }
        }
    }

    return dano;
}

// Cria um vetor de ponteiros para monstros iguais, do tipo "Campanha" ou "Boss"
void criarMonstrosIguais(Monstro *monstro[], const char objetivo[], int quantidade) {
    if (quantidade <= 0) return;

    Monstro *modelo = NULL;

    // Cria apenas UM monstro base
    if (strcmp(objetivo, "Campanha") == 0) {
        modelo = campanha();
    } else if (strcmp(objetivo, "Boss") == 0) {
        modelo = boss();
    }

    // Usa o modelo para preencher todos os monstros
    for (int i = 0; i < quantidade; i++) {
        monstro[i] = malloc(sizeof(Monstro));
        if (monstro[i] != NULL && modelo != NULL) {
            memcpy(monstro[i], modelo, sizeof(Monstro));
        }
    }

    // Libera o modelo após copiar (opcional, se não for usado em outro lugar)
    if (modelo != NULL) {
        free(modelo);
    }
}

void criarMonstrosDiferentes(Monstro *monstro[], const char objetivo[], int quantidade) {
    if (quantidade <= 0) return;

    for (int i = 0; i < quantidade; i++) {
        if (strcmp(objetivo, "Campanha") == 0) {
            monstro[i] = campanha(); // cada chamada gera um monstro diferente
        } else if (strcmp(objetivo, "Boss") == 0) {
            monstro[i] = boss(); // idem
        } else {
            monstro[i] = NULL; // segurança em caso de erro
        }
    }
}
