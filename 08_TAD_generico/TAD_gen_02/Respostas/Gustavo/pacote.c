#include "pacote.h"
#include <stdlib.h>
#include <stdio.h>

struct pacote{
    int tipo;
    void *vetor;
    int numElem;
    int somaVerifi;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote* CriaPacote(Type type, int numElem){
    tPacote *pac = malloc(sizeof(struct pacote));
    pac->tipo = type;
    pac->numElem = numElem;
    pac->somaVerifi = 0;
    pac->vetor = NULL;
    return pac;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote* pac){
    free(pac->vetor);
    free(pac);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote* pac){
    if(pac->tipo == 0){
        pac->vetor = malloc(pac->numElem*sizeof(char));
        for(int i = 0; i < pac->numElem; i++){
            scanf(" %c", &((char*)pac->vetor)[i]);
        }
    }
    else{
        pac->vetor = calloc(pac->numElem, sizeof(int));
        for(int i = 0; i < pac->numElem; i++){
            scanf("%d", &((int*)pac->vetor)[i]);
        }
    }
}

/**
 * @brief Imprime na tela um pacote que possui um id específico com seu valor calculado
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote* pac){
    printf("%d ", pac->somaVerifi);
    if(pac->tipo == 0){
        for(int i = 0; i < pac->numElem; i++){
            printf("%c", ((char*)pac->vetor)[i]);
        }
    }
    else{
        for(int i = 0; i < pac->numElem; i++){
            printf("%d", ((int*)pac->vetor)[i]);
        }
    }
    printf("\n");
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote* pac){
    if(pac->tipo==0){
        for(int i = 0; i < pac->numElem; i++){
            pac->somaVerifi += ((char*)pac->vetor)[i];
        }
    }
    else{
        for(int i = 0; i < pac->numElem; i++){
            pac->somaVerifi += ((int*)pac->vetor)[i];
        }
    }
}