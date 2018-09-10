#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef FUNCIONES_C_INCLUDED
#define FUNCIONES_C_INCLUDED


typedef struct
{
    char nombre[50];
    int edad;
    int dni;
    int isEmpty;

}ePersona;


/*void hardCode(eSector vec[])
{
    vec[0].id=1;
    strcpy(vec[0].descripcion,"RRHH");
    vec[0].isEmpty=0;

    vec[1].id=2;
    strcpy(vec[1].descripcion,"sistema");
    vec[1].isEmpty=0;

    vec[2].id=3;
    strcpy(vec[2].descripcion,"administracion");
    vec[2].isEmpty=0;

    vec[3].id=4;
    strcpy(vec[3].descripcion,"compras");
    vec[3].isEmpty=0;

    vec[4].id=5;
   strcpy(vec[4].descripcion,"deposito");
    vec[4].isEmpty=0;
}*/


void inicializarPersona(ePersona vec[], int CANT)
{
    for(int i=0; i < CANT; i++)
    {
        vec[i].isEmpty = 1;
    }
}


void ordenar(ePersona vec[], int CANT)
{
    ePersona auxiliar;
    int i;
    int j;

    for(i=0;i<CANT;i++)
    {

        for(j=i+1;j<CANT;j++)
        {

            if(strcmp(vec[i].nombre, vec[j].nombre)>0)
            {
                auxiliar = vec[i];
                vec[i] = vec[j];
                vec[j] = auxiliar;

            }

            else
            {

            if(strcmp(vec[i].nombre, vec[j].nombre)== 0)

            {
                if(vec[i].dni < vec[j].dni)
                {
                    auxiliar = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxiliar;
                }

                else if(vec[i].edad < vec[j].edad)
                {
                    auxiliar = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxiliar;
                }


            }

            }
        }
    }
}


void mostrarPersonas(ePersona vec[], int CANT)
{
    system("cls");
    printf("---Lista de Personas---\n\n");
    printf("        Nombre           Edad      DNI\n\n");

    for(int i=0; i< CANT; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarPersona(vec[i]);
        }
    }
}


void mostrarPersona(ePersona emp)
{
    printf("  %s     %3d      %10d\n", emp.nombre, emp.edad, emp.dni);
}


int obtenerEspacioLibre(ePersona vec[], int CANT)
{
    int indice = -1;

    for(int i=0; i < CANT; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


int buscarPorDni(ePersona vec[], int CANT, int dni)
{
    int indice = -1;

    for(int i=0; i < CANT; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].dni == dni)
        {
            indice = i;
            break;
        }
    }

    return indice;
}


int validarInt(char aux[])
{
    int i;
    int numero;

    for(i=0; i<strlen(aux); i++)
    {
        if (!(isdigit (aux[i])))
        {
            printf("La cantidad no es valida");
            return 0;
        }
    }
    numero=atoi(aux);
    if(numero < 1)
    {
        printf("La cantidad debe ser mayor a 0");
        return 0;
    }
    return numero;
}


/*float validarNumeroFlotante(char aux[])
{
    /*sueldo=validarNumeroFlotante("ingrese un sueldo: ")
    int validar;
    int numero;
    int i;
    long tam=256;
    char val, numeroCadena[tam];
    int tamCadena;
    printf("%s", mensaje);
    fflush(stdin);
    gets(numeroCadena);
    tamCadena=strlen(numeroCadena);
    for(i=0;i<tamCadena;i++)
    {
        if(isalpha( numeroCadena[i]))
        {
            validar=1;
            break;
        }
    }
        while(validar==1)
        {
            printf("Error ,ingrese un numero : ");
            fflush(stdin);
            gets(numeroCadena);
            tamCadena=strlen(numeroCadena);
            for(i=0;i<tamCadena;i++)
            {
               if(isalpha( numeroCadena[i]))
                {
                    validar=1;
                    break;
                }else
                {
                    validar=0;
                }
            }
        }
     numero=atof(numeroCadena);
  return numero;
}*/


int validarCHAR (char aux [])
{
    int i;
    int letras;
    letras = strlen(aux);

    if(letras > 50)
    {
        printf("La descripcion es demasiado larga.\n");
        return 0;
    }

    for (i=0; i<letras; i++)
    {
        if(!(isalpha(aux[i])))
        {
            if(aux [i] != ' ')
            {
                    printf("La descripcion no es valido.\n");
                    return 0;
            }
        }
    }

    return 1;
}


int validarLargoCadena(char cadena[],int  LargoMaximo)
{
            int largoCadena;
            largoCadena=strlen(cadena);
            if(largoCadena<LargoMaximo)
            {
               return 0;
            }
            else
            {
                return 1;

            }
}


void altaPersona(ePersona vec[], int CANT)
{
    ePersona nuevaPersona;
    int indice;
    int esta;
    char nombre[50];
    int aux[50];
    int dni;
    int edad;

    system("cls");
    printf("---->Alta persona<----\n\n");

    indice = obtenerEspacioLibre(vec, CANT);

    if(indice == -1)
    {
        printf("\nEl sistema se encuentra completo, no pueden agregrase nuevas personas, disculpe.\n\n");
    }

    else
    {
        printf("Ingrese DNI: ");
        scanf("%s", aux);
        fflush(stdin);

        dni = validarInt(aux);

        if(dni == 0)
        {
            printf(" por favor reingrese los datos\n");
        }

        else
        {

        esta = buscarPorDni(vec, CANT, dni);

        if(esta != -1)
        {
            printf("\nEl DNI %d ya se encuentra en el sistema\n", dni);
            mostrarPersona(vec[esta]);
        }

        else
        {
            nuevaPersona.isEmpty = 0;
            nuevaPersona.dni = dni;

            printf("Ingrese el nombre de la persona: ");
            gets(nombre);
            fflush(stdin);

            if(validarCHAR(nombre) == 0)
            {
                printf(" Por favor reingrese los datos\n");
            }

            else
            {
            strcpy(nuevaPersona.nombre, nombre);

            printf("Ingrese la edad de la persona: ");
            scanf("%s", aux);
            fflush(stdin);

            edad = validarInt(aux);

            if(edad == 0)
            {
                printf(" por favor reingrese los datos\n");
            }

            else
            {
                nuevaPersona.edad = edad;
                fflush(stdin);

                vec[indice] = nuevaPersona;

                printf("\nAlta exitosa!\n\n");
            }
            }
        }
        }
    }
}


void bajaPersona(ePersona vec[], int CANT)
{
    int dni;
    int aux[20];
    int esta;
    char confirma;

    system("cls");
    printf("---->Baja persona<----\n\n");

    printf("Ingrese DNI: ");
    scanf("%s", aux);

    dni = validarInt(aux);

    if(dni == 0)
    {
        printf(" por favor reingrese los datos\n");
    }

    else
    {

        fflush(stdin);

        esta = buscarPorDni(vec, CANT, dni);

    if(esta == -1)
    {
        printf("\nEl DNI %s no se encuentra cargado\n\n", dni);

    }

    else
    {
        mostrarPersona(vec[esta]);

        printf("\nSegura que quiere dar de baja a esta persona?\n Ingrese si para continuar:");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's')
        {
            vec[esta].isEmpty = 1;
            printf("\nBaja exitosa!\n\n");
        }

        else
        {
            printf("\nSe ha cancelado la baja\n\n");
        }

    }
    }
}


int graficoBarras(ePersona vec[], int CANT)
{
    int rango1 = 0;
    int rango2 = 0;
    int rango3 = 0;
    int i;
	int flag = 0;
	int mayor;

    for(int j=0 ; j<CANT; j++)
    {

        if(vec[j].edad > 0 && vec[j].edad <=18 && vec[j].isEmpty == 0)
        {
            rango1++;
        }

        if(vec[j].edad >= 19 && vec[j].edad <= 35 && vec[j].isEmpty == 0)
        {
            rango2++;
        }

        if(vec[j].edad > 35 && vec[j].isEmpty == 0)
        {
            rango3++;
        }
    }
    if(rango1 >= rango2 && rango1 >= rango3)
    {
        mayor = rango1;
    }
    else
    {
        if(rango2 >= rango1 && rango2 >= rango3)
        {
            mayor = rango2;
        }

        else
        {
        mayor = rango3;
        }
    }

    for(i=mayor; i>0; i--)
    {
        if(i<= rango1)
        {
            printf("*");
        }
        if(i<= rango2)
        {
            flag=1;
            printf("\t*");
        }
        if(i<= rango3)
        {
            if(flag==0)
                printf("\t\t*");

            if(flag==1)
                printf("\t*");
        }
        //Bajo una linea luego de cada iteracion
        printf("\n");
    }

    printf("<18\t19-35\t>35\n");
    return 0;

}




#endif // FUNCIONES_C_INCLUDED

