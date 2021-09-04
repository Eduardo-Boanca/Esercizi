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

void input(char parola[])
{
    printf("Inserisci la parola: ");
    gets(parola);
}

void toupperParola(char parola[])
{
    for (int i = 0; i < strlen(parola); i++)
        parola[i] = toupper(parola[i]);
}

bool checkPalind(char parola[])
{
    toupperParola(parola);
    bool checkPalind = true;
    for (int i = 0; i < strlen(parola)/2 && checkPalind; i++)
        if(parola[i] != parola[(strlen(parola)-1)-i])
            checkPalind = false;

    return checkPalind;
}

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

