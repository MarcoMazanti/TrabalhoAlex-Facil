#include <string.h>
#include "arma.h"

void armasBarbaro_Paladino(Jogador *jogador) {
    Arma corpoCorpo = {"Espadao", 6, 2, modificacaoAtributos(jogador->forca) +
        ((strcmp(jogador->classe, "Barbaro") == 0) ? 2 : 5)};
    Arma distancia = {"Arco Curto", 6, 1, modificacaoAtributos(jogador->destreza)};
    jogador->arma[0] = corpoCorpo;
    jogador->arma[1] = distancia;
}

void armasFeiticeiro_Mago(Jogador *jogador) {
    Arma corpoCorpo = {"Bordao", 8, 1, modificacaoAtributos(jogador->forca)};
    Arma distancia = {"Besta Leve", 6, 1, modificacaoAtributos(jogador->destreza)};
    jogador->arma[0] = corpoCorpo;
    jogador->arma[1] = distancia;
}

void gerarArmas(Jogador *jogador) {
    if (strcmp(jogador->classe, "Barbaro") == 0 || strcmp(jogador->classe, "Paladino") == 0) {
        armasBarbaro_Paladino(jogador);
    } else if (strcmp(jogador->classe, "Feiticeiro") == 0 || strcmp(jogador->classe, "Mago") == 0) {
        armasFeiticeiro_Mago(jogador);
    }
}