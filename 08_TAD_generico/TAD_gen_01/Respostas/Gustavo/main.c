#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

int main(){
    printf("tad_gen_01\n");
    tGeneric *gen;
    int numEle, tipo;
    printf("Digite o tipo e numero de elementos:");
    scanf("%d %d", &tipo, &numEle);
    gen = CriaGenerico(tipo, numEle);
    LeGenerico(gen);
    ImprimeGenerico(gen);
    DestroiGenerico(gen);
    return 0;
}