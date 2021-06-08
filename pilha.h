#ifndef _PILHA_H
#define _PILHA_H

//##### STRUCTS ###########

typedef struct NoPilha NoPilha;
typedef struct Pilha Pilha;

//########  FUNÇÕES #########

Pilha *inicializaPilha();
void empilha(int i, Pilha *p);
int desempilha(Pilha *p);
int inserirDisco(Pilha *p, int total);
int validaQuantDiscos(int i, int total);
void leDiscos(Pilha *p, int i);
int pegaTotalDiscos();
void excluiPilha(Pilha *p);

#endif