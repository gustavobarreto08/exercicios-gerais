#include "temperature_conversor.h"

float converte_celsius_para_kelvin(float temperatura){
    temperatura += 273.15;
    return temperatura;
}

float converte_celsius_para_fahrenheit(float temperatura){
    temperatura = temperatura *(9.0/5.0) + 32;
    return temperatura;
}

float converte_kelvin_para_celsius(float temperatura){
    temperatura -= 273.15;
    return temperatura;
}

float converte_kelvin_para_fahrenheit(float temperatura){
    temperatura = (temperatura - 273.15)*(9.0/5.0) + 32;
    return temperatura;
}

float converte_fahrenheit_para_celsius(float temperatura){
    temperatura = (temperatura-32)*(5.0/9.0);
    return temperatura;
}

float converte_fahrenheit_para_kelvin(float temperatura){
    temperatura = (temperatura-32)*(5.0/9.0)+273.15;
    return temperatura;
}