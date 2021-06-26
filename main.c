//####  TRABALHO 1 ESTRUTURA DE DADOS #################

//### INCLUDES ###############
#include <locale.h>
//#include "fila.h"
//#include "Fila.c"
#include "hanoi.c"

//######    FUNÇÕES ###########

//########  MAIN ###############

int main(){
    setlocale(LC_ALL, "Portuguese");//Permite usar os acentos da língua portuguesa
    printf("Digite as entradas de dados:\n");
    int i=pegaTotalDiscos();
    int total=i;
    Pilha *pinoA = inicializaPilha('A');
    Pilha *pinoB=inicializaPilha('B');
    Pilha *pinoC=inicializaPilha('C');
    i=inserirDisco(pinoA,i, 'A');
    i=inserirDisco(pinoB,i, 'B');
    i=inserirDisco(pinoC,i, 'C');
    apresentaEntrada(pinoA,pinoB,pinoC);
    cerebro(pinoA,pinoB,pinoC, total);
    apresentaEntrada(pinoA,pinoB,pinoC);
    //excluiPilha(pinoA);
    //excluiPilha(pinoB);
    //excluiPilha(pinoC);
}