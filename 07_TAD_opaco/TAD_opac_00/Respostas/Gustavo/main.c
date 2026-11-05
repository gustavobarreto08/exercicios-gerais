#include "circulo.h"
#include <stdio.h>

int main(){
    tCirculo *c;
    tPonto *p;
    float x,y,raio;
    scanf("%f",&x);
    scanf("%f",&y);
    scanf("%f",&raio);
    c = Circulo_Cria(x,y,raio);
    scanf("%f",&x);
    scanf("%f",&y);
    p = Pto_Cria(x,y);
    if(Circulo_Interior(c,p)){
        printf("1\n");
    }else{
        printf("0\n");
    }
    Circulo_Apaga(c);
    Pto_Apaga(p);
    return 0;
}