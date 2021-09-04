/* 
    Eduardo Boanca 3^C Informatica
    Programma che dice se la parola inserita da tastiera è palindroma,
    ovvero se è leggibile allo stesso modo da sinistra a destra e
    viceversa (es. OSSESSO)

    VERSIONE MANUALE CON CODICE PER IDENTIFICARE SE LA PAROLA E PALINDROMA
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#define LEN 20

/*----------------------------------------------------------------
Chiede in input la stringa inserendola nell'Array
*    Parametri
*        char parola[]: input: contiene la stringa
----------------------------------------------------------------*/
void input(char parola[])
{
    printf("Inserisci la parola: ");
    gets(parola);
}

/*----------------------------------------------------------------
Esegue il toupper della stringa inserita in input
*    Parametri
*        char parola[]: input/output: stringa maiuscola
----------------------------------------------------------------*/
void toupperParola(char parola[])
{
    for (int i = 0; i < strlen(parola); i++)
        parola[i] = toupper(parola[i]);
}

/* ----------------------------------------------------------------
Controlla se la stringa inserita in input è palindroma
*    Parametri
*        char parola[]: input: stringa da controllare
*        return bool isPalindroma: return se la parola è palindroma o no
-----------------------------------------------------------------*/
bool checkPalind(char parola[])
{
    toupperParola(parola);
    bool isPalindroma = true;
    for (int i = 0; i < strlen(parola)/2 && isPalindroma; i++)
        if(parola[i] != parola[(strlen(parola)-1)-i]) //compara se parola[i] è uguale a l'inverso (parola[(strelen(parola)-1)-i])
            isPalindroma = false;

    return isPalindroma;
}

/*-------MAIN-------*/
int main(int argc, char const *argv[])
{
    char parola[LEN];

    input(parola);
    if(checkPalind(parola))
        printf("La stringa inserita (%s) è palindroma", parola);
    else
        printf("La stringa inserita (%s) non è palindroma", parola);

    return 0;
}

