#ifndef funciones_h
#define funciones_h
#include <stdio.h>
#include <stdlib.h>




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


typedef void (*t_function)(embarcacion * , int *);

/* Función genérica */
void add(t_function, embarcacion *, int *);



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



void agregarEmbarcacion(embarcacion * embarcaciones, int *fin)
{
    embarcacion newBarco;

    printf(" Agregue el nombre de la embarcación: \n");
    getln();
    newBarco.nombre = getln();
    printf(" Agregue la eslora: \n ");
    scanf("%f", &newBarco.eslora);

    printf(" Agregue  la manga: \n");
    scanf("%f", &newBarco.manga);

    printf(" Agregue  el número máximo de tripulantes: \n");
    scanf("%d", &newBarco.max_tripulantes);
    newBarco.tripulacion = (persona *) malloc(sizeof (persona));
    newBarco.tripulacion_actual = 0;

    if (*fin == 0){
        *embarcaciones = newBarco;
    } else {
        int newFin = *fin + 1;
        embarcaciones = (embarcacion *) realloc(embarcaciones, newFin * sizeof(embarcacion));
        *(embarcaciones + newFin) = newBarco;

        embarcacion segundaPos = *(embarcaciones + newFin);
        printf("%s \n", segundaPos.nombre);
    }

    *fin =  *fin + 1;
    printf("fin: %d\n", *fin);
}

void imprimirEmbarcaciones(embarcacion * embarcaciones, int  *fin){
    int newFin = *fin;
    embarcacion * start = embarcaciones;
    embarcacion *end  = (embarcaciones + newFin + 1);

    for(; start < end; start++){
        printf("%s , %f metros X %f metros, %d tripulantes\n", start->nombre, start->eslora, start->manga, start->max_tripulantes);
    }
}

void agregarTripulante(embarcacion* embarcaciones, *fin)
{
    printf("Selecciona la embarcación a la cual quieres agregar un tripulante: \n");
    imprimirEmbarcaciones(embarcaciones, fin);
    int eleccion;
    scanf("%d", &eleccion);
    *(embarcaciones + (eleccion-1));
    if((*(embarcaciones + (eleccion-1))).tripulacion_actual == (*(embarcaciones + (eleccion-1))).max_tripulantes){
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
    int eleccion1;
    scanf("%d", &eleccion1);
    tripulante.rol = eleccion1 -1;

    if((*(embarcaciones + (eleccion-1))).tripulacion_actual == 0){
        (*(embarcaciones + (eleccion-1))).tripulacion_actual++;
        *(*(embarcaciones + (eleccion-1))).tripulacion = tripulante;
    }else{
        (*(embarcaciones + (eleccion-1))).tripulacion_actual++;
        (*(embarcaciones + (eleccion-1))).tripulacion = (persona*) realloc((*(embarcaciones + (eleccion-1))).tripulacion, ((*(embarcaciones + (eleccion-1))).tripulacion_actual)*sizeof (persona));
        *((*(embarcaciones + (eleccion-1))).tripulacion + (*(embarcaciones + (eleccion-1))).tripulacion_actual) = tripulante;
    }
}

void imprimirTripulantes(embarcacion *embarcaciones, int* fin)
{
    printf("Selecciona la embarcación a la cual quieres agregar un tripulante: \n");
    imprimirEmbarcaciones(embarcaciones, fin);
    int eleccion;
    scanf("%d", &eleccion);
    *(embarcaciones + (eleccion-1));
    persona * start = (*(embarcaciones + (eleccion-1))).tripulacion;
    persona * end = ((*(embarcaciones + (eleccion-1))).tripulacion + ((*(embarcaciones + (eleccion-1))).tripulacion_actual)+1);

    for(; start < end; start++){
        printf("%s %s, %d años, %u\n", start->nombre, start->apellidos, start->edad, start->rol);
    }
}

void add (t_function function, embarcacion * array, int *fin){
    (*function)(array, fin);
}



#endif /* funciones_h */
