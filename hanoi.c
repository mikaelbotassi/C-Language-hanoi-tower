#include "hanoi.h"

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
    /*if(A->quant!=0 && B->quant!=0){
        if(A->topo>B->topo){
            return;
        }
    }
    else{*/
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

void resolveHanoiSimples(Pilha *orig, Pilha *aux, Pilha *dest){
    if(hanoiSimples(orig, aux, dest)=='A'){
            resolucaoHanoi(orig, aux, dest, orig->quant);
        }
    if(hanoiSimples(orig, aux, dest)=='B'){
        resolucaoHanoi(aux, orig, dest, aux->quant);
    }
    if(hanoiSimples(orig, aux, dest)=='C'){
        return;
    }
}

char hanoiSimples(Pilha *orig, Pilha *aux, Pilha *dest){
    if(orig->quant>0 && aux->quant==0 && dest->quant==0){
        return 'A';
    }
    if(orig->quant==0 && aux->quant>0 && dest->quant==0){
        return 'B';
    }
    if(dest->quant>0 && aux->quant==0 && dest->quant==0){
        return 'C';
    }
    else{
        return 'X';
    }
}

int verificaTipo(Pilha *orig, Pilha *aux, Pilha *dest){
    if((orig->quant>0 && aux->quant>0 && dest->quant==0) || (orig->quant>0 && aux->quant==0 && dest->quant>0)||(orig->quant==0 && aux->quant>0 && dest->quant>0)){
        return 2;
    }
    if(orig->quant>0 && aux->quant>0 && dest->quant>0){
        return 3;
    }
}

int verificaTipoHanoiDuplo(Pilha *orig, Pilha *aux, Pilha *dest){
    if(orig->quant>0 && aux->quant>0){
        if((orig->topo->elemento>aux->topo->elemento) && dest->quant==0){
        return 1;
        }
    }
    else{
        return 0;
    }
}

void resolveHanoiDuplo(Pilha *orig, Pilha *aux, Pilha *dest){
    if(verificaTipoHanoiDuplo(orig, aux, dest)==1){
        resolucaoHanoi(aux, dest, orig, aux->quant);
    }
    if(verificaTipoHanoiDuplo(aux, orig, dest)==1){
        resolucaoHanoi(orig, dest, aux, orig->quant);
    }
    if(verificaTipoHanoiDuplo(orig, dest, aux)==1){
        resolucaoHanoi(dest, aux, orig, dest->quant);
    }
    if(verificaTipoHanoiDuplo(dest, orig, aux)==1){
        resolucaoHanoi(orig, aux, dest, orig->quant);
    }
    if(verificaTipoHanoiDuplo(aux, dest, orig)==1){
        resolucaoHanoi(dest, orig, aux, dest->quant);
    }
    if(verificaTipoHanoiDuplo(dest, aux, orig)==1){
        resolucaoHanoi(aux, orig, dest, aux->quant);
    }
}

int verificaTipoHanoiTriplo(Pilha *orig, Pilha *aux, Pilha *dest){
    if(orig->quant!=0 && aux->quant!=0 && dest->quant!=0){
        if((orig->topo->elemento>aux->topo->elemento) && (orig->topo->elemento>dest->topo->elemento)&&(aux->topo->elemento>dest->topo->elemento)){
        return 1;
    }
    }
    else{
        return 0;
    }
}

void resolveHanoiTriplo(Pilha *orig, Pilha *aux, Pilha *dest){
    if(verificaTipoHanoiTriplo(orig,aux,dest)==1){
        resolucaoHanoi(dest,orig,aux, dest->quant);
    }
    if(verificaTipoHanoiTriplo(orig,dest,aux)==1){
        resolucaoHanoi(aux,orig,dest, aux->quant);
    }
    if(verificaTipoHanoiTriplo(aux,orig,dest)==1){
        resolucaoHanoi(dest,aux,orig, dest->quant);
    }
    if(verificaTipoHanoiTriplo(aux,dest,orig)==1){
        resolucaoHanoi(orig,aux,dest, orig->quant);
    }
    if(verificaTipoHanoiTriplo(dest,aux,orig)==1){
        resolucaoHanoi(orig,dest,aux, orig->quant);
    }
    if(verificaTipoHanoiTriplo(dest,orig,aux)==1){
        resolucaoHanoi(aux,dest,orig, aux->quant);
    }
}

void cerebro(Pilha *orig, Pilha *aux, Pilha *dest, int total){
    while(dest->quant!=total){
        if(hanoiSimples(orig, aux, dest)!='X'){
            resolveHanoiSimples(orig, aux, dest);
        }
        else{
            if(verificaTipo(orig,aux,dest)==2){
                resolveHanoiDuplo(orig, aux, dest);
            }
            if(verificaTipo(orig,aux,dest)==3){
                resolveHanoiTriplo(orig, aux, dest);
            }
        }
        

    }
}