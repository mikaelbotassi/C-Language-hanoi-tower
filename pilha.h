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
void apresentaEntrada(Pilha *A, Pilha *B, Pilha *C);
void resolucaoHanoi(Pilha *orig, Pilha *aux, Pilha *dest, int total);
char hanoiSimples(Pilha *orig, Pilha *aux, Pilha *dest);
void resolveHanoiSimples(Pilha *orig, Pilha *aux, Pilha *dest);
void resolveHanoiDuplo(Pilha *orig, Pilha *aux, Pilha *dest);
void hanoiDuplo(Pilha *orig, Pilha *aux, Pilha *dest);
void cerebro(Pilha *orig, Pilha *aux, Pilha *dest, int total);
void resolveHanoiTriplo(Pilha *orig, Pilha *aux, Pilha *dest);
void moveDisco(Pilha *A, Pilha *B);

#endif