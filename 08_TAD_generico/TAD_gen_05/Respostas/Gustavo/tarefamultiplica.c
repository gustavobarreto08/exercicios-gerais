#include "tarefamultiplica.h"
#include <stdlib.h>
#include <stdio.h>

struct mult{
    float n1;
    float n2;
    float resultado;
    int prioridade;
};

/**
 * @brief Cria uma tarefa do tipo multiplicação de dois números
 * 
 * @param n1 - Primeiro número que será multiplicado quando a tarefa for executada
 * @param n2 - Segundo número que será multiplicado quando a tarefa for executada
 *
 * @return Um ponteiro para a tarefa criada
 */
tMult* CriaTarefaMultiplicar(float n1, float n2){
    tMult *mul = malloc(sizeof(struct mult));
    mul->n1 = n1;
    mul->n2 = n2;
    mul->prioridade = 0;
    return mul;
}

/**
 * @brief Função que executa uma tarefa de multiplicação de dois números
 *
 * @param mult - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaMultiplicar(void *mult){
    tMult *mul = (tMult*) mult;
    mul->resultado = mul->n1 * mul->n2;
    printf("\nO resultado da multiplicacao de %.2f com %.2f eh: %.2f\n", mul->n1, mul->n2, mul->resultado);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de multiplicação de dois números
 *
 * @param mult - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaMultiplicar(void *mult){
    tMult *mul = (tMult*) mult;
    free(mul);
}