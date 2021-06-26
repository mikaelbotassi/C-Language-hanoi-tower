#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef _FILA_H
#define _FILA_H

//######    STRUCTS ##########

typedef struct No No;
typedef struct Fila Fila;

//##### FUNÇÕES ########

Fila *inicializaFila();
void push(Fila * f, char origem, char destino);
char pop(Fila *f);
void imprimeFila(Fila *f);
void excluiFila(Fila *f);

#endif