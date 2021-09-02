/* 
    Eduardo Boanca 3^C Informatica
    Programma che dice se la parola inserita da tastiera è palindroma,
    ovvero se è leggibile allo stesso modo da sinistra a destra e
    viceversa (es. OSSESSO)

    VERSIONE AUTOMATICA TRAMITE USO DI FUNZIONE strrev()
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEN 10

/*----------------------------------------------------------------
    Funzione che mi permette di inserire una stringa
    Variabili: char string[] --> Input string
------------------------------------------------------------------*/
void input(char string[])
{
    printf("Inserisci la stringa: ");
    gets(string);
}

/*----------------------------------------------------------------
    Funzione che copia tramite la funzione strcpy()
    il contenuto della string[] all'interno di revString[],
    e tramite la funzione strrev() posso invertire la parola

    Variabili: char string[] --> Input string
               char revString[]
------------------------------------------------------------------*/
void reverseString(char string[], char revString[])
{
    strcpy(revString, string); /* Copio la stringa in input all'interno della revString */
    strrev(revString);         /* Inverto la stringa */
}

/*----------------------------------------------------------------
    Funzione che all'interno di un if tramite la funzione strcmp 
    compara le due stringhe e controlla se sono uguali
    
    Variabili: char string[] --> Input string
               char revString[]
------------------------------------------------------------------*/
void isPalindroma(char string[], char revString[])
{
    if (strcmp(string, revString) == 0) /* Comparo la stringa in input con quella invertita */
        printf("La stringa e' palindroma\n");
    else
        printf("La stringa non e' palindroma\n");
}

int main()
{
    char string[LEN], revString[LEN];

    input(string);
    reverseString(string, revString);
    isPalindroma(string, revString);

    return 0;
}