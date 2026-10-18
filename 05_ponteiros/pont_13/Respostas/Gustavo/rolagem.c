#include "rolagem.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Ponteiro para função que recebe um array de mensagens e o número de mensagens para rolagem.
 * 
 * @param msg Array de mensagens.
 * @param numMsgs Número de mensagens.
 */
typedef void (*FptrMsg)(char msg[NUM_MAX_MSGS][TAM_MAX_MSG], int * numMsgs);

/**
 * @brief Dispara a função de rolagem de mensagens.
 * 
 * @param FuncMsg Ponteiro para a função que recebe um array de mensagens e o número de mensagens.
 * @param tamanhoDisplay Tamanho do display.
 * @param tempoFim Tempo de duração da rolagem, que diz respeito a quantidade de deslocamento no painel.
 */
void RolaMsg(FptrMsg FuncMsg, int tamanhoDisplay, int tempoFim){
    char mensagem[NUM_MAX_MSGS][TAM_MAX_MSG];
    int numMsg, flag = 0;
    int *pontnumMsg = NULL;
    pontnumMsg = &numMsg;
    scanf("%d",pontnumMsg);
    scanf("\n");
    FuncMsg(mensagem,pontnumMsg);
    for(int i = 0; i<tempoFim; i++){
        for(int j = 0; j<tamanhoDisplay;){
            for(int q = 0; q<*pontnumMsg; q++){
                for(int k = 0; k<strlen(mensagem[q]); k++){
                    printf("%c",mensagem[q][k]);
                    j++;
                    if(j>=tamanhoDisplay){
                        flag = 1;
                        break;
                    }
                }
                if(flag){
                    break;
                }
            }
        }
        printf("\n");
        printf("\033[H\033[J");
    }
}