#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "modulocadastroUsuario.h"
#include "validacoes.h"

//DENTRO DESSE CADASTRO: estarão os dados do usuário do sistema de controle de despensa doméstica.

void modulocadastroUsuario(void)
{
    Usuario* cliente;
    ExcluirUsuario* excluir;
    int escolha = 0;
    do {
        escolha = telaMenuUsuario();
        switch (escolha) {
        case 1:
            cliente = infoUsuario();
            break;
        case 2:
            telaAtualizarUsuario();
            break; 
        case  3:
            exibeUsuario(cliente);
            break;
        case 4:
            excluir = infoExcluirUs();
            break;
        default :
            printf ("Opção inválida! \n");
            break;
    }

    } while(escolha != 0);
  
    free(cliente);
    free(excluir);

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

Usuario* infoUsuario( ) // Cadastro central do usuário
{
    Usuario* usu;
    usu = (Usuario*) malloc(sizeof(Usuario));
    system ( " cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                   Cadastro SIG-Pantry                     | \n");
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


Data* veriData( )
{
    Data* dt;
    dt = (Data*) malloc(sizeof(Data));
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

void telaAtualizarUsuario(void) 
{
    char op;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ------------------- ATUALIZAR USUÁRIO ------------------- | \n");
    printf(" |                                                           | \n");
    printf(" |                   1- Nome                                 | \n");
    printf(" |                   2- E-mail                               | \n");
    printf(" |                   3- Data de nascimento                   | \n");  
    printf(" |                   4- Username                             | \n"); 
    printf(" |                   5- Senha                                | \n");       
    printf(" |                   0- Voltar à tela menu usuário           | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &op); 
    getchar();
    escolhafuncao(op); 

}

void escolhafuncao(char op){ 
        AtualizarNome* atualizar;
        AtualizarEmail* atualiza;
        AtualizarDataNasc* atualiz;
        AtualizarUsername* atuali;
        AtualizarSenha* atual;
        switch (op)
        {
        case '1':
            atualizar = atualizarNome();
            break;
        case '2':
            atualiza = atualizarEmail();
            break;
        case '3':
            atualiz = atualizarData();
            break;
        case '4':
            atuali = atualizUsername();
            break;
        case '5':
            atual = atualizSenha();
            break;
        case '0':
            break;        
        default:
            printf("Opção inválida\n");
            break;
        }

        free (atualizar);
        free (atualiza);
        free (atualiz);
        free(atuali);
        free(atual);

}


AtualizarNome* atualizNome()
{
    AtualizarNome* atnomeus;
    atnomeus = (AtualizarNome*) malloc(sizeof(AtualizarNome));
    system( " clear || cls");
    printf(" | ============================================================== | \n");
    printf(" |                         SIG - Pantry                           | \n");
    printf(" |                       (Atualizar Nome)                         | \n");
    printf(" | ============================================================== | \n");
    printf(" |                                                                | \n");
    do
    {
        printf(" | Informe o novo nome: ");
        scanf("%s", atnomeus->nome);
        getchar();
        
    } while (!lerLetras(atnomeus->nome));

    printf(" | ------------------------------------------------------------- | \n");
    printf(" | ============================================================= | \n");
    printf(" | Nome atualizado, por favor, digite ENTER...");
    getchar();
    
    return atnomeus;

}

AtualizarEmail* atualizEmail( )
{
    AtualizarEmail* atEmail;
    atEmail = (AtualizarEmail*) malloc(sizeof(AtualizarEmail));
    system ( " cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                      SIG - Pantry                         | \n");
    printf(" |                    (Atualizar E-mail)                     | \n");
    printf(" | ========================================================= | \n");
    printf(" |                                                           | \n");
    
    do {
        printf(" | Informe o novo E-mail: ");   
        scanf("%s", atEmail->email);
        getchar();

    } while (!lerEmail(atEmail->email));

    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | ========================================================= | \n");
    system("Pause");
    system("cls");
    getchar();

    return atEmail;

}

AtualizarDataNasc* atualizarData()
{
    AtualizarDataNasc* atdatan;
    atdatan = (AtualizarDataNasc*) malloc(sizeof(AtualizarDataNasc));
    system( " clear || cls");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" |                         SIG - Pantry                           | \n");
    printf(" |                   (Atualizar data de nascimento)               | \n");
    printf(" | ============================================================== | \n");
    printf(" |                                                                | \n");
    do {
        printf(" | Informe o dia de vencimento do produto: ");
        scanf("%d", &atdatan->dia);
        getchar();
        printf(" | Informe o mês de vencimento do produto: ");
        scanf("%d", &atdatan->mes);
        getchar();
        printf(" | Informe o ano de vencimento do produto: ");
        scanf("%d", &atdatan->ano);
        getchar();
        
    } while(!valida_data(atdatan->dia, atdatan->mes, atdatan->ano));

    printf(" | ------------------------------------------------------------- | \n");
    printf(" | ============================================================= | \n");
    printf( " Press ENTER for continue...");
    getchar();

    return atdatan;
    
}

AtualizarUsername* atualizUsername()
{
    AtualizarUsername* atUsername;
    atUsername = (AtualizarUsername*) malloc(sizeof(AtualizarUsername));
    system ( " cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                      SIG - Pantry                         | \n");
    printf(" |                  (Atualizar username)                     | \n");
    printf(" | ========================================================= | \n");
    printf(" |                                                           | \n");

    do {
        printf(" | Escolha um novo username: ");
        scanf("%s", atUsername->username);
        getchar();

    } while(!lerUsernameSenha(atUsername->username));

    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | ========================================================= | \n");
    system("Pause");
    system("cls");
    getchar();

    return atUsername;

}

AtualizarSenha* atualizSenha()
{
    AtualizarSenha* atSenha;
    atSenha = (AtualizarSenha*) malloc(sizeof(AtualizarSenha));
    system ( " cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                      SIG - Pantry                         | \n");
    printf(" |                    (Atualizar senha)                      | \n");
    printf(" | ========================================================= | \n");
    printf(" |                                                           | \n");

    do {
        printf(" | Informe uma nova senha: ");
        scanf("%s", atSenha->senha);
        getchar();

    } while(!lerUsernameSenha(atSenha->senha));

    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | ========================================================= | \n");
    system("Pause");
    system("cls");
    getchar();

    return atSenha;

}
// ===================================== Listar o cadastro =================================
void exibeUsuario(const Usuario*, const Data*) 
{
    system ( " cls" );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                       SIG - Pantry                        | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                Dados cadastrados do usuário               | \n");
    printf(" |                                                           | \n"); 
    printf(" | Nome: %s\n", usu->nome);    
    printf(" | E-mail: %s\n", usu->email);
    printf(" | Dia do nascimento: %d\n", dt->dia); 
    printf(" | Mês do nascimento: %d\n", dt->mes); 
    printf(" | Ano do nascimento: %d\n", dt->ano); 
    printf(" | Username: %s\n", usu->username);
    printf(" | Senha: %s\n", usu->senha);
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    getchar();

}


// =============================== Remover o cadastro ============================

ExcluirUsuario* infoExcluirUs()
{
    ExcluirUsuario* excus;
    excus = (ExcluirUsuario*) malloc(sizeof(ExcluirUsuario));
    system( " clear || cls ");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ---------------------- EXCLUIR USUÁRIO ----------------------- | \n");
    printf(" |                                                                | \n");
    do
    {
        printf(" | Informe o email do usuário que deseja excluir: ");
        scanf("%s", excus->email);
        getchar();
        
    } while (!lerEmail(excus->email));

    // aqui terá um if se o código de barra for encontrado ele entrará nas opções
    // if barra == (nosso banco de dados);
        // digite a quantidade de itens que deseja excluir;
        // os itens serão removidos.
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ============================================================== | \n");
    printf(" Press ENTER for continue... ");
    getchar();

    return excus;

}