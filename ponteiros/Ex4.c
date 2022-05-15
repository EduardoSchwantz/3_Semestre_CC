/*4. Faça um programa que leia 2 valores inteiros e chame uma função que receba estas
2 variaveis e troque o seu conteudo, ou seja, esta funcao e chamada passando duas
variaveis A e B por exemplo e, após a execucao da função, A conterá o valor de B e B
tera o valor de A*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void trocavalor(int *i, int *j);
int main()
{
    SetConsoleOutputCP(65001);
    int var1 = 0, var2 = 0, *ptr1, *ptr2;
    ptr1 = malloc(sizeof(int));
    ptr2 = malloc(sizeof(int));
    ptr1 = &var1;
    ptr2 = &var2;

    printf("\nDigite o valor da primeira variável: ");
    scanf("%d", ptr1);
    printf("\nDigite o valor da segunda variável:  ");
    scanf("%d", ptr2);

    printf("\nValor de var 1: %d , valor de var2 :%d", *ptr1, *ptr2);
    trocavalor(ptr1, ptr2);
    printf("\nTrocando...");
    printf("\nValor de var 1 :%d , valor de var2 :%d", *ptr1, *ptr2);
    free(ptr1);
    free(ptr2);

    return 0;
}
void trocavalor(int *i, int *j)
{
    int aux;
    aux = *i;
    *i = *j;
    *j = aux;
}