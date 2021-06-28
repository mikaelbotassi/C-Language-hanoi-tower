#include "pilha.h"

//######    ESTRUTURAS ###########
typedef struct NoPilha{
    int elemento;
    struct NoPilha *prox;
}NoPilha;

typedef struct Pilha{
    NoPilha *topo;
    int quant;
    char nome;
}Pilha;

//#######   FUNÇÕES #############
Pilha *inicializaPilha(char nome){   //Aloca um espaço na memória e inicia a Fila
    Pilha *p=(Pilha*) malloc(sizeof(Pilha));
    p->topo=NULL;
    p->quant=0;
    p->nome=nome;
    return p;
}

void empilha(int i, Pilha *p){  //Adiciona um novo elemento na Pilha
    NoPilha *auxPilha = (NoPilha*) malloc(sizeof(NoPilha));

    if(auxPilha==NULL){
        printf("\n\nDesculpe, ocorreu um erro ao alocar o novo no da Pilha.\n\n");
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

void excluiPilha(Pilha *p){//exclui toda pilha
    while(p->topo!=NULL){
        desempilha(p);
    }
}
void apresentaPilha(Pilha *p){//Apresenta os nós da Pilha ao CONTRÁRIO(Do primeiro para o último)
    Pilha *aux=inicializaPilha('X');
    int i;
    if(p->topo==NULL){
        //printf("Pilha Vazia!");
    }
    else{
        while(p->topo!=NULL){
            empilha(desempilha(p), aux);
        }
        while(aux->topo!=NULL){
            i=desempilha(aux);
            printf("%d  ", i);
            empilha(i, p);
        }
    }
}