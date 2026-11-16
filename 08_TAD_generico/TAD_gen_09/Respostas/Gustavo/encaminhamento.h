#ifndef _ENCAMINHAMENTO_H
#define _ENCAMINHAMENTO_H

/*
    Estrutura do tipo Receita contendo os atributos necessários para a manipulação
*/
typedef struct _Encaminhamento Encaminhamento;

/*
    Função que cria uma receita e retorna o seu endereço de memória
    @param nomeMedicamento: nome do medicamento prescrito na receita
    @param nomePaciente: nome do paciente para quem a receita foi prescrita
    @param nomeMedico: nome do médico que prescreveu a receita
    @param instrucoes: instruções para o uso do medicamento
    @return: endereço de memória da receita criada
*/
Encaminhamento *criaEncaminhamento(char *nomeMedicamento, char *nomePaciente, char *nomeMedico, char *instrucoes);

/*
    Função que lê os dados de uma receita a partir da entrada padrão de acordo com a especificação
    @return: endereço de memória da receita lida
*/
Encaminhamento *leEncaminhamento();

/*
    Função que calcula o preço de impressão de uma receita de acordo com a especificação
    @param dado: ponteiro genérico para a receita a ser calculada
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão da receita
*/
float calculaPrecoImpressaoEncam(void *dado, float precoCaractere);

/*
    Função que imprime uma receita de acordo com a especificação (veja os casos de teste)
    @param dado: ponteiro genérico para a receita a ser impressa
*/
void imprimeEncam(void *dado);

/*
    Função que desaloca uma receita
    @param dado: ponteiro genérico para a receita a ser desalocada
*/
void desalocaEncam(void *dado);

#endif