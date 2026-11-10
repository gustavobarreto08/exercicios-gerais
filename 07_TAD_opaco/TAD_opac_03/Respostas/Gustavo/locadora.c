#include "locadora.h"
#include "filme.h"
#include <stdio.h>
#include <stdlib.h>

struct Locadora{
    tFilme **filmes;
    int lucro;
    int qtdFilmes;
};

/**
 * @brief Cria uma locadora, ainda sem filmes e sem lucro.
 * Todos os campos da estrutura devem ser inicializados aqui.
 * Se não for possível alocar memória, o programa é encerrado.
 *
 * @return tLocadora* Ponteiro para a locadora criada.
 */
tLocadora* CriaLocadora(){
    tLocadora *locadora = malloc(sizeof(struct Locadora));
    if(locadora == NULL){
        perror("erro aloc\n");
        exit(1);
    }
    locadora->filmes = NULL;
    locadora->qtdFilmes = 0;
    locadora->lucro = 0;
    return locadora;
}

/**
 * @brief Libera a memória de uma locadora, inclusive a dos seus filmes.
 *
 * @param locadora Ponteiro para a locadora a ser destruída.
 */
void DestroiLocadora(tLocadora* locadora){
    for(int i = 0; i < locadora->qtdFilmes; i++){
        DestroiFilme(locadora->filmes[i]);
    }
    free(locadora->filmes);
    free(locadora);
}

/**
 * @brief Cadastra os filmes de um bloco de cadastro, lendo-os com LeFilme até que ela retorne NULL (fim do bloco).
 * Cada filme é adicionado ao final da lista de filmes, imprimindo "Filme cadastrado - <código> - <nome>\n".
 * Se já houver um filme com o mesmo código, o filme não é cadastrado e imprime "Filme ja cadastrado no estoque\n".
 *
 * @param locadora Ponteiro para a locadora.
 */
void CadastraFilmesLocadora(tLocadora* locadora){
    tFilme *aux = NULL;
    while(1){
        int cadastrou = 0;
        aux = LeFilme();
        if(aux == NULL){
            return;
        }
        for(int i = 0; i < locadora->qtdFilmes; i++){
            if(ObtemCodigoFilme(locadora->filmes[i]) == ObtemCodigoFilme(aux)){
                DestroiFilme(aux);
                printf("Filme ja cadastrado no estoque\n");
                cadastrou = 1;
                break;
            }
        }
        if(!cadastrou){
            locadora->qtdFilmes++;
            locadora->filmes = realloc(locadora->filmes, locadora->qtdFilmes*sizeof(*(locadora->filmes)));
            locadora->filmes[locadora->qtdFilmes-1] = aux;
            printf("Filme cadastrado - %d - ", ObtemCodigoFilme(locadora->filmes[locadora->qtdFilmes-1]));
            ImprimeNomeFilme(locadora->filmes[locadora->qtdFilmes-1]);
            printf("\n");
        }
    }
}

/**
 * @brief Aluga uma fita de cada filme de um bloco de aluguel, lendo os códigos com LeCodigoFilme
 * até que ela retorne -1 (fim do bloco). Ao final do bloco, se pelo menos uma fita foi alugada, imprime
 * "Total de filmes alugados: <quantidade> com custo de R$<soma dos valores>\n".
 * 
 * Se o filme não estiver cadastrado, imprime "Filme <código> nao cadastrado\n";
 * Se não houver fitas em estoque, imprime "Filme <código> - <nome> nao disponivel no estoque. Volte mais tarde.\n".
 *
 * @param locadora Ponteiro para a locadora.
 */
void AlugaFilmesLocadora(tLocadora* locadora){
    int codigo = 0, totalAlugados = 0, totalCusto = 0, alugou;
    while(1){
        alugou = 0;
        codigo = LeCodigoFilme();
        if(codigo==-1){
            break;
        }
        for(int i = 0; i < locadora->qtdFilmes; i++){
            if(ObtemCodigoFilme(locadora->filmes[i]) == codigo){
                if(ObtemQtdEstoqueFilme(locadora->filmes[i]) < 1){
                    printf("Filme %d - ", codigo);
                    ImprimeNomeFilme(locadora->filmes[i]);
                    printf(" nao disponivel no estoque. Volte mais tarde.\n");
                    alugou = 1;
                    break;
                }
                AlugaFilme(locadora->filmes[i]);
                totalAlugados++;
                totalCusto += ObtemValorFilme(locadora->filmes[i]);
                alugou = 1;
            }
        }
        if(!alugou){
            printf("Filme %d nao cadastrado\n",codigo);
        }
    }
    if(totalAlugados && totalCusto){
        printf("Total de filmes alugados: %d com custo de R$%d\n", totalAlugados, totalCusto);
    }
}

/**
 * @brief Devolve uma fita de cada filme de um bloco de devolução, lendo os códigos com LeCodigoFilme
 * até que ela retorne -1 (fim do bloco).
 * 
 * Se o filme não estiver cadastrado, imprime "Filme <código> nao cadastrado\n";
 * Se nenhuma fita do filme estiver alugada, imprime "Nao e possivel devolver o filme <código> - <nome>\n";
 * Caso contrário, imprime "Filme <código> - <nome> Devolvido!\n" e o valor do filme é somado ao lucro.
 *
 * @param locadora Ponteiro para a locadora.
 */
void DevolveFilmesLocadora(tLocadora* locadora){
    int codigo = 0, alugou = 0;
    while(1){
        codigo = LeCodigoFilme();
        if(codigo==-1){
            break;
        }
        for(int i = 0; i < locadora->qtdFilmes; i++){
            if(ObtemCodigoFilme(locadora->filmes[i]) == codigo){
                if(ObtemQtdAlugadaFilme(locadora->filmes[i]) < 1){
                    printf("Nao e possivel devolver o filme %d - ", codigo);
                    ImprimeNomeFilme(locadora->filmes[i]);
                    printf("\n");
                    alugou = 1;
                    break;
                }
                DevolveFilme(locadora->filmes[i]);
                locadora->lucro += ObtemValorFilme(locadora->filmes[i]);
                alugou = 1;
                printf("Filme %d - ", codigo);
                ImprimeNomeFilme(locadora->filmes[i]);
                printf(" Devolvido!\n");
            }
        }
        if(!alugou){
            printf("Filme %d nao cadastrado\n",codigo);
        }
    }
}

/**
 * @brief Imprime "~ESTOQUE~\n" e, em seguida, todos os filmes cadastrados (inclusive os sem fitas em estoque)
 * em ordem alfabética do nome, no formato "<código> - <nome> - Fitas em estoque: <quantidade>\n".
 *
 * @param locadora Ponteiro para a locadora.
 */
void ImprimeEstoqueLocadora(tLocadora* locadora){
    tFilme *aux;
    printf("~ESTOQUE~\n");
    for(int i = 0; i < locadora->qtdFilmes; i ++){
        for(int q = 0; q < locadora->qtdFilmes-1; q++){
            if(ComparaNomesFilmes(locadora->filmes[q], locadora->filmes[q+1]) > 0){
                aux = locadora->filmes[q];
                locadora->filmes[q] = locadora->filmes[q+1];
                locadora->filmes[q+1] = aux;
            }
        }
    }
    for(int i = 0; i < locadora->qtdFilmes; i++){
        printf("%d - ", ObtemCodigoFilme(locadora->filmes[i]));
        ImprimeNomeFilme(locadora->filmes[i]);
        printf(" - Fitas em estoque: %d\n", ObtemQtdEstoqueFilme(locadora->filmes[i]));
    }
}

/**
 * @brief Imprime o lucro da locadora: "Lucro total R$<lucro>\n". Se o lucro for zero, não imprime nada.
 *
 * @param locadora Ponteiro para a locadora.
 */
void ImprimeLucroLocadora(tLocadora* locadora){
    if(locadora->lucro){
        printf("Lucro total R$%d\n", locadora->lucro);
    }
}