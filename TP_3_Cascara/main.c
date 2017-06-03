#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<ctype.h>
#include "funciones.h"
#include<string.h>
#define TAM 3


int main()
{
    EMovie movie[TAM];
    int confirm;
    char seguir='s';


    inicializarPeliculas(movie,TAM);

    do{
        switch(menu())
        {
            case 1:
                agregarPelicula(movie,TAM);
                system("cls");
                break;

            case 2:
                borrarPelicula(movie,TAM);
                system("cls");
                break;

            case 3:
                modificarPelicula(movie,TAM);
                system("cls");

               break;

            case 4:
                generarPagina(movie,1);
                printf("\nLa pagina HTML y el archivo binario han sido creados.\n\n");
                system("pause");
                system("cls");
                break;

            case 5:

               printf("\nConfirma el cierre del programa s/n ?\n");
               confirm=tolower(getch());

                if(confirm=='s')
                {
                    seguir = 'n';
                }
                system("cls");
                break;

        }

    }while(seguir=='s');

    return 0;
}



