#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <time.h>
void preenche_vetor(int *vetor, int tam);
void imprimir(int *vetor, int tam);
void selection_sort(int *vetor, int tam);
void insertion_sort(int *vetor, int tam);
void quick_sort(int *vetor, int pos_esq, int pos_dir);
void merge_sort(int *vetor, int inicio, int fim);
int particiona_quick_sort(int *vetor, int inicio, int fim);
void particiona_merge_sort(int *vetor, int inicio, int meio, int fim);

int main()
{
    SetConsoleOutputCP(65001);
    int tam, opcao, sair, *vetor;
    srand(time(NULL));

    do
    {
        printf("\n\n\n             Selecione uma opção:             \n");
        printf(" 1 - Criar vetor e preencher aleatóriamente o vetor.\n");
        printf(" 2 - Ordenação SELECTION SORT. \n");
        printf(" 3 - Ordenação INSERTION SORT.\n");
        printf(" 4 - Ordenação QUICK SORT.\n");
        printf(" 5 - Ordenação MERGE SORT.\n");
        printf(" 6 - Imprimir vetor.\n");
        printf(" 7 - Limpar vetor.\n");
        printf(" 0 - Sair.\n");
        printf("\n             Digite uma opção:             \n");
        scanf("%d", &opcao);
        getchar();
        system("clear||cls");
        switch (opcao)
        {
        case 1:
            printf("\nDigite o tamanho do vetor: ");
            scanf("%d", &tam);
            vetor = (int *)malloc(tam * sizeof(int));
            preenche_vetor(vetor, tam);
            break;

        case 2:
            selection_sort(vetor, tam - 1);
            printf("\nVetor ordenado utilizando SELECTION SORT\n");
            imprimir(vetor, tam);
            break;

        case 3:
            insertion_sort(vetor, tam - 1);
            printf("\nVetor ordenado utilizando INSERTION SORT\n");
            imprimir(vetor, tam);
            break;
        case 4:
            quick_sort(vetor, 0, tam - 1);
            printf("\nVetor ordenado utilizando QUICK SORT\n");
            imprimir(vetor, tam);
            break;

        case 5:
            merge_sort(vetor, 0, tam - 1);
            printf("\nVetor ordenado utilizando MERGE SORT\n");
            imprimir(vetor, tam);
            break;
        case 6:
            imprimir(vetor, tam);
            break;

        case 7:
            free(vetor);
            tam = 0;
            break;

        case 0:
            sair = 0;
            break;

        default:
            printf("\n             Digite uma válida:             \n");
        }

    } while (sair);

    free(vetor);
    return 0;
}
void preenche_vetor(int *vetor, int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        vetor[i] = rand() % 999;
    }
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
    for (i = 0; i < tam; i++)
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
    for (i = 0; i < tam; i++)
    {
        aux = vetor[i];
        for (j = i; (j > 0) && (aux < vetor[j - 1]); j--)
        {
            vetor[j] = vetor[j - 1];
            vetor[j - 1] = aux;
        }
    }
}

void quick_sort(int *vetor, int inicio, int fim)
{
    int pivo;
    if (fim > inicio)
    {
        pivo = particiona_quick_sort(vetor, inicio, fim);
        quick_sort(vetor, inicio, pivo - 1);
        quick_sort(vetor, pivo + 1, fim);
    }
}

int particiona_quick_sort(int *vetor, int inicio, int fim)
{
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = fim;
    pivo = vetor[inicio];

    while (esq < dir)
    {
        while (vetor[esq] <= pivo)
            esq++;
        while (vetor[dir] > pivo)
            dir--;

        if (esq < dir)
        {
            aux = vetor[esq];
            vetor[esq] = vetor[dir];
            vetor[dir] = aux;
        }
    }
    vetor[inicio] = vetor[dir];
    vetor[dir] = pivo;
    return dir;
}

void merge_sort(int *vetor, int inicio, int fim)
{
    int meio;
    if (inicio < fim)
    {
        meio = floor(inicio + fim) / 2;
        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio + 1, fim);
        particiona_merge_sort(vetor, inicio, meio, fim);
    }
}

void particiona_merge_sort(int *vetor, int inicio, int meio, int fim)
{
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int *)malloc(tamanho * sizeof(int));

    if (temp != NULL)
    {
        for (i = 0; i < tamanho; i++)
        {
            if (!fim1 && !fim2)
            {
                if (vetor[p1] < vetor[p2])
                    temp[i] = vetor[p1++];
                else
                    temp[i] = vetor[p2++];

                if (p1 > meio)
                    fim1 = 1;
                if (p2 > fim)
                    fim2 = 1;
            }
            else
            {
                if (!fim1)
                    temp[i] = vetor[p1++];
                else
                    temp[i] = vetor[p2++];
            }
        }
        for (j = 0, k = inicio; j < tamanho; j++, k++)
            vetor[k] = temp[j];
    }
    free(temp);
}