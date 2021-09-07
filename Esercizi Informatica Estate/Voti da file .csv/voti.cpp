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

typedef struct 
{
    char nome[LEN_NOME];
    float voto;
} studente;

/*----------------------------------------------------------------
Legge da un file csv i nomi e i voti e li inserisce in un array
*   Parametri:
*        studente voti[]: output: dove verrano inseriti i dati letti
*        return i: return del numeri di dati letti
----------------------------------------------------------------*/
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
        fscanf(f,"\n%[^,], %f", voti[i].nome, &voti[i].voto); //%[^,] prende il contenuto fino alla virgola

    return i;
}

/*----------------------------------------------------------------
Esegue la media di tutti i voti nel file
*    Parametri:
*         studente voti[]: input: dati dell'alunno
*         int len: input: fino a dove vengono considerati i dati
*         return media: return del valore della media di tutti i voti
----------------------------------------------------------------*/
float mediaVoti(studente voti[], int len)
{
    float somma = 0;
    float media = 0;
    for(int i = 0; i < len; i++)
        if(voti[i].voto != 0)
            somma += voti[i].voto;

    media = somma/len;
    return media;
}

/*----------------------------------------------------------------
Controlla quale alunno ha il voto piu alto
*    Parametri:
*         studente voti[]: dati alunni
*        int len: fino a dove vengono considerati i dati
*         return maggiore: return del voto piu alto
----------------------------------------------------------------*/
studente votoAlto(studente voti[], int len)
{
    studente maggiore;
    maggiore.voto = 0;
    for(int i = 0; i < len; i++)
        if(voti[i].voto > maggiore.voto)
            maggiore = voti[i];

    return maggiore;
}

/*----------------------------------------------------------------
Trova tutti gli alunni con un voto insufficiente
*   Parametri:
*      studente voti[]: input: dati alunni
*        int len: fino a dove vengono considerati i dati
----------------------------------------------------------------*/
void votiInsuff(studente voti[], int len)
{
    for(int i = 0; i < len; i++)
        if(voti[i].voto < 6 && voti[i].voto != 0)
            printf("Lo studente %s ha ricevuto un voto insufficiente che equivale a: %0.2f\n", voti[i].nome,voti[i].voto);
}

/*----------------------------------------------------------------
Calcola la percentuale degli assenti tra tutti gli alunni
*    Parametri:
*     studente voti[]: input: dati alunni
*        int len: fino a dove vengono considerati i dati
*         return percentAssenti: return della perecentuale assenti
----------------------------------------------------------------*/
float percentualeAssenti(studente voti[], int len)
{
    int numAssenti = 0;
    float percentAssenti = 0;
    for(int i = 0; i < len; i++)
        if(voti[i].voto == 0)
            numAssenti++;
    percentAssenti = (numAssenti * 100)/len;
    
    return percentAssenti;
}

/*----------------------------------------------------------------
Stampa i nomi degli alunni con i loro rispettivi voti
*    Parametri:
*     studente voti[]: input: dati alunni
*        int len: fino a dove vengono considerati i dati
----------------------------------------------------------------*/
void stampaVoti(studente voti[], int len)
{
    for (int i = 0; i < len; i++)
        printf("Alunno: %s:  |  Voto: %0.2f\n", voti[i].nome,voti[i].voto);
}

/*======MAIN======*/
int main(int argc, char const *argv[])
{
    studente voti[NUM_STUDENTI];
    int numStudent = caricaVoti(voti), scelta;
    studente votoPiuAlto;

    if(numStudent == ERRORE)
        return EXIT_FAILURE;

    stampaVoti(voti, numStudent);
    
    printf("\nLa media dei voti e': %.3f\n", mediaVoti(voti, numStudent));
    printf("\n");
    
    votoPiuAlto = votoAlto(voti, numStudent);
    printf("L'alunno/a con il voto piu alto e': %s con il voto di %.2f\n", votoPiuAlto.nome, votoPiuAlto.voto);

    votiInsuff(voti, numStudent);
    printf("\n");

    printf("La percentuale di studenti assenti e': %.2f%%\n", percentualeAssenti(voti, numStudent));

        return EXIT_SUCCESS;
}
