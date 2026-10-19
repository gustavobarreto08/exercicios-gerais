#include "utils_char.h"
#include <stdio.h>

int main(){
    char *vetor;
    int tamanho;
    scanf("%d",&tamanho);
    scanf("\n");
    vetor = CriaVetor(tamanho);
    ImprimeString(vetor,tamanho);
    LeVetor(vetor,tamanho);
    ImprimeString(vetor,tamanho);
    LiberaVetor(vetor);
    return 0;
}