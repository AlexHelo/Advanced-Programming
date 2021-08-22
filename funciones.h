#ifndef funciones_h
#define funciones_h

void setBarcos(int);
void setTripulante(int);
void getBarcos(int);
void getTripulante(int);

void setBarcos(int opcion)
{
    printf("%d - Agregando barco...\n", opcion);
}

void setTripulante(int opcion)
{
    printf("%d - Agregando tripulante...\n", opcion);
}

void getBarcos(int opcion)
{
    printf("%d - Mostrando barcos...\n", opcion);
}

void getTripulante(int opcion)
{
    printf("%d - Mostrando tripulantes...\n", opcion);
}

#endif /* funciones_h */
