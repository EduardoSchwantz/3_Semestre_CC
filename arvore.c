#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct no{
    int valor;
    struct no *direito, *esquerdo;
    int altura;
}No;

No* novoNo (int x);
int maior  (int a, int b);
int alturaDoNo (No *no);
int fatorDeBalanceamento(No *no);
No* rotacaoEsquerda(No *rigth);

int main(){
     SetConsoleOutputCP(650001);

    No *raiz = NULL;



return 0;
}

/*      Função que cria novo nó
        que retornará o endereço do nó criado.
*/
No* novoNo(int x){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = x;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        novo->altura = 0;
    }
    else
    printf("\nERRO ao alocar novo nó\n");
    return novo;
}

/*  função para retornar o maior
    entre dois valores.
*/
int maior (int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

/* retorna a altura de um no
    caso seja diferente de
    nula retorna -1
*/
int alturaDoNo (No *no){
    if(no != NULL){
        return no->altura;
    }
    else
    return -1;
}
/*
balanceia a estrutura do nó
*/
int fatorDeBalanceamento(No *no){
    if(no){
        return(alturaDoNo(no->esquerdo) - alturaDoNo(no->direito));
    }
    else{
        return 0;
    }
}
No* rotacaoEsquerda(No *raiz){
    No *novaraiz, *filho;

    novaraiz = raiz->direito;
    filho = novaraiz->esquerdo;

    novaraiz->esquerdo = raiz;
    raiz->direito = filho;
    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito) + 1);
    novaraiz->altura = maior(alturaDoNo(novaraiz->esquerdo), alturaDoNo(novaraiz->direito) + 1);
    
    return novaraiz;
}