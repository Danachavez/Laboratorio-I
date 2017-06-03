#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<ctype.h>
#include "funciones.h"
#include<string.h>
#define TAM 3

int menu()
{
    int opcion;

    printf("\tMenu de opciones:\n\n");
    printf("1. Agregar pelicula\n");
    printf("2. Borrar pelicula\n");
    printf("3. Modificar pelicula\n");
    printf("4. Generar pagina web\n");
    printf("5. Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    while(opcion<1||opcion>5)
    {
      printf("\n\nError!! Reingrese opcion entre 1 y 5: ");
      scanf("%d",&opcion);

    }

    return opcion;

}

void inicializarPeliculas(EMovie peliculas[], int tam)
 {
      int i;

     for(i=0;i<tam; i++)
    {
       peliculas[i].estado = 0;
    }
 }

 int buscarEspacioLibre(EMovie peliculas[], int tam)
{
    int indice = -1;
    int i;

    for(i=0;i<tam;i++)
    {
        if(peliculas[i].estado==0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}



int agregarPelicula(EMovie movie[], int tam)
{
   char auxCad[200];
   char auxGenero[30];
   char auxTitulo[50];
   int flag = 0;
   int indice;
   int puntaje;
   int duracion;
   char linkImagen[50];


   indice = buscarEspacioLibre(movie, tam);

    if(indice == -1)
    {
        printf("\nNo hay lugar disponible!\n\n");
        system("pause");
    }
    else
    {
            movie[indice].estado = 1;

            printf("\n\n");
            printf("Ingrese los datos de la pelicula:\n\n ");

            printf("- Titulo: ");
            fflush(stdin);
            gets(auxTitulo);

            while(strlen(auxTitulo)>30)
            {
               printf("\nError!! El titulo puede contener hasta 30 caracteres. Reingrese: ");
               fflush(stdin);
               gets(auxTitulo);
            }
             strcpy(movie[indice].titulo,auxTitulo);


            printf("- Genero: ");
            fflush(stdin);
            gets(auxGenero);

            while(strlen(auxGenero)>20)
            {
               printf("\nError!! El genero puede contener hasta 20 caracteres. Reingrese: ");
               fflush(stdin);
               gets(auxGenero);
            }
             strcpy(movie[indice].genero,auxGenero);


            printf("- Duracion de la pelicula: ");
            fflush(stdin);
            scanf("%d",&duracion);

             while(duracion<30 || duracion>500)
            {
              printf("\nError!! Ingrese un valor entre 30 y 500: ");
              scanf("%d", &duracion);
            }
            movie[indice].duracion=duracion;


            printf("- Descripcion: ");
            fflush(stdin);
            gets(auxCad);

            while(strlen(auxCad)>120)
            {
               printf("\nError!! La descripcion puede contener hasta 120 caracteres. Reingrese: ");
               fflush(stdin);
               gets(auxCad);
            }

            strcpy(movie[indice].descripcion,auxCad);

            printf("- Puntaje: ");
            fflush(stdin);
            scanf("%d",&puntaje);

            while(puntaje<0 || puntaje>10)
            {
              printf("\nError!! Ingrese un valor entre 0 y 10: ");
              scanf("%d", &puntaje);
            }
            movie[indice].puntaje=puntaje;


            printf("- Link de imagen: ");
            fflush(stdin);
            gets(linkImagen);

           while(strlen(linkImagen)>50)
           {
            printf("\nError. El link puede contener hasta 50 caracteres. Reingrese: ");
            fflush(stdin);
            gets(linkImagen);
           }
           strcpy(movie[indice].linkImagen,linkImagen);


           printf("\n\nPelicula agregada exitosamente!!\n\n");
           system("pause");

            flag = 1;

    }

       return flag;

}

void mostrarPelicula(EMovie* unaPelicula)
{
    printf("\n\nTitulo        Genero     Puntaje     Duracion ");
    printf("\n%s      %10s    %5d   %5d ", unaPelicula->titulo, unaPelicula->genero, unaPelicula->puntaje, unaPelicula->duracion);

}

void mostrarPeliculas(EMovie peliculas[], int tam)
{
    int i;
    for(i=0;i<tam; i++)
    {
        if(peliculas[i].estado == 1)
        {
            mostrarPelicula(peliculas + i);
        }
    }

    printf("\n\n");
}

int buscarPelicula(EMovie peliculas[], int tam, char titulo[])
{
    int indice = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(strcmp(peliculas[i].titulo,titulo)==0)
        {
            indice = i;
            break;
        }
    }
    return indice;

}


void borrarPelicula(EMovie* peliculas, int tam)
{
    int indice;
    char titulo[20];
    char baja;

    printf("\nIngrese el titulo de la pelicula: ");
    fflush(stdin);
    gets(titulo);

    indice = buscarPelicula(peliculas, tam, titulo);

    if(indice == -1)
    {
        printf("\nLa pelicula no se encuentra en el sistema\n\n");
    }
    else
    {
        printf("\nDatos de la pelicula:\n\n");
        mostrarPelicula(peliculas + indice);

        printf("\n\n\nConfirma que quiere eliminar la pelicula? s/n: ");
        fflush(stdin);
        scanf("%c", &baja);

        if(baja == 's')
        {
            peliculas[indice].estado = 2;
            printf("\nLa baja ha sido realizada con exito!!\n\n");
        }
        else
        {
            printf("\n\nLa baja ha sido cancelada!!\n\n");
        }

    }

      system("pause");
}


void modificarPelicula(EMovie* peliculas, int tam)
  {
    char auxCad[200];
    char auxLink[60];
    char titulo[20];
    char auxGenero[30];
    char auxTitulo[30];
    int duracion;
    int puntaje;
    int indice;
    int opcion;

    printf("\nIngrese el titulo de la pelicula: ");
    fflush(stdin);
    gets(titulo);

    indice = buscarPelicula(peliculas, tam, titulo);


    if(indice == -1)
    {
        printf("\nLa pelicula no se encuentra en el sistema\n\n");
    }
    else
    {
        fflush(stdin);
        printf("\nDatos de la pelicula:\n");
        mostrarPelicula(peliculas + indice);

        printf("\n\nSeleccione el dato a modificar: \n\n");
        printf("1. Titulo\n");fflush(stdin);
        printf("2. Genero\n");
        printf("3. Duracion\n");
        printf("4. Descripcion\n");
        printf("5. Puntaje\n");
        printf("6. Link de imagen\n\n");
        printf("Ingrese opcion: ");
        scanf("%d",&opcion);

        while(opcion<1 || opcion>6)
        {
          printf("\n\nError!! Reingrese opcion entre 1 y 6: ");
          scanf("%d",&opcion);
        }

        switch(opcion)
        {
            case 1:

            fflush(stdin);
            printf("\nIngrese el nuevo titulo de la pelicula: ");
            fflush(stdin);
            gets(auxTitulo);

            while(strlen(auxTitulo)>20)
            {
                printf("Error!! El titulo puede contener hasta 20 caracteres. Reingrese: ");
                fflush(stdin);
                gets(auxTitulo);
            }

            strcpy(peliculas[indice].titulo,auxTitulo);
            printf("\n\nLa modificacion ha sido realizada exitosamente!!");
            break;

            case 2:

            fflush(stdin);
            printf("Ingrese el nuevo genero de la pelicula: ");
            fflush(stdin);
            gets(auxGenero);

            while(strlen(auxGenero)>20)
            {
               printf("\nError!! El genero puede contener hasta 20 caracteres. Reingrese: ");
               fflush(stdin);
               gets(auxGenero);
            }

            strcpy(peliculas[indice].genero,auxGenero);
            printf("\n\nLa modificacion ha sido realizada exitosamente!!");
            break;

            case 3:

            fflush(stdin);
            printf("\nIngrese la duracion de la pelicula: ");
            scanf("%d",&duracion);

             while(duracion<30 || duracion>500)
            {
              printf("\nError!! Ingrese un valor entre 30 y 500: ");
              scanf("%d", &duracion);
            }

            peliculas[indice].duracion=duracion;
            printf("\n\nLa modificacion ha sido realizada exitosamente!!");
            break;

            case 4:

            fflush(stdin);
            printf("\nIngrese la descripcion de la pelicula:");
            gets(auxCad);

            while(strlen(auxCad)>120)
            {
               printf("\nError!! La descripcion puede contener hasta 120 caracteres. Reingrese: ");
               fflush(stdin);
               gets(auxCad);
            }

            strcpy(peliculas[indice].descripcion,auxCad);
            printf("\n\nLa modificacion ha sido realizada exitosamente!!");
            break;

            case 5:

            fflush(stdin);
            printf("\nIngrese el puntaje de la pelicula:");
            fflush(stdin);
            scanf("%d",&puntaje);

            while(puntaje<0 || puntaje>10)
            {
              printf("\nError!! Ingrese un valor entre 0 y 10: ");
              scanf("%d", &puntaje);
            }

            peliculas[indice].puntaje=puntaje;
            printf("\n\nLa modificacion ha sido realizada exitosamente!!");
            break;

            case 6:

            fflush(stdin);
            printf("\nIngrese el link de imagen de la pelicula:");
            fflush(stdin);
            gets(auxLink);

           while(strlen(auxLink)>50)
           {
            printf("\nError. El link puede contener hasta 50 caracteres. Reingrese: ");
            fflush(stdin);
            gets(auxLink);
           }

            strcpy(peliculas[indice].linkImagen,auxLink);
            printf("\n\nLa modificacion ha sido realizada exitosamente!!");
            break;

        }


    }

    system("pause");

  }

  void generarPagina(EMovie lista[], int tam)
  {
    FILE* bin;
    FILE* f;
    int i;

    f=fopen("index.html", "w");

    if(f==NULL)
    {
        printf("Error!! No se pudo abrir el archivo.");
        exit(1);
    }



    for(i=0;i<tam;i++)
    {
       if(lista[i].estado == 1)
       {

        fprintf(f, "<html>");
        fprintf(f, "<article class='col-md-4 article-intro'>");
        fprintf(f, "<a href='#'>");
        fprintf(f, "<img class='img-responsive img-rounded' src=");
        fprintf(f, lista[i].linkImagen);
        fprintf(f, "'alt=''>");
        fprintf(f, "</a>");
        fprintf(f, "<h3>");
        fprintf(f, "<a href='#'>");
        fprintf(f, lista[i].titulo);
        fprintf(f, "</a>");
        fprintf(f, "</h3>");
        fprintf(f, "<ul>");
        fprintf(f, "<li>Género: ");
        fprintf(f, lista[i].genero);
        fprintf(f, "</li>");
        fprintf(f, "<li>Puntaje: ");
        fprintf(f, "%d", lista[i].puntaje);
        fprintf(f, "</li>");
        fprintf(f, "<li>Duracion: ");
        fprintf(f, "%d", lista[i].duracion);
        fprintf(f, "</li>");
        fprintf(f, "<p>");
        fprintf(f, lista[i].descripcion);
        fprintf(f, "</p>");
        fprintf(f, "</article>");
        fprintf(f, "</html>");

       }
    }

    fclose(f);

    bin=fopen("bin.dat", "wb");

    if (bin==NULL)
    {
        printf("Error!! No se pudo abrir el archivo.");
        exit(1);
    }

    fwrite(&lista, sizeof(EMovie), 50, bin);

    fclose(bin);


  }

