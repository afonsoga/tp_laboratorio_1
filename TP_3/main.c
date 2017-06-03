#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesTP3.h"
#define MAX_CANTIDAD 10

int main()
{
    char seguir='s';
    int opcion, lugarLibre, flag=0, buscarIndice, auxID;

    eMovie peliculaArray[MAX_CANTIDAD];
    estadoPelicula(peliculaArray,MAX_CANTIDAD,0);
    leerBinario(peliculaArray,MAX_CANTIDAD);

    while(seguir=='s')
    {
        opcion=menuOpciones();
        switch(opcion)
        {
        case 1:
            system("cls");
            lugarLibre=buscarLugarLibre(peliculaArray,MAX_CANTIDAD);
            if(lugarLibre==-1)
            {
                printf("\n\tNO QUEDAN LUGARES LIBRES\n\n");
                fflush(stdin);
                getchar();
                break;
            }
            if(flag==0)
            {
                generarID(peliculaArray,MAX_CANTIDAD);
                flag=1;
            }
            agregarPelicula(peliculaArray,lugarLibre);
            break;
        case 2:
            system("cls");
            mostrarPeliculas(peliculaArray,MAX_CANTIDAD);
            auxID=getValidInt("\n\n\nIngrese el ID de la pelicula a dar de baja: ","\nEl ID debe ser numerico\n", 1, 1000);
            buscarIndice=buscarID(peliculaArray,MAX_CANTIDAD,auxID);

            if(buscarIndice==-1)
            {
                printf("\n\tNO EXISTE EL ID INGRESADO\n\n");
                fflush(stdin);
                getchar();
                break;
            }
            borrarPelicula(peliculaArray, buscarIndice);
            break;
        case 3:
            system("cls");
            mostrarPeliculas(peliculaArray,MAX_CANTIDAD);
            printf("\n\n");

            auxID=getValidInt("\nIngrese el ID de la pelicula a modificar: ","\nEl ID debe ser numerico\n", 1, 1000);
            buscarIndice=buscarID(peliculaArray,MAX_CANTIDAD,auxID);
            if(buscarIndice==-1)
            {
                printf("\n\tNO EXISTE EL ID INGRESADO\n\n\n\n");
                fflush(stdin);
                getchar();
                break;
            }
            modificarPelicula(peliculaArray, buscarIndice);
            fflush(stdin);
            getchar();
            break;
        case 4:
            system("cls");
            generarPagina(peliculaArray, MAX_CANTIDAD);
            fflush(stdin);
            getchar();
            break;
        case 5:
            system("cls");
            guardarBinario(peliculaArray, MAX_CANTIDAD);
            fflush(stdin);
            getchar();
            seguir='n';
            break;
        default:
            break;
        }
        system("cls");
    }
    return 0;
}
