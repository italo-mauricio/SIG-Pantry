#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modulolistadeCompras.h"
#include "validacoes.h"
#include "modulocadastroUsuario.h"
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
char telaListadeCompras(void)
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | -------------------| SIG-Pantry - LISTA DE COMPRAS |---------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |             1- Visualizar itens no estoque com quantidade mínima     | \n");
    printf(" |             2- Montar sua lista de compras                           | \n");
    printf(" |             3- Pesquisar lista de compras                            | \n");      
    printf(" |             4- Editar lista de compras                               | \n");      
    printf(" |             5- Excluir lista de compras                              | \n");      
    printf(" |             6- Visualizar itens cadastrados na lista                 | \n");       
    printf(" |             0- Voltar à tela principal                               | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &opcao);
    getchar();

    return opcao;

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
    Usuario* cliente;
    MontarLista* mtlista;
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
    
    cliente = (Usuario*) malloc(sizeof(Usuario));
    mtlista = (MontarLista*)malloc(sizeof(MontarLista)); 

    system ( " cls || clear " );
    printf("| ============================================================= | \n");
    printf("| ------------------------------------------------------------- | \n");
    printf("| ------------- | Montar a sua lista de compras | ------------- | \n");
    printf("|                                                               | \n");  
    printf("| Informe o seu username: ");
    scanf(" %30[^\n]", procurado);
    getchar();
    achou = 0;

    while((!achou) && (fread(cliente, sizeof(Usuario), 1, fp))) {
        if ((strcmp(cliente->usernameUsuario, procurado) == 0) && (cliente->status == '1')) {
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
                scanf("%s", mtlista->nome);
                getchar();
                
            } while (!validarLetras(mtlista->nome, tamanhoString(mtlista->nome)));

            do 
            {
                printf(" | Informe a quantidade de produto: ");
                scanf("%s", produto);
                getchar();
            
            } while (!lerQuantidade(produto));
            list = charParaInt(produto);
            mtlista->quantidadeProduto = list;
            mtlista->status = '1';
            gravaLista(mtlista);
            free(mtlista);
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
int gravaLista(MontarLista* mtlista) 
{
    FILE* fp2;
    fp2 = fopen("lista.dat", "ab");
    
    if (fp2 == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        return 0;
    
    }    
    fwrite(mtlista, sizeof(MontarLista), 1, fp2);
    fclose(fp2);
    return 0;    
}



//função de pesquisa a partir do username (id do usuário)
int buscarLista(void)
{
    FILE* fp2;
    MontarLista* mtlista;
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
    mtlista = (MontarLista*) malloc(sizeof(MontarLista));
    achou = 0;
    

     while((!achou) && (fread(mtlista, sizeof(MontarLista), 1, fp2))) {
         
        if ((strcmp(mtlista->nome, procurado) == 0) && (mtlista->status == '1')) {
            achou = 1;
        }
    
    }  
    if (achou) {
        system(" cls || clear");
        printf(" | =================== Lista encontrada ==================== |\n");
        printf(" |                                                           |\n");
        printf(" | Nome do produto: %s\n", mtlista->nome);
        printf(" | Quantidade do produto: %d\n", mtlista->quantidadeProduto);
        printf(" | Status: %c\n", mtlista->status);
        printf(" |                                                           | \n");
        printf(" | ========================================================= | \n");
        printf(" | Pressione qualquer tecla para sair.... ");
        getchar();
    
    } else {
        
        printf("Os dados da lista %s não foram encontrados\n", procurado);
    
    }  
    free(mtlista);
    fclose(fp2);  
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    return 0;
    
}


//função para exibição do que contém na lista
void exibeListaCompras(MontarLista* mtlista) 
{
    system(" cls || clear");
    printf(" | =================== Lista cadastrada ==================== |\n");
    printf(" |                                                           | \n");
    printf(" | Nome do produto: %s\n", mtlista->nome);
    printf(" | Quantidade do produto: %d\n", mtlista->quantidadeProduto);
    printf(" | Status: %c\n", mtlista->status);
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();    
}


//função para edição
int atualizarLista(void) 
{

    FILE* fp2;
    MontarLista* mtlista;
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

    mtlista = (MontarLista*) malloc(sizeof(MontarLista));
    system(" cls || clear ");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------------- Atualizar lista -------------------- | \n");
    printf("Informe o nome do produto: ");
    scanf("%s", procurado);
    getchar(); 
    achou = 0;

    while((!achou) && (fread(mtlista, sizeof(MontarLista), 1, fp2))) {
        if ((strcmp(mtlista->nome, procurado) == 0) && (mtlista->status == '1')) {
            achou = 1;
    }
    if (achou){
        exibeListaCompras(mtlista);
        resp = escAtualizarLista();
        printf("\n");

        if (resp == '1'){
       
            printf("Informe o novo nome do produto: ");
            scanf("%49[^\n]", mtlista->nome);
            getchar();

            do
            {
                printf("Informe a nova quantidade de produto: ");
                scanf(" %s", produto);
                getchar();

            } while(!lerQuantidade(produto));
            list = charParaInt(produto);
            mtlista->quantidadeProduto = list;

        }
        else if (resp == '2'){
            
            printf("Informe o novo nome do produto (sem acentuação): ");
            scanf("%49[^\n]", mtlista->nome);
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
            mtlista->quantidadeProduto = list;    
        }

        mtlista->status = '1';      
        fseek(fp2, (-1)*sizeof(MontarLista), SEEK_CUR);
        fwrite(mtlista, sizeof(MontarLista), 1, fp2);        
        printf(" |                                                           | \n");
        printf(" | --------------------------------------------------------- | \n");
        printf("Dados editados com sucesso");
        
   
    }else {   
        
        printf("A lista do usuário de username %s não foi encontrada\n", procurado);
    
    }   
    
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();       
    
    }   
    gravaLista(mtlista);   
    free(mtlista);
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
    MontarLista* mtlista;
    Usuario* cliente;
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
    
    while ((!achou) && (fread(mtlista, sizeof(MontarLista), 1, fp2))){
        if ((strcmp(cliente->usernameUsuario, procura) == 0) && (cliente->status == '1')){
            achou = 1;
        }
    }
    
    if (achou){
        
        exibeListaCompras(mtlista);
        getchar();
        printf(" | Deseja realmente excluir os dados desta lista? (s/n) ");
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
    fclose(fp2);  
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    
    return 0;
    
}


//relatório da lista pronta
int listaComprasPronta(void) 
{
    FILE* fp2;
    MontarLista* mtlista;
    
    fp2 = fopen("lista.dat", "rb");
    
    if (fp2 == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    
    printf("\n\n");
    printf(" | ===================== Exibe lista ======================= | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");

    mtlista = (MontarLista*)malloc(sizeof(MontarLista));
    
    while(fread(mtlista, sizeof(MontarLista), 1, fp2)) {
        exibeListaCompras(mtlista);
    } 
    fclose(fp2);
    free(mtlista);
    
    return 0;

}