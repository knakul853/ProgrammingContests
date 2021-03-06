/*
Alfonso Alfonso Peterssen
2 - 8 - 2007
PSN 2007 #61 "Cambiando de Dolar a Euro"
*/
#include <fstream>
#include <algorithm>
using namespace std;

#define problem "d"
#define LIMIT 1000000

int N, i, sol;
int C[ LIMIT ];

  int dfs( int x ) {
    if ( x <= LIMIT ) return C[x];
    return max( x, dfs( x / 2 ) + dfs( x / 3 ) + dfs( x / 4 ) );
  }

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N;

  for ( i = 1; i <= LIMIT; i++ ) {
    C[i] = C[ i >> 1 ] + C[i / 3] + C[ i >> 2 ];
    if ( i > C[i] ) C[i] = i;
  }

  fout << dfs( N ) << endl;

  return 0;
}

/*
61� Cambiando de Dolar a Euro.                            Croacia 2007
����������������������������������������������������������������������

Es muy frecuente que en las recientes Olimpiadas celebradas en Europa,
que el equipo  de  Cuba al llegar al  aeropuerto tenga que cambiar su
dinero (en dolares) a Euros para poder realizar algunas operaciones.

Al llegar al banco los miembros  de la delegaci�n se dieron cuenta  de
que hab�a dos maneras de  hacer un cambio de moneda. Se podia  cambiar
todas las monedas  en  dolar por la  misma  cantidad  en  euros o  por
la   suma    de  las    siguientes  denominaciones: N/2,   N/3  y  N/4
(divisones   enteras). Al   hacer estas  operaciones  pudieron  pensar
que al  hacer estas  divisiones  podr�an perder mucho dinero.  Observe
el siguiente ejemplo mostrado debajo.

Ejemplo: N = 12 dolar

�����������������Ŀ   ������������������������Ŀ
�     Cambio 1    �   �     Cambio 2           �
�����������������Ĵ   ������������������������Ĵ
� Dolar �   Euro  �   � Dolar  �      Euros    �
� 12    �   12    �   � 12     �   12 / 2 =  6 �
�������������������   �        �   12 / 3 =  4 �
                      �        �   12 / 4 =  3 �
                      �        �  Total     13 �
                      ��������������������������

Buscando los miembros de la delegaci�n obtener m�s ganancia realizaron
el segundo cambio.

Tarea

Ayude al  equipo de  Cuba a  obtener una  ganancia mayor  a la hora de
hacer el cambio de dinero de Dolar a Euro, manteniendo en cada  cambio
la mayor ganancia posible.

Entrada

La entrada ser� a trav�s del fichero DOLEUR.IN el cual consistir� de
una sola l�nea conteniendo el n�mero entero N (1 <= N <= 30000000).

Salida

La salida ser� hacia el fichero  DOLEUR.OUT el cual en su �nica  l�nea
contendr� el valor m�ximo obtenido por el jefe de la delegaci�n cubana
al hacer el cambio de Dolar a Euro.

Ejemplos de Entrada y Salida:

Ejemplo 1

�����������Ŀ   ������������Ŀ
� DOLEUR.IN �   � DOLEUR.OUT �
�����������Ĵ   ������������Ĵ
� 12        �   � 13         �
�������������   ��������������

Ejemplo 2

�����������Ŀ   ������������Ŀ
� DOLEUR.IN �   � DOLEUR.OUT �
�����������Ĵ   ������������Ĵ
� 24        �   � 27         �
�������������   ��������������
*/
