#ifndef funciones_h
#define funciones_h
#include <stdio.h>
#include <stdlib.h>

typedef void (*t_function)(void * , int );

/* Función genérica */
void add(t_function, void *, int);


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

typedef struct
        {
    char *nombre;
    float eslora;
    float manga;
    int max_tripulantes;
    persona *tripulacion;
        } embarcacion;
char *getln()
{
    char *line = NULL, *tmp = NULL;
    size_t size = 0, index = 0;
    int ch = EOF;

    while (ch) {
        ch = getc(stdin);

        /* Check if we need to stop. */
        if (ch == EOF || ch == '\n')
            ch = 0;

        /* Check if we need to expand. */
        if (size <= index) {
            size += 1;
            tmp = realloc(line, size);
            if (!tmp) {
                free(line);
                line = NULL;
                break;
            }
            line = tmp;
        }

        /* Actually store the thing. */
        line[index++] = ch;
    }

    return line;
}

void agregarEmbarcacion(void * embarcaciones, int* fin)
{
    embarcacion newBarco;

    printf(" Agregue el nombre de la embarcación: \n");
    newBarco.nombre = getln();
    printf(" Agregue la eslora: \n ");
    scanf("%f", &newBarco.eslora);

    printf(" Agregue  la manga: \n");
    scanf("%f", &newBarco.manga);

    printf(" Agregue  el número máximo de tripulantes: \n");
    scanf("%d", &newBarco.max_tripulantes);

    *(embarcacion *)(embarcaciones + *fin + 1) = newBarco;

    printf("%s\n", ((embarcacion *)(embarcaciones + *fin + 1))->nombre);
    printf("%f\n", ((embarcacion *)(embarcaciones + *fin + 1))->eslora);
    printf("%f\n", ((embarcacion *)(embarcaciones + *fin + 1))->manga);
    printf("%d\n", ((embarcacion *)(embarcaciones + *fin + 1))->max_tripulantes);
    *fin ++;
}

void imprimirEmbarcaciones(void * embarcaciones, int fin){
        embarcacion * aux = embarcaciones;
        embarcacion * last = embarcaciones + fin;
    printf("Estoy en el metodo!\n");
    printf("fin: %d", fin);

        for (; aux < last; ++aux) {
            printf("Imprimiendo");
            printf("%s\n", aux->nombre);
            printf("%f\n", aux->eslora);
            printf("%f\n", aux->manga);
            printf("%d\n", aux->max_tripulantes);
        }
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

void add (t_function function, void* array, int fin){
    (*function)(array, fin);
}



#endif /* funciones_h */
