#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "batalha.h"

int iniciativa(int iniciativa) {
    return rand() % 20 + iniciativa + 1;
}

// Função para ordenar por iniciativa (decrescente)
void ordenarOrdemJogada(OrdemJogada *ordem, int tamanho) {
    OrdemJogada temp;
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (ordem[j].iniciativa > ordem[i].iniciativa) {
                temp = ordem[i];
                ordem[i] = ordem[j];
                ordem[j] = temp;
            }
        }
    }
}

int aindaHaMonstros(Monstro *monstros[], int quant) {
    for (int i = 0; i < quant; i++) {
        if (monstros[i]->vida > 0) return 1;
    }
    return 0;
}

void batalhar(Jogador *jogador, Jogador *ajudante, Monstro *monstros[], int quantMonstros) {
    OrdemJogada ordemPrincipal[2 + quantMonstros];

    // Jogador
    strcpy(ordemPrincipal[0].name, jogador->name);
    ordemPrincipal[0].iniciativa = iniciativa(jogador->iniciativa);

    // Ajudante
    strcpy(ordemPrincipal[1].name, ajudante->name);
    ordemPrincipal[1].iniciativa = iniciativa(ajudante->iniciativa);

    // Monstros
    for (int i = 0; i < quantMonstros; i++) {
        char nomeComNumero[50];
        sprintf(nomeComNumero, "%s %d", monstros[i]->name, i + 1);
        strcpy(ordemPrincipal[i + 2].name, nomeComNumero);
        ordemPrincipal[i + 2].iniciativa = iniciativa(monstros[i]->iniciativa);
    }

    // Ordenar em ordem decrescente de iniciativa
    ordenarOrdemJogada(ordemPrincipal, 2 + quantMonstros);

    // Mostrar ordem de batalha
    printf("\nOrdem de batalha:\n");
    for (int i = 0; i < 2 + quantMonstros; i++) {
        printf("%d. %s - Iniciativa: %d\n", i + 1, ordemPrincipal[i].name, ordemPrincipal[i].iniciativa);
    }

    Sleep(2500);

    // Inicia a batalha
    printf("\n");
    int numMonstroAtacar = 0, numMonstro = 0;
    char ultimaLetra;
    while (aindaHaMonstros(monstros, quantMonstros)) {
        for (int i = 0; i < quantMonstros + 2; i++) {
            // Verifica se é jogador e se está morto
            if (strcmp(ordemPrincipal[i].name, jogador->name) == 0 && jogador->vida <= 0) continue;

            // Verifica se é o ajudante e se está morto
            if (strcmp(ordemPrincipal[i].name, ajudante->name) == 0 && ajudante->vida <= 0) continue;

            // Verifica se é um monstro e se está morto
            if (strcmp(ordemPrincipal[i].name, jogador->name) != 0 &&
                strcmp(ordemPrincipal[i].name, ajudante->name) != 0) {

                // Pega o número do monstro
                int len = strlen(ordemPrincipal[i].name);
                char ch = ordemPrincipal[i].name[len - 1];

                // Verifica se é um número e dentro dos limites
                if (ch >= '1' && ch <= '9') {
                    numMonstro = ch - '1'; // índice começa em 0

                    if (numMonstro >= 0 && numMonstro < quantMonstros) {
                        if (monstros[numMonstro]->vida <= 0) continue;
                    }
               }
            }

            printf("Agora eh a vez do %s!\n", ordemPrincipal[i].name);

            if (strcmp(ordemPrincipal[i].name, jogador->name) == 0) {           // Jogador ataca
                printf("Vida: %d\n", jogador->vida);
                printf("Existem esses monstros vivos:\n");
                for (int i = 0; i < quantMonstros; i++) {
                    if (monstros[i]->vida > 0) {
                        printf("%s %d\n", monstros[i]->name, i + 1);
                    }
                }
                printf("Escolha um para atacar!\n>");
                scanf("%d", &numMonstroAtacar);
                playerAtaca(jogador, monstros[numMonstroAtacar - 1]);

            } else if (strcmp(ordemPrincipal[i].name, ajudante->name) == 0) {   // Ajudante ataca
                printf("Vida: %d\n", ajudante->vida);
                NPCAtaca(ajudante, monstros[rand() % quantMonstros]);

            } else {                                                            // Monstro[i] ataca
                numMonstro = strlen(ordemPrincipal[i].name);
                ultimaLetra = ordemPrincipal[i].name[numMonstro - 1];
                numMonstro = ultimaLetra - '1'; // índice ajustado

                monstroAtaca(monstros[numMonstro], ((rand() % 2) == 0) ? jogador : ajudante);
            }

            if (jogador->vida <= 0) {
                printf("Voce Morreu!!!\n");
                printf("Jogue melhor da proxima vez!\n");
                exit(0);
            }

            Sleep(2000);
            printf("\n");
        }
    }
    printf("A batalha acabou!\n\n");
}
