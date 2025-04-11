#include <stdio.h>
#include <stdlib.h>
#include "fimJogo.h"

// Função responsável por terminar a execução quando o jogador morrer
void jogadorMorreu() {
  printf("\n!!!Jogador Morreu!!!\n");
  printf("Tente novamente, mas seja uma cuidadoso da próxima vez!\n");
  exit(0);
}
