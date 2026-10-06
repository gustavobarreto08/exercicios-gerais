#include "pessoa.h"
#include <stdio.h>

int main(){
    int qtdpessoas,qtdassociacoes;
    scanf("%d",&qtdpessoas);
    tPessoa pessoas[qtdpessoas];
    for(int i = 0; i<qtdpessoas; i++){
        pessoas[i] = CriaPessoa();
        LePessoa(&pessoas[i]);
    }
    AssociaFamiliasGruposPessoas(pessoas);
    for(int i = 0; i<qtdpessoas; i++){
        ImprimePessoa(&pessoas[i]);
    }
    return 0;
}