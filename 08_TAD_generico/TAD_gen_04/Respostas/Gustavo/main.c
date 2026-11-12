#include "banco.h"

int main(){
    tBanco *banco = CriaBanco();
    LeBanco(banco);
    char c;
    int numa;
    while(1){
        scanf("%c\n", &c);

        if(c == 'A'){
            tAgencia *a = CriaAgencia();
            LeAgencia(a);
            AdicionaAgencia(banco,a);
        }
        if(c == 'C'){
            tConta *conta = CriaConta();
            LeConta(conta);
            scanf("%d", &numa);
            InsereContaBanco(banco,numa,conta);
        }
        if(c == 'F'){
            break;
        }
    }
    ImprimeRelatorioBanco(banco);
    DestroiBanco(banco);
    return 0;
}