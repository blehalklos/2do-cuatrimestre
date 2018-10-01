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
void addEmployees(Employee empleados[], int tam, Sector sectors[], int tamSector);
void removeEmployee(Employee *empleados, int tam, Sector sectors[], int tamSector);
void modifyEmployee(Employee empleados[], int tam, Sector sectors[], int tamSector);;
int chooseSector(Sector sectors[], int tam);
void getDescription(Sector sectors[], int tamSector, int sector, char array[]);
int menu();

int main()
{

    char seguir = 's';
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
        switch(menu())
        {

        case 1:
            addEmployees(list, 1000, sectors, 5);
            system("pause");
            break;
        case 2:
            modifyEmployee(list, 1000, sectors, 5);
            break;
        case 3:
            removeEmployee(list, 1000, sectors, 5);
            break;
        case 4:
            sortEmployeeByName(list, 1000, sectors, 5);
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

void addEmployees(Employee empleados[], int tam, Sector sectors[], int tamSector)
{
    system("cls");
    Employee nuevoEmpleado;
    int indice;
    int esta;
    int Id;

    indice = findAvailable(empleados, tam);

    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        printf("Ingrese Id: ");
        scanf("%d", &Id);

        esta = findEmployeeById(empleados, tam, Id);

        if(esta != -1)
        {
            printf("Existe un empleado con el Id %d\n", Id);
            printEmployee( empleados[esta], sectors, tamSector);
        }
        else{
            nuevoEmpleado.Id = Id;

            printf("Ingrese el nombre del empleado: ");
            fflush(stdin);
            gets(nuevoEmpleado.name);

            printf("Ingrese el apellido del empleado: ");
            fflush(stdin);
            gets(nuevoEmpleado.lastName);

            printf("Ingrese el salario del empleado: ");
            fflush(stdin);
            scanf("%f", &nuevoEmpleado.salary);

            nuevoEmpleado.sector = chooseSector(sectors, 5);

            if(nuevoEmpleado.sector == 0)
            {
                printf("No existe ese sector, seleccione uno valido.\n");
            }

            else
            {
            nuevoEmpleado.isEmpty = 1;

            empleados[indice] = nuevoEmpleado;

            printf("Alta exitosa.");
            }
        }
    }

}

void printEmployee(Employee emp, Sector sectors[], int tamSector)
{
    char description[20];

    getDescription(sectors, tamSector, emp.sector, description);

    printf("%d %s %s %.2f %s \n\n", emp.Id, emp.name, emp.lastName, emp.salary, description);

}


void sortEmployeeByName(Employee nomina[], int tam, Sector sectors[], int tamSector)
{
    for(int i=0; i< tam; i++)
    {
        if( nomina[i].isEmpty == 1)
        {
            printEmployee(nomina[i], sectors, tamSector);
        }
    }
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

    printf("\nConfirma borrado?: ");
    fflush(stdin);
    scanf("%c", &borrar);
    if(borrar != 's'){
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
float newSalary;
char charAux[20];
int option;

printf("Ingrese Id: ");
scanf("%d", &Id);

indice = findEmployeeById(empleados, tam, Id);

if( indice == -1)
{
    printf("No hay ningun empleado con el Id %d\n", Id);
    system("pause");
}
else{
    printEmployee( empleados[indice], sectors, tamSector);

    printf("Que desea modificar?\n");
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
            printf("Ingrese el nuevo nombre: ");
            gets(charAux);
            strcpy(empleados[indice].name, charAux);
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
            printf("Ingrese el nuevo apellido: ");
            gets(charAux);
            strcpy(empleados[indice].lastName, charAux);
            printf("Exito!\n\n");
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
            printf("Ingrese el nuevo salario: ");
            scanf("%f", &newSalary);

            empleados[indice].salary = newSalary;
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
        printf("Ingrese una opcion valida");


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
