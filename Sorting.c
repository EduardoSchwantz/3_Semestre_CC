#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
void imprimir(int *vetor, int tam);
void selection_sort(int *vetor, int tam);
void insertion_sort(int *vetor, int tam);
int main()
{
    SetConsoleOutputCP(65001);
    int tam = 0, opcao, sair, i, valor, *vetor;

    srand(time(NULL));

    do
    {
        printf("\n\n\n             Selecione uma opção:             \n");
        printf(" 1 - Criar vetor aleatório.\n");
        printf(" 2 - Ordenação SELECTION SORT. \n");
        printf(" 3 - Ordenação INSERTION SORT.\n");
        printf(" 4 - \n");
        printf(" 5 - Imprimir vetor.\n");
        printf(" 6 - Limpar vetor.\n");
        printf(" 7 - Sair.\n");
        printf("\n             Digite uma opção:             \n");
        scanf("%d", &opcao);
        getchar();
        system("clear||cls");

        switch (opcao)
        {
        case 1:
            printf("\nDigite o tamanho do vetor: ");
            scanf("%d", &tam);
            vetor = malloc(tam * sizeof(int));
            for (i = 0; i < tam; i++)
            {
                valor = 0;
                valor = rand() % 999;
                vetor[i] = valor;
            }
            break;

        case 2:
            selection_sort(vetor, tam);
            printf("\nVetor ordenado utilizando SELECTION SORT\n");
            imprimir(vetor, tam);
            break;

        case 3:
            insertion_sort(vetor, tam);
            printf("\nVetor ordenado utilizando INSERTION SORT\n");
            imprimir(vetor, tam);
            break;

        case 5:
            imprimir(vetor, tam);
            break;

        case 6:
            free(vetor);
            break;

        case 7:
            sair = 0;
            break;

        default:
            printf("\n             Digite uma válida:             \n");
        }

    } while (sair);

    free(vetor);
    return 0;
}
void imprimir(int *vetor, int tam)
{
    printf("\n             Imprimindo Vetor:             \n");
    for (int i = 0; i < tam; i++)
    {

        printf("%d, ", vetor[i]);
    }
}

void selection_sort(int *vetor, int tam)
{
    int i, j, menor, troca;
    for (i = 0; i < tam - 1; i++)
    {
        menor = i;
        for (j = i + 1; j < tam; j++)
        {
            if (vetor[j] < vetor[menor])
                menor = j;
        }
        if (i != menor)
        {
            troca = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = troca;
        }
    }
}
void insertion_sort(int *vetor, int tam)
{
    int i, j, aux;
    for (i = 1; i < tam; i++)
    {
        aux = vetor[i];
        for (j = i; (j > 0) && (aux < vetor[j - 1]); j--)
        {
            vetor[j] = vetor[j - 1];
            vetor[j - 1] = aux;
        }
    }
}