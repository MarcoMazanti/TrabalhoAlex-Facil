#include <stdio.h>
#include <windows.h>
#include "jogador.h"
#include "magia.h"
#include "arma.h"
#include "../Utils/utils.h"

// Função para zerar todos os dados do jogador, usada ao iniciar ou reiniciar o personagem
void zerarJogador(Jogador *jogador) {
    memset(jogador, 0, sizeof(Jogador));
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
    if (dano > 0) {
        if (jogador->vida > dano) {
            jogador->vida -= dano;
        } else {
            jogador->vida = 0;
            printf("%s morreu!\n\n", jogador->name);
        }
    } else if (dano == 0) {
        jogador->debuff = 'S';
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

// Função para o menu principal de ataque
int menuTipoAtaque(Jogador *jogador) {
    int tipoAtaque = 0;
inicio_menu_tipo:
    printf("Escolha qual tipo de ataque usara:\n");
    printf("1. Arma\n2. Truque\n3. Magia\n> ");
    char *possiveisAtaques[] = {"1", "2", "3", "arma", "truque", "magia", "1. Arma", "2. Truque", "3. Magia"};
    tipoAtaque = verificarEntrada(3, 9, possiveisAtaques, 0);

    return tipoAtaque;
}


// Função para o menu de armas
int menuArma(Jogador *jogador) {
    int especificoAtaque;

inicio_menu_arma:
    printf("Escolha com o que ira atacar (0 para voltar):\n");

    // Espaço real para as strings
    static char numero[2][4];             // "1", "2"
    static char nome[2][50];              // "Espadao", etc.
    static char completo[2][75];          // "1. Espadao"
    char *possiveisArmas[6];              // Aponta para as strings acima
    char texto[75];
    char parte1[50];

    for (int i = 0; i < 2; i++) {
        // Cria o texto formatado
        snprintf(texto, sizeof(texto), "%d. %s (%dd%d + %d)\n", i + 1,
                 jogador->arma[i].nameArma,
                 jogador->arma[i].quantDados,
                 jogador->arma[i].tipoDado,
                 jogador->arma[i].atributosSomados);

        char *espaco = strstr(texto, " (");
        char ataque[50];
        char dados[20];
        strcpy(dados, espaco + 1);
        int tamanhoNome = espaco - texto; // posição da substring

        strncpy(ataque, texto, tamanhoNome);   // copia o nome antes de " ("
        ataque[tamanhoNome] = '\0';

        printf("%s ", ataque);
        textoColorido(dados, "vermelho", "normal");

        // 1. Número ("1", "2")
        snprintf(numero[i], sizeof(numero[i]), "%d", i + 1);
        possiveisArmas[i] = numero[i];

        // 2. Nome da arma ("Espadao", etc.)
        if (espaco != NULL) {
            int tamanho = espaco - texto - 3; // Remove "1. " do começo
            if (tamanho >= sizeof(parte1)) tamanho = sizeof(parte1) - 1;
            strncpy(parte1, texto + 3, tamanho);
            parte1[tamanho] = '\0';
            strncpy(nome[i], parte1, sizeof(nome[i]) - 1);
            nome[i][sizeof(nome[i]) - 1] = '\0';
        }
        possiveisArmas[i + 2] = nome[i];

        // 3. Nome completo ("1. Espadao")
        snprintf(completo[i], sizeof(completo[i]), "%d. %s", i + 1, jogador->arma[i].nameArma);
        possiveisArmas[i + 4] = completo[i];
    }

    printf("Digite o numero da arma:\n> ");
    especificoAtaque = verificarEntrada(2, 6, possiveisArmas, 1);

    if (especificoAtaque == 0) return -1;

    return especificoAtaque - 1;
}


// Função para o menu de magias e truques
int menuMagia(Jogador *jogador, int tipoMagia) {
    int especificoAtaque;
    int maxMagias = contarMagiasDisponiveis(jogador, tipoMagia - 1);

inicio_menu_magia:
    printf("Escolha com o que ira atacar (0 para voltar):\n");

    // Espaço real para as strings
    char numero[maxMagias][4];
    char nome[maxMagias][50];
    char completo[maxMagias][75];
    char *possiveisMagias[maxMagias * 3];  // Aponta para as strings acima
    char texto[75];
    char parte1[50];

    for (int i = 0; i < maxMagias; i++) {
        snprintf(texto, sizeof(texto),"%d. %s (%dd%d + %d)\n",
               i + 1,
               jogador->magia[tipoMagia - 1][i].nameMagia,
               jogador->magia[tipoMagia - 1][i].quantDados,
               jogador->magia[tipoMagia - 1][i].tipoDado,
               jogador->magiaSomaAtributos);

        char *espaco = strstr(texto, " (");
        char ataque[50];
        char dados[20];
        strcpy(dados, espaco + 1);
        int tamanhoNome = espaco - texto; // posição da substring

        strncpy(ataque, texto, tamanhoNome);   // copia o nome antes de " ("
        ataque[tamanhoNome] = '\0';

        printf("%s ", ataque);
        textoColorido(dados,
            ((strcmp(jogador->magia[tipoMagia - 1][i].tipoMagia, "Cura") == 0) ? "verde" :
                (strcmp(jogador->magia[tipoMagia - 1][i].tipoMagia, "Defesa") == 0) ? "amarelo" : "vermelho"), "normal");

        snprintf(numero[i], sizeof(numero[i]), "%d", i + 1);
        possiveisMagias[i] = numero[i];

        if (espaco != NULL) {
            int tamanho = espaco - texto - 3; // Remove "1. " do começo
            if (tamanho >= sizeof(parte1)) tamanho = sizeof(parte1) - 1;
            strncpy(parte1, texto + 3, tamanho);
            parte1[tamanho] = '\0';
            strncpy(nome[i], parte1, sizeof(nome[i]) - 1);
            nome[i][sizeof(nome[i]) - 1] = '\0';
        }
        possiveisMagias[i + maxMagias] = nome[i];

        snprintf(completo[i], sizeof(completo[i]), "%d. %s", i + 1, jogador->magia[tipoMagia - 1][i].nameMagia);
        possiveisMagias[i + (maxMagias * 2)] = completo[i];
    }
    printf("Digite o numero %s:\n> ", ((tipoMagia - 1 == 0) ? "do truque" : "da magia"));
    especificoAtaque = verificarEntrada(maxMagias, maxMagias * 3, possiveisMagias, 1);

    if (especificoAtaque == 0) return -1;

    return especificoAtaque - 1;
}

// Função responsável por manusear o tipo de dano gerado
int ataqueJogador(Jogador *jogador) {
    int tipoAtaque, index, dano = 0;

menu_principal:
    // Exibe o menu principal de ataque (arma ou magia/truque)
    tipoAtaque = menuTipoAtaque(jogador);

    // Se o jogador escolheu ataque com arma
    if (tipoAtaque == 1) {
        index = menuArma(jogador);  // Mostra o menu de armas

        // Se o jogador escolheu voltar (0), retorna ao menu principal
        if (index == -1) goto menu_principal;

        // Calcula o dano da arma (rolando os dados)
        int somaDados = 0;
        for (int i = 0; i < jogador->arma[index].quantDados; i++) {
            somaDados += (rand() % (jogador->arma[index].tipoDado + 1));
        }

        dano = somaDados + jogador->arma[index].atributosSomados;

        return dano;

    } else if (tipoAtaque >= 2) {
    menu_tipo_magia:


        // Mostra o menu de magias do tipo escolhido (truque ou magia)
        index = menuMagia(jogador, tipoAtaque - 1);

        // Se quiser voltar do menu de magias, retorna ao menu principal
        if (index == -1) goto menu_principal;

        // Pega a magia escolhida
        Magia magia = jogador->magia[tipoAtaque - 2][index];

        // Lógica com base no tipo da magia
        if (strcmp(magia.tipoMagia, "Defesa") == 0) {
            dano = 0;  // Magia de defesa não causa dano
        } else if (strcmp(magia.tipoMagia, "Cura") == 0) {
            // Calcula a cura da magia (rolando os dados)
            int somaDados = 0;
            for (int i = 0; i < magia.quantDados; i++) {
                somaDados += (rand() % (magia.tipoDado) + 1);
            }

            dano = somaDados + jogador->magiaSomaAtributos;

            jogador->vida += dano;  // Recupera a vida do jogador
            dano = -1;  // Indica cura com valor negativo
        } else {
            // Magia ofensiva
            int somaDados = 0;
            for (int i = 0; i < magia.quantDados; i++) {
                somaDados += (rand() % (magia.tipoDado) + 1);
            }

            dano = somaDados + jogador->magiaSomaAtributos;
        }

        return dano;
    }

    // Segurança: qualquer caminho inválido volta ao menu principal
    goto menu_principal;
}

// Função para escolha de raça com bônus específicos
void escolherRaca(Jogador *jogador) {
    int respostaRaca;

    printf("Atualmente possui 3 racas disponiveis, sendo elas:\n");
    printf("1. Anao\n2. Elfo\n3. Humano\n");
    printf("Digite o numero que representa o que voce deseja :\n> ");
    char *casosRaca[] = {"1", "2", "3", "Anao", "Elfo", "Humano", "1. Anao", "2. Elfo", "3. Humano"};
    respostaRaca = verificarEntrada(3, 9, casosRaca, 0);

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
    printf("1. Barbaro\n2. Feiticeiro\n3. Mago\n4. Paladino\n");
    printf("Digite o numero que representa o que voce deseja :\n> ");
    char *casosClasse[] = {"1", "2", "3", "4", "Barbaro", "Feiticeiro", "Mago", "Paladino", "1. Barbaro", "2. Feiticeiro", "3. Mago", "4. Paladino"};
    respostaClasse = verificarEntrada(4, 12, casosClasse, 0);

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
    printf("Digite o nome para o seu personagem:\n> ");
    entradaDeNomeAceito(jogador->name);
    limparTela();
    printf("Seja bem vindo %s!\n", jogador->name);

    printf("Agora esta na hora de escolher a sua raca!\n");
    escolherRaca(jogador);
    limparTela();
    printf("Parabens, agora voce eh um %s!!!\n", jogador->raca);

    printf("Agora esta na hora de voce escolher a sua classe!\n");
    escolherClasse(jogador);
    printf("Parabens, agora voce eh um %s!!!\n", jogador->classe);

    printf("Agora sera gerado as magias e as armas para voce usar!\n");
    Sleep(1500);

    gerarMagias(jogador);
    gerarArmas(jogador);

    uparNivel(jogador, 5);
    jogador->iniciativa = modificacaoAtributos(jogador->destreza);
    jogador->magiaSomaAtributos = modificacaoAtributos(jogador->sabedoria);
}
