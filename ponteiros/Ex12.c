/*12. Faça um programa que leia três valores inteiros e chame uma função que receba estes 3
valores de entrada e retorne eles ordenados, ou seja, o menor valor na primeira variável,
o segundo menor valor na variável do meio, e o maior valor na última variável. A função
deve retornar o valor 1 se os três valores forem iguais e 0 se existirem valores diferentes.
Exibir os valores ordenados na tela.*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int * ordenar (int *a, int *b, int *c);
int main (){
    SetConsoleOutputCP(650001);
    int var1, var2, var3, *ptr1 = &var1, *ptr2 = &var2, *ptr3 = &var3, *retorno;
    ptr1 = malloc(sizeof(int));
    ptr2 = malloc(sizeof(int));
    ptr3 = malloc(sizeof(int));
    printf("\nDIgite o valor das três variáveis...\n");
    scanf("%d", ptr1);
    scanf("%d", ptr2);
    scanf("%d", ptr3);
    if (*ptr1 == *ptr2 && *ptr2 == *ptr3 && *ptr3 == *ptr1)
    {
        retorno = ordenar(ptr1, ptr2, ptr3);
        printf("%d", *retorno);
    }
    
    

    free (ptr1);
    free (ptr2);
    free (ptr3);
    free (retorno);
return 0;
}
int* ordenar (int *a, int *b, int *c){
    int *retorno;

    if (*a > *b && *b > *c)
    {
        /* code */
    }
    





    if (*a == *b && *b == *c && *c == *a)
    {   
        retorno = malloc(sizeof(int));
        *retorno = 1;
        
        return retorno;
    }
    

}