//####  TRABALHO 1 ESTRUTURA DE DADOS #################

//### INCLUDES ###############
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <string.h>

//###########   STRUCTS #############

//##### Struct Fila ########
typedef struct No{
    int elemento;
    struct No *prox;
}No;

typedef struct Fila{
    No *inicio;
    No *fim;
}Fila;

//###### Struct Pilha ##########
typedef struct NoPilha{
    int elemento;
    struct NoPilha *prox;
}NoPilha;

typedef struct Pilha{
    NoPilha *topo;
}Pilha;

//#######      FUNÇÕES  #################

//####  FUNÇÕES FILA ########
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

//###### FUNÇÕES PILHA ##########

Pilha *inicializaPilha(){   //Aloca um espaço na memória e inicia a Fila
    Pilha *p=(Pilha*) malloc(sizeof(Pilha));
    p->topo=NULL;
}

void empilha(int i, Pilha *p){  //Adiciona um novo elemento na Pilha
    NoPilha *auxPilha = (NoPilha*) malloc(sizeof(NoPilha));

    if(auxPilha==NULL){
        printf("\n\nDesculpe, ocorreu um erro ao alocar o novo nó da Pilha.\n\n");
        return;
    }
    else{
        auxPilha->elemento=i;

        auxPilha->prox=p->topo;

        p->topo=auxPilha;

        return;
    }

}

int desempilha(Pilha *p){   //Retira um elemento da Pilha
    NoPilha *aux= p->topo;
    int elemento;

    if(aux==NULL){
        printf("Pilha Vazia!\n");
        return;
    }
    else{
        p->topo=aux->prox;
        aux->prox=NULL;
        elemento=aux->elemento;
        free(aux);
        return elemento;
        }
}