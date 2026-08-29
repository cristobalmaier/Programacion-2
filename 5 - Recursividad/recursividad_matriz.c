// dado una matriz de n x n, cargarlas y mostrar la sumatoria de la diagonal principal con 2 funciones recursivas

#include <stdio.h>

void cargar(int mat[3][3],int i,int j){

    if (i >= 3){
        return;
    }

    printf("Ingrese el valor para [%d][%d]: ", i, j);
    scanf("%d", &mat[i][j]);

    j += 1;

    if (j >= 3){
        cargar(mat, i + 1, 0);
    }else{
        cargar(mat, i, j);
    }

}

int sumar_diagonal(int mat[3][3],int i){
    if (i >= 3){
        return 0;
    }
    return mat[i][i] + sumar_diagonal(mat,i+1);
}

int main()
{
    int mat[3][3];
    int resultado = 0;
    
    cargar(mat,0,0);
    resultado = sumar_diagonal(mat,0);
    
    printf("La sumatoria de la diagonal principal es: %d", resultado);
    return 0;
}
