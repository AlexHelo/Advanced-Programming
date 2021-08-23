#ifndef funciones_h
#define funciones_h
#include <stdio.h>
#include <stdlib.h>

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
    char nombre[50];
    char apellidos[50];
    int edad;
    roles_tripulacion rol;
} persona;

typedef struct
        {
    char nombre[50];
    float eslora;
    float manga;
    int max_tripulantes;
    persona *tripulacion;
        } embarcacion;


embarcacion agregarEmbarcacion(embarcacion * embarcaciones, int fin)
{
    embarcacion newBarco;

    printf(" Agregue el nombre de la embarcación: \n ");
    scanf("%s", &newBarco.nombre);
    printf(" Agregue la eslora: \n ");
    scanf("%f", &newBarco.eslora);

    printf(" Agregue  la manga: \n");
    scanf("%f", &newBarco.manga);

    printf(" Agregue  el número máximo de tripulantes: \n");
    scanf("%d", &newBarco.max_tripulantes);



    *(embarcaciones + fin + 1) = newBarco;

    printf("%s\n", embarcaciones[fin+1].nombre);
    printf("%f\n", embarcaciones[fin+1].eslora);
    printf("%f\n", embarcaciones[fin+1].manga);
    printf("%d\n", embarcaciones[fin+1].max_tripulantes);
}

void setTripulante(int opcion)
{
    printf("%d - Agregando tripulante...\n\n", opcion);
}

void getBarcos(int opcion)
{
    printf("%d - Mostrando barcos...\n\n", opcion);
}

void getTripulante(int opcion)
{
    printf("%d - Mostrando tripulantes...\n\n", opcion);
}

void startMenu(int opcion) {
    printf("--- Opciones --- \n1-Incorporar Barcos\n2-Incorporar Tripulantes\n3-Ver Barcos\n4-Ver Tripulantes\n0-Terminar\nEscoge tu opcion: ");
}

void boatMenu() {
    printf("--- Opciones --- \n1-Incorporar Barcos\n2-Incorporar Tripulantes\n3-Ver Barcos\n4-Ver Tripulantes\n0-Terminar\nEscoge tu opcion: ");

}

#endif /* funciones_h */
