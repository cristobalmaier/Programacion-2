#include <stdio.h>
#include <string.h>

int main()
{
    int letra, posicion = 0, cont_vocales_par = 0;
    int siguiente;

    printf("Ingrese un texto: ");

    letra = getchar();

    while (letra != '\n'){
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u'){
            if (posicion % 2 == 0){
                cont_vocales_par++;
            }
        }

        posicion++;

        if (letra == 'a'){
            siguiente = getchar();

            if (siguiente == 's'){
                putchar('A');
                putchar('S');

                letra = getchar();
            }else{
                putchar(letra);

                if (siguiente != '\n'){
                    if (siguiente == ' '){
                        putchar(' ');
                        putchar(' ');
                        putchar(' ');
                        putchar(' ');
                    }else{
                        putchar(siguiente);
                    }

                    letra = getchar();
                }
                else
                {
                    letra = siguiente;
                }
            }
        }
        else if (letra == ' ')
        {
            // Mostrar 4 espacios entre palabras
            putchar(' ');
            putchar(' ');
            putchar(' ');
            putchar(' ');

            letra = getchar();
        }
        else
        {
            putchar(letra);
            letra = getchar();
        }
    }

    printf("\nCantidad de vocales en posicion par: %d", cont_vocales_par);

    return 0;
}
