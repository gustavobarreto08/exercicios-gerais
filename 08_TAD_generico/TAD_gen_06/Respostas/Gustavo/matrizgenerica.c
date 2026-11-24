#include "matrizgenerica.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct matrizgenerica{
    int qtdlinhas;
    int qtdcolunas;
    void **matriz;
    int numBytesElem;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar uma Matriz de qualquer tipo de dados,
 * desde que esse tipo ocupe determinado número de bytes.
 *
 * @param linhas - Numero de linhas da matriz
 * @param colunas - Numero de colunas da matriz
 * @param numByteElem - Número de Bytes que cada elemento da matriz ocupará
 *
 * @return Um ponteiro para a estrutura que armazena uma matriz genérica
 */
tMatrizGenerica * CriaMatrizGenerica(int linhas, int colunas, int numByteElem){
    tMatrizGenerica *m = malloc(sizeof(struct matrizgenerica));
    m->qtdlinhas = linhas;
    m->qtdcolunas = colunas;
    m->numBytesElem = numByteElem;
    m->matriz = malloc(m->qtdlinhas * sizeof(*m->matriz));
    for(int i = 0; i < m->qtdlinhas; i++){
        m->matriz[i] = malloc(m->qtdcolunas*numByteElem);
    }
    return m;
}

/**
 * @brief Libera a memória alocada dinamicamente para uma matriz
 *
 * @param mat - Ponteiro para a matriz a ser liberada
 *
 */
void DestroiMatrizGenerica(tMatrizGenerica * mat){
    for(int i = 0; i < mat->qtdlinhas; i++){
        free(mat->matriz[i]);
    }
    free(mat->matriz);
    free(mat);
}

/**
 * @brief Obtém o número de linhas da matriz
 *
 * @param mat - Ponteiro para a matriz que queremos saber o número de linhas
 *
 * @return O número de linhas da matriz
 */
int ObtemNumeroLinhasMatrizGenerica(tMatrizGenerica * mat){
    return mat->qtdlinhas;
}

/**
 * @brief Obtém o número de colunas da matriz
 *
 * @param mat - Ponteiro para a matriz que queremos saber o número de colunas
 *
 * @return O número de colunas da matriz
 */
int ObtemNumeroColunasMatrizGenerica(tMatrizGenerica * mat){
    return mat->qtdcolunas;
}

/**
 * @brief Obtém ponteiro para um elemento qualquer da matriz genérica.
 *
 * @param mat - Ponteiro para a matriz que queremos encontrar o elemento na linha e coluna desejada
 * @param linha - Linha que o elemento está
 * @param coluna - Coluna que o elemento está
 *
 * @return Ponteiro para o elemento da matriz que está na linha e coluna passadas como parâmetro
 */
void * ObtemElementoMatrizGenerica(tMatrizGenerica * mat, int linha, int coluna){
    return (char*)mat->matriz[linha] + coluna * mat->numBytesElem;
}

/**
 * @brief Atribui um elemento a uma posição de uma matriz.
 *
 * @param mat - Ponteiro para a matriz que queremos atribuir o elemento na linha e coluna desejada
 * @param linha - Linha que o elemento ficará
 * @param coluna - Coluna que o elemento ficará
 * @param *elem - Ponteiro para o elemento que será colocado na matriz (será feita uma cópia)
 *
 * @return Ponteiro para o elemento da matriz que está na linha e coluna passadas como parâmetro
 */
void AtribuiElementoMatrizGenerica(tMatrizGenerica * mat, int linha, int coluna, void* elem){
    void *destino = ObtemElementoMatrizGenerica(mat,linha,coluna);
    memcpy(destino,elem, mat->numBytesElem);
}

/**
 * @brief Imprime os elementos usando um callback para imprimir o tipo de dados da matriz.
 * A matriz é impressa linha a linha: após cada elemento (inclusive o último da linha) é impresso um espaço
 * e, ao final de cada linha, uma quebra de linha ('\n'). O callback deve imprimir apenas o elemento,
 * sem espaços ou quebras de linha.
 *
 * @param mat - Ponteiro para a matriz que queremos atribuir o elemento na linha e coluna desejada
 * @param imprime_elemento - Ponteiro para a função (callback) que tem a capacidade de imprimir os dados de um elemento desta matriz
 */

void ImprimirMatrizGenerica(tMatrizGenerica * mat, void (imprime_elemento(void*))){
    for(int i = 0; i < mat->qtdlinhas; i++){
        for(int q = 0; q < mat->qtdcolunas; q++){
            imprime_elemento(ObtemElementoMatrizGenerica(mat,i,q));
            printf(" ");
        }
        printf("\n");
    }
}

/**
 * @brief Encontra a transposta de uma matriz passada como parâmetro
 *
 * @param mat - A matriz que queremos encontrar a transposta
 *
 * @return Ponteiro para uma nova matriz, igual à transposta da matriz mat
 */
tMatrizGenerica *MatrizTransposta(tMatrizGenerica *mat){
    tMatrizGenerica *transposta = CriaMatrizGenerica(mat->qtdcolunas, mat->qtdlinhas, mat->numBytesElem);
    for(int i = 0; i < mat->qtdlinhas; i++){
        for(int q = 0; q < mat->qtdcolunas; q++){
            AtribuiElementoMatrizGenerica(transposta, q, i, ObtemElementoMatrizGenerica(mat,i,q));
        }
    }
    return transposta;
}

/**
 * @brief Calcula e retorna a multiplicação entre duas matrizes
 *
 * @param mat1 - A primeira matriz da multiplicação
 * @param mat2 - A segunda matriz da multiplicação
 * @param numByteTarget - Número de bytes do elemento resultante 
 * @param multi_elem - Ponteiro para função (callback) que realiza a multiplicação entre dois elementos do tipo de dados contido na matriz
 * @param soma_elem - Ponteiro para função (callback) que realiza a soma entre dois elementos do tipo de dados contido na matriz
 *
 * @return Ponteiro para uma nova matriz, igual a multiplicação entre mat1 e mat2.
 */
tMatrizGenerica *MultiplicaMatrizes(tMatrizGenerica *mat1, tMatrizGenerica *mat2, int numByteTarget, void* (*multi_elem)(void*, void*), void* (*soma_elem)(void*,void*)){
    tMatrizGenerica *m = CriaMatrizGenerica(mat1->qtdlinhas, mat2->qtdcolunas, numByteTarget);
    void * resul = NULL;
    int linharesul = 0, colunaresul = 0;
    for(int w = 0; w < mat2->qtdcolunas; w++){
        linharesul = 0;
        for(int i = 0; i < mat1->qtdlinhas; i++){ 
            for(int q = 0; q < mat1->qtdcolunas; q++){
                resul = soma_elem(multi_elem(ObtemElementoMatrizGenerica(mat1,i,q), ObtemElementoMatrizGenerica(mat2,q,w)),resul);
            }
            AtribuiElementoMatrizGenerica(m, linharesul, colunaresul, resul);
            linharesul++;
        }
        colunaresul++;
    }
    return m;
}


/**
 * @brief Converte o tipo da matriz
 *
 * @param mat - A matriz que queremos converter para o novo tipo
 * @param novoNumByteElem - Número de bytes do novo tipo da matriz
 * @param converte_elem - Ponteiro para função que tem a capacidade de converter o elemento do tipo original para o novo tipo
 *
 * @return Ponteiro para uma nova matriz, no novo formato
 */
tMatrizGenerica *ConverteTipoMatriz(tMatrizGenerica *mat2, int novoNumByteElem, void* (*converte_elem)(void*)){
    tMatrizGenerica *nova = CriaMatrizGenerica(mat2->qtdlinhas, mat2->qtdcolunas, novoNumByteElem);
    for(int i = 0; i < nova->qtdlinhas; i++){
        for(int q = 0; q < nova->qtdcolunas; q++){
           AtribuiElementoMatrizGenerica(nova, nova->qtdlinhas, nova->qtdcolunas, converte_elem(ObtemElementoMatrizGenerica(mat2,i,q)));
        }
    }
    return nova;
}