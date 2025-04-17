#include <stdlib.h>
#include <stdio.h>
#include "atacar.h"
#include "../Utils/textoColorido.h"

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
    // Verifica o tipo de ataque e depois se for ataque ou defesa deve rodar o d20 para ver se acertou, já a cura vai direto
    int danoPlayer = ataqueJogador(jogador);
    int dadoAcertoPlayer = 0;
    char strDano[10];
    if (danoPlayer >= 0) {
        if (jogador->debuff == 'S') {
            dadoAcertoPlayer = debuffPlayer(jogador);
            if (dadoAcertoPlayer <= 1) {
                textoColorido("Falha critica!!!\n", "vermelho", "normal");
                jogador->debuff = 'S';
            }
            if (dadoAcertoPlayer > monstro->escudo) {
                if (dadoAcertoPlayer >= 20) {
                    textoColorido("Acerto critico!!!\n", "verde", "normal");
                    danoPlayer *= 2;
                }
                receberDanoMonstro(monstro, danoPlayer);
                if (danoPlayer == 0) {
                    printf("%s deixou o %s em desvantagem!\n", jogador->name, monstro->name);
                } else {
                    printf("%s causo ", jogador->name);
                    snprintf(strDano, sizeof(strDano), "%d ", danoPlayer);
                    textoColorido(strDano, "vermelho", "normal");
                    printf("de dano!\n");
                }
            } else {
                printf("%s errou o ataque!\n", jogador->name);
            }
        } else {
            dadoAcertoPlayer = (rand() % 20) + jogador->iniciativa + 1;
            if (dadoAcertoPlayer <= 1) {
                textoColorido("Falha critica!!!\n", "vermelho", "normal");
                jogador->debuff = 'S';
            }
            if (dadoAcertoPlayer > monstro->escudo) {
                if (dadoAcertoPlayer >= 20) {
                    textoColorido("Acerto critico!!!\n", "verde", "normal");
                    danoPlayer *= 2;
                }
                receberDanoMonstro(monstro, danoPlayer);
                if (danoPlayer == 0) {
                    printf("%s deixou o alvo em desvantagem!\n", jogador->name);
                } else {
                    printf("%s causo ", jogador->name);
                    snprintf(strDano, sizeof(strDano), "%d ", danoPlayer);
                    textoColorido(strDano, "vermelho", "normal");
                    printf("de dano!\n");
                }
            } else {
                printf("%s errou o ataque!\n", jogador->name);
            }
        }
    } else {
        printf("%s curou vida!\n", jogador->name);
    }

}

void NPCAtaca(Jogador *ajudante, Monstro *monstro) {
    int danoNPC = ataqueAjudante(ajudante);
    int dadoAcertoNPC = 0;
    char strDano[10];
    if (danoNPC >= 0) {
        if (ajudante->debuff == 'S') {
            dadoAcertoNPC = debuffPlayer(ajudante);
            if (dadoAcertoNPC <= 1) {
                textoColorido("Falha critica!!!\n", "vermelho", "normal");
                ajudante->debuff = 'S';
            }
            if (dadoAcertoNPC > monstro->escudo) {
                if (dadoAcertoNPC >= 20) {
                    textoColorido("Acerto critico!!!\n", "verde", "normal");
                    danoNPC *= 2;
                }
                receberDanoMonstro(monstro, danoNPC);
                if (danoNPC == 0) {
                    printf("%s deixou o alvo em desvantagem!\n", ajudante->name);
                } else {
                    printf("%s causo ", ajudante->name);
                    snprintf(strDano, sizeof(strDano), "%d ", danoNPC);
                    textoColorido(strDano, "vermelho", "normal");
                    printf("de dano!\n");
                }
            } else {
                printf("%s errou o ataque!\n", ajudante->name);
            }
        } else {
            dadoAcertoNPC = (rand() % 20) + ajudante->iniciativa + 1;
            if (dadoAcertoNPC <= 1) {
                textoColorido("Falha critica!!!\n", "vermelho", "normal");
                ajudante->debuff = 'S';
            }
            if (dadoAcertoNPC > monstro->escudo) {
                if (dadoAcertoNPC >= 20) {
                    textoColorido("Acerto critico!!!\n", "verde", "normal");
                    danoNPC *= 2;
                }
                receberDanoMonstro(monstro, danoNPC);
                if (danoNPC == 0) {
                    printf("%s deixou o alvo em desvantagem!\n", ajudante->name);
                } else {
                    printf("%s causo ", ajudante->name);
                    snprintf(strDano, sizeof(strDano), "%d ", danoNPC);
                    textoColorido(strDano, "vermelho", "normal");
                    printf("de dano!\n");
                }
            } else {
                printf("%s errou o ataque!\n", ajudante->name);
            }
        }
    } else {
        printf("%s curou vida!\n", ajudante->name);
    }
}

// Função responsável por fazer o monstro atacar o jogador
void monstroAtaca(Monstro *monstro, Jogador *jogador) {
    int danoMonstro = ataqueMonstro(monstro);
    int dadoAcertoMonstro = 0;
    char strDano[10];
    if (danoMonstro >= 0) {
        if (monstro->debuff == 'S') {
            dadoAcertoMonstro = debuffMonstro(monstro);
            if (dadoAcertoMonstro <= 1) {
                textoColorido("Falha critica!!!\n", "vermelho", "normal");
                monstro->debuff = 'S';
            }
            if (dadoAcertoMonstro > jogador->escudo) {
                if (dadoAcertoMonstro >= 20) {
                    textoColorido("Acerto critico!!!\n", "verde", "normal");
                    danoMonstro *= 2;
                }
                receberDanoJogador(jogador, danoMonstro);
                if (danoMonstro == 0) {
                    printf("%s deixou o alvo em desvantagem!\n", monstro->name);
                } else {
                    printf("%s causo ", monstro->name);
                    snprintf(strDano, sizeof(strDano), "%d ", danoMonstro);
                    textoColorido(strDano, "vermelho", "normal");
                    printf("de dano!\n");
                }
            } else {
                printf("%s errou o ataque!\n", monstro->name);
            }
        } else {
            dadoAcertoMonstro = (rand() % 20) + monstro->iniciativa + 1;
            if (dadoAcertoMonstro <= 1) {
                textoColorido("Falha critica!!!\n", "vermelho", "normal");
                monstro->debuff = 'S';
            }
            if (dadoAcertoMonstro > jogador->escudo) {
                if (dadoAcertoMonstro >= 20) {
                    textoColorido("Acerto critico!!!\n", "verde", "normal");
                    danoMonstro *= 2;
                }
                receberDanoJogador(jogador, danoMonstro);
                if (danoMonstro == 0) {
                    printf("%s deixou o alvo em desvantagem!\n", monstro->name);
                } else {
                    printf("%s causo ", monstro->name);
                    snprintf(strDano, sizeof(strDano), "%d ", danoMonstro);
                    textoColorido(strDano, "vermelho", "normal");
                    printf("de dano!\n");
                }
            } else {
                printf("%s errou o ataque!\n", monstro->name);
            }
        }
    } else {
        printf("%s curou vida!\n", monstro->name);
    }

}
