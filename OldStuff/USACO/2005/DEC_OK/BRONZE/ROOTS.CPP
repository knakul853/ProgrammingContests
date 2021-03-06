/*
Alfonso Alfonso Peterssen
3 - 8 - 2007
USACO 2005 DEC Bronze "Encontrando Ra�ces Bovinas"
*/
#include <cmath>
#include <fstream>
using namespace std;

#define problem "d"
#define LIMIT 31633
#define sqr( x ) ( ( x ) * ( x ) )

int L, i, sq, t, pot;
double target;

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> L >> target;

  pot = 1;
  for ( i = 0; i < L; i++ )
    pot *= 10;

  for ( i = 0; i <= LIMIT; i++ ) {

    sq = ceil( sqr( i + target / pot ) );
    t = ( sqrt( sq ) - ( int ) sqrt( sq ) ) * pot;

    if ( t == target ) {
      fout << sq << endl;
      break;
    }
  }

  return 0;
}

/*
Problema 13: Encontrando Ra�ces Bovinas [Kolstad, 2005]

Las vacas est�n tratando de encontrar sus ra�ces. Ellas no son tan
inteligentes como los humanos cuando ellos encuentran ra�ces cuadradas,
las vacas pierden la porci�n entera de sus c�lculos de ra�ces cuadradas.
Por lo tanto en vez de calcular la ra�z de 2 como
1.4142135623730950488016887242096980785696, ellas deducen que es
0.4142135623730950488016887242096980785696. La ra�z cuadrada de 16 es
calculada como 0 (obviamente un error).

Sin embargo, este c�lculo err�neo, produce preguntas interesantes. Dada
una cadena de d�gitos de longitud L (1 <= L <= 9), �cu�l es el entero
m�s peque�o cuya parte decimal de ra�z cuadrada bovina comienza con
esos d�gitos?

Por ejemplo, considere la cadena "123". La ra�z cuadrada de 17 es
aproximadamente 4.1231056256176605498214098559740770251472, por lo tanto
su ra�z cuadrada bovina es 0.1231056256176605498214098559740770251472
cuya parte decimal (exactamente despu�s del punto) comienza con 123.
Resulta ser que 17 es el entero m�s peque�o con esta propiedad.

TIEMPO DE EJECUCION: 0.5 segundos

NOMBRE DEL PROBLEMA: roots

FORMATO DE ENTRADA:

* L�nea 1: Un solo entero, L

* L�neas 2: L digitos (sin espacios)

ENTRADA EJEMPLO (archivo roots.in):

3
123

FORMATO DE SALIDA:

* L�nea 1: Un solo entero que es el entero m�s peque�o cuya ra�z cuadrada
        bovina comienza con la cadena dada

SALIDA EJEMPLO (archivo roots.out):

17

DETALLES DE LA SALIDA:

sqrt(17) ~= 4.1231056256176605498214098559740770251472
*/
