#include "rolagem.h"
#include <stdio.h>

void LeMensagem(char mensagem[NUM_MAX_MSGS][TAM_MAX_MSG], int numMsg){
    for(int i = 1; i<=numMsg; i++){
        scanf("%[^\n]",mensagem[i]);
        scanf("\n");
    }
}

int main(){
    char mensagens[NUM_MAX_MSGS][TAM_MAX_MSG];
    char mensagemprintada[31];
    int qtdrolagens, nummensagens;
    scanf("%d",&qtdrolagens);
    scanf("%d",&nummensagens);
    RolaMsg(&LeMensagem,30,qtdrolagens);
    return 0;
}
