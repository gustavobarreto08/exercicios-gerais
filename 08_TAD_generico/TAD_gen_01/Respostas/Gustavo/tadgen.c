#include "tadgen.h"
#include <stdlib.h>
#include <stdio.h>

struct generic{
    void *vetorgen;
    int qtdElementos;
    int tipo;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem){
    tGeneric *gen = malloc(sizeof(struct generic));
    gen->vetorgen = NULL;
    gen->tipo = type;
    gen->qtdElementos = numElem;
    return gen;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen){
    free(gen->vetorgen);
    free(gen);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen){
    printf("\n Digite o vetor:\n");
    if(gen->tipo == 0){
        gen->vetorgen = calloc(gen->qtdElementos, sizeof(float));
        for(int i = 0; i < gen->qtdElementos; i++){
            scanf("%f", &((float*)gen->vetorgen)[i]);
        }
    }
    else if(gen->tipo == 1){
        gen->vetorgen = calloc(gen->qtdElementos, sizeof(int));
        for(int i = 0; i < gen->qtdElementos; i++){
            scanf("%d", &((int*)gen->vetorgen)[i]);
        }
    }
    else{
        printf("TIPO INEXISTENTE\n");
        exit(1);
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen){
    for(int i = 0; i < gen->qtdElementos; i++){
        if(gen->tipo == 1){
            printf("%d " , ((int*)gen->vetorgen)[i]);
        }
        if(gen->tipo == 0){
            printf("%.2f ", ((float*)gen->vetorgen)[i]);
        }
    }
}