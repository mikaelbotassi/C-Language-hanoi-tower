#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

//######    ESTRUTURAS ###########
typedef struct No{
    char origem;
    char destino;
    struct No *prox;
}No;

typedef struct Fila{
    No *inicio;
    No *fim;
    int movimentos;
}Fila;

//#######   FUNÇÕES #############

Fila *inicializaFila(){ //Aloca o espaço de memória da Fila
    Fila *f=(Fila*) malloc(sizeof(Fila));
    f->inicio=NULL;
    f->fim=NULL;
    f->movimentos=0;
    return f;
}

void push(Fila * f, char origem, char destino){   //Adiciona um elemento da Fila
    No *novoNo = (No*) malloc(sizeof(No));
    if(novoNo==NULL){
        printf("\n\nDesculpe, ocorreu um erro ao alocar o novo nó.\n\n");
        return;
    }else{
        novoNo->origem=origem;
        novoNo->destino=destino;
        novoNo->prox=NULL;
        if(f->inicio==NULL){
            f->inicio=novoNo;
        }
        else{
            f->fim->prox=novoNo;
        }

        f->fim=novoNo;
        f->movimentos++;
        return;
    }

}

int pop(Fila *f){   //Retira um elemento da Fila
    No *aux=f->inicio;
    char elemento;
    if(aux==NULL){
        printf("\n\nFila vazia! Não é possível retirar elementos!\n\n");
        return;
    }
    else{
        f->inicio=f->inicio->prox;
        aux->prox=NULL;
        elemento=aux->origem;
        free(aux);
        if(f->inicio==NULL){
            f->fim=NULL;
        }
        f->movimentos--;
        return elemento;
    }
}

void imprimeFila(Fila *f){ //Imprime todos os elementos da fila
    No *aux=f->inicio;
    if(f->inicio==NULL){
        printf("\n\nFila vazia.\n\n");
    }
    else{
        while(aux!=NULL){
            printf("%c  %c", aux->origem, aux->destino);
            aux=aux->prox;
        }
    }
}

void excluiFila(Fila *f){   //Exclui a fila e desaloca a memória
    No *aux;
    while(f->inicio!=NULL){
        aux=f->inicio;
        f->inicio=f->inicio->prox;
        free(aux);
    }
    return;
}