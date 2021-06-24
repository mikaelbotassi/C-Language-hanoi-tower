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

int inserirDisco(Pilha *p, int total, char pino){
    int i;
    if(total!=0){
    printf("Quantos Discos ha no pino %c?", pino);
    scanf("%d", &i);
    }
    else{
        return total;
    }
    i=validaQuantDiscos(i, total);
    total=total-i;
    leDiscos(p,i);
    return total;
}

int validaQuantDiscos(int i, int total){
    while(i>total){
        printf("\nNumero invalido! O número de discos neste pino excede a quantidade total de discos");
        printf("\nDigite a quantidade novamente: ");
        scanf("%d", &i);
    }
    return i;
}

void leDiscos(Pilha *p, int i){
    int cont,raio;
    for(cont=1;cont<=i;cont++){
        printf("Digite o raio do %i disco: ", cont);
        scanf("%d", &raio);
        empilha(raio, p);
    }
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

int pegaTotalDiscos(){
    int i;
    printf("\nDigite o total de discos(Maximo 10): ");
    scanf("%d", &i);
    while(i>10){
        printf("O numero de discos excede o limite que e 10, por favor Digite Novamente: ");
        scanf("%d", &i);
    }
    return i;
}

void excluiPilha(Pilha *p){
    while(p->topo!=NULL){
        desempilha(p);
    }
}
void apresentaPilha(Pilha *p){
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

void apresentaEntrada(Pilha *A, Pilha *B, Pilha *C){
    int total= A->quant+B->quant+C->quant;
    printf("\n\n");
    printf("\n%d\n", total);

    printf("%d  ", A->quant);
    apresentaPilha(A);

    printf("\n%d  ", B->quant);
    apresentaPilha(B);
    
    printf("\n%d  ", C->quant);
    apresentaPilha(C);
}

void moveDisco(Pilha *A, Pilha *B){
    printf("\nMover o disco de raio %d, de %c para %c", A->topo->elemento, A->nome, B->nome);
    empilha(desempilha(A), B);
}

void resolucaoHanoi(Pilha *orig, Pilha *aux, Pilha *dest, int total){
    if(total==1){
        moveDisco(orig,dest);
    }
    else{
        resolucaoHanoi(orig, dest, aux, total-1);
        moveDisco(orig, dest);
        resolucaoHanoi(aux,orig,dest, total-1);
    }
}
char hanoiSimples(Pilha *orig, Pilha *aux, Pilha *dest, int total){
    if(orig->quant>0 & aux->quant==0 & dest->quant==0){
        return 'A';
    }
    if(orig->quant==0 & aux->quant>0 & dest->quant==0){
        return 'B';
    }
    if(dest->quant>0 & aux->quant==0 & dest->quant==0){
        return 'C';
    }
}

void cerebro(Pilha *orig, Pilha *aux, Pilha *dest, int total){
    while(dest->quant!=total){
        if(hanoiSimples(orig, aux, dest, total)=='A'){
            resolucaoHanoi(orig, aux, dest, orig->quant);
        }
        if(hanoiSimples(orig, aux, dest, total)=='B'){
            resolucaoHanoi(aux, orig, dest, aux->quant);
        }
        if(hanoiSimples(orig, aux, dest, total)=='C'){
            return;
        }
        //if(hanoiDoisPinos())

    }
}