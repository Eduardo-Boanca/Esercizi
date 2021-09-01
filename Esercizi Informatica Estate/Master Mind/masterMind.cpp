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
#include <iostream>
#include <math.h>

#define LEN 4
#define MAX_ATT 10

typedef struct
{
	int corretto;
	int quasiCorretto;
} solutions;

void linea()
{
	for(int i = 0; i < 75; i++)
		printf("-");
}

void codeGen(int numSegreti[LEN])
{
	int i, numRand;

	srand(time(0));

	for (i = 0; i < LEN; i++)
	{
		numRand = rand() % 10;
		numSegreti[i] = numRand;
		printf("%d", numSegreti[i]);
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
		scanf("%d", &tmpCode);
	}
	while(tmpCode > (pow(10,LEN)-1) || tmpCode < 0); 

	printf("\n");

	for(int i = 0; i < LEN; i++)
	{
		indNumeri[(LEN-1)-i] = tmpCode % 10; //serve per copiare i numeri in input dentro al vettore
		tmpCode /= 10;
	}
}

void stampaVett(int vet[], int len)
{
	for(int i = 0; i < len; i++)
		printf("%d", vet[i]);
}

void stampaRis(int indNumeri[], solutions soluzioni)
{
	stampaVett(indNumeri, LEN);
	printf("%d cifre giuste nel posto giusto,     %d cifre giuste nel posto sbagliato", soluzioni.corretto, soluzioni.quasiCorretto);

	printf("\n");
	printf("\n");
	linea();
	printf("\n");
	printf("\n");

	if(soluzioni.corretto == LEN)
		printf("HAI INDOVINATO IL NUMERO! BRAVO!! \n\n");

}


void copiaArray(int vet1[], int vet2[])
{
	for(int i = 0; i < LEN; i++)
		vet1[i] = vet2[i];
}


solutions verificaCodice(int indNumeri[], int numSegreti[])
{
	int tmpCode[LEN];
	solutions soluzioni;
	soluzioni.corretto = 0;
	soluzioni.quasiCorretto = 0;
	bool checkUguale;

	copiaArray(tmpCode,numSegreti);
	
	for(int i = 0; i < LEN; i++)
	{
		checkUguale = false;

		for(int j = 0; j < LEN && !checkUguale; j++)
		{
			if(indNumeri[i] == tmpCode[j])
			{
				if(i==j)
					soluzioni.corretto++;
				else
					soluzioni.quasiCorretto++;

				checkUguale = true;
				tmpCode[j] = -1;
			}
		}
	}

	return soluzioni;

}


int main(int argc, char const *argv[])
{
	/* code */
	int numSegreti[LEN], indNumeri[LEN], tentativi = 0;
	solutions soluzioni;

	codeGen(numSegreti);

	do
	{
		guess(indNumeri);

		soluzioni = verificaCodice(indNumeri, numSegreti);

		stampaRis(indNumeri, soluzioni);
			tentativi++;
	}
	while(tentativi < MAX_ATT);

	if(soluzioni.corretto < LEN)
		printf("MI DISPIACE HAI PERSO...\n\n");

	printf("La combinazione giusta era: ");
	stampaVett(numSegreti, LEN);
	
	return 0;
}
