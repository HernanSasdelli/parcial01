/*
 * Arcades.c
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

#define OCUPADO 1
#define LIBRE 0

static int arc_generadorId(void);
/** \brief funcion estatica para generar id sin que se repita dentro del programa
 * \return retorna la proxima ID generada
 */
static int arc_generadorId(void)
{
	static int c=1000;
	c++;
	return c;
}

/** \brief recibe una estructura, y el dato en comun con una segunda estructura, para dar de baja posisciones
 * \de la primera
 * \param recibe la estructura con el dato en comun con otra estructura exterior
 * \recibe int id, recibe el dato en comun entre las dos estructuras
 * \param int Largo
 * \return int(-1) si los parametros son NULL (0) su resolvio
 */
void arc_bajaPorIdCruzado(Arcade* list, int LARGO, int ID)
{
	int i;
	int contador=0;
	if(list!=NULL && LARGO>0 && ID>=0)
	{
		for(i=0;i<LARGO;i++)
		{
			if(list[i].idSalon==ID && list[i].isEmpty==OCUPADO)
			{
				list[i].isEmpty=LIBRE;
				printf("\nEl Arcade %d tambien a sido dado de baja\n",list[i].id);
				contador++;
			}
		}
		if(contador==0)
		{
			printf("\n El Salon no tenia Arcades asociados\n");
		}
		else
		{
			printf("\nCon el Salon %d se han eliminado %d Arcades\n",ID, contador);
		}
	}
}

/** \brief Inicializa en 0, o LIBRE, toda las variables isEmpty de la estructura
 * \param Lista estructura
 * \param int largo
 * \return int(-1) si fallo (0)si resolvio
 */
int arc_init(Arcade* list, int len)
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



/** \brief Busca en un estructura la posicion libre con la variable bandera isEmpty como parametro
 * \param Lista estructura
 * \param int Largo
 * \return int(-1) campos NUll int (posicion libre) si resuelve
 */
int arc_buscarLibre(Arcade* estructura,int LARGO)
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

/** \brief Busca una plantilla de empleado a traves del campo de ID
 * \param Lista estructura
 * \param int largo
 * \param int ID
 * \return int(-1) falla, int (ID) si resuelve
 */
int arc_buscarPorId(Arcade* list,int len,int id)
{
	int retorno=-1;
	int i;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id==id && list[i].isEmpty==OCUPADO)
			{
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
int arc_buscarOcupado(Arcade* estructura,int LARGO)
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

/** \brief agrega las variables recolectadas por otra funcion a una estructura
 * \param Lista estructura
 * \param int Posicion de la estructura donde cargar los datos
 *  \param int id nuevo id generado por otra funcion
 *  \param char name[] y char Last Name [] cargan los nombre y apellido que recibieron por parametros las variables de una estructura
 * \return int(-1) si algun parametro es NULL (0) si logro copiar
 */
int arc_Add(Arcade* list, int len,int idSalon, char nacion[],int sonido,int players,int monedaMax,char juego[])
{
	int retorno=-1;
	if(list!=NULL && len>=0 && nacion!=NULL && idSalon && sonido>0 && players>0 && monedaMax>0 && juego!=NULL)
	{
		list[len].id=arc_generadorId();
		list[len].idSalon=idSalon;
		strcpy(list[len].nac,nacion);
		strcpy(list[len].juego,juego);
		list[len].players=players;
		list[len].tipSon=sonido;
		list[len].monedaMax=monedaMax;
		list[len].isEmpty=OCUPADO;
		retorno=0;
	}
	return retorno;
}
/** \brief Imprime por pantalla los campos de una sola plantila en una posicion especifica sin verificar si hay datos cargados
 * \param LIsta estructura
 * \param int posicion donde se encuentra la plantilla
 * \return no retorna, solo imprime
 */
void arc_mostrarUnaPosicion(Arcade* list,int posicion)
{
	printf("\n__________________________________________________________________________________\n|                 ||               ||Jug||Mon||MON||   Nacio-  ||       ||\n|      Arcade     ||    Salon:     ||Max||max||EST||  nalidad  || Juego ||\n__________________________________________________________________________________\n");
	if(list!=NULL && posicion>-1)
	{
		printf("| ID Arcade: %d |",list[posicion].id);
		printf("| ID Salon: %d |",list[posicion].idSalon);
		printf("| %d |",list[posicion].players);
		printf("| %d |",list[posicion].monedaMax);
		printf("| %d |",list[posicion].tipSon);
		printf("| %s |",list[posicion].nac);
		printf("| %s |\n",list[posicion].juego);
	}
	else
	{
		printf("No se encontro ID");
	}
}
void arc_mostrarUnaPosicion2(Arcade* list,int posicion)
{
	if(list!=NULL && posicion>-1)
	{
		printf("| ID Arcade: %d |",list[posicion].id);
		printf("| ID Salon: %d |",list[posicion].idSalon);
		printf("| %d |",list[posicion].players);
		printf("| %d |",list[posicion].monedaMax);
		printf("| %d |",list[posicion].tipSon);
		printf("| %s |",list[posicion].nac);
		printf("| %s |\n",list[posicion].juego);
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
int arc_ImprimirTodos(Arcade* list, int LARGO)
{
	int retorno=-1;
	int i;
	if(list!=NULL && LARGO>0)
	{
		printf("\n__________________________________________________________________________________\n|                 ||               ||Jug||Mon||MON||   Nacio-  ||       ||\n|      Arcade     ||    Salon:     ||Max||max||EST||  nalidad  || Juego ||\n__________________________________________________________________________________\n");
		for(i=0;i<LARGO;i++)
		{
			if(list[i].isEmpty==OCUPADO)
			{
				arc_mostrarUnaPosicion2(list,i);
				retorno=0;
			}
		}
	}
	return retorno;
}



int arc_bajaLogica(Arcade* list, int len, int id)
{
	int retorno=-1;
	int i;

	if(list!=NULL && len>0 && id>=0)
	{
		i=arc_buscarPorId(list, len, id);
		if(i>-1)
		{
			list[i].isEmpty=LIBRE;
			retorno=0;
		}
		else
		{
			retorno=-2;
		}
	}

	return retorno;
}
//imprimir juegos

void imprimirJuegos(Arcade* struc, int LEN)
{
	#define CANT_ARCADES 1000//recordar igualar a maximo de arcades
	int i;//arcade
	int j;//recorrer estructura juegos
	int x=0;//cargar estructura juegos

	int flag=0;
	typedef struct
	{
	  char juego[63];
	  int isEmpty;
	}Juegos;
	Juegos eJuegos[CANT_ARCADES];
	arc_init(eJuegos, CANT_ARCADES);

	if(struc!=NULL && LEN>0)
	{
		for(i=0;i<LEN;i++)//arcade
		{
			if(struc[i].isEmpty==OCUPADO)
			{
				if(flag==0)
				{
					flag=1;
					strcpy(eJuegos[x].juego,struc[i].juego);
					eJuegos[x].isEmpty=OCUPADO;
				}
				else
				{
					for(j=0;j<CANT_ARCADES;j++)
					{
						if(strcmp(struc[i].juego,eJuegos[x].juego)!=0)
						{
							x++;
							strcpy(eJuegos[x].juego,struc[i].juego);
							eJuegos[x].isEmpty=OCUPADO;
						}
					}
				}
			}
		}
		for(j=0;j<CANT_ARCADES;j++)
		{
			if(eJuegos[j].isEmpty==OCUPADO)
			{
				printf(" %s \n",eJuegos[j].juego);
			}
		}
	}
}



