#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct //Definida estructura
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;

void inicializarPersona(Employee vec[], int CANT);

void ordenar(Employee vec[], int CANT);

void mostrarPersonas(Employee vec[], int CANT);

void mostrarPersona(Employee emp);

int obtenerEspacioLibre(Employee vec[], int CANT);

int buscarPorDni(Employee vec[], int CANT, int dni);

void altaPersona(Employee vec[], int CANT);

void bajaPersona(Employee vec[], int CANT);

int graficoBarras(Employee vec[], int CANT);

int validarInt(char aux[]);

int validarCHAR (char aux []);

#endif // FUNCIONES_H_INCLUDED

