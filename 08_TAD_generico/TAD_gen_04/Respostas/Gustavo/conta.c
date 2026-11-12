#include "conta.h"
#include <stdlib.h>
#include <stdio.h>

struct Conta{
    int numero;
    float saldo;
    char nome[100];
};

/**
 * @brief Função para criar uma nova conta bancária.
 * @return Um ponteiro para a nova conta bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tConta *CriaConta(){
    tConta *c = malloc(sizeof(struct Conta));
    if(c == NULL){
        exit(1);
    }
    c->saldo = 0.0;
    c->numero = 0;
    return c;
}

/**
 * @brief Função para destruir uma conta bancária.
 * @param conta A conta bancária a ser destruída.
 */
void DestroiConta(DataType conta){
    tConta *c = (tConta*) conta;
    free(c);
}

/**
 * @brief Função para ler uma conta bancária no formato "numero;nome do cliente;saldo inicial".
 * @param conta A conta bancária a ser lida.
 */
void LeConta(tConta *conta){
    scanf("%d;%[^;];%f\n", &conta->numero, conta->nome, &conta->saldo);
}

/**
 * @brief Função para obter o saldo de uma conta bancária.
 * @param conta A conta bancária.
 * @return O saldo da conta bancária.
 */
float GetSaldoConta(tConta *conta){
    return conta->saldo;
}