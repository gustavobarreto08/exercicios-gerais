#include "rolagem.h"
#include <stdio.h>

void LeMensagem(char mensagem[NUM_MAX_MSGS][TAM_MAX_MSG], int* numMsg){
    for(int i = 0; i<*numMsg; i++){
        scanf("%[^\n]",mensagem[i]);
        scanf("\n");
    }
}

int main(){
    int qtdrolagens;
    scanf("%d",&qtdrolagens);
    RolaMsg(&LeMensagem,30,qtdrolagens);
    return 0;
}