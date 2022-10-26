#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "modulocadastroUsuario.h"
#include "validacoes.h"

//DENTRO DESSE CADASTRO: estarão os dados do usuário do sistema de controle de despensa doméstica.

void modulocadastroUsuario(void)
{
    Usuario* cliente;
    int escolha = 0;
    do {
        escolha = telaMenuUsuario();
        switch (escolha) {
        case 1:
            cliente = infoUsuario();
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

Usuario* infoUsuario( );

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

Usuario* infoUsuario( ) // Cadastro central do usuário
{
    Usuario* usu;
    usu = (Usuario*) malloc(sizeof(Usuario));
    system ( " cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                  Cadastro SIG - Pantry                    | \n");
    printf(" | ========================================================= | \n");
    printf(" |                                                           | \n");
    do
    {
        printf(" | Informe o seu nome: ");
        scanf("%s", usu->nome);
        getchar();
        
    } while (!lerLetras(usu->nome));
    
    do {
        printf(" | Informe o seu E-mail: ");   
        scanf("%s", usu->email);
        getchar();

    } while (!lerEmail(usu->email));
  
    veriData();
  
    do {
        printf(" | Escolha um username: ");
        scanf("%s", usu->username);
        getchar();

    } while(!lerUsernameSenha(usu->username));

    do {
        printf(" | Informe sua senha: ");
        scanf("%s", usu->senha);
        getchar();

    } while(!lerUsernameSenha(usu->senha));
    
    printf(" | Usuário cadastrado com sucesso!                           | \n");
    printf(" | ========================================================= | \n");
    printf(" Press ENTER to exit...");
    getchar();

    return usu;
}


Data* veriData( ){
    Data* dt;
    do {        
        printf(" | Informe o dia de nascimento: ");
        scanf("%d",&dt->dia);
        getchar();
        printf(" | Informe o mês de nascimento: ");
        scanf("%d",&dt->mes);
        getchar();
        printf(" | Informe o ano de nascimento: ");
        scanf("%d",&dt->ano);
        getchar();
        
     } while(!valida_data(dt->dia, dt->mes, dt->ano));
  
    return dt;
}


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
        scanf("%s", nome);
        getchar();
        
    } while (!lerLetras(nome));
    
    do {
        printf(" | Informe o novo E-mail: ");   
        scanf("%s", email);
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
        scanf("%s", username);
        getchar();

    } while(!lerUsernameSenha(username));

    do {
        printf(" | Informe sua nova senha: ");
        scanf("%s", senha);
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