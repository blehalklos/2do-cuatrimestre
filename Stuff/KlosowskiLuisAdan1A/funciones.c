#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef FUNCIONES_C_INCLUDED
#define FUNCIONES_C_INCLUDED

typedef struct
{
    int codigoProveedor;
    char descripcion[50];

}eProveedor;


typedef struct
{
    int codigoProducto;
    char descripcionProducto[50];
    float importe;
    int cantidad;
    int isEmpty;

}eProducto;


/*void hardCode(eSector vec[])
{
    vec[0].id=1;
    strcpy(vec[0].descripcionProducto,"RRHH");
    vec[0].isEmpty=0;

    vec[1].id=2;
    strcpy(vec[1].descripcionProducto,"sistema");
    vec[1].isEmpty=0;

    vec[2].id=3;
    strcpy(vec[2].descripcionProducto,"administracion");
    vec[2].isEmpty=0;

    vec[3].id=4;
    strcpy(vec[3].descripcionProducto,"compras");
    vec[3].isEmpty=0;

    vec[4].id=5;
   strcpy(vec[4].descripcionProducto,"deposito");
    vec[4].isEmpty=0;
}*/


float sumar(float a, float b) // Funcion sumar permite sumar dos enteros A y B.
{

    float resultado; // Declarada la variable resultado donde se guardara el mismo.
    resultado = a + b; // Guarda el resultado de la operacion dentro de la variable resultado.
    return resultado; // Devuelve el mismo.

}


void inicializarProducto(eProducto vec[], int CANT)
{
    for(int i=0; i < CANT; i++)
    {
        vec[i].isEmpty = 1;
    }
}


void ordenar(eProducto vec[], int CANT)
{
    eProducto auxiliar;
    int i;
    int j;

    for(i=0;i<CANT;i++)
    {

        for(j=i+1;j<CANT;j++)
        {

            if(strcmp(vec[i].descripcionProducto, vec[j].descripcionProducto)>0)
            {
                auxiliar = vec[i];
                vec[i] = vec[j];
                vec[j] = auxiliar;

            }

            else
            {

            if(strcmp(vec[i].descripcionProducto, vec[j].descripcionProducto)== 0)

            {
                if(vec[i].codigoProducto < vec[j].codigoProducto)
                {
                    auxiliar = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxiliar;
                }

                else if(vec[i].importe < vec[j].importe)
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


void mostrarProduto(eProducto vec[], int CANT)
{
    system("cls");
    printf("---Lista de Personas---\n\n");
    printf("        Nombre           Edad      DNI\n\n");

    for(int i=0; i< CANT; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarProducto(vec[i]);
        }
    }
}


void mostrarProducto(eProducto emp)
{
    printf("  %d     %s     %0.2f      %d      \n", emp.codigoProducto, emp.descripcionProducto, emp.importe, emp.cantidad);
}


int obtenerEspacioLibre(eProducto vec[], int CANT)
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


int buscarProducto(eProducto vec[], int CANT, int codigoProducto)
{
    int indice = -1;

    for(int i=0; i < CANT; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].codigoProducto == codigoProducto)
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


float validarNumeroFlotante(char mensaje[])
{
    int validar;
    float numero;
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
}


int validarCHAR (char descripcionProducto [])
{
    int i;
    int letras;
    letras = strlen(descripcionProducto);

    if(letras > 50)
    {
        printf("La descripcion del producto es demasiado larga.\n");
        return 0;
    }

    for (i=0; i<letras; i++)
    {
        if(!(isalpha(descripcionProducto[i])))
        {
            if(descripcionProducto [i] != ' ')
            {
                    printf("La descripcion del producto no es valida.\n");
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


void altaProducto(eProducto vec[], int CANT)
{
    eProducto nuevoProducto;
    int indice;
    char descripcionProducto[50];
    char aux[50];
    int codigoProducto;
    float importe;
    int cantidad;
    int esta;

    system("cls");
    printf("---->Alta producto<----\n\n");

    indice = obtenerEspacioLibre(vec, CANT);

    if(indice == -1)
    {
        printf("\nEl sistema se encuentra completo, no pueden agregrase nuevas personas, disculpe.\n\n");
    }

    else
    {
        printf("Ingrese el codigo del producto: ");
        scanf("%s", aux);
        fflush(stdin);

        codigoProducto = validarInt(aux);

        if(codigoProducto == 0)
        {
            printf(" por favor reingrese los datos\n");
        }

        else
        {

        esta = buscarProducto(vec, CANT, codigoProducto);

        if(esta != -1)
        {
            printf("\nEl codigo %d ya se encuentra en el sistema\n", codigoProducto);
            mostrarProducto(vec[esta]);
        }

        else
        {
        nuevoProducto.isEmpty = 0;
        nuevoProducto.codigoProducto = codigoProducto;

        fflush(stdin);
        printf("Ingrese la descripcion del producto: ");
        gets(descripcionProducto);

        fflush(stdin);
        if(validarCHAR(descripcionProducto) == 0)
        {
            printf(" Por favor reingrese los datos\n");
        }

        else
        {
            strcpy(nuevoProducto.descripcionProducto, descripcionProducto);

            fflush(stdin);
            importe=(validarNumeroFlotante("ingrese el importe: "));

            nuevoProducto.importe = importe;

            fflush(stdin);
            printf("Ingrese la cantidad del producto: ");
            scanf("%s", aux);

            cantidad = validarInt(aux);
            nuevoProducto.cantidad = cantidad;

            vec[indice] = nuevoProducto;


            printf("\nAlta exitosa!\n\n");
        }
    }
    }
    }
}

void bajaProducto(eProducto vec[], int CANT)
{
    int codigoProducto;
    int aux[20];
    int esta;
    char confirma;

    system("cls");
    printf("---->Baja persona<----\n\n");

    printf("Ingrese el codigo del producto: ");
    scanf("%s", aux);

    codigoProducto = validarInt(aux);

    if(codigoProducto == 0)
    {
        printf(" por favor reingrese los datos\n");
    }

    else
    {

        fflush(stdin);

        esta = buscarProducto(vec, CANT, codigoProducto);

    if(esta == -1)
    {
        printf("\nEl producto %s no se encuentra cargado\n\n", codigoProducto);

    }

    else
    {
        mostrarProducto(vec[esta]);

        printf("\nSegura que quiere dar de baja este producto?\n Ingrese si para continuar:");
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


int graficoBarras(eProducto vec[], int CANT)
{
    int rango1 = 0;
    int rango2 = 0;
    int rango3 = 0;
    int i;
	int flag = 0;
	int mayor;

    for(int j=0 ; j<CANT; j++)
    {

        if(vec[j].importe > 0 && vec[j].importe <=18 && vec[j].isEmpty == 0)
        {
            rango1++;
        }

        if(vec[j].importe >= 19 && vec[j].importe <= 35 && vec[j].isEmpty == 0)
        {
            rango2++;
        }

        if(vec[j].importe > 35 && vec[j].isEmpty == 0)
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


void modificarProducto(eProducto vec[], int CANT)
{
    eProducto nuevoProducto;
    char descripcionProducto[50];
    float importe;
    int opcion;
    int codigoProducto;
    int aux[20];
    int esta;
    int cantidad;
    char confirma;
    int flag=1;
    int indice;

    system("cls");
    printf("---->Modificar producto<----\n\n");

    printf("Ingrese el codigo del producto: ");
    scanf("%s", aux);

    codigoProducto = validarInt(aux);

    if(codigoProducto == 0)
    {
        printf(" por favor reingrese los datos\n");
    }

    else
    {

        fflush(stdin);

        esta = buscarProducto(vec, CANT, codigoProducto);

        if(esta == -1)
        {
            printf("\nEl producto %s no se encuentra cargado\n\n", codigoProducto);
        }

        else
        {

        fflush(stdin);
        system("cls");
        printf("---->Modificar producto<----\n\n");

        mostrarProducto(vec[esta]);

        printf("Que desea modificar?\n");
        printf("1- Descripcion\n");
        printf("2- Importe\n");
        printf("3- Cantidad\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                fflush(stdin);
                printf("Ingrese la nueva descripcion del producto:  ");
                gets(descripcionProducto);

                if(validarCHAR(descripcionProducto) == 0)
                {
                    printf(" Por favor reingrese los datos\n");
                }

                else
                {
                        strcpy(vec[esta].descripcionProducto,descripcionProducto);
                        printf("Modificacion exitosa!\n\n");

                }

                break;

            case 2:
                fflush(stdin);
                importe=(validarNumeroFlotante("ingrese el nuevo importe: "));
                vec[esta].importe = importe;
                printf("Modificacion exitosa!\n\n");

                break;

            case 3:
                fflush(stdin);
                printf("Ingrese la nueva cantidad del producto: ");
                scanf("%s", aux);

                cantidad = validarInt(aux);
                vec[esta].cantidad = cantidad;

                printf("Modificacion exitosa!\n\n");

                break;

            default:
                printf("Opcion no valida, por favor reingrese una opcion de la lista.\n");
                system("pause");


            }

        }
    }
}

int informarProducto(eProducto vec[], int CANT)
{

   int tam=100;
   int i;
   int val=0;
   int mayor;
   float total=0;
   float promedio=0;
   int totalStock=0;
   int contador=0;
   int noSuperoPromedio=0;
   int productosMayor10=0;
   int productosMenor10=0;

   for(i=0; i < tam; i++)
   {
       if(vec[i].isEmpty == 1)
       {
           total = total + vec[i].importe;
           totalStock = totalStock + vec[i].cantidad;
       }
   }
          printf("%0.2f\n", &total);
          printf("%d\n", &totalStock);
}

#endif // FUNCIONES_C_INCLUDED

