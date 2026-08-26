#include <stdio.h>
#include <string.h>

int fact(int num){
    int resultado;
    // caso base (condicion de corte)
    if (num == 0){
        return 1;
    }
    
    // caso general (recursividad)
    resultado = num * fact(num - 1);
    return resultado;
}

int main()
{
    int num = 5;
    printf("%d",fact(num));

    return 0;
}
