#include <string.h>
#include <stdlib.h>
#include "ajudante.h"
#include "../Jogador/arma.h"
#include "../Jogador/magia.h"

void gerarHumano(Jogador *ajudante) {
    strcpy(ajudante->raca, "Humano");
    ajudante->forca += 1;
    ajudante->destreza += 1;
    ajudante->constituicao += 1;
    ajudante->sabedoria += 1;
}

void gerarBarbaro(Jogador *ajudante) {
    strcpy(ajudante->classe, "Barbaro");
    ajudante->ataqueExtra = 'S';
    ajudante->proficiencia += 3;
    ajudante->dadoVida = 12;
    ajudante->escudo = 16;
    ajudante->forca += 15;
    ajudante->destreza += 10;
    ajudante->constituicao += 12;
    ajudante->sabedoria += 8;
}

void gerarFeiticeiro(Jogador *ajudante) {
    strcpy(ajudante->classe, "Feiticeiro");
    ajudante->ataqueExtra = 'N';
    ajudante->proficiencia += 3;
    ajudante->dadoVida = 6;
    ajudante->escudo = 14;
    ajudante->forca += 8;
    ajudante->destreza += 12;
    ajudante->constituicao += 10;
    ajudante->sabedoria += 15;
}

void gerarMago(Jogador *ajudante) {
    strcpy(ajudante->classe, "Mago");
    ajudante->ataqueExtra = 'N';
    ajudante->dadoVida = 6;
    ajudante->escudo = 13;
    ajudante->forca += 8;
    ajudante->destreza += 12;
    ajudante->constituicao += 10;
    ajudante->sabedoria += 15;
}

void gerarPaladino(Jogador *ajudante) {
    strcpy(ajudante->classe, "Paladino");
    ajudante->ataqueExtra = 'S';
    ajudante->proficiencia += 3;
    ajudante->dadoVida = 10;
    ajudante->escudo = 17;
    ajudante->forca += 15;
    ajudante->destreza += 8;
    ajudante->constituicao += 10;
    ajudante->sabedoria += 12;
}

void gerarAjudante(Jogador *ajudante, Jogador *jogador) {
    int possivelClasse;

    strcpy(ajudante->name, "Elric");
    gerarHumano(ajudante);

    if (strcmp(jogador->classe, "Barbaro") == 0 || strcmp(jogador->classe, "Paladino") == 0) {
        possivelClasse = rand() % 2;
        if (possivelClasse == 0) {
            gerarFeiticeiro(ajudante);
        } else {
            gerarMago(ajudante);
        }
    } else if (strcmp(jogador->classe, "Feiticeiro") == 0 || strcmp(jogador->classe, "Mago") == 0) {
        if (possivelClasse == 0) {
            gerarBarbaro(ajudante);
        } else {
            gerarPaladino(ajudante);
        }
    }

    gerarMagias(ajudante);
    gerarArmas(ajudante);

    uparNivel(ajudante, 4);
    ajudante->iniciativa = modificacaoAtributos(ajudante->destreza);
    ajudante->magiaSomaAtributos = modificacaoAtributos(ajudante->sabedoria);
}
