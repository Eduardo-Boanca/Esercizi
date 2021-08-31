/* 
    Eduardo Boanca 3^C Informatica
    Questo programma ti permette di giocare al gioco del Master Mind.
    In 10 tentativi bisogna indovinare un numero di 4 cifre pensato
    dal computer. Saranno 4 cifre singole contenute in un vettore Int
    di 4 posizioni. Ad ogni tiro il computer dovrà dire quante cifre sono
    state indovinate e in che posizione del vettore
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define LEN 4
#define MAX_ATT 10

void codeGen(int numSegreti[LEN])
{
	int i, numRand;

	srand(time(0));

	for (i = 0; i < LEN; i++)
	{
		numRand = rand() % 10;
		numSegreti[i] = numRand;
	}
}

void guess(int indNumeri[LEN])
{
	int i;
	int tmpCode;

	printf("Le cifre che puoi inserire sono: ");
	for (i = 0; i < 10; i++)
		printf("%d, ", i);

	do
	{
		printf("\nInserisci le tue risposte: \n");
		scanf("%d", tmpCode);
	}
	while(tmpCode > (pow(10,LEN)-1) || tmpCode < 0); 

	printf("\n");

	for(int i = 0; i < LEN; i++)
	{
		indNumeri[(LEN-1)-i] = tmpCode % 10; //serve per copiare i numeri in input dentro al vettore
		tmpCode /= 10;
	}
}

int main(int argc, char const *argv[])
{
	/* code */
	int numSegreti[LEN];

	codeGen(numSegreti);
	return 0;
}
