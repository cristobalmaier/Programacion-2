#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct alumnos{
    char nombre[20];
    int legajo; 
    float nota; 
    struct alumnos *sig;
}nodo;

void crear(nodo *p_copia){
    printf("Ingrese nombre: ");
    scanf("%s", p_copia -> nombre);
    if (strcmp(p_copia -> nombre,"cristobal")==0){
        p_copia -> sig=NULL;
    }
    else{
        printf("Ingrese legajo: ");
        scanf("%d", &p_copia -> legajo);

        printf("Ingrese nota: ");
        scanf("%f", &p_copia -> nota);

        p_copia -> sig = (nodo*)malloc(sizeof(nodo));
        crear(p_copia -> sig);// aumenta para poder ir al otro nodo
    }
}

void mostrar(nodo *p){
    if (p -> sig==NULL){
        return;
    }
    else{
        printf("\nNombre: %s", p->nombre);
        printf("\nLegajo: %d", p->legajo);
        printf("\nNota: %f", p->nota);
        p = p -> sig;
        mostrar(p);
    }
}

void promedio(nodo *p, int *p_cont, float *p_acum){
    
    if (p -> sig == NULL){
        return;
    }
    else{
        *p_cont++;
        *p_acum += p -> nota;
        promedio(p, p_cont,p_acum);
    }
}

int main(){
    nodo *p;
    int i,cont;
    float acum = 0;
    p = NULL;
    p = (nodo*)malloc(sizeof(nodo)); // GUARDA EL ESPACIO DE MEMORIA PARA LA ESTRUCTURA
    crear(p);
    mostrar(p);
    promedio(p,&cont,&acum);
    if (cont != 0){
        printf("Promedio: %.2f", (float)acum/cont);
    }else{
        printf("SOS CRACK");
    }
    
    return 0;
}
