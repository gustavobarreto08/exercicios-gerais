#include "rolagem.h"

void PrintaTudo(char mensagemprintada){
    printf("%s",mensagemprintada);
    printf("\n");
    printf("\033[H\033[J");
}

int main(){
    char mensagens[NUM_MAX_MSGS][TAM_MAX_MSG];
    char mensagemprintada[30];
    int qtdrolagens, nummensagens;
    scanf("%d",&qtdrolagens);
    scanf("%d",&nummensagens);
    scanf("\n");
    for(int i = 1; i<=nummensagens; i++){
        scanf("%[^\n]",mensagens[i]);
        scanf("\n");
    }
    for(int i = 0; i<qtdrolagens; i++){
        
    }
    return 0;
}
