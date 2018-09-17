#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombre[25];
    char sexo;
    float sueldo;
}eEmpleado;

void mostrarEmpleado(eEmpleado employee);
void mostrarEmpleados(eEmpleado lista[], int TAM);

int main()
{
    int TAM=4;
    eEmpleado empleados[]={
    {1111, "Adan", 'm', 10000},
    {3333, "Gustavo", 'm', 10000},
    {4444, "Ernesto", 'm', 10000},
    {5555, "Ignacio", 'm', 10000},
    };

    /*for(int i=0; i < TAM; i++)
    {
        printf("Ingrese el legajo:");
        scanf("%d", &empleados[i].legajo);

        printf("Ingrese el nombre:");
        fflush(stdin);
        gets(empleados[i].nombre);

        printf("Ingrese el sexo:");
        fflush(stdin);
        scanf("%c", &empleados[i].sexo);

        printf("Ingrese el sueldo:");
        fflush(stdin);
        scanf("%f", &empleados[i].sueldo);
    }*/

    mostrarEmpleados(empleados, TAM);

    return 0;
}

void mostrarEmpleados(eEmpleado lista[], int TAM)
{
    system("cls");
    printf(" Legajo  Nombre  Sexo  Sueldo\n\n");

    for(int i=0; i < TAM; i++)
    {
        mostrarEmpleado(lista[i]);
    }
}

void mostrarEmpleado(eEmpleado employee)
{
    printf("%d  %s  %c  %.2f\n\n", employee.legajo, employee.nombre, employee.sexo, employee.sueldo);
}
