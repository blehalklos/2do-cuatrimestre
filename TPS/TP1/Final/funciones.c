#include <stdio.h>
#include <stdlib.h>
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

float sumar(float a, float b)
/** \brief suma dos numeros
 *
 * \param A
 * \param B
 * \return resultado de la suma
 *
 */

{

    float resultado;
    resultado = a + b;
    return resultado;

}

float resta(float a, float b)
/** \brief resta dos numeros
 *
 * \param A
 * \param B
 * \return resultado de la resta
 *
 */

{

   float resultado;
   resultado = a - b;
   return resultado;

}

float producto (float a, float b)
/** \brief multiplica dos numeros
 *
 * \param A
 * \param B
 * \return resultado de la multiplicacion
 *
 */

{

    float resultado;
    resultado = a * b;
    return resultado;

}

float division (float a, float b)
/** \brief divide dos numeros
 *
 * \param A
 * \param B
 * \return resultado de la division
 *
 */

{

    float resultado;
    resultado = a / b;
    return resultado;

}

float factorial (float a)
/** \brief factoriza un numero
 *
 * \param A
 * \return resultado de la factorizacion
 *
 */

{

    float resultado = 1;

    while (a > 0)
    {
        resultado = resultado * a;
        a--;
    }

    return resultado;
}

#endif // FUNCIONES_H_INCLUDED


