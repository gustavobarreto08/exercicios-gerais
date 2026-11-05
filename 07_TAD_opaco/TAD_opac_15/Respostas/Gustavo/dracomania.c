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
        perror("ERRO");
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
        perror("ERRO");
        exit(1);
    }
    draco->duelos = calloc(10,sizeof(tDuelo*));
    if(draco->duelos==NULL){
        perror("ERRO");
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
    int rodando = 1;
    while(rodando){
        scanf(" %c", &d->opcao);
        switch(d->opcao){
            case CADASTRAR:
                tCarta *cartaaux;
                tCarta **cartasaux;
                if(d->qtdCartas == (d->qtdreallocsCarta*10)-1){
                    d->qtdreallocsCarta++;
                    cartasaux = realloc(d->cartas, d->qtdreallocsCarta*10*sizeof(tCarta*));
                    if(cartasaux==NULL){
                        printf("ERRO ALOC\n");
                        exit(1);
                    }
                    d->cartas = cartasaux;
                    cartasaux = NULL;
                }
                cartaaux = LeCarta();
                if(EhCartaValida(cartaaux)){
                    int cadastrou = 0;
                    for(int i = 0; i<d->qtdCartas; i++){
                        if(EhMesmoIdCarta(cartaaux,d->cartas[i])){
                            LiberaCarta(d->cartas[i]);
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
                    LiberaCarta(cartaaux);
                }
            break;
            
            case LUTAR:
            tDuelo **duelosaux;
                if(d->qtdDuelos == (d->qtdreallocsDuelo*10)-1){
                    d->qtdreallocsDuelo++;
                    duelosaux = realloc(d->duelos, d->qtdreallocsDuelo*10*sizeof(tCarta*));
                    if(duelosaux==NULL){
                        printf("ERRO ALOC\n");
                        exit(1);
                    }
                    d->duelos = duelosaux;
                    duelosaux = NULL;
                }
                d->duelos[d->qtdDuelos] = LeDuelo();
                d->qtdDuelos++;
            break;

            case FINALIZAR:
                rodando = 0;
                break;
            break;

            default:
                printf("ERRADO");
            break;
        }
    }
    for(int i = 0; i < d->qtdDuelos; i++){
        int indicec1, indicec2;
        int idC1 = ObtemC1Duelo(d->duelos[i]);
        int idC2 = ObtemC2Duelo(d->duelos[i]);
        for(int q = 0; q< d->qtdCartas; q++){
            if(ObtemIdCarta(d->cartas[q])==idC1){
                indicec1 = q;
            }
            if(ObtemIdCarta(d->cartas[q])==idC2){
                indicec2 = q;
            }
        }
        RealizaDuelo(d->duelos[i], d->cartas[indicec1],d->cartas[indicec2]);
        if(i==0){
            d->identificadorLutaMaiorDiferenca = ObtemIdDuelo(d->duelos[i]);
        }
        if(ObtemDesempateDuelo(d->duelos[i])){
                d->qtdDesempates++;
        }
        if(ObtemDiferencaDuelo(d->duelos[i])>ObtemDiferencaDuelo(d->duelos[d->identificadorLutaMaiorDiferenca-1])){
            d->identificadorLutaMaiorDiferenca = ObtemIdDuelo(d->duelos[i]);
        }
    }
    for(int i = 0; i<d->qtdCartas; i++){
        if(i==0){
            d->cartaMaisVitoriosa = d->cartas[i];
            continue;
        }
        if(ObtemNumVitCarta(d->cartaMaisVitoriosa)<ObtemNumVitCarta(d->cartas[i])){
            d->cartaMaisVitoriosa = d->cartas[i];
        }else if(ObtemNumVitCarta(d->cartaMaisVitoriosa)==ObtemNumVitCarta(d->cartas[i])){
            d->cartaMaisVitoriosa = d->cartas[i];
            printf("EMPATE?");
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
    if(d->qtdDuelos==0){
        return;
    }
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