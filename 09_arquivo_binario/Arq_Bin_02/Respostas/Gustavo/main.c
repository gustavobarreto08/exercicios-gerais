#include "base_alunos.h"
#include <stdio.h>

int main(){
    tBaseAlunos *b = CriarBaseAlunos();
    char nomearq[100];
    scanf("%[^\n]\n", nomearq);
    LerBaseAlunos(b, nomearq);
    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f", GetCoeficienteRendimentoMedioBaseAlunos(b));
    DestruirBaseAlunos(b);
    return 0;
}