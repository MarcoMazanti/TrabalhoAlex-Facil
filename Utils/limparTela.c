#include <stdio.h>
#include "limparTela.h"

void limparTela() {
    printf("\033[2J\033[H"); // Limpa a tela e move o cursor para o topo
}