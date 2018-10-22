#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    char marca[20];
    int capacidad;
    float precio;
}ePendrive;

int cargarPendrive(ePendrive* pen);
void mostrarPendrive(ePendrive* pen);

int main()
{

ePendrive* pendrive;

if(cargarPendrive(&pendrive) == 1)
{
    mostrarPendrive(&pendrive);
}

return 0;

}

int cargarPendrive(ePendrive* pen)
{
    int todoOk =  0;

    if(pen != NULL)
    {
    fflush(stdin);
    printf("Ingrese codigo: ");
    scanf("%d", &pen->codigo);

    fflush(stdin);
    printf("Ingrese marca: ");
    gets(pen->marca);

    fflush(stdin);
    printf("Ingrese capacidad: ");
    scanf("%d", &pen->capacidad);

    fflush(stdin);
    printf("Ingrese precio: ");
    scanf("%f", &pen->precio);

    todoOk = 1;
    }

    return todoOk;
}

void mostrarPendrive(ePendrive* pen)
{
        printf("%d %s %dGB %.2f", pen->codigo, pen->marca, pen->capacidad, pen->precio);
}
