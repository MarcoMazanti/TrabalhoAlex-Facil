#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "textoColorido.h"

static void paraMinusculo(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

void textoColorido(const char* texto, const char* cor, const char* estilo) {
    int codCor = 37;     // Branco padrão
    int codEstilo = 0;   // Sem estilo

    char corMin[20];
    char estiloMin[20];
    strncpy(corMin, cor, sizeof(corMin));
    strncpy(estiloMin, estilo, sizeof(estiloMin));
    corMin[sizeof(corMin) - 1] = '\0';
    estiloMin[sizeof(estiloMin) - 1] = '\0';

    paraMinusculo(corMin);
    paraMinusculo(estiloMin);

    // Cores
    if (strcmp(corMin, "preto") == 0) codCor = 30;
    else if (strcmp(corMin, "vermelho") == 0) codCor = 31;
    else if (strcmp(corMin, "verde") == 0) codCor = 32;
    else if (strcmp(corMin, "amarelo") == 0) codCor = 33;
    else if (strcmp(corMin, "azul") == 0) codCor = 34;
    else if (strcmp(corMin, "magenta") == 0) codCor = 35;
    else if (strcmp(corMin, "ciano") == 0) codCor = 36;
    else if (strcmp(corMin, "branco") == 0) codCor = 37;

    // Estilos
    if (strcmp(estiloMin, "normal") == 0) codEstilo = 0;
    else if (strcmp(estiloMin, "negrito") == 0) codEstilo = 1;
    else if (strcmp(estiloMin, "italico") == 0) codEstilo = 3;
    else if (strcmp(estiloMin, "sublinhado") == 0) codEstilo = 4;
    else if (strcmp(estiloMin, "invertido") == 0) codEstilo = 7;

    printf("\033[%d;%dm%s\033[0m", codEstilo, codCor, texto);
}