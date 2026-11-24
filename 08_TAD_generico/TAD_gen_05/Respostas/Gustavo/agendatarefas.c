#include "agendatarefas.h"
#include <stdlib.h>
#include <stdio.h>

typedef void (*fexecuta)(void*);
typedef void (*fdestroi)(void*);

struct agendatarefas{
    void **tarefas;
    int capacidade;
    int qtdTarefas;
    fexecuta *executa;
    fdestroi *destroi;
    int *prioridades;
};

/**
 * @brief Cria uma variável para um tipo genérico que representa uma Agenda de Tarefas
 *
 * @param numElem A quantidade de tarefas que serão armazenadas no agendador
 *
 * @return Um ponteiro para a agenda de tarefas
 */
tAgendaTarefas* CriaAgendaDeTarefas(int numElem){
    tAgendaTarefas *a = malloc(sizeof(struct agendatarefas));
    a->tarefas =  NULL;
    a->capacidade = numElem;
    a->qtdTarefas = 0;
    a->destroi = NULL;
    a->executa = NULL;
    a->prioridades = calloc(numElem, sizeof(int));
    return a;
}

/**
 * @brief Destroi a agenda de tarefas (libera a memória)
 *
 * @param tar - A agenda que terá seu conteúdo liberado/destruído
 */
void DestroiAgendaDeTarefas(tAgendaTarefas* tar){
    for(int i = 0; i < tar->qtdTarefas; i++){
        tar->destroi[i](tar->tarefas[i]);
    }
    free(tar->tarefas);
    free(tar->destroi);
    free(tar->executa);
    free(tar->prioridades);
    free(tar);
}

/**
 * @brief Cadastra uma tarefa em um agendador de tarefas
 *
 * @param tar - Pointeiro para a agenda de tarefas
 * @param prioridade - Prioridade de execução da nova tarefa
 * @param tarefa - Ponteiro para nova tarefa a ser executada
 * @param executa - Ponteiro para função (callback) que será chamada quando for a hora de executar a tarefa
 * @param destroi - Ponteiro para função (callback) que será chamada quando for a hora de destruir a tarefa (liberar a memória)
 *
 */
void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*) ){
        tar->qtdTarefas++;
        tar->tarefas = realloc(tar->tarefas, tar->qtdTarefas*sizeof(*tar->tarefas));
        tar->executa = realloc(tar->executa, tar->qtdTarefas*sizeof(*tar->executa));
        tar->destroi = realloc(tar->destroi, tar->qtdTarefas*sizeof(*tar->destroi));
        tar->tarefas[tar->qtdTarefas-1] = tarefa;
        tar->executa[tar->qtdTarefas-1] = executa;
        tar->destroi[tar->qtdTarefas-1] = destroi;
        tar->prioridades[tar->qtdTarefas-1] = prioridade;
}

/**
 * @brief Executa as tarefas que estão salvas na agenda de tarefas passada como parâmetro.
 *
 * @param tar Agenda de tarefas
 *
 */
void ExecutarTarefasDaAgenda(tAgendaTarefas* tar){
    int *jafeitos = calloc(tar->qtdTarefas, sizeof(int));
    int ultimaFeita = -1;
    for(int i = 0; i < tar->qtdTarefas; i++){
        ultimaFeita = -1;
        for(int q = 0; q < tar->qtdTarefas; q++){
            if(ultimaFeita == -1 || (tar->prioridades[q] > tar->prioridades[ultimaFeita] && jafeitos[q] == 0)){
            if(jafeitos[q] == 1){
                    continue;
                }
                ultimaFeita = q;
            }
        }
        tar->executa[ultimaFeita](tar->tarefas[ultimaFeita]);
        jafeitos[ultimaFeita] = 1;
    }
    free(jafeitos);
}