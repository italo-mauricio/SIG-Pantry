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
char removeUsuario (void);
char removeNome(void);
char removeCpf(void);
char removeEmail(void);


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
              char remove;
            do {
                remove = telaRemove();
                switch (remove) {
                case '1':
                    removeUsuario();
                    break;
                case '2':
                    removeNome();
                    break; 
                case  '3':
                    removeCpf();
                    break;
                case '4':
                    removeEmail();
                    break; 
                default :
                    printf ("Opcao invalida \n");
                    break;
            }

            } while(remove != '0');

        default :
            printf ("Opcao invalida \n");
            break;
    }

    } while(escolha != '0');

    return  0 ;
}


char telaCadastroUsuario(void)
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ------------ SIG-Pantry - CADASTRO USUÁRIO -------------- | \n");
    printf(" |                                                           | \n");
    printf(" |                  1 - Cadastrar Usuário                    | \n");
    printf(" |                  2 - Editar Cadastro                      | \n"); 
    printf(" |                  3 - Listar Usuários                      | \n");    
    printf(" |                  4 - Remover Usuário                      | \n");
    printf(" |                  5 - Retornar ao Menu Inicial             | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao: ");
    scanf("%c", &opcao);
    getchar();
    
    return opcao;

}

char cadastroUsuario(void)
{
    char esc;
    char Nome, CPF, Email, DatadeNascimento, Username, Senha;
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
    printf(" | Username:                                                 | \n");
    printf(" | Senha:                                                    | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Descrição: Ola, aqui serao colocadas as suas informacoes  | \n");
    printf(" | pessoais para efetuarmos o seu cadastro no nosso sistema. | \n");
    printf(" | Serao apenas informacoes rapidas para a sua segurança.    | \n");
    printf("  | ======================================================== | \n");
    printf(" Press ENTER to exit...");
    scanf("%c", &esc);

    return esc;

  

}

char telaEditar(void)
{
   
    char esc;
    system ( " clear " );
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

char telaListar(void)
{

    char esc;
    system ( " clear " );
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


char telaRemove(void){


    char opcao;
    system ( " clear " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                       SIG - Pantry                        | \n");
    printf(" |                      (Remover Dados)                      | \n");
    printf(" |                                                           | \n");
    printf(" |                                                           | \n");
    printf(" | ----------------- 1- Username do usuario ---------------- | \n");
    printf(" | ----------------- 2- Nome do usuario  ------------------- | \n");
    printf(" | ----------------- 3- CPF do usuario  -------------------- | \n");
    printf(" | ----------------- 4- Email do usuario  ------------------ | \n");
    printf(" | ----------------- 0- Voltar a tela de cadastro ---------- | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao: \n");
    scanf("%c", &opcao);  
    getchar();

    return opcao;



}


char removeUsuario (void)

{

    char esc;
    printf("| ============================================================= | \n");
    printf("| ------------------------------------------------------------- | \n");
    printf("| ------------------- | Remover Username | -------------------- | \n");
    printf("|                                                               | \n");
    printf("| Nome do usuario que deseja removar:                           | \n");
    printf("|                                                               | \n");
    printf("|                                                               | \n");
    printf("|                                                               | \n");
    printf("| ============================================================= | \n");
    printf("| Press ENTER to exit... ");
    scanf("%c", &esc);


    return esc;


}


char removeNome(void){

    
    char esc;
    printf("| ============================================================= | \n");
    printf("| ------------------------------------------------------------- | \n");
    printf("| ------------------- | Remover Nome | ------------------------ | \n");
    printf("|                                                               | \n");
    printf("| Nome que deseja removar:                                      | \n");
    printf("|                                                               | \n");
    printf("|                                                               | \n");
    printf("|                                                               | \n");
    printf("| ============================================================= | \n");
    printf("| Press ENTER to exit... ");
    scanf("%c", &esc);


    return esc;

}


char removeCpf(void)
{

    char esc;
    printf("| ============================================================= | \n");
    printf("| ------------------------------------------------------------- | \n");
    printf("| ---------------------- | Remover CPF | ---------------------- | \n");
    printf("|                                                               | \n");
    printf("| CPF que deseja removar:                                       | \n");
    printf("|                                                               | \n");
    printf("|                                                               | \n");
    printf("|                                                               | \n");
    printf("| ============================================================= | \n");
    printf("| Press ENTER to exit... ");
    scanf("%c", &esc);

    return esc;

}

char removeEmail(void)
{

    char esc;
    printf("| ============================================================= | \n");
    printf("| ------------------------------------------------------------- | \n");
    printf("| ---------------------- | Remover Email | -------------------- | \n");
    printf("|                                                               | \n");
    printf("| Email que deseja removar:                                     | \n");
    printf("|                                                               | \n");
    printf("|                                                               | \n");
    printf("|                                                               | \n");
    printf("| ============================================================= | \n");
    printf("| Press ENTER to exit... ");
    scanf("%c", &esc);


    return esc;

}