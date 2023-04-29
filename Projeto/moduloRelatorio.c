#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacoes.h"
#include "menuItemModule.h"
#include "moduloRelatorio.h"
#include "shoppingListModule.h"
#include "userRegistrationModule.h"
#include "clearScreen.c"


/*
              Bem-vindo(a) aos relatórios!
        
        Neste módulo serão mostrados os relatórios do projeto!


*/


//função principal de navegação
char moduloRelatorio(void)
{
    char choice;
    NoItem* list;
    do {
        choice = relatoryScreen();
        switch (choice) {
            case '1':
                menuCategory(); //com base na categoria selecionada
                break;
            case '2':
                menuLocalRelatory(); //com base no local selecionado para armazenar
                break; 
            case '3':
                list = listaOrdenadaItens(); //itens em ordem alfabética
                exibeOrdemItem(list);
                break; 
            default :
                printf ("Opção inválida!");
                break;
        }

    } while(choice != '0');
    
    return choice;

}


// tela principal
char relatoryScreen(void)
{
    char esc;
    clear();
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | --------------------| SIG-Pantry - REPORTS |------------------------ | \n");
    printf(" |                                                                      | \n");
    printf(" |                 1- Stock based on category                           | \n");
    printf(" |                 2- Stock based on storage location                   | \n");
    printf(" |                 3- Items in alphabetical order                       | \n");
    printf(" |                 0- Return to main menu                               | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Chooose an option: ");
    scanf("%c", &esc);
    getchar();
    
    return esc;

}


//navegação da escolha da categoria
void menuCategory(void)
{
    char choice;
    do
    {
        choice = relatoryCategory();
        switch (choice)
        {
            case '1':
                displayHygieneItens();
                break; 
            case '2':
                displayCleaningItens();
                break;
            case '3':
                displayFoodItens();
                break;
        }

    } while (choice != '0');

} 


//função para selecionar uma das categorias
char relatoryCategory(void)
{
    char esc;
    clear();
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ------------------|  Reports based on category |-------------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |               1- Report of personal hygiene items                    | \n");
    printf(" |               2- Report of cleaning items                            | \n");
    printf(" |               3- Report of food items                                | \n");
    printf(" |               0- Return to main screen                               | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Choose an option: ");
    scanf("%c", &esc);
    getchar();
    
    return esc;

}


//função para retornar o relatório dos itens de higiente
int displayHygieneItens(void)
{
    FILE* fp3;
    Item* it;
    int found;
        
    fp3 = fopen("itens.dat", "rb");

    if (fp3 == NULL) 
    {
        printf("Oops! An error occurred while opening the file!\n");
        return 0;
    }
        
    clear();
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ------------| Report of personal hygiene items |------------------ | \n");
    printf(" |                                                                      | \n");
    it = (Item*) malloc(sizeof(Item));
    found = 0;

    while((fread(it, sizeof(Item), 1, fp3))){
        if (((it->category == '1')) && (it->status == '1')){
            displayInfoItem(it);
            found = 1;
        }
    }

    if (found){
        return 0;
    } else {
        printf(" | No report to be displayed");
    }

    free(it);
    fclose(fp3);
    getchar();

    return 0;

} 


//função para retornar o relatório dos itens de limpeza
int displayCleaningItens(void)
{
    FILE* fp3;
    Item* it;
    int found;
        
    fp3 = fopen("itens.dat", "rb");

    if (fp3 == NULL) 
    {
        printf("Oops! An error occurred while opening the file!\n");
        return 0;
    }
        
    clear();
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | -----------------| Report of cleaning items |----------------------- | \n");
    printf(" |                                                                      | \n");
    it = (Item*) malloc(sizeof(Item));
    found = 0;


    while((fread(it, sizeof(Item), 1, fp3))){
        if (((it->category == '2')) && (it->status == '1')){
            displayInfoItem(it);
            found = 1;
        }
    } 
    if (found){
        return 0;
    } else {
        printf(" | No report to display");
    }
    free(it);
    fclose(fp3);
    getchar();

    return 0;
   
} 



//função para retornar o relatório dos itens de alimento
int displayFoodItens(void)
{
    FILE* fp3;
    Item* it;
    int found;

    fp3 = fopen("itens.dat", "rb");

    if (fp3 == NULL) 
    {
        printf("Oops! An error occurred while opening the file!\n");
        return 0;
    }

    clear();
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ----------------| Report of food items |----------------------------- | \n");
    printf(" |                                                                      | \n");
    it = (Item*) malloc(sizeof(Item));
    found = 0;

    while((fread(it, sizeof(Item), 1, fp3))){
        if (((it->category == '3')) && (it->status == '1')){
            displayInfoItem(it);
            found = 1;
        }

    }    

    if (found){

        return 0;

    } else {

        printf(" | No report to be displayed");

    }
    free(it);
    fclose(fp3);
    getchar();

    return 0;

    
} 


//navegação da escolha do local
void menuLocalRelatory(void)
{
    char choice;
    do
    {
        choice = relatorioLocalArmaz();
        switch (choice)
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

    } while (choice != '0');

} 


char relatorioLocalArmaz(void)
{
    char esc;
    clear();
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
    FILE* fp3;
    Item* it;
    int achou;

    fp3 = fopen("itens.dat", "rb");

    if (fp3 == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }
    
    clear();
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ----------------| Relatório dos itens da geladeira |---------------- | \n");
    printf(" |                                                                      | \n");
    it = (Item*) malloc(sizeof(Item));
    achou = 0;

    while((fread(it, sizeof(Item), 1, fp3))){
        if (((it->storageLocation == '1')) && (it->status == '1')){
            displayInfoItem(it);
            achou = 1;

        }

    } 
    
    if (achou){
        
        return 0;
    
    } else {
        
        printf(" | Nenhum relatório para ser exibido");
  
    
    }
    free(it);
    fclose(fp3);
    getchar();
    return 0;
    
} 


//função para retornar o relatório dos itens do armário da cozinha
int exibirArmarioCozinha(void)
{
    FILE* fp3;
    Item* it;
    int achou;
    
    fp3 = fopen("itens.dat", "rb");

    if (fp3 == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }
    
    clear();
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ----------| Relatório dos itens do armário da cozinha |------------- | \n");
    printf(" |                                                                      | \n");
    it = (Item*) malloc(sizeof(Item));
    achou = 0;

    while((fread(it, sizeof(Item), 1, fp3))){
        if (((it->storageLocation == '2')) && (it->status == '1')){
            displayInfoItem(it);
            achou = 1;
            
        }

    }  
    
    if (achou){
        
        return 0;
    
    } else {
        
        printf(" | Nenhum relatório para ser exibido");

    
    }
    free(it);
    fclose(fp3);
    getchar();
    return 0;
    
}


//função para retornar o relatório dos itens da área de serviço
int exibirAreaServ(void)
{
    FILE* fp3;
    Item* it;
    int achou;
    
    fp3 = fopen("itens.dat", "rb");

    if (fp3 == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }
    
    clear();
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ------------| Relatório dos itens do área de serviço |-------------- | \n");
    printf(" |                                                                      | \n");
    it = (Item*) malloc(sizeof(Item));
    achou = 0;


    while((fread(it, sizeof(Item), 1, fp3))){
        if (((it->storageLocation == '3')) && (it->status == '1')){
            displayInfoItem(it);
            achou = 1;
            
        }

    }   
    
    if (achou){
        
        return 0;
    
    } else {
        
        printf(" | Nenhum relatório para ser exibido");
    
    }
    free(it);
    fclose(fp3);
    getchar();

    return 0;
    
}



//função para retornar o relatório dos itens do guarda-roupa
int exibirGuardaRoupa(void)
{
    FILE* fp3;
    Item* it;
    int achou;
    
    fp3 = fopen("itens.dat", "rb");

    if (fp3 == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }
    
    clear();
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | --------------| Relatório dos itens do guarda-roupa |--------------- | \n");
    printf(" |                                                                      | \n");
    it = (Item*) malloc(sizeof(Item));
    achou = 0;


    while((fread(it, sizeof(Item), 1, fp3))){
        if (((it->storageLocation == '5')) && (it->status == '1')){
            displayInfoItem(it);
            achou = 1;
            
        }

    }  
    
    if (achou){
        
        return 0;
    
    } else {
        
        printf(" | Nenhum relatório para ser exibido");

    
    }
    free(it);
    fclose(fp3);
    getchar();
    return 0;
    
}


//função para retornar o relatório dos itens do banheiro
int exibirBanheiro(void)
{
    FILE* fp3;
    Item* it;
    int achou;
    
    fp3 = fopen("itens.dat", "rb");

    if (fp3 == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }
    
    clear();
    printf(" | ========================================================================= | \n");
    printf(" | ------------------------------------------------------------------------- | \n");
    printf(" | ----------------| Relatório dos itens do banheiro |---------------------- | \n");
    printf(" |                                                                           | \n");
    it = (Item*) malloc(sizeof(Item));
    achou = 0;

    while((fread(it, sizeof(Item), 1, fp3))){
        if (((it->storageLocation == '4')) && (it->status == '1')){
            displayInfoItem(it);
            achou = 1;
            
        }

    }    
    
    if (achou){
        
        return 0;
    
    } else {
        
        printf(" | Nenhum relatório para ser exibido");
    
    }
    free(it);
    fclose(fp3);
    getchar();
    return 0;
    
}


//função para ordenar os itens em ordem alfabética
NoItem* listaOrdenadaItens(void) //adaptada by @flgorgonio
{
    FILE* fp3;
    Item* it;
    NoItem* novoItem;
    NoItem* lista;

    lista = NULL;
    
    fp3 = fopen("itens.dat", "rb");
    
    if (fp3 == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }

    it = (Item*) malloc(sizeof(Item));
    
    while(fread(it, sizeof(Item), 1, fp3)) 
    {        
        if (it->status == '1') {
            novoItem = (NoItem*) malloc(sizeof(NoItem));
            strcpy(novoItem->nomeProduto, it->productName);
            strcpy(novoItem->nomeMarca, it->nameBrand);
            strcpy(novoItem->codigoBarras, it->barCode);
            novoItem->dia = it->day;
            novoItem->mes = it->month;
            novoItem->ano = it->year;
            novoItem->estoqueMinimo = it->minimumInventory;
            novoItem->categoria = it->category;
            novoItem->localArmazenamento = it->storageLocation;
            novoItem->status = it->status;
            novoItem->quantProduto = it->quantProduct;

            if (lista == NULL){
                lista = novoItem;
                novoItem->prox = NULL;
            }
            
            else if (strcmp(novoItem->nomeProduto, lista->nomeProduto) < 0){
                novoItem->prox = lista;
                lista = novoItem;
            }
            
            else
            {
                NoItem* anter = lista;
                NoItem* atual = lista->prox;
                
                while ((atual != NULL) && strcmp(atual->nomeProduto, novoItem->nomeProduto) < 0 ){
                    anter = atual;
                    atual = atual->prox;
                }

                anter->prox = novoItem;
                novoItem->prox = atual;
            }           
        }
    }
    
    fclose(fp3);
    free(it);
    
    return lista;

}

void exibeOrdemItem(NoItem* lista)
{
    while (lista != NULL){    
        
        Item* it;
        it = (Item*) malloc(sizeof(Item));
    
        char aux[20];
        char aux2[20];
        if (it->category == '1'){
            strcpy(aux, "Higiene pessoal");
        
        }else if(it->category == '2'){
            strcpy(aux, "Limpeza");
        
        }else{
            strcpy(aux, "Alimento");
        }

        if (it->storageLocation == '1'){
            strcpy(aux2, "Geladeira");
        
        }else if(it->storageLocation == '2'){
            strcpy(aux2, "Armário de cozinha");
        
        }else if(it->storageLocation == '3'){
            strcpy(aux2, "Área de serviço");        
        
        }else if(it->storageLocation == '4'){
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
