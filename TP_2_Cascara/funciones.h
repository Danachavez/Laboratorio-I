#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Despliega el menu de opciones.
 * @param no recibe ningun valor.
 * @return el valor de la opcion ingresada por el usuario.
 */
int menu();

/**
 * Se inicializa el estado de las personas en 0 para decir que todavia no se cargó ningun valor en el y que esta disponible.
 * @param personas el array se pasa como parametro.
 * @return no devuelve ningun valor.
 */

void inicializarPersonas(EPersona[]);

 /**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni.
 */
int buscarPorDni(EPersona lista[], int dni);

/**
 * Muestra los datos de una persona.
 * @param persona obtiene los datos de la persona.
 * @return no devuelve ningun valor.
 */

void mostrarPersona(EPersona);
/**
 * Muestra los datos de las personas cargados en el array.
 * @param personas el array se pasa como parametro.
 * @return no devuelve ningun valor.
 */

void mostrarPersonas(EPersona[]);
/**
 * Ordena las personas ingresadas al sistema por orden alfabetico.
 * @param x el array se pasa como parametro.
 * @return no devuelve ningun valor.
 */
void ordenarPersonas(EPersona x[]);

/**
 * Carga los datos de las personas al sistema.
 * @param personas el array se pasa como parametro.
 * @return no devuelve ningun valor.
 */
void agregarPersona(EPersona[]);

/**
 * Da de baja a la persona con el dni que coincida con el anteriormente guardado en el sistema.
 * @param personas el array se pasa como parametro.
 * @return no devuelve ningun valor.
 */

void BajaPersona(EPersona[]);

/**
 * imprime un grafico de barras indicando la cantidad de personas por rango de edad.
 * @param personas el array se pasa como parametro.
 * @return no devuelve ningun valor.
 */
void imprimirGrafico(EPersona personas[]);



#endif // FUNCIONES_H_INCLUDED
