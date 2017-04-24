#include <stdio.h>
#include <stdlib.h>
#include "funcionesTP1.h"


float suma(float x, float y)
{
    return (x+y);
}


float resta(float x, float y)
{
    return (x-y);
}


float division(float x, float y)
{
    return (x/y);
}


float multiplicacion(float x, float y)
{
    return (x*y);
}


int factorial(float x)
{
    int resultado, i=(int)x;
    float j=(x-i);

    if(j!=0 || i<0)
    {
        printf("\nTiene que se un numero entero y positivo.\n");
        resultado=0;
    }
    else
    {
        if(i==0)
        {
            resultado=1;
        }
        else
        {
            resultado=i*factorial(i-1);
        }
    }
    return resultado;
}
