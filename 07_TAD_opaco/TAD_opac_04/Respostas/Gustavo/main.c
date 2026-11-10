#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int nAlunos;
    tAluno **alunos = NULL;
    scanf("%d", &nAlunos);
    alunos = malloc(nAlunos*sizeof(*(alunos)));
    for(int i = 0; i<nAlunos; i++){
        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);
    }
    tAluno *aux = NULL;
    for(int i = 0; i < nAlunos; i++){
        for(int q = 0; q < nAlunos-1; q++){
            if(ComparaMatricula(alunos[q], alunos[q+1]) > 0){
                aux = alunos[q];
                alunos[q] = alunos[q+1];
                alunos[q+1] = aux;
            }
        }
    }
    for(int i = 0; i < nAlunos; i++){
        if(VerificaAprovacao(alunos[i])){
            ImprimeAluno(alunos[i]);
        }
    }
    for(int i = 0; i < nAlunos; i++){
        ApagaAluno(alunos[i]);
    }
    free(alunos);
    return 0;
}