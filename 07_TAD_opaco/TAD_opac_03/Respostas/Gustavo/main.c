#include "locadora.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    tLocadora *locadora = CriaLocadora();
    if(locadora == NULL){
        perror("ERRO ALOC\n");
        exit(1);
    }
    while(1){
        char opcao[20];
        if(scanf(" %[^\n]", opcao) == EOF){
            break;
        }

        if(!strcmp(opcao,"Cadastrar")){
            CadastraFilmesLocadora(locadora);
            printf("\n");
        }
        else if(!strcmp(opcao,"Devolver")){
            DevolveFilmesLocadora(locadora);
            printf("\n");
        }
        else if(!strcmp(opcao,"Alugar")){
            AlugaFilmesLocadora(locadora);
            printf("\n");
        }
        else if(!strcmp(opcao,"Estoque")){
            ImprimeEstoqueLocadora(locadora);
            printf("\n");
        }
    }
    ImprimeLucroLocadora(locadora);
    DestroiLocadora(locadora);
    return 0;
}