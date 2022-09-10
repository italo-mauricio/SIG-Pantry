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
                    remove = telaRemove();          // No momento vamos concatenar os dois swifts, porém sabemos que não é a melhor alternativa
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
                    case '5':
                        telaCadastroUsuario();
                            
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
    char Nome, CPF, Email, DatadeNascimento, Username, Senha;
    system ( " cls " );
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
    printf(" | 1- Atualizar Nome:                                        | \n");
    printf(" | 2- Atualizar Email:                                       | \n"); 
    printf(" | 3- Atualizar Data nascimento:                             | \n");    
    printf(" | 4- Atualizar Username:                                    | \n");
    printf(" | 5- Atualizar Senha:                                       | \n");
    printf(" | 0- Voltar a tela de cadastro;                             | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao: \n");
    scanf("%c", &esc);
    getchar();
   
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
    printf(" |            Aqui serao listados os seus dados!             | \n");
    printf(" |                                                           | \n"); 
    printf(" | 1- Nome:                                                  | \n");    
    printf(" | 2- Email:                                                 | \n");
    printf(" | 3- CPF:                                                   | \n");
    printf(" | 4- Data de nascimento:                                    | \n");
    printf(" | 5- Username:                                              | \n");
    printf(" | 6- Senha:                                                 | \n");
    printf(" | 0- Voltar a tela de cadastro;                             | \n");
    printf(" |                                                           | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao: \n");
    scanf("%c", &esc);
    getchar();
   

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
    printf(" |  1- Username do usuario                                   | \n");
    printf(" |  2- Nome do usuario                                       | \n");
    printf(" |  3- CPF do usuario                                        | \n");
    printf(" |  4- Email do usuario                                      | \n");
    printf(" |  0- Voltar a tela de cadastro                             | \n");
    printf(" |                                                           | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao: \n");
    scanf("%c", &opcao);
    getchar();

    return opcao;

}



// A partir do chamamento da subfunção acima, entra nestas funções


char removeUsuario(void)

{
    
    char esc;
    system ( " cls " );
    printf("| ============================================================= | \n");
    printf("| ------------------------------------------------------------- | \n");
    printf("| ------------------- | Remover Username | -------------------- | \n");
    printf("|                                                               | \n");
    printf("| 1- Nome do usuario que deseja removar:                        | \n");
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
    system ( " cls " );
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
    system ( " cls " );
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
    system ( " cls " );
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