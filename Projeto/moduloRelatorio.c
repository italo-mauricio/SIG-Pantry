#include <stdio.h>
#include <stdlib.h>
#include "moduloRelatorio.h"
#include <string.h>
#include "validacoes.h"
#include "moduloMenuItem.h"
#include "modulolistadeCompras.h"
#include "modulocadastroUsuario.h"


/*
              Bem-vindo(a) aos relatórios!
        
        Neste módulo serão mostrados os relatórios do projeto!


*/


//função principal de navegação
char moduloRelatorio(void)
{
    char escolha;
    NoItem* lista;
    do {
        escolha = telaRelatorio();
        switch (escolha) {
            case '1':
                escRelatoriosCategoria(); //com base na categoria selecionada
                break;
            case '2':
                escRelatoriosLocal(); //com base no local selecionado para armazenar
                break; 
            case '3':
                escRelatoriosTipo(); //com base no E e S do menu itens
                break;
            case '4':
                lista = listaOrdenadaItens(); //itens em ordem alfabética
                exibeOrdemItem(lista);
                break; 
            default :
                printf ("Opção inválida!");
                break;
        }

    } while(escolha != '0');
    return escolha;
}

// tela principal
char telaRelatorio(void)
{
    char esc;
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | -------------------| SIG-Pantry - RELATÓRIOS |---------------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |                 1- Estoque com base na categoria                     | \n");
    printf(" |                 2- Estoque com base no local de armazenamento        | \n");
    printf(" |                 3- Estoque com base no tipo                          | \n");
    printf(" |                 4- Itens em ordem alfabética                          | \n");
    printf(" |                 0- Voltar à tela principal                           | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    getchar();
    return esc;
}


//navegação da escolha da categoria
void escRelatoriosCategoria(void)
{
    char opcao;
    do
    {
        opcao = relatorioCategoria();
        switch (opcao)
        {
            case '1':
                exibirItensHigiene();
                break; 
            case '2':
                exibirItensLimpeza();
                break;
            case '3':
                exibirItensAlimento();
                break;
        }

    } while (opcao != '0');

} 


//função para selecionar uma das categorias
char relatorioCategoria(void)
{
    char esc;
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ---------------| Relatórios com base na categoria |----------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |               1- Relatório dos itens de higiene pessoal              | \n");
    printf(" |               2- Relatório dos itens de limpeza                      | \n");
    printf(" |               3- Relatório dos itens de alimento                     | \n");
    printf(" |               0- Voltar à tela principal                             | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    getchar();
    return esc;
}


//função para retornar o relatório dos itens de higiente
int exibirItensHigiene(void)
{
    FILE* fp;
    Item* it;
    int achou;
    
    fp = fopen("itens.dat", "rb");

    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }
    
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ------------| Relatório dos itens de higiene pessoal |-------------- | \n");
    printf(" |                                                                      | \n");
    it = (Item*) malloc(sizeof(Item));
    achou = 0;

    while((fread(it, sizeof(Item), 1, fp))){
        if (((it->categoria == '1')) && (it->status == '1')){
            exibeInfoItem(it);
            achou = 1;
        }

    }

    if (achou){
        
        return 0;
    
    } else {
        
        printf("ERRO");
    
    }
    free(it);
    fclose(fp);
    getchar();

    return 0;

} 


//função para retornar o relatório dos itens de limpeza
int exibirItensLimpeza(void)
{
    FILE* fp;
    Item* it;
    int achou;
    
    fp = fopen("itens.dat", "rb");

    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }
    
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | -----------------| Relatório dos itens de limpeza |----------------- | \n");
    printf(" |                                                                      | \n");
    it = (Item*) malloc(sizeof(Item));
    achou = 0;


    while((fread(it, sizeof(Item), 1, fp))){
        if (((it->categoria == '2')) && (it->status == '1')){
            exibeInfoItem(it);
            achou = 1;
        }

    } 
    if (achou){
        
        return 0;
    
    } else {
        
        printf("ERRO");
    
    }
    free(it);
    fclose(fp);
    getchar();

    return 0;
    
} 



//função para retornar o relatório dos itens de alimento
int exibirItensAlimento(void)
{
    FILE* fp;
    Item* it;

    int achou;

    fp = fopen("itens.dat", "rb");

    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }
    
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ----------------| Relatório dos itens de alimento |----------------- | \n");
    printf(" |                                                                      | \n");
    it = (Item*) malloc(sizeof(Item));
    achou = 0;

    while((fread(it, sizeof(Item), 1, fp))){
        if (((it->categoria == '3')) && (it->status == '1')){
            exibeInfoItem(it);
            achou = 1;
        }

    }    
    
    if (achou){
        
        return 0;
    
    } else {
        
        printf("ERRO");
    
    }
    free(it);
    fclose(fp);
    getchar();

    return 0;
    
} 


//navegação da escolha do local
void escRelatoriosLocal(void)
{
    char opcao;
    do
    {
        opcao = relatorioLocalArmaz();
        switch (opcao)
        {
            case '1':
                exibirGeladeira();
                break; 
            case '2':
                exibirArmarioCozinha();
                break;
            case '3':
                exibirAreaServ();
                break;
            case '4':
                exibirBanheiro();
                break;  
            case '5':
                exibirGuardaRoupa();
                break;      
        }

    } while (opcao != '0');

} 


char relatorioLocalArmaz(void)
{
    char esc;
    system (" Clear||cls ");
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ---------- | Relatórios com base no local de armazenamento | ------- | \n");
    printf(" |                                                                      | \n");
    printf(" |                 1- Geladeira                                         | \n");
    printf(" |                 2- Armário da cozinha                                | \n");
    printf(" |                 3- Área de serviço                                   | \n");
    printf(" |                 4- Banheiro                                          | \n");
    printf(" |                 5- Guarda-roupa                                      | \n");
    printf(" |                 0- Voltar à tela principal                           | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    getchar();
    return esc;

}


//função para retornar o relatório dos itens da geladeira
int exibirGeladeira(void)
{
    FILE* fp;
    Item* it;
    int achou;

    fp = fopen("itens.dat", "rb");

    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }
    
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ----------------| Relatório dos itens da geladeira |---------------- | \n");
    printf(" |                                                                      | \n");
    it = (Item*) malloc(sizeof(Item));
    achou = 0;

    while((fread(it, sizeof(Item), 1, fp))){
        if (((it->localArmazenamento == '1')) && (it->status == '1')){
            exibeInfoItem(it);
            achou = 1;

        }

    } 
    
    if (achou){
        
        return 0;
    
    } else {
        
        printf("ERRO");
  
    
    }
    free(it);
    fclose(fp);
    getchar();
    return 0;
    
} 


//função para retornar o relatório dos itens do armário da cozinha
int exibirArmarioCozinha(void)
{
    FILE* fp;
    Item* it;
    int achou;
    
    fp = fopen("itens.dat", "rb");

    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }
    
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ----------| Relatório dos itens do armário da cozinha |------------- | \n");
    printf(" |                                                                      | \n");
    it = (Item*) malloc(sizeof(Item));
    achou = 0;

    while((fread(it, sizeof(Item), 1, fp))){
        if (((it->localArmazenamento == '2')) && (it->status == '1')){
            exibeInfoItem(it);
            achou = 1;
            
        }

    }  
    
    if (achou){
        
        return 0;
    
    } else {
        
        printf("ERRO");

    
    }
    free(it);
    fclose(fp);
    getchar();
    return 0;
    
}



//função para retornar o relatório dos itens da área de serviço
int exibirAreaServ(void)
{
    FILE* fp;
    Item* it;
    int achou;
    
    fp = fopen("itens.dat", "rb");

    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }
    
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ------------| Relatório dos itens do área de serviço |-------------- | \n");
    printf(" |                                                                      | \n");
    it = (Item*) malloc(sizeof(Item));
    achou = 0;


    while((fread(it, sizeof(Item), 1, fp))){
        if (((it->localArmazenamento == '3')) && (it->status == '1')){
            exibeInfoItem(it);
            achou = 1;
            
        }

    }   
    
    if (achou){
        
        return 0;
    
    } else {
        
        printf("ERRO");
    
    }
    free(it);
    fclose(fp);
    getchar();

    return 0;
    
}



//função para retornar o relatório dos itens do guarda-roupa
int exibirGuardaRoupa(void)
{
    FILE* fp;
    Item* it;
    int achou;
    
    fp = fopen("itens.dat", "rb");

    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }
    
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | --------------| Relatório dos itens do guarda-roupa |--------------- | \n");
    printf(" |                                                                      | \n");
    it = (Item*) malloc(sizeof(Item));
    achou = 0;


    while((fread(it, sizeof(Item), 1, fp))){
        if (((it->localArmazenamento == '5')) && (it->status == '1')){
            exibeInfoItem(it);
            achou = 1;
            
        }

    }  
    
    if (achou){
        
        return 0;
    
    } else {
        
        printf("ERRO");

    
    }
    free(it);
    fclose(fp);
    getchar();
    return 0;
    
}



//função para retornar o relatório dos itens do banheiro
int exibirBanheiro(void)
{
    FILE* fp;
    Item* it;
    int achou;
    
    fp = fopen("itens.dat", "rb");

    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }
    
    system ( " clear||cls " );
    printf(" | ========================================================================= | \n");
    printf(" | ------------------------------------------------------------------------- | \n");
    printf(" | ----------------| Relatório dos itens do banheiro |---------------------- | \n");
    printf(" |                                                                           | \n");
    it = (Item*) malloc(sizeof(Item));
    achou = 0;

    while((fread(it, sizeof(Item), 1, fp))){
        if (((it->localArmazenamento == '4')) && (it->status == '1')){
            exibeInfoItem(it);
            achou = 1;
            
        }

    }    
    
    if (achou){
        
        return 0;
    
    } else {
        
        printf("ERRO");
    
    }
    free(it);
    fclose(fp);
    getchar();
    return 0;
    
}



//navegação da escolha do tipo -> VER SE TIPO TEM QUE FICAR NO STRUCT DE ITEM TBM
/*void escRelatoriosTipo(void)
{
    char opcao;
    do
    {
        opcao = relatoriopeloTipo();
        switch (opcao)
        {
            case '1':
                exibirEntrada();
                break; 
            case '2':
                exibirSaida();
                break;    
        }

    } while (opcao != '0');

} 



//função para exibir os itens que entraram/saíram
char relatoriopeloTipo(void)
{
    char esc;
    system (" Clear||cls ");
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | -------------- | Relatório do estoque com base no tipo | ----------- | \n");
    printf(" |                                                                      | \n");
    printf(" |                    1- Itens que entraram (E)                         | \n");
    printf(" |                    2- Itens que saíram (S)                           | \n");
    printf(" |                    0- Voltar à tela principal                        | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    return esc;

}
/*

/*
//função para retornar o relatório dos itens que entraram
int exibirEntrada(void)
{
    FILE* fp;
    Mov* mv;
    int achou;
    
    fp = fopen("movimento.dat", "rb");

    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }
    
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ----------| Relatório dos itens que entraram na despensa |---------- | \n");
    printf(" |                                                                      | \n");
    mv = (Mov*) malloc(sizeof(Mov));
    achou = 0;

    while((fread(mv, sizeof(Item), 1, fp))){
        if (((mv->tipo == '1'))) {
            exibeInfoItem(it);
            achou = 1;
            
        }

    }
    
    if (achou){
        
        return 0;
    
    } else {
        
        printf("ERRO");
    
    }

    free(mv);
    fclose(fp);
    getchar();
    return 0;
    
}
*/

//função para retornar o relatório dos itens que saíram
/*int exibirSaida(void)
{
    FILE* fp;
    Mov* mv;
    int achou;
    
    fp = fopen("movimento.dat", "rb");
    
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }

    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | -----------| Relatório dos itens que saíram da despensa |----------- | \n");
    printf(" |                                                                      | \n");
    mv = (Mov*) malloc(sizeof(Mov));
    achou = 0;

    while((fread(mv, sizeof(Item), 1, fp))){
        if (((mv->tipo == '2'))) {
            exibeInfoItem(it);
            achou = 1;
            
        }

    }  
    if (achou){
        
        return 0;
    
    } else {
        
        printf("ERRO");
    
    }
    free(mv);
    fclose(fp);
    getchar();
    return 0;
    
}*/

//função para ordenar os itens em ordem alfabética
NoItem* listaOrdenadaItens(void) //adaptada by @flgorgonio
{
    FILE* fp;
    Item* it;
    NoItem* novoItem;
    NoItem* lista;

    lista = NULL;
    
    fp = fopen("itens.dat", "rb");
    
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }

    it = (Item*) malloc(sizeof(Item));
    
    while(fread(it, sizeof(Item), 1, fp)) 
    {        
        if (it->status == '1') {
            novoItem = (NoItem*) malloc(sizeof(NoItem));
            strcpy(novoItem->nomeProduto, it->nomeProduto);
            strcpy(novoItem->nomeMarca, it->nomeMarca);
            strcpy(novoItem->codigoBarras, it->codigoBarras);
            strcpy(novoItem->dia, it->dia);
            strcpy(novoItem->mes, it->mes);
            strcpy(novoItem->ano, it->ano);
            strcpy(novoItem->estoqueMinimo, it->estoqueMinimo);
            novoItem->categoria = it->categoria;
            novoItem->localArmazenamento = it->localArmazenamento;
            novoItem->status = it->status;
            strcpy(novoItem->quantProduto, it->quantProduto);

            if (lista == NULL){
                lista = novoItem
                novoItem->prox = NULL;
            }
            
            else if (strcmp(novoItem>nomeProduto, lista->nomeProduto) < 0){
                novoItem->prox = lista;
                lista = novoItem;
            }
            
            else
            {
                NoItem* anter = lista;
                NoItem* atual = lista->prox;
                
                while ((atual != NULL) && strcmp(atual->nomeProduto, novoItem->nomeProduto < 0)){
                    anter = atual;
                    atual = atual->prox;
                }

                anter->prox = novoItem;
                novoItem->prox = atual;
            }           
        }
    }
    
    fclose(fp);
    free(it);
    
    return lista;

}

void exibeOrdemItem(NoItem* lista)
{
    while (lista != NULL){    
        
        char aux[20];
        char aux2[20];
        if (it->categoria == '1'){
            strcpy(aux, "Higiene pessoal");
        
        }else if(it->categoria == '2'){
            strcpy(aux, "Limpeza");
        
        }else{
            strcpy(aux, "Alimento");
        }

        if (it->localArmazenamento == '1'){
            strcpy(aux2, "Geladeira");
        
        }else if(it->localArmazenamento == '2'){
            strcpy(aux2, "Armário de cozinha");
        
        }else if(it->localArmazenamento == '3'){
            strcpy(aux2, "Área de serviço");        
        
        }else if(it->localArmazenamento == '4'){
            strcpy(aux2, "Banheiro");          
        
        }else{
            strcpy(aux2, "Guarda-roupa");
        }

        printf(" | ========================================================= | \n");
        printf(" |                                                           | \n");
        printf(" | Nome do produto: %s\n", lista->nomeProduto);    
        printf(" | Nome da marca: %s\n", lista->nomeMarca);    
        printf(" | Código de barras: %s\n", lista->codigoBarras);    
        printf(" | Estoque mínimo do produto: %d\n", lista->estoqueMinimo);
        printf(" | Data de vencimento: %d/%d/%d\n", lista->dia, lista->mes, lista->ano); 
        printf(" | Categoria do produto: %s\n", aux);
        printf(" | Local de armazenamento: %s\n", aux2);
        printf(" | Quantidade do produto: %d\n", lista->quantProduto);
        printf(" | Status: %c\n", lista->status);
        printf(" |                                                           | \n");
        printf(" | ========================================================= | \n");
        printf(" | Pressione qualquer tecla para sair.... ");
        getchar();

            
        lista = lista->prox;
        
    }

}
