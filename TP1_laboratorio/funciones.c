#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float sumar(float nro1,float nro2)
{
    float resultado;
    resultado=nro1+nro2;
    printf("\nEl resultado de la suma es %.2f\n",resultado);

    return resultado;
}

float restar(float nro1,float nro2)
{
    float resultado;
    resultado=nro1-nro2;
    printf("\nEl resultado de la resta es %.2f\n",resultado);

    return resultado;
}

float dividir(float nro1,float nro2)
{
    float resultado;

    while(nro2==0)
    {
        printf("\n\nDATO INVALIDO. Reingrese el segundo operando para realizar la division: ");
        scanf("%f",&nro2);

        resultado=nro1/nro2;

    }

     resultado=nro1/nro2;
     printf("\nEl resultado de la division es %.2f\n",resultado);

    return resultado;
}

float multiplicar(float nro1,float nro2)
{
    float resultado;

    resultado=nro1*nro2;
    printf("\nEl resultado de la multiplicacion es %.2f\n",resultado);

    return resultado;
}

 float calcularfactorial(float num)
{

    int cont=1;
    double resultado=1;

    while(cont<=num)
    {
        resultado=resultado*cont;
        cont++;
    }

    printf("\nEl factorial de %.2f es %.2f\n",num,resultado);

    return resultado;

}


float hacerTodas(float nr1, float nr2)
{
    sumar(nr1,nr2);
    restar(nr1,nr2);
    dividir(nr1,nr2);
    multiplicar(nr1,nr2);

    if(nr1>=0)
    {
      calcularfactorial(nr1);

    }

    else
    {
      printf("\nError, para calcular el factorial debe ingresar un numero positivo. Reingrese el primer operando.\n");

    }

    return 1;

}
