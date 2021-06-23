#ifndef _PILHA_H
#define _PILHA_H

//##### STRUCTS ###########

typedef struct NoPilha NoPilha;
typedef struct Pilha Pilha;

//########  FUNÇÕES #########

Pilha *inicializaPilha(char nome);
void empilha(int i, Pilha *p);
int desempilha(Pilha *p);
int inserirDisco(Pilha *p, int total, char pino);
int validaQuantDiscos(int i, int total);
void leDiscos(Pilha *p, int i);
int pegaTotalDiscos();
void excluiPilha(Pilha *p);
int validaRaio(Pilha *p, int raio);
void apresentaPilha(Pilha *p);
apresentaEntrada(Pilha *A, Pilha *B, Pilha *C);
void resolucaoHanoi(Pilha *orig, Pilha *aux, Pilha *dest, int total);
void moveDisco(Pilha *A, Pilha *B);

#endif