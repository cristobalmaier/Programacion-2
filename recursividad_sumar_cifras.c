// dado un numero de 3 cifras, sumarlas entre si

#include <stdio.h>

int sumar_cifras(int num) {
    
    // caso base
    if (num < 10) {
        return num;
    }

    // caso general
    return num % 10 + sumar_cifras(num / 10);

}

int main() {
    int num;

    printf("Ingrese un numero de 3 cifras: ");
    scanf("%d", &num);

    printf("La suma es: %d", sumar_cifras(num));

    return 0;
}
