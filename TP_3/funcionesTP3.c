#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesTP3.h"

void estadoPelicula(eMovie* peliculaArray,int tam,int valor)
{
    int i;
    if(peliculaArray!=NULL && tam>0)
    {
        for(i=0; i<tam; i++)
        {
            peliculaArray[i].estado=valor;
        }
    }
}

int buscarLugarLibre(eMovie* peliculaArray,int tam)
{
    int i;
    if(peliculaArray!=NULL && tam>0)
    {
        for(i=0; i<tam; i++)
        {
            if(peliculaArray[i].estado==0)
            {
                return i;
            }
        }
    }
    return -1;
}

int buscarID(eMovie* peliculaArray,int tam,char auxID)
{
    int i;
    if(peliculaArray!=NULL && tam>0)
    {
        for(i=0; i<tam; i++)
        {
            if(peliculaArray[i].id==auxID && peliculaArray[i].estado==1)
            {
                return i;
            }
        }
    }
    return -1;
}

int menuOpciones()
{
    int opcion, aux;

    printf("\n--=--=--=--=--=-- MENU --=--=--=--=--=--\n");
    printf("\n1. AGREGAR PELICULA\n");
    printf("2. BORRAR PELICULA\n");
    printf("3. MODIFICAR PELICULA\n");
    printf("4. GENERAR PAGINA WEB\n");
    printf("5. SALIR\n");
    printf("\nOPCION: ");
    scanf("%d", &aux);

    while(aux<1 || aux>5)
    {
        printf("\nERROR. Opcion no valida. Reingrese: ");
        scanf("%d", &aux);
    }
    opcion=aux;
    return opcion;
}

void generarID(eMovie* peliculaArray,int tam)
{
    int i;
    int j;
    peliculaArray[0].id=1;

    if(peliculaArray!=NULL && tam>0)
    {
        for(i=0; i<tam; i++)
        {
            for(j=i+1; j<tam; j++)
            {
                peliculaArray[j].id=peliculaArray[i].id+1;
            }
        }
    }
}

int esAlfaNumerico(char nombre[])
{
    int i=0;
    while(nombre[i] != '\0')
    {
        if((nombre[i] != ' ') && (nombre[i] < 'a' || nombre[i] > 'z') && (nombre[i] < 'A' || nombre[i] > 'Z') && (nombre[i] < '0' || nombre[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}

void obtenerTitulo(char aux[])
{
    printf("\nIngrese titulo: ");
    fflush(stdin);
    gets(aux);
    esAlfaNumerico(aux);
    while(strlen(aux)>29)
    {
        printf("ERROR. Titulo no valido. Reingrese: ");
        fflush(stdin);
        gets(aux);
        esAlfaNumerico(aux);
    }
}

void obtenerGenero(char aux[])
{
    printf("\nIngrese genero: ");
    fflush(stdin);
    gets(aux);
    esAlfaNumerico(aux);
    while(strlen(aux)>29)
    {
        printf("ERROR. Genero no valido. Reingrese: ");
        fflush(stdin);
        gets(aux);
        esAlfaNumerico(aux);
    }
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if (!getStringNumeros(requestMessage,auxStr))
        {
            printf ("%s\n",errorMessage);
            continue;
        }
        auxInt = atoi(auxStr);
        if(auxInt < lowLimit || auxInt > hiLimit)
        {
            printf ("El valor debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;
        }
        return auxInt;
    }
}

void agregarPelicula(eMovie* peliculaArray,int indice)
{
    char auxTitulo[30];
    char auxGenero[30];
    int auxDuracion;
    char auxDescripcion[500];
    int auxPuntaje;
    char auxlinkImagen[100];

    obtenerTitulo(auxTitulo);
    strcpy(peliculaArray[indice].titulo,auxTitulo);

    obtenerGenero(auxGenero);
    strcpy(peliculaArray[indice].genero,auxGenero);

    auxDuracion=getValidInt("\nIngrese duracion: ","\nLA DURACION DEBE SER NUMERICA\n",1,240);
    peliculaArray[indice].duracion=auxDuracion;

    printf("\nIngrese descripcion de pelicula: ");
    fflush(stdin);
    gets(auxDescripcion);
    strcpy(peliculaArray[indice].descripcion,auxDescripcion);

    auxPuntaje=getValidInt("\nIngrese puntaje: ","\nEL PUNTAJE DEBE SER NUMERICO\n",1,10);
    peliculaArray[indice].puntaje=auxPuntaje;

    printf("\nIngrese link de la imagen: ");
    fflush(stdin);
    gets(auxlinkImagen);
    strcpy(peliculaArray[indice].linkImagen,auxlinkImagen);

    peliculaArray[indice].estado=1;
    printf("\nPELICULA INGRESADA EXITOSAMENTE\n");
    fflush(stdin);
    getchar();
}

void mostrarPeliculas(eMovie* peliculaArray,int tam)
{
    int i;

    printf("\n\n");
    printf("%3s%20s%25s%21s%21s","ID","TITULO","GENERO","DURACION","PUNTAJE\n\n");
    if(peliculaArray!=NULL && tam>0)
    {
        for(i=0; i<tam; i++)
        {
            if(peliculaArray[i].estado==1)
            {
                printf("%3d%25s%22s%18d%18d\n", peliculaArray[i].id, peliculaArray[i].titulo, peliculaArray[i].genero,peliculaArray[i].duracion,peliculaArray[i].puntaje);
            }
        }
    }
}

void borrarPelicula(eMovie* peliculaArray, int indice)
{
    peliculaArray[indice].estado=0;

    printf("\nLA PELICULA SE ELIMINO EXITOSAMENTE\n");
    fflush(stdin);
    getchar();
}

int menuOpcionesModificacion()
{
    int opcion, aux;

    printf("\n--=--=--=--=--=-- MENU --=--=--=--=--=--\n");
    printf("\n1. MODIFICAR TITULO\n");
    printf("2. MODIFICAR GENERO\n");
    printf("3. MODIFICAR DURACION\n");
    printf("4. MODIFICAR DESCRIPCION\n");
    printf("5. MODIFICAR PUNTAJE\n");
    printf("6. MODIFICAR LINK DE LA IMAGEN\n");
    printf("7. VOLVER\n");
    printf("\nOPCION: ");
    scanf("%d", &aux);

    while(aux<1 || aux>7)
    {
        printf("\nERROR. Opcion no valida. Reingrese: ");
        scanf("%d", &aux);
    }
    opcion=aux;
    return opcion;
}

void modificarPelicula(eMovie* peliculaArray, int indice)
{
    char auxTitulo[20];
    char auxGenero[20];
    int auxDuracion, auxPuntaje, opcion;
    char auxDescripcion[500];
    char auxlinkImagen[100];

    system("cls");
    opcion=menuOpcionesModificacion();
    switch(opcion)
    {
    case 1:
        obtenerTitulo(auxTitulo);
        strcpy(peliculaArray[indice].titulo,auxTitulo);
        printf("\nMODIFICACION REALIZADA EXITOSAMENTE\n");
        getchar();
        break;
    case 2:
        obtenerGenero(auxGenero);
        strcpy(peliculaArray[indice].genero,auxGenero);
        printf("\nMODIFICACION REALIZADA EXITOSAMENTE\n");
        getchar();
        break;
    case 3:
        auxDuracion=getValidInt("\nIngrese duracion: ","\nLA DURACION DEBE SER NUMERICA\n",1,240);
        peliculaArray[indice].duracion=auxDuracion;
        printf("\nMODIFICACION REALIZADA EXITOSAMENTE\n");
        getchar();
        break;
    case 4:
        printf("\nIngrese descripcion de pelicula: ");
        fflush(stdin);
        gets(auxDescripcion);
        strcpy(peliculaArray[indice].descripcion,auxDescripcion);
        printf("\nMODIFICACION REALIZADA EXITOSAMENTE\n");
        getchar();
        break;
    case 5:
        auxPuntaje=getValidInt("\nIngrese puntaje: ","\nEL PUNTAJE DEBE SER NUMERICO\n",1,10);
        peliculaArray[indice].puntaje=auxPuntaje;
        printf("\nMODIFICACION REALIZADA EXITOSAMENTE\n");
        getchar();
        break;
    case 6:
        printf("\nIngrese link de la imagen: ");
        fflush(stdin);
        gets(auxlinkImagen);
        strcpy(peliculaArray[indice].linkImagen,auxlinkImagen);
        printf("\nMODIFICACION REALIZADA EXITOSAMENTE\n");
        getchar();
        break;
    case 7:
        printf("NO SE REALIZO NINGUNA MODIFICACION");
        break;
    default:
        break;
    }
}

void generarPagina(eMovie* peliculaArray, int cantidad)
{
    int i;
    FILE *f;

    f=fopen("pagina.html", "w");

    if(f==NULL)
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO\n");
        exit(1);
    }
    fprintf(f,"<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'><div class='row'>");

    for(i=0; i<cantidad; i++)
    {
        if(peliculaArray[i].estado==1)
        {
            fprintf(f,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''>", peliculaArray[i].linkImagen);
            fprintf(f,"</a><h3><a href='#'>%s</a></h3><ul>",peliculaArray[i].titulo);
            fprintf(f,"<li>Genero:%s</li><li>Puntaje:%d</li><li>Duracion:%d</li></ul>", peliculaArray[i].genero, peliculaArray[i].puntaje, peliculaArray[i].duracion);
            fprintf(f,"<p>%s</p></article>", peliculaArray[i].descripcion);
        }
    }
    fprintf(f,"</div></div><script src='js/jquery-1.11.3.min.js'></script><script src='js/bootstrap.min.js'></script><script src='js/ie10-viewport-bug-workaround.js'></script><script src='js/holder.min.js'></script></body></html>");
    fclose(f);
    printf("\nLA PAGINA WEB SE GENERO EXITOSAMENTE\n");
}

void guardarBinario(eMovie* peliculaArray, int cantidad)
{
    FILE *f;

    f=fopen("bin.dat", "wb");
    if(f==NULL)
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO");
        exit(1);
    }
    fwrite(peliculaArray, sizeof(eMovie), cantidad, f);
    printf("\nARCHIVO GUARDADO EXITOSAMENTE\n");
    fclose(f);
}

void leerBinario(eMovie* peliculaArray, int cantidad)
{
    FILE *f;

    f=fopen("bin.dat", "rb+");
    if(f==NULL)
    {
        f=fopen("bin.dat", "wb");

    }
    if(f == NULL)
    {
        printf("NO SE PUDO ABRIR EL ARCHIVO");
        exit(1);
    }
    fread(peliculaArray, sizeof(eMovie), cantidad, f);
    fclose(f);
}
