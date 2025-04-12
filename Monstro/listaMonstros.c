#include <stdlib.h>
#include <string.h>
#include "listaMonstros.h"

// Função que retorna um monstro aleatório para encontros normais da campanha
Monstro* campanha() {
    Monstro *monstro = malloc(sizeof(Monstro)); // Aloca espaço para um monstro na memória

    switch (rand() % 3) { // Sorteia um dos três monstros possíveis
        case 0:
            strcpy(monstro->name, "Lobo Artico");
            monstro->vida = 18;
            monstro->escudo = 11;
            monstro->iniciativa = 0;
            monstro->ataque[0] = (Ataque){"Mordida Agil", "Ataque", 1, 6, 2};
            monstro->ataque[1] = (Ataque){"Investida Nevasca", "Ataque", 1, 4, 3};
            monstro->ataque[2] = (Ataque){"Uivo de Alerta", "Defesa", 0, 0, 0};
            break;
        case 1:
            strcpy(monstro->name, "Corrupto de Gelo");
            monstro->vida = 26;
            monstro->escudo = 15;
            monstro->iniciativa = 1;
            monstro->ataque[0] = (Ataque){"Lanca de Gelo", "Ataque", 2, 6, 3};
            monstro->ataque[1] = (Ataque){"Nevoa Congelante", "Defesa", 3, 4, 1};
            monstro->ataque[2] = (Ataque){"Explosao Invernal", "Ataque", 3, 6, 2};
            break;
        case 2:
            strcpy(monstro->name, "Carnical de Gelo");
            monstro->vida = 24;
            monstro->escudo = 13;
            monstro->iniciativa = 2;
            monstro->ataque[0] = (Ataque){"Garras Gelidas", "Ataque", 1, 8, 1};
            monstro->ataque[1] = (Ataque){"Mordida Apodrecida", "Ataque", 1, 6, 2};
            monstro->ataque[2] = (Ataque){"Toque da Necroneve", "Defesa", 2, 4, 0};
            break;
    }

    return monstro; // Retorna o monstro sorteado
}

// Função que retorna um monstro chefe (boss) para batalhas importantes
Monstro* boss() {
    Monstro *monstro = malloc(sizeof(Monstro)); // Aloca espaço para o chefe

    strcpy(monstro->name, "Diabo dos Espinhos");
    monstro->vida = 65;
    monstro->escudo = 14;
    monstro->iniciativa = 5;
    monstro->ataque[0] = (Ataque){"Chicote Espinhoso", "Ataque", 2, 6, 3};
    monstro->ataque[1] = (Ataque){"Rajada Infernal", "Ataque", 3, 4, 2};
    monstro->ataque[2] = (Ataque){"Explosão de Dor", "Ataque", 2, 8, 1};

    return monstro;
}

// Possível adição futura de boss mais poderoso
/*
Monstro noivaDoAbismo = {
    .name = "Noiva do Abismo",
    .vida = 200,
    .escudo = 10,
    .iniciativa = 20,
    .ataque = {
        {"Grito do Vazio", "Ataque", 4, 6, 5},   // Dano em área + chance de causar medo
        {"Manto Abissal", "Defesa", 0, 0, 5},    // Aumenta escudo e aplica penalidade em inimigos
        {"Sussurro Sombrio", "Cura", 3, 6, 4}    // Cura a si mesma e pode causar dano psíquico em inimigos
    }
};
*/
