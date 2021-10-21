/*
 * Juegos.c
 *
 *  Created on: 20 oct. 2021
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
/** \brief Inicializa en 0, o LIBRE, toda las variables isEmpty de la estructura
 * \param Lista estructura
 * \param int largo
 * \return int(-1) si fallo (0)si resolvio
*/
void game_init(Game* list, int LEN)
{
	int i;
	if (list!=NULL && LEN>0)
	{
		for (i=0;i<LEN; i++)
		{
			list[i].isEmpty=LIBRE;

		}
	}
}

/** \brief Busca en un estructura la posicion libre con la variable bandera isEmpty como parametro
 * \param Lista estructura
 * \param int Largo
 * \return int(-1) campos NUll int (posicion libre) si resuelve
 */
int game_buscarLibre(Game* list,int LEN)
{
	int retorno=-1;
	int i;
	if(list!=NULL && LEN>0)
	{
		for(i=0;i<LEN;i++)
		{
			if(list[i].isEmpty==LIBRE)
			{
				retorno=i;
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
void game_Add(Game* list,int LEN, char* game)
{
	int pos;
	if(list!=NULL && LEN>=0 && game!=NULL)
	{
		if ((game_BuscarRepetido(list, LEN, game))!=0)
		{
			pos=game_buscarLibre(list, LEN);
			strcpy((list[pos].juego),game);
			list[pos].isEmpty=OCUPADO;
		}
	}
}
int game_BuscarRepetido(Game* list, int LEN, char* game)
{
	int retorno=-1;
	int i;
	for(i=0;i<LEN;i++)
	{
		if(list[i].isEmpty==OCUPADO)
		{
			if((strcmp(list[i].juego,game))==0)
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
//NO ANDA
/*int game_Baja(Game* list,int LEN, char* game)
{
	int retorno=-1;
	int pos;
	if(list!=NULL && LEN>=0 && game!=NULL)
	{
		retorno=0;
		if (game_BuscarRepetido==0)
		{
			pos=game_buscarLibre(list, LEN);
			strcpy(list[pos].juego,game);
			list[pos].isEmpty=OCUPADO;
		}
	}
	return retorno;
}*/
/** \brief Imprime una estructura completa y las variables de cada plantilla siempre que esten en uso
 * \param Lista estructura
 * \param int largo
 *  */
int game_ImprimirTodos(Game* list, int LARGO)
{
	int retorno=-1;
	int i;
	if(list!=NULL && LARGO>0)
	{
		for(i=0;i<LARGO;i++)
		{
			if(list[i].isEmpty==OCUPADO)
			{
				printf("%s\n",list[i].juego);
				retorno=0;
			}
		}
	}
	return retorno;
}

