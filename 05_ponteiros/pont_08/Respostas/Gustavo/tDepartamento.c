#include "tDepartamento.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief Cria um departamento com os dados passados via parâmetro
 *
 *
 * @param *curso1 Ponteiro para string que contém o nome do primeiro curso do departamento
 * @param *curso2 Ponteiro para string que contém o nome do segundo curso do departamento
 * @param *curso3 Ponteiro para string que contém o nome do terceiro curso do departamento
 * @param *nome Ponteiro para string que contém o nome do departamento
 * @param m1 Nota do primeiro curso (curso1)
 * @param m2 Nota do segundo curso (curso2)
 * @param m3 Nota do terceiro curso (curso3)
 * @param *diretor Ponteiro para string que contém o nome do diretor/chefe do departamento
 */
tDepartamento CriaDepartamento( char *curso1, char *curso2, char *curso3,
                                char *nome, int m1, int m2, int m3, char *diretor ){
    tDepartamento departamentocriado;
    strcpy(departamentocriado.curso1,curso1);
    strcpy(departamentocriado.curso2,curso2);
    strcpy(departamentocriado.curso3,curso3);
    strcpy(departamentocriado.nome, nome);
    departamentocriado.m1 = m1;
    departamentocriado.m2 = m2;
    departamentocriado.m3 = m3;
    strcpy(departamentocriado.diretor, diretor);
    return departamentocriado;
}

/**
 * @brief Imprime os atributos de um departamento em tela
 *
 * @param depto - Um departamento que terá seus dados impressos em tela
 */

void ImprimeAtributosDepartamento(tDepartamento depto){
    float media = (depto.m1+depto.m2+depto.m3)/3.0;
    printf("\nDepartamento: %s\n",depto.nome);
    printf("\t1o curso: %s\n",depto.curso1);
    printf("\tMedia do 1o curso: %d\n",depto.m1);
    printf("\t2o curso: %s\n",depto.curso2);
    printf("\tMedia do 2o curso: %d\n",depto.m2);
    printf("\t3o curso: %s\n",depto.curso3);
    printf("\tMedia do 3o curso: %d\n",depto.m3);
    printf("\tMedia dos cursos: %.2f\n",media);
}

/**
 * @brief Ordena os departamentos de acordo com as médias das notas de cada um dos seus três cursos (da maior para a menor).
 *
 * @param *vetor_deptos - Ponteiro para um vetor de departamentos
 * @param num_deptos - O número de departamentos contidos no vetor_deptos
 */
void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos){
    float media1,media2;
    tDepartamento aux;
    for(int j = 0; j < num_deptos-1; j++){
        for(int i = 0; i < num_deptos-1; i++){
            media1 = (vetor_deptos[i].m1 + vetor_deptos[i].m2 + vetor_deptos[i].m3)/3.0;
            media2 = (vetor_deptos[i+1].m1 + vetor_deptos[i+1].m2 + vetor_deptos[i+1].m3)/3.0;
            if(media2>media1){
                aux = CriaDepartamento(vetor_deptos[i].curso1, vetor_deptos[i].curso2, vetor_deptos[i].curso3, vetor_deptos[i].nome,
                vetor_deptos[i].m1, vetor_deptos[i].m2, vetor_deptos[i].m3, vetor_deptos[i].diretor);
                vetor_deptos[i] = CriaDepartamento(vetor_deptos[i+1].curso1, vetor_deptos[i+1].curso2, vetor_deptos[i+1].curso3, vetor_deptos[i+1].nome,
                vetor_deptos[i+1].m1, vetor_deptos[i+1].m2, vetor_deptos[i+1].m3, vetor_deptos[i+1].diretor);
                vetor_deptos[i+1] = CriaDepartamento(aux.curso1, aux.curso2, aux.curso3, aux.nome,
                aux.m1, aux.m2, aux.m3, aux.diretor);
            }
        }
    }
}
