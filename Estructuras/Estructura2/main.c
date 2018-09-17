#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int day;
    int month;
    int year;
}eFecha;

typedef struct
{
    int legajo;
    char nombre[25];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;
}eEmpleado;


int main()
{
    eEmpleado unEmpleado;

    unEmpleado.legajo = 1234;
    strcpy(unEmpleado.nombre, "Juan");
    unEmpleado.sexo = 'm';
    unEmpleado.sueldo = 10000.5;
    unEmpleado.fechaIngreso.day = 8;
    unEmpleado.fechaIngreso.month = 4;
    unEmpleado.fechaIngreso.year = 1995;

    printf("%d  %s  %c  %.2f  %02d/%02d/%4d", unEmpleado.legajo, unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldo, unEmpleado.fechaIngreso.day, unEmpleado.fechaIngreso.month, unEmpleado.fechaIngreso.year);


    return 0;
}
