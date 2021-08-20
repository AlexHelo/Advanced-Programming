#include <stdio.h>

typedef enum {arponero, cocinero, vigía, capitán, médico} roles_tripulacion;

typedef struct {
    char * nombre;
    char * apellidos;
    int edad;
    roles_tripulacion rol;
} persona;

struct embarcacion {
    char * nombre;
    float eslora;
    float manga;
    int max_tripulantes;
    persona * tripulacion;
};

int main() {
    printf("Hello, World!\n");
    return 0;
}
