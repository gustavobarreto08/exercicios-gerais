#include "pessoa.h"
#include <stdio.h>
#include <string.h>
/**
 * @brief Cria uma nova pessoa com nome vazio (primeiro caractere igual a '\0') e inicializa os ponteiros para pai, mae e irmao com NULL.
 * 
 * @return Uma nova pessoa e sem pais e irmao.
 */
tPessoa CriaPessoa(){
    tPessoa pessoa;
    pessoa.nome[0] = '\0';
    pessoa.pai = NULL;
    pessoa.mae = NULL;
    pessoa.irmao = NULL;
    return pessoa;
}

/**
 * @brief Lê os dados de uma pessoa.
 * 
 * @param pessoa Ponteiro para a pessoa a ser lida.
 */
void LePessoa(tPessoa *pessoa){
    scanf("\n%99[^\n]",pessoa->nome);
    scanf("\n");
}

/**
 * @brief Verifica se uma pessoa tem pai e/ou mae associado(s).
 * Ou seja, verifica pelo menos um dos ponteiros pai e mae é diferente de NULL.
 * 
 * @param pessoa Ponteiro para a pessoa a ser verificada.
 * 
 * @return 1 se a pessoa tiver pai e/ou mae associado(s) e 0 caso contrário.
*/
int VerificaSeTemPaisPessoa(tPessoa *pessoa){
    if(pessoa->mae!=NULL || pessoa->pai!=NULL){
        return 1;
    }
    return 0;
}

/**
 * @brief Imprime os dados de umIncludes/pessoa.ha pessoa caso tenha pai e/ou mae associado(s).
 * Dica: use a função VerificaSeTemPaisPessoa para verificar se a pessoa tem pai e/ou mae associado(s).
 * Alem disso, imprimir o nome do irmao caso exista.
 * 
 * @param pessoa Ponteiro para a pessoa a ser impressa.
 */
void ImprimePessoa(tPessoa *pessoa){
    if(VerificaSeTemPaisPessoa(pessoa)){
        printf("NOME COMPLETO: %s\n",pessoa->nome);
        if(pessoa->pai==NULL){
            printf("PAI: NAO INFORMADO\n");
        }else{
            printf("PAI: %s\n",pessoa->pai->nome);
        }
        if(pessoa->mae==NULL){
            printf("MAE: NAO INFORMADO\n");
        }else{
            printf("MAE: %s\n",pessoa->mae->nome);
        }
        if(pessoa->irmao==NULL){
            printf("IRMAO: NAO INFORMADO\n");
        }else{
            printf("IRMAO: %s\n",pessoa->irmao->nome);
        }
        printf("\n");
    }
}

/**
 * @brief Verifica se duas pessoas são irmãos, ou seja, se os ponteiros pai e mae são iguais.
 * 
 * @param pessoa1 Ponteiro para a primeira pessoa.
 * @param pessoa2 Ponteiro para a segunda pessoa.
 * 
 * @return 1 se as pessoas forem irmãos e 0 caso contrário.
*/
int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2){
    if(pessoa1->pai==pessoa2->pai){
        if(pessoa1->mae==pessoa2->mae){
            return 1;
        }
        return 0;
    }
    return 0;
}


/**
 * @brief Le as associciacoes da entrada padrao e altera as pessoas de forma a representar as associacoes lidas
 * 
 * Apos a associado dos pais, voce deve verificar se ha irmaos e associar os irmaos.
 * 
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 * @param numPessoas Numero de pessoas a serem associadas (tamanho do vetor).
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas){
    int qtdassociacoes;
    scanf("%d",&qtdassociacoes);
    for(int i = 0; i<qtdassociacoes; i++){
        int mae,pai,filho;
            scanf("\nmae: %d, pai: %d, filho: %d",&mae,&pai,&filho);
            if(mae!=-1){
                pessoas[filho].mae = &pessoas[mae];
            }
            if(pai!=-1){
                pessoas[filho].pai = &pessoas[pai];
            }
    }
    for(int i = 0; i<numPessoas; i++){
        for(int j = 0; j<numPessoas; j++){
            if(i!=j){
                if(VerificaIrmaoPessoa(&pessoas[i],&pessoas[j])){
                    pessoas[i].irmao = &pessoas[j];
                    pessoas[j].irmao = &pessoas[i];
                }
            }
        }
    }
}