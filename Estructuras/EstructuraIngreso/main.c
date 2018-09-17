#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombre[25];
    char sexo;
    float sueldo;
}eEmpleado;

int main()
{
    eEmpleado empleado;

    printf("Ingrese el legajo:");
    scanf("%d", &empleado.legajo);

    printf("Ingrese el nombre:");
    fflush(stdin);
    gets(empleado.nombre);

    printf("Ingrese el sexo:");
    fflush(stdin);
    scanf("%c", &empleado.sexo);

    printf("Ingrese el sueldo:");
    fflush(stdin);
    scanf("%f", &empleado.sueldo);

    printf("%d  %s  %c  %.2f", empleado.legajo, empleado.nombre, empleado.sexo, empleado.sueldo);

    return 0;
}
