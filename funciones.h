#ifndef funciones_h
#define funciones_h
#include <stdio.h>
#include <stdlib.h>

typedef void (*t_function)(void * , int *);

/* Función genérica */
void add(t_function, void *, int *);


typedef enum
{
    arponero,
    cocinero,
    vigia,
    capitan
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
    int tripulacion_actual;
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

void agregarEmbarcacion(void * embarcaciones, int *fin)
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

    newBarco.tripulacion = (persona *) malloc(sizeof (persona));
    newBarco.tripulacion_actual = 0;
    embarcaciones = (void *) realloc(embarcaciones, (*fin+1)*sizeof(embarcacion));
    *(embarcacion *)(embarcaciones + *fin + 1) = newBarco;

    printf("%s\n", ((embarcacion *)(embarcaciones + *fin + 1))->nombre);
    printf("%f\n", ((embarcacion *)(embarcaciones + *fin + 1))->eslora);
    printf("%f\n", ((embarcacion *)(embarcaciones + *fin + 1))->manga);
    printf("%d\n", ((embarcacion *)(embarcaciones + *fin + 1))->max_tripulantes);
    *fin =  *fin + 1;
    printf("fin: %d\n", *fin);
}

void imprimirEmbarcaciones(void * embarcaciones, int  *fin){
    embarcacion * aux = embarcaciones;
    embarcacion * last = embarcaciones + *fin;

    printf("fin: %d", *fin);

    for (; aux < last; ++aux) {

        printf("%s\n", aux->nombre);
        printf("%f\n", aux->eslora);
        printf("%f\n", aux->manga);
        printf("%d\n", aux->max_tripulantes);
    }
}

void agregarTripulante(embarcacion bote)
{
    if(bote.tripulacion_actual == bote.max_tripulantes){
        printf("La tripulación de este barco ya está al límite");
        return;
    }
    persona tripulante;
    printf(" Agregue el nombre del tripulante: \n");
    getln();
    tripulante.nombre = getln();
    printf(" Agregue los apellidos del tripulante: \n ");
    tripulante.apellidos = getln();

    printf(" Agregue  la edad del tripulante: \n");
    scanf("%d", &tripulante.edad);

    printf("apellido: %s", tripulante.apellidos);
    printf("edad: %d", tripulante.edad);
    printf(" Escoga un rol para el tripulante: \n");
    printf("1: Arponero \n 2: Cocinero\n 3: Vigia \n 4: Capitan\n");
    int eleccion;
    scanf("%d", &eleccion);
    if (eleccion == 1){
        tripulante.rol = arponero;
    }
    if (eleccion == 2){
        tripulante.rol = cocinero;
    }
    if (eleccion == 3){
        tripulante.rol = vigia;
    }
    if (eleccion == 4){
        tripulante.rol = capitan;
    }

    if(bote.tripulacion_actual == 0){
        bote.tripulacion_actual++;
        *bote.tripulacion = tripulante;
    }else{
        bote.tripulacion_actual++;
        bote.tripulacion = (persona*) realloc(bote.tripulacion, (bote.tripulacion_actual)*sizeof (persona));
        *(bote.tripulacion + bote.tripulacion_actual) = tripulante;
    }
}

void getBarcos(int opcion)
{
    printf("%d - Mostrando barcos...\n\n", opcion);
}

void imprimirTripulantes(embarcacion bote)
{
    persona * start = bote.tripulacion;
    persona * end = (bote.tripulacion + bote.tripulacion_actual);

    for(; start < end; start++){
        printf("%s %s, %d años, %s", start->nombre, start->apellidos, start->edad, start->rol);
    }
}

void add (t_function function, void* array, int *fin){
    (*function)(array, fin);
}



#endif /* funciones_h */
