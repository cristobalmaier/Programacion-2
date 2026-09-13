#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct lista{
    int codmat;
    char nombre[15];
    struct lista *sig;
}nodo;

// Crear la lista
void crear(nodo *p){
    printf("Ingrese codigo de materia: ");
    scanf("%d", &p->codmat);
    if (p->codmat == 0){
        p->sig = NULL;
    }
    else{
        printf("Ingrese nombre: ");
        scanf("%s", p->nombre);

        p->sig = (nodo*)malloc(sizeof(nodo));

        crear(p->sig);
    }
}

// Mostrar la lista
void mostrar(nodo *p){
    if (p->sig == NULL){
        return;
    }
    else{
        printf("\nCodigo de materia: %d", p->codmat);
        printf("\nNombre: %s\n", p->nombre);

        p = p->sig;
        mostrar(p);
    }
}

// Mostrar alumnos de una materia
void alumnos_materia(nodo *p, int codigo){
    if (p->sig == NULL){
        return;
    }
    else{
        if (p->codmat == codigo){
            printf("\nAlumno: %s", p->nombre);
        }
        p = p->sig;
        alumnos_materia(p, codigo);
    }
}

// Mostrar codigo de materia con mas alumnos
void materia_mas_alumnos(nodo *p, int *maximo, int *codigo_maximo){
    int contador;
    int codigo_actual;

    if (p->sig == NULL){
        return;
    }
    else{
        codigo_actual = p->codmat;
        contador = 0;

        while (p->sig != NULL && p->codmat == codigo_actual){
            contador++;
            p = p->sig;
        }
        if (contador > *maximo){
            *maximo = contador;
            *codigo_maximo = codigo_actual;
        }
        materia_mas_alumnos(p, maximo, codigo_maximo);
    }
}

int main(){

    nodo *p;
    int codigo;
    int maximo = 0;
    int codigo_maximo = 0;

    p = (nodo*)malloc(sizeof(nodo));

    // Punto a
    crear(p);

    printf("\n--- LISTA COMPLETA ---\n");
    mostrar(p);

    // Punto b
    printf("\n\nIngrese codigo de materia a buscar: ");
    scanf("%d", &codigo);

    printf("\n--- ALUMNOS DE LA MATERIA ---\n");
    alumnos_materia(p, codigo);

    // Punto c
    materia_mas_alumnos(p, &maximo, &codigo_maximo);

    printf("\n\n--- MATERIA CON MAS ALUMNOS ---\n");
    printf("\nCodigo de materia: %d", codigo_maximo);
    printf("\nCantidad de alumnos: %d\n", maximo);

    return 0;
}
