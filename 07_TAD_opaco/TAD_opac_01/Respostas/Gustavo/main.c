#include "jogo.h"
#include <stdio.h>

int main(){
    do{
        tJogo *jogo = CriaJogo();
        ExecutaJogo(jogo);
        DestroiJogo(jogo);

    }while(ContinuaJogo());
    return 0;
}