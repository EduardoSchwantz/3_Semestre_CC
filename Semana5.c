#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


int main(){
    int *opcao = (int*) malloc(sizeof(int)), *sair = (int*) malloc(sizeof(int));
    SetConsoleOutputCP(65001);
     
 do
 {
     
  
            
            printf("\n             Selecione uma opção:             \n");
            printf(" 1 - Adicionar Nome\n");
            printf(" 2 - Remover Nome\n");
            printf(" 3 - Listar\n");
            printf(" 4 - Busque um nome na lista\n");            
            printf(" 5 - Sair\n");
            printf("Digite uma opção:\n");
            scanf("%d", &((int*)opcao)[1]);
            getchar();
            system("clear||cls");
            
    switch (((int*)opcao)[1])
   {
    case 1:                                      
                                                                             
        break;
    case 2:   
                printf("\n             Sua lista de Nomes             \n");          
                
        break;
    case 3:     
                printf("             Sua lista de Nomes             \n");               
        break;  
    case 4:
        
        break; 
    case 5:          
            printf("\n             Encerrando Programa!!             \n");
            *(int*) sair = 0; 
        break;
    default:
            printf("\n             Opção Invalida!!                         \n");
            printf("\n             Digite Uma Opção valida.             \n");
   }       
} while (*(int*)sair);

free(opcao);
free(sair);
return 0;
}
