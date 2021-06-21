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
    int quant;
}Pilha;

//#######   FUNÇÕES #############
Pilha *inicializaPilha(){   //Aloca um espaço na memória e inicia a Fila
    Pilha *p=(Pilha*) malloc(sizeof(Pilha));
    p->topo=NULL;
    p->quant=0;
    return p;
}

int inserirDisco(Pilha *p, int total){
    int i;
    scanf("%d", &i);
    i=validaQuantDiscos(i, total);
    total=total-i;
    leDiscos(p,i);
    return total;
}

int validaQuantDiscos(int i, int total){
    while(i>total){
        scanf("%d", &i);
    }
    return i;
}

void leDiscos(Pilha *p, int i){
    int cont,raio;
    for(cont=1;cont<=i;cont++){
        scanf("%d", &raio);
        raio=validaRaio(p, raio);
        empilha(raio, p);
    }
}
int validaRaio(Pilha *p, int raio){
    while(raio<=0){
        scanf("%d", &raio);
    }
    if(p->topo==NULL){
    }
    else{
        while(raio>p->topo->elemento){
            scanf("%d", &raio);
        }
    }
    return raio;
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
        p->quant++;

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
        p->quant--;
        return elemento;
        }
}

int pegaTotalDiscos(){
    int i;
    scanf("%d", &i);
    while(i>10){
        scanf("%d", &i);
    }
    return i;
}

void excluiPilha(Pilha *p){
    while(p->topo!=NULL){
        desempilha(p);
    }
}