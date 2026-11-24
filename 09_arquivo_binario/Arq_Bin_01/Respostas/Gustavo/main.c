#include "aluno.h"
#include <stdio.h>
#include <string.h>

int main(){ 
    int nalunos;
    Aluno **alunos;
    char fileName[100];
    strcpy(fileName, "alunos.bin");
    printf("Digite o numero de alunos: ");
    scanf("%d", &nalunos);
    alunos = CriaVetorAlunos(nalunos);
    LeAlunos(alunos, nalunos);
    SalvaAlunosBinario(alunos, fileName, nalunos);
    LiberaAlunos(alunos,nalunos);
    alunos = CriaVetorAlunos(nalunos);
    CarregaAlunosBinario(alunos, fileName);
    ImprimeAlunos(alunos, nalunos);
    LiberaAlunos(alunos, nalunos);
    return 0;
}