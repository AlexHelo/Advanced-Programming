#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"


typedef void (*opcion_t)(int);
void menu_f(opcion_t *opciones);
void imprimirEmbarcaciones(embarcacion * inicio, embarcacion * fin)
{
    for (embarcacion * aux = inicio; aux < fin; ++aux) {
        printf("%s\t", aux->nombre, " %f ", aux->eslora, " %f ", aux->manga, " %d", aux->max_tripulantes);
    }

    printf("\n");
}
int main()
{
    embarcacion * embarcaciones = (embarcacion *) malloc(sizeof(embarcacion));
    opcion_t *menu = (opcion_t *)malloc(4 * sizeof(opcion_t));
    printf("%d", sizeof(embarcacion));
    *embarcaciones = agregarEmbarcacion();
    printf("%s \n",*embarcaciones->nombre);
    *menu = agregarEmbarcacion;
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
        printf("--- Opciones --- \n1-Agregar Barco\n2-Agregar Tripulante\n3-Ver Barcos\n4-Ver Tripulantes\n0-Terminar\nEscoge tu opcion: ");

        scanf("%d", &opcion);

        if (opcion > 0 && opcion <= 4)
        {
            (*(opciones + opcion - 1))(opcion);
        }
    } while (opcion > 0 && opcion <= 4);
}

void loadMenu(opcion_t *opciones){
    int opcion;


}

