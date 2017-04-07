#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    char confirm;
    float oper1=0;
    float oper2=0;
    int opcion;


     do
      {
        printf("\n------CALCULADORA------\n");
        printf("\n\nMenu de opciones\n");
        printf("\n1- Ingresar 1er operando (A = %.2f)\n",oper1);
        printf("2- Ingresar 2do operando (B = %.2f)\n",oper2);
        printf("3- Calcular la suma (%.2f + %.2f)\n",oper1,oper2);
        printf("4- Calcular la resta (%.2f - %.2f)\n",oper1,oper2);
        printf("5- Calcular la division (%.2f / %.2f)\n",oper1,oper2);
        printf("6- Calcular la multiplicacion (%.2f * %.2f)\n",oper1,oper2);
        printf("7- Calcular el factorial (%.2f!)\n",oper1);
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        printf("\nIngrese opcion: ");
        scanf("%d",&opcion);


        while(opcion<1||opcion>9)
        {
            printf("\n\nError!! Reingrese opcion entre 1 y 9: ");
            scanf("%d",&opcion);
        }


        switch(opcion)
        {
            case 1:
                system("cls");
                printf("\nIngrese el primer operando: ");
                scanf("%f",&oper1);
                break;

            case 2:
                system("cls");
                printf("\nIngrese el segundo operando: ");
                scanf("%f",&oper2);
                break;

            case 3:
                system("cls");
                sumar(oper1,oper2);

                break;

            case 4:
                system("cls");
                restar(oper1,oper2);

                break;

            case 5:
                system("cls");
                dividir(oper1,oper2);

                break;

            case 6:
                system("cls");
                multiplicar(oper1,oper2);

                break;

            case 7:
                system("cls");

                if(oper1>=0)
                {
                  calcularfactorial(oper1);
                }

                else
                {
                    printf("\nError, el numero debe ser positivo.Reingrese el primer operando.\n");
                }


                break;

            case 8:
                system("cls");
                hacerTodas(oper1,oper2);
               break;

            case 9:
                system("cls");
                printf("\nConfirma el cierre del programa s/n?: ");
                fflush(stdin);
                confirm=tolower(getchar());

                if(confirm == 's')
                {
                    seguir = 'n';
                }

                break;

        }

   }while(seguir == 's');

   return 0;

}










