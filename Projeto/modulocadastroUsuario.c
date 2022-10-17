#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "modulocadastroUsuario.h"
#include "validacoes.h"

/*
DENTRO DESSE CADASTRO: estará os dados do usuário do sistema de controle de despensa doméstica.
*/

void modulocadastroUsuario(void)
{
    int escolha = 0;
    do {
        escolha = telaMenuUsuario();
        switch (escolha) {
        case 1:
            cadastroUsuario();
            break;
        case 2:
            telaEditar();
            break; 
        case  3:
            telaListar();
            break;
        case 4:
            telaRemove();
            break;
        default :
            printf ("Opção inválida! \n");
            break;
    }

    } while(escolha != 0);

   
}


// ================================ Começo do cadastro ====================================== //

int telaMenuUsuario(void) // Tela inicial dos cadastros
{
    int opcao;
    system ( " cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------- SIG-Pantry - MENU USUÁRIO ---------------- | \n");
    printf(" |                                                           | \n");
    printf(" |                 1 - Cadastrar Usuário                     | \n");
    printf(" |                 2 - Editar Cadastro                       | \n"); 
    printf(" |                 3 - Listar Usuários                       | \n");    
    printf(" |                 4 - Remover Usuário                       | \n");
    printf(" |                 0 - Voltar à tela principal               | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opção: ");
    scanf("%d",&opcao);
    getchar();
    
    return opcao;

}


// =================================================================================

void cadastroUsuario(void) // Cadastro central do usuário
{
    char nome[20];
    
    char Email [50]; 
    int dia, mes, ano;

    char Username [50];
    char Senha [50];
    system ( " cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                  Cadastro SIG - Pantry                    | \n");
    printf(" | ========================================================= | \n");
    printf(" |                                                           | \n");
    do
    {
        printf(" | Informe o seu nome: ");
        scanf("%s", nome);
        getchar();
        
    } while (!lerLetras(nome));
    
    do {
        printf(" | Informe o seu E-mail: ");   
        scanf("%s", Email);
        getchar();

    } while (!lerEmail(Email));

    do {
        printf(" | Informe o dia de nascimento: ");
        scanf("%d", &dia);
        getchar();
        printf(" | Informe o mês de nascimento: ");
        scanf("%d", &mes);
        getchar();
        printf(" | Informe o ano de nascimento: ");
        scanf("%d", &ano);
        getchar();
        
    } while(!valida_data(dia, mes, ano));
  
    do {
        printf(" | Escolha um username: ");
        scanf("%s", Username);
        getchar();

    } while(!lerUsernameSenha(Username));

    do {
        printf(" | Informe sua senha: ");
        scanf("%s", Senha);
        getchar();

    } while(!lerUsernameSenha(Senha));
    
    printf(" | Usuário cadastrado com sucesso!                           | \n");
    printf(" | ========================================================= | \n");
    printf(" Press ENTER to exit...");
    getchar();
}

//do{
  //  nome = lerNome(void);
// } while(!lerNome)




// ============================== Editar o cadastro =================================== 

void telaEditar(void)
{
    char nome[20];
    char email[30];
  
    int dia, mes, ano;

    char username[10];
    char senha [8];
    
    system ( " cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                      SIG - Pantry                         | \n");
    printf(" |                    (Atualizar Dados)                      | \n");
    printf(" | ========================================================= | \n");
    printf(" |                                                           | \n");
    do
    {
        printf(" | Informe o novo nome: ");
        scanf("%[A-Z a-z]", nome);
        getchar();
        
    } while (!lerLetras(nome));
    
    do {
        printf(" | Informe o novo E-mail: ");   
        scanf("%[A-Z a-z @ . _]", email);
        getchar();

    } while (!lerEmail(email));

    do {
        printf(" | Informe o dia de nascimento: ");
        scanf("%d", &dia);
        getchar();
        printf(" | Informe o mês de nascimento: ");
        scanf("%d", &mes);
        getchar();
        printf(" | Informe o ano de nascimento: ");
        scanf("%d", &ano);
        getchar();
        
    } while(!valida_data(dia, mes, ano));    
    
    do {
        printf(" | Escolha um novo username: ");
        scanf("%[A-Z a-z]", username);
        getchar();

    } while(!lerUsernameSenha(username));

    do {
        printf(" | Informe sua nova senha: ");
        scanf("%[A-Z a-z 0-9]", senha);
        getchar();

    } while(!lerUsernameSenha(senha));

    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | ========================================================= | \n");
    system("Pause");
    system("cls");

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
    printf(" |            Aqui serão listados os seus dados!             | \n");
    printf(" |                                                           | \n"); 
    printf(" | 1- Nome:                                                  | \n");    
    printf(" | 2- E-mail:                                                | \n");
    printf(" | 3- CPF:                                                   | \n");
    printf(" | 4- Data de nascimento:                                    | \n");
    printf(" | 5- Username:                                              | \n");
    printf(" | 6- Senha:                                                 | \n");
    printf(" | 0- Voltar a tela de cadastro;                             | \n");
    printf(" |                                                           | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    getchar();
   
    return esc;
         
}


// =============================== Remover o cadastro ============================

char telaRemove(void)
{

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