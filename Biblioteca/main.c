#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANT 20


int main()
{
    char seguir='s';
    int opcion=0;
    ePersona persona[CANT];
    inicializarPersona(persona, CANT);

    while(seguir=='s')
    {
        ordenar(persona, CANT);

        fflush(stdin);
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                altaPersona(persona, CANT);
                system("pause");
                break;

            case 2:
                bajaPersona(persona, CANT);
                system("pause");
                break;

            case 3:
                mostrarPersonas(persona, CANT);
                system("pause");
                break;

            case 4:
                graficoBarras(persona, CANT);
                system("pause");
                break;

            case 5:
                seguir = 'n';
                break;

            default:
                printf("Opcion no valida, por favor reingrese una opcion de la lista.\n");
                system("pause");
        }
    }

    return 0;
}
