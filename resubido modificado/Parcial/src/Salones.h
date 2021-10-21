/*
 * Salones.h
 *
 *  Created on: 17 oct. 2021
 *      Author: HERNAN
 */

#ifndef SALONES_H_
#define SALONES_H_
typedef struct
{
 int idSalon;
 char name[51];
 char direc[51];
 int tipo;
 int isEmpty;

}Salon;

void altaForzadaSalon(Salon* struc, int LEN, int i,char* name, char* direc, int tipo);

int sal_buscarLibre(Salon* estructura,int LARGO);
int sal_buscarOcupado(Salon* estructura,int LARGO);
int sal_buscarPorId(Salon* list,int len,int id);

int sal_init(Salon* list, int len);
int sal_Alta(Salon* estructura, int LARGO);
int sal_Add(Salon* list, int len, int id, char name[],char
		direc[],int tipo);
void sal_mostrarUnaPosicion(Salon* list, int posicion);
int sal_ImprimirTodos(Salon* list, int LARGO);



#endif /* SALONES_H_ */
