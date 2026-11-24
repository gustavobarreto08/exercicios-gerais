#include "tarefaimprime.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct impr{
    char msg[100];
    int prioridade;
;};

/**
 * @brief Cria uma tarefa do tipo impressão em tela
 * 
 * @param msg - A mensagem que deve ser impressa em tela
 *
 * @return Um ponteiro para a tarefa criada
 */
tImpr* CriaTarefaImprimir(char *msg){
    tImpr *i = malloc(sizeof(struct impr));
    strcpy(i->msg, msg);
    i->prioridade = 0;
    return i;
}

/**
 * @brief Função que executa uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaImprimir(void *imp){
    tImpr *i = (tImpr*) imp;
    printf("\n%s", i->msg);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaImprimir(void *imp){
    tImpr *i = (tImpr*) imp;
    free(i);
}