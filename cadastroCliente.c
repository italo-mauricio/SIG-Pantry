
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

char cadastroUsuario(void)
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                  Cadastro SIG - Pantry                    | \n");
    printf(" | ========================================================= | \n");
    printf(" |                                                           | \n");
    printf(" | Nome:                                                     | \n");
    printf(" | CPF:                                                      | \n"); 
    printf(" | Email:                                                    | \n");    
    printf(" | Data de Nascimento:                                       | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Descrição: Olá, aqui serão colocadas as suas informações  | \n");
    printf(" | pessoais para efetuarmos o seu cadastro no nosso sistema  | \n");
    printf(" | serão apenas informações rápida para a sua segurança.     | \n");
    print("  | ========================================================= | \n");

    
    return opcao;

}

char telaEditar(void)
{
    char opcao;
    system ( " clear " );
    printf(" | ========================================================== | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                      SIG - EDITAR                         | \n");
    printf(" | ========================================================= | \n");
    printf(" |                                                           | \n");
    printf(" | Editar Nome:                                              | \n");
    printf(" | Editar Email:                                             | \n"); 
    printf(" | Editar Data nascimento:                                   | \n");    
    printf(" | Editar Username:                                          | \n");
    printf(" | Editar Senha:                                             | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ========================================================= | \n");
    printf(" | ========================================================= | \n");
    scanf("%c", &opcao);  
    
    return opcao;

}

char telaListar(void)
{
    char opcao;
    system ( " clear " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                                                           | \n");
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



char telaRemove(void){

     char opcao;
    system ( " clear " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                                                           | \n");
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