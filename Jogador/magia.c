#include <string.h>
#include <windows.h>
#include "magia.h"

Magia truques() {
    Magia listaTruques[] = {
        {"Raio de Gelo", "Ataque", 8, 1},
        {"Toque Chocante", "Ataque", 8, 1},
        {"Chama Sagrada", "Ataque", 8, 1},
        {"Orbe Acido", "Ataque", 6, 1},
        {"Rajada Mistica", "Ataque", 10, 1},
        {"Toque Gelido", "Ataque", 8, 1},
        {"Luz Cegante", "Defesa", 0, 0},
        {"Pele de Rocha", "Defesa", 0, 0},
        {"Cura Rapida", "Cura", 4, 1},
        {"Empurrao Magico", "Ataque", 6, 1}
    };

    int totalTruques = sizeof(listaTruques) / sizeof(listaTruques[0]);
    int indiceAleatorio = rand() % totalTruques;
    return listaTruques[indiceAleatorio];
}

Magia magiaNV1() {
    Magia listaNV1[] = {
        {"Misseis Magicos", "Ataque", 4, 3},
        {"Armadura Arcana", "Defesa", 0, 0},
        {"Cura de Ferimentos", "Cura", 8, 1},
        {"Escudo", "Defesa", 0, 0},
        {"Chama Fulgurante", "Ataque", 8, 2},
        {"Raio Enfraquecedor", "Ataque", 6, 2},
        {"Nevoa Ocultante", "Defesa", 0, 0},
        {"Toque Vampirico", "Ataque", 6, 3},
        {"Cura Moderada", "Cura", 8, 2},
        {"Projecao Sombria", "Defesa", 0, 0},
        {"Arma Magica", "Ataque", 6, 2},
        {"Escudo Sombrio", "Defesa", 0, 0},
        {"Explosao Arcana", "Ataque", 6, 3},
        {"Cura Menor", "Cura", 4, 2},
        {"Espinhos Etereos", "Ataque", 8, 1}
    };

    int totalMagias = sizeof(listaNV1) / sizeof(listaNV1[0]);
    int indiceAleatorio = rand() % totalMagias;
    return listaNV1[indiceAleatorio];
}

Magia magiaNV2() {
    Magia listaNV2[] = {
        {"Relampago", "Ataque", 8, 3},
        {"Cura Completa", "Cura", 8, 3},
        {"Parede de Fogo", "Ataque", 6, 4},
        {"Armadura Elemental", "Defesa", 0, 0},
        {"Lancas Magicas", "Ataque", 10, 2},
        {"Circulo de Protecao", "Defesa", 0, 0},
        {"Cura Aprimorada", "Cura", 8, 4}
    };

    int totalMagias = sizeof(listaNV2) / sizeof(listaNV2[0]);
    int indiceAleatorio = rand() % totalMagias;
    return listaNV2[indiceAleatorio];
}

Magia magiaNV3() {
    Magia listaNV3[] = {
        {"Bola de Fogo", "Ataque", 6, 6},
        {"Muralha de Gelo", "Defesa", 0, 0},
        {"Restauracao Maior", "Cura", 8, 5},
        {"Impacto Divino", "Ataque", 10, 3}
    };

    int totalMagias = sizeof(listaNV3) / sizeof(listaNV3[0]);
    int indiceAleatorio = rand() % totalMagias;
    return listaNV3[indiceAleatorio];
}

// seleciona os truques e impede de vir algum repetido
void selecaoTruques(Jogador *jogador, int quantTruques) {
    int truquesSelecionados = 0;

    while (truquesSelecionados < quantTruques) {
        Magia novaMagia = truques();
        int repetida = 0;

        // verifica se já existe esse truque
        for (int i = 0; i < truquesSelecionados; i++) {
            if (strcmp(jogador->magia[0][i].nameMagia, novaMagia.nameMagia) == 0) { // compara as duas strings
                repetida = 1;
                break;
            }
        }

        if (!repetida) { // atribui ao jogador
            jogador->magia[0][truquesSelecionados] = novaMagia;
            truquesSelecionados++;
        }
    }
}

// sorteia magias com base nas porcentagens e do nível máximo
void selecaoMagias(Jogador *jogador, int quantMagias, int maxNV) {
    int magiasSelecionadas = 0;

    while (magiasSelecionadas < quantMagias) {
        int chance = rand() % 100; // 0 a 99
        Magia nova;

        if (maxNV == 3) {
            if (chance < 50) {
                nova = magiaNV1();
            } else if (chance < 85) {
                nova = magiaNV2();
            } else {
                nova = magiaNV3();
            }
        } else if (maxNV == 2) {
            if (chance < 65) {
                nova = magiaNV1();
            } else {
                nova = magiaNV2();
            }
        } else {
            nova = magiaNV1();
        }

        jogador->magia[1][magiasSelecionadas] = nova;
        magiasSelecionadas++;
    }
}

void gerarMagias(Jogador *jogador) {
    if (strcmp(jogador->classe, "Feiticeiro") == 0) {       // Feiticeiro - 5 truques - 6 magias
        selecaoTruques(jogador, 5);
        selecaoMagias(jogador, 6, 3);
    } else if (strcmp(jogador->classe, "Mago") == 0) {      // Mago - 4 truques - 8 magias
        selecaoTruques(jogador, 4);
        selecaoMagias(jogador, 8, 3);
    } else if (strcmp(jogador->classe, "Paladino") == 0) {  // Paladino - 3 magias
        selecaoMagias(jogador, 3, 2);
    }
}