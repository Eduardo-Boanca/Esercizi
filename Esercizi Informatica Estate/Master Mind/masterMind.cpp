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
/*------------------------------
Definizione del tipo solutions
-------------------------------*/
typedef struct
{
	int corretto;
	int quasiCorretto;

} solutions;

/*------------------------------
Procedura che stampa una linea
-------------------------------*/
void linea()
{
	for (int i = 0; i < 75; i++)
		printf("-");
}

/*--------------------------------------------------------
Procedura che genera il codice segreto
*	Parametri:
*		int numSegreti[]: output: Contiene il codice segreto
----------------------------------------------------------*/
void codeGen(int numSegreti[LEN])
{
	int i, numRand;

	for (i = 0; i < LEN; i++)
	{
		numRand = rand() % 10;
		numSegreti[i] = numRand;
		printf("%d   ", numSegreti[i]);
	}
}

/*--------------------------------------------------------
Procedura che chiede in input il codice all'interno ad una 
variabile temporanea che poi verrà scomposta ed inserita 
all'interno di un array
*	Parametri:
*		int indNumeri[]: output: Contiene il codice dell'utente
----------------------------------------------------------*/
void guess(int indNumeri[LEN], int *tentativi)
{
	int i;
	int tmpCode;

	printf("Le cifre che puoi inserire sono: ");
	for (i = 0; i < 10; i++)
		printf("%d, ", i);

	do
	{
		printf("\n\nTentativo numero: %d", *tentativi);
		printf("\nInserisci le tue risposte: \n");
		scanf("%d", &tmpCode);
	} while (tmpCode > (pow(10, LEN) - 1) || tmpCode < 0);

	printf("\n");

	for (int i = 0; i < LEN; i++)
	{
		indNumeri[(LEN - 1) - i] = tmpCode % 10; //serve per copiare i numeri in input dentro al vettore
		tmpCode /= 10;
	}
}

/*----------------------------------------------------------------
Procedura che stampa l'array passato come parametro
* Parametri:
*		int vet[]: input: array che sarà stampato
*		int len: input: lunghezza dell'array
----------------------------------------------------------------*/

void stampaVett(int vet[], int len)
{
	for (int i = 0; i < len; i++)
		printf("%d", vet[i]);
}

/*---------------------------------------------------------------------
Procedura che stampa se le cifre sono al posto
giusto oppure no, e in caso il numero venga indovinato
viene stampato il messaggio di vittoria
*	Parametri:
*		int: indNumeri[]: input: codice inserito da utente
*		solutions soluzioni: indizi se le cifre sono nel posto giusto
-----------------------------------------------------------------------*/
void stampaRis(int indNumeri[], solutions soluzioni)
{
	char risp;
	//stampaVett(indNumeri, LEN);
		printf("%d cifre giuste nel posto giusto,  %d cifre giuste nel posto sbagliato", soluzioni.corretto, soluzioni.quasiCorretto);

		printf("\n");
		printf("\n");
		linea();
		printf("\n");
		printf("\n");

		if (soluzioni.corretto == LEN)
			printf("HAI INDOVINATO IL NUMERO! BRAVO!! \n\n");
}

/*----------------------------------------------------------------
Procedura che copia il contenuto del secondo array nel primo
*	Parametri:
*		int vet1[]: input: array contenente la copia
*		int vet2[]: input: array originario
----------------------------------------------------------------*/
void copiaArray(int vet1[], int vet2[])
{
	for (int i = 0; i < LEN; i++)
		vet1[i] = vet2[i];
}

/*--------------------------------------------------------
Funzione che esegue la comparazione dei due codici per
vedere se ci sono differenze, e grazie a questo si possono
ricevere le indicazioni sulle posizoni giuste o meno dei numeri
*	Parametri:
*		int indNumeri[]: input: codice inserito dall'utente
*		int numSegreti[]: input: codice creato dal Programma
*		return solutions: output: contiene le indicazioni se
*			i numeri inseriti sono corretti o quasiCorretti
--------------------------------------------------------*/
solutions verificaCodice(int indNumeri[], int numSegreti[])
{
	int tmpCode[LEN];
	solutions soluzioni;
	soluzioni.corretto = 0;
	soluzioni.quasiCorretto = 0;
	bool checkUguale;

	copiaArray(tmpCode, numSegreti);

	for (int i = 0; i < LEN; i++)
	{
		checkUguale = false;

		for (int j = 0; j < LEN && !checkUguale; j++)
		{
			if (indNumeri[i] == tmpCode[j])
			{
				if (i == j)
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

/*----------------------------------------------
Procedura che stampa l'introduzione al programma
----------------------------------------------*/
void Benvenuto()
{
	printf("\n******************************************************************");
	printf("\n		BENVENUTO AL GIOCO DEL MASTERMIND			");
	printf("\n******************************************************************");
}

/*------MAIN------*/
int main(int argc, char const *argv[])
{
	/* code */
	srand(time(NULL));
	int numSegreti[LEN], indNumeri[LEN], tentativi = 0;
	char risp;
	solutions soluzioni;

	Benvenuto();

	do
	{

		codeGen(numSegreti);
	do
	{
			
		do
		{
			guess(indNumeri, &tentativi);

			soluzioni = verificaCodice(indNumeri, numSegreti);

			stampaRis(indNumeri, soluzioni);
			tentativi++;
		} while (tentativi < MAX_ATT || soluzioni.corretto == LEN);

		printf("\nVUOI CONTINUARE? (S/N): ");
		scanf("%c", &risp);

	} while(risp == 'S');

		if (soluzioni.corretto < LEN)
		printf("MI DISPIACE HAI PERSO...\n\n");


		printf("La combinazione giusta era: ");
		stampaVett(numSegreti, LEN);

		printf("\nVUOI CONTINUARE? (S/N): ");
		scanf("%c", &risp);

	} while (risp == 'S');

	printf("\nSEI USCITO DAL GIOCO\n");

	return 0;
}
