/*5. Faça um programa que leia dois valores inteiros e chame uma função que receba estes
2 valores de entrada e retorne o maior valor na primeira variavel e o menor valor na
segunda variavel. Escreva o conteúdo das 2 variáveis na tela. */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void troca (int *i, int *j);
int main(){
    SetConsoleOutputCP(65001);
    int var1, var2, *ptr1 = &var1, *ptr2 = &var2;
    ptr1 = malloc(sizeof(int));
    ptr2 = malloc(sizeof(int));
    printf("\nDigite a primeira variável: ");
    scanf("%d", ptr1);
    printf("\nDigite a segunda variável: ");
    scanf("%d", ptr2);
    printf("\nValor de var 1: %d , valor de var2 :%d", *ptr1, *ptr2);
    troca(ptr1, ptr2);
    printf("\nValor de var 1 :%d , valor de var2 :%d", *ptr1, *ptr2);

    free (ptr1);
    free (ptr2);
return 0;
} 
void troca (int *i, int *j){
    int aux;
    if (*i < *j)
    {   
        aux = *i;
        *i = *j;
        *j = aux;
    }   
}