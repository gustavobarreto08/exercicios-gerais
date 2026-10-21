#include "utils_char2.h"
#include <stdio.h>

int main(){
    char *vetor;
    int *tamanho = NULL;
    int tam = TAM_PADRAO;
    tamanho = &tam;
    vetor = CriaVetorTamPadrao();
    vetor = LeVetor(vetor,tamanho);
    ImprimeString(vetor);
    LiberaVetor(vetor);
    return 0;
}