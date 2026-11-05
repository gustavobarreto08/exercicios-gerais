#include "jogador.h"
#include <stdio.h>
#include <stdlib.h>

struct Jogador{
    int idJogador;
    tJogada *jogada;
};

/**
 * Aloca e retorna uma estrutura do tipo tJogador.
 * Se a alocação falhar, o programa é encerrado.
 *
 *  @param idJogador o ID do jogador (1 ou 2).
 * 
 * @return a estrutura do tipo tJogador alocada.
 */
tJogador* CriaJogador(int idJogador){
    tJogador *j = malloc(sizeof(struct Jogador));
    if(j == NULL){
        perror("ERRO ALOC\n");
    }
    j->idJogador = idJogador;
    return j;
}

/**
 * Libera a memória de uma estrutura do tipo tJogador.
 * 
 * @param jogador a estrutura do tipo tJogador a ser liberada.
 */
void DestroiJogador(tJogador* jogador){
    free(jogador);
}

/**
 * Verifica se a jogada foi lida corretamente, se a posição informada
 * é válida e se está livre no tabuleiro.
 *
 * @param jogada a jogada a ser verificada.
 * @param tabuleiro o tabuleiro atual.
 *
 * @return 1 se a jogada for válida, 0 caso contrário.
 */
int EhJogadaValida(tJogada* jogada, tTabuleiro* tabuleiro){
    if(FoiJogadaBemSucedida(jogada)){
        int x,y;
        x = ObtemJogadaX(jogada);
        y = ObtemJogadaY(jogada);
        if(EhPosicaoValidaTabuleiro(x,y)){
            if(EstaLivrePosicaoTabuleiro(tabuleiro,x,y)){
                return 1;
            }
            else{
                printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
            }
        }
        else{
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
        }
    }
    return 0;
}

/**
 * Solicita e realiza uma jogada do jogador, repetindo a leitura
 * até que seja informada uma posição válida e livre no tabuleiro.
 * 
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 */
void JogaJogador(tJogador* jogador, tTabuleiro* tabuleiro){
    jogador->jogada = CriaJogada();
    printf("Jogador %d\n", jogador->idJogador);
    LeJogada(jogador->jogada);
    while(!EhJogadaValida(jogador->jogada,tabuleiro)){
        printf("Jogador %d\n", jogador->idJogador);
        LeJogada(jogador->jogada);
    }
    printf("Jogada [%d,%d]!\n", ObtemJogadaX(jogador->jogada), ObtemJogadaY(jogador->jogada));
    MarcaPosicaoTabuleiro(tabuleiro,jogador->idJogador,ObtemJogadaX(jogador->jogada), ObtemJogadaY(jogador->jogada));
    DestroiJogada(jogador->jogada);
}

/**
 * Verifica se o jogador venceu o jogo.
 * 
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador* jogador, tTabuleiro* tabuleiro){
    for(int i = 0; i <= 2; i++){
        int controle = 0;
        for(int q = 0; q <= 2; q++){
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,q,i,jogador->idJogador)){
                controle++;
            }
        }
        if(controle == 3){
            return 1;
        }
    }
    for(int i = 0; i <= 2; i++){
        int controle = 0;
        for(int q = 0; q <= 2; q++){
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,i,q,jogador->idJogador)){
                controle++;
            }
        }
        if(controle == 3){
            return 1;
        }
    }
    int controle = 0;
    for(int x = 0, y = 0; x<=2 && y<=2; x++, y++){
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,x,y,jogador->idJogador)){
            controle++;
        }
    }
    if(controle == 3){
        return 1;
    }
    controle = 0;
    for(int x = 2, y = 0; x>=0 && y<=2; x--, y++){
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro,x,y,jogador->idJogador)){
            controle++;
        }
    }
    if(controle == 3){
        return 1;
    }
    return 0;
}