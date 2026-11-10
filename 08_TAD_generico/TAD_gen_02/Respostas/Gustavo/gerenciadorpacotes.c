#include "gerenciadorpacotes.h"
#include <stdio.h>
#include <stdlib.h>

struct gerenciadorpacotes{
    tPacote **pacotes;
    int qtdPacotes;
};

/**
 * @brief Cria uma TAD que gerencia pacotes. O pacote é um TAD genérico.
 *
 *
 * @return O gerenciador de pacotes
 */
tGerenciador* CriaGerenciador(){
    tGerenciador *geren = malloc(sizeof(struct gerenciadorpacotes));
    if(geren == NULL){
        exit(1);
    }
    geren->pacotes = NULL;
    geren->qtdPacotes = 0;
    return geren;
}

/**
 * @brief Adiciona um pacote ao gerenciador de pacotes.
 *
 * @param geren O gerenciador de pacotes que armazenará o pacote 
 * @param pac O pacote que queremos adicionar no gerenciador.
 *
 */
void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac){
    geren->qtdPacotes++;
    geren->pacotes = realloc(geren->pacotes, geren->qtdPacotes*sizeof(*(geren->pacotes)));
    geren->pacotes[geren->qtdPacotes-1] = pac;
    pac = NULL;
}


/**
 * @brief Destrói um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que será destruído (memória liberada)
 *
 */
void DestroiGerenciador(tGerenciador* geren){
    for(int i = 0; i < geren->qtdPacotes; i++){
        DestroiPacote(geren->pacotes[i]);
    }
    free(geren->pacotes);
    free(geren);
}

/**
 * @brief Imprime um pacote específico do gerenciador de pacotes.
 *
 * @param geren - O gerenciador de pacotes que terá um pacote impresso
 * @param idx - O índice do pacote a ser impresso (começa em zero!)
 *
 */
void ImprimirPacoteNoIndice(tGerenciador* geren, int idx){
    ImprimePacote(geren->pacotes[idx]);
}


/**
 * @brief Imprime todos os pacotes de um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que terá seus pacotes impressos
 *
 */
void ImprimirTodosPacotes(tGerenciador* geren){
    for(int i = 0; i < geren->qtdPacotes; i++){
        ImprimirPacoteNoIndice(geren,i);
    }
}
