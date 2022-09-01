#include<stdio.h>
#include<stdlib.h>

/*
inserir opção: consultar produtos já existentes (tela principal)
*/

// Assinatura das funções:
char telaCadastroItens(void);
char telaCadastrarAlimento(void);
char telaCadastrarHigiene(void);
char telaCadastrarLimpeza(void);
void moduloCadastro(void);

// Funções do módulo do cadastro de itens:

void moduloCadastro(void) {
    char opcao;
    do {
        opcao = telaCadastro();
        switch(opcao) {
            case '1':
                telaCadastrarAlimento();
                break;
            case '2':
                telaCadastrarHigiene();
                break;
            case '3': 
                telaCadastrarLimpeza();
                break;
            default:
                printf('Opcao invalida!\n');
                break;
        }       
    } while (opcao != '0');

}


char telaCadastroItens(void)
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------- SIG-Pantry - CADASTRAR ITENS ------------- | \n");
    printf(" |                                                           | \n");
    printf(" | ------------- 1- Cadastrar item alimentar --------------- | \n");
    printf(" | ------------- 2- Cadastrar item de higiene pessoal ------ | \n"); 
    printf(" | ------------- 3- Cadastrar item de limpeza -------------- | \n");    
    printf(" | ------------- 0- Voltar a tela principal ---------------- | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao:                                        | \n");
    printf(" | ========================================================= | \n");
    scanf("%c", &opcao);

    return opcao;

}

char telaCadastrarAlimento(void)
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ----------------- CADASTRAR ITEM ALIMENTAR -------------- | \n");
    printf(" |                                                           | \n");
    printf(" | ----------------- 1- Nome do Item ----------------------- | \n");
    printf(" | ----------------- 2- Data de validade ------------------- | \n"); 
    printf(" | ----------------- 3- Local de armazenamento ------------- | \n");    
    printf(" | ----------------- 0- Voltar a tela principal ------------ | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao:                                        | \n");
    printf(" | ========================================================= | \n");
    scanf("%c", &opcao);  
    
    return opcao;

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
    char opcao;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ---------- CADASTRAR ITEM DE HIGIENE PESSOAL ------------ | \n");
    printf(" |                                                           | \n");
    printf(" | --------------- 1- Nome do Item ------------------------- | \n");
    printf(" | --------------- 2- Data de validade --------------------- | \n"); 
    printf(" | --------------- 3- Local de armazenamento --------------- | \n");    
    printf(" | --------------- 0- Voltar a tela principal -------------- | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao:                                        | \n");
    printf(" | ========================================================= | \n");
    scanf("%c", &opcao);  
    
    return opcao;

}

char telaCadastrarLimpeza(void)
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ---------------- CADASTRAR ITEM DE LIMPEZA -------------- | \n");
    printf(" |                                                           | \n");
    printf(" | ----------------- 1- Nome do Item ----------------------- | \n");
    printf(" | ----------------- 2- Data de validade ------------------- | \n"); 
    printf(" | ----------------- 3- Local de armazenamento ------------- | \n");    
    printf(" | ----------------- 0- Voltar a tela principal ------------ | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao:                                        | \n");
    printf(" | ========================================================= | \n");
    scanf("%c", &opcao);  
    
    return opcao;
    
}
