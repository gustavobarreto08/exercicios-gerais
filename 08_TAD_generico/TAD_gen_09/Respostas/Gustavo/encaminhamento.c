#include "encaminhamento.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct _Encaminhamento{
    char nomeMedico[100];
    char nomePaciente[100];
    char especialidade[100];
    char motivo[200];
};
/*
    Função que cria uma receita e retorna o seu endereço de memória
    @param nomeMedicamento: nome do medicamento prescrito na receita
    @param nomePaciente: nome do paciente para quem a receita foi prescrita
    @param nomeMedico: nome do médico que prescreveu a receita
    @param instrucoes: instruções para o uso do medicamento
    @return: endereço de memória da receita criada
*/
Encaminhamento *criaEncaminhamento(char *especialidade, char *nomePaciente, char *nomeMedico, char *motivo){
    Encaminhamento *r = malloc(sizeof(struct _Encaminhamento));
    strcpy(r->especialidade, especialidade);
    strcpy(r->nomeMedico, nomeMedico);
    strcpy(r->nomePaciente, nomePaciente);
    strcpy(r->motivo, motivo);
    return r;
}

/*
    Função que lê os dados de uma receita a partir da entrada padrão de acordo com a especificação
    @return: endereço de memória da receita lida
*/
Encaminhamento *leEncaminhamento(){
    char especialidade[100];
    char nomeMedico[100];
    char nomePaciente[100];
    char motivo[200];
    scanf("%[^\n]\n", nomeMedico);
    scanf("%[^\n]\n", nomePaciente);
    scanf("%[^\n]\n", especialidade);
    scanf("%[^\n]\n", motivo);
    Encaminhamento *r = criaEncaminhamento(especialidade, nomePaciente, nomeMedico, motivo);
    return r;
}

/*
    Função que calcula o preço de impressão de uma receita de acordo com a especificação
    @param dado: ponteiro genérico para a receita a ser calculada
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão da receita
*/
float calculaPrecoImpressaoEncam(void *dado, float precoCaractere){
    Encaminhamento *r = (Encaminhamento*) dado;
    int TotalCaracteres = strlen(r->especialidade) + strlen(r->motivo) + strlen(r->nomeMedico) + strlen(r->nomePaciente);
    float preco = TotalCaracteres * precoCaractere;
    return preco;
}

/*
    Função que imprime uma receita de acordo com a especificação (veja os casos de teste)
    @param dado: ponteiro genérico para a receita a ser impressa
*/
void imprimeEncam(void *dado){
    Encaminhamento *r = (Encaminhamento*) dado;
    printf("- - ENCAMINHAMENTO - -\n");
    printf("PACIENTE: %s\n", r->nomePaciente);
    printf("ESPECIALIDADE: %s\n", r->especialidade);
    printf("MOTIVO: %s\n", r->motivo);
    printf("MEDICO: %s\n", r->nomeMedico);
    printf("- - - - - - - - - - - -\n");
}

/*
    Função que desaloca uma receita
    @param dado: ponteiro genérico para a receita a ser desalocada
*/
void desalocaEncam(void *dado){
    Encaminhamento *e = (Encaminhamento*) dado;
    free(e);
}