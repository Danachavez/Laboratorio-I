#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int estado;

}EMovie;

/**
 *  Despliega un menu de opciones
 *  @param No recibe ningun parametro
 *  @return retorna la opcion selecionada
 */
int menu();

/**
 *  Inicializa el estado de las peliculas en 0 para indicar que todavia no se cargo la pelicula.
 *  @param peliculas el array como parametro
 *  @param tam el tamaño del array.
 *  @return no retorna ningun valor
 */

void inicializarPeliculas(EMovie peliculas[], int tam);

/**
 *  Busca que haya espacio dsiponible para una nueva pelicula.
 *  @param peliculas el array como parametro.
 *  @param tam el tamaño del array.
 *  @return retorna el indice para saber si hay espacio o no disponible.
 */
int buscarEspacioLibre(EMovie peliculas[], int tam);

/**
 *  Muestra los datos de una pelicula.
 *  @param unaPelicula la pelicula a mostrar
 *  @return  no retorna ningun valor.
 */
void mostrarPelicula(EMovie* unaPelicula);
/**
 *  Muestra los datos de todas las peliculas cargadas.
 *  @param peliculas el array como parametro
 *  @param tam el tamaño del array.
 *  @return  no retorna ningun valor.
 */
void mostrarPeliculas(EMovie peliculas[], int tam);

/**
 *  Modifica los datos de las peliculas cargadas.
 *  @param peliculas el array como parametro.
 *  @param tam el tamaño del array.
 *  @return no retorna ningun valor.
 */

void modificarPelicula(EMovie* peliculas, int tam);
/**
 *  Agrega una nueva pelicula al archivo binario.
 *  @param movie el array como parametro.
 *  @param tam el tamaño de array.
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no.
 */
int agregarPelicula(EMovie* movie, int);

/**
 *  Borra una pelicula del archivo binario.
 *  @param peliculas la estructura a ser eliminada al archivo.
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no.
 */
 void borrarPelicula(EMovie* peliculas, int tam);

/**
 *  Genera un archivo html a partir de las peliculas y un archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param tam el tamaño del array.
 */
void generarPagina(EMovie lista[] ,int);

#endif // FUNCIONES_H_INCLUDED
