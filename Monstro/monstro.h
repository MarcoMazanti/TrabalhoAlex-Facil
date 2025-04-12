#ifndef MONSTRO_H
#define MONSTRO_H

typedef struct {
  char nomeAtaque[75];
  char tipoAtaque[10];
  int tipoDado;
  int quantDado;
  int atributosSomados;
} Ataque;

typedef struct {
  char name[50];
  char debuff;
  int vida;
  int escudo;
  int iniciativa;
  Ataque ataque[3];
} Monstro;

void zerarMonstro(Monstro *monstro);
void receberDanoMonstro(Monstro *monstro, int dano);
int ataqueMonstro(Monstro *monstro);
void criarMonstrosIguais(Monstro *monstro[], const char objetivo[], int quantidade);
void criarMonstrosDiferentes(Monstro *monstro[], const char objetivo[], int quantidade);

#endif