#include "fila_imp.h"
#include "exame.h"
#include "encaminhamento.h"
#include "receita.h"
#include <stdio.h>
#include <string.h>

int main(){
    char opcao[40];
    float precoCarac;
    FilaImp *fila = criaFilaImp();
    scanf("%f", &precoCarac);
    scanf("\n");

    while(1){
        scanf("%[^\n]\n", opcao);

        if(strcmp(opcao, "RECEITA") == 0){
            Receita *r = leReceita();
            insereDocumentoFilaImp(fila,r,imprimeReceita,desalocaReceita, calculaPrecoImpressaoReceita);
        }
        else if(strcmp(opcao, "ENCAMINHAMENTO") == 0){
            Encaminhamento *e = leEncaminhamento();
            insereDocumentoFilaImp(fila,e,imprimeEncam, desalocaEncam, calculaPrecoImpressaoEncam);
        }
        else if(strcmp(opcao, "EXAME") == 0){
            Exame *e = leExame();
            insereDocumentoFilaImp(fila, e, imprimeExame, desalocaExame, calculaPrecoImpressaoExame);
        }
        else if(strcmp(opcao, "QUANTIDADE") == 0){
            printf("- QUANTIDADE DE DOCUMENTOS NA FILA: %d\n", quantidadeDocumentosNaFilaImp(fila));
        }
        else if(strcmp(opcao, "PRECO") == 0){
            printf("- PRECO TOTAL DA FILA: R$ %.2f\n", precoTotalImpressaoFilaImp(fila, precoCarac));
        }
        else if(strcmp(opcao, "IMPRIME") == 0){
            imprimeFilaImp(fila);
        }
        else if(strcmp(opcao, "FIM") == 0){
            break;
        }
    }
    desalocaFilaImp(fila);
    return 0;
}