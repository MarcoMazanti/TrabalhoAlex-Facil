#include <stdio.h>
#include <windows.h>
#include <time.h>
#include "Jogador/jogador.h"
#include "Ajudante/ajudante.h"
#include "Monstro/monstro.h"
#include "Batalha/batalha.h"

void verificacaoRapidaPersonagem(Jogador *jogador);
void verificacaoRapidaMonstro(Monstro *monstro);

int main() {
    srand(time(NULL));
    int quantMonstrosCampanha = 3;

    // Cria os personagens que participarão do RPG
    Jogador jogador, ajudante;
    Monstro *monstroCampanha[quantMonstrosCampanha];

    // Previne vir algum lixo de memória
    zerarJogador(&jogador);
    zerarJogador(&ajudante);

    criarJogador(&jogador);
    gerarAjudante(&ajudante, &jogador);

    // Verifica se foi criado tudo certo, apenas para o desenvolvimento do código
    verificacaoRapidaPersonagem(&jogador);
    verificacaoRapidaPersonagem(&ajudante);

    // Início da história do RPG
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("---------------------------------------O Chamado do Inverno---------------------------------------\n\n");
    printf(" O inverno chegou mais cedo este ano, trazendo com ele nao apenas o frio cortante das montanhas,\n"
                 "mas tambem o silencio inquietante que paira sobre as terras do norte. Desde que um estranho objeto\n"
                 "caiu do ceu sobre o vilarejo vizinho, nenhuma mensagem, nenhuma caravana e nenhum som de vida\n"
                 "foram ouvidos daquela direcao.\n");
    Sleep(15000);
    printf(" Diante da urgencia e do crescente temor entre os moradores, o chefe da vila decide enviar um\n"
                 "aventureiro chamado %s, conhecido por suas facanhas, para investigar o ocorrido.\n"
                 "Como a situacao parece perigosa demais para ser enfrentada sozinho, um jovem assistente chamado\n"
                 "%s eh designado para acompanha-lo.\n"
                 " Com isso, voce e seu novo ajudante partem para investigar o vilarejo vizinho logo apos o\n"
                 "meio dia.\n", jogador.name, ajudante.name);
    Sleep(17500);

    int quantBatalhas = rand() % 6;
    for (int i = 0; i < quantBatalhas; i++) {
        printf(" A viagem ocorria silenciosamente, com o vento cortando os rostos e a neve escondendo pegadas\n"
                     "antigas. Logo, um grupo de monstros famintos cruza seu caminho e voces se preparam para essa\n"
                     "batalha.\n");
        Sleep(17500);

        quantBatalhas++;

        // Atribui os valores para cada respectivo monstro
        criarMonstrosIguais(monstroCampanha, "Campanha", quantMonstrosCampanha);
        batalhar(&jogador, &ajudante, monstroCampanha, quantMonstrosCampanha);

        jogador.vida = jogador.vidaMax;
        ajudante.vida = ajudante.vidaMax;

        printf("\n Apos essa batalha, voces descansam um pouco e logo apos parte para viagem, mas pouco tempo\n"
                     "depois acaba escurecendo e voces descidem descansar e irem dormir.\n"
                     " Apos acordarem, voces ja partem em viagem.");
    }

    printf(" A medida que se aproximam do vilarejo desaparecido, um número anormal de corvos começa a seguir o\n"
                 "grupo, soltando grasnados estridentes e incessantes.\n\n");
    Sleep(10000);
    printf(" Conforme chegava na vila, aparecia mais e mais corpos espalhados pelo chao, alguns queimados e\n"
                 "outros com um tipo de espinho enfiados neles e quando finalmente alcancam a praca central, a cena\n"
                 "eh desoladora: no centro, cravado na terra congelada, esta um monolito negro rachado, envolto em\n"
                 "uma aura pulsante, juntamente com dois diabos dos espinhos.\n");
    printf(" Conforme observa essa cena, voces percebem que os dois monstros aparentam estar feridos e com um\n"
                 "tipo de coleiras magiacas em si, mas o mais estranho eh o que eles estão fazendo, eles estão\n"
                 "arranhando aquele monolito, querendo quebra-lo.\n");
    Sleep(20000);
    printf(" Por um pequeno deslize do %s, os monstros percebem que nao estao mais sozinho e partem\n"
                 "para a matar os invasores!!!\n", ajudante.name);

    quantMonstrosCampanha = 2;
    criarMonstrosIguais(monstroCampanha, "Boss", quantMonstrosCampanha);
    batalhar(&jogador, &ajudante, monstroCampanha, quantMonstrosCampanha);

    printf("\n Apos dar o golpe final o segundo diabo, em seu ultimo ato, ele lança uma magia no monolito que\n"
                 "gera uma rachadura profunda. Logo apos isso, o monolito comeca a emanar mana pura em grande\n"
                 "quantidade e revela inscricoes que estavam ocultas!\n"
                 " Curioso, voce vai ver ler o que estava escrilo: \n\n");
    printf("Chamas do vazio, atendam ao chamado.\n"
                 "Que a oferenda se sangue abra o caminho.\n\n");
    Sleep(2000);
    printf(" Apos terminar de ler, a rachadura comeca a crescer ate que a pedra se parte ao meio e lanca\n"
                 "um enorme circulo magico no ceu, o maior que voce ja tenha ouvido falar ou visto.\n"
                 " E entao, algo comeca a surgir. Uma figura feminina, parecendo uma noiva, mas com um vestido\n"
                 "escuro e rasgado nas pontas.\n");
    Sleep(12500);
    printf(" Conforme surgia essa noiva, mais e mais gelado ficava o local e diversos gritos comecam a surgir\n"
                 "do ceu que ecoam na alma dos vivos e então voce se lembra que ja ouviu falar desse monstro,\n"
                 "um monstro que destruiu cidades por completo, mas achava ate esse ponto que era mentira devido a\n"
                 "tanto tempo que se passava esse boato e nunca ser comprovado, mas se lembrava do nome: \n"
                 " A Noiva do Abismo\n\n");
    Sleep(12500);
    printf(" Voce esta completamente aterrorizado com o que esta acontecendo e observa que a noiva nao esta\n"
                 "atacando, ela apenas observa ao redor como que estivesse se apresentando ao mundo e logo apos\n"
                 "ela parte voando para o desconhecido.\n"
                 " Apenas uma frase passa na sua cabeça agora:\n"
                 " O verdadeiro terror esta apenas comecando!\n");
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
    printf("Iniciatival : %d\n", monstro->iniciativa);
}