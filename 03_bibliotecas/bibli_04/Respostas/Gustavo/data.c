#include "data.h"
#include <stdio.h>

int verificaBissexto(int ano){
    if(ano%100==0){
        if(ano%40==0){
            return 1;
        }
    }else{
        if(ano%4==0){
            return 1;
        }
    }
    return 0;
}

void imprimeData(int dia,int mes, int ano){
    printf("%02d/%02d/%d\n",dia,mes,ano);
}

void imprimeProximaData(int dia, int mes, int ano){
    if(dia+1 > numeroDiasMes(mes,ano)){
        if(mes+1 > 12){
            ano ++;
            dia = 1;
            mes = 1;
        }else{
            mes ++;
            dia = 1;
        }
    }
    else{
        dia ++;
    }
    imprimeData(dia,mes,ano);
}

int numeroDiasMes(int mes, int ano){
    switch(mes){
        case 1:
            return 31;
            break;

        case 2:
            if(verificaBissexto(ano)){
                return 29;
            }
            else{
                return 28;
            }
            break;

        case 3:
            return 31;
            break;

        case 4:
            return 30;
            break;

        case 5:
            return 31;
            break;

        case 6:
            return 30;
            break;

        case 7:
            return 31;
            break;

        case 8:
            return 31;
            break;

        case 9:
            return 30;
            break;

        case 10:
            return 31;
            break;

        case 11:
            return 30;
            break;

        case 12:
            return 31;
            break;

        default:
            return 0;
            break;
    }
}

int verificaDataValida(int dia, int mes, int ano){
    if(mes>=1 && mes<=12){
        if(dia>=1 && dia<=numeroDiasMes(mes,ano)){
            return 1;
        }
    }
    return 0;
}

void imprimeMesExtenso(int mes){
    switch(mes){
        case 1:
            printf("Janeiro");
            break;

        case 2:
            printf("Fevereiro");
            break;

        case 3:
            printf("Marco");
            break;

        case 4:
            printf("Abril");
            break;

        case 5:
            printf("Maio");
            break;

        case 6:
            printf("Junho");
            break;

        case 7:
            printf("Julho");
            break;

        case 8:
            printf("Agosto");
            break;

        case 9:
            printf("Setembro");
            break;

        case 10:
            printf("Outubro");
            break;

        case 11:
            printf("Novembro");
            break;

        case 12:
            printf("Dezembro");
            break;

        default:
            break;
    }
}

void imprimeDataExtenso(int dia, int mes, int ano){
    printf("%02d de ",dia);
    imprimeMesExtenso(mes);
    printf(" de %d\n", ano);
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    if(ano1>ano2){
        return 1;
    }
    else if(ano1==ano2){
        if(mes1>mes2){
            return 1;
        }
        else if(mes1==mes2){
            if(dia1>dia2){
                return 1;
            }
            else if(dia1==dia2){
                return 0;
            }
            else{
                return -1;
            }
        }
        else{
            return -1;
        }
    }
    else{
        return -1;
    }
}

int calculaDiasAteMes(int mes, int ano){
    int i,dias=0;
    for(i=1;i<mes;i++){
        dias += numeroDiasMes(i,ano);
    }
    return dias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    int i, dias = 0,diasData1 = 0, diasData2 = 0;
    if(comparaData(dia1,mes1,ano1,dia2,mes2,ano2)==1){
        for(i=ano2;i<ano1;i++){
            if(verificaBissexto(i)){
                diasData1 += 366;
            }else{
                diasData1 += 365;
            }
        }
        diasData1 += calculaDiasAteMes(mes1,ano1);
        diasData1 += dia1;
        diasData2 += calculaDiasAteMes(mes2,ano2);
        diasData2 += dia2;
        dias = diasData1 - diasData2;
    }
    else if(comparaData(dia1,mes1,ano1,dia2,mes2,ano2)==-1){
        for(i=ano1;i<ano2;i++){
            if(verificaBissexto(i)){
                diasData2 += 366;
            }else{
                diasData2 += 365;
            }
        }
        diasData2 += calculaDiasAteMes(mes2,ano2);
        diasData2 += dia2;
        diasData1 += calculaDiasAteMes(mes1,ano1);
        diasData1 += dia1;
        dias = diasData2 - diasData1;
    }
    return dias;
}