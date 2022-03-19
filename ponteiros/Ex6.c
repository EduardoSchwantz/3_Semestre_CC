/*6. Elaborar um programa que leia dois valores inteiros (A e B). Em seguida faça uma função
que retorne a soma do dobro dos dois numeros lidos. A função deverá armazenar o dobro
de A na propria variável A e o dobro de B na própria variável B*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
int* somaDobro (int *i, int *j);
int main(){
    SetConsoleOutputCP(65001);
    int var1, var2, *ptr1 = &var1, *ptr2 = &var2, *dobro;
    ptr1 = malloc(sizeof(int));
    ptr2 = malloc(sizeof(int));
    printf("\nDigite a primeira variável: ");
    scanf("%d", ptr1);
    printf("\nDigite a segunda variável: ");
    scanf("%d", ptr2);
    dobro = somaDobro(ptr1, ptr2);
    
    printf("\nDobro de A: %d\nDobro de B: %d\n A soma do dobro das duas variáveis é : %d", *ptr1, *ptr2, *dobro);

    free (ptr1);
    free (ptr2);
    free (dobro);
return 0;
} 
int* somaDobro (int *i, int *j){
    int *dobro;
    *i = (*i)*2;
    *j = (*j)*2;
    dobro = malloc(sizeof(int));
    *dobro = *i+*j;
    return dobro;
}