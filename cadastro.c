
#include<stdio.h>
#include<stdlib.h>

/*
DENTRO DESSE CADASTRO: estará os dados do usuário do sistema de controle de despensa doméstica.
*/

char telaCadastro(void);
char telaAlimento(void);
char telaHigiene(void);
char telaLimpeza(void);

int  main ( void )
{
    char tela;
    tela = telaCadastro ();
    switch (tela)
    {
        case '1':
            cadastrarAlimento();
            break;
        case '2':
            cadastrarHigiente();
            break; 
        case  '3' :
            cadastrarLimpeza();
            break;
        case '4' :
            printf ( "Opcao invalida!\n" );
            break;
    }
}
char telaCadastro(void)
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ------------ SIG-Pantry - CADASTRO USUÁRIO -------------- | \n");
    printf(" |                                                           | \n");
    printf(" | ---------------- 1 - Cadastrar Usuário  ----------------- | \n");
    printf(" | ---------------- 2 - Editar Cadastro    ----------------- | \n"); 
    printf(" | ---------------- 3 - Listar Usuários    ----------------- | \n");    
    printf(" | ---------------- 4 - Remover Usuário    ----------------- | \n");
    printf(" | ---------------- 5 - Retornar ao Menu Inicial ----------- | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao:                                        | \n");
    printf(" | ========================================================= | \n");
    scanf("%c", &opcao);

    return opcao;

}

char telaAlimento(void)
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ----------------- CADASTRAR ITEM ALIMENTAR -------------- | \n");
    printf(" |                                                           | \n");
    printf(" | ----------------- 1- Nome do Item ----------------------- | \n");
    printf(" | ----------------- 2- Data de Validade ------------------- | \n"); 
    printf(" | ----------------- 3- Local de armazenamento ------------- | \n");    
    printf(" | ----------------- 0- Voltar a tela principal ------------ | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao:                                        | \n");
    printf(" | ========================================================= | \n");
    scanf("%c", &opcao);  
    
    return opcao;

}

char telaHigiene(void)
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ---------- CADASTRAR ITEM DE HIGIENE PESSOAL ------------ | \n");
    printf(" |                                                           | \n");
    printf(" | --------------- 1- Nome do Item ------------------------- | \n");
    printf(" | --------------- 2- Data de Validade --------------------- | \n"); 
    printf(" | --------------- 3- Local de armazenamento --------------- | \n");    
    printf(" | --------------- 0- Voltar a tela principal -------------- | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao:                                        | \n");
    printf(" | ========================================================= | \n");
    scanf("%c", &opcao);  
    
    return opcao;

}

char telaLimpeza(void)
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ---------------- CADASTRAR ITEM DE LIMPEZA -------------- | \n");
    printf(" |                                                           | \n");
    printf(" | ----------------- 1- Nome do Item ----------------------- | \n");
    printf(" | ----------------- 2- Data de Validade ------------------- | \n"); 
    printf(" | ----------------- 3- Local de armazenamento ------------- | \n");    
    printf(" | ----------------- 0- Voltar a tela principal ------------ | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao:                                        | \n");
    printf(" | ========================================================= | \n");
    scanf("%c", &opcao);  
    
    return opcao;
    

}
