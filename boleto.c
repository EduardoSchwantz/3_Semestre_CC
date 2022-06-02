#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
void criar_arquivo(FILE *file);
void imprimir_arquivo(FILE *file);
void adicionar_arquivo(FILE *file);
int main()
{
    SetConsoleOutputCP(65001);
    int sair, opcao;
    FILE *file;
    do
    {
        printf("\n\n\n             Selecione uma opção:             \n");
        printf(" 1 - Criar Arquivo.\n");
        printf(" 2 - Adicionar boleto.\n");
        printf(" 3 - Mostrar boletos.\n");
        printf(" 0 - Sair\n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            file = fopen("boletos.txt", "r");
            criar_arquivo(file);

            break;

        case 2:
            file = fopen("boletos.txt", "a");
            adicionar_arquivo(file);
            break;

        case 3:
            file = fopen("boletos.txt", "r");
            imprimir_arquivo(file);

            break;

        case 0:
            fclose(file);
            sair = 0;
            break;
        default:
            printf("\n             Digite uma opção válida:             \n");
        }

    } while (sair);

    return 0;
}
void criar_arquivo(FILE *file)
{
    if (file == NULL)
    {
        printf("\nArquivo Criado.\n");
        file = fopen("boletos.txt", "w");
        fprintf(file, "             BOLETOS             \n");
        fclose(file);

    }
    else
    {
        printf("\nArquivo já existe.\n");
    }
}

void imprimir_arquivo(FILE *file)
{
    if (file == NULL)
    {
        printf("\nArquivo não existe, Crie o arquivo\n");
    }
    else
    {
        char frase[1000];
        while (fgets(frase, 1000, file) != NULL)
        {
            printf("\n");
            printf("%s", frase);
        }
    }
    fclose(file);
}
void adicionar_arquivo(FILE *file)
{
    char aux_file[200], empresa[20], data_venc[20], valor[20];
    strcat(aux_file, "\nEmpresa: ");
    printf("\nDigite o nome da empresa: ");
    fgets(empresa, 20, stdin);
    strcat(aux_file, empresa);
    strcat(aux_file, " Data: ");
    printf("\nDigite a data de vencimento do boleto Ex.: 26/06/2022 : ");
    fgets(data_venc, 20, stdin);
    strcat(aux_file, data_venc);
    strcat(aux_file, " Valor: R$");
    printf("\nDigite o valor do boleto Ex.: 678,89  : ");
    fgets(valor, 20, stdin);
    strcat(aux_file, valor);
    fputs(aux_file, file);
    fclose(file);
}