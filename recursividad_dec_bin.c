#include <stdio.h>

void dec_a_binario(int num) {
    // Caso base 
    if (num < 2) {
        printf("%d", num);
        return;
    }

    // Caso general
    dec_a_binario(num / 2);
    printf("%d", num % 2);
}

int main() {
    int num;

    printf("Ingrese un numero decimal para pasar a binario: ");
    scanf("%d", &num);

    dec_a_binario(num);

    return 0;
}
