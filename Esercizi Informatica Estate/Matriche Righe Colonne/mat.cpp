/* 
    Eduardo Boanca 3^C Informatica

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COL 5
#define RIG 5

/*----------------------------------------------------------------
Carica la matrice con numeri casuali
*    Parametri
*        int mat[][COL]: output: matrice caricata con numeri casuali
----------------------------------------------------------------*/
void creaMatrice(int mat[][COL])
{
    srand(time(0));

    for(int i = 0; i < RIG; i++)
        for(int j = 0; j < COL; j++)
            mat[i][j] = rand() % 100 + 1;
}

/*--------------------------------------------------------
Stampa il valore massimo per ogni riga
*    Parametri
*        int mat[][COL]: input: matrice che da i valori di ogni riga
--------------------------------------------------------*/

void maxRiga(int mat[][COL])
{
    int max = -1;

    for(int i = 0; i < RIG; i++)
    {
        for(int j = 0; j < COL; j++)
            if(mat[i][j] > max)
                max = mat[i][j];
        printf("numero massimo della riga n.%d e': %d\n", i, max);
        max = -1;
    }
}

/*----------------------------------------------------------------
Stampa il valore minimo di tutta la matrice
*    Parametri
*        int mat[][COL]: input matrice da cui prende il valore piu basso
----------------------------------------------------------------*/
void minMatrice(int mat[][COL])
{
    int min = mat[0][0];
    for(int i = 0; i < RIG; i++)
    {
        for(int j = 0; j < COL; j++)
            if(mat[i][j] < min)
                min = mat[i][j];
        printf("\nIl numero minimo della matrice e': %d\n", min);
    }

}

/*----------------------------------------------------------------
Esegue e stampa la media dei numeri in colonna di ogni colonna
*    Parametri
*          int mat[][COL]: input: matrice dove esegue il calcolo della media
----------------------------------------------------------------*/
void mediaCol(int mat[][COL])
{
    float somma = 0;
    float media = 0;
    
    for(int j = 0; j < COL; j++)
    {
        for(int i = 0; i < RIG; i++)
            somma += mat[i][j];
        somma = somma/RIG;
        printf("la media della colonna %d e': %.2f\n",j, somma);
        somma = 0;
    }
}

/*----------------------------------------------------------------
Stampa la matrice con i numeri casuali
*    Parametri
*        int mat[][COL]: output: matrice da stampare
----------------------------------------------------------------*/
void stampaMatrice(int mat[][COL])
{
    for(int i = 0; i < RIG; i++)
    {
        printf("\n");
        for(int j = 0; j < COL; j++)
            printf(" %3d ", mat[i][j]);
    }
    printf("\n\n");
}

/*=======MAIN=======*/
int main(int argc, char const *argv[])
{
    int mat[RIG][COL];

    creaMatrice(mat);
    stampaMatrice(mat);
    maxRiga(mat);
    minMatrice(mat);
    printf("\n");
    mediaCol(mat);

    return 0;
}
