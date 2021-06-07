#ifndef _FILA_H
#define _FILA_H

//######    STRUCTS ##########

typedef struct No No;
typedef struct Fila Fila;

//##### FUNÇÕES ########

Fila *inicializaFila();
void push(Fila * f, int novoEle);
int pop(Fila *f);
void imprimeFila(Fila *f);
void excluiFila(Fila *f);

#endif