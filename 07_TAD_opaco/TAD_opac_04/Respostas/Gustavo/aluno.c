#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>

struct Aluno{
    char *nome;
    int n1;
    int n2;
    int n3;
    int matricula;
};

/**
 * @brief Cria um novo aluno vazio.
 * Todos os campos da estrutura devem ser inicializados aqui; os dados do aluno são preenchidos
 * depois, por LeAluno.
 * 
 * @return tAluno* Ponteiro para o aluno criado.
 */
tAluno* CriaAluno(){
    tAluno *a = malloc(sizeof(struct Aluno));
    a->nome = malloc(MAX_NOME*sizeof(char));
    a->n1 = -1;
    a->n2 = -1;
    a->n3 = -1;
    a->matricula = -1;
    return a;
}

/**
 * @brief Libera a memória de um aluno.
 * 
 * @param aluno Ponteiro para estrutura do tipo tAluno a ser apagada.
 */
void ApagaAluno(tAluno *aluno){
    free(aluno->nome);
    free(aluno);
}


/**
 * @brief Lê os dados de um aluno da entrada padrão, em três linhas: o nome, a
 * matrícula e as três notas (inteiros de 0 a 10, separados por espaço).
 * 
 * @param aluno Ponteiro para aluno, cujos dados serão preenchidos nessa função
 */
void LeAluno(tAluno *aluno){
    scanf(" %[^\n]", aluno->nome);
    scanf("%d", &aluno->matricula);
    scanf("%d %d %d", &aluno->n1, &aluno->n2, &aluno->n3);
}

/**
 * @brief Compara as matrículas de dois alunos.
 * 
 * @param aluno1 Ponteiro para o primeiro aluno a ser comparado.
 * @param aluno2 Ponteiro para o segundo aluno a ser comparado.
 * @return int Retorna 1 se a matrícula do aluno1 é maior que a do aluno2, -1 se a matrícula do aluno1 é menor que a do aluno2 e 0 se as matrículas são iguais.
 */
int ComparaMatricula(tAluno* aluno1, tAluno* aluno2){
    if(aluno1->matricula > aluno2->matricula){
        return 1;
    }else if(aluno1->matricula == aluno2->matricula){
        return 0;
    }else{
        return -1;
    }
}

/**
 * @brief Calcula a média aritmética das três notas de um aluno.
 * 
 * @param aluno Ponteiro para aluno a ter a média calculada.
 * @return float Retorna a média das notas do aluno.
 */
float CalculaMediaAluno(tAluno* aluno){
    float media;
    media = (aluno->n1 + aluno->n2 + aluno->n3)/3.0;
    return media;
}

/**
 * @brief Verifica se um aluno foi aprovado (média maior ou igual a 7) ou reprovado.
 * 
 * @param aluno Ponteiro para aluno a ser verificado.
 * @return int Retorna 1 se o aluno foi aprovado e 0 se foi reprovado.
 */
int VerificaAprovacao(tAluno* aluno){
    if(CalculaMediaAluno(aluno) >= 7.0){
        return 1;
    }
    return 0;
}

/**
 * @brief Imprime APENAS o nome do aluno, seguido de quebra de linha. Ex.: "Maria\n".
 * 
 * @param aluno Ponteiro para aluno a ser impresso.
 */
void ImprimeAluno(tAluno* aluno){
    printf("%s\n", aluno->nome);
}