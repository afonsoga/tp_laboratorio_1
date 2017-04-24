#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "funcionesTP2.h"

int obtenerEspacioLibre(ePersona lista[], int tam)
{
    int index=-1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].estado==-1)
        {
            index=i;
            break;
        }
    }
    return index;
}

int buscarPorDni(ePersona lista[], int tam, int dni)
{
    int index=-1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].dni==dni)
        {
            index=i;
            break;
        }
    }
    return index;
}
