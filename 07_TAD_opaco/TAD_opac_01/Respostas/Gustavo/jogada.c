#include "jogada.h"
#include <stdio.h>
#include <stdlib.h>

struct Jogada{
    int x;
    int y;
};


/**
 * Aloca e retorna uma estrutura do tipo tJogada.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tJogada alocada.
 */
tJogada* CriaJogada(){
    tJogada *j = malloc(sizeof(struct Jogada));
    if(j == NULL){
        perror("ERRO ALOC\n");
    }
    j->x = -1001;
    j->y = -1001;
    return j;
}


/**
 * Libera a memória de uma estrutura do tipo tJogada.
 * 
 * @param jogada a estrutura do tipo tJogada a ser liberada.
 */
void DestroiJogada(tJogada* jogada){
    free(jogada);
}


/**
 * Solicita ao usuário as coordenadas de uma jogada,
 * realiza a leitura e armazena os valores em uma estrutura do tipo tJogada.
 * 
 * @param jogada a estrutura do tipo tJogada a ser preenchida.
 */
void LeJogada(tJogada* jogada){
    printf("Digite uma posicao (x e y):\n");
    scanf("%d", &jogada->x);
    scanf("%d", &jogada->y);
}


/**
 * Retorna a coordenada X da jogada.
 * 
 * @param jogada a estrutura do tipo tJogada.
 * 
 * @return a coordenada X da jogada.
 */
int ObtemJogadaX(tJogada* jogada){
    return jogada->x;
}


/**
 * Retorna a coordenada Y da jogada.
 * 
 * @param jogada a estrutura do tipo tJogada.
 * 
 * @return a coordenada Y da jogada.
 */
int ObtemJogadaY(tJogada* jogada){
    return jogada->y;
}


/**
 * Retorna 1 se a jogada foi bem sucedida e 0 caso contrário.
 * 
 * @param jogada a estrutura do tipo tJogada.
 * 
 * @return 1 se a jogada foi bem sucedida, 0 caso contrário.
 */
int FoiJogadaBemSucedida(tJogada* jogada){
    if(jogada->x == -1001 || jogada->y == -1001){
        return 0;
    }
    return 1;
}