#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "verificarEntrada.h"

#include "textoColorido.h"

static void paraMinusculo(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int contemAlgoVisivel(const char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isspace((unsigned char)str[i])) {
            return 1;
        }
    }
    return 0;
}

void entradaDeNomeAceito(char* resposta) {
    char nome[75];
    while (1) {
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0'; // remove \n do final

        if (contemAlgoVisivel(nome)) {
            strcpy(resposta, nome);
            break;
        }

        textoColorido("Nome Invalido!\n", "vermelho", "normal");
        printf("Digite um nome valido:\n> ");
    }
}

// Ordem a colocar-se, quantAlternativas, QuantCasos e um array com os possíveis casos
// EX: char *escolhas[] = { "1", "2", "Sim", "Nao", "S", "N"};
int verificarEntrada(int quantidadeAlternativas, int quantidadeCasos, char *casos[], int temVolta) {
    char resposta[75];

    while (1) {
        fgets(resposta, sizeof(resposta), stdin);
        resposta[strcspn(resposta, "\n")] = '\0'; // Remove o \n do final

        for (int i = 0; i < quantidadeCasos; i++) {
            if (strcmp(casos[i], "") == 0) continue;
            if (strcasecmp(resposta, casos[i]) == 0) {
                return (i % quantidadeAlternativas) + 1;
            } else if (temVolta == 1 && strcmp(resposta, "0") == 0) {
                return 0;
            }
        }
        if (quantidadeCasos == 0) {
            if (strcmp(resposta, "0") == 0) {
                return 0;
            }
        }

        textoColorido("Resposta Invalida!\n", "vermelho", "normal");
        printf("Digite algo valido:\n> ");
    }
}

