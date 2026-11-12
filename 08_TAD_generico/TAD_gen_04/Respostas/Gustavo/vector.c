#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

struct Vector{
    int tamanho;
    DataType *vetor;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct(){
    Vector *v = malloc(sizeof(struct Vector));
    if(v == NULL){
        exit(1);
    }
    v->tamanho = 0;
    v->vetor = NULL;
    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val){
    v->tamanho++;
    v->vetor = realloc(v->vetor, v->tamanho*sizeof(*(v->vetor)));
    v->vetor[v->tamanho - 1] = val;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i){
    return v->vetor[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v){
    return v->tamanho;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType)){
    for(int i = 0; i < v->tamanho; i++){
        destroy(v->vetor[i]);
    }
    free(v->vetor);
    free(v);
}