#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANT 100


int main()
{
    char seguir='s';
    int opcion=0;
    eProducto producto[CANT];
    inicializarProducto(producto, CANT);

    while(seguir=='s')
    {
        ordenar(producto, CANT);

        fflush(stdin);
        system("cls");
        printf("1- Altas\n");
        printf("2- Modificar\n");
        printf("3- Baja\n");
        printf("4- Informar\n");
        printf("5- Listar\n");
        printf("6- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                altaProducto(producto, CANT);
                system("pause");
                break;

            case 2:
                modificarProducto(producto, CANT);
                system("pause");
                break;

            case 3:
                bajaProducto(producto, CANT);
                system("pause");
                break;

            case 4:

                informarProducto(producto, CANT);
                system("pause");
                break;

            case 5:

                break;

            case 6:
                seguir = 'n';
                break;

            default:
                printf("Opcion no valida, por favor reingrese una opcion de la lista.\n");
                system("pause");
        }
    }

    return 0;
}
