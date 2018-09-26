#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef FUNCIONES_C_INCLUDED
#define FUNCIONES_C_INCLUDED

typedef struct //Definida estructura
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;


void intializeEmployee(Employee vec[], int CANT)//Inicializa todos los estados en 1 del array Persona
{
    for(int i=0; i < CANT; i++)
    {
        vec[i].isEmpty = 1;
    }
}


void ordenar(Employee vec[], int CANT) // Devuelve todos los elementos dentro del array ordenados por name
{
    Employee auxiliar;
    int i;
    int j;

    for(i=0;i<CANT;i++)
    {

        for(j=i+1;j<CANT;j++)//Declaracion del for para el burbujeo
        {

            if(strcmp(vec[i].name, vec[j].name)>0)//Devuelve si el primer elemento es mayor que el segundo
            {
                auxiliar = vec[i];//Swap de los names
                vec[i] = vec[j];
                vec[j] = auxiliar;

            }

            else
            {

            if(strcmp(vec[i].name, vec[j].name)== 0)

            {
                if(vec[i].dni < vec[j].dni)// Swap del dni acorde al swap de los names
                {
                    auxiliar = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxiliar;
                }

                else if(vec[i].edad < vec[j].edad)// Swap de la edad acorde a los names
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


void mostrarPersonas(Employee vec[], int CANT)//Devuelve las personas dentro del array por name edad y dni
{
    system("cls");
    printf("---Lista de Personas---\n\n");
    printf("        name           Edad      DNI\n\n");

    for(int i=0; i< CANT; i++)//Inicializado for para comprobar que elemento del array esta ocupado
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarPersona(vec[i]);//Llamada de funcion mostrarPersona de vec[i]
        }
    }
}

void mostrarPersona(Employee emp)//Devuelve los datos dentro del array
{
    printf("  %s     %3d      %10d\n", emp.name, emp.edad, emp.dni);
}


int obtenerEspacioLibre(Employee vec[], int CANT)//Devuelve que espacio dentro del array se encuentra libre
{
    int indice = -1;

    for(int i=0; i < CANT; i++)//for para recorrer el array
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;//Devuelve el indice en caso que sea = 1
            break;
        }
    }

    return indice;
}


int findEmployeeById(Employee vec[], int CANT, int id)//Busqueda de los elementos dni dentro de los arrays
{
    int indice = -1;

    for(int i=0; i < CANT; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].id == id)//Si el estado del array es 0 y el dni ingresado es igual al dni dentro del array
        {
            indice = i;
            break;
        }
    }

    return indice;//Devuelve el indice en el que se encuentra
}


int validarInt(char aux[])//Validacion de Int
{
    int i;
    int numero;

    for(i=0; i<strlen(aux); i++)//For para determinar si fue ingresado un char o un elemento especial
        if (!(isdigit (aux[i])))
        {
            printf("La cantidad no es valida");
            return 0;//devuelve un error
        }

    numero=atoi(aux);
    if(numero < 1)//Condicional para que no sea ingresado un numero igual o menor a 0
    {
        printf("La cantidad debe ser mayor a 0");
        return 0;//devuelve un error
    }
    return numero;//Devuelve el numero comprobado sin errores
}


int validarCHAR (char aux [])//Validacion de Caracter
{
    int i;
    int letras;
    letras = strlen(aux);

    if(letras > 50)//Condicion para determinar si los elementos exceden el tamaño de la cadena
    {
        printf("La descripcion es demasiado larga.\n");
        return 0;//devuelve un error
    }

    for (i=0; i<letras; i++)
    {
        if(!(isalpha(aux[i])))//Condicional para determinar que ningun int o elemento especial haya sido ingresado
        {
            if(aux [i] != ' ')
            {
                    printf("La descripcion no es valido.\n");
                    return 0;//devuelve un error
            }
        }
    }

    return 1;//Devuelve la cadena comprobada sin errores
}

void altaPersona(Employee vec[], int CANT)//Alta de persona
{
    Employee nuevaPersona;//Inicializada variable de estructura
    int indice;
    int esta;
    char name[50];
    int aux[50];
    int dni;
    int edad;

    system("cls");
    printf("---->Alta persona<----\n\n");

    indice = obtenerEspacioLibre(vec, CANT);//Comprobacion de espacio disponible en array

    if(indice == -1)
    {
        printf("\nEl sistema se encuentra completo, no pueden agregrase nuevas personas, disculpe.\n\n");
    }

    else
    {
        printf("Ingrese DNI: ");
        scanf("%s", aux);
        fflush(stdin);

        dni = validarInt(aux);//Validacion de Int

        if(dni == 0)
        {
            printf(" por favor reingrese los datos\n");
        }

        else
        {

        esta = buscarPorDni(vec, CANT, dni);//Comprobacion de DNI si ya se encuentra repetido

        if(esta != -1)
        {
            printf("\nEl DNI %d ya se encuentra en el sistema\n", dni);
            mostrarPersona(vec[esta]);//Devuelve el DNI ya ingresado con su respectiva informacion
        }

        else
        {
            nuevaPersona.isEmpty = 0;
            nuevaPersona.dni = dni;

            printf("Ingrese el name de la persona: ");
            gets(name);
            fflush(stdin);

            if(validarCHAR(name) == 0)//Validacion de char
            {
                printf(" Por favor reingrese los datos\n");
            }

            else
            {
            strcpy(nuevaPersona.name, name);

            printf("Ingrese la edad de la persona: ");
            scanf("%s", aux);
            fflush(stdin);

            edad = validarInt(aux);//Validacion de int

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


void bajaPersona(Employee vec[], int CANT)//Baja logica de persona
{
    int dni;
    int aux[20];
    int esta;
    char confirma;

    system("cls");
    printf("---->Baja persona<----\n\n");

    printf("Ingrese DNI: ");
    scanf("%s", aux);

    dni = validarInt(aux);//Validacion de Int

    if(dni == 0)
    {
        printf(" por favor reingrese los datos\n");
    }

    else
    {

        fflush(stdin);

        esta = buscarPorDni(vec, CANT, dni);//Devuelve si se encuentra ingresado el DNI cargado

    if(esta == -1)
    {
        printf("\nEl DNI %s no se encuentra cargado\n\n", dni);

    }

    else
    {
        mostrarPersona(vec[esta]);//Devuelve los datos dentro del array correspondiente

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

int graficoBarras(Employee vec[], int CANT)//Codigo de barras
{
    int rango1 = 0;
    int rango2 = 0;
    int rango3 = 0;
    int i;
	int flag = 0;
	int mayor;

    for(int j=0 ; j<CANT; j++)//For que recorre los elementos dentro del array
    {

        if(vec[j].edad > 0 && vec[j].edad <=18 && vec[j].isEmpty == 0)//Condicion que determina si cumple con los rangos propuestos,
        {
            rango1++;
        }

        if(vec[j].edad >= 19 && vec[j].edad <= 35 && vec[j].isEmpty == 0)//Condicion que determina si cumple con los rangos propuestos,
        {
            rango2++;
        }

        if(vec[j].edad > 35 && vec[j].isEmpty == 0)//Condicion que determina si cumple con los rangos propuestos,
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
