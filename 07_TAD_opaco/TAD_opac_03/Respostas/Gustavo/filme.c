#include "filme.h"
#include <stdio.h>
#include <stdlib.h>

struct Filme
{
    int codigo;
    char *nome;
    int valor;
    int qtdFitas;
    int fitasAlugadas;
};

/**
 * @brief Lê da entrada padrão a linha de cadastro de um filme, no formato "<código>,<nome>,<valor>,<quantidade de fitas>",
 * e cria um filme com esses dados, ainda sem fitas alugadas. Todos os campos da estrutura devem ser inicializados aqui.
 * Se a próxima entrada for o '#' que encerra o bloco, consome o '#' e retorna NULL.
 * Se não for possível alocar memória, o programa é encerrado.
 *
 * @return tFilme* Ponteiro para o filme criado, ou NULL se o bloco terminou.
 */
tFilme* LeFilme(){
    int codigo;
    codigo = LeCodigoFilme();
    if(codigo!=-1){
        tFilme *filme = malloc(sizeof(struct Filme));
        if(filme == NULL){
            perror("erro aloc\n");
            exit(1);
        }
        filme->nome = malloc(MAX_CARACTERES*sizeof(char));
        filme->codigo = codigo;
        scanf(",%[^,],", filme->nome);
        scanf("%d,%d",&filme->valor, &filme->qtdFitas);
        filme->fitasAlugadas = 0;
        return filme;
    }else{
        return NULL;
    }
}

/**
 * @brief Lê da entrada padrão o código de um filme (um por linha).
 * Se a próxima entrada for o '#' que encerra o bloco, consome o '#' e retorna -1.
 *
 * @return int Código lido, ou -1 se o bloco terminou.
 */
int LeCodigoFilme(){
    int codigo;
    if(scanf("%d", &codigo)==1){
        return codigo;
    }else{
        scanf("#");
        return -1;
    }
}

/**
 * @brief Libera a memória de um filme.
 *
 * @param filme Ponteiro para o filme a ser destruído.
 */
void DestroiFilme(tFilme* filme){
    free(filme->nome);
    free(filme);
}

/**
 * @brief Obtém o código de um filme.
 *
 * @param filme Ponteiro para o filme.
 * @return int Código do filme.
 */
int ObtemCodigoFilme(tFilme* filme){
    return filme->codigo;
}

/**
 * @brief Imprime o nome de um filme, sem quebra de linha.
 *
 * @param filme Ponteiro para o filme.
 */
void ImprimeNomeFilme(tFilme* filme){
    printf("%s", filme->nome);
}

/**
 * @brief Obtém o valor de um filme.
 *
 * @param filme Ponteiro para o filme.
 * @return int Valor do filme.
 */
int ObtemValorFilme(tFilme* filme){
    return filme->valor;
}

/**
 * @brief Obtém a quantidade de fitas de um filme em estoque.
 *
 * @param filme Ponteiro para o filme.
 * @return int Quantidade de fitas em estoque.
 */
int ObtemQtdEstoqueFilme(tFilme* filme){
    return filme->qtdFitas;
}

/**
 * @brief Obtém a quantidade de fitas de um filme que estão alugadas.
 *
 * @param filme Ponteiro para o filme.
 * @return int Quantidade de fitas alugadas.
 */
int ObtemQtdAlugadaFilme(tFilme* filme){
    return filme->fitasAlugadas;
}

/**
 * @brief Aluga uma fita do filme: uma fita sai do estoque e passa a estar alugada.
 *
 * @param filme Ponteiro para o filme.
 */
void AlugaFilme(tFilme* filme){
    filme->qtdFitas--;
    filme->fitasAlugadas++;
}

/**
 * @brief Devolve uma fita do filme: uma fita alugada volta para o estoque.
 *
 * @param filme Ponteiro para o filme.
 */
void DevolveFilme(tFilme* filme){
    filme->fitasAlugadas--;
    filme->qtdFitas++;
}

/**
 * @brief Compara os nomes de dois filmes em ordem alfabética.
 *
 * @param filme1 Ponteiro para o primeiro filme.
 * @param filme2 Ponteiro para o segundo filme.
 * @return int Valor negativo se o nome de filme1 vem antes, positivo se vem depois e 0 se os nomes são iguais.
 */
int ComparaNomesFilmes(tFilme* filme1, tFilme* filme2){
    int i = 0;
    while(filme1->nome[i]!='\0' && filme2->nome[i]!='\0'){
        if(filme1->nome[i] > filme2->nome[i]){
            return 1;
        }else if(filme1->nome[i] < filme2->nome[i]){
            return -1;
        }
        i++;
    }
    return 0;
}