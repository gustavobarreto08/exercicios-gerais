#include "vetor.h"
#include <stdio.h>

int soma(int a, int b){
    return a+b;
}

int mult(int a, int b){
    return a*b;
}

int main(){
    Vetor vet[10];
    LeVetor(vet);
    printf("Soma: %d\n",AplicarOperacaoVetor(vet,soma));
    printf("Produto: %d\n",AplicarOperacaoVetor(vet,mult));
    return 0;
}