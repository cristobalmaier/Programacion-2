#include <stdio.h>

int main()
{
    int letra;
    int cont = 1;

    printf("Ingresar una oracion terminada en punto: ");

    letra = getchar();

    while (letra != '.') {

        if (letra >= 'a' && letra <= 'z') {
            if (cont % 2 == 0) {
                letra -= 32;
            }
            cont++;
        }
        else if (letra >= 'A' && letra <= 'Z') {
            if (cont % 2 != 0) {
                letra += 32;
            }
            cont++;
        }

        if (letra == ' ') {
            putchar(letra);
            letra = getchar();

            while (letra == ' ') {
                letra = getchar();
            }
        }
        else {
            putchar(letra);
            letra = getchar();
        }
    }

    putchar(letra);

    return 0;
}
