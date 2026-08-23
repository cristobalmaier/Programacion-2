#include <stdio.h>
#include <string.h>

int main()
{
    char nombre[5][20], nombre_max[20];
    int notas[5],i,max_nota;
    max_nota = notas[0];

    strcpy(nombre_max, nombre[0]);

    for (i = 0; i < 5; i++){
        printf("Ingrese su nombre: ");
        scanf("%s", nombre[i]);

        printf("Ingrese su nota: ");
        scanf("%d", &notas[i]);
    }

    for (i = 0; i < 5; i++){
        if (notas[i] > max_nota){
            strcpy(nombre_max, nombre[i]);
            max_nota = notas[i];
        }
    }

    printf("El abanderado es: %s con nota: %d\n", nombre_max,max_nota);

    if (strcmp(nombre_max, "Lucas") == 0){
        printf("SI el abanderado es Lucas!");
    }else{
        printf("NO es lucas el abanderado");
    }

    return 0;
}
