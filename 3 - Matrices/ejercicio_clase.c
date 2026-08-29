#include <stdio.h>

int cargar (int vec[10]){
    int i,num;
    for (i = 0; i < 4; i++){
        printf("Ingrese un numero: ");
        scanf("%i", &vec[i]);
    }
    
    printf("Ingrese otro numero: ");
    scanf("%d", &num);
    
    while (num % 2 == 0 || num > vec[3]){
        vec[i] = num;
        i++;
        printf("Ingrese otro numero: ");
        scanf("%d", &num);
    }
    return i;
}

void mostrar(int vec[10]){
    int i;
    for (i = 0; i < tam; i ++){
        printf("%d\t", vec[i]);
    }
}

int sumar(int vec[10], int tam){
    int i,acum = 0;
    for (i = 0; i < tam; i ++){
        if (i % 2 != 0 ){
            acum += vec[i];
        }
    }
    return acum;
}

int multiplicar (int vec[10], int tam){
    int i, productoria = 1;
    for (i = 0; i < tam; i++){
        if (9 % vec[i] == 0){
            productoria *= vec[i];
        }
    }
    return productoria;
}

int minimo (int vec[10], int tam){
    int i, min = vec[0], posmin;
    for (i = 0; i < tam; i++){
        if (vec[i] < min){
            min = vec[i];
            posmin = i;
        }
    }
    return posmin;
}

int main()
{
    int vec[10], tam, resultado,posmin;
    tam = cargar(vec);
    mostrar(vec,tam);
    
    if (tam % 2 == 0){
        resultado = sumar(vec,tam);
    }else{
        resultado = multiplicar(vec,tam);
    }
    printf("El resultado es %d", &resultado);
    posmin = min(vec,tam)
    printf("El valor minimo es %d y esta en la pos %d", vec[posmin], posmin);
    return 0;
}
