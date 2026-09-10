#include "string_utils.h"
#include <stdio.h>

int main(){
    int escolha = 0, i=0;
    char string[100];
    char stringcopia[100];
    fgets(string,100,stdin);
    while(1){
        if(string[i]=='\n'){
            string[i] = '\0';
            break;
        }
        i++;
    }
    while(escolha!=6){
        printf("1 - Tamanho da string\n");
        printf("2 - Copiar string\n");
        printf("3 - Converter string para letras maiusculas\n");
        printf("4 - Converter string para letras minusculas\n");
        printf("5 - Imprimir string ao contrario\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida: \n");
        scanf("%d",&escolha);
        switch(escolha){
            case 1:
                printf("Tamanho da string: %d\n\n", (string_length(string)));
            break;

            case 2:
                printf("String copiada: ");
                string_copy(string,stringcopia);
                printf("%s",string);
                printf("\n\n");
            break;

            case 3:
                printf("String convertida para maiusculas: ");
                string_upper(string);
                printf("%s",string);
                printf("\n\n");
            break;

            case 4:
                printf("String convertida para minusculas: ");
                string_lower(string);
                printf("%s",string);
                printf("\n\n");
            break;

            case 5:
                printf("String invertida: ");
                string_reverse(string);
                printf("%s",string);
                printf("\n\n");
            break;

            default:
            break;
        }
    }
    return 0;
}