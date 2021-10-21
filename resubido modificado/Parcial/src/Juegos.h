/*
 * Juegos.h
 *
 *  Created on: 20 oct. 2021
 *      Author: HERNAN
 */

#ifndef JUEGOS_H_
#define JUEGOS_H_
typedef struct
{
 char juego[63];
 int isEmpty;
}Game;

void game_init(Game* list, int LEN);
int game_buscarLibre(Game* list,int LEN);
void game_Add(Game* list,int LEN, char* game);
int game_BuscarRepetido(Game* list, int LEN, char* game);
int game_ImprimirTodos(Game* list, int LARGO);


#endif /* JUEGOS_H_ */
