//####  TRABALHO 1 ESTRUTURA DE DADOS #################

//### INCLUDES ###############
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#include "pilha.h"
//#include "fila.h"
#include "Pilha.c"
//#include "Fila.c"

//######    FUNÇÕES ###########

//########  MAIN ###############

int main(){
    setlocale(LC_ALL, "Portuguese");//Permite usar os acentos da língua portuguesa
    printf("Digite as entradas de dados:\n");
    int i=pegaTotalDiscos();
    int total=i;
    Pilha *pinoA = inicializaPilha();
    Pilha *pinoB=inicializaPilha();
    Pilha *pinoC=inicializaPilha();
    i=inserirDisco(pinoA,i, 'A');
    i=inserirDisco(pinoB,i, 'B');
    i=inserirDisco(pinoC,i, 'C');
    apresentaEntrada(pinoA,pinoB,pinoC, total);
    //apresentaPilha(pinoA);
    //resolucaoHanoi(pinoA,pinoB,pinoC,i,total);
    excluiPilha(pinoA);
    excluiPilha(pinoB);
    excluiPilha(pinoC);
}