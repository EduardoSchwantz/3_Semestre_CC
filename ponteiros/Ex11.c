/*11. Crie um programa que contenha um array contendo 5 elementos inteiros. Leia esse array
do teclado e imprima o endereço das posições contendo valores pares.*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main (){
    SetConsoleOutputCP(650001);
    int array[5], *ptr = &array;
        printf("\nDigite o valor do vetor de 5 pocições");
        for (int i = 0; i < 5; i++)
        {
            printf("\nDigite o %dª valor: ", i+1);
            scanf("%d", (ptr+i));
        }
            printf("\nImprimindo o endereço de memória do valores pares...");
         for (int i = 0; i < 5; i++)
        {
           
            if ((*(ptr+i))%2 == 0)
            {
                
                printf("\n%dª Endereço = %x", i+1, (ptr+i));
            }
        }



return 0;
}


