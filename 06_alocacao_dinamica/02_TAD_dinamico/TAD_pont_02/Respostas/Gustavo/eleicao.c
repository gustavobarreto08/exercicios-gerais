#include "eleicao.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_CANDIDATOS_POR_CARGO 3
#define MAX_ELEITORES 10

/* typedef struct {
    tCandidato** presidentes;
    int totalPresidentes;

    tCandidato** governadores;
    int totalGovernadores;

    int votosBrancosPresidente;
    int votosNulosPresidente;

    int votosBrancosGovernador;
    int votosNulosGovernador;

    tEleitor** eleitores;
    int totalEleitores;
    
} tEleicao; */

/**
 * @brief Inicializa uma eleição com valores padrão (zerando as variáveis que armazenam votos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados
 * A memória necessária para os vetores "presidentes", "governadores" deve ser alocada aqui.
 * Demais ponteiros devem ser inicializado com NULL.
 * @return Eleição inicializada.
 */
tEleicao* InicializaEleicao(){
    int qtdcandidatos;
    tCandidato *candidatoaux;
    tEleicao *eleicao = malloc(sizeof*eleicao);
    eleicao->votosBrancosGovernador = 0;
    eleicao->votosNulosGovernador = 0;
    eleicao->votosBrancosPresidente = 0;
    eleicao->votosNulosPresidente = 0;
    eleicao->presidentes = malloc(MAX_CANDIDATOS_POR_CARGO*sizeof*(eleicao->presidentes));
    for(int i = 0; i< MAX_CANDIDATOS_POR_CARGO; i++){
        eleicao->presidentes[i] = CriaCandidato();
    }
    eleicao->governadores = malloc(MAX_CANDIDATOS_POR_CARGO*sizeof*(eleicao->governadores));
    for(int i = 0; i< MAX_CANDIDATOS_POR_CARGO; i++){
        eleicao->governadores[i] = CriaCandidato();
    }
    eleicao->eleitores = malloc(MAX_ELEITORES*sizeof*(eleicao->eleitores));
    for(int i = 0; i< MAX_ELEITORES; i++){
        eleicao->eleitores[i] = CriaEleitor();
    }
    scanf("%d",&qtdcandidatos);
    for(int i = 0; i<qtdcandidatos; i++){
        candidatoaux = CriaCandidato();
        //ver qual cargo dele e atribuir no vetor certo
    }
    return eleicao;
}


void ApagaEleicao(tEleicao* eleicao);

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada. 
 */
void RealizaEleicao(tEleicao* eleicao);

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao* eleicao);
