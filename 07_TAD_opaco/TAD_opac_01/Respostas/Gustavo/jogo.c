#include "jogo.h"
#include <stdio.h>
#include <stdlib.h>

struct Jogo{
    tTabuleiro *tabuleiro;
    tJogador **jogador;
};


/**
 * Aloca e retorna uma estrutura do tipo tJogo.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tJogo alocada.
 */
tJogo* CriaJogo(){
    tJogo *j = malloc(sizeof(struct Jogo));
    j->tabuleiro = CriaTabuleiro();
    j->jogador = malloc(2*sizeof(tJogador*));
    for(int i = 0; i < 2; i++){
        j->jogador[i] = CriaJogador(i+1);
    }
    return j;
}


/**
 * Executa o jogo, alternando as jogadas entre os jogadores até que haja um vencedor ou o jogo termine sem vencedor.
 * 
 * @param jogo o jogo a ser iniciado.
 */
void ExecutaJogo(tJogo* jogo){
    int qualJogador = 0;
    while(1){
        qualJogador = 0;
        JogaJogador(jogo->jogador[qualJogador], jogo->tabuleiro);
        ImprimeTabuleiro(jogo->tabuleiro);
        if(VenceuJogador(jogo->jogador[qualJogador], jogo->tabuleiro)){
            printf("JOGADOR %d Venceu!\n", qualJogador+1);
            break;
        }
        if(AcabouJogo(jogo)){
            printf("Sem vencedor!\n");
            break;
        }
        qualJogador = 1;
        JogaJogador(jogo->jogador[qualJogador], jogo->tabuleiro);
        ImprimeTabuleiro(jogo->tabuleiro);
        if(VenceuJogador(jogo->jogador[qualJogador], jogo->tabuleiro)){
            printf("JOGADOR %d Venceu!\n", qualJogador+1);
            break;
        }
        if(AcabouJogo(jogo)){
            printf("Sem vencedor!\n");
            break;
        }
    }
}


/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 * 
 * @param jogo o jogo atual.
 * 
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo* jogo){
    if(!TemPosicaoLivreTabuleiro(jogo->tabuleiro)){
        return 1;
    }
    return 0;
}


/**
 * Verifica se o usuário deseja jogar novamente.
 * 
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo(){
    char opcao;
    printf("Jogar novamente? (s,n)\n");
    scanf(" %c", &opcao);
    if(opcao == 's'){
        return 1;
    }else if(opcao == 'n'){
        return 0;
    }
}


/**
 * Libera a memória de uma estrutura do tipo tJogo.
 * 
 * @param jogo a estrutura do tipo tJogo a ser liberada.
 */
void DestroiJogo(tJogo* jogo){
    for(int i = 0; i < 2; i++){
        DestroiJogador(jogo->jogador[i]);
    }
    free(jogo->jogador);
    DestroiTabuleiro(jogo->tabuleiro);
    free(jogo);
}