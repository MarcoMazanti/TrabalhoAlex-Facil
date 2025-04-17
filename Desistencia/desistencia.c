#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "desistencia.h"
#include "../Utils/utils.h"

static void fimDoJogo() {
    printf("\nAperte ENTER para terminar o jogo!\n");
    for (int i = 0;; i++) {
        if (_kbhit()) {
            if (getch() == 13) { // 13 é o código ASCII do Enter
                break;
            }
        }
        Sleep(100);
    }
}

void desistirInicio(){
    printf("Voce aceita ir nessa aventura?\n");
    textoColorido("1. Sim\n", "verde", "normal");
    textoColorido("2. Nao\n", "vermelho", "normal");
    printf("> ");
    char *possiveisRespostas[8] = {"1", "2", "Sim", "Nao", "S", "N", "1. Sim", "2. Nao"};
    int resposta = verificarEntrada(2, 4, possiveisRespostas, 0);

    if (resposta == 2) {
        printf(" Com isso voce eh mandado embora da vila por nao ajuda-los, mas apos um tempo, voce comeca\n"
                     "a ouvir um boato que uma vila foi completamente destruida e que agora possui uma criatura\n"
                     "espalhando o caus naquela regiao e voce lembra que era a vila que voce foi mandado embora.\n");
        fimDoJogo();
        exit(0);
    }
    printf("Com isso voce se aceita o pedido do chefe da vila!\n");
}

void desistirMeio(Jogador *ajudante){
    printf("Durante a viagem vem uma ideia de desistir da aventura por conta do perigo!\n"
                 "Voce deside continuar na aventura?\n");
    textoColorido("1. Sim\n", "verde", "normal");
    textoColorido("2. Nao\n", "vermelho", "normal");
    printf("> ");
    char *possiveisRespostas[8] = {"1", "2", "Sim", "Nao", "S", "N", "1. Sim", "2. Nao"};
    int resposta = verificarEntrada(2, 4, possiveisRespostas, 0);

    if (resposta == 2) {
        printf(" Apos desistir ir embora o %s fica um pouco revoltado, mas segue voce. Durante a noite,\n"
                     "%s decide ficar de vigia, voce aceita um pouco duvidoso, mas aceita.\n"
                     " Entao durante a noite voce eh acordado sendo esfaqueado pelo seu \"ajudante\", e antes\n"
                     "de morrer voce ouve dele:\n", ajudante->name, ajudante->name);
        printf("Voce eh uma vergonha para o nosso povo, nem deveria ser considerado como um de nos!\n");
        printf(" Apos isso, seu coracao eh perfurado pela lamina.\n");
        fimDoJogo();
        exit(0);
    }
    printf(" Voce apenas afasta essa ideia e segue viagem!\n");
}