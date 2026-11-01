#include "duelo.h"
#include "carta.h"
#include <stdio.h>
#include <stdlib.h>

struct Duelo{
    char opcaoLuta;
    int identificadorC1;
    int identificadorC2;
    int identificadorLuta;
    int desempate;
    int diferenca;
};

/**
 * @brief Lê um duelo do usuário.
 * @return Retorna um ponteiro para o duelo lido.
 */
tDuelo *LeDuelo(){
    tDuelo *d;
    d = malloc (sizeof(struct Duelo));
    scanf("%d", &(d->identificadorLuta));
    scanf("%d", &d->identificadorC1);
    scanf("%d", &d->identificadorC2);
    scanf(" %c", &d->opcaoLuta);
    d->desempate = 0;
    d->diferenca = 0;
    return d;
}

/**
 * @brief Libera a memória alocada para um duelo.
 * @param d Ponteiro para o duelo a ser liberado.
 */
void LiberaDuelo(tDuelo *d){
    free(d);
}

/**
 * @brief Realiza um duelo entre duas cartas.
 * @param d Ponteiro para o duelo.
 * @param c1 Ponteiro para a primeira carta.
 * @param c2 Ponteiro para a segunda carta.
 */
void RealizaDuelo(tDuelo *d, tCarta *c1, tCarta *c2){
    d->identificadorC1 = ObtemIdCarta(c1);
    d->identificadorC2 = ObtemIdCarta(c2);
    switch(d->opcaoLuta){
        case 'F':
            int ataquec1, ataquec2;
            ataquec1 = ObtemForcaCarta(c1);
            ataquec2 = ObtemForcaCarta(c2);
            if(ataquec1>ataquec2){
                d->diferenca = ataquec1 - ataquec2;
                AdicionaVitoriaCarta(c1);
            }else if(ataquec1==ataquec2){
                d->desempate = 1;
                if(d->identificadorC1<d->identificadorC2){
                    AdicionaVitoriaCarta(c1);
                }else if(d->identificadorC1>d->identificadorC2){
                    AdicionaVitoriaCarta(c2);
                }
                else{
                    printf("ID IGUAIS");
                    exit(1);
                }
            }else{
                d->diferenca = ataquec2 - ataquec1;
                AdicionaVitoriaCarta(c2);
            }
        break;
        case 'G':
            int fogoc1, fogoc2;
            fogoc1 = ObtemFogoCarta(c1);
            fogoc2 = ObtemFogoCarta(c2);
            if(fogoc1>fogoc2){
                d->diferenca = fogoc1 - fogoc2;
                AdicionaVitoriaCarta(c1);
            }else if(fogoc1==fogoc2){
                d->desempate = 1;
                if(d->identificadorC1<d->identificadorC2){
                    AdicionaVitoriaCarta(c1);
                }else if(d->identificadorC1>d->identificadorC2){
                    AdicionaVitoriaCarta(c2);
                }
                else{
                    printf("ID IGUAIS");
                    exit(1);
                }
            }else{
                d->diferenca = fogoc2 - fogoc1;
                AdicionaVitoriaCarta(c2);
            }
        break;
        case 'M':
            int magiac1, magiac2;
            magiac1 = ObtemMagiaCarta(c1);
            magiac2 = ObtemMagiaCarta(c2);
            if(magiac1>magiac2){
                d->diferenca =magiac1 - magiac2;
                AdicionaVitoriaCarta(c1);
            }else if(magiac1==magiac2){
                d->desempate = 1;
                if(d->identificadorC1<d->identificadorC2){
                    AdicionaVitoriaCarta(c1);
                }else if(d->identificadorC1>d->identificadorC2){
                    AdicionaVitoriaCarta(c2);
                }
                else{
                    printf("ID IGUAIS");
                    exit(1);
                }
            }else{
                d->diferenca =magiac2 - magiac1;
                AdicionaVitoriaCarta(c2);
            }
        break;
    }
}

/**
 * @brief Retorna o ID da primeira carta do duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna o ID da primeira carta do duelo.
 */
int ObtemC1Duelo(tDuelo *d){
    return d->identificadorC1;
}

/**
 * @brief Retorna o ID da segunda carta do duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna o ID da segunda carta do duelo.
 */
int ObtemC2Duelo(tDuelo *d){
    return d->identificadorC2;
}

/**
 * @brief Retorna se houve desempate no duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna true se houve desempate e false caso contrário.
 */
bool ObtemDesempateDuelo(tDuelo *d){
    if(d->desempate){
        return true;
    }
    return false;
}

/**
 * @brief Retorna a diferença de pontos entre as cartas no duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna a diferença de pontos entre as cartas no duelo.
 */
int ObtemDiferencaDuelo(tDuelo *d){
    return d->diferenca;
}

/**
 * @brief Retorna o ID do duelo.
 * @param d Ponteiro para o duelo.
 * @return Retorna o ID do duelo.
 */
int ObtemIdDuelo(tDuelo *d){
    return d->identificadorLuta;
}