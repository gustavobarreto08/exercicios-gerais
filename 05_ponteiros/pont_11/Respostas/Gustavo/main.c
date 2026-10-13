#include "calculadora.h"
#include <stdio.h>

float soma(float a, float b){
    return a+b;
}

float sub(float a, float b){
    return a-b;
}

float mult(float a,float b){
    return a*b;
}

float div(float a, float b){
    return a/b;
}

int main(){
    char op = '\0';
    float n1,n2;
    float resultado;
    while(op!='f'){
        scanf("%c",&op);
        scanf("%f %f",&n1,&n2);
        if(op=='a'){
            resultado = Calcular(n1,n2,soma);
            printf("%.2f + %.2f = %.2f\n",n1,n2,resultado);
        }
        else if(op=='s'){
            resultado = Calcular(n1,n2,sub);
            printf("%.2f - %.2f = %.2f\n",n1,n2,resultado);
        }
        else if(op=='m'){
            resultado = Calcular(n1,n2,mult);
            printf("%.2f x %.2f = %.2f\n",n1,n2,resultado);
        }
        else if(op=='d'){
            resultado = Calcular(n1,n2,div);
            printf("%.2f / %.2f = %.2f\n",n1,n2,resultado);
        }
    }
    return 0;
}