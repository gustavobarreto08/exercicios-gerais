#include "base_alunos.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

struct BaseAlunos{
    tAluno **alunos;
    int nAlunos;
};

/**
 * @brief Função para criar uma nova base de alunos.
 * 
 * @return Um ponteiro para a base de alunos recém-criada. Se houver erro na alocação de memória, o programa é encerrado.
 */
tBaseAlunos* CriarBaseAlunos(){
    tBaseAlunos *b = malloc(sizeof(struct BaseAlunos));
    b->nAlunos = 0;
    return b;
}

/**
 * @brief Função para destruir uma base de alunos.
 * 
 * @param baseAlunos A base de alunos a ser destruída.
 */
void DestruirBaseAlunos(tBaseAlunos* baseAlunos){
    for(int i = 0; i < baseAlunos->nAlunos; i++){
        DestruirAluno(baseAlunos->alunos[i]);
    }
    free(baseAlunos->alunos);
    free(baseAlunos);
}

/**
 * @brief Função para ler uma base de alunos de um arquivo binário.
 * 
 * @param baseAlunos A base de alunos para ler o arquivo.
 * @param nomeArquivo O nome do arquivo a ser lido.
 */
void LerBaseAlunos(tBaseAlunos* baseAlunos, char* nomeArquivo){
    FILE *arq = fopen(nomeArquivo, "rb");
    fread(&baseAlunos->nAlunos, sizeof(int), 1, arq);
    baseAlunos->alunos = malloc(baseAlunos->nAlunos * sizeof(*(baseAlunos->alunos)));
    for(int i = 0; i < baseAlunos->nAlunos; i++){
        baseAlunos->alunos[i] = LeAluno(arq);
    }
    fclose(arq);
}

/**
 * @brief Função para obter o coeficiente de rendimento médio de uma base de alunos.
 * 
 * @param baseAlunos A base de alunos para obter o coeficiente de rendimento médio.
 * @return O coeficiente de rendimento médio da base de alunos.
 */
float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos* baseAlunos){
    float soma = 0.0;
    for(int i = 0; i < baseAlunos->nAlunos; i++){
        soma += GetCoeficienteRendimentoAluno(baseAlunos->alunos[i]);
    }
    return soma/baseAlunos->nAlunos;
}