/*1. Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de ´
cada variavel usando os ponteiros. Imprima os valores das variaveis antes e apos a modificão*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(65001);
    int x = 0;
    int *p = &x;
    float y = 0;
    float *l = &y;
    char z = 'B';
    char *m = &z;
    printf("O valor de x antes da modifição é : %d\n", x);
    printf("O valor de y antes da modifição é : %.2f\n", y);
    printf("O valor de z antes da modifição é : %c\n", z);
    *p = 70;
    *l = 63.70;
    *m = 'A';
    printf("O valor de x depois da modificao é : %d\n", x);
    printf("O valor de y depois da modificao é : %.2f\n", y);
    printf("O valor de z depois da modificao é : %c\n", z);

    return 0;
}