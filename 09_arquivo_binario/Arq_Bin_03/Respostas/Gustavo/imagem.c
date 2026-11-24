#include "imagem.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief Estrutura para representar uma imagem.
 */
struct tImagem{
    void **matriz;
    int tipo;
    int qtdLinhas;
    int qtdColunas;
    int bytesLidos;
};

/**
 * @brief Função para ler uma imagem de um arquivo binário e aloca-la na memória.
 * A função também armazena o número de bytes lidos na estrutura Imagem.
 * @param path O caminho para o arquivo de imagem.
 * @return Um ponteiro para a imagem lida. Se houver erro (de leitura ou alocação de memória), a função imprime uma mensagem de erro e termina o programa.
 */
Imagem *LerImagem(const char *caminho){
    Imagem *i = malloc(sizeof(struct tImagem));
    i->bytesLidos = 0;
    FILE *f = fopen(caminho, "rb");
    i->bytesLidos += fread(&i->qtdLinhas, sizeof(int), 1, f) * sizeof(int);
    i->bytesLidos += fread(&i->qtdColunas, sizeof(int), 1, f) * sizeof(int);
    i->bytesLidos += fread(&i->tipo, sizeof(int), 1, f) * sizeof(int);
    if(i->tipo == 0){
        i->matriz = malloc(i->qtdLinhas * sizeof(*(i->matriz)));
        for(int q = 0; q < i->qtdLinhas; i++){
            i->matriz[q] = malloc(i->qtdColunas * sizeof(**(i->matriz)));
        }
        i->bytesLidos += fread(&i->matriz, sizeof(float),i->qtdColunas*i->qtdLinhas, f) * sizeof(float);
    }
    else if(i->tipo == 1){
        i->matriz = malloc(i->qtdLinhas * sizeof(*(i->matriz)));
        for(int q = 0; q < i->qtdLinhas; i++){
            i->matriz[q] = malloc(i->qtdColunas * sizeof(**(i->matriz)));
        }
        i->bytesLidos += fread(&i->matriz, sizeof(int),i->qtdColunas*i->qtdLinhas, f) * sizeof(int);
        fread(&i->matriz, sizeof(int),i->qtdColunas*i->qtdLinhas, f);
    }
    fclose(f);
    return i;
}

/**
 * @brief Função para destruir uma imagem.
 * @param img A imagem a ser destruída.
 */
void DestruirImagem(Imagem *img){
    for(int i = 0; i < img->qtdLinhas; i++){
        free(img->matriz[i]);
    }
    free(img->matriz);
    free(img);
}

/**
 * @brief Função para obter o número de bytes lidos de uma imagem.
 * @param img A imagem.
 * @return O número de bytes lidos.
 */
int ObterNumeroBytesLidos(Imagem *img){
    return img->bytesLidos;
}

/**
 * @brief Função para imprimir uma imagem.
 * @param img A imagem.
 */
void ImprimirImagem(Imagem *img){
    for(int q = 0; q < img->qtdColunas; q++){
        for(int i = 0; i < img->qtdLinhas; i++){
            if(img->tipo == 0){
                printf("%d ", (int*) &(img->matriz)[q][i]);
            }
            else if(img->tipo == 1){
                printf("%.2f ", (float*) &(img->matriz)[q][i]);
            }
        }
        printf("\n");
    }
}