#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

//######    ESTRUTURAS ###########
typedef struct No{
    int elemento;
    struct No *prox;
}No;

typedef struct Fila{
    No *inicio;
    No *fim;
}Fila;

//#######   FUNÇÕES #############

Fila *inicializaFila(){ //Aloca o espaço de memória da Fila
    Fila *f=(Fila*) malloc(sizeof(Fila));
    f->inicio=NULL;
    f->fim=NULL;
    return f;
}

void push(Fila * f, int novoEle){   //Adiciona um elemento da Fila
    No *novoNo = (No*) malloc(sizeof(No));
    if(novoNo==NULL){
        printf("\n\nDesculpe, ocorreu um erro ao alocar o novo nó.\n\n");
        return;
    }else{
        novoNo->elemento=novoEle;
        novoNo->prox=NULL;
        if(f->inicio==NULL){
            f->inicio=novoNo;
        }
        else{
            f->fim->prox=novoNo;
        }

        f->fim=novoNo;
        return;
    }

}

int pop(Fila *f){   //Retira um elemento da Fila
    No *aux=f->inicio;
    int elemento;
    if(aux==NULL){
        printf("\n\nFila vazia! Não é possível retirar elementos!\n\n");
        return;
    }
    else{
        f->inicio=f->inicio->prox;
        aux->prox=NULL;
        elemento=aux->elemento;
        free(aux);
        if(f->inicio==NULL){
            f->fim=NULL;
        }

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
            printf("%d  ", aux->elemento);
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