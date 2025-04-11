#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "Jogador/jogador.h"
#include "Ajudante/ajudante.h"
#include "Monstro/monstro.h"

void verificacaoRapidaPersonagem(Jogador *jogador);
void verificacaoRapidaMonstro(Monstro *monstro);

int main() {
    srand(time(NULL));

    // Cria os personagens que participarão do RPG
    Jogador jogador, ajudante;
    Monstro *monstroCampanha[3];

    // Previne vir algum lixo de memória
    zerarJogador(&jogador);
    zerarJogador(&ajudante);

    // Atribui os valores para cada respectivo personagem
    criarMonstrosIguais(monstroCampanha, "Campanha", 3);

    criarJogador(&jogador);
    gerarAjudante(&ajudante, &jogador);

    // Verifica se foi criado tudo certo, apenas para o desenvolvimento do código
    verificacaoRapidaPersonagem(&jogador);
    verificacaoRapidaPersonagem(&ajudante);
    for (int i = 0; i < 3; i++) {
        verificacaoRapidaMonstro(monstroCampanha[i]);
    }

    // Início da história do RPG
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("----------O Chamado do Inverno----------\n");
    printf(" O inverno chegou mais cedo este ano, trazendo com ele nao apenas o frio cortante das montanhas,\n"
                 "mas tambem o silencio inquietante que paira sobre as terras do norte. Desde que um estranho objeto\n"
                 "caiu do ceu sobre o vilarejo vizinho, nenhuma mensagem, nenhuma caravana e nenhum som de vida\n"
                 "foram ouvidos daquela direcao.\n");
    Sleep(17500);
    printf(" Diante da urgencia e do crescente temor entre os moradores, o chefe da vila decide enviar um\n"
                 "aventureiro chamado %s, conhecido por suas facanhas, para investigar o ocorrido.\n"
                 "Como a situacao parece perigosa demais para ser enfrentada sozinho, um jovem assistente chamado\n"
                 "%s eh designado para acompanha-lo.\n"
                 " Com isso, voce e seu novo ajudante partem para investigar o vilarejo vizinho logo apos o\n"
                 "meio dia.\n", jogador.name, ajudante.name);
    Sleep(17500);
    printf("A viagem comeca silenciosa, com o vento cortando os rostos e a neve escondendo pegadas antigas.\n"
                 "Logo, um grupo de %s famintos cruza seu caminho e voces se preparam para essa batalhas.\n", monstroCampanha[0]->name);

    // criar o funcionamento da batalha

    return 0;
}

void verificacaoRapidaPersonagem(Jogador *jogador) {
    int quantArmas = 0, quantTruques = 0, quantMagia = 0;

    printf("==================Veficicacao==================\n");
    printf("Nome : %s - ", jogador->name);
    printf("Nivel : %d \n", jogador->nivel);
    printf("Raca : %s - ", jogador->raca);
    printf("Classe : %s\n", jogador->classe);
    printf("Vida : %d - ", jogador->vida);
    printf("Escudo : %d \n", jogador->escudo);

    for (int i = 0; i < 2; i++) {
        if (strcmp(jogador->arma[i].nameArma, "") != 0) {
            quantArmas++;
        }

        for (int j = 0; j < 10; j++) {
            if (strcmp(jogador->magia[i][j].nameMagia, "") != 0) {
                if (i == 0) {
                    quantTruques++;
                } else {
                    quantMagia++;
                }
            } else {
                break;
            }
        }
    }
    printf("Possui %d armas, %d truques e %d magias.\n\n", quantArmas, quantTruques, quantMagia);
}

void verificacaoRapidaMonstro(Monstro *monstro) {
    printf("==================Veficicacao==================\n");
    printf("Nome : %s\n", monstro->name);
    printf("Vida : %d - Escudo : %d\n\n", monstro->vida, monstro->escudo);
}

/*
 * ----------------CONTINUIDADE DA HISTÓRIA------------------
 * mas não são o bastante para deter a missão.
 * No entanto, à medida que se aproximam do vilarejo desaparecido, um número anormal de corvos começa
 * a seguir o grupo, soltando grasnados estridentes e incessantes.
 *
 * Quando finalmente alcançam a praça central, a cena é desoladora: no centro, cravado na terra congelada,
 * está um monólito negro rachado, envolto em uma aura pulsante. Dois Diabos dos Espinhos, feridos e
 * marcados com coleiras de energia mágica, arranham a superfície da pedra como se fossem compelidos a isso.
 *
 * Um deslize do assistente quebra o silêncio e inicia uma batalha brutal. Os dois demônios são derrotados,
 * mas o jovem ajudante cai em combate. No último suspiro de um dos diabos, uma última magia é lançada
 * contra o monólito, abrindo uma rachadura profunda.
 *
 * Mana pura escapa da pedra, revelando inscrições que até então estavam ocultas. O aventureiro se aproxima e lê:
 *
 * "Chamas do vazio, atendam ao chamado.
 * Que a oferenda de sangue abra o caminho."
 *
 * A rachadura cresce. A pedra se parte. Um círculo mágico se forma no céu, e então... ela surge.
 *
 * A Noiva do Abismo, uma entidade envolta em véus negros e gelo eterno, desce dos céus com um grito que
 * ecoa pela alma. Ela não ataca. Ela apenas observa, se apresenta ao mundo... e parte voando para o desconhecido.
 *
 * O verdadeiro terror, no entanto, está apenas começando.
 */