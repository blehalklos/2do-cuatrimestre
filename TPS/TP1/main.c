#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "funciones.c"

int main()
{
    char seguir='s';
    int opcion=0;
    float A=0; // Declarada variable float donde se guardara el primer operando como float en caso de que el user opere con numero decimales
    float B=0; // Declarada variable float donde se guardara el segundo operando como float en caso de que el user opere con numero decimales
    float resultado; // Declarada variable resultado donde iran los resultados de las operaciones
    float resultadoSuma; // Declarada variable para ser usada solo en la opcion 8
    float resultadoResta; // Declarada variable para ser usada solo en la opcion 8
    float resultadoProducto; // Declarada variable para ser usada solo en la opcion 8
    float resultadoDivision; // Declarada variable para ser usada solo en la opcion 8
    float resultadoB; // Declarada variable para ser usada solo en la opcion 8



    while(seguir=='s')
    {


        system("cls");

        printf("1- Ingresar 1er operando (A)= %.0f \n", A);
        printf("2- Ingresar 2do operando (B)= %.0f \n", B);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                system("cls");
                printf("Ingrese el 1er numero\n");
                scanf("%f", &A);

                break;

            case 2:

               system("cls");
               printf("Ingrese el 2do numero \n");
               scanf("%f", &B);

                break;

            case 3:

                system("cls");
                resultado = sumar(A,B);
                printf("El resultado de la suma es %f \n", resultado);
                system("pause");

                break;

            case 4:

                system("cls");
                resultado = resta(A,B);
                printf("El resultado de la resta es %f \n", resultado);
                system("pause");

                break;

            case 5:

                system("cls");
                if (B == 0) // Se declara un if para validar que no pueda dividirse por 0.
                    {
                        printf("No puede dividir por 0 \n");
                        system("pause");
                        break;
                    }

                resultado = division(A,B);
                printf("El resultado de la division es %.2f \n", resultado);
                system("pause");

                break;

            case 6:

                system("cls");
                resultado = producto(A,B);
                printf("El resultado de la multiplicacion es %.2f \n", resultado);
                system("pause");

                break;

            case 7:

                system("cls");
                if (A < 0) // Se declara un if para validar que no pueda factorizar un numero negativo.
                    {
                        printf("No puede factorizar un numero negativo \n");
                        system("pause");
                        break;
                    }

                    else if (A >= 13) // Se declara un if para que no sobrepase el limite de la calculadora.
                    {
                        printf("El numero a factorizar es demasiado grande, por favor use uno mas chico \n");
                        system("pause");
                        break;
                    }

                resultado = factorial(A);
                printf("El factorial de %.2f es %.2f \n", A, resultado);
                system("pause");

                break;

            case 8:

                system("cls");
                resultadoSuma = sumar(A,B);
                resultadoResta = resta(A,B);
                resultadoDivision = division(A,B);
                resultadoProducto = producto(A,B);

                printf("El resultado de la suma es %.2f \n", resultadoSuma);
                printf("El resultado de la resta es %.2f \n", resultadoResta);

                if (B == 0)  // Se declara un if para validar que no pueda dividirse por 0.
                    {
                        printf("No puede dividir por 0 \n");
                    }
                    else
                        {
                            printf("El resultado de la division es %.2f \n", resultadoDivision);
                        }

                printf("El resultado de la multiplicacion es %.2f \n", resultadoProducto);

                if (A < 0) // Se declara un if para validar que no pueda factorizar un numero negativo.
                    {
                        printf("No puede factorizar por un numero negativo \n");
                    }

                        else if (A >= 13) // Se declara un if para que no sobrepase el limite de la calculadora.
                            {
                                printf("El numero a factorizar es demasiado grande, por favor use uno mas chico \n");
                            }
                            else
                                {
                                    resultado = factorial(A);
                                    printf("El factorial de %.2f es %.2f \n", A, resultado);
                                }

                if (B < 0) // Se declara un if para validar que no pueda factorizar un numero negativo.
                    {
                        printf("No puede factorizar por un numero negativo \n");
                        system("pause");
                        break;
                    }

                        else if (B >= 13) // Se declara un if para que no sobrepase el limite de la calculadora.
                            {
                                printf("El numero a factorizar es demasiado grande, por favor use uno mas chico \n");
                            }

                            else
                                {
                                    resultadoB = factorial(B);
                                    printf("El factorial de %.2f es %.2f \n", B, resultadoB);
                                }

                system("pause");
                break;

            case 9:

                seguir = 'n';
                break;

            default:

                system("cls");
                printf("Ingrese una opcion valida de la lista por favor \n"); // Declarado un default en caso de que el User ingrese una opcion no valida
                system("pause");
        }

}
    return 0;

}





