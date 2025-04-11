#include <string.h>
#include "arma.h"

// Função para definir as armas de corpo a corpo e à distância para classes focadas em força (Bárbaro ou Paladino)
void armasBarbaro_Paladino(Jogador *jogador) {
    Arma corpoCorpo = {"Espadao", 6, 2,
        modificacaoAtributos(jogador->forca) + ((strcmp(jogador->classe, "Barbaro") == 0) ? 2 : 5)};
    Arma distancia = {"Arco Curto", 6, 1, modificacaoAtributos(jogador->destreza)};

    jogador->arma[0] = corpoCorpo;
    jogador->arma[1] = distancia;
}

// Função para definir as armas de corpo a corpo e à distância para classes mágicas (Feiticeiro ou Mago)
void armasFeiticeiro_Mago(Jogador *jogador) {
    Arma corpoCorpo = {"Bordao", 8, 1, modificacaoAtributos(jogador->forca)};
    Arma distancia = {"Besta Leve", 6, 1, modificacaoAtributos(jogador->destreza)};

    jogador->arma[0] = corpoCorpo;
    jogador->arma[1] = distancia;
}

// Função principal que gera as armas com base na classe do jogador
void gerarArmas(Jogador *jogador) {
    if (strcmp(jogador->classe, "Barbaro") == 0 || strcmp(jogador->classe, "Paladino") == 0) {
        armasBarbaro_Paladino(jogador);
    }
    else if (strcmp(jogador->classe, "Feiticeiro") == 0 || strcmp(jogador->classe, "Mago") == 0) {
        armasFeiticeiro_Mago(jogador);
    }
}
