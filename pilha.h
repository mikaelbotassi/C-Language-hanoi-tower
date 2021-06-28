#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef _PILHA_H
#define _PILHA_H

//##### STRUCTS ###########

typedef struct NoPilha{
    int elemento;
    struct NoPilha *prox;
}NoPilha;

typedef struct Pilha{
    NoPilha *topo;
    int quant;
    char nome;
}Pilha;

//########  FUNÇÕES #########

Pilha *inicializaPilha(char nome);
void empilha(int i, Pilha *p);
int desempilha(Pilha *p);
void excluiPilha(Pilha *p);
void apresentaPilha(Pilha *p);

#endif