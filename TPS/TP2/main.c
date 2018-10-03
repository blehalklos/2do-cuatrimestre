#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


typedef struct
{
    int Id;
    char name[20];
    char lastName[20];
    float salary;
    int sector;
    int isEmpty;
} Employee;


typedef struct{
    int id;
    char description[20];
}Sector;


void initEmployees( Employee x[], int tam);
int findAvailable( Employee x[], int tam);
int findEmployeeById(Employee x[], int tam, int Id);
void printEmployee(Employee emp, Sector sectors[], int tamSector);
void sortEmployeeByName(Employee nomina[], int tam, Sector sectors[], int tamSector);
void addEmployees(Employee empleados[], int tam, Sector sectors[], int tamSector, int idFlag);
void removeEmployee(Employee *empleados, int tam, Sector sectors[], int tamSector);
void modifyEmployee(Employee empleados[], int tam, Sector sectors[], int tamSector);;
int chooseSector(Sector sectors[], int tam);
void getDescription(Sector sectors[], int tamSector, int sector, char array[]);
int validarCHAR (char aux []);
float validarNumeroFlotante(char aux[]);
int validarLargoCadena(char aux[],int  LargoMaximo);
void ordenar(Employee vec[], int CANT);
int menu();


int main()
{

    char seguir = 's';
    int idFlag = 0;
    Employee list[1000];
    Sector sectors[] = {
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Compras"},
        {4, "Contable"},
        {5, "Sistemas"}
        };

    initEmployees(list, 1000);


    do
    {
        ordenar(list, 1000);

        switch(menu())
        {

        case 1:
            idFlag++;
            addEmployees(list, 1000, sectors, 5, idFlag);
            system("pause");
            break;

        case 2:
            if(idFlag == 0)
            {
                system("cls");
                printf("Primero debe de ingresar un empleado.\n\n");
                system("pause");
            }
            else
            {
                modifyEmployee(list, 1000, sectors, 5);
            }
            break;

        case 3:
            if(idFlag == 0)
            {
                system("cls");
                printf("Primero debe de ingresar un empleado.\n\n");
                system("pause");
            }
            else
            {
            removeEmployee(list, 1000, sectors, 5);
            }
            break;

        case 4:
            if(idFlag == 0)
            {
                system("cls");
                printf("Primero debe de ingresar un empleado.\n\n");
                system("pause");
            }
            else
            {
            sortEmployeeByName(list, 1000, sectors, 5);
            }
            system("pause");
            break;
        case 5:
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

void initEmployees( Employee x[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        x[i].isEmpty = 0;
    }
}


int findAvailable( Employee x[], int tam)
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


int findEmployeeById(Employee x[], int tam, int Id)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {


        if( x[i].Id == Id && x[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int menu()
{


    int opcion;
    system("cls");
    printf("ABM\n");
    printf("\n");
    printf("1- Alta\n");
    printf("2- Modificar\n");
    printf("3- Baja\n");
    printf("4- Informar\n");
    printf("5- Salir\n");
    printf("\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


void addEmployees(Employee empleados[], int tam, Sector sectors[], int tamSector, int idFlag)
{
    system("cls");
    Employee nuevoEmpleado;
    int indice;
    char aux[20];

    indice = findAvailable(empleados, tam);

    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {

        printf("Ingrese el nombre del empleado: ");
        fflush(stdin);
        gets(aux);

        if(validarLargoCadena(aux, 19) == 1)
        {
            printf("Error, el nombre es muy largo.\n\n");
        }

        else
        {
            if(validarCHAR(aux) == 0)
            {
                printf("Error, dato no valido.\n\n");

            }

            else
            {
                strcpy(nuevoEmpleado.name, aux);

                printf("Ingrese el apellido del empleado: ");
                fflush(stdin);
                gets(aux);

                if(validarLargoCadena(aux, 19) == 1)
                {
                    printf("Error, el nombre es muy largo.\n\n");
                }

                else
                {

                    if(validarCHAR(aux) == 0)
                    {
                        printf("Error, dato no valido.\n\n");
                    }

                    else
                    {

                        strcpy(nuevoEmpleado.lastName, aux);

                        printf("Ingrese el salario del empleado: ");
                        fflush(stdin);

                        nuevoEmpleado.salary = validarNumeroFlotante(aux);

                        nuevoEmpleado.sector = chooseSector(sectors, 5);

                        if(nuevoEmpleado.sector == 0)
                        {
                            printf("No existe ese sector, seleccione uno valido.\n");
                        }

                        else
                        {

                            nuevoEmpleado.Id = idFlag;

                            nuevoEmpleado.isEmpty = 1;

                            empleados[indice] = nuevoEmpleado;

                            printf("Alta exitosa.");
                        }
                    }
                }
            }
        }
    }
}


void ordenar(Employee vec[], int CANT)
{
    Employee auxiliar;
    int i;
    int j;

    for(i=0;i<CANT-1;i++)
    {

        for(j=i+1;j<CANT-1;j++)
        {

            if(vec[i].sector < vec[j].sector)
            {
                    auxiliar = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxiliar;
            }

            if(strcmp(vec[i].lastName, vec[j].lastName)>0)
            {
                auxiliar = vec[i];
                vec[i] = vec[j];
                vec[j] = auxiliar;

            }

            else
            {

            if(strcmp(vec[i].lastName, vec[j].lastName)== 0)

            {
                if(vec[i].name < vec[j].name)
                {
                    auxiliar = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxiliar;
                }

                else if(vec[i].salary < vec[j].salary)
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


void printEmployee(Employee emp, Sector sectors[], int tamSector)
{
    char description[20];

    getDescription(sectors, tamSector, emp.sector, description);

    printf("%d %s %s %.2f %s \n\n", emp.Id, emp.lastName, emp.name, emp.salary, description);

}


void sortEmployeeByName(Employee nomina[], int tam, Sector sectors[], int tamSector)
{

    float totalSalarios = 0;
    float promedioSalarios = 0;
    int flag = 0;
    int flagPromedioSuperado = 0;

    for(int i=0; i< tam; i++)
    {
        if( nomina[i].isEmpty == 1)
        {
            printEmployee(nomina[i], sectors, tamSector);
        }
    }

    for (int i=0; i< tam; i++)
    {
        if( nomina[i].isEmpty == 1)
        {
            flag++;
            totalSalarios = totalSalarios + nomina[i].salary;
        }
    }
    promedioSalarios = totalSalarios / flag;

    for (int i=0; i< tam; i++)
    {
        if( nomina[i].isEmpty == 1)
        {
            if(nomina[i].salary > promedioSalarios)
            {
                flagPromedioSuperado++;
            }
        }
    }
    printf("El total de los salarios es de: %.2f, su promedio es: %.2f y %d empleados superan dicho promedio.\n\n", totalSalarios, promedioSalarios, flagPromedioSuperado);
}


void removeEmployee(Employee empleados[], int tam, Sector sectors[], int tamSector)
{

int Id;
int indice;
char borrar;

printf("Ingrese Id: ");
scanf("%d", &Id);

indice = findEmployeeById(empleados, tam, Id);

if( indice == -1){
    printf("No hay ningun empleado con el Id %d\n", Id);
}
else{
    printEmployee( empleados[indice], sectors, tamSector);

    printf("\nConfirma borrado?('S' para confirmar - 'N' para cancelar): ");
    fflush(stdin);
    scanf("%c", &borrar);
    if(borrar != 's' && borrar != 'S')
    {
        printf("Borrado cancelado\n\n");
    }
    else{
        empleados[indice].isEmpty = 0;
        printf("Se ha eliminado el empleado\n\n");
    }
    system("pause");
}

}


void modifyEmployee(Employee empleados[], int tam, Sector sectors[], int tamSector)
{

    int Id;
    int indice;
    char modificar;
    char aux[20];
    int option;

    printf("Ingrese Id: ");
    scanf("%d", &Id);

    indice = findEmployeeById(empleados, tam, Id);

    if( indice == -1)
    {
        printf("No hay ningun empleado con el Id %d\n", Id);
        system("pause");
    }

    else
    {
        printEmployee( empleados[indice], sectors, tamSector);

        printf("\nQue desea modificar?\n");
        printf("1- Nombre\n");
        printf("2- Apellido\n");
        printf("3- Salario\n");
        printf("4- Sector\n");

        scanf("%d", &option);

    switch(option)
    {
        case 1:
            printf("\nDesea modificar el nombre?('S' para continuar - 'N' para cancelar): ");
            fflush(stdin);
            scanf("%c", &modificar);
            if(modificar != 's')
            {
                printf("Modificacion cancelada\n\n");
            }

            else
            {
                fflush(stdin);
                printf("\nIngrese el nuevo nombre del empleado: ");
                gets(aux);

                if(validarLargoCadena(aux, 19) == 1)
                {
                    printf("Error, el nombre es muy largo.\n\n");
                }

                else
                {
                    if(validarCHAR(aux) == 0)
                    {
                        printf("Error, dato no valido.\n\n");
                    }

                    else
                    {
                        strcpy(empleados[indice].name, aux );

                        printf("Exito!\n\n");
                    }

            system("pause");
            break;

    case 2:
        printf("\nDesea modificar el apellido?('S' para continuar - 'N' para cancelar): ");
        fflush(stdin);
        scanf("%c", &modificar);
        if(modificar != 's')
        {
            printf("Modificacion cancelada\n\n");
        }

        else
        {
            fflush(stdin);
            printf("Ingrese el nuevo apellido del empleado: ");
            gets(aux);

            if(validarLargoCadena(aux, 19) == 1)
                {
                    printf("Error, el nombre es muy largo.\n\n");
                }

                else
                {
                    if(validarCHAR(aux) == 0)
                    {
                        printf("Error, dato no valido.\n\n");
                    }

                    else
                    {
                        strcpy(empleados[indice].lastName, aux);
                        printf("Exito!\n\n");
                    }
                }
        }
        system("pause");
        break;

    case 3:
        printf("\nDesea modificar el salario?('S' para continuar - 'N' para cancelar): ");
        fflush(stdin);
        scanf("%c", &modificar);
        if(modificar != 's')
        {
            printf("Modificacion cancelada\n\n");
        }

        else
        {
            printf("Ingrese el nuevo salario del empleado: ");
            fflush(stdin);

            empleados[indice].salary = validarNumeroFlotante(aux);

            printf("Exito!\n\n");
        }
        system("pause");
        break;

    case 4:

        printf("\nDesea modificar el sector?('S' para continuar - 'N' para cancelar): ");
        fflush(stdin);
        scanf("%c", &modificar);
        if(modificar != 's')
        {
            printf("Modificacion cancelada\n\n");
        }

        else
        {
            empleados[indice].sector = chooseSector(sectors, 5);
            printf("Exito!\n\n");
        }

        system("pause");
        break;

    default:
        printf("Ingrese una opcion valida\n\n");
        system("pause");


                }
            }
        }
    }
}


int chooseSector(Sector sectors[], int tam)
{
    int sector;
    printf("\nSectores\n\n");
    for(int i=0; i < tam; i++){
        printf("%d %s\n", sectors[i].id, sectors[i].description);
    }
    printf("\nSeleccione sector: ");
    scanf("%d", &sector);

    if(sector >= 6 || sector < 1)
    {
        sector = 0;
    }

    return sector;

}


void getDescription(Sector sectors[], int tamSector, int sector, char array[])
{

    for(int i=0; i < tamSector; i++){
        if( sectors[i].id == sector){

            strcpy(array, sectors[i].description);
            break;
        }
    }


}


int validarCHAR (char aux [])
{
    int i;
    int letras;
    letras = strlen(aux);

    for (i=0; i<letras; i++)
    {
        if(!(isalpha(aux[i])))
        {
            if(aux[i] != ' ')
            {
                    return 0;
            }
        }
    }

    return 1;
}


float validarNumeroFlotante(char aux[])
{
    int validar;
    float numero;
    int i;
    long tam=256;
    char numeroCadena[tam];
    int tamCadena;

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
            printf("Error ,ingrese un numero valido: ");
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


int validarLargoCadena(char aux[],int  LargoMaximo)
{
            int largoCadena;
            largoCadena=strlen(aux);
            if(largoCadena<LargoMaximo)
            {
               return 0;
            }
            else
            {
                return 1;

            }
}
