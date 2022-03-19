/*2. Escreva um programa que contenha duas variaveis inteiras. Compare seus endereços exiba o maior endereço*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int main(){
    SetConsoleOutputCP(65001);
    int var1=0, var2=0, *ptr1 = &var1, *ptr2 = &var2;
    printf("\nComparando o endereço de duas variáveis");
    printf("\nEndereço da variavel var1: %x \nEndereço da variavel var2: %x", ptr1, ptr2);
    if (ptr1 > ptr2)
    {
        printf("\nvar1 é maior que var2");
    }
    else printf("\nvar2 é maior que var1");
return 0;
}