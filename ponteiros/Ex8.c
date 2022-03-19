/*8. Crie um programa que contenha um array de float contendo 10 elementos. Imprima o
endereço de cada posição desse array*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main(){
    SetConsoleOutputCP(65001);
    int i, variavel[10], *ptr1;
    ptr1 = variavel;
    ptr1 = (int*) malloc(10*sizeof(int));
    for (i = 0; i < 10; i++)
    {
        printf("\nDigite o %d numero do vetor de 10 posições: ", i+1);
        scanf("%d", (ptr1+i));
    }
    for (i = 0; i < 10; i++)
    {
        printf("\n%x", (ptr1+i));
    }
    


free (ptr1);
return 0;
}