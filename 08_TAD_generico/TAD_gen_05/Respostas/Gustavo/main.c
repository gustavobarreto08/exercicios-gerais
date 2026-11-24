#include "agendatarefas.h"
#include "tarefaimprime.h"
#include "tarefamultiplica.h"
#include "tarefasoma.h"
#include <stdio.h>
#include <string.h>

int main(){
    int qtdTarefas = 0, prioridade = 0;
    char c;
    printf("Digite o numero de tarefas: ");
    scanf("%d", &qtdTarefas);
    tAgendaTarefas *tar = CriaAgendaDeTarefas(qtdTarefas);
    for(int i = 0; i < qtdTarefas; i++){
        scanf("%d", &prioridade);
        scanf(" %c ", &c);
        if(c == 'I'){
            char nome[100];
            scanf("%[^\n]\n", nome);
            tImpr *s = CriaTarefaImprimir(nome);
            CadastraTarefaNaAgenda(tar, prioridade, s, ExecutaTarefaImprimir, DestroiTarefaImprimir);
        }
        else if(c == 'M'){
            float n1, n2;
            scanf("%f %f\n", &n1, &n2);
            tMult *m = CriaTarefaMultiplicar(n1,n2);
            CadastraTarefaNaAgenda(tar, prioridade, m, ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);
        }
        else if(c == 'S'){
            float n1, n2;
            scanf("%f %f\n", &n1, &n2);
            tSoma *m = CriaTarefaSoma(n1,n2);
            CadastraTarefaNaAgenda(tar, prioridade, m, ExecutaTarefaSoma, DestroiTarefaSoma);
        }
        else{
            char nome[200];
            char lixo[200];
            scanf("%[^\n]\n",lixo);
            strcpy(nome,"Digite um tipo de tarefa suportado (I/S/M))");
            printf("\n%s", nome);
            i--;
        }
    }
    ExecutarTarefasDaAgenda(tar);
    DestroiAgendaDeTarefas(tar);
    return 0;
}