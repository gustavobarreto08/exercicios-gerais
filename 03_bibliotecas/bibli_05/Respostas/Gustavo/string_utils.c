#include "string_utils.h"

int string_length(char *str){
    int i = 0;
    while(str[i]!='\0'){
        i++;
    }
    i--;
    return i;
}

void string_copy(char *src, char *dest){
    int i = 0;
    while(src[i]!='\0'){
        dest[i] = src[i];
        i++;
    }
}

void string_upper(char *str){
    int i = 0;
    while(str[i]!='\0'){
        if(str[i]>='a' && str[i]<='z'){
            str[i] -= 32;
        }
        i++;
    }
}

void string_lower(char *str){
    int i = 0;
    while(str[i]!='\0'){
        if(str[i]>='A' && str[i]<='Z'){
            str[i] += 32;
        }
        i++;
    }
}

void string_reverse(char *str){
    int tam, i = 0;
    char aux;
    tam = string_length(str);
    if(tam%2==0){
        while(tam != (i+1)){
            aux = str[tam-1];
            str[tam-1] = str[i];
            str[i] = aux;
            tam--;
            i++;
        }
    }else{
        while(tam != i){
            aux = str[tam-1];
            str[tam-1] = str[i];
            str[i] = aux;
            tam--;
            i++;
        }
    }
}