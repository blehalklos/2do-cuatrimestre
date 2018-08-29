#include <stdio.h>
#include <stdlib.h>
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

float sumar(float a, float b) // Funcion sumar permite sumar dos enteros A y B.
{

    float resultado; // Declarada la variable resultado donde se guardara el mismo.
    resultado = a + b; // Guarda el resultado de la operacion dentro de la variable resultado.
    return resultado; // Devuelve el mismo.

}

float resta(float a, float b) // Funcion resta permite restar dos enteros A y B.
{

   float resultado; // Declara la variable resultado donde se guardara el mismo.
   resultado = a - b; // Guarda el resultado de la operacion dentro de la variable resultado.
   return resultado; // Devuelve el mismo.

}

float producto (float a, float b) // Funcion producto permite multiplicar dos enteros A y B.
{

    float resultado; // Declara la variable resultado donde se guardara el mismo.
    resultado = a * b; // Guarda el resultado de la operacion dentro de la variable resultado.
    return resultado; // Devuelve el mismo.

}

float division (float a, float b) // Funcion division permite dividir dos decimales A y B.
{

    float resultado; // Declara la variable resultado donde se guardara el mismo.
    resultado = a / b; // Guarda el resultado de la operacion dentro de la variable resultado.
    return resultado; // Devuelve el mismo.

}

float factorial (float a) // Funcion factorial permite devolver el factorial de un entero.
{

    float resultado = 1; // Declara la variable resultado con valor 1.

    while (a > 0) // Se declara una validacion para que se efectue la operacion hasta que sea igual a 0 y no entre si es negativo.
    {
        resultado = resultado * a; // Multiplica el entero A por el valor dentro de la variable resultado.
        a--; // Resta 1 al entero dentro de A .
    }

    return resultado; // Devuelve resultado.
}

#endif // FUNCIONES_H_INCLUDED


