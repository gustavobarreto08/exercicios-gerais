#include "data.h"
#include <stdio.h>
/**
 * @brief Inicializa uma data com os valores passados como parâmetro.
 * 
 * Esta função recebe como parâmetro o dia, mês e ano de uma data e inicializa a estrutura tData correspondente com esses valores.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @param data Ponteiro para a estrutura tData que será inicializada.
 */
void InicializaDataParam( int dia, int mes, int ano, tData *data){
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
}

/**
 * @brief Lê uma data do usuário.
 * 
 * Esta função lê do usuário o dia, mês e ano de uma data e armazena esses valores na estrutura tData correspondente.
 * 
 * @param data Ponteiro para a estrutura tData que será preenchida com os valores lidos.
 */
void LeData( tData *data ){
    int dia,mes,ano;
    scanf("%d",&dia);
    scanf("%d",&mes);
    scanf("%d",&ano);
    if(mes<1){
        mes = 1;
    }
    if(mes>12){
        mes = 12;
    }
    InicializaDataParam(dia,mes,ano,data);
    if(dia<1){
        dia = 1;
    }
    if(dia>InformaQtdDiasNoMes(data)){
        dia = InformaQtdDiasNoMes(data);
    }
    InicializaDataParam(dia,mes,ano,data);
}

/**
 * @brief Imprime uma data na tela.
 * 
 * Esta função recebe como parâmetro uma estrutura tData e imprime na tela o dia, mês e ano correspondentes.
 * 
 * @param data Ponteiro para a estrutura tData que será impressa.
 */
void ImprimeData( tData *data ){
    printf("'%02d/%02d/%d'", data->dia, data->mes, data->ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * Esta função recebe como parâmetro uma estrutura tData e verifica se o ano correspondente é bissexto.
 * 
 * @param data Ponteiro para a estrutura tData que será verificada.
 * @return 1 se o ano é bissexto, 0 caso contrário.
 */
int EhBissexto( tData *data ){
    if(data->ano%4==0){
        if(data->ano%100==0){
            if(data->ano%400==0){
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 0;
}

/**
 * @brief Informa a quantidade de dias no mês de uma data.
 * 
 * Esta função recebe como parâmetro uma estrutura tData e informa a quantidade de dias no mês correspondente.
 * 
 * @param data Ponteiro para a estrutura tData que será verificada.
 * @return Quantidade de dias no mês correspondente.
 */
int InformaQtdDiasNoMes( tData *data ){
    int mes = data->mes;
    if(mes==1){
        return 31;
    }
    if(mes==2){
        if(EhBissexto(data)){
            return 29;
        }else{
            return 28;
        }
    }
    if(mes==3){
        return 31;
    }
    if(mes==4){
        return 30;
    }
    if(mes==5){
        return 31;
    }
    if(mes==6){
        return 30;
    }
    if(mes==7){
        return 31;
    }
    if(mes==8){
        return 31;
    }
    if(mes==9){
        return 30;
    }
    if(mes==10){
        return 31;
    }
    if(mes==11){
        return 30;
    }
    if(mes==12){
        return 31;
    }
}

/**
 * @brief Avança uma data para o dia seguinte.
 * 
 * Esta função recebe como parâmetro uma estrutura tData e avança a data correspondente para o dia seguinte.
 * 
 * @param data Ponteiro para a estrutura tData que será avançada.
 */
void AvancaParaDiaSeguinte( tData *data ){
    if(data->dia+1<=InformaQtdDiasNoMes(data)){
        data->dia++;
    }else{
        data->dia = 1;
        if(data->mes+1<=12){
            data->mes++;
        }else{
            data->mes = 1;
            data->ano++;
        }
    }
}

/**
 * @brief Verifica se duas datas são iguais.
 * 
 * Esta função recebe como parâmetro duas estruturas tData e verifica se elas representam a mesma data.
 * 
 * @param data1 Ponteiro para a primeira estrutura tData que será comparada.
 * @param data2 Ponteiro para a segunda estrutura tData que será comparada.
 * @return 1 se as datas são iguais, 0 caso contrário.
 */
int EhIgual( tData *data1, tData *data2 ){
    if(data1->dia==data2->dia){
        if(data1->mes==data2->mes){
            if(data1->ano==data2->ano){
                return 1;
            }
        }
    }
    return 0;
}