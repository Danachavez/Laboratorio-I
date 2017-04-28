#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include<ctype.h>
#include "funciones.h"

int menu()
 {
    int opcion;
    system("cls");

        printf("\nMenu de opciones\n\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        printf("\n\nIngrese opcion: ");
        scanf("%d",&opcion);

        while(opcion<1||opcion>5)
        {
            printf("\n\nError!! reingrese opcion entre 1 y 5: ");
            scanf("%d",&opcion);

        }

        return opcion;

 }


 void inicializarPersonas(EPersona personas[])
 {
     int i;
     for(i=0;i<20;i++)
     {
         personas[i].estado=0;
     }
 }

 int obtenerEspacioLibre(EPersona lista[])
 {
    int indice= -1;
    int i;

    for(i=0;i<20;i++)
    {
       if(lista[i].estado==0)
       {
           indice=i;
           break;
       }

    }

    return indice;
 }

int buscarPorDni(EPersona lista[], int dni)
 {
     int indice= -1;
     int i;


    for(i=0;i<20;i++)
    {
       if(lista[i].dni==dni)
       {
           indice=i;
           break;
       }
    }

    return indice;
 }

  void mostrarPersona(EPersona persona)
 {

     printf("\n%10s %5d %3d", persona.nombre, persona.edad, persona.dni);
 }


 void mostrarPersonas(EPersona personas[])
 {
     int i;

     printf("\n   Nombre   Edad    DNI \n");

     for(i=0;i<20;i++)
    {
        if(personas[i].estado==1)

         {
             mostrarPersona(personas[i]);
         }
    }

    printf("\n\n");
 }


 void ordenarPersonas(EPersona x[])
 {
     int i;
     int j;
     EPersona auxPersona;

     for(i=0;i<19;i++)
     {
         for(j=i+1;j<20;j++)
         {
             if(strcmp(x[i].nombre, x[j].nombre)>0)
              {
                auxPersona = x[i];
                x[i] = x[j];
                x[j] = auxPersona;

              }
         }
     }

     mostrarPersonas(x);

 }


 void agregarPersona(EPersona personas[])
 {
     int indice;
     int dni;
     int esta;

     indice=obtenerEspacioLibre(personas);

     if(indice== -1)
     {
         printf("\nNo hay espacio disponible\n");
     }

     else
     {
        printf("\nIngrese DNI: ");
        scanf("%d",&dni);

        esta=buscarPorDni(personas,dni);

         if(esta!= -1)
         {
             printf("\nLa persona ya esta dada de alta en el sistema\n");
         }

         else
         {
             personas[indice].dni=dni;

             printf("\nIngrese el nombre: ");
             fflush(stdin);
             gets(personas[indice].nombre);

             printf("\nIngrese la edad: ");
             scanf("%d",&personas[indice].edad);

             while(personas[indice].edad<=0||personas[indice].edad>120)
             {
                 printf("\n\nError!! Edad invalida. Reingrese la edad: ");
                 scanf("%d",&personas[indice].edad);
             }

             personas[indice].estado = 1;


             printf("\n\nLa persona fue agregada con exito!!!\n\n");
         }

     }
 }


 void BajaPersona(EPersona personas[])
 {
    int indice;
    int dni;
    char baja;

    printf("\nIngrese el DNI: ");
    scanf("%d", &dni);

    indice = buscarPorDni(personas,dni);

    if(indice == -1)
    {
        printf("\nLa persona con DNI %d no se encuentra en el sistema\n\n", dni);
    }
    else
    {

        system("cls");
        printf("\n\n*** Datos de la persona ***\n\n");
        printf("\n\nNombre  edad  DNI \n\n");
        mostrarPersona(personas[indice]);

        printf("\n\nConfirma la baja de la persona? s/n? \n\n");
        fflush(stdin);
        baja=tolower(getch());


        if(baja == 's')
        {
            personas[indice].estado = 2;
            printf("\nLa baja se ha realizado exitosamente!!!\n\n");
        }
        else
        {
            printf("\n\nLa baja ha sido cancelada\n\n");
        }

    }

      system("pause");
}



void imprimirGrafico(EPersona personas[])
 {

    int i;
    int personasMenor18 = 0;
    int personas19a35 = 0;
    int personasMayor35 = 0;
    int maxCant = 0;
    int flag= 0;

    // Obtengo las cantidades de cada rango
    for(i = 0; i < 20; i++)
    {
       if(personas[i].estado == 1 && personas[i].edad > 35)
       {
           personasMayor35++;
       }
       if(personas[i].estado == 1 && personas[i].edad > 18 && personas[i].edad <= 35)
       {
           personas19a35++;
       }
       if(personas[i].estado == 1 && personas[i].edad <= 18)
       {
           personasMenor18++;
       }
    }

    // Obtengo el rango con mayor cantidad de personas
    if (personasMenor18 >= personas19a35)
    {
        maxCant = personasMenor18;
    }
    else
    {
        maxCant = personas19a35;
    }

    if (maxCant <  personasMayor35)
    {
        maxCant = personasMayor35;
    }

    // Muestro los asteriscos y los rangos

    for(i=maxCant; i>0; i--)
        {
            if(i<10)
            {
                printf("%02d|",i);
            }
            else
            {
                printf("%02d|",i);
            }

            if(i<= personasMenor18)
            {
                printf("*");
            }

            if(i<= personas19a35)
            {
                flag=1;
                printf("\t*");
            }

            if(i<= personasMayor35)
            {
                if(flag==0)
                printf("\t\t*");
                if(flag==1)
                printf("\t*");
            }

        //Bajo una linea luego de cada iteracion

        printf("\n");
    }

    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d\n\n", personasMenor18, personas19a35, personasMayor35);

}







