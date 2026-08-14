#include <stdio.h>

void cargar(int mat[3][3]){
    int i,j;
    for (i=0 ; i < 3; i++){
        for (j = 0; j < 3; j++){
            printf("Ingrese el valor: ");
            scanf("%d",&mat[i][j]);
        }
    }
}

void mostrar(int mat[3][3]){
    int i,j;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int sumatoriaFila2 (int mat[3][3]){
    int j;
    int acum = 0;
    for (j = 0; j < 3; j++){
        acum += mat[1][j];
    }
    return acum;
}

int mayorColumna2(int mat[3][3]){
    int i;
    int max = mat[0][1];
    
    for (i = 0; i < 3; i++){
        if (mat[i][1] > max){
            max = mat[i][1];
        }
    }
    return max;
}

void promedioMultiples5(int mat[3][3]){
    int i,j;
    float contador = 0, acum = 0;
    
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if (mat[i][j] % 5 == 0){
                acum += mat[i][j];
                contador++;
            }
        }
    }
    if (contador > 0){
        float promedio = acum / contador;
        printf("El promedio de multiplos de 5 es: %.2f\n", promedio);
    }else{
        printf("NO HAY MULTIPLOS DE 5\n");
    }
}

int sumatoriaDiagonalPrincipal(int mat[3][3]){
    int i;
    int acum = 0;
    
    for (i = 0; i < 3; i++){
        acum += mat[i][i];
    }
    return acum;
}

void minimoPorFila(int mat[3][3]){
    int i,j,min;
    
    for (i = 0; i < 3; i++){
        min = mat[i][0];
        for (j = 0; j < 3; j++){
            if (mat [i][j] < min){
                min = mat [i][j];
            }
        }
        printf("El minimo de la fila %d es: %d\n", i + 1, min);
    }
}

void mostrarDiagonalSecundaria(int mat[3][3]){
    int i;
    printf("Elementos de la diagonal Secundaria: ");
    for (i = 0; i < 3; i++){
        printf("%d ", mat[i][2 - i]);
    }
    printf("\n");
    
}

int main()
{
    int mat[3][3];
    
    cargar(mat);
    mostrar(mat);
    
    printf("a) Sumatoria de la 2da fila: %d\n", sumatoriaFila2(mat));
    printf("b) Mayor elemento de la 2da columna: %d\n", mayorColumna2(mat));
    promedioMultiples5(mat);
    printf("d) Sumatoria de la diagonal principal: %d\n", sumatoriaDiagonalPrincipal(mat));
    minimoPorFila(mat);
    mostrarDiagonalSecundaria(mat);
    return 0;
}
