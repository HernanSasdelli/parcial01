/*
 ============================================================================
 Name        : Parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
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


int main(void)
{
	setbuf(stdout, NULL);

	Salon eSalones[CANT_SALONES];
	Arcade eArcades[CANT_ARCADES];

	int opcion;
	char respuesta;
	int controlArcade;
	int controlBajaSalon;


	printf("\nBIENVENID@ AL PROGRAMA DE LOS '90\n");
	if(arc_init(eArcades, CANT_ARCADES)==0 && sal_init(eSalones, CANT_SALONES)==0)
	{
		do
		{
			printf("\n____________________________________\nMENU PRINCIPAL\n____________________________________\n");
			printf("\n-----------SALONES-------------\n1. ALTA SALON\n2. ELIMINAR SALON\n3. SALONES ACTIVOS\n\n-----------ARCADES-------------\n4. INCORPORAR ARCADE\n5. MODIFICAR ARCADE\n6. ELIMINAR ARCADE\n7. LISTA DE ARCADES\n8. LISTADO DE JUEGOS\n9. INFORMES");
			if(utn_getNumero(&opcion,"\n\nIngrese Opcion\n","ERROR! Opcion Invalida, reintente\n",1,9,2)==0)
			{
				switch (opcion)
				{
					case 1:
						printf("\n__________________________________________\n\tALTA DE SALON\n__________________________________________\n");
						do
						{
							if(sal_Alta(eSalones,CANT_SALONES)==-2)
							{
								printf("\nNo tiene mas espacio para altas de salon\nDebera dar de baja un salon primero (opcion 2)\n");
								break;
							}
							else
							{
								if(preguntarSeguir(&respuesta,1,"\nDesea Ingresar otro Salon?s/n\n","\nERROR!Ingreso Invalido\n")==-1)
								{
									printf("\nNo se pudo completar el Alta\n");
									break;
								}
							}

						}while(respuesta=='s'||respuesta=='S');

					break;
					case 2:
						printf("\n__________________________________________\n\tBAJA DE SALONES\n__________________________________________\n");
						do
						{
							controlBajaSalon=sal_baja(eSalones, CANT_SALONES, eArcades,CANT_ARCADES);
							if(controlBajaSalon==-2)
							{
								printf("\nNo hay salones cargados (Opcion 1)\n");
								break;
							}

							{
								switch(controlBajaSalon)
								{
									case -1:
										printf("\nEl Id Ingresado no existe o esta dado de baja\n");
									break;
									case 0:
										printf("\nSe ha completado la baja con exito\n");
									break;
									case 1:
										printf("\nEl salon no se dio de baja\n");
									break;

								}
								if(preguntarSeguir(&respuesta,1,"\nDesea Ingresar Id nuevamente para dar de baja?s/n\n","\nERROR!Ingreso Invalido\n")==-1)
								{
									printf("\nNo se pudo Continuar\n");
									break;
								}
							}
						}while(respuesta=='s'||respuesta=='S');
					break;
					case 3:
						printf("\n__________________________________________\n\tLISTA DE SALONES\n__________________________________________\n");
						if(sal_ImprimirTodos(eSalones, CANT_SALONES)==-1)
						{
							printf("\nNo hay Salones Cargados (Opcion 1)\n");
						}

					break;
					case 4:
						printf("\n__________________________________________\n\tALTA DE ARCADES\n__________________________________________\n");
						do
						{
							controlArcade=arc_Alta(eArcades, CANT_ARCADES, eSalones, CANT_SALONES);
							if(controlArcade==-2)
							{
								printf("\nNo tiene mas espacio para altas de Arcades\nDebera dar de baja una consola primero (opcion 6)\n");
								break;
							}
							else
							{
								if(controlArcade==-3)
								{
									printf("\nNo hay Salones Cargados (Opcion 1)\n");
									break;
								}
								else
								{
									if(controlArcade==-1)
									{
										printf("\nNo se pudo completar el alta de Arcade\n");
									}
									if(preguntarSeguir(&respuesta,1,"\nDesea Ingresar nuevo Arcade?s/n\n","\nERROR!Ingreso Invalido\n")==-1)
									{
										printf("\nRespuesta Ivalida\n");
										break;
									}
								}
							}

						}while(respuesta=='s'||respuesta=='S');
					break;
					case 5:
						printf("\n__________________________________________\n\tMODIFICACION DE ARCADES\n__________________________________________\n");

						do
						{
							controlArcade=arc_modificacion(eArcades,CANT_ARCADES,eSalones,CANT_SALONES);
							if(controlArcade==-2)
							{
								printf("\nNo hay Arcades cargados (Opcion 4)\n");
								break;
							}
							else
							{
								switch(controlArcade)
								{
									case -1:
										printf("\nEl Id Ingresado no existe o esta dado de baja\n");
									break;
									case 0:
										printf("\nSe han modificado campos en la ficha del Arcade\n");
									break;
									case 1:
										printf("\nNo se han modificado campos en la ficha del Arcade\n");
									break;
								}
								if(preguntarSeguir(&respuesta,1,"\nDesea Ingresar Id nuevamente para modificar?s/n\n","\nERROR!Ingreso Invalido\n")==-1)
								{
									printf("\nNo se pudo Continuar\n");
									break;
								}

							}
						}while(respuesta=='s'||respuesta=='S');
					break;
					case 6:
						printf("\n__________________________________________\n\tELIMINAR ARCADES\n__________________________________________\n");
						do
						{
							controlArcade=arc_baja(eArcades,CANT_ARCADES,eSalones,CANT_SALONES);
							if(controlArcade==-2)
							{
								printf("\nNo hay arcades cargados (Opcion 4)\n");
								break;
							}
							else
							{
								switch(controlBajaSalon)
								{
									case -1:
										printf("\nEl Id Ingresado no existe o esta dado de baja\n");
									break;
									case 0:
										printf("\nSe ha completado la baja con exito\n");
									break;
									case 1:
										printf("\nEl salon no se dio de baja\n");
									break;

								}
								if(preguntarSeguir(&respuesta,1,"\nDesea Ingresar Id nuevamente para dar de baja?s/n\n","\nERROR!Ingreso Invalido\n")==-1)
								{
									printf("\nNo se pudo Continuar\n");
									break;
								}
							}
						}while(respuesta=='s'||respuesta=='S');
					break;
					case 7:
						printf("\n__________________________________________\n\tLISTA DE ARCADES\n__________________________________________\n");
						if(arc_ImprimirTodos(eArcades, CANT_ARCADES)==-1)
						{
							printf("\nNo hay Arcades Cargados (Opcion 4)\n");
						}
					break;
					case 8:
						printf("__________________________________________\n\tJUEGOS CARGADOS\n__________________________________________\n");
						imprimirJuegos(eArcades, CANT_ARCADES);
					break;
					case 9:
						printf("\n__________________________________________\n\tINFORMES\n__________________________________________\n");
						if(sal_buscarOcupado(eSalones, CANT_SALONES)==0)
						{
							if(arc_buscarOcupado(eArcades, CANT_ARCADES)==0)
							{
								do
								{
									printf("\n-------------------\n\tMENU\n-------------------\n1. Salones con mas de 4 arcades\n2. Arcades con mas de 2 jugadores\n3. Info Salon por ID\n4. Arcades de Salon x ID\n5. Salon con mas Arcades\n6. Maxima Recaudacion Total por Salon\n7. Verificar juego cargado\n");
									printf("\n8. Salir de Informes ->");
									if(utn_getNumero(&opcion,"\n\nIngrese Opcion\n","ERROR! Opcion Invalida, reintente\n",1,8,2)==0)
									{
										switch(opcion)
										{
											case 1://Salones con mas de 4 arcades
												contarSalonesSegunArcades(eSalones,CANT_SALONES,eArcades,CANT_ARCADES);
											break;
											case 2://Arcades con mas de 2 jugadores
												listarArcadesPorJugadores(eArcades,CANT_ARCADES,eSalones,CANT_SALONES,2);
											break;
											case 3://Info Salon por ID
												 infoSalonxId(eArcades,CANT_ARCADES,eSalones,CANT_SALONES);
											break;
											case 4://Arcades de Salon x ID
												listarArcadesxIdSalon(eArcades,CANT_ARCADES,eSalones,CANT_SALONES);
											break;
											case 5://Salon con mas Arcades

												imprimirSalonconMasArcades(eArcades,CANT_ARCADES,eSalones,CANT_SALONES);
											break;
											case 6://Maxima Recaudacion Total por Salon
												recaudacionMaxPorSalon(eArcades,CANT_ARCADES,eSalones,CANT_SALONES);
											break;
											case 7://Verificar juego cargado
												verificarJuegoCargado(eArcades, CANT_ARCADES);
											break;
											case 8:
												opcion=8;
											break;
											default:
												printf("\nOpcion Invalida\n");


										}
									}
								}while(opcion!=8);
							}
							else
							{
								printf("No hay Arcades Cargados (Opcion 4)");
							}
						}
						else
						{
							printf("No hay Salones Cargados (Opcion 1)");
						}

					break;
				}
			}
			else
			{
				puts("No ha ingresado opcion valida");
			}
			if(preguntarSeguir(&respuesta,2,"\nDesea Continuar en el Programa?s/n\n","\nERROR!Ingreso Invalido\n")==-1)
			{
				printf("ERROR! Opcion invalida el programa se cerrara");
				break;
			}

		} while (respuesta=='s' ||respuesta=='S');
	}
	else
	{
		printf("ERROR! No se pudo inicializar, el programa se cerrara");

	}

	printf("________________________________________\nGRACIAS POR UTILIZAR ESTE PARCIAL 1\n________________________________________\nPRESIONE CUALQUIER TECLA PARA SALIR");
	getch();

	return EXIT_SUCCESS;
}
