#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int codigo;
    char marca[20];
    int capacidad;
    float precio;
}ePendrive;

int cargarPendrive(ePendrive* pen, int codigo, char marca[], int cap, float   precio);
void mostrarPendrive(ePendrive* pen);

int main()
{

int codigo;
char marca[20];
int cap;
float precio;
ePendrive* pendrive;

fflush(stdin);
printf("Ingrese codigo: ");
scanf("%d", &codigo);

fflush(stdin);
printf("Ingrese marca: ");
gets(marca);

fflush(stdin);
printf("Ingrese capacidad: ");
scanf("%d", &cap);

fflush(stdin);
printf("Ingrese precio: ");
scanf("%f", &precio);

if(cargarPendrive(&pendrive, codigo, marca, cap, precio) == 1)
{
    mostrarPendrive(&pendrive);
}

return 0;

}

int cargarPendrive(ePendrive* pen, int codigo, char marca[], int cap, float precio)
{
    int todoOk =  0;

    if(pen != NULL)
    {
    pen->codigo = codigo;
    strcpy(pen->marca, marca);
    pen->capacidad = cap;
    pen->precio = precio;

    todoOk = 1;
    }

    return todoOk;
}

void mostrarPendrive(ePendrive* pen)
{
        printf("%d %s %dGB %.2f", pen->codigo, pen->marca, pen->capacidad, pen->precio);
}
