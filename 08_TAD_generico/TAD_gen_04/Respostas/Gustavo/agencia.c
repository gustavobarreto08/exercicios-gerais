#include "agencia.h"
#include <stdlib.h>
#include <stdio.h>

struct Agencia{
    Vector *contas;
    int numero;
    char nome[100];
};

/**
 * @brief Função para criar uma nova agência bancária.
 * @return Um ponteiro para a nova agência bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tAgencia *CriaAgencia(){
    tAgencia *a = malloc(sizeof(struct Agencia));
    if(a == NULL){
        exit(1);
    }
    a->contas = VectorConstruct();
    a->numero = 0;
    return a;
}

/**
 * @brief Função para destruir uma agência bancária.
 * @param agencia A agência bancária a ser destruída.
 */
void DestroiAgencia(DataType agencia){
    tAgencia *a = (tAgencia*) agencia;
    VectorDestroy(a->contas, DestroiConta);
    free(a);
}

/**
 * @brief Função para ler uma agência bancária no formato "numero;nome".
 * @param agencia A agência bancária a ser lida.
 */
void LeAgencia(tAgencia *agencia){
    scanf("%d;%[^\n]\n", &agencia->numero, agencia->nome);
}

/**
 * @brief Função para adicionar uma conta bancária a uma agência bancária.
 * @param agencia A agência bancária.
 * @param conta A conta bancária a ser adicionada.
 */
void AdicionaConta(tAgencia *agencia, tConta *conta){
    VectorPushBack(agencia->contas, conta);
}

/**
 * @brief Função para comparar um número de agência bancária com uma agência bancária.
 * @param numAgencia O número da agência bancária.
 * @param agencia2 A agência bancária a ser comparada.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int ComparaAgencia(int numAgencia, tAgencia *agencia2){
    if(numAgencia == agencia2->numero){
        return 1;
    }
    return 0;
}

/**
 * @brief Função para obter o saldo médio das contas de uma agência bancária.
 * @param agencia A agência bancária.
 * @return O saldo médio das contas da agência.
 */
float GetSaldoMedioAgencia (tAgencia *agencia){
    float saldoMedio = 0.0;
    for(int i = 0; i < VectorSize(agencia->contas); i++){
        saldoMedio += GetSaldoConta(VectorGet(agencia->contas,i));
    }
    saldoMedio = saldoMedio/VectorSize(agencia->contas);
    return saldoMedio;
}

/**
 * @brief Função para imprimir os dados de uma agência bancária (nome, número, número de contas cadastradas e saldo médio).
 * @param agencia A agência bancária.
 */
void ImprimeDadosAgencia(tAgencia *agencia){
    printf("\tNome: %s\n", agencia->nome);
    printf("\tNumero: %d\n", agencia->numero);
	printf("\tNumero de contas cadastradas: %d\n", VectorSize(agencia->contas));
	printf("\tSaldo médio: R$%.2f\n\n", GetSaldoMedioAgencia(agencia));
}