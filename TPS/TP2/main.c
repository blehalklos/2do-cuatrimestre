#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 20

typedef struct //Definida estructura
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;

void intializeEmployee(Employee vec[], int CANT)
void addEmployee(Employee vec[], int CANT)
void removeEmployee(Employee vec[], int CANT)
void findEmployeeById(Employee vec[], int CANT, int id)
void sortEmployee(Employee vec[], int CANT)


int main()
{
    char seguir='s';
    int opcion=0;
    Employee employee[CANT];
    initEmployees(employee, CANT);

    while(seguir=='s')
    {
        ordenar(employee, CANT);

        fflush(stdin);
        system("cls");
        printf("1- Alta empleado\n");
        printf("2- Modificar empleado\n");
        printf("3- Baja empleado\n");
        printf("4- Informar empleados\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                addEmployee(employee, CANT);
                system("pause");
                break;

            case 2:
                removeEmployee(employee, CANT);
                system("pause");
                break;

            case 3:
                modifyEmployee(employee, CANT);
                system("pause");
                break;

            case 4:
                sortEmployee(employee, CANT);
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

void intializeEmployee(Employee vec[], int CANT)//Inicializa todos los estados en 1 del array Persona
{
    for(int i=0; i < CANT; i++)
    {
        vec[i].isEmpty = 1;
    }
}

void addEmployee(Employee vec[], int CANT)//Alta de persona
{
    Employee employee;//Inicializada variable de estructura
    int indice;
    int esta;
    char name[51];
    char lastName[51];
    int aux[51];
    float salary;
    int sector;

    system("cls");
    printf("---->Alta persona<----\n\n");

    indice = obtenerEspacioLibre(vec, CANT);//Comprobacion de espacio disponible en array

    if(indice == -1)
    {
        printf("\nEl sistema se encuentra completo, no pueden agregrase nuevas personas.\n\n");
    }

    else
    {
        printf("Ingrese el nombre de la persona: ");
        gets(name);
        fflush(stdin);

        if(validarCHAR(name) == 0)//Validacion de char
        {
            printf(" Por favor reingrese los datos\n");
        }

        else
        {
        strcpy(Employee.name, name);

        printf("Ingrese el apellido de la persona: ");
        gets(lastName);
        fflush(stdin);

        if(validarCHAR(lastName) == 0)//Validacion de char
        {
            printf(" Por favor reingrese los datos\n");
        }

        else
        {
        strcpy(Employee.lastNamename, lastName);

        printf("Ingrese el salario de la persona: ");
        scanf("%s", aux);
        fflush(stdin);

        Employee.salary = salary;
        fflush(stdin);

        vec[indice] = employee;

        printf("\nAlta exitosa!\n\n");
        }
        }
    }
}

void removeEmployee(Employee vec[], int CANT)//Baja logica de persona
{
    int id;
    int aux[20];
    int esta;
    char confirma;

    system("cls");
    printf("---->Baja persona<----\n\n");

    printf("Ingrese Id: ");
    scanf("%s", aux);

    id = validarInt(aux);//Validacion de Int

    if(id == 0)
    {
        printf(" por favor reingrese los datos\n");
    }

    else
    {

        fflush(stdin);

        esta = findEmployeeById(vec, CANT, id);//Devuelve si se encuentra ingresado el DNI cargado

    if(esta == -1)
    {
        printf("\nEl Id %s no se encuentra cargado\n\n", id);

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

void sortEmployee(Employee vec[], int CANT) // Devuelve todos los elementos dentro del array ordenados por name
{

void mostrarPersona(Employee emp)//Devuelve los datos dentro del array
{
    printf("  %d     %3d      %10d\n", emp.id, emp.name, emp.lastName, emp.salary);
}
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
                if(vec[i].id < vec[j].id)// Swap del dni acorde al swap de los names
                {
                    auxiliar = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxiliar;
                }

                else if(vec[i].id < vec[j].id)// Swap de la edad acorde a los names
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
