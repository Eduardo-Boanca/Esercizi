/* 
    Eduardo Boanca 3^C Informatica
    Programma che conta il numero di parole all'interno di una frase
    dove si suppone che una frase sia costituita di parole,
    dove una parola è una sequenza di caratteri diversi dallo spazio e delimitata da
    uno o più spazi a destra e sinistra. Uno o più spazi possono aprire o chiudere la frase.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1000

/*----------------------------------------------------------------
    Funzione che mi permette di inserire una stringa
    Variabili: char str[] --> Input string
------------------------------------------------------------------*/
void input(char str[LEN])
{
    printf("Inserisci la frase: ");
    gets(str);
}

/*----------------------------------------------------------------
    Funzione che mi permette contare quante parole ci sono all'interno
    della frase
    Variabili: char string[] --> Contiene la frase inserita in input
               int i --> Contatore (contatore di caratteri)
               int w --> Contatore (contatore di parole)
------------------------------------------------------------------*/
void checkParole(char str[LEN], int *i = 0, int *w = 0)
{

    for (*i = 0; *i < strlen(str); *i = *i + 1) //for che cicla per tutta la lunghezza della frase
    {
        if (str[*i] != ' ' && str[*i] != '\t' && str[*i] != ';' && str[*i] != ':') //si esegue un controllo per capire dove inizia e finisce una parola
        {
            *w = *w + 1; //si incrementa il contatore di parole

            while (str[*i] != ' ' && str[*i] != '\0') //Serve per saltare allo spazio successivo
                *i = *i + 1;   //si incrementa il contatore di caratteri
        }
    }
}

/*----------------------------------------------------------------
    Funzione che stampa a video il numero di parole e di caratteri
    Variabili: int i --> Contatore (contatore di caratteri)
               int w --> Contatore (contatore di parole)
------------------------------------------------------------------*/
void output(int *i, int *w)
{
    printf("Parole = %d", *w);
    printf("\nCaratteri totali (spazi inclusi) = %d", *i - 1);
}

int main()
{
    char str[LEN];
    int i = 0, w = 0;

    input(str);
    checkParole(str,&i,&w);
    output(&i, &w);

    return 0;
}
