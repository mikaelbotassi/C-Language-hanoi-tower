#ifndef _PILHA_H
#define _PILHA_H

//##### STRUCTS ###########

typedef struct NoPilha NoPilha;
typedef struct Pilha Pilha;

//########  FUNÇÕES #########

Pilha *inicializaPilha();
void empilha(int i, Pilha *p);
int desempilha(Pilha *p);

#endif