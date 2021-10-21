/*
 * Arcades.h
 *
 *  Created on: 17 oct. 2021
 *      Author: HERNAN
 */

#ifndef ARCADES_H_
#define ARCADES_H_

//Tipo de salon
#define SHOPPING 1
#define LOCAL 2

//Tipo de sonido
#define MONO 1
#define ESTEREO 2


typedef struct
{
 int id;
 int idSalon;
 char nac[51];
 int tipSon;
 int players;
 int monedaMax;
 char juego[63];
 int isEmpty;

}Arcade;

void altaForzadaArcade(Arcade* struc, int LEN, int i, int idSalon,char* nac, int tipSon, int players, int monedaMax,char* juego);

int arc_init(Arcade* list, int len);
int arc_buscarLibre(Arcade* estructura,int LARGO);
int arc_buscarPorId(Arcade* list,int len,int id);
int arc_buscarOcupado(Arcade* estructura,int LARGO);
int arc_Add(Arcade* list, int len,int idSalon, char nacion[],int sonido,int players,int monedaMax,char juego[]);


int arc_ImprimirTodos(Arcade* list, int LARGO);
void arc_mostrarUnaPosicion2(Arcade* list,int posicion);
void arc_mostrarUnaPosicion(Arcade* list,int posicion);
void imprimirJuegos(Arcade* struc,int LEN);

int arc_bajaLogica(Arcade* list, int len,int id);
void arc_bajaPorIdCruzado(Arcade* list, int LARGO, int ID);


#endif /* ARCADES_H_ */


