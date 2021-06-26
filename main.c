//####  TRABALHO 1 ESTRUTURA DE DADOS #################

//### INCLUDES ###############
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#include "pilha.h"
#include "fila.h"
#include "Pilha.c"
#include "Fila.c"

//######    FUNÇÕES ###########

//########  MAIN ###############

int main(){
    setlocale(LC_ALL, "Portuguese");//Permite usar os acentos da língua portuguesa
    printf("Digite as entradas de dados:\n");
    int i=pegaTotalDiscos();
    int total=i;
    Fila *movimentos = inicializaFila();
    Pilha *pinoA = inicializaPilha('A');
    Pilha *pinoB=inicializaPilha('B');
    Pilha *pinoC=inicializaPilha('C');
    i=inserirDisco(pinoA,i, 'A');
    i=inserirDisco(pinoB,i, 'B');
    i=inserirDisco(pinoC,i, 'C');
    apresentaEntrada(pinoA,pinoB,pinoC);
    cerebro(pinoA,pinoB,pinoC, total, movimentos);
    apresentaEntrada(pinoA,pinoB,pinoC);
    imprimeFila(movimentos);
    //excluiPilha(pinoA);
    //excluiPilha(pinoB);
    //excluiPilha(pinoC);
}