#include "documento.h"
#include <stdio.h>
#include <stdlib.h>

struct _Documento{
    void *documento;
    func_ptr_calculaPreco calculapreço;
    func_ptr_desaloca desaloca;
    func_ptr_imprime imprime;
};


/*
    Função que cria um documento genérico e retorna o seu endereço de memória
    @param dado: ponteiro genérico para o dado do documento
    @param imprimeDado: ponteiro para a função de impressão do dado do documento genérico
    @param desalocaDado: ponteiro para a função de desalocação do dado do documento genérico
    @param calculaPrecoDado: ponteiro para a função de cálculo do preço do dado do documento genérico
    @return: endereço de memória do documento genérico criado
*/
Documento *criaDocumento(void *dado, func_ptr_imprime imprimeDado,
                         func_ptr_desaloca desalocaDado, func_ptr_calculaPreco calculaPrecoDado){
                            Documento *doc = malloc(sizeof(struct _Documento));
                            doc->documento = dado;
                            doc->imprime = imprimeDado;
                            doc->desaloca = desalocaDado;
                            doc->calculapreço = calculaPrecoDado;
                            return doc;
                         }

/*
    Função que imprime um documento genérico de acordo com a função de impressão passada
    @param doc: ponteiro para um documento a ser impresso
*/
void imprimeDocumento(Documento *doc){
    doc->imprime(doc->documento);
}

/*
    Função que calcula o preço de impressão de um documento de acordo com a função de cálculo estabelecida na especificação
    @param doc: ponteiro para um documento a ser calculado o preço
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão do documento
*/
float calculaPrecoImpressaoDocumento(Documento *doc, float precoCaractere){
    float preco = doc->calculapreço(doc->documento, precoCaractere);
    return preco;
}

/*
    Função que desaloca um documento de acordo com a função de desalocação passada
    @param doc: ponteiro para um documento a ser desalocado
*/
void desalocaDocumento(Documento *doc){
    doc->desaloca(doc->documento);
    free(doc);
}