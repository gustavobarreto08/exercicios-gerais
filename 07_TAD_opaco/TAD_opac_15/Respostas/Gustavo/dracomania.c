#include "dracomania.h"
#include "duelo.h"
#include <stdio.h>
#include <stdlib.h>

struct Dracomania{
    char opcao;
    int qtdCartas;
    int qtdDuelos;
    int qtdCartasDescartadas;
    int qtdDesempates;
    int identificadorLutaMaiorDiferenca;
    int qtdreallocsCarta;
    int qtdreallocsDuelo;
    tCarta **cartas;
    tDuelo **duelos;
    tCarta *cartaMaisVitoriosa;
};

/**
 * @brief Cria uma nova instância do jogo Dracomania.
 * @return Retorna um ponteiro para a estrutura criada.
 */
tDracomania *CriaDracomania(){
    tDracomania *draco = malloc(sizeof(struct Dracomania));
    if(draco==NULL){
        exit(1);
    }
    draco->opcao = '\0';
    draco->qtdCartas = 0;
    draco->qtdCartasDescartadas = 0;
    draco->qtdDuelos = 0;
    draco->qtdDesempates = 0;
    draco->identificadorLutaMaiorDiferenca = 0;
    draco->qtdreallocsCarta = 1;
    draco->qtdreallocsDuelo = 1;
    draco->cartaMaisVitoriosa = NULL;
    draco->cartas = malloc(10*sizeof(tCarta*));
    if(draco->cartas==NULL){
        exit(1);
    }
    draco->duelos = malloc(10*sizeof(tDuelo*));
    if(draco->duelos==NULL){
        exit(1);
    }
    return draco;
}

/**
 * @brief Roda o jogo Dracomania.
 * @param d Ponteiro para a instância do jogo.
 * @return Retorna um ponteiro para a instância do jogo atualizada.
 */
void RodaDracomania(tDracomania *d){
    while(1){
        scanf(" %c", &d->opcao);
        switch(d->opcao){
            case CADASTRAR:
                tCarta *cartaaux;
                if(d->qtdCartas == (d->qtdreallocsCarta*10)-1){
                    d->qtdreallocsCarta++;
                    d->cartas = realloc(d->cartas, d->qtdreallocsCarta*10*sizeof(tCarta*));
                    if(d->cartas==NULL){
                        printf("ERRO ALOC\n");
                        exit(1);
                    }
                }
                cartaaux = LeCarta();
                if(EhCartaValida(cartaaux)){
                    int cadastrou = 0;
                    for(int i = 0; i<d->qtdCartas; i++){
                        if(EhMesmoIdCarta(cartaaux,d->cartas[i])){
                            d->cartas[i] = cartaaux;
                            cadastrou = 1;
                        }
                    }
                    if(!cadastrou){
                        d->cartas[d->qtdCartas] = cartaaux;
                        d->qtdCartas++;
                    }
                }else{
                    d->qtdCartasDescartadas++;
                }
            break;
            
            case LUTAR:
                if(d->qtdDuelos == (d->qtdreallocsDuelo*10)-1){
                    d->qtdreallocsDuelo++;
                    d->duelos = realloc(d->cartas, d->qtdreallocsDuelo*10*sizeof(tCarta*));
                    if(d->duelos==NULL){
                        printf("ERRO ALOC\n");
                        exit(1);
                    }
                }
                d->duelos[d->qtdDuelos] = LeDuelo();
                d->qtdDuelos++;
            break;

            case FINALIZAR:
                break;
            break;

            default:
                printf("ERRADO");
            break;
        }
    }
    for(int i = 0; i< d->qtdDuelos; i++){
        int idC1 = ObtemC1Duelo(d->duelos[i]);
        int idC2 = ObtemC2Duelo(d->duelos[i]);
        RealizaDuelo(d->duelos[i],d->cartas[idC1],d->cartas[idC2]);
        if(i==0){
            d->identificadorLutaMaiorDiferenca = i;
        }
        if(ObtemDesempateDuelo(d->duelos[i])){
                d->qtdDesempates++;
        }
        if(ObtemDiferencaDuelo(d->duelos[i])>ObtemDiferencaDuelo(d->duelos[d->identificadorLutaMaiorDiferenca])){
            d->identificadorLutaMaiorDiferenca = i;
        }
    }
    for(int i = 0; i<d->qtdCartas-1; i++){
        if(ObtemNumVitCarta(d->cartas[i])>ObtemNumVitCarta(d->cartas[i+1])){
            d->cartaMaisVitoriosa = d->cartas[i];
        }else if(ObtemNumVitCarta(d->cartas[i])==ObtemNumVitCarta(d->cartas[i+1])){
            d->cartaMaisVitoriosa = d->cartas[i];
            printf("EMPATE?");
        }
        else{
            d->cartaMaisVitoriosa = d->cartas[i+1];
        }
    }
}

/**
 * @brief Imprime o relatório final do jogo Dracomania.
 * @param d Ponteiro para a instância do jogo.
 */
void ImprimeRelatorioDracomania(tDracomania *d){
    printf("Quantidade de Cartas: %d\n", d->qtdCartas);
    printf("Quantidade de descartadas: %d\n", d->qtdCartasDescartadas);
    printf("Quantidade de lutas: %d\n", d->qtdDuelos);
    printf("Lutas que foram desempatadas: %d\n", d->qtdDesempates);
    printf("Carta mais vitoriosa: %s\n", ObtemNomeCarta(d->cartaMaisVitoriosa));
    printf("Luta com Maior Diferenca: %d\n", d->identificadorLutaMaiorDiferenca);
}

/**
 * @brief Libera a memória alocada para a instância do jogo Dracomania.
 * @param d Ponteiro para a instância do jogo.
 */
void LiberaDracomania(tDracomania *d){
    for(int i = 0; i<d->qtdCartas; i++){
        LiberaCarta(d->cartas[i]);
    }
    free(d->cartas);
    for(int i = 0; i<d->qtdDuelos; i++){
        LiberaDuelo(d->duelos[i]);
    }
    free(d->duelos);
    free(d);
}