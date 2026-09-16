#include "temperature_conversor.h"
#include <stdio.h>

int main(){
    float temperatura;
    char entrada,saida;
    scanf("%f %c %c",&temperatura, &entrada, &saida);
    if(entrada=='c'){
        if(saida=='k'){
            temperatura = converte_celsius_para_kelvin(temperatura);
            printf("Temperatura: %.2fK",temperatura);
        }
        if(saida=='f'){
            temperatura = converte_celsius_para_fahrenheit(temperatura);
            printf("Temperatura: %.2fFº",temperatura);
        }
    }
    if(entrada=='k'){
        if(saida=='c'){
            temperatura = converte_kelvin_para_celsius(temperatura);
            printf("Temperatura: %.2fCº",temperatura);
        }
        if(saida=='f'){
            temperatura = converte_kelvin_para_fahrenheit(temperatura);
            printf("Temperatura: %.2fFº",temperatura);
        }
    }
    if(entrada=='f'){
        if(saida=='k'){
            temperatura = converte_fahrenheit_para_kelvin(temperatura);
            printf("Temperatura: %.2fK",temperatura);
        }
        if(saida=='c'){
            temperatura = converte_fahrenheit_para_celsius(temperatura);
            printf("Temperatura: %.2fCº",temperatura);
        }
    }
    return 0;
}