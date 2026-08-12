#include <stdio.h>

void cargar(int mat[3][3]){
    int i,j;
    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
            printf("Ingrese el valor: ");
            scanf("%d",&mat[i][j]);
        }
    }
}

void mostrar(int mat[3][3]){
    int i,j;
    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int mat[3][3];
    cargar(mat);
    mostrar(mat);
    return 0;
}
