/*
 * Salones.c
 *
 *  Created on: 17 oct. 2021
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
#include "Juegos.h"

#define OCUPADO 1
#define LIBRE 0

static int sal_generadorId(void);


//Funciones

/** \brief funcion estatica para generar id sin que se repita dentro del programa
 * \return retorna la proxima ID generada
 */
static int sal_generadorId(void)
{
	static int c=100;
	c++;
	return c;
}
void altaForzadaSalon(Salon* struc, int LEN, int i,char* name, char* direc, int tipo)
{
	if(i>=0 && i<=LEN)
	{
		struc[i].isEmpty=OCUPADO;
		struc[i].idSalon=sal_generadorId();
		strcpy(struc[i].name,name);
		strcpy(struc[i].direc,direc);
		struc[i].tipo=tipo;
	}
}

/** \brief Busca en un estructura la posicion libre con la variable bandera isEmpty como parametro
 * \param Lista estructura
 * \param int Largo
 * \return int(-1) campos NUll int (posicion libre) si resuelve
 */
int sal_buscarLibre(Salon* estructura,int LARGO)
{
	int retorno=-1;
	//int buffer;
	int i;
	if(estructura!=NULL && LARGO>0)
	{
		for(i=0;i<LARGO;i++)
		{
			if(estructura[i].isEmpty==LIBRE)
			{
				//buffer=i;
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

/** \brief busca posiciones ocupadas para chequear que la lista este cargada
 * \param Lista Estructura
 * \param int Largo
 * \return int(-1) si falla int (0) si resuelve
 */
int sal_buscarOcupado(Salon* estructura,int LARGO)
{
	int retorno=-1;
	int i;
	if(estructura!=NULL && LARGO>0)
	{
		for(i=0;i<LARGO;i++)
		{
			if(estructura[i].isEmpty==OCUPADO)
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
/** \brief Busca una plantilla de empleado a traves del campo de ID
 * \param Lista estructura
 * \param int largo
 * \param int ID
 * \return int(-1) falla, int (ID) si resuelve
 */
int sal_buscarPorId(Salon* list,int len,int id)
{
	int retorno=-1;
	int i;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].idSalon==id && list[i].isEmpty==OCUPADO)
			{
				retorno=i;
				break;
			}
		}
	}

	return retorno;
}

/** \brief Inicializa en 0, o LIBRE, toda las variables isEmpty de la estructura
 * \param Lista estructura
 * \param int largo
 * \return int(-1) si fallo (0)si resolvio
*/
int sal_init(Salon* list, int len)
{
	int i;
	int retorno=-1;
	if (list!=NULL && len>0)
	{
		retorno=0;
		for (i=0;i<len; i++)
		{
			list[i].isEmpty=LIBRE;
		}
	}
	return retorno;
}

/** \brief Carga todas las variables de una estructura
 * \param Lista estructura
 * \param  int largo
 * \return int(-1) si falla (-2) si la estructura esta llena (0) si se pudieron cargar los datos corectamente
 */
int sal_Alta(Salon* estructura, int LARGO)
{
	int retorno=-1;
	int disponible=sal_buscarLibre(estructura, LARGO);
	int id=0;
	char name[63];
	char direc[63];//lastName
	int tipo;

	if(estructura!=NULL && LARGO>0)
	{
		if(disponible>=0)
		{
			if(utn_getTexto(name,sizeof(name),"Ingrese el Nombre del Salon\n","\nError! Ingreso invalido\n",2)==0)
			{
				if(utn_getAlfanumerica(direc,sizeof(direc),"Ingrese la direccion del salon\n","\nError! Ingreso invalido\n",2)==0)
				{
						if(utn_getNumero(&tipo,"Sector\n1. SHOPPING\n2. LOCAL\nIngrese: ","\nError! Opcion Invalida\n",1,2,2)==0)
					{
						id=sal_generadorId();
						if(sal_Add(estructura, disponible, id, name, direc, tipo)==0)
						{
							printf("\nAlta salon exitosa\n");
							sal_mostrarUnaPosicion(estructura, disponible);
							retorno=0;
						}
					}

				}
			}
		}
		else
		{
			//no hay mas espacio
			retorno=-2;
		}
	}
	return retorno;
}

/** \brief agrega las variables recolectadas por otra funcion a una estructura
 * \param Lista estructura
 * \param int Posicion de la estructura donde cargar los datos
 *  \param int id nuevo id generado por otra funcion
 *  \param char name[] y char Last Name [] cargan los nombre y apellido que recibieron por parametros las variables de una estructura
 * \return int(-1) si algun parametro es NULL (0) si logro copiar
 */
int sal_Add(Salon* list, int len, int id, char name[],char
		direc[],int tipo)
{
	int retorno=-1;
	if(list!=NULL && len>=0 && id>=0 && name!=NULL && direc!=NULL && tipo>0)
	{
		retorno=0;
		list[len].idSalon=id;
		strcpy(list[len].name,name);
		strcpy(list[len].direc,direc);
		list[len].tipo=tipo;
		list[len].isEmpty=OCUPADO;
	}
	return retorno;
}

/** \brief Imprime por pantalla los campos de una sola plantila en una posicion especifica sin verificar si hay datos cargados
 * \param LIsta estructura
 * \param int posicion donde se encuentra la plantilla
 * \return no retorna, solo imprime
 */
void sal_mostrarUnaPosicion(Salon* list, int posicion)
{
	//printf("_______________________________\n| S | Apellido - Nombre | Salario\n_______________________________\n");
	if(list!=NULL && posicion>-1)
	{
		//printf("%d\t",list[control].idSalon);
		printf("| %s |",list[posicion].name);
		printf("| %s |",list[posicion].direc);
		printf("| %d |\n",list[posicion].tipo);
	}
	else
	{
		printf("No se encontro ID");
	}
}
/** \brief Imprime una estructura completa y las variables de cada plantilla siempre que esten en uso
 * \param Lista estructura
 * \param int largo
 * \return int(-1) si los parametros son NULL (0) su resolvio
 */
int sal_ImprimirTodos(Salon* list, int LARGO)
{
	int retorno=-1;
	int i;
	if(list!=NULL && LARGO>0)
	{
		//printf("ID   Sector  Apellido y Nombre   Salario\n___________________________________________\n");
		for(i=0;i<LARGO;i++)
		{
			if(list[i].isEmpty==OCUPADO)
			{
				printf("| %d |",list[i].idSalon);
				printf("| %s |",list[i].name);
				printf("| %s |",list[i].direc);
				printf("| %d |\n",list[i].tipo);
				//printf("%d\t\n",list[i].isEmpty);
				retorno=0;
			}
		}
	}
	return retorno;
}
