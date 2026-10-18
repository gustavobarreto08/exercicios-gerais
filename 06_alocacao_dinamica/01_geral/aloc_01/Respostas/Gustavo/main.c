#include "utils.h"
#include <stdio.h>

int main(){
    int tamanho;
    float media;
    int *vetor;
    scanf("%d",&tamanho);
    vetor = CriaVetor(tamanho);
    LeVetor(vetor,tamanho);
    media = CalculaMedia(vetor,tamanho);
    LiberaVetor(vetor);
    printf("%.2f",media);
}