#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct alumnos{
    char nombre[20];
    int legajo; 
    float nota; 
    struct alumnos *sig;
}nodo;

typedef struct alumnos2{
    char nombre[20]; 
    struct alumnos2 *sig;
}nodo2;

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
        crear(p_copia -> sig);
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
        (*p_cont)++;
        *p_acum += p -> nota;
        promedio(p -> sig, p_cont,p_acum);
    }
}

// crear una nueva lista con los alumnos cuya nota sea superior a 7
void alumnos_mayor_7(nodo *p, nodo *p_7){
    if (p -> sig == NULL){
        p_7 -> sig = NULL;
    }
    else{
        if (p -> nota > 7){
            strcpy(p_7 -> nombre, p -> nombre);
            p_7 -> legajo = p -> legajo;
            p_7 -> nota = p -> nota;
            p_7 -> sig = (nodo*)malloc(sizeof(nodo)); //creo espacio en memoria
            p_7 = p_7 -> sig; //aumento a donde apunta p_7 si se da que p -> nota > 7.
        }
        alumnos_mayor_7(p -> sig, p_7);
    }
}

void legajo_par(nodo *p, nodo *p_legajo_par){
    if (p -> sig == NULL){
        p_legajo_par -> sig = NULL;
    }
    else{
        if (p -> legajo % 2 == 0 ){
            strcpy(p_legajo_par -> nombre, p -> nombre);
            p_legajo_par -> legajo = p -> legajo;
            p_legajo_par -> nota = p -> nota;
            p_legajo_par -> sig = (nodo*)malloc(sizeof(nodo)); //creo espacio en memoria
            p_legajo_par = p_legajo_par -> sig; //aumento a donde apunta p_legajo_par si se da que p -> nota % 2 == 0.
        }
        legajo_par(p -> sig, p_legajo_par);
    }
}

// crear una nueva lista con los alumnos cuya nota sea igual a 2
void alumnos_2(nodo *p, nodo2 *p_2){
    if (p -> sig == NULL){
        p_2 -> sig = NULL;
    }
    else{
        if (p -> nota == 2){
            strcpy(p_2 -> nombre, p -> nombre);
            printf("\n Nombre: %s", p_2 -> nombre);
            p_2 -> sig = (nodo2*)malloc(sizeof(nodo2)); //creo espacio en memoria
            p_2 = p_2 -> sig; //aumento a donde apunta p_2 si se da que p -> nota == 2.
        }
        alumnos_2(p -> sig, p_2);
    }
}

int main(){
    nodo *p,*p_7,*p_legajo_par;
    nodo2 *p_2;
    int i,cont = 0;
    float acum = 0;
    p = NULL;
    p_7 = NULL;
    p_2 = NULL;
    p_legajo_par = NULL;
    p = (nodo*)malloc(sizeof(nodo)); // GUARDA EL ESPACIO DE MEMORIA PARA LA ESTRUCTURA
    p_7 = (nodo*)malloc(sizeof(nodo)); // GUARDA EL ESPACIO DE MEMORIA PARA LA ESTRUCTURA
    p_legajo_par = (nodo*)malloc(sizeof(nodo));
    p_2 = (nodo2*)malloc(sizeof(nodo2)); // GUARDA EL ESPACIO DE MEMORIA PARA LA ESTRUCTURA
    
    crear(p);
    mostrar(p);
    promedio(p,&cont,&acum);
    if (cont != 0){
        printf("\nPromedio: %.2f", (float)acum/cont);
        alumnos_mayor_7(p, p_7);
        printf("\n ---- Alumnos con nota mayor a 7 ----");
        mostrar(p_7);
        
        printf("\n ---- Alumnos con nota igual a 2 ----");
        alumnos_2(p, p_2);
        
        legajo_par(p,p_legajo_par);
        printf("\n --- Alumnos con legajos pares ---");
        mostrar(p_legajo_par);
    }else{
         printf("momo");
    }
    return 0;
}
