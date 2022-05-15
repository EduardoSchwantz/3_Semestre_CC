/*9. Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas.
Imprima o endereço de cada posição dessa matriz.*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
    SetConsoleOutputCP(65001);
    int i, j;
    float **matriz;
    matriz = (float **)malloc(3 * sizeof(float *));

    for (i = 0; i < 3; i++)
    {
        matriz[i] = (float *)malloc(3 * sizeof(float));
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("\nLinha %d, Coluna %d: ", i + 1, j + 1);
            scanf("%f", *(matriz + i) + j);
        }
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%2x ", ((matriz + i) + j));
        }
        printf("\n");
    }
    free(matriz);
    for (i = 0; i < 3; i++)
    {
        free(matriz[i]);
    }

    return 0;
}