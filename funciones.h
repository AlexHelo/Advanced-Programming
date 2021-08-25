#ifndef funciones_h
#define funciones_h
#include <stdio.h>
#include <stdlib.h>

#define CHUNK 5;



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
char const* roles[] = {"Arponero", "Cocinero", "Vigia", "Capitan"};
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
            size += CHUNK;
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
    newBarco.tripulacion = (persona *) malloc(newBarco.max_tripulantes * sizeof (persona));
    newBarco.tripulacion_actual = 0;
    /* Agregar variable de cuántos barcos hay y realocar solo cuando llegamos al máximo llamamos realloc y actualizamos max_barcos*/
    if ((*fin+1) % 10 == 0){
        /* Validar resultado de realloc, si es null, existe un error */
        printf("buscando más memoria");
        embarcaciones = (embarcacion *) realloc(embarcaciones, 10*sizeof(embarcacion));

        if(!embarcaciones){
            printf("No hay memoria para gregar más embarcaciones");
            return;
        }

    }
    *(embarcaciones + *fin) = newBarco;

    *fin =  *fin + 1;
    printf("fin: %d\n", *fin);
}

void imprimirEmbarcaciones(embarcacion * embarcaciones, int  *fin){
    embarcacion * start = embarcaciones;
    embarcacion *end  = (embarcaciones + *fin);
    int count = 1;
    for(; start < end; start++){
        if (start->max_tripulantes > 1)
        printf("%d | %s , %fm X %fm, %d tripulantes\n", count, start->nombre, start->eslora, start->manga, start->max_tripulantes);
        if (start->max_tripulantes == 1)
            printf("%d | %s , %fm X %fm, %d tripulante\n", count, start->nombre, start->eslora, start->manga, start->max_tripulantes);
        count++;
    }
}

embarcacion * seleccionarEmbarcacion(embarcacion * embarcaciones, *fin){
    printf("Selecciona una embarcación: \n");
    imprimirEmbarcaciones(embarcaciones, fin);
    int eleccion;
    scanf("%d", &eleccion);
    return (embarcaciones + (eleccion-1));
}

void agregarTripulante(embarcacion* embarcaciones, *fin)
{

    embarcacion * bote = seleccionarEmbarcacion(embarcaciones, fin);
    if(bote->tripulacion_actual == bote->max_tripulantes){
        printf("La tripulación de este barco ya está al límite\n");
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



    *(bote->tripulacion + bote->tripulacion_actual) = tripulante;
    bote->tripulacion_actual++;
}

void imprimirTripulantes(embarcacion *embarcaciones, int* fin)
{
    embarcacion * bote = seleccionarEmbarcacion(embarcaciones, fin);
    persona * start = bote->tripulacion;
    persona * end = bote->tripulacion + bote->tripulacion_actual;

    for(; start < end; start++){
        printf("%s %s, %d años, %s\n", start->nombre, start->apellidos, start->edad, roles[start->rol]);
    }
}

void add (t_function function, embarcacion * array, int *fin){
    (*function)(array, fin);
}



#endif /* funciones_h */
