#include <stdio.h>
#include <string.h>

int main()
{
    int letra,cont = 0; // es lo mismo que poner char letra

    printf("Ingresar una opracion terminada en punto: ");
    
    letra = getchar();
    
    while (letra != '\n'){

        if (letra != 'a' && letra != 'e' && letra != 'i' && letra != 'o' && letra != 'u' && letra != ' ' && letra != '.'){
            cont++;
        }
        putchar(letra);
        letra = getchar();
    }

    putchar(letra);

    printf("\nCantidad de consonantes: %d", cont);

    return 0;
}
