#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char titulo[30];
    char genero[30];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[100];
    int estado;
    int id;
}eMovie;

/**
 * \brief Inicializa el campo estado en un array de peliculas
 * \param peliculaArray Es el array pasado por parametro
 * \param tam Es leltamaño del array
 * \param valor Es el valor que se le asigna al estado
 * \return void
 */
void estadoPelicula(eMovie* peliculaArray,int tam,int valor);
/**
 * \brief Busca el primer lugar no libre en el array
 * \param abonadoArray Es el array pasado por parametro
 * \param tam Es el tamaño del array
 * \return Retorna -1 si no hay lugares libres o el indice de la posicion libre
 */
int buscarLugarLibre(eMovie* peliculaArray,int tam);
/**
 * \brief Obtiene el indice que coincide con el ID pasado por parametro.
 * \param abonadoArray Es el array pasado por parametro
 * \param tam Es el tamaño del array
 * \param auxID Es el id pasado por parametro
 * \return Retorna -1 si no hay coincidencia o el indice de la posicion donde se encuentra el ID
 */
int buscarID(eMovie* peliculaArray,int tam,char auxID);
/** \brief Despliega un menu de opciones por pantalla
 * \return la opcion elegida del menu
 */
int menuOpciones();
/**
 * \brief Generar el ID automaticamente
 * \param abonadoArray Es el array pasado por parametro
 * \param tam Es el tamaño del array
 * \return void
 */
void generarID(eMovie* peliculaArray,int tam);
/**\brief Verifica si el valor recibido contiene solo letras y números
 * \param nombre Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 */
int esAlfaNumerico(char nombre[]);
/**\brief Pide por pantalla el titulo
 * \param aux es el array donde se guarda el nombre
 */
void obtenerTitulo(char aux[]);
/**\brief Pide por pantalla el genero
 * \param aux es el array donde se guarda el nombre
 */
void obtenerGenero(char aux[]);
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]);
/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 */
int esNumerico(char str[]);
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[]);
/**
 * \brief Solicita un numero entero al usuario y lo valida
 * \param requestMessage Es el mensaje a ser mostrado para solicitar el dato
 * \param requestMessage Es el mensaje a ser mostrado en caso de error
 * \return El número ingresado por el usuario
 */
int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
/**
 *  \brief Agrega una pelicula
 * \param peliculaArray Es el array pasado por parametro
 * \param indice Es el indice pasado por parametro
 * \return void
 */
void agregarPelicula(eMovie* peliculaArray,int indice);
/**
 * \brief Muestra por pantalla el contenido del array pasado por parametro
 * \param peliculaArray Es el array pasado por parametro
 * \param tam Es el tamaño del array
 * \return void
 */

void mostrarPeliculas(eMovie* peliculaArray,int tam);
/**
 * \brief Borra una pelicula
 * \param peliculaArray Es el array pasado por parametro
 * \param indice Es el indice pasado por parametro
 * \return void
 */
void borrarPelicula(eMovie* peliculaArray, int indice);
/** \brief Despliega un menu de opciones por pantalla
 * \return la opcion elegida del menu
 */
int menuOpcionesModificacion();
/**
 * \brief Modifica una pelicula
 * \param peliculaArray Es el array pasado por parametro
 * \param indice Es el indice pasado por parametro
 * \return void
 */
void modificarPelicula(eMovie* peliculaArray, int indice);
/** \brief genera un html con las peliculas cargadas
 * \param peliculaArray Es el array pasado por parametro
 * \param cantidad Es la cantidad de iteraciones
 * \return void
 */
void generarPagina(eMovie* peliculaArray, int cantidad);
/** \brief Guarda los datos del archivo binario
 * \param peliculaArray Es el array pasado por parametro
 * \param cantidad Es la cantidad de iteraciones
 * \return void
 */
void guardarBinario(eMovie* peliculaArray, int cantidad);
/** \brief Lee los datos del archivo binario
 * \param peliculaArray Es el array pasado por parametro
 * \param cantidad Es la cantidad de iteraciones
 * \return void
 */
void leerBinario(eMovie* peliculaArray, int cantidad);

#endif // FUNCIONES_H_INCLUDED
