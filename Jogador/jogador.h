#ifndef JOGADOR_H
#define JOGADOR_H

typedef struct {
    char nameArma[50];
    int tipoDado;
    int quantDados;
    int atributosSomados;
} Arma;

typedef struct {
    char nameMagia[50];
    char tipoMagia[10]; // ataque, defesa ou cura
    int tipoDado;
    int quantDados;
} Magia;

typedef struct {
    char name[75];
    char raca[50];
    char classe[50];
    char ataqueExtra;
    char debuff;
    int nivel;
    int vida;
    int vidaMax;
    int dadoVida;
    int escudo;
    int iniciativa;
    int dinheiro;
    Arma arma[2];       // 1 arma para perto e outra para distância
    Magia magia[2][10]; // 0 - truques | 1 - magias
    int forca;          // para ataque corpo a corpo
    int destreza;       // para ataques a distancia
    int constituicao;   // para vida
    int sabedoria;      // para ataque de magia
    int proficiencia;
    int magiaSomaAtributos;
} Jogador;

void zerarJogador(Jogador *jogador);
int modificacaoAtributos(int atributo);
void uparNivel(Jogador *jogador, int quantidade);
void receberDanoJogador(Jogador *jogador, int dano);
int contarMagiasDisponiveis(Jogador *jogador, int tipo);
int ataqueJogador(Jogador *jogador);
void criarJogador(Jogador *jogador);

#endif
