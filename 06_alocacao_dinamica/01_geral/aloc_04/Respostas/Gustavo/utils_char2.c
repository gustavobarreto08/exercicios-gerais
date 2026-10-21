#include <stdio.h>
#include "utils_char2.h"
#include <stdlib.h>

/**
 * Cria um vetor de caracteres que consegue armazenar uma string de tamanho igual a "TAM_PADRAO", alocado dinamicamente.
 * Neste caso, a string deve ser inicializada com todas as suas "TAM_PADRAO" posições com "_", e a última posição deve conter '\0'.
 * Se houver erro na alocação, imprime uma mensagem de erro e encerra o programa.
 * 
 * @return Ponteiro para o vetor criado.
 */
char *CriaVetorTamPadrao(){
    char *vetor = NULL;
    vetor = malloc((TAM_PADRAO+1)*sizeof(char));
    if(vetor==NULL){
        printf("ERRO");
        exit(1);
    }
    for(int i = 0;i<=TAM_PADRAO;i++){
        if(i==TAM_PADRAO){
            vetor[i] = '\0';
            break;
        }
        vetor[i] = '_';
    }
    return vetor;
}

/**
 * Aumenta o tamanho de um vetor alocado dinamicamente
 * O vetor deve ser aumentado para conseguir alocar mais "TAM_PADRAO" caracteres (o vetor só pode ter tamanhos múltiplos de "TAM_PADRAO")
 * Preencha as novas posições com "_", e lembre-se que a última deve conter '\0'.
 * 
 * @param tamanhoantigo Tamanho do vetor a ser modificado
 * @return Ponteiro para o novo vetor.
 */
char *AumentaTamanhoVetor(char* vetor, int tamanhoantigo){
    char *temp = NULL;
    temp = realloc(vetor,(tamanhoantigo+TAM_PADRAO+1)*sizeof(char));
    if(temp==NULL){
        printf("erro");
        exit(1);
    }
    vetor = temp;
    for(int i = tamanhoantigo;i<(tamanhoantigo+TAM_PADRAO)+1;i++){
        if(i==(tamanhoantigo+TAM_PADRAO)){
            vetor[i] = '\0';
            break;
        }
        vetor[i] = '_';
    }
    return vetor;
}

/**
 * Lê uma string do tamanho especificado até um enter ser apertado.
 * Caso seja necessário alterar o tamanho do vetor, o tamanho deve ser atualizado para que o programa
 * saiba o novo tamanho do vetor.
 *
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho* Ponteiro para uma variável do tipo inteiro que armazena o tamanho atual do vetor.
 * @return Um ponteiro para o vetor lido.
*/
char* LeVetor(char *vetor, int *tamanho){
    char c;
    for(int i = 0;; i++){
        if(i>=*tamanho){
            vetor = AumentaTamanhoVetor(vetor,*tamanho);
            *tamanho = (*tamanho)+TAM_PADRAO;
        }
        scanf("%c",&c);
        if(c!='\n'){
            vetor[i] = c;
        }else{
            break;
        }
    }
    return vetor;
}

/**
 * Imprime a string
 * 
 * @param vetor Ponteiro para o vetor a ser imprimido.
*/
void ImprimeString(char *vetor){
    printf("%s\n",vetor);
}

/**
 * Libera a memória alocada para um vetor de caracteres.
 * 
 * @param vetor Ponteiro para o vetor a ser liberado.
*/
void LiberaVetor(char *vetor){
    free(vetor);
}
