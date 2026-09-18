#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
    int numero_legajo;
    char nombre[20];
    int edad;
    char carrera[20];
    int ano_cursando;
    struct lista *sig;
} nodo;


/* =========================
   CREAR LISTA
   ========================= */

void crear(nodo *p)
{
    printf("Ingrese numero legajo: ");
    scanf("%d", &p->numero_legajo);

    if (p->numero_legajo == 0)
    {
        p->sig = NULL;
    }
    else
    {
        printf("Ingrese nombre: ");
        scanf("%s", p->nombre);

        printf("Ingrese edad: ");
        scanf("%d", &p->edad);

        while (p->edad <= 17)
        {
            printf("Error! Ingrese edad mayor a 17 años: ");
            scanf("%d", &p->edad);
        }

        printf("Ingrese carrera (Seguridad o Inteligencia): ");
        scanf("%s", p->carrera);

        while (strcmp(p->carrera, "Seguridad") != 0 &&
               strcmp(p->carrera, "Inteligencia") != 0)
        {
            printf("Error! Ingrese carrera (Seguridad o Inteligencia): ");
            scanf("%s", p->carrera);
        }

        printf("Ingrese año de cursada: ");
        scanf("%d", &p->ano_cursando);

        p->sig = (nodo *)malloc(sizeof(nodo));

        crear(p->sig);
    }
}


/* =========================
   MOSTRAR LISTA
   ========================= */

void mostrar(nodo *p)
{
    if (p == NULL || p->numero_legajo == 0)
    {
        return;
    }
    else
    {
        printf("\nNumero legajo: %d", p->numero_legajo);
        printf("\nNombre: %s", p->nombre);
        printf("\nEdad: %d", p->edad);
        printf("\nCarrera: %s", p->carrera);
        printf("\nAño cursando: %d\n", p->ano_cursando);

        mostrar(p->sig);
    }
}


/* =========================
   NUEVA LISTA:
   INTELIGENCIA Y MAYOR A 2
   ========================= */

void alumnos_inteligencia_segundo_ano(nodo *p, nodo *p_inteligencia_2)
{
    if (p == NULL || p->numero_legajo == 0)
    {
        p_inteligencia_2->numero_legajo = 0;
        p_inteligencia_2->sig = NULL;
    }
    else
    {
        if (strcmp(p->carrera, "Inteligencia") == 0 &&
            p->ano_cursando > 2)
        {
            p_inteligencia_2->numero_legajo = p->numero_legajo;

            strcpy(p_inteligencia_2->nombre, p->nombre);

            p_inteligencia_2->edad = p->edad;

            strcpy(p_inteligencia_2->carrera, p->carrera);

            p_inteligencia_2->ano_cursando = p->ano_cursando;

            p_inteligencia_2->sig = (nodo *)malloc(sizeof(nodo));

            p_inteligencia_2 = p_inteligencia_2->sig;
        }

        alumnos_inteligencia_segundo_ano(p->sig, p_inteligencia_2);
    }
}


/* =========================
   PROMEDIO DE SEGURIDAD
   ========================= */

void promedio_seguridad(nodo *p, int *contador, int *total)
{
    if (p == NULL || p->numero_legajo == 0)
    {
        return;
    }

    (*total)++;

    if (strcmp(p->carrera, "Seguridad") == 0)
    {
        (*contador)++;
    }

    promedio_seguridad(p->sig, contador, total);
}


/* =========================
   ELIMINAR CABEZA
   ========================= */

nodo *eliminar1(nodo *p, int legajo)
{
    nodo *aux;

    if (p != NULL && p->numero_legajo == legajo)
    {
        aux = p->sig;

        free(p);

        p = aux;
    }

    return p;
}


/* =========================
   ELIMINAR CUALQUIER POSICION
   ========================= */

void eliminar2(nodo *p, int legajo)
{
    nodo *aux;

    while (p->sig != NULL)
    {
        if (p->sig->numero_legajo == legajo)
        {
            aux = p->sig->sig;

            free(p->sig);

            p->sig = aux;
        }
        else
        {
            p = p->sig;
        }
    }
}


/* =========================
   INSERTAR DELANTE DE LA CABEZA
   ========================= */

nodo *insertar1(nodo *p, int legajo)
{
    nodo *aux;

    if (p != NULL && p->numero_legajo == legajo)
    {
        aux = (nodo *)malloc(sizeof(nodo));

        aux->numero_legajo = 9999;

        strcpy(aux->nombre, "PEPE");

        aux->edad = 99;

        strcpy(aux->carrera, "Inteligencia");

        aux->ano_cursando = 0;

        aux->sig = p;

        p = aux;
    }

    return p;
}


/* =========================
   INSERTAR EN CUALQUIER POSICION
   ========================= */

void insertar2(nodo *p, int legajo)
{
    nodo *aux;

    while (p->sig != NULL)
    {
        if (p->sig->numero_legajo == legajo)
        {
            aux = (nodo *)malloc(sizeof(nodo));

            aux->numero_legajo = 9999;

            strcpy(aux->nombre, "PEPE");

            aux->edad = 99;

            strcpy(aux->carrera, "Inteligencia");

            aux->ano_cursando = 0;

            aux->sig = p->sig;

            p->sig = aux;

            return;
        }
        else
        {
            p = p->sig;
        }
    }
}


/* =========================
   MAIN
   ========================= */

int main()
{
    nodo *p;
    nodo *p_inteligencia_2;

    int legajo;
    int opc;

    int contador;
    int total;

    float promedio;

    p = (nodo *)malloc(sizeof(nodo));

    crear(p);


    do
    {
        printf("\n\n----- MENU -----\n");

        printf("1. Mostrar lista\n");
        printf("2. Mostrar alumnos de Inteligencia mayores a 2 años\n");
        printf("3. Calcular promedio de estudiantes de Seguridad\n");
        printf("4. Eliminar estudiante\n");
        printf("5. Insertar alumno antes de un legajo\n");
        printf("6. Salir\n");

        printf("Ingrese una opcion: ");
        scanf("%d", &opc);


        switch (opc)
        {
            /* =========================
               MOSTRAR
               ========================= */

            case 1:

                printf("\n--- LISTA ORIGINAL ---\n");

                mostrar(p);

                break;


            /* =========================
               INTELIGENCIA > 2
               ========================= */

            case 2:

                p_inteligencia_2 = (nodo *)malloc(sizeof(nodo));

                alumnos_inteligencia_segundo_ano(
                    p,
                    p_inteligencia_2
                );

                printf("\n--- ALUMNOS DE INTELIGENCIA MAYORES A 2 AÑOS ---\n");

                mostrar(p_inteligencia_2);

                break;


            /* =========================
               PROMEDIO SEGURIDAD
               ========================= */

            case 3:

                contador = 0;
                total = 0;

                promedio_seguridad(
                    p,
                    &contador,
                    &total
                );

                if (total > 0)
                {
                    promedio = (float)contador / total;

                    printf(
                        "\nPromedio de estudiantes que eligen Seguridad: %.2f\n",
                        promedio
                    );
                }
                else
                {
                    printf("\nNo hay estudiantes cargados.\n");
                }

                break;


            /* =========================
               ELIMINAR
               ========================= */

            case 4:

                printf("\nIngrese legajo a eliminar: ");
                scanf("%d", &legajo);

                /*
                   Primero intentamos eliminar
                   la cabeza.
                */

                p = eliminar1(p, legajo);

                /*
                   Si la cabeza no era el legajo,
                   buscamos en el resto de la lista.
                */

                if (p != NULL)
                {
                    eliminar2(p, legajo);
                }

                printf("\n--- LISTA ACTUALIZADA ---\n");

                mostrar(p);

                break;


            /* =========================
               INSERTAR
               ========================= */

            case 5:

                printf(
                    "\nIngrese el legajo delante del cual desea insertar a PEPE: "
                );

                scanf("%d", &legajo);

                /*
                   Primero comprobamos si el legajo
                   está en la cabeza.
                */

                if (p != NULL && p->numero_legajo == legajo)
                {
                    p = insertar1(p, legajo);
                }
                else if (p != NULL)
                {
                    /*
                       Si no está en la cabeza,
                       buscamos en el resto.
                    */

                    insertar2(p, legajo);
                }

                printf("\n--- LISTA ACTUALIZADA ---\n");

                mostrar(p);

                break;


            /* =========================
               SALIR
               ========================= */

            case 6:

                printf("\nSaliendo del programa...\n");

                break;


            /* =========================
               OPCION INVALIDA
               ========================= */

            default:

                printf("\nOpcion invalida.\n");
        }

    } while (opc != 6);


    return 0;
}
