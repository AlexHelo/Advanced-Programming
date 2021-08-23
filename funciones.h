#ifndef funciones_h
#define funciones_h

void setBarcos(int);
void setTripulante(int);
void getBarcos(int);
void getTripulante(int);

void setBarcos(int opcion)
{
    printf("%d - Agregando barco...\n\n", opcion);
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

#endif /* funciones_h */
