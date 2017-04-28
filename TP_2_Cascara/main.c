#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include<ctype.h>
#include "funciones.h"



int main()
{
    EPersona personas[20];

    char seguir='s';
    int confirm;

    inicializarPersonas(personas);

    do
    {
        switch(menu())
        {
            case 1:

                agregarPersona(personas);
                system("pause");

                break;

            case 2:

                BajaPersona(personas);

                break;

            case 3:

                system("cls");
                printf("\n          *** Listado de personas ordenado alfabeticamente ***  \n");
                ordenarPersonas(personas);
                system("pause");

                break;

            case 4:

                imprimirGrafico(personas);
                system("pause");

                break;
            case 5:
                printf("\nConfirma el cierre del programa s/n ?\n\n");
                confirm=tolower(getch());

                if(confirm=='s')
                {
                    seguir = 'n';
                }

                break;
        }

    }while(seguir=='s');

    return 0;
}











