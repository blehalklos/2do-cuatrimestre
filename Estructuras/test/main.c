#include <stdio.h>
#include <stdlib.h>
#define TAM 3

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
    int i;

    eEmpleado empleados[TAM];

    for(i=0; i < TAM; i++)
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
    }

    return 0;
}

void mostrarEmpleados(eEmpleado lista[], int TAM)
{
    system("cls");
    printf(" Legajo  Nombre  Sexo  Sueldo\n\n");

    for(i=0; i < TAM; i++)
    {
        mostrarEmpleado(lista[i]);
    }
}

void mostrarEmpleado(eEmpleado employee)
{
    printf("%d  %s  %c  %.2f\n\n", employee.legajo, employee.nombre, employee.sexo, employee.sueldo);
}

