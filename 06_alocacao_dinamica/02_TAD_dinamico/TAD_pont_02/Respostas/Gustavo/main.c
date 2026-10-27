#include "eleicao.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    tEleicao *eleicao;
    eleicao = InicializaEleicao();
    RealizaEleicao(eleicao);
    ImprimeResultadoEleicao(eleicao);
    ApagaEleicao(eleicao);
    return 0;
}