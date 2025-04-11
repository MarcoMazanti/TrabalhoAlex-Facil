#ifndef MAGIA_H
#define MAGIA_H

#include "jogador.h"

Magia truques();
Magia magiaNV1();
Magia magiaNV2();
Magia magiaNV3();
void selecaoTruques(Jogador *jogador, int quantTruques);
void selecaoMagias(Jogador *jogador, int quantMagias, int maxNV);
void gerarMagias(Jogador *jogador);

#endif