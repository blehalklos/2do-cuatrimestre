#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char nombre[25];
    char sexo;
    float sueldo;
}eEmpleado;

void mostrarEmpleado(eEmpleado employee);

int main()
{
    eEmpleado unEmpleado;
    eEmpleado otroEmpleado;
    eEmpleado emp3 = {9999, "Jose", 'm', 20000};
    eEmpleado emp4 = emp3;

    unEmpleado.legajo = 1234;
    strcpy(unEmpleado.nombre,"Juan");
    unEmpleado.sexo = 'm';
    unEmpleado.sueldo = 10000.5;

    otroEmpleado.legajo = 5678;
    strcpy(otroEmpleado.nombre,"Juana");
    otroEmpleado.sexo = 'f';
    otroEmpleado.sueldo = 90000.5;

    mostrarEmpleado(unEmpleado);
    mostrarEmpleado(otroEmpleado);
    mostrarEmpleado(emp3);
    mostrarEmpleado(emp4);

    return 0;
}

void mostrarEmpleado(eEmpleado employee)
{
    printf("%d  %s  %c  %.2f\n\n", employee.legajo, employee.nombre, employee.sexo, employee.sueldo);
}
