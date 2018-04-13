#include <stdio.h>
#include <stdlib.h>
#include "limits.h"

/**
* \brief Recibe el valor de dos numeros y calcula la suma
* \param numeroUno corresponde al primer numero ingresado por el usuario
* \param numeroDos corresponde al segundo numero ingresado por el usuario
* \param resultadoSuma corresponde a la suma de los numeros ingresados
* \return si el retorno es correcto[0] o erroneo[-1]
*
*/

float sumaEnteros (float numeroUno, float numeroDos, float* resultadoSuma)
{
    float resultadoCalculo;
    int retorno=-1;

    resultadoCalculo=numeroUno+numeroDos;
    if(resultadoCalculo< INT_MAX && resultadoCalculo> INT_MIN)
    {
        *resultadoSuma=resultadoCalculo;
        retorno=0;
    }
    return retorno;
}

/**
* \brief Recibe el valor de dos numeros y calcula su division
* \param numeroUno corresponde al primer numero ingresado por el usuario
* \param numeroDos corresponde al segundo numero ingresado por el usuario
* \param resultadoDivision corresponde a la division de los numeros ingresados
* \return si el retorno es correcto[0] o erroneo[-1]
*
*/

float divisionEnteros(float numeroUno, float numeroDos,float *resultadoDivision)
{
    double resultadoCalculo;
    int retorno=-1;

    resultadoCalculo=numeroUno/numeroDos;
    if(numeroDos>0 && resultadoCalculo<INT_MAX &&resultadoCalculo>INT_MIN)
    {
        *resultadoDivision=resultadoCalculo;
        retorno=0;
    }

    return retorno;
}

/**
* \brief Recibe el valor de dos numeros y calcula la multiplicacion
* \param numeroUno corresponde al primer numero ingresado por el usuario
* \param numeroDos corresponde al segundo numero ingresado por el usuario
* \param resultadoMultiplicacion corresponde a la multiplicacion de los numeros ingresados
* \return si el retorno es correcto[0] o erroneo[-1]
*
*/

float multiplicacionEnteros(float numeroUno, float numeroDos,float* resultadoMultiplicacion)
{
    double resultadoCalculo;
    int retorno=-1;

    resultadoCalculo=numeroUno*numeroDos;
    if(resultadoCalculo<INT_MAX && resultadoCalculo>INT_MIN )
    {
        *resultadoMultiplicacion=resultadoCalculo;
        retorno=0;
    }
    return retorno;
}

/**
* \brief Recibe el valor de dos numeros y calcula la resta
* \param numeroUno corresponde al primer numero ingresado por el usuario
* \param numeroDos corresponde al segundo numero ingresado por el usuario
* \param resultadoResta corresponde a la multiplicacion de los numeros ingresados
* \return si el retorno es correcto[0] o erroneo[-1]
*
*/

float restaEnteros(float numeroUno, float numeroDos,float* resultadoResta)
{
    double resultadoCalculo;
    int retorno=-1;

    resultadoCalculo=numeroUno-numeroDos;
    if(resultadoCalculo>INT_MIN&&resultadoCalculo<INT_MAX)
    {
        *resultadoResta=resultadoCalculo;
        retorno=0;

    }

    return retorno;
}

/**
* \brief Recibe el valor de un numero y calcula el factorial
* \param numeroUno corresponde al numero ingresado por el usuario
* \return el factorial del numero ingresado
*/

float factorial(float numeroUno)
{
    int i;
    float resultadoFactorial=1;

    for(i=1;i<=numeroUno;i++)
    {
        resultadoFactorial=resultadoFactorial*i;

    }


    return resultadoFactorial;
}

