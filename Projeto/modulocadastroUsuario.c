#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "modulocadastroUsuario.h"
#include "validacoes.h"

void modulocadastroUsuario(void)
{    
    int escolha;
    do {
        escolha = telaMenuUsuario();
        switch (escolha) {
        case 1:
            InfoUsuario(); //cadastro
            break;
        case 2:
            buscaInfoUsuario(); //pesquisa
            break;
        case 3:
            //EditarUsuario(); //edição
            break;
        case 4:
            infoExcluirUs(); //exclusão
            break; 
        case 5:
            listaInfoUsuario(); //relatório
            break;
        default:
            printf ("Opção inválida! \n");
            break;
    }

    } while(escolha != 0);
  
}

int telaMenuUsuario(void) 
{
    int opcao;
    system ( " cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------- SIG-Pantry - MENU USUÁRIO ---------------- | \n");
    printf(" |                                                           | \n");
    printf(" |                 1 - Cadastrar Usuário                     | \n");
    printf(" |                 2 - Pesquisar dados                       | \n");
    printf(" |                 3 - Editar Cadastro                       | \n"); 
    printf(" |                 4 - Excluir Usuário                       | \n");
    printf(" |                 5 - Listar dados                          | \n");    
    printf(" |                 0 - Voltar à tela principal               | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opção: ");
    scanf("%d",&opcao);
    getchar();
    
    return opcao;

}

//função para cadastro do usuário no programa - "preenche"
void InfoUsuario(void) 
{
    Usuario* cliente;
    system ( " cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                   Cadastro SIG-Pantry                     | \n");
    printf(" | ========================================================= | \n");
    printf(" |                                                           | \n");
    cliente = (Usuario*) malloc(sizeof(Usuario));
    do
    {
        printf(" | Informe o seu nome: ");
        scanf("%[A-Z a-z 0-9 ]", cliente->nome);
        getchar();
        
    } while (!validarLetras(cliente->nome, tamanhoString(cliente->nome)));
    
    do {
        printf(" | Informe o seu E-mail: ");   
        scanf("%s", cliente->email);
        getchar();

    } while (!lerEmail(cliente->email));
    
    do {        
        printf(" | Informe o dia de nascimento: ");
        scanf("%d",&cliente->dia);
        getchar();
        printf(" | Informe o mês de nascimento: ");
        scanf("%d",&cliente->mes);
        getchar();
        printf(" | Informe o ano de nascimento: ");
        scanf("%d",&cliente->ano);
        getchar();
        
     } while(!valida_data(cliente->dia, cliente->mes, cliente->ano));  
 
    do {
        printf(" | Escolha um username: ");
        scanf("%s", cliente->username);
        getchar();

    } while(!lerUsernameSenha(cliente->username));

    do {
        printf(" | Informe sua senha: ");
        scanf("%s", cliente->senha);
        getchar();

    } while(!lerUsernameSenha(cliente->senha));
    
    printf(" | Usuário cadastrado com sucesso!                           | \n");
    printf(" | ========================================================= | \n");
    cliente->status = '1'; //o t(true) mostra que foi cadastrado
    gravaUsuario(cliente);
    free(cliente);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    


}

//A partir do username, visto que cada usuário tem o seu
void buscaInfoUsuario(void)
{
    FILE* fp;
    Usuario* cliente;
    int achou;
    char procurado[15];
    fp = fopen("usuario.dat", "rb");

    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
    }
    printf("\n\n");
    system ( " cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                   Buscar dados do usuário                 | \n");
    printf(" | ========================================================= | \n");
    printf("Informe o seu username: ");
    scanf(" %30[^\n]", procurado);
    getchar();
    cliente = (Usuario*) malloc(sizeof(Usuario));
    achou = 0;
    while((!achou) && (fread(cliente, sizeof(Usuario), 1, fp))) {
        printf("nome do cliente |%s|\n", cliente->username);
        if ((strcmp(cliente->username, procurado) == 0) && (cliente->status == '1')) {
            achou = 1;
        }
    }
    fclose(fp);
    if (achou) {
        exibeInfoUsuario(cliente);
    } else {
        printf("Os dados do usuário %s não foram encontrados\n", procurado);
    }
    free(cliente);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    

}

//void editaDadosUsu(void) {
    
//}

//VAI PRECISAR ALTERAR
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
            atualizar = atualizaNome();
            break;
        case '2':
            atualiza = atualizEmail();
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

AtualizarNome* atualizaNome()
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

//função para gravar no arquivo
void gravaUsuario(Usuario* cliente) 
{
    FILE* fp;
    fp = fopen("usuario.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Não é possível continuar o programa...\n");
        exit(1);
    }
    
    fwrite(cliente, sizeof(Usuario), 1, fp);
    fclose(fp);

}

//função para remover o cadastro
void infoExcluirUs(void)
{
    FILE* fp;
    Usuario* cliente;
    int achou;
    char resp;
    char procurado[20];
    fp = fopen("usuario.dat", "r+b");

    if (fp == NULL){
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
    }
    cliente = (Usuario*) malloc(sizeof(Usuario));
    system( " clear || cls ");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ---------------------- EXCLUIR USUÁRIO ----------------------- | \n");
    printf(" |                                                                | \n");
    printf(" | Informe o username do usuário que você quer excluir: ");
    scanf(" %30[^\n]", procurado);
    getchar();  
    achou = 0;
    while ((!achou) && (fread(cliente, sizeof(Usuario), 1, fp))){
        if ((strcmp(cliente->username, procurado) == 0) && (cliente->status == '1')){
            achou = 1;
        }
    }

   if (achou){
        exibeInfoUsuario(cliente);
        getchar();
        printf("Deseja realmente excluir os dados deste usuário? (s/n)");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S'){
            cliente->status = '0';
            fseek(fp, (-1)*sizeof(Usuario), SEEK_CUR);
            fwrite(cliente, sizeof(Usuario), 1, fp);
            printf("\nUsuário excluído com sucesso!");
            gravaUsuario(cliente);
        }else{
            printf("\nTudo bem, os dados não foram alterados!");
        }
    }else{
        printf("O usuário não foi encontrado!");
    }
    free(cliente);
    fclose(fp);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    
}

//função para listar os dados do usuário 
void listaInfoUsuario(void) 
{
    FILE* fp;
    Usuario* cliente;
    fp = fopen("usuario.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
    }
    printf("\n\n");
    printf(" | ==================== Exibe usuário ====================== | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    cliente = (Usuario*)malloc(sizeof(Usuario));
    while(fread(cliente, sizeof(Usuario), 1, fp)) {
        exibeInfoUsuario(cliente);
    }
    fclose(fp);
    free(cliente);

}

void exibeInfoUsuario(Usuario* cliente) {
    printf(" | Nome: %s\n", cliente->nome);    
    printf(" | E-mail: %s\n", cliente->email);
    printf(" | Dia do nascimento: %d\n", cliente->dia); 
    printf(" | Mês do nascimento: %d\n", cliente->mes); 
    printf(" | Ano do nascimento: %d\n", cliente->ano); 
    printf(" | Username: %s\n", cliente->username);
    printf(" | Status: %c\n", cliente->status);
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    
}