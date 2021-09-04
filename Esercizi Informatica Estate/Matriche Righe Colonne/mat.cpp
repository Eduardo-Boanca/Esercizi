/* 
    Eduardo Boanca 3^C Informatica

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COL 10
#define RIG 5

void creaMatrice(int mat[][COL])
{
    srand(time(0));

    for(int i = 0; i < RIG; i++)
        for(int j = 0; j < COL; j++)
            mat[i][j] = rand() % 100 + 1;
}

void maxRiga(int mat[][COL])
{
    int max = -1;

    for(int i = 0; i < RIG; i++)
    {
        for(int j = 0; j < COL; j++)
            if(mat[i][j] > max)
                max = mat[i][j];
        printf("numero minimo della riga %d e': %d\n", i, max);
        max = -1;
    }
}

int minMatrice(int mat[][COL])
{
    int min = mat[0][0];
    for(int i = 0; i < RIG; i++)
    {
        for(int j = 0; j < COL; j++)
            if(mat[i][j] < min)
                min = mat[i][j];
    }
    return min;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
