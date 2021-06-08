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
    int i=pegaTotalDiscos();
    Pilha *pinoA = inicializaPilha();
    Pilha *pinoB=inicializaPilha();
    Pilha *pinoC=inicializaPilha();
    i=inserirDisco(pinoA,i);
    i=inserirDisco(pinoB,i);
    i=inserirDisco(pinoC,i);
}