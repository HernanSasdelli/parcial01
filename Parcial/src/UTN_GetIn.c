/*
 * UTN_GetIn.c
 *
 *  Created on: 16 oct. 2021
 *      Author: HERNAN
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <conio.h>
#include "UTN_GetIn.h"
#include "Arcades.h"
#include "Salones.h"
#include "Informes.h"


static int esNumerica(char* pArray);
static int esNumericaFloat(char* pArray);
static int myGets(char* pArray, int len);
static int esTexto(char* pArray);
static int esNumerica(char* pArray);
static int esRespuestaSoN(char* pArray);


/** \brief recibe por funciones una cadera o chary lo analiza si es correcto para cargarlo en una variable por puntero
 * \param Lista estructura
 * \param int Largo
 * \param char *mensaje que ve el usuario antes de ingresar el dato solicitado
 * \param char *mensajeErro que ve el usuario despues de ingresar un dato no solicitado o incorrecto
 * \param int reintentos es la cantidad de veces que el usuario puede ingresar el dato solicitado de forma incorrecta antes de dar por cancelado el ingreso
 * \return int(-1) parametro NULL (0) si resolvio
 */
int utn_getTexto(char* pArray,int LARGO,char* mensaje, char* mensajeError,int reintentos)
{
	int retorno=-1;
	char buffer[LARGO];
	if(pArray!=NULL && LARGO>0 && mensaje!=NULL && mensajeError!=NULL && reintentos>=0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);

			if(myGets(buffer,LARGO)==0)
			{
				if(esTexto(buffer)==1)
				{
					strcpy(pArray,buffer);
					retorno=0;
					break;
				}
				else
				{
					printf("%s", mensajeError);
				}
			}
			else
			{
				printf("%s", mensajeError);
			}
			reintentos--;
		}while(reintentos>=0);

	}
	else
	{
		printf("%s", mensajeError);
	}
	return retorno;
}
/** \brief recibe por funciones un numero int lo analiza si es correcto para cargarlo en una variable por puntero
 * \param Lista estructura
 * \param int reintentos es la cantidad de veces que el usuario puede ingresar el dato solicitado de forma incorrecta antes de dar por cancelado el ingreso
 * \param char *mensaje que ve el usuario antes de ingresar el dato solicitado
 * param char *mensajeErro que ve el usuario despues de ingresar un dato no solicitado o incorrecto
 * param int minimo y int maximo limites
 * \return int(-1) campos NUll int (posicion libre) si resuelve
 */
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno=-1;
	int bufferInt;
	char array[50];
	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL )
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			if(myGets(array,sizeof(array))==0)
			{
				if(esNumerica(array)==1)
				{
					bufferInt=atoi(array);

					if (bufferInt>=minimo && bufferInt<=maximo)
					{
						*pResultado=bufferInt;
						retorno=0;
						break;
					}
					else
					{
						printf("%s",mensajeError);
					}
				}
				else
				{
					printf("%s",mensajeError);
				}
			}

			else
			{
				printf("%s",mensajeError);
			}

			reintentos--;

		}while(reintentos>=0);

	}
	return retorno;
}
/** \brief recibe desde el ingreso del usuario un array y lo devuelve por puntero
 * \param Lista Estructura
 * \param Largo
 * \return int(-1) campos NUll int (0) si resuelve
 */
static int myGets(char* pArray, int len)
{
    int retorno=-1;
    int indexFinal;
    fflush(stdin);
    if(fgets(pArray,len,stdin)!=NULL)
    {
    	indexFinal=strlen(pArray)-1;
    	if(pArray[0]=='\n' || pArray[0]=='\t' || pArray[0]==' ')
        {
        	retorno=-1;
        }
    	else
    	{
			if(pArray[indexFinal]=='\n')
			{
				pArray[indexFinal]='\0';
			}
			retorno=0;
    	}
    }
    return retorno;
}
/** \brief recibe array y lo convierte en entero
 * \param puntero a variable int

 * \return int(-1) campos NUll int (0) si resuelve
 */
int getInt(int* pResultado)
{
	int retorno=-1;
	char buffer[50];
	if(pResultado!=NULL)
	{
		if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer)==0)
		{
			retorno=0;
			*pResultado=atoi(buffer);
		}

	}
	return retorno;
}

/** \brief recibe array y verifica que sea un numero entero
 * \array de char
 * \return int(-1) campos NUll int (1) si resuelve
 */
static int esNumerica(char* pArray)
{
	int retorno=1;
	int i=1;

	  while(pArray[i]!='\0')
	  {
		  if(i==0 && (pArray[i]=='+' || pArray[i]=='-'))
		  {
		  	continue;
		  }
		  if(pArray[i]<'0' || pArray[i]>'9')
		  {
			  retorno=-1;
			  break;
		  }
		  i++;
	  }

	  return retorno;
}
/** \brief recibe array y verifica que sea un char
 * \param array de char
 * \return int(-1) campos NUll int (1) si resuelve
 */
static int esTexto(char* pArray)
{
	int retorno=1;
	int i=0;
	while(pArray[i]!='\0')
	{
	  if((pArray[i]!=' ') && (pArray[i]<'a' || pArray[i]>'z') && (pArray[i]<'A' || pArray[i]>'Z'))
	  {
		 retorno=-1;
		 break;
	  }
	  i++;
	}
	return retorno;
}


/** \brief recibe por funciones un numero float lo analiza si es correcto para cargarlo en una variable por puntero
 * \param pResultado array de float
 * \param int reintentos es la cantidad de veces que el usuario puede ingresar el dato solicitado de forma incorrecta antes de dar por cancelado el ingreso
 * \param char *mensaje que ve el usuario antes de ingresar el dato solicitado
 * param char *mensajeErro que ve el usuario despues de ingresar un dato no solicitado o incorrecto
 * param int minimo y int maximo limites
 * \return int(-1) campos NUll int (0) si resuelve
 */
int utn_getNumeroFloat (float* pResultado, char* mensaje, char* mensajeError,float minimo, float maximo, int reintentos)
{
	int retorno=-1;
	char array[51];
	float bufferInt;

	if (pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<maximo && reintentos>0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			if (myGets(array,sizeof(array))==0)
			{
				if(esNumericaFloat(array)==1)
				{

					bufferInt=atof(array);
					if (bufferInt>=minimo && bufferInt<=maximo)
					{
						*pResultado=bufferInt;
						retorno=0;
						break;
					}
					else
					{
						printf("%s",mensajeError);
					}
				}
				else
				{
					printf("%s",mensajeError);
				}
			}

			else
			{
				printf("%s",mensajeError);
			}
			reintentos--;
		}while(reintentos>=0);
	}
	return retorno;
}

/** \brief recibe array y verifica que sea un numero con coma
 * \param array de char
 * \return int(-1) campos NUll int (1) si resuelve
 */
static int esNumericaFloat(char* pArray)
 {
 	 int retorno=1;
	 int i=0;
 	 int contarPunto=0;
 	int banderaError=0;

 	 if(pArray[i]=='+'|| pArray[i]=='-')
	 {
		i=1;
		if(pArray[i]=='.')
		{
			retorno=-1;
			banderaError=1;
		}
	 }
 	 if(banderaError==0)
 	 {
			while(pArray[i]!='\0')
		   {
			   if((pArray[i]<'0' || pArray[i]>'9') && pArray[i]!='.')
			   {
				   retorno=-1;
				   break;
			   }
			   if(pArray[i]=='.')
			   {
				  contarPunto++;
			   }
			   if(pArray[0]=='.')
			   {
				   retorno=-1;
				   break;
			   }
			   i++;
		   }
		 if(contarPunto>1)
		 {
			 retorno=-1;
		 }
 	 }


 	 return retorno;

}
int preguntarSeguir(char* pRespuesta,int reintentos,char* mensaje,char* mensajeError)
{
	int retorno=-1;
	char aux[2];
	if(pRespuesta!=NULL && reintentos>=0 && mensajeError!=NULL)
	{
		do
		{
			if(utn_getTexto(aux,2,mensaje, mensajeError,reintentos)==0)
			{
				if(esRespuestaSoN(aux)==1)
				{
					*pRespuesta=aux[0];
					retorno=0;
					break;
				}
				printf("\t\t%s",mensajeError);
			}
			reintentos--;
		}while(reintentos>=0);
	}
	return retorno;
}

/** \brief recibe array y verifica que sea una s o una n en mayuscula o minuscula
 * \param array de char
 * \return int(-1) campos NUll int (1) si resuelve
 */
static int esRespuestaSoN(char* pArray)
{
	int retorno=-1;
	int i=0;
	if(pArray!=NULL)
	{
		while(pArray[i]!='\0')
		{
		  if(pArray[i]=='s' || pArray[i]=='n' || pArray[i]=='S' || pArray[i]=='N')
		  {
			 retorno=1;
			 break;
		  }
		  i++;
		}
	}
	return retorno;
}

