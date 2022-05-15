/*7. Crie um programa que contenha uma função que permita passar por parâmetro dois
números inteiros A e B. A função deverá calcular a soma entre estes dois números e
armazenar o resultado na variavel A. Esta função não deverá possuir retorno, mas deverá
modificar o valor do primeiro parametro. Imprima os valores de A e B na função principal.*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
void soma(int *i, int *j);
int main()
{
    SetConsoleOutputCP(65001);
    int var1, var2, *ptr1 = &var1, *ptr2 = &var2;
    ptr1 = malloc(sizeof(int));
    ptr2 = malloc(sizeof(int));
    printf("\nDigite a primeira variável: ");
    scanf("%d", ptr1);
    printf("\nDigite a segunda variável: ");
    scanf("%d", ptr2);
    soma(ptr1, ptr2);
    printf("\nValor de A modificado: %d, Valor de B: %d ", *ptr1, *ptr2);

    free(ptr1);
    free(ptr2);
    return 0;
}
void soma(int *i, int *j)
{
    *i = *i + *j;
}