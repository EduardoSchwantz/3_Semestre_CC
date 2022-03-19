#include <stdio.h>
#include <stdlib.h>

void trocar(int* i, int* j);
int main(){

int var1, var2, *p, *i;

p = malloc(sizeof(int));
i = malloc(sizeof(int));

var1 = 1; 
var2 = 2; 

*p = var1;
*i = var2;

trocar(p, i);

printf("\n%d", *p);
printf("\n%d", *i);
return 0;
}

void trocar(int i, int* j){

int aux;
 
aux = *i;
*i = *j;
*j = aux;
}