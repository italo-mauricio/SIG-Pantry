#include<stdio.h>
#include<stdlib.h>
#include "modulocadastroUsuario.h"

/*
DENTRO DESSE CADASTRO: estará os dados do usuário do sistema de controle de despensa doméstica.
*/

// ================ Declarando as funções =======================
char telaCadastroUsuario(void);
char cadastroUsuario(void);
char telaEditar(void);
char telaListar(void);
char telaRemove(void);


// ==============================================================

int  main (void)
{
    char escolha;
    do {
        escolha = telaCadastroUsuario();
        switch (escolha) {
        case '1':
            cadastroUsuario();
            break;
        case '2':
            telaEditar();
            break; 
        case  '3':
            telaListar();
            break;
        case '4':
            telaRemove();
            break;

        default :
            printf ("Opcao invalida \n");
            break;
    }

    } while(escolha != '0');

    return  0 ;
}


// ================================ Começo do cadastro ====================================== //

char telaCadastroUsuario(void) // Tela inicial dos cadastros
{
    char opcao;
    system ( " cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ------------ SIG-Pantry - CADASTRO USUARIO -------------- | \n");
    printf(" |                                                           | \n");
    printf(" |                  1 - Cadastrar Usuario                    | \n");
    printf(" |                  2 - Editar Cadastro                      | \n"); 
    printf(" |                  3 - Listar Usuarios                      | \n");    
    printf(" |                  4 - Remover Usuario                      | \n");
    printf(" |                  5 - Retornar ao Menu Inicial             | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao: ");
    scanf("%c", &opcao);
    getchar();
    
    return opcao;

}


// =================================================================================

char cadastroUsuario(void) // Cadastro central do usuário
{
    char esc;
    char nome [20];
    char CPF [11];
    char Email;
    char DatadeNascimento;
    char Username;
    char Senha;
    system ( " cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                  Cadastro SIG - Pantry                    | \n");
    printf(" | ========================================================= | \n");
    printf(" |                                                           | \n");
    printf(" | Informe seu nome: ");
    scanf("%[A-Z a-z]", nome);
    getchar(); 
    printf(" | Informe o seu CPF: ");
    scanf("%c", &CPF); 
    getchar();
    printf(" | Informe o seu Email: ");    
    scanf("%c", &Email);
    getchar();
    printf(" | Informe sua Data de Nascimento: ");
    scanf("%c", &DatadeNascimento);
    getchar();
    printf(" | Escolha um Username: ");
    scanf("%c", &Username);
    getchar();
    printf(" | Informe sua Senha: ");
    scanf("%c", &Senha);
    getchar();
    printf(" | Usuario cadastrado com sucesso!                           | \n");
    printf(" | ========================================================= | \n");
    printf(" Press ENTER to exit...");
    scanf("%c", &esc);
    getchar();

    return esc;

}

// ============================== Editar o cadastro =================================== 

char telaEditar(void)
{
   
    char esc;
    system ( " cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                      SIG - Pantry                         | \n");
    printf(" |                    (Atualizar Dados)                      | \n");
    printf(" | ========================================================= | \n");
    printf(" |                                                           | \n");
    printf(" | Atualizar Nome:                                           | \n");
    printf(" | Atualizar Email:                                          | \n"); 
    printf(" | Atualizar Data nascimento:                                | \n");    
    printf(" | Atualizar Username:                                       | \n");
    printf(" | Atualizar Senha:                                          | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | ========================================================= | \n");
    printf("| Press ENTER to exit... ");
    scanf("%c", &esc);
   
    return esc;

}


// ===================================== Listar o cadastro =================================

char telaListar(void)
{

    char esc;
    system ( " cls" );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                       SIG - Pantry                        | \n");
    printf(" |                      (Listar Dados)                       | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |              Aqui serão listado seus dados!               | \n");
    printf(" |                                                           | \n"); 
    printf(" |  Nome:                                                    | \n");    
    printf(" |  Email:                                                   | \n");
    printf(" |  CPF:                                                     | \n");
    printf(" |  Data de nascimento:                                      | \n");
    printf(" |  Username:                                                | \n");
    printf(" |  Senha:                                                   | \n");
    printf(" |                                                           | \n");
    printf(" |                                                           | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ========================================================= | \n");
    printf("| Press ENTER to exit... ");
    scanf("%c", &esc);

    return esc;
      
    
}


// =============================== Remover o cadastro ============================

char telaRemove(void){


    char opcao;
    system ( " cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                       SIG - Pantry                        | \n");
    printf(" |                      (Remover Dados)                      | \n");
    printf(" |                                                           | \n");
    printf(" |                                                           | \n");
    printf(" | Digite qual usuário você quer remover:                    | \n");
    printf(" | Digite a senha de acesso:                                 | \n");
    printf(" | Deseja realmente excluir?                                 | \n");
    printf(" |                                                           | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ========================================================= | \n");        
    printf(" | Press ENTER for exit... ");
    scanf("%c", &opcao);  
    getchar();

    return opcao;



}


