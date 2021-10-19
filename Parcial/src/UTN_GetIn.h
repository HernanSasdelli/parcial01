/*
 * UTN_GetIn.h
 *
 *  Created on: 16 oct. 2021
 *      Author: HERNAN
 */

#ifndef UTN_GETIN_H_
#define UTN_GETIN_H_

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int getInt(int* pResultado);
//int getChar(char*pResultado);
int utn_getTexto(char* pArray,int LARGO,char* mensaje, char* mensajeError,int reintentos);
int utn_getNumeroFloat (float* pResultado, char* mensaje, char* mensajeError,float minimo, float maximo, int reintentos);
int preguntarSeguir(char* pRespuesta,int reintentos,char* mensaje,char* mensajeError);

#endif /* UTN_GETIN_H_ */

