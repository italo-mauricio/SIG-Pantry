#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modulolistadeCompras.h"
#include "validacoes.h"
#include "userRegistrationModule.h"
#include "moduloMenuItem.h"


/*
              Bem-vindo(a) ao módulo de lista de compras!
        
             Neste módulo será feita a lista de compras 

*/


typedef struct item Item;

//função de navegação principal do módulo
void menulistadeCompras(void)
{
    char escolha;
    do {
        escolha = telaListadeCompras();
        switch (escolha) {
        case '1':
            itensQuantMinima(); //lista itens que estão acabando no estoque 
            break; 
        case '2':
            infoMontarLista(); //preenche lista
            break;
        case '3':
            buscarLista(); //pesquisa
            break; 
        case '4':
            atualizarLista(); //edição
            break;  
        case '5':
            excluirLista(); //exclusão
            break;
        case '6':
            listaComprasPronta(); //exibição da lista pronta (relatório)
            break;
        default:
            printf("Opção inválida\n");
            break;

        }

    } while(escolha != '0');
        
        printf("Obrigado, Volte sempre!");

} 


//tela principal de escolha
char shoppingListScreen(void)
{
    char option;
    system("clear||cls");
    printf("| ==================================================================== | \n");
    printf("| -------------------------------------------------------------------- | \n");
    printf("| -------------------| SIG-Pantry - SHOPPING LIST |------------------- | \n");
    printf("|                                                                      | \n");
    printf("|             1- View items in stock with minimum quantity             | \n");
    printf("|             2- Create your shopping list                             | \n");
    printf("|             3- Search shopping list                                  | \n");      
    printf("|             4- Edit shopping list                                    | \n");      
    printf("|             5- Delete shopping list                                  | \n");      
    printf("|             6- View items registered in the list                     | \n");       
    printf("|             0- Back to main screen                                    | \n");
    printf("|                                                                      | \n");
    printf("| ==================================================================== | \n");
    printf("| Choose an option: ");
    scanf("%c", &option);
    getchar();

    return option;
}


//função que lista os itens que estão acabando no estoque
int itensQuantMinima(void)     
{
    FILE* fp3;
    Item* it;  
    fp3 = fopen("itens.dat", "rt"); //só precisa abrir o de itens, pois irá resgatar informações desse arq
    
    if (fp3 == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo");
        return 0;
    }
    it = (Item*)malloc(sizeof(Item));
    
    while(fread(it, sizeof(Item), 1, fp3)) {
        if (it->quantProduto <= it->estoqueMinimo) {
            system( " clear || cls ");
            printf(" | ============================================================== | \n");
            printf(" | -------------------------------------------------------------- | \n");
            printf(" | --------- Itens com quantidade mínima na despensa ------------ | \n");
            printf(" |                                                                | \n");
            exibeInfoItem(it);

        }
    }
    free(it);
    fclose(fp3);
    
    return 0;

}


//função para a montagem da lista vinculada ao id do usuário
int infoMontarLista(void)
{
    FILE* fp;
    User* cliente;
    CreateList* mtlist;
    int achou;
    char procurado[15];
    int resp;
    int i;
    char produto[20];
    int list;

    fp = fopen("usuario.dat", "rb");

    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    
    cliente = (User*) malloc(sizeof(User));
    mtlist = (CreateList*)malloc(sizeof(CreateList)); 

    system ( " cls || clear " );
    printf("| ============================================================= | \n");
    printf("| ------------------------------------------------------------- | \n");
    printf("| ------------- | Montar a sua lista de compras | ------------- | \n");
    printf("|                                                               | \n");  
    printf("| Informe o seu username: ");
    scanf(" %30[^\n]", procurado);
    getchar();
    achou = 0;

    while((!achou) && (fread(cliente, sizeof(User), 1, fp))) {
        if ((strcmp(cliente->usernameUser, procurado) == 0) && (cliente->status == '1')) {
            achou = 1;
        }
    }
    if (achou){

        printf("| Informe quantos itens vão ser adicionados à lista: ");
        scanf("%d", &resp);

        for (i = 1; i <= resp; i++) {
            
            do
            {
                printf(" | Informe o nome do produto: "); 
                scanf("%s", mtlist->nome);
                getchar();
                
            } while (!validarLetras(mtlist->nome, tamanhoString(mtlist->nome)));

            do 
            {
                printf(" | Informe a quantidade de produto: ");
                scanf("%s", produto);
                getchar();
            
            } while (!lerQuantidade(produto));
            list = charParaInt(produto);
            mtlist->quantidadeProduto = list;
            mtlist->status = '1';
            gravaLista(mtlist);
            free(mtlist);
        }  
       
      
    
    } else {
        
        printf("Os dados do usuário %s não foram encontrados\n", procurado);
    
    }  
    printf("|                                                               | \n");
    printf("| ============================================================= | \n");
  
    free(cliente);
    fclose(fp);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();   
    return 0;

}



//função para gravar no arquivo
int gravaLista(CreateList* mtlist) 
{
    FILE* fp2;
    fp2 = fopen("lista.dat", "ab");
    
    if (fp2 == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        return 0;
    
    }    
    fwrite(mtlist, sizeof(CreateList), 1, fp2);
    fclose(fp2);
    return 0;    
}



//função de pesquisa a partir do username (id do usuário)
int buscarLista(void)
{
    FILE* fp2;
    CreateList* mtlist;
    int achou;
    char procurado[15];
    
    fp2 = fopen("lista.dat", "rb");

    if (fp2 == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    
    }   
    printf("\n\n");
    system ( " cls  || clear " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                   Buscar dados da lista                   | \n");
    printf(" | ========================================================= | \n");
    printf("Informe o nome do produto: ");
    scanf(" %30[^\n]", procurado);
    getchar(); 
    mtlist = (CreateList*) malloc(sizeof(CreateList));
    achou = 0;
    

     while((!achou) && (fread(mtlist, sizeof(CreateList), 1, fp2))) {
         
        if ((strcmp(mtlist->nome, procurado) == 0) && (mtlist->status == '1')) {
            achou = 1;
        }
    
    }  
    if (achou) {
        system(" cls || clear");
        printf(" | =================== Lista encontrada ==================== |\n");
        printf(" |                                                           |\n");
        printf(" | Nome do produto: %s\n", mtlist->nome);
        printf(" | Quantidade do produto: %d\n", mtlist->quantidadeProduto);
        printf(" | Status: %c\n", mtlist->status);
        printf(" |                                                           | \n");
        printf(" | ========================================================= | \n");
        printf(" | Pressione qualquer tecla para sair.... ");
        getchar();
    
    } else {
        
        printf("Os dados da lista %s não foram encontrados\n", procurado);
    
    }  
    free(mtlist);
    fclose(fp2);  
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    return 0;
    
}


//função para exibição do que contém na lista
void exibeListaCompras(CreateList* mtlist) 
{
    system(" cls || clear");
    printf(" | =================== Lista cadastrada ==================== |\n");
    printf(" |                                                           | \n");
    printf(" | Nome do produto: %s\n", mtlist->nome);
    printf(" | Quantidade do produto: %d\n", mtlist->quantidadeProduto);
    printf(" | Status: %c\n", mtlist->status);
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();    
}


//função para edição
int atualizarLista(void) 
{

    FILE* fp2;
    CreateList* mtlist;
    char resp;
    int achou;
    char procurado[15];
    char produto[20];
    int list;
  
    fp2 = fopen("lista.dat", "r+b");
    
    if (fp2 == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    } 

    mtlist = (CreateList*) malloc(sizeof(CreateList));
    system(" cls || clear ");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------------- Atualizar lista -------------------- | \n");
    printf("Informe o nome do produto: ");
    scanf("%s", procurado);
    getchar(); 
    achou = 0;

    while((!achou) && (fread(mtlist, sizeof(CreateList), 1, fp2))) {
        if ((strcmp(mtlist->nome, procurado) == 0) && (mtlist->status == '1')) {
            achou = 1;
    }
    if (achou){
        exibeListaCompras(mtlist);
        resp = escAtualizarLista();
        printf("\n");

        if (resp == '1'){
       
            printf("Informe o novo nome do produto: ");
            scanf("%49[^\n]", mtlist->nome);
            getchar();

            do
            {
                printf("Informe a nova quantidade de produto: ");
                scanf(" %s", produto);
                getchar();

            } while(!lerQuantidade(produto));
            list = charParaInt(produto);
            mtlist->quantidadeProduto = list;

        }
        else if (resp == '2'){
            
            printf("Informe o novo nome do produto (sem acentuação): ");
            scanf("%49[^\n]", mtlist->nome);
            getchar();

        }
        else if (resp == '3'){
            do
            {
                printf("Informe a nova quantidade de produto: ");
                scanf("%s", produto);
                getchar();

            } while(!lerQuantidade(produto));
            list = charParaInt(produto);
            mtlist->quantidadeProduto = list;    
        }

        mtlist->status = '1';      
        fseek(fp2, (-1)*sizeof(CreateList), SEEK_CUR);
        fwrite(mtlist, sizeof(CreateList), 1, fp2);        
        printf(" |                                                           | \n");
        printf(" | --------------------------------------------------------- | \n");
        printf("Dados editados com sucesso");
        
   
    }else {   
        
        printf("A lista do usuário de username %s não foi encontrada\n", procurado);
    
    }   
    
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();       
    
    }   
    gravaLista(mtlist);   
    free(mtlist);
    fclose(fp2); 

    return 0;

}


//função para escolha do que deseja editar
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
    FILE* fp2;
    CreateList* mtlist;
    User* cliente;
    int achou;
    char resp;
    char procura[20];

    fp2 = fopen("lista.dat", "r+b");

    if (fp2 == NULL){
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }

    fp = fopen("usuario.dat", "r+b");

    if (fp == NULL){
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }  
    
    mtlist = (CreateList*) malloc(sizeof(CreateList));
    cliente = (User*) malloc(sizeof(User)); 
    
    system( " clear || cls ");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ------------------------ Excluir lista ----------------------- | \n");
    printf(" |                                                                | \n");
    printf(" | Informe o seu username para procurar a lista que você deseja excluir: ");
    scanf("%s", procura);
    getchar();    
    achou = 0;
    
    while ((!achou) && (fread(mtlist, sizeof(CreateList), 1, fp2))){
        if ((strcmp(cliente->usernameUser, procura) == 0) && (cliente->status == '1')){
            achou = 1;
        }
    }
    
    if (achou){
        
        exibeListaCompras(mtlist);
        getchar();
        printf(" | Deseja realmente excluir os dados desta lista? (s/n) ");
        scanf("%c", &resp);
        
        if (resp == 's' || resp == 'S'){
            
            mtlist->status = '0';
            fseek(fp, (-1)*sizeof(CreateList), SEEK_CUR);
            fwrite(mtlist, sizeof(mtlist), 1, fp);
            printf("\nLista excluída com sucesso!");
            gravaLista(mtlist);
            gravaUsuario(cliente);
            printf(" Pressione qualquer tecla para sair... ");
            getchar();
        
        }else{
        
            printf("\nTudo bem, a lista não foi alterada!");
        
        }
    
    }else{
    
        printf("A lista não foi encontrada!");
    
    }  
    free(mtlist);
    free(cliente);
    fclose(fp);
    fclose(fp2);  
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    
    return 0;
    
}


//relatório da lista pronta
int listaComprasPronta(void) 
{
    FILE* fp2;
    CreateList* mtlist;
    
    fp2 = fopen("lista.dat", "rb");
    
    if (fp2 == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    
    printf("\n\n");
    printf(" | ===================== Exibe lista ======================= | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");

    mtlist = (CreateList*)malloc(sizeof(CreateList));
    
    while(fread(mtlist, sizeof(CreateList), 1, fp2)) {
        exibeListaCompras(mtlist);
    } 
    fclose(fp2);
    free(mtlist);
    
    return 0;

}