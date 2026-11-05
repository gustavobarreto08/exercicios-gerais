#include "tabuleiro.h"
#include <stdlib.h>
#include <stdio.h>

struct Tabuleiro{
    char **mapa;
};


/**
 * Aloca e retorna uma estrutura do tipo tTabuleiro.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tTabuleiro alocada.
 */
tTabuleiro* CriaTabuleiro(){
    tTabuleiro *t = malloc(sizeof(struct Tabuleiro));
    if(t == NULL){
        perror("ERRO ALOC\n");
    }
    t->mapa = malloc(TAM_TABULEIRO * sizeof(char*));
    for(int i = 0; i < TAM_TABULEIRO; i++){
        t->mapa[i] = malloc(TAM_TABULEIRO * sizeof(char));
    }
    for(int i = 0; i < TAM_TABULEIRO; i++){
        for(int q = 0; q < TAM_TABULEIRO; q++){
            t->mapa[i][q] = '-';
        }
    }
    return t;
}


/**
 * Libera a memória de uma estrutura do tipo tTabuleiro.
 * 
 * @param tabuleiro a estrutura do tipo tTabuleiro a ser liberada.
 */
void DestroiTabuleiro(tTabuleiro* tabuleiro){
    for(int i = 0; i < TAM_TABULEIRO; i++){
        free(tabuleiro->mapa[i]);
    }
    free(tabuleiro->mapa);
    free(tabuleiro);
}


/**
 * Marca uma posição do tabuleiro com a peça do jogador.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param peca a peça do jogador (1 ou 2).
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 */
void MarcaPosicaoTabuleiro(tTabuleiro* tabuleiro, int peca, int x, int y){
    if(peca == 1){
        tabuleiro->mapa[y][x] = 'X';
    }
    else if(peca == 2){
        tabuleiro->mapa[y][x] = '0';
    }
}


/**
 * Verifica se há alguma posição livre no tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se há alguma posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro* tabuleiro){
    for(int i = 0; i < TAM_TABULEIRO; i++){
        for(int q = 0; q < TAM_TABULEIRO; q++){
            if(tabuleiro->mapa[i][q] == '-'){
                return 1;
            }
        }
    }
    return 0;
}


/**
 * Verifica se a posição do tabuleiro está marcada com a peça do jogador.
 * 
 * @param tabuleiro - o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * @param peca a peça do jogador (1 ou 2).
 * 
 * @return 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro* tabuleiro, int x, int y, int peca){
    char marca;
    if(peca==1){
        marca = 'X';
    }
    else if(peca==2){
        marca = '0';
    }
    if(tabuleiro->mapa[y][x] == marca){
        return 1;
    }else{
        return 0;
    }
}


/**
 * Verifica se a posição do tabuleiro está livre.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * 
 * @return 1 se a posição está livre, 0 caso contrário.
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro* tabuleiro, int x, int y){
    if(tabuleiro->mapa[y][x] == '-'){
        return 1;
    }
    return 0;
}


/**
 * Verifica se a posição do tabuleiro é válida.
 * 
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * 
 * @return 1 se a posição é válida, 0 caso contrário.
 */
int EhPosicaoValidaTabuleiro(int x, int y){
    if(x == 0 || x == 1 || x == 2){
        if(y == 0 || y == 1 || y == 2){
            return 1;
        }
    }
    return 0;
}


/**
 * Imprime o tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro* tabuleiro){
    for(int i = 0; i < TAM_TABULEIRO; i++){
        printf("\t%c%c%c\n", tabuleiro->mapa[i][0], tabuleiro->mapa[i][1], tabuleiro->mapa[i][2]);
    }
}
