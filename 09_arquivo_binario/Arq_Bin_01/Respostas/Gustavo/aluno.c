#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct aluno{
    char nome[100];
    char dtnasc[100];
    char curso[100];
    char periodoing[100];
    int percconc;
    float cra;
};

/**
 * @brief Cria um vetor de ponteiros para alunos, com espaço para numeroAlunos elementos.
 *
 * @param numeroAlunos - Quantidade de alunos que o vetor deve comportar
 *
 * @return Ponteiro para o vetor de alunos criado
 */
Aluno** CriaVetorAlunos(int numeroAlunos){
    Aluno **alunos = malloc(numeroAlunos * sizeof(*(alunos)));
    return alunos;
}

/**
 * @brief Cria um aluno com os dados passados como parâmetro.
 *
 * @param nome - Nome do aluno
 * @param dtNasc - Data de nascimento do aluno
 * @param cursoUfes - Curso do aluno na UFES
 * @param periodoIngresso - Período de ingresso do aluno
 * @param percConclusao - Porcentagem de conclusão do curso
 * @param CRA - Coeficiente de rendimento acadêmico
 *
 * @return Ponteiro para o aluno criado
 */
Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA){
    Aluno *a = malloc(sizeof(struct aluno));
    strcpy(a->nome, nome);
    strcpy(a->dtnasc, dtNasc);
    strcpy(a->curso, cursoUfes);
    strcpy(a->periodoing, periodoIngresso);
    a->percconc = percConclusao;
    a->cra = CRA;
    return a;
}

/**
 * @brief Lê da entrada padrão os dados de numeroAlunos alunos, criando cada um deles e guardando-o no vetor.
 *
 * @param vetorAlunos - Vetor (já criado) onde os alunos serão guardados
 * @param numeroAlunos - Quantidade de alunos a serem lidos
 */
void LeAlunos(Aluno** vetorAlunos, int numeroAlunos){
    char nome[100];
    char dtnasc[100];
    char curso[100];
    char periodoing[100];
    int percconc;
    float cra;
    for(int i = 0; i < numeroAlunos; i++){
        scanf("\n%[^\n]\n", nome);
        scanf("%[^\n]\n", dtnasc);
        scanf("%[^\n]\n", curso);
        scanf("%[^\n]\n", periodoing);
        scanf("%d\n", & percconc);
        scanf("%f\n", &cra);
        vetorAlunos[i] = CriaAluno(nome, dtnasc, curso, periodoing, percconc, cra);
    }

}

/**
 * @brief Libera a memória de todos os alunos e do próprio vetor.
 *
 * @param alunos - Vetor de alunos a ser liberado
 * @param numeroAlunos - Quantidade de alunos no vetor
 */
void LiberaAlunos(Aluno** alunos, int numeroAlunos){
    for(int i = 0; i < numeroAlunos; i++){
        free(alunos[i]);
    }
    free(alunos);
}

/**
 * @brief Salva o vetor de alunos em um arquivo binário e imprime a quantidade de bytes salvos
 * no formato "Numero de bytes salvos: X", seguido de uma quebra de linha.
 *
 *
 * @param alunos - Vetor de alunos a ser salvo
 * @param fileName - Nome do arquivo binário a ser criado
 * @param numeroAlunos - Quantidade de alunos no vetor
 */
void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos){
    int tamanhoBytesAluno =  0;
    int intEscrito = 0;
    FILE *arqbin = fopen(fileName, "wb");
    tamanhoBytesAluno+= fwrite(&numeroAlunos, sizeof(int), 1, arqbin) * sizeof(int);
    for(int i = 0; i < numeroAlunos; i++){
        intEscrito = strlen(alunos[i]->nome);
        tamanhoBytesAluno += fwrite(&intEscrito, sizeof(int), 1, arqbin) * sizeof(int);
        tamanhoBytesAluno+= fwrite(alunos[i]->nome, sizeof(char), intEscrito, arqbin)* sizeof(char);
        intEscrito = strlen(alunos[i]->dtnasc);
        tamanhoBytesAluno+=fwrite(&intEscrito, sizeof(int), 1, arqbin) * sizeof(int);
        tamanhoBytesAluno+=fwrite(alunos[i]->dtnasc, sizeof(char), intEscrito, arqbin)* sizeof(char);
        intEscrito = strlen(alunos[i]->curso);
        tamanhoBytesAluno+=fwrite(&intEscrito, sizeof(int), 1, arqbin)* sizeof(int);
        tamanhoBytesAluno+=fwrite(alunos[i]->curso, sizeof(char), intEscrito, arqbin)* sizeof(char);
        intEscrito = strlen(alunos[i]->periodoing);
        tamanhoBytesAluno+=fwrite(&intEscrito, sizeof(int), 1, arqbin)* sizeof(int);
        tamanhoBytesAluno+=fwrite(alunos[i]->periodoing, sizeof(char), intEscrito, arqbin)* sizeof(char);
        tamanhoBytesAluno+=fwrite(&alunos[i]->percconc, sizeof(int), 1, arqbin)* sizeof(int);
        tamanhoBytesAluno+=fwrite(&alunos[i]->cra, sizeof(float), 1, arqbin)* sizeof(float);
    }
    if(arqbin != NULL){
        fclose(arqbin);
    }
    printf("Numero de bytes salvos: %d\n", tamanhoBytesAluno);
}

/**
 * @brief Lê os alunos de um arquivo binário criando cada um deles e guardando no vetor.
 *
 * @param alunos - Vetor (já criado, com espaço para todos os alunos do arquivo) onde os alunos serão guardados
 * @param fileName - Nome do arquivo binário a ser lido
 */
void CarregaAlunosBinario(Aluno **alunos, char *fileName){
    int qtdAlunos = 0;
    int tamanhoVet = 0;
    char vetor[100];
    int intLido = 0;
    float floatLido = 0.0;
    FILE *arqbin = fopen(fileName, "rb");
    fread(&qtdAlunos, sizeof(int), 1, arqbin);
    for(int i = 0; i < qtdAlunos; i++){
        alunos[i] = malloc(sizeof(struct aluno));
    }
    for(int i = 0; i < qtdAlunos; i++){
        fread(&tamanhoVet, sizeof(int), 1, arqbin);
        fread(vetor, sizeof(char), tamanhoVet, arqbin);
        vetor[tamanhoVet] = '\0';
        strcpy(alunos[i]->nome, vetor);
        fread(&tamanhoVet, sizeof(int), 1, arqbin);
        fread(vetor, sizeof(char), tamanhoVet, arqbin);
        vetor[tamanhoVet] = '\0';
        strcpy(alunos[i]->dtnasc, vetor);
        fread(&tamanhoVet, sizeof(int), 1, arqbin);
        fread(vetor, sizeof(char), tamanhoVet, arqbin);
        vetor[tamanhoVet] = '\0';
        strcpy(alunos[i]->curso, vetor);
        fread(&tamanhoVet, sizeof(int), 1, arqbin);
        fread(vetor, sizeof(char), tamanhoVet, arqbin);
        vetor[tamanhoVet] = '\0';
        strcpy(alunos[i]->periodoing, vetor);
        fread(&intLido, sizeof(int), 1, arqbin);
        alunos[i]->percconc = intLido;
        fread(&floatLido, sizeof(float), 1, arqbin);
        alunos[i]->cra = floatLido;
    }
    if(arqbin != NULL){
        fclose(arqbin);
    }
}

/**
 * @brief Imprime os dados de todos os alunos do vetor.
 *
 * @param alunos - Vetor de alunos a ser impresso
 * @param numeroAlunos - Quantidade de alunos no vetor
 */
void ImprimeAlunos(Aluno** alunos, int numeroAlunos){
    for(int i = 0; i < numeroAlunos; i++){
        printf("Aluno %d:\n", i);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Data Nascimento: %s\n", alunos[i]->dtnasc);
        printf("Curso: %s\n", alunos[i]->curso);
        printf("Periodo Ingresso: %s\n", alunos[i]->periodoing);
        printf("%% Conclusao do Curso: %d\n", alunos[i]->percconc);
        printf("CRA: %.2f\n", alunos[i]->cra);
    }
}