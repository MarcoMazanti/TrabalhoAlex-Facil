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

int ataqueAjudante(Jogador *ajudante) {
    int dano = 0;

        if (strcmp(ajudante->classe, "Barbaro") == 0 || strcmp(ajudante->classe, "Paladino") == 0) {
            // Ataca com arma
            int arma = rand() % 2;
            dano = ajudante->arma[arma].quantDados * (rand() % ajudante->arma[arma].quantDados) + ajudante->arma[arma].atributosSomados + 1;
        } else {
            // Ataca com magia
            int tipoMagia = rand() % 2;
            int numMagia = rand() % contarMagiasDisponiveis(ajudante, tipoMagia);

            Magia magia = ajudante->magia[tipoMagia][numMagia];

            if (strcmp(magia.tipoMagia, "Defesa") == 0) {
                dano = 0;
            } else if (strcmp(magia.tipoMagia, "Cura") == 0) {
                int somaDados = 0;
                for (int i = 0; i < magia.quantDados; i++) {
                    somaDados += (rand() % (magia.tipoDado) + 1);
                }

                dano = somaDados + ajudante->magiaSomaAtributos;

                ajudante->vida += dano;
                dano = -1;
            } else {
                int somaDados = 0;
                for (int i = 0; i < magia.quantDados; i++) {
                    somaDados += (rand() % (magia.tipoDado) + 1);
                }

                dano = somaDados + ajudante->magiaSomaAtributos;
            }
        }
    return dano;
}

// Função principal que gera o ajudante com base na classe do jogador principal
void gerarAjudante(Jogador *ajudante, Jogador *jogador) {
    int possivelClasse;

    strcpy(ajudante->name, "Elric");
    gerarHumano(ajudante);

    // Define a classe do ajudante como complementar à do jogador
    if (strcmp(jogador->classe, "Barbaro") == 0 || strcmp(jogador->classe, "Paladino") == 0) {
        possivelClasse = rand() % 2;
        if (possivelClasse == 0) {
            gerarFeiticeiro(ajudante);
        } else {
            gerarMago(ajudante);
        }
    } else if (strcmp(jogador->classe, "Feiticeiro") == 0 || strcmp(jogador->classe, "Mago") == 0) {
        possivelClasse = rand() % 2;
        if (possivelClasse == 0) {
            gerarBarbaro(ajudante);
        } else {
            gerarPaladino(ajudante);
        }
    }

    gerarMagias(ajudante);
    gerarArmas(ajudante);

    uparNivel(ajudante, 4);

    ajudante->vida += 10;
    ajudante->iniciativa = modificacaoAtributos(ajudante->destreza);
    ajudante->magiaSomaAtributos = modificacaoAtributos(ajudante->sabedoria);
}
