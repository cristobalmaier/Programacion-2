//ULTIMO PUNTO DEL PRIMER EJERCICIO NO SE HACE


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

int sumatoria(int mat[3][3]){
    int i,j,acum = 0;
    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
            if (i == 1){
            acum += mat[i][j];
            printf("La sumatoria de los elementos de la 2°fila es: %d\n", acum);
            }
        }
    }
    return acum;
}


// SEGUIR ACA
int mayor(int mat[3][3]){
    int i,j,max,posmax;
    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
            if (j ==2){
                
            }
        }
        
    }
}

int main()
{
    int mat[3][3];
    cargar(mat);
    mostrar(mat);
    sumatoria(mat);
    return 0;
}
