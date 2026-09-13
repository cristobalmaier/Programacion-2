#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct lista{
    int DNI;
    char nombre [15];
    float saldo;
    struct lista *sig;
}nodo;

typedef struct lista2{
        float saldo;
        struct lista2 *sig;
}nodo2;

void crear(nodo *p){
    printf("Ingrese DNI: ");
    scanf("%d", &p -> DNI);
    if (p -> DNI == 0){
        p -> sig = NULL;
    }
    else{
        printf("Ingrese nombre: ");
        scanf("%s", p -> nombre);

        printf("Ingrese saldo: ");
        scanf("%f", &p -> saldo);

        p -> sig = (nodo*)malloc(sizeof(nodo));
        crear(p -> sig);
    }
}

void mostrar(nodo *p){
    if (p -> sig == NULL){
        return;
    }
    else{
        printf("\nDNI: %d", p -> DNI);
        printf("\nNombre: %s", p -> nombre);
        printf("\nSaldo: %.2f", p -> saldo);
        p = p -> sig;
        mostrar(p);
    }
}

//nueva lista para saldos negativos
void saldos_negativos(nodo*p, nodo2 *p_saldo_negativo){
    if (p -> sig == NULL){
        p_saldo_negativo -> sig == NULL;
    }
    else{
        if (p -> saldo < 0){
            p_saldo_negativo -> saldo = p -> saldo;
            printf("Saldo: %.2f", p_saldo_negativo -> saldo);
            p_saldo_negativo -> sig = (nodo2*)malloc(sizeof(nodo2));
            p_saldo_negativo = p_saldo_negativo -> sig;
        }
        saldos_negativos(p -> sig, p_saldo_negativo);
    }
}

int main(){
    nodo *p;
    nodo2 *p_saldo_negativo;

    p = (nodo*)malloc(sizeof(nodo));
    p_saldo_negativo = (nodo2*)malloc(sizeof(nodo2));
    
    crear(p);
    mostrar(p);
    printf("\n---Lista con los saldos negativos ---");
    saldos_negativos(p, p_saldo_negativo);
}
