#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shoppingListModule.h"
#include "validacoes.h"
#include "userRegistrationModule.h"
#include "moduloMenuItem.h"


/*
              Bem-vindo(a) ao módulo de lista de compras!
        
             Neste módulo será feita a lista de compras 

*/


typedef struct item Item;

//função de navegação principal do módulo
void shoppingListMenu(void)
{
    char choice;
    do {
        choice = shoppingListScreen();
        switch (choice) {
        case '1':
            itemsMinimumQuant(); //lista itens que estão acabando no estoque 
            break; 
        case '2':
            infoBuildList(); //preenche lista
            break;
        case '3':
            searchListByProduct(); //pesquisa
            break; 
        case '4':
            updateList(); //edição
            break;  
        case '5':
            deleteList(); //exclusão
            break;
        case '6':
            readyShoppingList(); //exibição da lista pronta (relatório)
            break;
        default:
            printf("Invalid Option\n");
            break;

        }

    } while(choice != '0');
        
        printf("Thank you!");

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
    printf("|             0- Back to main screen                                   | \n");
    printf("|                                                                      | \n");
    printf("| ==================================================================== | \n");
    printf("| Choose an option: ");
    scanf("%c", &option);
    getchar();

    return option;
}


//função que lista os itens que estão acabando no estoque
int itemsMinimumQuant(void)     
{
    FILE* fp3;
    Item* it;  
    fp3 = fopen("items.dat", "rt"); // Only need to open the item file, as it will retrieve information from this file.
    
    if (fp3 == NULL)
    {
        printf("An error occurred while opening the file.");
        return 0;
    }
    it = (Item*)malloc(sizeof(Item));
    
    while(fread(it, sizeof(Item), 1, fp3)) {
        if (it->quantProduct <= it->minimumInventory) {
            system( " clear || cls ");
            printf(" | ============================================================== | \n");
            printf(" | -------------------------------------------------------------- | \n");
            printf(" | --------- Items with minimum quantity in the pantry ----------- | \n");
            printf(" |                                                                | \n");
            displayItemInfo(it);

        }
    }
    free(it);
    fclose(fp3);
    
    return 0;

}

//função para a montagem da lista vinculada ao id do usuário
int infoBuildList(void) {
    FILE* fp;
    User* client;
    CreateList* list;
    int found;
    char searched[15];
    int resp;
    int i;
    char product[20];
    int listQuantity;

    fp = fopen("user.dat", "rb");

    if (fp == NULL) {
        printf("Oops! Error opening file!\n");
        return 0;
    }
    
    client = (User*) malloc(sizeof(User));
    list = (CreateList*)malloc(sizeof(CreateList)); 

    system("cls || clear");
    printf("| ============================================================= | \n");
    printf("| ------------------------------------------------------------- | \n");
    printf("| ------------- | Build your shopping list | ------------- | \n");
    printf("|                                                               | \n");  
    printf("| Enter your username: ");
    scanf(" %30[^\n]", searched);
    getchar();
    found = 0;

    while((!found) && (fread(client, sizeof(User), 1, fp))) {
        if ((strcmp(client->usernameUser, searched) == 0) && (client->status == '1')) {
            found = 1;
        }
    }
    if (found){
        printf("| Enter the number of items to be added to the list: ");
        scanf("%d", &resp);

        for (i = 1; i <= resp; i++) {
            do {
                printf(" | Enter the name of the product: "); 
                scanf("%s", list->name);
                getchar();
            } while (!validateLetters(list->name, stringLength(list->name)));

            do {
                printf(" | Enter the quantity of product: ");
                scanf("%s", product);
                getchar();
            } while (!readQuantity(product));
            listQuantity = charToInt(product);
            list->quantityProduct = listQuantity;
            list->status = '1';
            saveList(list);
            free(list);
        }  
    } else {
        printf("User data for %s not found\n", searched);
    }  
    printf("|                                                               | \n");
    printf("| ============================================================= | \n");
    free(client);
    fclose(fp);
    printf(" | Press any key to exit.... ");
    getchar();   
    return 0;
}


// function to save to file
int saveList(CreateList* mtlist)
{
    FILE* fp2;
    fp2 = fopen("list.dat", "ab");

 
    if (fp2 == NULL) {
        printf("Oops! An error occurred while opening the file!\n");
        return 0;

    }    
    fwrite(mtlist, sizeof(CreateList), 1, fp2);
    fclose(fp2);
    return 0;    
}


int searchListByProduct(void) {
    
    FILE *filePointer;
    CreateList *list;
    int found = 0;
    char searchKey[15];

    filePointer = fopen("list.dat", "rb");

    if (filePointer == NULL) {
        printf("Oops! Error opening file!\n");
        return 0;
    }   

    printf("\n\n");
    system("cls || clear");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                   Search List Data                        | \n");
    printf(" | ========================================================= | \n");
    printf("Enter the product name: ");
    scanf(" %30[^\n]", searchKey);
    getchar(); 
    list = (CreateList*) malloc(sizeof(CreateList));
    found = 0;

    while ((!found) && (fread(list, sizeof(CreateList), 1, filePointer))) {
        if ((strcmp(list->name, searchKey) == 0) && (list->status == '1')) {
            found = 1;
        }
    }  

    if (found) {
        system("cls || clear");
        printf(" | =================== List Found ==================== |\n");
        printf(" |                                                     |\n");
        printf(" | Product Name: %s\n", list->name);
        printf(" | Product Quantity: %d\n", list->quantityProduct);
        printf(" | Status: %c\n", list->status);
        printf(" |                                                     | \n");
        printf(" | ===================================================== | \n");
        printf(" | Press any key to exit.... ");
        getchar();
    } else {
        printf("List data for %s was not found.\n", searchKey);
    }

    free(list);
    fclose(filePointer);  
    printf(" | Press any key to exit.... ");
    getchar();
    return 0;
}

//função para exibição do que contém na lista
void displayShoppingList(CreateList *list) {
    system("cls || clear");
    printf(" | =================== Registered List ==================== |\n");
    printf(" |                                                           | \n");
    printf(" | Product Name: %s\n", list->name);
    printf(" | Product Quantity: %d\n", list->quantityProduct);
    printf(" | Status: %c\n", list->status);
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press any key to exit.... ");
    getchar();    
}


//função para edição
int updateList(void) 
{
    FILE* fp;
    CreateList* mtlist;
    char response;
    int found;
    char search[15];
    char product[20];
    int quantity;
  
    fp = fopen("list.dat", "r+b");
    
    if (fp == NULL) 
    {
        printf("Ops! An error occurred while opening the file!\n");
        return 0;
    } 

    mtlist = (CreateList*) malloc(sizeof(CreateList));
    system("cls || clear");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------------- Update List ------------------------ | \n");
    printf("Enter the product name: ");
    scanf("%s", search);
    getchar(); 
    found = 0;

    while((!found) && (fread(mtlist, sizeof(CreateList), 1, fp))) {
        if ((strcmp(mtlist->name, search) == 0) && (mtlist->status == '1')) {
            found = 1;
        }
    }
    if (found){
        exibeListaCompras(mtlist);
        response = escAtualizarLista();
        printf("\n");

        if (response == '1'){
            printf("Enter the new product name: ");
            scanf("%49[^\n]", mtlist->name);
            getchar();

            do
            {
                printf("Enter the new quantity of product: ");
                scanf(" %s", product);
                getchar();

            } while(!lerQuantidade(product));
            quantity = charParaInt(product);
            mtlist->quantityProduct = quantity;

        }
        else if (response == '2'){
            
            printf("Enter the new product name (without accentuation): ");
            scanf("%49[^\n]", mtlist->name);
            getchar();

        }
        else if (response == '3'){
            do
            {
                printf("Enter the new quantity of product: ");
                scanf("%s", product);
                getchar();

            } while(!lerQuantidade(product));
            quantity = charParaInt(product);
            mtlist->quantityProduct = quantity;    
        }

        mtlist->status = '1';      
        fseek(fp, (-1)*sizeof(CreateList), SEEK_CUR);
        fwrite(mtlist, sizeof(CreateList), 1, fp);        
        printf(" |                                                           | \n");
        printf(" | --------------------------------------------------------- | \n");
        printf("Data edited successfully");
        
   
    }else {   
        
        printf("The list for the username %s was not found\n", search);
    
    }   
    
    printf(" | Press any key to exit.... ");
    getchar();       
      
    gravaLista(mtlist);   
    free(mtlist);
    fclose(fp); 

    return 0;

}


//função para escolha do que deseja editar
char screenUpdateList(void) 
{
    char esc;
    system(" cls || clear");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------------- Update list ------------------------ | \n");
    printf(" |                                                           | \n");
    printf(" |                 1- Edit all                               | \n");
    printf(" |                 2- Edit name                              | \n");
    printf(" |                 3- Edit product quantity                  | \n");
    printf(" |                 0- Return to main screen                   | \n");    
    printf(" |                                                           | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | Select an option of what you want to edit: ");
    scanf("%c", &esc);
    getchar();

    return esc;
}

//Função para exclusão lógica
int deleteList(void)
{
    FILE* fp;
    FILE* fp2;
    CreateList* mtlist;
    User* client;
    int found;
    char resp;
    char search[20];


    fp2 = fopen("list.dat", "r+b");

    if (fp2 == NULL){
        printf("Oops! Error opening file!\n");
        return 0;
    }

    fp = fopen("user.dat", "r+b");

    if (fp == NULL){
        printf("Oops! Error opening file!\n");
        return 0;
    }  

    mtlist = (CreateList*) malloc(sizeof(CreateList));
    client = (User*) malloc(sizeof(User)); 

    system( " clear || cls ");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ------------------------ Delete list ------------------------- | \n");
    printf(" |                                                                | \n");
    printf(" | Enter your username to search for the list you want to delete: ");
    scanf("%s", search);
    getchar();    
    found = 0;

    while ((!found) && (fread(mtlist, sizeof(CreateList), 1, fp2))){
        if ((strcmp(client->usernameUser, search) == 0) && (client->status == '1')){
            found = 1;
        }
    }

    if (found){
        
        exibeListaCompras(mtlist);
        getchar();
        printf(" | Do you really want to delete the data in this list? (y/n) ");
        scanf("%c", &resp);
        
        if (resp == 'y' || resp == 'Y'){
            
            mtlist->status = '0';
            fseek(fp, (-1)*sizeof(CreateList), SEEK_CUR);
            fwrite(mtlist, sizeof(mtlist), 1, fp);
            printf("\nList deleted successfully!");
            gravaLista(mtlist);
            gravaUsuario(client);
            printf(" Press any key to exit... ");
            getchar();
        
        }else{
        
            printf("\nOkay, the list was not changed!");
        
        }

    }else{

        printf("The list was not found!");

    }  
    free(mtlist);
    free(client);
    fclose(fp);
    fclose(fp2);  
    printf(" | Press any key to exit.... ");
    getchar();

    return 0;

}
//relatório da lista pronta
int readyShoppingList(void)
{
    FILE* fp2;
    CreateList* mtlist;

    fp2 = fopen("list.dat", "rb");

    if (fp2 == NULL) {
        printf("Oops! Error opening the file!\n");
        return 0;
    }

    printf("\n\n");
    printf(" | ===================== Display List ======================= | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");

    mtlist = (CreateList*)malloc(sizeof(CreateList));

    while(fread(mtlist, sizeof(CreateList), 1, fp2)) {
        displayShoppingList(mtlist);
    } 
    fclose(fp2);
    free(mtlist);

    return 0;
}