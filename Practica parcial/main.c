#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct
{
    int idMenu;
    char descripcion[51];
    float importe;
    int isEmpty;
}eMenu;


typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;


typedef struct
{
    int id;
    char description[20];
}Sector;


typedef struct
{
    int Id;
    char name[20];
    char lastName[20];
    char sexo;
    float salary;
    eFecha fechaDeIngreso;
    int sector;
    int isEmpty;
}Employee;


typedef struct
{
   int idAlmuerzo;
   eMenu idMenu;
   Employee Id;
   eFecha fechaAlmuerzo;
}eAlmuerzo;

void altaMenu(eMenu menu[], int tam);
void initMenu(eMenu x[], int tam);
int findAvailableMenu(eMenu x[], int tam);


int main()
{

    char seguir = 's';
    int contadorId = 0;
    eMenu listMenu[20];
    Employee list[100];
    Sector sectors[] = {
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Compras"},
        {4, "Contable"},
        {5, "Sistemas"}
        };

    initEmployees(list, 100);


    do
    {
        ordenar(list, 100);

        switch(menu())
        {

        case 1:
            altaMenu(listMenu, 20);
            system("pause");
            break;


        case 5:
            contadorId++;
            addEmployees(list, 100, sectors, 5, contadorId);
            system("pause");
            break;

        case 6:
            if(contadorId == 0)
            {
                system("cls");
                printf("Primero debe de ingresar un empleado.\n\n");
                system("pause");
            }
            else
            {
                modifyEmployee(list, 100, sectors, 5);
            }
            break;

        case 7:
            if(contadorId == 0)
            {
                system("cls");
                printf("Primero debe de ingresar un empleado.\n\n");
                system("pause");
            }
            else
            {
            removeEmployee(list, 100, sectors, 5);
            }
            break;

        case 8:
            if(contadorId == 0)
            {
                system("cls");
                printf("Primero debe de ingresar un empleado.\n\n");
            }
            else
            {
            sortEmployeeByName(list, 100, sectors, 5);
            }
            system("pause");
            break;
        case 9:
            seguir = 'n';
            break;

        default:
            printf("\nIngrese una opcion valida por favor.\n\n");
            system("pause");
        }

    }
    while(seguir == 's');



    return 0;
}

void initMenu( eMenu x[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        x[i].isEmpty = 0;
    }
}

int findAvailableMenu( eMenu x[], int tam)
{
    int indice = -1;

    for(int i=0; i< tam; i++)
    {

        if( x[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


void altaMenu(eMenu listMenu[], int tam)
{
    system("cls");
    eMenu nuevoMenu;
    float importe;
    char aux[20];
    int indice;

    indice = findAvailableMenu(listMenu, tam);

    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
    printf("Ingrese id del menu:");
    scanf("%d", &nuevoMenu.idMenu);

    printf("\nIngrese la descripcion del menu:");
    fflush(stdin);
    gets(aux);

    strcpy(nuevoMenu.descripcion, aux);

    printf("\nIngrese importe del menu:");
    scanf("%f", &nuevoMenu.importe);

    nuevoMenu.isEmpty = 1;

    printf("Exito!");
    }
}


