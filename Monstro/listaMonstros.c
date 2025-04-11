#include <stdlib.h>
#include <string.h>
#include "listaMonstros.h"

Monstro* campanha() {
    Monstro *monstro = malloc(sizeof(Monstro));

    switch (rand() % 3) {
        case 0:
            strcpy(monstro->name, "Lobo Artico");
            monstro->vida = 18;
            monstro->escudo = 11;
            monstro->iniciativa = 14;
            monstro->ataque[0] = (Ataque){"Mordida Agil", "Ataque", 1, 6, 2};
            monstro->ataque[1] = (Ataque){"Investida Nevasca", "Ataque", 1, 4, 3};
            monstro->ataque[2] = (Ataque){"Uivo de Alerta", "Defesa", 0, 0, 0};
            break;
        case 1:
            strcpy(monstro->name, "Corrupto de Gelo");
            monstro->vida = 26;
            monstro->escudo = 15;
            monstro->iniciativa = 15;
            monstro->ataque[0] = (Ataque){"Lanca de Gelo", "Ataque", 2, 6, 3};
            monstro->ataque[1] = (Ataque){"Nevoa Congelante", "Defesa", 3, 4, 1};
            monstro->ataque[2] = (Ataque){"Explosao Invernal", "Ataque", 3, 6, 2};
            break;
        case 2:
            strcpy(monstro->name, "Carnical de Gelo");
            monstro->vida = 24;
            monstro->escudo = 13;
            monstro->iniciativa = 8;
            monstro->ataque[0] = (Ataque){"Garras Gelidas", "Ataque", 1, 8, 1};
            monstro->ataque[1] = (Ataque){"Mordida Apodrecida", "Ataque", 1, 6, 2};
            monstro->ataque[2] = (Ataque){"Toque da Necroneve", "Defesa", 2, 4, 0};
            break;
    }

    return monstro;
}

Monstro* boss() {
    Monstro *monstro = malloc(sizeof(Monstro));

    strcpy(monstro->name, "Diabo dos Espinhos");
    monstro->vida = 65;
    monstro->escudo = 4;
    monstro->iniciativa = 12;
    monstro->ataque[0] = (Ataque){"Chicote Espinhoso", "Ataque", 2, 6, 3};
    monstro->ataque[1] = (Ataque){"Rajada Infernal", "Ataque", 3, 4, 2};
    monstro->ataque[2] = (Ataque){"Explosão de Dor", "Ataque", 2, 8, 1};

    return monstro;
}


// possível adição futura para batalhar
//Monstro noivaDoAbismo = {
//    .name = "Noiva do Abismo",
//    .vida = 200,
//    .escudo = 10,
//    .iniciativa = 20,
//    .ataque = {
//        {"Grito do Vazio", "Ataque", 4, 6, 5}, dano alto em área + chance de medo
//        {"Manto Abissal", "Defesa", 0, 0, 5}, escudo + penalidade para ataques inimigos
//        {"Sussurro Sombrio", "Cura", 3, 6, 4} recupera vida dela e possivelmente causa dano psíquico em quem está por perto
//    }
//};
