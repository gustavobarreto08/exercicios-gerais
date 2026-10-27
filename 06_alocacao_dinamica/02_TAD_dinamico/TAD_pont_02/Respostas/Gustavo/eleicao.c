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
    eleicao->totalEleitores = 0;
    eleicao->totalGovernadores = 0;
    eleicao->totalPresidentes = 0;
    eleicao->presidentes = malloc(MAX_CANDIDATOS_POR_CARGO*sizeof*(eleicao->presidentes));
    eleicao->governadores = malloc(MAX_CANDIDATOS_POR_CARGO*sizeof*(eleicao->governadores));
    eleicao->eleitores = malloc(MAX_ELEITORES*sizeof*(eleicao->eleitores));
    scanf("%d",&qtdcandidatos);
    for(int i = 0; i<qtdcandidatos; i++){
        char cargo;
        candidatoaux = CriaCandidato();
        LeCandidato(candidatoaux);
        cargo = ObtemCargo(candidatoaux);
        if(cargo=='P'){
            (eleicao->presidentes[eleicao->totalPresidentes]) = candidatoaux; 
            eleicao->totalPresidentes++;
        }else if(cargo=='G'){
            (eleicao->governadores[eleicao->totalGovernadores]) = candidatoaux;
            eleicao->totalGovernadores++;
        }
    }
    return eleicao;
}


void ApagaEleicao(tEleicao* eleicao){
    for(int i = 0; i<eleicao->totalPresidentes; i++){
        ApagaCandidato(eleicao->presidentes[i]);
    }
    free(eleicao->presidentes);
    for(int i = 0; i<eleicao->totalGovernadores; i++){
        ApagaCandidato(eleicao->governadores[i]);
    }
    free(eleicao->governadores);
    for(int i = 0; i<eleicao->totalEleitores; i++){
        ApagaEleitor(eleicao->eleitores[i]);
    }
    free(eleicao->eleitores);
    free(eleicao);
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada. 
 */
void RealizaEleicao(tEleicao* eleicao){
    int qtdeleitores;
    scanf("%d",&qtdeleitores);
    for(int i = 0; i<qtdeleitores; i++){
        eleicao->eleitores[i] = CriaEleitor();
        LeEleitor(eleicao->eleitores[i]);
        eleicao->totalEleitores++;
    }
    for(int i = 0; i<qtdeleitores; i++){
        int votoP, votoG;
        for(int q = 0; q<qtdeleitores; q++){
            if(q!=i){
                if(EhMesmoEleitor(eleicao->eleitores[q],eleicao->eleitores[i])){
                    printf("ELEICAO ANULADA\n");
                    ApagaEleicao(eleicao);
                    exit(1);
                }
            }
        }
        votoP = ObtemVotoPresidente(eleicao->eleitores[i]);
        for(int q = 0; q<eleicao->totalPresidentes; q++){
            if(votoP==0){
                eleicao->votosBrancosPresidente++;
                break;
            }
            if(VerificaIdCandidato(eleicao->presidentes[q],votoP)){
                IncrementaVotoCandidato(eleicao->presidentes[q]);
                break;
            }
            if(q==eleicao->totalPresidentes-1){
                eleicao->votosNulosPresidente++;
            }
        }
        votoG = ObtemVotoGovernador(eleicao->eleitores[i]);
        for(int q = 0; q<eleicao->totalGovernadores; q++){
            if(votoG==0){
                eleicao->votosBrancosGovernador++;
                break;
            }
            else if(VerificaIdCandidato(eleicao->governadores[q],votoG)){
                IncrementaVotoCandidato(eleicao->governadores[q]);
                break;
            }
            else if(q==eleicao->totalGovernadores-1){
                eleicao->votosNulosGovernador++;
            }
        }
    }
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao* eleicao){
    int empategov = 0;
    int empatepre = 0;
    int qtdvotosP = 0;
    int qtdvotosG = 0;
    int qtdVotosInvalidosG = 0;
    int qtdVotosInvalidosP = 0;
    int brancosTotais;
    int nulosTotais;
    float percentualPresidente;
    float percentualGovernador;
    tCandidato *govEleito;
    tCandidato *preEleito;
    for(int i = 0; i<eleicao->totalGovernadores; i++){
        qtdvotosG += eleicao->governadores[i]->votos;
    }
    qtdvotosG += eleicao->votosBrancosGovernador;
    qtdvotosG += eleicao->votosNulosGovernador;
    qtdVotosInvalidosG += eleicao->votosBrancosGovernador;
    qtdVotosInvalidosG += eleicao->votosNulosGovernador;
    for(int i = 0; i<eleicao->totalPresidentes; i++){
        qtdvotosP += eleicao->presidentes[i]->votos;
    }
    qtdvotosP += eleicao->votosBrancosPresidente;
    qtdvotosP += eleicao->votosNulosPresidente;
    qtdVotosInvalidosP += eleicao->votosBrancosPresidente;
    qtdVotosInvalidosP += eleicao->votosNulosPresidente;
    for(int i = 0; i<=eleicao->totalPresidentes-1; i++){
        if(i==0){
            preEleito = eleicao->presidentes[i];
        }
        if(i==2){
            break;
        }
        if(ObtemVotos(preEleito)<ObtemVotos(eleicao->presidentes[i+1])){
            preEleito = eleicao->presidentes[i+1];
        }else if(ObtemVotos(preEleito)==ObtemVotos(eleicao->presidentes[i+1])){
            if(EhMesmoCandidato(preEleito,eleicao->presidentes[i+1])){
                continue;
            }else if(qtdVotosInvalidosP<=ObtemVotos(preEleito)){
                printf("- PRESIDENTE ELEITO: EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
                empatepre = 1;
                break;
            }
        }
    }
    for(int i = 0; i<=eleicao->totalGovernadores-1; i++){
        if(i==0){
            govEleito = eleicao->governadores[i];
        }
        if(i==2){
            break;
        }
        if(ObtemVotos(govEleito)<ObtemVotos(eleicao->governadores[i+1])){
            govEleito = eleicao->governadores[i+1];
        }else if(ObtemVotos(govEleito)==ObtemVotos(eleicao->governadores[i+1])){
            if(EhMesmoCandidato(govEleito,eleicao->governadores[i+1])){
                continue;
            }else if(qtdVotosInvalidosG<=ObtemVotos(govEleito)){
                printf("- GOVERNADOR ELEITO: EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
                empategov = 1;
                break;
            }
        }
    }
    if(qtdVotosInvalidosP>ObtemVotos(preEleito)){
            printf("- PRESIDENTE ELEITO: SEM DECISAO\n");
            empatepre = 1;
            ApagaEleicao(eleicao);
    }
    if(qtdVotosInvalidosG>ObtemVotos(govEleito)){
            printf("- GOVERNADOR ELEITO: SEM DECISAO\n");
            ApagaEleicao(eleicao);
            empategov = 1;
    }
    percentualGovernador = CalculaPercentualVotos(govEleito,qtdvotosG);
    percentualPresidente = CalculaPercentualVotos(preEleito,qtdvotosP);
    brancosTotais = eleicao->votosBrancosGovernador + eleicao->votosBrancosPresidente;
    nulosTotais = eleicao->votosNulosGovernador + eleicao->votosNulosPresidente;
    if(!empatepre){
        printf("- PRESIDENTE ELEITO: ");
        ImprimeCandidato(preEleito,percentualPresidente);
    }
    if(!empategov){
        printf("- GOVERNADOR ELEITO: ");
        ImprimeCandidato(govEleito,percentualGovernador);
    }
    printf("- NULOS E BRANCOS: %d, %d", nulosTotais, brancosTotais);
}
