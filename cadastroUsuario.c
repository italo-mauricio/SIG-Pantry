
#include<stdio.h>
#include<stdlib.h>

/*
DENTRO DESSE CADASTRO: estará os dados do usuário do sistema de controle de despensa doméstica.
*/

char telaCadastroUsuario(void);
char cadastroUsuario(void);
char telaEditar(void);
char telaListar(void);
char telaRemove(void);

int  main (void)
{
    char escolha;
    do {
        escolha = telaCadastroUsuario();
        switch (escolha) {
        case '1':
            telaCadastroUsuario();
            break;
        case '2':
            telaCadastroItens();
            break; 
        case  '3':
            telaListadeCompras();
            break;
        case '4':
            telaRelatorio();
            break; 
        case '5':    
            telaSobre ();
            break ;
        defaut :
            printf ('Opcao invalida \n');
            break ;
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
    printf(" | Escolha uma opcao:                                        | \n");
    printf(" | ========================================================= | \n");
    scanf("%c", &opcao);
    getchar();
    
    return opcao;

}

char cadastroUsuario(void)
{
    char Nome, CPF, Email, Data de nascimento, Username, Senha;
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
    print("  | ========================================================= | \n");

  

}

char telaEditar(void)
{
   
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
   

}

char telaListar(void)
{
   
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
    printf(" | ----------------- 1- Nome do Item ----------------------- | \n");
    printf(" | ----------------- 2- Data de Validade ------------------- | \n"); 
    printf(" | ----------------- 3- Local de armazenamento ------------- | \n");    
    printf(" | ----------------- 0- Voltar a tela principal ------------ | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao:                                        | \n");
    printf(" | ========================================================= | \n");
    scanf("%c", &opcao);  
    getchar();
    
    return opcao; 
    
}