#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

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

float sumar(float a, float b);

void inicializarPersona(eProducto vec[], int CANT);

void ordenar(eProducto vec[], int CANT);

void mostrarPersonas(eProducto vec[], int CANT);

void mostrarPersona(eProducto emp);

int obtenerEspacioLibre(eProducto vec[], int CANT);

int buscarPorDni(eProducto vec[], int CANT, int dni);

void altaProducto(eProducto vec[], int CANT);

void bajaProducto(eProducto vec[], int CANT);

int graficoBarras(eProducto vec[], int CANT);

int validarInt(char aux[]);

int validarCHAR (char aux []);

void moficarProducto(eProducto vec[], int CANT);

int informarProducto(eProducto vec[], int CANT);

#endif // FUNCIONES_H_INCLUDED

