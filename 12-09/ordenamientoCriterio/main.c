#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 200

int main()
{
    char nombre[CANT][31], nombreAux[31];
    char apellido[CANT][31], apeAux[31];
    int edad[CANT], edadAux;
    int legajo[CANT], legajoAux;
    int isEmpty[CANT], isEmptyAux;
    int cantidad;
    int opcion;
    int exit='n';
    int exitMod='n';
    int flag;
    int i;
    int j;
    char rta;


    for(i=0; i<CANT; i++)
    {
        isEmpty[i]=1;
    }

    while(exit == 'n')
    {
        system("cls");
        printf("*****************************************************************\n");
        printf("*\t\t\t*ABM Empleados*\t\t\t\t*\n");
        printf("*\t\t\t\t\t\t\t\t*\n");
        printf("* 1 - Ingresar empleado\t\t\t\t\t\t*\n");
        printf("* 2 - Eliminar empleado\t\t\t\t\t\t*\n");
        printf("* 3 - Modificar empleado\t\t\t\t\t*\n");
        printf("* 4 - Informar empleados\t\t\t\t\t*\n");
        printf("* 5 - Salir\t\t\t\t\t\t\t*\n");
        printf("*\t\t\t\t\t\t\t\t*\n");
        printf("*****************************************************************\n\n");

        scanf("%d",&opcion);

        switch(opcion)
        {

            case 1:

                system("cls");

                for(i=0; i < CANT; i++)
                {
                    if(isEmpty[i] == 1)
                    {
                        for(i=0; i < CANT; i++)
                        {
                            fflush(stdin);
                            printf("Ingrese el legajo:");
                            scanf("%d", &legajo[i]);

                            fflush(stdin);
                            printf("Ingrese el apellido:");
                            gets(apellido[i]);

                            fflush(stdin);
                            printf("Ingrese el nombre:");
                            gets(nombre[i]);

                            fflush(stdin);
                            printf("Ingrese la edad:");
                            scanf("%d", &edad[i]);

                            isEmpty[i] = 0;

                            system("cls");
                            printf("Alta exitosa!\n");
                            system("pause");

                            break;
                        }
                    }
                }

                break;

            case 2:

                printf("Legajo:");
                scanf("%d", &legajoAux);
                flag=0;

                for(i=0; i<CANT;i++)
                {
                    if(legajoAux == legajo[i] && isEmpty[i] == 0)
                    {
                        isEmpty[i]=1;
                        flag=1;
                    }
                }

                if(flag==0)
                {
                    printf("Legajo no encontrado");
                }

                break;

            case 3:

                printf("Legajo:");
                scanf("%d", &legajoAux);
                flag = 0;

                for(i=0; i < CANT; i++)
                {
                    if(legajoAux == legajo[i])
                    {
                        printf("%d %s %s %d\n", legajo[i], apellido[i], nombre[i], edad[i]);
                        printf("Modificar S/N:");
                        fflush(stdin);
                        scanf("%c", &rta);

                        if(rta == 's')
                        {
                            printf("Que desea modificar?\n");
                            printf("1 - Apellido\n");
                            printf("2 - Nombre\n");
                            printf("3 - Edad\n");
                            printf("4 - Salir\n");
                            printf("Seleccion:");
                            scanf("%d", &opcion);

                            switch(opcion)
                            {
                            case 1:
                                printf("Apellido:")
                                fflush(stdin);
                                gets(apellido);
                                }
                        }
                    }
                }

            case 4:

                system("cls");

                for(i=0; i<CANT-1;i++)
                {
                    for(j=i++;j<CANT;j++)
                    {
                        if(strcmp(apellido[i], apellido[j]) > 0)
                        {
                            strcpy(apeAux, apellido[i]);
                            strcpy(apellido[i], apellido[j]);
                            strcpy(apellido[j], apeAux);

                            strcpy(nombreAux, nombre[i]);
                            strcpy(nombre[i], nombre[j]);
                            strcpy(nombre[j], nombreAux);

                            edadAux = edad[i];
                            edad[i] = edad[j];
                            edad[j] = edadAux;

                            legajoAux = legajo[i];
                            legajo[i] = legajo[j];
                            legajo[j] = legajoAux;

                            isEmptyAux = isEmpty[i];
                            isEmpty[i] = isEmpty[j];
                            isEmpty[j] = isEmptyAux;
                        }
                        else
                        {
                            if(strcmp(apellido[i], apellido[j]) == 0)
                            {
                                if(strcmp(nombre[i],nombre[j]) > 0)
                                {
                                    strcpy(nombreAux, nombre[i]);
                                    strcpy(nombre[i], nombre[j]);
                                    strcpy(nombre[j], nombreAux);

                                    edadAux = edad[i];
                                    edad[i] = edad[j];
                                    edad[j] = edadAux;

                                    legajoAux = legajo[i];
                                    legajo[i] = legajo[j];
                                    legajo[j] = legajoAux;

                                    isEmptyAux = isEmpty[i];
                                    isEmpty[i] = isEmpty[j];
                                    isEmpty[j] = isEmptyAux;
                                }
                            }
                        }
                    }

                    printf("Legajo\tApellido\t\tNombre\t\tEdad\n\n");
                    for(i=0; i<CANT; i++)
                    {
                        if(isEmpty[i] == 0)
                        {
                            printf("%d\t%s\t\t%s\t\t%d\n",legajo[i],apellido[i],nombre[i],edad[i]);
                        }
                    }
                }

                system("pause");

                break;

            case 5:

                fflush(stdin);
                exit='s';

                break;

            default:

                fflush(stdin);
                printf("Ingrese una opcion valida por favor");
                system("pause");

                break;

        }
    }



    return 0;
}
