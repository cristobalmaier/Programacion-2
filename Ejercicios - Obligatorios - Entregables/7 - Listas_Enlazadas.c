#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct alumnos{
    char nombre[20];
    int edad;
    struct alumnos *sig;
}nodo;

typedef struct alumnos2{
    char nombre[20];
    struct alumnos2 *sig;
}nodo2;

// Crear la lista original
void crear(nodo *p){

    printf("Ingrese nombre: ");
    scanf("%s", p->nombre);

    // Si se ingresa "FIN", llegamos al final de la lista.
    if (strcmp(p->nombre, "FIN") == 0){
        p->sig = NULL;
    }
    else{
        printf("Ingrese edad: ");
        scanf("%d", &p->edad);

        // Creo espacio en memoria para el siguiente nodo.
        p->sig = (nodo*)malloc(sizeof(nodo));

        // Sigo cargando la lista.
        crear(p->sig);
    }
}

// Mostrar la lista
void mostrar(nodo *p){
    if (p->sig == NULL){
        return;
    }
    else{
        printf("\nNombre: %s", p->nombre);
        printf("\nEdad: %d", p->edad);

        // Avanzo al siguiente nodo de la lista.
        p = p->sig;

        // Sigo mostrando la lista.
        mostrar(p);
    }
}

// Calcular promedio de edad
void promedio_edad(nodo *p, int *p_cont, float *p_acum){
    if (p->sig == NULL){
        return;
    }
    else{
        (*p_cont)++;
        *p_acum += p->edad;

        // Sigo recorriendo la lista original.
        promedio_edad(p->sig, p_cont, p_acum);
    }
}

// Crear una nueva lista con los alumnos cuya edad está entre 40 y 50 años.
void edad_entre_40_50(nodo *p, nodo *p_40_50){
    if (p->sig == NULL){
        p_40_50->sig = NULL;
    }
    else{
        if (p->edad >= 40 && p->edad <= 50){
            
            // Copio los datos del alumno a la nueva lista.
            strcpy(p_40_50->nombre, p->nombre);
            p_40_50->edad = p->edad;

            // Creo espacio para el próximo nodo de la nueva lista.
            p_40_50->sig = (nodo*)malloc(sizeof(nodo));

            // Avanzo al siguiente nodo de la nueva lista.
            p_40_50 = p_40_50->sig;
        }
        // sigo recorriendo la lista original.
        edad_entre_40_50(p->sig, p_40_50);
    }
}

// Generar otra lista con los nombres solamente de aquellos alumnos cuya edad es menor a 30.
void edad_menor_30(nodo *p, nodo2 *p_menor_30){
    if (p->sig == NULL){
        p_menor_30->sig = NULL;
    }
    else{
        if (p->edad < 30){

            // Copio solamente el nombre porque el enunciado no pide guardar la edad.
            strcpy(p_menor_30->nombre, p->nombre);
            printf("\nNombre: %s", p_menor_30->nombre);

            // Creo espacio para el próximo nodo de la nueva lista.
            p_menor_30->sig = (nodo2*)malloc(sizeof(nodo2));
            
            // Avanzo al siguiente nodo de la nueva lista.
            p_menor_30 = p_menor_30->sig;
        }
        // Sigo recorriendo la lista original.
        edad_menor_30(p->sig, p_menor_30);
    }
}

// Contar la cantidad de alumnos cuya edad está entre 20 y 35 años sobre la lista original.
void edad_entre_20_35(nodo *p, int *p_cont_20_35){
    if (p->sig == NULL){
        return;
    }
    else{
        if (p->edad >= 20 && p->edad <= 35){
            (*p_cont_20_35)++;
        }
        // Sigo recorriendo la lista original.
        edad_entre_20_35(p->sig, p_cont_20_35);
    }
}

int main(){
    // Punteros para la lista original y las nuevas listas.
    nodo *p, *p_40_50;

    // Puntero para la lista que solamente contiene nombres.
    nodo2 *p_menor_30;

    int cont = 0;
    float acum = 0;
    int cont_20_35 = 0;

    // Creo espacio en memoria para el primer nodo de la lista original.
    p = (nodo*)malloc(sizeof(nodo));

    // Creo espacio en memoria para el primer nodo de la nueva lista de alumnos entre 40 y 50.
    p_40_50 = (nodo*)malloc(sizeof(nodo));

    // Creo espacio en memoria para el segundo nodo de la nueva lista de menores a 30.
    p_menor_30 = (nodo2*)malloc(sizeof(nodo2));

    crear(p);

    printf("\n--- LISTA ORIGINAL ---");
    mostrar(p);

    promedio_edad(p, &cont, &acum);

    // Verifico que se haya ingresado al menos un alumno.
    if (cont != 0){

        printf("\n\nPromedio de edad: %.2f", acum / cont);

        // Crear nueva lista con alumnos entre 40 y 50.
        edad_entre_40_50(p, p_40_50);

        printf("\n\n--- ALUMNOS ENTRE 40 Y 50 AÑOS ---");
        mostrar(p_40_50);

        // Crear y mostrar lista de nombres de alumnos menores a 30.
        printf("\n\n--- ALUMNOS MENORES A 30 AÑOS ---");
        edad_menor_30(p, p_menor_30);

        // Contar alumnos cuya edad está entre 20 y 35.
        edad_entre_20_35(p, &cont_20_35);

        // Mostrar cantidad de alumnos entre 20 y 35.
        printf("\n\n--- CANTIDAD DE ALUMNOS ENTRE 20 Y 35 AÑOS ---");
        printf("\nCantidad: %d", cont_20_35);
    }
    else{
        printf("\nNo se ingresaron alumnos.");
    }
    return 0;
}