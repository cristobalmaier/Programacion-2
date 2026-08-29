// dado un numero, desde ese numero hasta 0, acumular los numeros pares

#include <stdio.h>

int acumular(int num) {
    // Caso base
    if (num <= 0) {
        return 0;
    }

    // Caso general
    if (num % 2 == 0) {
        return num + acumular(num - 1);
    }

    // Si es impar
    return acumular(num - 1);
}

int main() {
    int num;

    printf("Ingrese su numero: ");
    scanf("%d", &num);

    printf("La suma es: %d", acumular(num));

    return 0;
}

