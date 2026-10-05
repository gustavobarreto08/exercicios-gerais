#include "tDepartamento.h"
#include <stdio.h>

int main(){
    int num_deptos;
    int m1,m2,m3;
    char nome[STRING_MAX];
    char diretor[STRING_MAX];   
    char curso1[STRING_MAX];
    char curso2[STRING_MAX];
    char curso3[STRING_MAX];
    scanf("%d\n",&num_deptos);
    tDepartamento departamentos[num_deptos];
    printf("\nDigite um departamento com médias válidas");
    for(int i = 0; i < num_deptos; i++){
        scanf("%[^\n]",nome);
        scanf("\n");
        scanf("%[^\n]",diretor);
        scanf("\n");
        scanf("%[^\n]",curso1);
        scanf("\n");
        scanf("%[^\n]",curso2);
        scanf("\n");
        scanf("%[^\n]",curso3);
        scanf("\n");
        scanf("%d %d %d\n",&m1,&m2,&m3);
        departamentos[i] = CriaDepartamento(curso1,curso2,curso3,nome,m1,m2,m3,diretor);
    }
    OrdenaDepartamentosPorMedia(departamentos,num_deptos);
    for(int i = 0; i < num_deptos; i++){
        ImprimeAtributosDepartamento(departamentos[i]);
    }
}