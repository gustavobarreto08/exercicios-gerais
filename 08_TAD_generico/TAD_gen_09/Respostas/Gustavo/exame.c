#include "exame.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct _Exame{
    char medico[100];
    char paciente[100];
    char descricao[200];
};

/*
    Função que cria uma receita e retorna o seu endereço de memória
    @param nomeMedicamento: nome do medicamento prescrito na receita
    @param nomePaciente: nome do paciente para quem a receita foi prescrita
    @param nomeMedico: nome do médico que prescreveu a receita
    @param instrucoes: instruções para o uso do medicamento
    @return: endereço de memória da receita criada
*/
Exame *criaExame(char *nomePaciente, char *nomeMedico, char *descricao){
    Exame *r = malloc(sizeof(struct _Exame));
    strcpy(r->descricao, descricao);
    strcpy(r->medico, nomeMedico);
    strcpy(r->paciente, nomePaciente);
    return r;
}

/*
    Função que lê os dados de uma receita a partir da entrada padrão de acordo com a especificação
    @return: endereço de memória da receita lida
*/
Exame *leExame(){
    char nomeMedico[100];
    char nomePaciente[100];
    char descricao[200];
    scanf("%[^\n]\n", nomeMedico);
    scanf("%[^\n]\n", nomePaciente);
    scanf("%[^\n]\n", descricao);
    Exame *r = criaExame(nomePaciente, nomeMedico, descricao);
    return r;
}

/*
    Função que calcula o preço de impressão de uma receita de acordo com a especificação
    @param dado: ponteiro genérico para a receita a ser calculada
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão da receita
*/
float calculaPrecoImpressaoExame(void *dado, float precoCaractere){
    Exame *r = (Exame*) dado;
    int TotalCaracteres = strlen(r->descricao) + strlen(r->medico) + strlen(r->paciente);
    float preco = TotalCaracteres * precoCaractere;
    return preco;
}

/*
    Função que imprime uma receita de acordo com a especificação (veja os casos de teste)
    @param dado: ponteiro genérico para a receita a ser impressa
*/
void imprimeExame(void *dado){
    Exame *r = (Exame*) dado;
    printf("- - EXAME - -\n");
    printf("PACIENTE: %s\n", r->paciente);
    printf("SOLICITACAO: %s\n", r->descricao);
    printf("MEDICO: %s\n", r->medico);
    printf("- - - - - - -\n");
}

/*
    Função que desaloca uma receita
    @param dado: ponteiro genérico para a receita a ser desalocada
*/
void desalocaExame(void *dado){
    Exame *e = (Exame*) dado;
    free(e);
}