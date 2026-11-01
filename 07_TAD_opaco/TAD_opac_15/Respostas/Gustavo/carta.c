#include "carta.h"
#include "duelo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Carta{
    int identificador;
    char *nome;
    int poderFogo;
    int poderForca;
    int poderMagia;
    int numVitorias;
};

/**
 * @brief Lê uma carta do usuário e retorna um ponteiro para ela.
 * @return Retorna um ponteiro para a carta lida.
 */
tCarta *LeCarta(){
    tCarta *c = malloc(sizeof(struct Carta));
    c->nome = malloc(100*sizeof(char));
    scanf("%d", &c->identificador);
    scanf(" %[^\n]", c->nome);
    scanf("%d %d %d", &c->poderMagia, &c->poderForca, &c->poderFogo);
    c->numVitorias = 0;
    return c;
}

/**
 * @brief Libera a memória alocada para uma carta.
 * @param c Ponteiro para a carta a ser liberada.
 */
void LiberaCarta(tCarta *c){
    free(c->nome);
    free(c);
}

/**
 * @brief Retorna o ID de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o ID da carta.
 */
int ObtemIdCarta(tCarta *c){
    return c->identificador;
}

/**
 * @brief Retorna o nome de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o nome da carta.
 */
char * ObtemNomeCarta(tCarta *c){
    return c->nome;
}

/**
 * @brief Retorna o número de vitórias de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o número de vitórias da carta.
 */
int ObtemNumVitCarta(tCarta *c){
    return c->numVitorias;
}

/**
 * @brief Retorna o valor de magia de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o valor de magia da carta.
 */
int ObtemMagiaCarta(tCarta *c){
    return c->poderMagia;
}

/**
 * @brief Retorna o valor de ataque de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o valor de ataque da carta.
 */
int ObtemForcaCarta(tCarta *c){
    return c->poderForca;
}

/**
 * @brief Retorna o valor de fogo de uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o valor de fogo da carta.
 */
int ObtemFogoCarta(tCarta *c){
    return c->poderFogo;
}

/**
 * @brief Verifica se uma carta é válida.
 * @param c Ponteiro para a carta.
 * @return Retorna true se a carta é válida e false caso contrário.
 */
bool EhCartaValida(tCarta *c){
    int tamanhoNome = strlen(c->nome);
    int somaPoder = 0;
    somaPoder = c->poderFogo + c->poderForca + c->poderMagia;
    if(somaPoder>80){
        return false;
    }
    if(tamanhoNome>50){
        return false;
    }
    if(c->poderFogo>30 || c->poderForca>30 || c->poderMagia>30){
        return false;
    }
    return true;
}

/**
 * @brief Verifica se duas cartas possuem o mesmo ID.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna true se as cartas possuem o mesmo ID e false caso contrário.
 */
bool EhMesmoIdCarta(tCarta *c1, tCarta *c2){
    if(c1->identificador == c2->identificador){
        return true;
    }
    return false;
}

/**
 * @brief Compara duas cartas pelo ID.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna um valor negativo se c1 < c2, zero se c1 == c2 e um valor positivo se c1 > c2.
 */
int ComparaIdCarta(tCarta *c1, tCarta *c2){
    if(c1->identificador < c2->identificador){
        return -1;
    }
    else if(c1->identificador == c2->identificador){
        return 0;
    }
    else{
        return 1;
    }
}

/**
 * @brief Compara duas cartas pelo valor de magia.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna um valor negativo se c1 < c2, zero se c1 == c2 e um valor positivo se c1 > c2.
 */
int ComparaMagiaCarta(tCarta *c1, tCarta *c2){
   if(c1->poderMagia < c2->poderMagia){
        return -1;
    }
    else if(c1->poderMagia == c2->poderMagia){
        return 0;
    }
    else{
        return 1;
    } 
}

/**
 * @brief Compara duas cartas pelo valor de ataque.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna um valor negativo se c1 < c2, zero se c1 == c2 e um valor positivo se c1 > c2.
 */
int ComparaForcaCarta(tCarta *c1, tCarta *c2){
    if(c1->poderForca < c2->poderForca){
        return -1;
    }
    else if(c1->poderForca == c2->poderForca){
        return 0;
    }
    else{
        return 1;
    }
}

/**
 * @brief Compara duas cartas pelo valor de fogo.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 * @return Retorna um valor negativo se c1 < c2, zero se c1 == c2 e um valor positivo se c1 > c2.
 */
int ComparaFogoCarta(tCarta *c1, tCarta *c2){
    if(c1->poderFogo < c2->poderFogo){
        return -1;
    }
    else if(c1->poderFogo == c2->poderFogo){
        return 0;
    }
    else{
        return 1;
    }
}

/**
 * @brief Adiciona uma vitória para uma carta.
 * @param c Ponteiro para a carta.
 * @return Retorna o novo número de vitórias da carta.
 */
int AdicionaVitoriaCarta(tCarta *c){
    c->numVitorias = c->numVitorias + 1;
    return c->numVitorias;
}