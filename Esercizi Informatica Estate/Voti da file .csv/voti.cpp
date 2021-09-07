/* 
    Eduardo Boanca 3^C Informatica
    Realizzare un programma che
        - prenda in input da un file .csv i nomi e i voti di una serie di studenti in un compito in classe.
        - Un voto con valore 0 indica che lo studente è assente al momento della prova.
        - Stampi la media dei voti non considerando le assenze
        - Stampi il nome dello studente che ha riportato il voto massimo
        - Stampi l’elenco degli studenti insufficienti (esclusi gli assenti)
        - Stampi la percentuale di studenti assenti
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN_NOME 50
#define NUM_STUDENTI 40
#define ERRORE -1
#define OK 1

typedef struct 
{
    char nome[LEN_NOME];
    float voto;
} studente;

int caricaVoti(studente voti[])
{
    FILE * f;
    char file[30];
    int i;

    printf("Nome del file da caricare: ");
    scanf("%s", file);
    f = fopen(file,"r");

    if(f == NULL)
        return ERRORE;
    
    for(i = 0; !feof(f); i++)
        fscanf(f,"\n%[^,], %f", voti[i].nome, &voti[i].voto);

    return i-1;
}

float mediaVoti(studente voti[], int len)
{
    float somma = 0;
    for(int i = 0; i < len; i++)
        if(voti[i].voto != 0)
            somma += voti[i].voto;

    return (float) somma/len;
}

studente votoAlto(studente voti[], int len)
{
    studente maggiore;
    maggiore.voto = 0;
    for(int i = 0; i < len; i++)
        if(voti[i].voto > maggiore.voto)
            maggiore = voti[i];

    return maggiore;
}

void votiInsuff(studente voti[], int len)
{
    for(int i = 0; i < len; i++)
        if(voti[i].voto < 6 && voti[i].voto != 0)
            printf("Lo studente %s ha ricevuto un voto insufficiente che equivale a: %0.2f\n", voti[i].nome,voti[i].voto);
}

float percentualeAssenti(studente voti[], int len)
{
    int numAssenti = 0;
    for(int i = 0; i < len; i++)
        if(voti[i].voto == 0)
            numAssenti++;
    
    return (float) (numAssenti*100)/len;
}

void stampaVoti(studente voti[], int len)
{
    for (int i = 0; i < len; i++)
        printf("Alunno: %s: Voto: %0.2f\n", voti[i].nome,voti[i].voto);
}

int main(int argc, char const *argv[])
{
    studente voti[NUM_STUDENTI];
    int numStudent = caricaVoti(voti), scelta;
    studente votoPiuAlto;

    if(numStudent == ERRORE)
        return EXIT_FAILURE;
    
    printf("La media dei voti e': %.3f", mediaVoti(voti, numStudent));
    printf("\n");
    
    votoPiuAlto = votoAlto(voti, numStudent);
    printf("L'alunno con il voto piu alto e': %s con il voto di %.2f", votoPiuAlto.nome, votoPiuAlto.voto);
    printf("\n");

    votiInsuff(voti, numStudent);
    printf("\n");

    printf("La percentuale di studenti assenti e': %.2f%%", percentualeAssenti(voti, numStudent));
    printf("\n");

    stampaVoti(voti, numStudent);

        return EXIT_SUCCESS;
}
