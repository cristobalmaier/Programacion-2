// Dado un array de números enteros ordenado de menor a mayor,
// escribe una función en C que elimine todos los elementos duplicados de modo que cada elemento aparezca solo una vez.
// La función debe modificar el array directamente mediante punteros y devolver la nueva longitud del array sin duplicados.
// Los elementos que queden más allá de la nueva longitud no importan.

#include <stdio.h>

void cargar(int *puntero, int n){
    int i;

    for (i = 0; i < n; i++){
        printf("Ingrese el valor: ");
        scanf("%d", puntero);
        puntero++;
    }
}

void mostrar(int *puntero, int nueva_longitud){
    int i;

    for (i = 0; i < nueva_longitud; i++){
        printf("%d\n", *puntero);
        puntero++;
    }
}

int comparar(int *puntero, int n){
    int i;
    int j = 0;

    for (i = 1; i < n; i++){

        if (*(puntero + i) != *(puntero + j)){ // compara los valores del array por posiciones, si son iguales o distintos
            j++;
            *(puntero + j) = *(puntero + i);
        }
    }

    return j + 1;
}

int main(){

    int array[5], nueva_longitud;

    cargar(array, 5);
    nueva_longitud = comparar(array, 5);
    mostrar(array, nueva_longitud);
    printf("La longitud es: %d", nueva_longitud);

    return 0;
}
