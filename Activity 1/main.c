#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"


typedef void (*opcion_t)(int);
void menu_f(opcion_t *opciones, embarcacion * embarcaciones, int * embarcaciones_count);

int main()
{
    static int embarcacionesCount = 0;
    static embarcacion * embarcaciones;
    embarcaciones = (embarcacion *) malloc(10 * sizeof(embarcacion));
    opcion_t *menu = (opcion_t *)malloc(4 * sizeof(opcion_t));

    *menu = agregarEmbarcacion;
    *(menu + 1) = agregarTripulante;
    *(menu + 2) = imprimirEmbarcaciones;
    *(menu + 3) = imprimirTripulantes;

    menu_f(menu, embarcaciones, &embarcacionesCount);
    embarcacion * end = embarcaciones + embarcacionesCount;

    for(embarcacion* aux = embarcaciones; aux < end; aux++){
        free(aux->nombre);
        persona * end1 = aux->tripulacion + aux->tripulacion_actual;
        for (persona * aux1 = aux->tripulacion; aux1 < end1; aux1++){
            free(aux1->nombre);
            free(aux1->apellidos);
        }
        free(aux->tripulacion);
    }
    free(embarcaciones);
    free(menu);
    return 0;
}

void menu_f(opcion_t *opciones, embarcacion *embarcaciones, int *embarcaciones_count)
{
    int opcion;

    do
    {
        printf("--- Opciones --- \n1-Agregar Barco\n2-Agregar Tripulante\n3-Ver Barcos\n4-Ver Tripulantes\n0-Terminar\nEscoge tu opcion: ");

        scanf("%d", &opcion);

        if (opcion > 0 && opcion <= 4)
        {

            /* Hacer estos parámetros dinámicos */
            add((*(opciones + opcion - 1)), embarcaciones, embarcaciones_count);
        }
    } while (opcion > 0 && opcion <= 4);
}

void loadMenu(opcion_t *opciones){
    int opcion;


}

