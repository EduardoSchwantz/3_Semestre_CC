#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


char* adicionar(char* str);
char* remover(char* str);

int main(){
     SetConsoleOutputCP(650001);


        int repetir, opcao, sair=1;
        char *pbuffer = calloc(1,sizeof(char));

       
while (sair){
            printf("\n-------------Selecione uma opcao-----------------\n");
            printf(" 1 - Adicionar nome\n");
            printf(" 2 - Remover nome\n");
            printf(" 3 - Listar\n");
            printf(" 4 - Sair\n");
            printf("Digite uma opcao:\n");
            scanf("%d", &opcao);
            getchar();
            
            
    switch (opcao)
    {
    case 1:
            system("cls");
            repetir = 1;
            while (repetir)
            {   
                pbuffer = adicionar(pbuffer);                
                printf("\nDigite 1 para adicionar outro nome, e 0 para voltar ao MENU: ");
                scanf("%d", &repetir);
                getchar();
                                           
            }
                                            
        break;

    case 2:    
                repetir = 1;
            while (repetir){
                remover(pbuffer);
                printf("\nRemovido, verifique na opcao 3\n");
                printf("\nDigite 1 pra remover outro nome, e 0 para voltar ao MENU: ");
                scanf("%d", &repetir);
                getchar();              
                }
                
           
        break;

    case 3:     
                system("cls");
                printf("------------------Sua lista de Nomes-----------------\n%s\n", pbuffer);               
        break;
    case 4:
            
            printf("Saindo....");
            sair = 0;
        break;
    }
    
}
free(pbuffer);
return 0;

}
char* adicionar(char* str){
    int buffer_size, str_size;
    char divisaoNome[] = "\n", dados[200], idade[50], telefone[50];
    char separar_nome_idade[] = " -> Idade: ", complementar_idade[] = " Anos";
    char separar_idade_telefone[] = " -> Telefone: "; 
    printf("\nInsira o nome: ");
    gets(dados);
    strcat(dados, separar_nome_idade);    
    printf("\nInsira a idade do aluno: ");
    gets(idade);
    strcat(dados, idade);
    strcat(dados, complementar_idade);
    strcat(dados, separar_idade_telefone);   
    printf("\nInsira o telefone do aluno: ");
    gets(telefone);
    strcat(dados, telefone);
    strcat(dados, divisaoNome);
    strcat(dados, divisaoNome);    
    buffer_size = strlen(dados);
    str_size = strlen(str);
    str = (char*)realloc(str, (buffer_size+str_size)*sizeof(char)+sizeof(char)); 
    strcat(str, dados);
    return str;
}

char* remover(char* str){
    int tamanho, i, repetir;
    char removenome[200], *start, *end, *test, *testeaxuliar;
 
    printf("Insira o nome a ser removido da lista: ");
    gets(removenome);
    testeaxuliar = strstr(str, removenome);
    test = strtok(testeaxuliar, "\n");
            repetir = 1;
            while (repetir)
            {   
    if(test !=  NULL){ 
        tamanho = strlen(test);
        start = strstr(str, test);            //achado o ponteiro pro começo da palavra a ser retirada, ou Null caso ela n exista
        end = start;                            //guarda o local do começo da palavra a ser retirada
            for(i=0; i<tamanho; i++)            //end agora aponta pra primeira letra da proxima palavra
            end++;  
        memmove(start, end, strlen(end)+1);     //sobrescreve a palavra com o restante da string. o +1 é para trazer o caractere nulo também. 
        tamanho = strlen(str);
        str = (char*)realloc(str, tamanho*sizeof(char)+sizeof(char)); //diminue a quantidade de memória alocada, o +1 é para contar o caractere nulo. 
        return str;
    }
            else{
            printf("Nome não encontrado digite novamente.\n");
            printf("\nDigite 1 para tentar outro nome ou 0 para voltar ao MENU: ");
            scanf("%d", &repetir); 
            getchar();
            }
        }
}