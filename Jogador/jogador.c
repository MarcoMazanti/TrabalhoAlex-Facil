#include <stdio.h>
#include <windows.h>
#include "jogador.h"
#include "magia.h"
#include "arma.h"
#include "../fimJogo.h"

// Função para zerar todos os dados do jogador, usada ao iniciar ou reiniciar o personagem
void zerarJogador(Jogador *jogador) {
    // Reset de strings
    strcpy(jogador->name, "");
    strcpy(jogador->raca, "");
    strcpy(jogador->classe, "");
    jogador->ataqueExtra = 'N';

    // Reset de atributos básicos
    jogador->nivel = 0;
    jogador->vida = 0;
    jogador->dadoVida = 0;
    jogador->escudo = 0;
    jogador->iniciativa = 0;
    jogador->dinheiro = 0;
    jogador->forca = 0;
    jogador->destreza = 0;
    jogador->constituicao = 0;
    jogador->sabedoria = 0;
    jogador->proficiencia = 0;
    jogador->magiaSomaAtributos = 0;

    // Zera armas
    for (int i = 0; i < 2; i++) {
        strcpy(jogador->arma[i].nameArma, "");
        jogador->arma[i].tipoDado = 0;
        jogador->arma[i].quantDados = 0;
        jogador->arma[i].atributosSomados = 0;
    }

    // Zera magias (truques e magias)
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 10; j++) {
            strcpy(jogador->magia[i][j].nameMagia, "");
            strcpy(jogador->magia[i][j].tipoMagia, "");
            jogador->magia[i][j].tipoDado = 0;
            jogador->magia[i][j].quantDados = 0;
        }
    }
}

// Função que calcula o modificador de atributo (baseado em D&D)
int modificacaoAtributos(int atributo) {
    return (atributo - 10) / 2;
}

// Função para upar o jogador de nível e ajustar a vida
void uparNivel(Jogador *jogador, int quantidade) {
    if (jogador->nivel == 0) {
        jogador->vida += jogador->dadoVida + modificacaoAtributos(jogador->constituicao) + 10;
        jogador->nivel++;
        quantidade--;
    }

    for (int i = 0; i < quantidade; i++) {
        jogador->vida += jogador->dadoVida / 2 + modificacaoAtributos(jogador->constituicao) + 1;
    }
    jogador->nivel += quantidade;

    jogador->vidaMax = jogador->vida;
}

// Função para tratar o recebimento de dano pelo jogador
void receberDanoJogador(Jogador *jogador, int dano) {
    if (jogador->vida > dano) {
        jogador->vida -= dano;
    } else {
        jogador->vida = 0;
        jogadorMorreu(); // chama função de fim de jogo
    }
}

// Conta quantas magias de determinado tipo o jogador possui
int contarMagiasDisponiveis(Jogador *jogador, int tipo) {
    int count = 0;
    for (int i = 0; i < 10; i++) {
        if (strcmp(jogador->magia[tipo][i].nameMagia, "") != 0)
            count++;
        else
            break;
    }
    return count;
}

// Função que executa um ataque, seja com arma ou magia
int ataqueJogador(Jogador *jogador) {
    int dano = 0;
    int tipoAtaque = 0, tipoMagia = 0, expecificoAtaque = 0;
    char repetir;

    // Escolha do tipo de ataque
    do {
        printf("Escolha qual tipo de ataque usara:\n");
        printf("1. Arma\n2. Magia ou Truque\n>");
        scanf("%d", &tipoAtaque);

        if (tipoAtaque < 1 || tipoAtaque > 2) {
            repetir = 'S';
            printf("Voce escolheu tipo inexistente!\n");
        } else {
            repetir = 'N';
        }
    } while (repetir == 'S');

    // Ataque com arma
    if (tipoAtaque == 1) {
        do {
            printf("Escolha com o que irá atacar:\n");
            for (int i = 0; i < 2; i++) {
                printf("%d. %s (%dd%d + %d)\n", i + 1,
                       jogador->arma[i].nameArma,
                       jogador->arma[i].quantDados,
                       jogador->arma[i].tipoDado,
                       jogador->arma[i].atributosSomados);
            }
            printf("Digite o número da arma:\n>");
            scanf("%d", &expecificoAtaque);

            if (expecificoAtaque < 1 || expecificoAtaque > 2) {
                repetir = 'S';
                printf("Escolha inválida!\n");
            } else {
                repetir = 'N';
                int somaDados = 0;
                for (int i = 0; i < jogador->arma[expecificoAtaque - 1].quantDados; i++) {
                    somaDados += (rand() % jogador->arma[expecificoAtaque - 1].tipoDado) + 1;
                }
                dano = somaDados + jogador->arma[expecificoAtaque - 1].atributosSomados;
            }
        } while (repetir == 'S');
    }
    // Ataque com magia
    else {
        do {
            printf("Escolha se usara um truque ou magia:\n1. Truque\n2. Magia\n>");
            scanf("%d", &tipoMagia);

            if (tipoMagia < 1 || tipoMagia > 2) {
                repetir = 'S';
                printf("Tipo inválido!\n");
            } else {
                repetir = 'N';
            }
        } while (repetir == 'S');

        int maxMagias = contarMagiasDisponiveis(jogador, tipoMagia - 1);

        do {
            printf("Escolha com o que irá atacar:\n");
            for (int i = 0; i < maxMagias; i++) {
                printf("%d. %s (%dd%d + %d)\n",
                       i + 1,
                       jogador->magia[tipoMagia - 1][i].nameMagia,
                       jogador->magia[tipoMagia - 1][i].quantDados,
                       jogador->magia[tipoMagia - 1][i].tipoDado,
                       jogador->magiaSomaAtributos);
            }
            printf("Digite o número da magia:\n>");
            scanf("%d", &expecificoAtaque);

            if (expecificoAtaque < 1 || expecificoAtaque > maxMagias) {
                repetir = 'S';
                printf("Escolha inválida!\n");
            } else {
                repetir = 'N';
                int somaDados = 0;
                for (int i = 0; i < jogador->magia[tipoMagia - 1][expecificoAtaque - 1].quantDados; i++) {
                    somaDados += (rand() % jogador->magia[tipoMagia - 1][expecificoAtaque - 1].tipoDado) + 1;
                }
                dano = somaDados + jogador->magiaSomaAtributos;
            }
        } while (repetir == 'S');
    }

    return dano + 1;
}

// Função para escolha de raça com bônus específicos
void escolherRaca(Jogador *jogador) {
    char repetir;
    int respostaRaca;

    printf("Atualmente possui 3 racas disponiveis, sendo elas:\n");
    do {
        printf("1. Anao\n2. Elfo\n3. Humano\n>");
        scanf("%d", &respostaRaca);

        if (respostaRaca < 1 || respostaRaca > 3) {
            repetir = 'S';
            printf("Voce escolheu uma raca ainda nao cadastrada!\n");
        } else {
            repetir = 'N';
        }
    } while (repetir == 'S');

    switch (respostaRaca) {
        case 1:
            strcpy(jogador->raca, "Anao");
            jogador->constituicao += 2;
            jogador->forca += 2;
            break;
        case 2:
            strcpy(jogador->raca, "Elfo");
            jogador->destreza += 2;
            jogador->sabedoria += 2;
            break;
        case 3:
            strcpy(jogador->raca, "Humano");
            jogador->forca += 1;
            jogador->destreza += 1;
            jogador->constituicao += 1;
            jogador->sabedoria += 1;
            break;
    }
}

// Função para escolha de classe com configuração inicial de atributos
void escolherClasse(Jogador *jogador) {
    char repetir;
    int respostaClasse;

    printf("Atualmente possui 4 classes disponiveis:\n");
    do {
        printf("1. Barbaro\n2. Feiticeiro\n3. Mago\n4. Paladino\n>");
        scanf("%d", &respostaClasse);

        if (respostaClasse < 1 || respostaClasse > 4) {
            repetir = 'S';
            printf("Voce escolheu uma classe ainda nao cadastrada!\n");
        } else {
            repetir = 'N';
        }
    } while (repetir == 'S');

    // Distribuição de atributos com base na classe
    switch (respostaClasse) {
        case 1:
            strcpy(jogador->classe, "Barbaro");
            jogador->ataqueExtra = 'S';
            jogador->proficiencia += 3;
            jogador->dadoVida = 12;
            jogador->escudo = 16;
            jogador->forca += 15;
            jogador->destreza += 10;
            jogador->constituicao += 12;
            jogador->sabedoria += 8;
            break;
        case 2:
            strcpy(jogador->classe, "Feiticeiro");
            jogador->ataqueExtra = 'N';
            jogador->proficiencia += 3;
            jogador->dadoVida = 6;
            jogador->escudo = 14;
            jogador->forca += 8;
            jogador->destreza += 12;
            jogador->constituicao += 10;
            jogador->sabedoria += 15;
            break;
        case 3:
            strcpy(jogador->classe, "Mago");
            jogador->ataqueExtra = 'N';
            jogador->proficiencia += 3;
            jogador->dadoVida = 6;
            jogador->escudo = 13;
            jogador->forca += 8;
            jogador->destreza += 12;
            jogador->constituicao += 10;
            jogador->sabedoria += 15;
            break;
        case 4:
            strcpy(jogador->classe, "Paladino");
            jogador->ataqueExtra = 'S';
            jogador->proficiencia += 3;
            jogador->dadoVida = 10;
            jogador->escudo = 17;
            jogador->forca += 15;
            jogador->destreza += 8;
            jogador->constituicao += 10;
            jogador->sabedoria += 12;
            break;
    }
}

void criarJogador(Jogador *jogador) {
    printf("Digite o nome para o seu personagem:\n>");
    fgets(jogador->name, sizeof(jogador->name), stdin);
    jogador->name[strcspn(jogador->name, "\n")] = '\0'; // remove o último \n posto pelo fgets()
    printf("Seja bem vindo %s!\n", jogador->name);

    printf("Agora esta na hora de escolher a sua raca!\n");
    Sleep(1500);
    escolherRaca(jogador);
    printf("Parabens, agora voce eh um %s!!!\n", jogador->raca);

    printf("Agora esta na hora de voce escolher a sua classe!\n");
    Sleep(1500);
    escolherClasse(jogador);
    printf("Parabens, agora voce eh um %s!!!\n", jogador->classe);

    printf("Agora sera gerado as magias e as armas para voce usar!\n");

    gerarMagias(jogador);
    gerarArmas(jogador);

    uparNivel(jogador, 5);
    jogador->iniciativa = modificacaoAtributos(jogador->destreza);
    jogador->magiaSomaAtributos = modificacaoAtributos(jogador->sabedoria);
}
