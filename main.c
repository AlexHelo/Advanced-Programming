#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"


typedef void (*opcion_t)(int);
void menu_f(opcion_t *opciones);

int main()
{
    int embarcacionesCount = 0;
    embarcacion * embarcaciones = (embarcacion *) malloc(sizeof(embarcacion));
    opcion_t *menu = (opcion_t *)malloc(4 * sizeof(opcion_t));

    agregarEmbarcacion(embarcaciones, &embarcacionesCount);

    imprimirEmbarcaciones(embarcaciones, 1);


    *menu = add;
    *(menu + 1) = add;
    *(menu + 2) = add;
    *(menu + 3) = add;

    menu_f(menu);


    return 0;
}

void menu_f(opcion_t *opciones)
{
    int opcion;

    do
    {
        printf("--- Opciones --- \n1-Agregar Barco\n2-Agregar Tripulante\n3-Ver Barcos\n4-Ver Tripulantes\n0-Terminar\nEscoge tu opcion: ");

        scanf("%d", &opcion);

        if (opcion > 0 && opcion <= 4)
        {
            /* Hacer estos parámetros dinámicos */
            (*(opciones + opcion - 1))(opcion);
        }
    } while (opcion > 0 && opcion <= 4);
}

void loadMenu(opcion_t *opciones){
    int opcion;


}

