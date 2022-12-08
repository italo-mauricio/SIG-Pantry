#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "modulocadastroUsuario.h"
#include "validacoes.h"

/*
              Bem-vindo(a) ao módulo de cadastro de usuários!
        
        Neste módulo serão cadastrados os usuários do nosso programa

*/


// Este é o menu principal deste módulo
void modulocadastroUsuario(void)
{    
    char op;
    do {
        op = telaMenuUsuario();
        switch (op) {
        case '1':
            InfoUsuario(); //cadastro
            break;
        case '2':
            buscaInfoUsuario(); //pesquisa
            break;
        case '3':
            atualizarUsuario(); //edição
            break;
        case '4':
            infoExcluirUs(); //exclusão
            break; 
        case '5':
            listaInfoUsuario(); //relatório
            break;
        default:
            printf ("Opção inválida! \n");
            break;
    }

    } while(op != '0');
      
}


// tela que será usada para a escolha da navegação 
char telaMenuUsuario(void) 
{
    char opcao;
    system ( "cls || clear" );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------- SIG-Pantry - MENU USUÁRIO ---------------- | \n");
    printf(" |                                                           | \n");
    printf(" |                 1 - Cadastrar usuário                     | \n");
    printf(" |                 2 - Pesquisar dados                       | \n");
    printf(" |                 3 - Editar cadastro                       | \n"); 
    printf(" |                 4 - Excluir usuário                       | \n");
    printf(" |                 5 - Listar dados                          | \n");    
    printf(" |                 0 - Voltar à tela principal               | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opção: ");
    scanf("%s",&opcao);
    getchar();
    
    return opcao;

}



//função para cadastro do usuário no programa 
void InfoUsuario(void) 
{
    Usuario* cliente;
    
    system(" cls || clear");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                   Cadastro SIG-Pantry                     | \n");
    printf(" | ========================================================= | \n");
    printf(" |                                                           | \n");
    cliente = (Usuario*) malloc(sizeof(Usuario));
    do
    {
        printf(" | Informe o seu nome: ");
        scanf("%[A-Z a-z]", cliente->nomeUsuario);
        getchar();
        
    } while (!validarLetras(cliente->nomeUsuario, tamanhoString(cliente->nomeUsuario)));
    
    do {
        printf(" | Informe o seu E-mail: ");   
        scanf("%s", cliente->emailUsuario);
        getchar();

    } while (!lerEmail(cliente->emailUsuario));
    
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

        printf(" | Informe o seu username: "); 
        scanf("%s",cliente->usernameUsuario);
        getchar();
    
    } while(!((lerUsername(cliente->usernameUsuario)) && (validaUser(cliente->usernameUsuario))));
          
    printf(" | Usuário cadastrado com sucesso!                           | \n");
    printf(" | ========================================================= | \n");
    cliente->status = '1'; //o 1 mostra que foi cadastrado
    gravaUsuario(cliente);
    free(cliente);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();      
}



//busca a partir do username (id), visto que cada usuário tem o seu, iremos fazer a busca
int buscaInfoUsuario(void)
{
    FILE* fp;
    Usuario* cliente;
    int achou;
    char procurado[15]; 
    fp = fopen("usuario.dat", "rb");

    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }   
    printf("\n\n");
    system(" cls || clear ");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                   Buscar dados do usuário                 | \n");
    printf(" | ========================================================= | \n");
    printf("Informe o seu Username: ");
    scanf(" %30[^\n]", procurado);
    getchar();   
    cliente = (Usuario*) malloc(sizeof(Usuario));  
    achou = 0;  
    while((!achou) && (fread(cliente, sizeof(Usuario), 1, fp))) {
        if ((strcmp(cliente->usernameUsuario, procurado) == 0) && (cliente->status == '1')) {
            achou = 1;
        }
    }
    if (achou) {
        system(" cls || clear" );
        printf(" | ================== Usuário encontrado =================== |\n");
        printf(" |                                                           |\n");
        printf(" | Nome: %s\n", cliente->nomeUsuario);
        printf(" | Username: %s", cliente->usernameUsuario);    
        printf(" | E-mail: %s\n", cliente->emailUsuario);
        printf(" | Dia do nascimento: %d\n", cliente->dia); 
        printf(" | Mês do nascimento: %d\n", cliente->mes); 
        printf(" | Ano do nascimento: %d\n", cliente->ano); 
        printf(" | Status: %c\n", cliente->status);
        printf(" |                                                           | \n");
        printf(" | ========================================================= | \n");
    
    } else {
        printf("Os dados do usuário %s não foram encontrados\n", procurado);
    }
    free(cliente);
    fclose(fp); 
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    return 0; 
}



//função para editar dados do usuário
int atualizarUsuario(void) //adaptada by @IsaKaillany
{
    FILE* fp;
    Usuario* cliente;
    char resp;
    int achou;
    char procurado[20];
    fp = fopen("usuario.dat", "r+b");
    
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }  
    cliente = (Usuario*) malloc(sizeof(Usuario));  
    system(" cls || clear ");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ------------------- Atualizar usuário ------------------- | \n");
    printf("Informe o seu username: ");
    scanf(" %s", procurado);
    getchar(); 
    achou = 0;


    while((!achou) && (fread(cliente, sizeof(Usuario), 1, fp))) {
        if ((strcmp(cliente->usernameUsuario, procurado) == 0) && (cliente->status == '1')) {
            achou = 1;
    }
    if (achou){

        exibeInfoUsuario(cliente);
        resp = escAtualizarUsuario();
        printf("\n");

        if (resp == '1'){
            do
            {
                printf("Informe o novo nome: ");
                scanf("%[A-Z a-z]", cliente->nomeUsuario);
                getchar();

            } while(!validarLetras(cliente->nomeUsuario, tamanhoString(cliente->nomeUsuario)));

            do
            {
                printf("Informe o novo e-mail: ");
                scanf(" %49[^\n]", cliente->emailUsuario);
                getchar();

            } while(!lerEmail(cliente->emailUsuario));

            do
            {        
                printf(" | Informe o novo dia de nascimento: ");
                scanf("%d",&cliente->dia);
                getchar();
                printf(" | Informe o novo mês de nascimento: ");
                scanf("%d",&cliente->mes);
                getchar();
                printf(" | Informe o novo ano de nascimento: ");
                scanf("%d",&cliente->ano);
                getchar();
        
            } while(!valida_data(cliente->dia, cliente->mes, cliente->ano));  

        }
        else if (resp == '2'){
            do
            {
                printf("Informe o novo nome: ");
                scanf("%[A-Z a-z]", cliente->nomeUsuario);
                getchar();

            } while(!validarLetras(cliente->nomeUsuario, tamanhoString(cliente->nomeUsuario)));  
        }
        else if (resp == '3'){
            do
            {
                printf("Informe o novo e-mail: ");
                scanf(" %49[^\n]", cliente->emailUsuario);
                getchar();

            } while(!lerEmail(cliente->emailUsuario));
        }
        else if (resp == '4'){
            do
            {        
                printf(" | Informe o novo dia de nascimento: ");
                scanf("%d",&cliente->dia);
                getchar();
                printf(" | Informe o novo mês de nascimento: ");
                scanf("%d",&cliente->mes);
                getchar();
                printf(" | Informe o novo ano de nascimento: ");
                scanf("%d",&cliente->ano);
                getchar();
        
            } while(!valida_data(cliente->dia, cliente->mes, cliente->ano)); 
        }
        cliente->status = '1';      
        fseek(fp, (-1)*sizeof(Usuario), SEEK_CUR);
        fwrite(cliente, sizeof(Usuario), 1, fp);        
        printf(" |                                                           | \n");
        printf(" | --------------------------------------------------------- | \n");
        printf("Dados editados com sucesso");
    }   
    else 
    {   
        
        printf("O username %s não foi encontrado\n", procurado);
    }
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    free(cliente);
    fclose(fp);      
    } 
    return 0;
}


//função para selecionar o que quer atualizar
char escAtualizarUsuario(void)
{    
    char esc;
    system(" cls || clear");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ------------------- Atualizar usuário ------------------- | \n");
    printf(" |                                                           | \n");
    printf(" |                 1- Editar tudo                            | \n");
    printf(" |                 2- Editar nome                            | \n");
    printf(" |                 3- Editar e-mail                          | \n");
    printf(" |                 4- Editar data de nascimento              | \n");                 
    printf(" |                 0- Voltar à tela principal                | \n");    
    printf(" |                                                           | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | Selecione uma opção do que você deseja editar: ");
    scanf("%c", &esc);
    getchar();
    return esc;
}



//função para gravar no arquivo
int gravaUsuario(Usuario* cliente) 
{
    FILE* fp;
    fp = fopen("usuario.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Não é possível continuar o programa...\n");
        return 0;
    }
    
    fwrite(cliente, sizeof(Usuario), 1, fp);
    fclose(fp);
    return 0;

}



//função para remover o cadastro
int infoExcluirUs(void)
{
    FILE* fp;
    Usuario* cliente;
    int achou;
    char resp;
    char procurado[20];
    
    fp = fopen("usuario.dat", "r+b");

    if (fp == NULL){
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    cliente = (Usuario*) malloc(sizeof(Usuario));
    system( " clear || cls ");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ---------------------- Excluir usuário ----------------------- | \n");
    printf(" |                                                                | \n");
    printf(" | Informe o username do usuário que você quer excluir: ");
    scanf(" %30[^\n]", procurado);
    getchar();  
    achou = 0;
    
    while ((!achou) && (fread(cliente, sizeof(Usuario), 1, fp))){
        if ((strcmp(cliente->usernameUsuario, procurado) == 0) && (cliente->status == '1')){
            achou = 1;
        }
    }
   if (achou){
        exibeInfoUsuario(cliente);
        printf("Deseja realmente excluir os dados deste usuário? (s/n)");
        scanf("%c", &resp);
        
        if (resp == 's' || resp == 'S'){
            cliente->status = '0';
            fseek(fp, (-1)*sizeof(Usuario), SEEK_CUR);
            fwrite(cliente, sizeof(Usuario), 1, fp);
            printf("\nUsuário excluído com sucesso!");
            gravaUsuario(cliente);
            getchar();   
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
    return 0;
    
}


//função para listar os dados do usuário 
int listaInfoUsuario(void) 
{
    FILE* fp;
    Usuario* cliente;
    
    fp = fopen("usuario.dat", "rb");
    
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    cliente = (Usuario*)malloc(sizeof(Usuario)); 
    while(fread(cliente, sizeof(Usuario), 1, fp)) {
        system(" cls || clear");
        printf(" | ==================== Lista usuário ====================== | \n");
        printf(" |                                                           | \n");
        exibeInfoUsuario(cliente);
    } 
    fclose(fp);
    free(cliente);
    return 0;

}


// função para exibir as informações do usuário
void exibeInfoUsuario(Usuario* cliente) {
    system(" cls || clear");
    printf(" | =================== Usuário cadastrado ================== |\n");
    printf(" |                                                           |\n");
    printf(" | Nome: %s\n", cliente->nomeUsuario); 
    printf(" | Username: %s\n", cliente->usernameUsuario);   
    printf(" | E-mail: %s\n", cliente->emailUsuario);
    printf(" | Dia do nascimento: %d\n", cliente->dia); 
    printf(" | Mês do nascimento: %d\n", cliente->mes); 
    printf(" | Ano do nascimento: %d\n", cliente->ano); 
    printf(" | Status: %c\n", cliente->status);
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();   
}



//função para verificar se já tem um username cadastrado no arquivo
int validaUser(char* user)
{
    FILE *fp;
    Usuario *usuarioArq;

    usuarioArq = (Usuario*)malloc(sizeof(Usuario));
    
    fp = fopen("usuario.dat", "rt");
    
    if (fp == NULL)
    {
        printf("Gerando arquivo...");
        fclose(fp);
        return 1;
    }
    

    while (!feof(fp))
    {
        fread(usuarioArq, sizeof(Usuario), 1, fp);
        if (strcmp(user, usuarioArq->usernameUsuario) == 0 && (usuarioArq->status != '0'))
        {
            fclose(fp);
            return 0;
        }
    }
    fclose(fp);
    return 1;

}