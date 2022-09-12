#include<stdio.h>
#include<stdlib.h>
#include "modulocadastroItem.h"

// Assinatura das funções:
char telaCadastroItens(void);
char telaCadastrarAlimento(void);
char telaCadastrarHigiene(void);
char telaCadastrarLimpeza(void);
char telaLocaldeArmazenamento(void);
void modulocadastroItem(void);

// Funções do módulo do cadastro de itens:

void modulocadastroItem(void) {
    char escolha;
    do {
        escolha = telaCadastroItens();
        switch(escolha) {
            case '1':
                telaCadastrarAlimento();
                break;
            case '2':
                telaCadastrarHigiene();
                break;
            case '3': 
                telaCadastrarLimpeza();
                break;
            case '4': 
                telaLocaldeArmazenamento();
                break;
        } 
              
    } while (escolha != '0');

}


char telaCadastroItens(void)
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------- SIG-Pantry - CADASTRAR ITENS ------------- | \n");
    printf(" |                                                           | \n");
    printf(" |               1- Cadastrar item alimentar                 | \n");
    printf(" |               2- Cadastrar item de higiene pessoal        | \n"); 
    printf(" |               3- Cadastrar item de limpeza                | \n"); 
    printf(" |               4- Local de armazenamento                   | \n");      
    printf(" |               0- Voltar a tela principal                  | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao: \n");
    scanf("%c", &opcao);
    getchar();

    return opcao;

}

char telaCadastrarAlimento(void)
{
    //char opcao;
    char nomeItem [20];
    char dataValidade [10];
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ----------------- CADASTRAR ITEM ALIMENTAR -------------- | \n");
    printf(" |                                                           | \n");    
    printf(" |  1- Informe o nome do item: \n");
    scanf("%[A-Z a-z]", nomeItem);
    printf(" |  2- Informe a data de validade: \n");
    scanf("%[0-9., -., /., .]", &dataValidade);
    printf(" |  3- Editar cadastro \n");    
    printf(" |  4- Excluir item  \n");        
    printf(" |  0- Voltar a tela de cadastro \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    //printf(" | Escolha uma opcao: \n");
    //scanf("%c", &opcao);  
    printf(" Press ENTER to exit...");

    return '0';

}

/*void telaCadastrarAlimento(void) 
{
    char opcao;
    if(opcao == 1){
        printf('Nome do item:\n');
    } if(opcao == 2) {
        printf('Data de validade:\n');
    } if(opcao == 3) {
        //printf('Local de armazenamento:\n'); pensar em puxar as opções: geladeira, armário...
    } else {
        printf('Voltar a tela de Cadastro de Itens');
    }

}*/

char telaCadastrarHigiene(void)
{
    //char opcao;
    char nomeItem [20];
    char dataValidade [10];
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ----------- CADASTRAR ITEM DE HIGIENE PESSOAL ----------- | \n");
    printf(" |                                                           | \n");
    printf(" |  1- Informe o nome do item: \n");
    scanf("%[A-Z a-z]", nomeItem);
    printf(" |  2- Informe a data de validade: \n");
    scanf("%[0-9., -., /., .]", &dataValidade);
    printf(" |  3- Editar cadastro \n");    
    printf(" |  4- Excluir item  \n");        
    printf(" |  0- Voltar a tela de cadastro \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    //printf(" | Escolha uma opcao: \n");
    //scanf("%c", &opcao);  
    
    return '0';

}

char telaCadastrarLimpeza(void)
{
    //char opcao;
    char nomeItem[20];
    char dataValidade[10];
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ---------------- CADASTRAR ITEM DE LIMPEZA -------------- | \n");
    printf(" |                                                           | \n");
    printf(" |  1- Informe o nome do item: \n");
    scanf("%[A-Z a-z]", nomeItem);
    printf(" |  2- Informe a data de validade: \n");
    scanf("%[0-9., -., /., .]", &dataValidade);
    printf(" |  3- Editar cadastro \n");    
    printf(" |  4- Excluir item  \n");        
    printf(" |  0- Voltar a tela de cadastro \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    //printf(" | Escolha uma opcao: \n");
    //scanf("%c", &opcao);  
    
    return '0';
    
}

char telaLocaldeArmazenamento(void) 
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ----------------- LOCAL DE ARMAZENAMENTO ---------------- | \n");
    printf(" |                                                           | \n");
    printf(" |                 1- Geladeira                              | \n");
    printf(" |                 2- Armario da cozinha                     | \n");
    printf(" |                 3- Armario da area de servico             | \n");  
    printf(" |                 4- Armario do banheiro                    | \n"); 
    printf(" |                 5- Guarda-roupa                           | \n");       
    printf(" |                 0- Voltar a tela de cadastro              | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao: \n");
    scanf("%c", &opcao);  
    
    return opcao;

}
