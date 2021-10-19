/*
 * Informes.h
 *
 *  Created on: 17 oct. 2021
 *      Author: HERNAN
 */

#ifndef INFORMES_H_
#define INFORMES_H_


int arc_baja(Arcade* list, int len, Salon* list2, int largo);
int arc_modificacion(Arcade* pArray, int LARGO, Salon* pArray2, int LARGO2);
int arc_Alta(Arcade* list1,int LARGO1, Salon* list2,int LARGO2);

int sal_baja(Salon* list, int len, Arcade* list2,int len2);
int sal_bajaLogica(Salon* list, int len, int id ,Arcade* list2,int len2);
void arc_imprimirArcadesIdSalon(Salon* list, int posicion ,Arcade* list2,int largo);
void imprimirSalonconMasArcades(Arcade* list, int posicion ,Salon* list2,int largo);


//9
void contarSalonesSegunArcades(Salon* struc1, int LEN_S1,Arcade* struc2,int LEN_S2);
void listarArcadesPorJugadores(Arcade* struc,int LEN1,Salon* struc2, int LEN2, int CANTJUG);
void infoSalonxId(Arcade* struc,int LEN1,Salon* struc2, int LEN2);
void contarArcadesxSalon(Arcade* struc,int LEN1,Salon* struc2, int posicion);
void listarArcadesxIdSalon(Arcade* struc,int LEN1,Salon* struc2, int LEN2);
void recaudacionMaxPorSalon(Arcade* struc,int LEN1,Salon* struc2, int LEN2);
void verificarJuegoCargado(Arcade* struc, int LEN);

#endif /* INFORMES_H_ */
