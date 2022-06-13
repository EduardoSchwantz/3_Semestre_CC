/*10. Crie um programa que contenha um array de inteiros contendo 5 elementos. Utilizando
apenas aritmetica de ponteiros, leia esse array do teclado e imprima o dobro de cada
valor lido.*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void dobro(int *j);
int main()
{
    SetConsoleOutputCP(650001);
    int i, vetor[5], *ptr = &vetor;
    ptr = malloc(sizeof(int));
    for (i = 0; i < 5; i++)
    {
        printf("\nDigite o %d numero do vetor de 5 posições: ", i + 1);
        scanf("%d", (ptr + i));
    }
    dobro(ptr);
    for (i = 0; i < 5; i++)
    {
        printf("\nO dobro da posição número %d tem valor de: %d", i + 1, *(ptr + i));
    }
    return 0;
}
void dobro(int *j)
{
    for (int i = 0; i < 5; i++)
    {
        *(j + i) = (*(j + i)) * 2;
    }
}