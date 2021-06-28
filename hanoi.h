#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "fila.h"

#ifndef _HANOI_H
#define _HANOI_H

int inserirDisco(Pilha *p, int total, char pino);
int validaQuantDiscos(int i, int total);
void leDiscos(Pilha *p, int i);
int pegaTotalDiscos();
void apresentaEntrada(Pilha *A, Pilha *B, Pilha *C);
void moveDisco(Pilha *A, Pilha *B, Fila *movimentos);
void resolucaoHanoi(Pilha *orig, Pilha *aux, Pilha *dest, int total, Fila *movimentos);
void resolveHanoiSimples(Pilha *orig, Pilha *aux, Pilha *dest, Fila *movimentos);
char hanoiSimples(Pilha *orig, Pilha *aux, Pilha *dest);
int verificaTipo(Pilha *orig, Pilha *aux, Pilha *dest);
int verificaTipoHanoiDuplo(Pilha *orig, Pilha *aux, Pilha *dest);
void resolveHanoiDuplo(Pilha *orig, Pilha *aux, Pilha *dest, Fila *movimentos);
int verificaTipoHanoiTriplo(Pilha *orig, Pilha *aux, Pilha *dest);
void resolveHanoiTriplo(Pilha *orig, Pilha *aux, Pilha *dest, Fila *movimentos);
void cerebro(Pilha *orig, Pilha *aux, Pilha *dest, int total, Fila *movimentos);

#endif