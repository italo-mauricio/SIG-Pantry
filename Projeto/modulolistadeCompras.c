#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modulolistadeCompras.h"
#include "validacoes.h"
#include "modulocadastroUsuario.h"
#include "modulomenuItem.h"

typedef struct item Item;

// consertar a parte de salvamento ou busca

void menulistadeCompras(void)
{
    char escolha;
    do {
        escolha = telaListadeCompras();
        switch (escolha) {
        /*case '1':
            itensQuantMinima(); //listar estoque mínimo
            break; */
        /*case '2':
            itensProxVencimento(); //listar itens próximos ao vencimento
            break; */
        case '1':
            infoMontarLista(); //preencher a lista
            break;
        case '2':
            buscarLista(); //pesquisa
            break; 
        case '3':
            atualizarLista(); //edição
            break;  
        case '4':
            excluirLista(); //exclusão
            break;
        case '5':
            listaComprasPronta(); //exibição da lista pronta (relatório)
            break;
        default:
            printf("Opção in válida\n");
            break;
    }

    } while(escolha != '0');
        printf("Obrigado! Volte sempre!");

} 

char telaListadeCompras(void)
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | -------------------| SIG-Pantry - LISTA DE COMPRAS |---------------- | \n");
    printf(" |                                                                      | \n");
    //printf(" |             1- Visualizar itens no estoque com quantidade mínima     | \n");
    //printf(" |             2- Visualizar itens próximos ao vencimento               | \n");
    printf(" |             1- Montar sua lista de compras                           | \n");
    printf(" |             2- Pesquisar lista de compras                            | \n");      
    printf(" |             3- Editar lista de compras                               | \n");      
    printf(" |             4- Excluir lista de compras                              | \n");      
    printf(" |             5- Visualizar itens cadastrados na lista                 | \n");       
    printf(" |             0- Voltar à tela principal                               | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &opcao);
    getchar();

    return opcao;

} 

//função feita para informar a quantid. mínima de itens com base no que foi registrado 
/*char itensQuantMinima(void)     
{
    FILE *fp;
    Item* it;
    int achou;
    char resp;
    char procurado[20];
    
    fp = fopen("itens.dat", "rt"); //só precisa abrir o de itens, pois irá resgatar informações desse arq
    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo");
        exit(1);
    }
    it = (Item*)malloc(sizeof(Item));

    while(fread(it, sizeof(Item), 1, fp)) { //fazer como o lista usuário, mas dentro do while colocar if cliente...
    system( " clear || cls ");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | --------- Itens com quantidade mínima na despensa ------------ | \n");
    printf(" |              ");

    }
    fclose(fp);
    free(it);

}
*/

/*void itensProxVencimento(void)
{
    //criar um ponteiro que puxe a informação com base na data de validade do cadastro de itens
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ----------------- | Itens próximos ao vencimento | ----------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |  Itens próximos ao vencimento: ");
    getchar();
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Pressione qualquer tecla para sair... ");
    getchar();

} */

//ver se procura pelo nome da lista ou pelo username do usuário
int infoMontarLista(void)
{
    FILE* fp;
    Usuario* cliente;
    MontarLista* mtlista;
    int achou;
    char procurado[15];

    fp = fopen("usuario.dat", "rb");

    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    cliente = (Usuario*) malloc(sizeof(Usuario));
    mtlista = (MontarLista*)malloc(sizeof(MontarLista));

    int resp;
    int i;
    system ( " cls || clear " );
    printf("| ============================================================= | \n");
    printf("| ------------------------------------------------------------- | \n");
    printf("| ------------- | Montar a sua lista de compras | ------------- | \n");
    printf("|                                                               | \n");
   
    printf("Informe o seu username: ");
    scanf(" %30[^\n]", procurado);
    getchar();

    achou = 0;
    while((!achou) && (fread(cliente, sizeof(Usuario), 1, fp))) {
        if ((strcmp(cliente->usernameUsuario, procurado) == 0) && (cliente->status == '1')) {
            achou = 1;
        }
    }
    fclose(fp);

    if (achou){

        printf("Informe quantos itens você vai adicionar a lista: ");
        scanf("%d", &resp);

        for (i = 1; i <= resp; i++) {
            
            do
            {
                printf(" | Informe o nome do produto: "); 
                scanf("%s", mtlista->nome);
                getchar();
                
            } while (!validarLetras(mtlista->nome, tamanhoString(mtlista->nome)));

            do 
            {
                printf(" | Informe a quantidade de produto: ");
                scanf("%s", mtlista->quantidadeProduto);
                getchar();
            
            } while (!lerQuantidade(mtlista->quantidadeProduto));
        }
        
    
    } else {
        printf("Os dados do usuário %s não foram encontrados\n", procurado);
    }
    printf("|                                                               | \n");
    printf("| ============================================================= | \n");
    mtlista->status = '1';
    gravaLista(mtlista);
    free(mtlista);
    gravaUsuario(cliente);
    free(cliente);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    return 0;

}

//função para gravar no arquivo
int gravaLista(MontarLista* mtlista) 
{
    FILE* fp;
    fp = fopen("lista.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        return 0;
    }
    
    fwrite(mtlista, sizeof(MontarLista), 1, fp);
    fclose(fp);
    return 0;
    
}

//função de pesquisa a partir do username (id do usuário)
int buscarLista(void)
{
    FILE* fp;
    MontarLista* mtlista;
    Usuario* cliente;
    int achou;
    char procurado[15];
    fp = fopen("lista.dat", "rb");

    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    printf("\n\n");
    system ( " cls  || clear " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                   Buscar dados da lista                   | \n");
    printf(" | ========================================================= | \n");
    printf("Informe o seu username: ");
    scanf(" %30[^\n]", procurado);
    getchar();
    mtlista = (MontarLista*) malloc(sizeof(MontarLista));
    cliente = (Usuario*) malloc(sizeof(Usuario));
    achou = 0;
    while((!achou) && (fread(mtlista, sizeof(MontarLista), 1, fp))) {
        if ((strcmp(cliente->usernameUsuario, procurado) == 0) && (cliente->status == '1')) {
            achou = 1;
        }
    }
    fclose(fp);
    if (achou) {
        system(" cls || clear");
        printf(" | =================== Lista encontrada ==================== |\n");
        printf(" |                                                           |\n");
        printf(" | Nome do produto: %s\n", mtlista->nome);
        printf(" | Quantidade do produto: %s\n", mtlista->quantidadeProduto);
        printf(" | Status: %c\n", mtlista->status);
        printf(" |                                                           | \n");
        printf(" | ========================================================= | \n");
        printf(" | Pressione qualquer tecla para sair.... ");
        getchar();
    
    } else {
        printf("Os dados da lista %s não foram encontrados\n", procurado);
    }
    free(mtlista);
    free(cliente);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    return 0;
    
}

void exibeListaCompras(MontarLista* mtlista) 
{
    system(" cls || clear");
    printf(" | =================== Lista cadastrada ==================== |\n");
    printf(" |                                                           | \n");
    printf(" | Nome do produto: %s\n", mtlista->nome);
    printf(" | Quantidade do produto: %s\n", mtlista->quantidadeProduto);
    printf(" | Status: %c\n", mtlista->status);
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    
}

//função para edição
int atualizarLista(void) 
{
    FILE* fp;
    Usuario* cliente;
    MontarLista* mtlista;
    char resp;
    int achou;
    char procurado[20];

    fp = fopen("usuario.dat", "r+b");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }

    fp = fopen("lista.dat", "r+b");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }
    
    cliente = (Usuario*) malloc(sizeof(Usuario));
    mtlista = (MontarLista*) malloc(sizeof(MontarLista));

    system(" cls || clear ");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------------- Atualizar lista -------------------- | \n");
    printf("Informe o seu username: ");
    scanf(" %s", procurado);
    getchar();
    achou = 0;
    while((!achou) && (fread(cliente, sizeof(Usuario), 1, fp))) {
        if ((strcmp(cliente->usernameUsuario, procurado) == 0) && (cliente->status == '1')) {
            achou = 1;
    }
    if (achou){

        exibeListaCompras(mtlista);
        resp = escAtualizarLista();
        printf("\n");

        if (resp == '1'){
            do
            {
                printf("Informe o novo nome do produto: ");
                scanf("%49[^\n]", mtlista->nome);
                getchar();

            } while(!validarLetras(mtlista->nome, tamanhoString(mtlista->nome)));

            do
            {
                printf("Informe a nova quantidade de produto: ");
                scanf(" %s", mtlista->quantidadeProduto);
                getchar();

            } while(!lerQuantidade(mtlista->quantidadeProduto));

        }

        else if (resp == '2'){
            do
            {
                printf("Informe o novo nome do produto: ");
                scanf("%49[^\n]", mtlista->nome);
                getchar();

            } while(!validarLetras(mtlista->nome, tamanhoString(mtlista->nome)));  
        }

        else if (resp == '3'){
            do
            {
                printf("Informe a nova quantidade de produto: ");
                scanf("%s", mtlista->quantidadeProduto);
                getchar();

            } while(!lerQuantidade(mtlista->quantidadeProduto));
        }

        mtlista->status = '1';      
        fseek(fp, (-1)*sizeof(MontarLista), SEEK_CUR);
        fwrite(mtlista, sizeof(MontarLista), 1, fp);        
        printf(" |                                                           | \n");
        printf(" | --------------------------------------------------------- | \n");
        printf("Dados editados com sucesso");
    }
    
    else 
    {   
        
        printf("A lista do usuário de username %s não foi encontrada\n", procurado);
    }
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    free(mtlista);
    free(cliente);
    fclose(fp); 
        

    } 
    return 0;
}

char escAtualizarLista(void) 
{
    char esc;
    system(" cls || clear");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------------- Atualizar lista -------------------- | \n");
    printf(" |                                                           | \n");
    printf(" |                 1- Editar tudo                            | \n");
    printf(" |                 2- Editar nome                            | \n");
    printf(" |                 3- Editar quantidade de produto           | \n");
    printf(" |                 0- Voltar à tela principal                | \n");    
    printf(" |                                                           | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | Selecione uma opção do que você deseja editar: ");
    scanf("%c", &esc);
    getchar();

    return esc;

}

//Função para exclusão lógica
int excluirLista(void)
{
    FILE* fp;
    MontarLista* mtlista;
    Usuario* cliente;
    int achou;
    char resp;
    char procura[20];
    fp = fopen("lista.dat", "r+b");

    if (fp == NULL){
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }

    fp = fopen("usuario.dat", "r+b");

    if (fp == NULL){
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    
    mtlista = (MontarLista*) malloc(sizeof(MontarLista));
    cliente = (Usuario*) malloc(sizeof(Usuario));
    system( " clear || cls ");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ------------------------ Excluir lista ----------------------- | \n");
    printf(" |                                                                | \n");
    printf(" | Informe o seu username para procurar a lista que você deseja excluir: ");
    scanf("%s", procura);
    getchar();  
    achou = 0;
    while ((!achou) && (fread(mtlista, sizeof(MontarLista), 1, fp))){
        if ((strcmp(cliente->usernameUsuario, procura) == 0) && (cliente->status == '1')){
            achou = 1;
        }
    }

   if (achou){
        exibeListaCompras(mtlista);
        getchar();
        printf("Deseja realmente excluir os dados desta lista? (s/n)");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S'){
            mtlista->status = '0';
            fseek(fp, (-1)*sizeof(MontarLista), SEEK_CUR);
            fwrite(mtlista, sizeof(mtlista), 1, fp);
            printf("\nLista excluída com sucesso!");
            gravaLista(mtlista);
            gravaUsuario(cliente);
            printf(" Pressione qualquer tecla para sair... ");
            getchar();
        }else{
            printf("\nTudo bem, a lista não foi alterada!");
        }
    }else{
        printf("A lista não foi encontrada!");
    }
    free(mtlista);
    free(cliente);
    fclose(fp);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    return 0;
    
}

//listar a lista pronta
int listaComprasPronta(void) 
{
    FILE* fp;
    MontarLista* mtlista;
    fp = fopen("lista.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    printf("\n\n");
    printf(" | ===================== Exibe lista ======================= | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    mtlista = (MontarLista*)malloc(sizeof(MontarLista));
    while(fread(mtlista, sizeof(MontarLista), 1, fp)) {
        exibeListaCompras(mtlista);
    }
    fclose(fp);
    free(mtlista);
    return 0;
}