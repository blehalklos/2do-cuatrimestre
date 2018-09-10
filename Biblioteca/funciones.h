#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[50];
    int edad;
    int dni;
    int isEmpty;

}ePersona;

void inicializarPersona(ePersona vec[], int CANT);

void ordenar(ePersona vec[], int CANT);

void mostrarPersonas(ePersona vec[], int CANT);

void mostrarPersona(ePersona emp);

int obtenerEspacioLibre(ePersona vec[], int CANT);

int buscarPorDni(ePersona vec[], int CANT, int dni);

void altaPersona(ePersona vec[], int CANT);

void bajaPersona(ePersona vec[], int CANT);

int graficoBarras(ePersona vec[], int CANT);

int validarInt(char aux[]);

int validarCHAR (char aux []);

#endif // FUNCIONES_H_INCLUDED

