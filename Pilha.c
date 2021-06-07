#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

//######    ESTRUTURAS ###########
typedef struct NoPilha{
    int elemento;
    struct NoPilha *prox;
}NoPilha;

typedef struct Pilha{
    NoPilha *topo;
}Pilha;

//#######   FUNÇÕES #############
Pilha *inicializaPilha(){   //Aloca um espaço na memória e inicia a Fila
    Pilha *p=(Pilha*) malloc(sizeof(Pilha));
    p->topo=NULL;
    return p;
}

void inserirDisco(Pilha *p, int total){
    int i;
    printf("Quantos Discos há no pino? ");
    scanf("%d", &i);
    i=validaQuantDiscos(i, total);
    leDiscos(p,i);
}

int validaQuantDiscos(int i, int total){
    while(i>total){
        printf("\nNúmero inválido! O número de discos neste pino excede a quantidade total de discos");
        printf("\nDigite a quantidade novamente: ");
        scanf("%d", &i);
    }
    return i;
}

void leDiscos(Pilha *p, int i){
    int cont,raio;
    for(cont=1;cont<=i;cont++){
        printf("Digite o raio do %iº disco: ", cont);
        scanf("%d", &raio);
        empilha(raio, p);
    }
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

void excluiFila(Pilha *p){
    while(p->topo!=NULL){
        desempilha(p);
    }
}