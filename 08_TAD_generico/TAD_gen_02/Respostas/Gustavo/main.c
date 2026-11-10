#include "gerenciadorpacotes.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int opcao, printa = 0;
    tGerenciador *geren = CriaGerenciador();
    while(1){
        if(printa){
            printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem: \n");
        }else{
            printf("\n");
        }
        printf("Escolha uma opcao:\n");
        printf("\t(1) Cadastrar um novo pacote\n");
        printf("\t(2) Imprimir um pacote especifico\n");
        printf("\t(3) Imprimir todos os pacotes e sair\n");
        scanf("%d", &opcao);

        if(opcao == 1){
            int tipo, numEle;
            scanf("%d %d", &tipo, &numEle);
            if(tipo != 0 && tipo != 1){
                continue;
            }
            tPacote *aux = CriaPacote(tipo,numEle);
            LePacote(aux);
            AdicionaPacoteNoGerenciador(geren,aux);
            aux = NULL;
        }
        else if(opcao == 2){
            int idx;
            scanf("%d", &idx);
            ImprimirPacoteNoIndice(geren,idx);
        }
        else if(opcao == 3){
            ImprimirTodosPacotes(geren);
            break;
        }
        printa = 1;
    }
    DestroiGerenciador(geren);
    return 0;
}