#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"

typedef enum
{
    arponero,
    cocinero,
    vigia,
    capitan,
    medico
} roles_tripulacion;

typedef struct
{
    char *nombre;
    char *apellidos;
    int edad;
    roles_tripulacion rol;
} persona;

struct embarcacion
        {
    char *nombre;
    float eslora;
    float manga;
    int max_tripulantes;
    persona *tripulacion;
        };

typedef void (*opcion_t)(int);
void menu_f(opcion_t *opciones);

int main()
{

    opcion_t *menu = (opcion_t *)malloc(4 * sizeof(opcion_t));

    *menu = setBarcos;
    *(menu + 1) = setTripulante;
    *(menu + 2) = getBarcos;
    *(menu + 3) = getTripulante;

    menu_f(menu);

    return 0;
}

void menu_f(opcion_t *opciones)
{
    int opcion;

    do
    {
        printf("--- Opciones --- \n1-Incorporar Barcos\n2-Incorporar Tripulantes\n3-Ver Barcos\n4-Ver Tripulantes\n0-Terminar\nEscoge tu opcion: ");

        scanf("%d", &opcion);

        if (opcion > 0 && opcion <= 4)
        {
            (*(opciones + opcion - 1))(opcion);
        }
    } while (opcion > 0 && opcion <= 4);
}
