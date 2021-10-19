/*
 * Informes.c
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

#define CANT_ARCADES 1000
#define CANT_SALONES 100
#define OCUPADO 1
#define LIBRE 0




/** \brief baja logica a traves de bandera isEmpty buscando por ID
 * \param lista estructura
 * \param int largo
 * \return int(-1) por parametros NULL, (-2) si no existen plantillas para modificar (0) si desea continuar
 */
int arc_baja(Arcade* list, int len, Salon* list2, int largo )
{
	int retorno=-1;
	int id=-1;
	int posicion;
	char auxRespuesta;
	int reintentos=2;

	if(list!=NULL && len>0)
	{
		if(arc_ImprimirTodos(list,len)==-1)
		{
			//no hay empleados cargados
			retorno=-2;
		}
		else
		{
			do{
					if(utn_getNumero(&id,"\nSeleccione ID que desea dar de baja: \n", "\nERROR! No esta ingresando un valor de ID\n",0,3000,2)==0)
					{
						posicion=arc_buscarPorId(list,len,id);
						if(posicion==-1)
						{
							//el id ingresado no existe
							retorno=-1;
						}
						else
						{
							printf("\nEl Arcade ID %d tiene cargados los siguientes datos:\n ",id);
							arc_mostrarUnaPosicion2(list,posicion);
							printf("\nEl Salon al que pertenecese es:\n ");
							int posicionSalon=sal_buscarPorId(list2,largo,list[posicion].idSalon);
							sal_mostrarUnaPosicion(list2, posicionSalon);
							if(preguntarSeguir(&auxRespuesta,1,"\nEsta seguro de dar de baja?s/n\n","\nERROR!Ingreso Invalido\n")==-1)
							{
								//no se decide si seguir
								retorno=1;
								break;
							}
							else
							{
								if(auxRespuesta=='s' || auxRespuesta=='S')
								{
									if(arc_bajaLogica(list, len, id)==0)
									{
										retorno=0;
										break;
									}
									else
									{
										retorno=1;
										break;
									}

								}
							}
						}
					printf("\El ID ingresado no existe o esta dado de baja\n");
					reintentos--;
					}
				}while(reintentos>=0);
		}
	}
	return retorno;
}
/*
 * brief
 *
 *
 *
 * */
int sal_bajaLogica(Salon* list, int len, int id,Arcade* list2,int len2)
{
	int retorno=-1;
	int i;

	if(list!=NULL && len>0 && id>=0)
	{
		i=sal_buscarPorId(list, len, id);
		if(i>-1)
		{
			list[i].isEmpty=LIBRE;
			arc_bajaPorIdCruzado(list2, len2, id);
			retorno=0;
		}
		else
		{
			retorno=-2;
		}
	}

	return retorno;
}

int sal_baja(Salon* list, int len, Arcade* list2,int len2)
{
	int retorno=-1;
	int id;
	int posicion;
	char auxRespuesta;

	if(list!=NULL && len>0)
	{
		if(sal_ImprimirTodos(list,len)==-1)
		{
			//no hay salones
			retorno=-2;
		}
		else
		{
			if(utn_getNumero(&id,"\nSeleccione ID que desea dar de baja: \n", "\nERROR! No esta ingresando un valor de ID\n",0,3000,2)==0)
			{
				posicion=sal_buscarPorId(list,len,id);
				if(posicion==-1)
				{
					//el id ingresado no existe
					retorno=-1;
				}
				else
				{
					printf("El ID %d tiene cargados los siguientes datos:\n ",id);
					sal_mostrarUnaPosicion(list,posicion);

					if(preguntarSeguir(&auxRespuesta,1,"\nEsta seguro de dar de baja?s/n\n","\nERROR!Ingreso Invalido\n")==-1)
					{
						//no se decide si seguir
						retorno=1;
					}
					else
					{
						if(auxRespuesta=='s' || auxRespuesta=='S')
						{
							if(sal_bajaLogica(list, len, id,list2,len2)==0)
							{
								retorno=0;
							}

						}
						else
						{
							retorno=1;
						}
					}
				}
			}
		}
	}
	return retorno;
}



/** \brief a traves de un menu permite modificar por separados todas las variables de una posicion de las estructura
 * \param Lista Estructura
 * \param int LArgo
 * \return int (-1) si algun parametro es NULL, (-2) si no existen datos por modificar (0) si logra moficar al menos una variable de toda la plantilla (1)si no se modifica ninguna variable
 */
int arc_modificacion(Arcade* pArray, int LARGO, Salon* pArray2, int LARGO2)
{
	int retorno=-1;
	int id;
	int posId;
	char auxRespuesta;
	int auxOpcion;
	int flagCarga=0;
	char juego[63];
	int posIdSalon;
	int players;

	Arcade auxiliarArray[LARGO];//recordar pasar el dato de LARGO con un strlen o define para que las cadenas queden iguales

	if(pArray!=NULL && LARGO>0)
	{
		if(arc_ImprimirTodos(pArray,LARGO)==-1)
		{
			//no hay arcades cargados
			retorno=-2;
		}
		else
		{

			if(utn_getNumero(&id,"\nSeleccione ID que desea modificar: \n", "\nERROR! No esta ingresando un valor de ID\n",0,3000,2)==0)
				{
					posId=arc_buscarPorId(pArray,LARGO,id);//el find ya verificaba que no este dado de baja
					if(posId<0)
					{
						//el id ingresado no existe
						retorno=-1;
					}
					else
					{
						auxiliarArray[posId]=pArray[posId];
						printf("\nEl ID %d tiene cargados los siguientes datos:\n ",id);
						arc_mostrarUnaPosicion(pArray,posId);
						posIdSalon=sal_buscarPorId(pArray2, LARGO2,pArray[posId].idSalon);
						printf("\nDatos del Salon que contiene el Arcade:\n");
						sal_mostrarUnaPosicion(pArray2,posIdSalon);

						if(preguntarSeguir(&auxRespuesta,1,"\nEsta seguro de modificar?s/n\n","\nERROR!Ingreso Invalido\n")==-1)
						{
							printf("\nNo se pudo completar la modificacion\n");
							retorno=-1;
						}
						else
						{
							if(auxRespuesta=='s' || auxRespuesta=='S')
							{
								do{

									if(utn_getNumero(&auxOpcion,"\nQue dato desea modificar? \n1-Cantidad de Jugadores\n2-Juego que contiene\nIngrese: ", "\nERROR! No esta ingresando una opcion valida\n",1,2,2)==0)
									{
										switch(auxOpcion)
										{
											case 1:

												if(utn_getNumero(&players,"\nIngrese nueva cantidad de Jugadores (1 a 10)\n","\nError! Ingreso Invalido\n",1, 10, 2)==0)
												{
													auxiliarArray[posId].players=players;
													printf("\nCantidad de jugadores modificada con exito\n");
													flagCarga=1;
												}
												else
												{
													printf("\nEste campo no se pudo modificar\n");
												}
											break;
											case 2:
												if(utn_getTexto(juego,sizeof(juego),"\nIngrese nombre de nuevo juego\n","Error! Ingreso invalido\n",2)==0)
												{
													strcpy(auxiliarArray[posId].juego,juego);
													printf("\nNombre del Juego modificadp con exito\n");
													flagCarga=1;
												}
												else
												{
													printf("\nEste campo no se pudo modificar\n");
												}
											break;
										}
										pArray[posId]=auxiliarArray[posId];
										//copio el auxiliar en el array original para no romper
									}
									else
									{
										retorno=1;
										if(flagCarga==1)
										{
											retorno=0;
										}
										printf("\nNo se pudo completar la modificacion\n");
										break;
									}
									if(preguntarSeguir(&auxRespuesta,1,"\nDesea Modificar otros campos?s/n\n","\nERROR!Ingreso Invalido\n")==-1)
									{
										retorno=1;
										if(flagCarga==1)
										{
											retorno=0;
										}
										printf("\nNo se pudo completar la modificacion\n");

									}
									else
									{
										if(auxRespuesta=='n' || auxRespuesta=='N')
										{
											retorno=1;
											if(flagCarga==1)
											{
												retorno=0;
												printf("\nEl ID %d, ahora tiene los siguientes datos: \n",id);
												arc_mostrarUnaPosicion(pArray, posId);
											}


										}
									}

								}while(auxRespuesta=='s' || auxRespuesta=='S');
							}
							else
							{
								retorno=1;
							}

						}

					}
				}
				else
				{
					printf("\nERROR! No se pudo completar la operacion\n");
				}
		}
	}
	return retorno;
}
void arc_imprimirSalonIdArcade(Arcade* list, int posicion ,Salon* list2,int largo)
{
	int i;
	if(list!=NULL && posicion>=0 && list2!=NULL && largo>0)
	{
		for(i=0;i>largo;i++)
		{
			if(list2[i].idSalon==list[posicion].idSalon)
			{

				sal_mostrarUnaPosicion(list2,i);
				break;
			}
		}

	}
}
void arc_imprimirArcadesIdSalon(Salon* list, int posicion ,Arcade* list2,int largo)
{
	int i;
	if(list!=NULL && posicion>=0 && list2!=NULL && largo>0)
	{
		for(i=0;i>largo;i++)
		{
			if(list2[i].idSalon==list[posicion].idSalon)
			{

				arc_mostrarUnaPosicion2(list2,i);
				break;
			}
		}

	}
}
int arc_Alta(Arcade* list1,int LARGO1, Salon* list2,int LARGO2)
{
	int retorno=-1;
	int disponible;

	int idSalon;
	char nacion[63];
	int sonido;
	int players;
	int monedaMax;
	char juego[63];
	int reintentos=2;

	if(list1!=NULL && LARGO1>0 && list2!=NULL && LARGO2>0)
	{
	  disponible=arc_buscarLibre(list1, LARGO1);
	  if(disponible>=0)
	  {
		 if(sal_ImprimirTodos(list2, LARGO2)==-1)
		 {
			 retorno=-3;
		 }
		 else
		 {

			do
			{
				if(utn_getNumero(&idSalon,"\nIngrese el Salon al que pertenecera el Arcade\n","\nError! Ingreso invalido\n",1,999,2)==0)
				{
					if(sal_buscarPorId(list2, LARGO2, idSalon)>-1)
					{
						if(utn_getTexto(nacion,sizeof(nacion),"\nIngrese pais de Fabricacion del Arcade\n","\nError! Ingreso invalido\n",2)==0)
						{
							if(utn_getNumero(&sonido,"\nSelecciones tipo de sonido\n1. MONO\n2. ESTEREO\nIngrese: ","\nError! Ingreso invalido\n",1,2,2)==0)
							{
								if(utn_getNumero(&players,"\nIndique cantidad de jugadores (1-10)\n","\nError! Ingreso invalido\n",1,10,2)==0)
								{
									if(utn_getNumero(&monedaMax,"\nIndique cantidad maxima de monedas (1-150)\n","\nError! Ingreso invalido\n",1,150,2)==0)
									{
										if(utn_getTexto(juego,sizeof(nacion),"\nIngrese el Titulo del Juego\n","\nError! Ingreso invalido\n",2)==0)
										{

											if(arc_Add(list1,disponible, idSalon, nacion, sonido, players, monedaMax, juego)==0)
											{
												printf("\nAlta Arcade exitosa\n");
												arc_mostrarUnaPosicion(list1, disponible);
												retorno=0;
												break;
											}
											else
												break;
										}
										else
											break;
									}
									else
										break;
								}
								else
									break;
							}
							else
								break;
						}
						else
							break;
					}
					else
					{
						printf("El ID de Salon no existe");
						reintentos--;
					}
				}
			}while(reintentos>=0);

		  }
		}
	   else
	   {
		   retorno=-2;
	   }

	}
	return retorno;
}
//1
void contarSalonesSegunArcades(Salon* struc1, int LEN_S1,Arcade* struc2,int LEN_S2)//salon//arcade
{

	int j;
	int i;

	int contadorAux;
	int contadorMax=0;
	if(struc1!=NULL && struc2!=NULL && LEN_S1>0 && LEN_S2>0)
	{
		for(i=0;i<LEN_S1;i++)
		{
			contadorAux=0;
			//SALON
			if(struc1[i].isEmpty==OCUPADO)
			{
				//arcade
				for(j=0;j>LEN_S2;j++)
				{
					if(struc1[i].idSalon==struc2[j].idSalon)
					{
						contadorAux++;

					}
				}
				if(contadorAux>4)
				{
					sal_mostrarUnaPosicion(struc1, i);
					contadorMax++;
				}
			}
		}
		if(contadorMax==0)
		{
			printf("\nNo hay salones que superen los 4 arcades\n");
		}
		else
		{
			printf("\nLos salones que superan los 4 arcades son:  %d \n",contadorMax);
		}

	}
	else
	{
		printf("\nNo se pudo realizar el informe\n");
	}

}
//2
void listarArcadesPorJugadores(Arcade* struc,int LEN1,Salon* struc2, int LEN2, int CANTJUG)
{
	int i;
	int j;

	if(struc!=NULL && LEN1>0 && CANTJUG>0)
	{
		for(i=0;i<LEN1;i++)
		{
			if(struc[i].players>CANTJUG && struc[i].isEmpty==OCUPADO)
			{
				for(j=0;j<LEN2;j++)
				{
					if(struc[i].idSalon==struc2[j].idSalon)
					{
							printf("El Arcade %d puede jugarse hasta %d jugadores \n Contiene el juego %s y esta en el salon %s\n",struc[i].id,struc[i].players,struc[i].juego,struc2[j].name);

					}
				}
			}
		}
	}

}
//3
void infoSalonxId(Arcade* struc,int LEN1,Salon* struc2, int LEN2)
{
	int reintentos=2;
	int idSalon;
	int posicion;
	if(struc!=NULL && LEN1>0 && struc2!=NULL && LEN2>0 )
	{
		if(sal_ImprimirTodos(struc2, LEN2)==-1)
		{
		  printf("No se puede realizar el informe");
		}
		else
		{
			do
			{
				if(utn_getNumero(&idSalon,"\nIngrese Salon que desea informar\n","\nError! Ingreso invalido\n",1,999,2)==0)
				{
					posicion=sal_buscarPorId(struc2, LEN2, idSalon);
					if(posicion>-1)
					{

						sal_mostrarUnaPosicion(struc2, posicion);
						contarArcadesxSalon(struc, LEN1, struc2, posicion);
						break;

					}
					else
					{
						printf("\nEl ID de Salon no existe\n");
						reintentos--;
					}
				}
			}while(reintentos>=0);
		}
	}
}
//3b
void contarArcadesxSalon(Arcade* struc,int LEN1,Salon* struc2, int posicion)
{
	int i;
	int contador=0;
	for(i=0;i<LEN1;i++)
	{
		if(struc[i].isEmpty==OCUPADO)
		{
			if(struc[i].idSalon==struc2[posicion].idSalon)
			{
				contador++;

			}
		}

	}
	if(contador>0)
	{
		printf("\nEl total de Arcades en este Salon es: %d\n",contador);
	}
	else
	{
		printf("\nNo hay Arcades en este Salon\n");
	}
}
//4
void listarArcadesxIdSalon(Arcade* struc,int LEN1,Salon* struc2, int LEN2)
{
	int i;
	int reintentos=2;
	int idSalon;
	int posicion;
	if(struc!=NULL && LEN1>0 && struc2!=NULL && LEN2>0 )
	{
		if(sal_ImprimirTodos(struc2, LEN2)==-1)
		{
		  printf("No se puede realizar el informe");
		}
		else
		{
			do
			{
				if(utn_getNumero(&idSalon,"\nIngrese Salon que desea visualizar sus Arcades\n","\nError! Ingreso invalido\n",1,999,2)==0)
				{
					posicion=sal_buscarPorId(struc2, LEN2, idSalon);
					if(posicion>-1)
					{
						for(i=0;i<LEN1;i++)
						{
							if(struc[i].isEmpty==OCUPADO)
							{
								if(struc[i].idSalon==idSalon)
								{
									arc_mostrarUnaPosicion2(struc,i);
								}
							}

						}
						break;

					}
					else
					{
						printf("\nEl ID de Salon no existe\n");
						reintentos--;
					}
				}
			}while(reintentos>=0);
		}
	}

}
//6
void recaudacionMaxPorSalon(Arcade* struc,int LEN1,Salon* struc2, int LEN2)
{
	int reintentos=2;
	int idSalon;
	int posicion;
	int i;
	float acumTotal=0;
	float monedaIng;
	float acuArc;

	if(struc!=NULL && LEN1>0 && struc2!=NULL && LEN2>0 )
	{
		sal_ImprimirTodos(struc2, LEN2);

		do
		{
			if(utn_getNumero(&idSalon,"\nIngrese ID de Salon que desa saber la recaudacion maxima\n","\nError! Ingreso invalido\n",1,999,2)==0)
			{
				posicion=sal_buscarPorId(struc2, LEN2, idSalon);
				if(posicion>-1)
				{
					if(utn_getNumeroFloat(&monedaIng,"\nIngrese Valor de fichas $(1/200)\n","\nError! Ingreso invalido\n",1,200,2)==0)
					{
						for(i=0;i<LEN1;i++)
						{
							acuArc=0;
							if(struc[i].isEmpty==OCUPADO)
							{
								if(struc[i].idSalon==idSalon)
								{
									acuArc=struc[i].monedaMax*monedaIng;
									acumTotal=acumTotal+acuArc;
									printf("\n--El Arcade %d puede recaudar $ %.2f en total--\n",struc[i].id,acuArc);
								}
							}

						}
						printf("\nEl Salon %d puede recaudar $ %.2f en total\n",idSalon,acumTotal);
						break;
					}
					else
					{
						printf("\nNo se pudo completar informe\n");
						break;
					}
				}
				else
				{
					printf("\nEl ID de Salon no existe\n");
					reintentos--;
				}
			}
		}while(reintentos>=0);
	}
}
//7
void verificarJuegoCargado(Arcade* struc, int LEN)
{
	int i;
	char juego[63];
	int contador=0;
	if(struc!=NULL && LEN>0)
	{
		if(utn_getTexto(juego,sizeof(juego),"\nIngrese el Nombre un juego\n","\nError! Ingreso invalido\n",2)==0)
		{
			for(i=0;i<LEN;i++)
			{
				if(strcmp(struc[i].juego,juego)==0)
				{
					contador++;
				}
			}
			printf("\nSon %d los Arcades que contienen el juego %s .\n",contador, juego);
		}
	}
}
//5
void imprimirSalonconMasArcades(Arcade* struc,int LEN1,Salon* struc2, int LEN2)
{
	int i;
	int j;
	int contador=0;
	int flag=0;
	int iMax=0;
	int contMax=0;
	if(struc!=NULL && LEN1>0 && struc2!=NULL && LEN2>0)
	{
		for(i=0;i<LEN2;i++)
		{
			contador=0;
			if(struc2[i].isEmpty==OCUPADO)
			{
				for(j=0;j<LEN1;j++)
				{
					if(struc[j].isEmpty==OCUPADO)
					{
						if(struc2[i].idSalon==struc[j].idSalon)
						{
							contador++;
						}
					}
				}
				if(contador>contMax || flag==0)
				{
					contMax=contador;
					iMax=i;
					flag=1;
				}

			}

		}
		if(contMax>0)
		{
			printf("\nEl salon con mas arcades es: %d \n",struc2[iMax].idSalon);
			printf("\nEl nombre del salon es: %s \n",struc2[iMax].name);
			printf("\nLa direccion es: %s \n",struc2[iMax].direc);
			printf("\nEl tipo de salon es (1.Local/2.Shopping): %s \n",struc2[iMax].direc);
		}
	}
}








