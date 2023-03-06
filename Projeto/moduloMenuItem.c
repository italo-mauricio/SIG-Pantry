#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloMenuItem.h"
#include "validacoes.h"
#include "userRegistrationModule.h"
#include "clearScreen.c"


/*
                Bem-vindo(a) ao módulo de cadastro de Itens

            Neste módulo será realizado o cadastro de itens no sistema


*/


//menu de navegação principal do módulo
void moduloMenuItem(void)
{
    char escolha;
    do {
        escolha = telaRegistrarItem();
        switch(escolha) {
            case '1':
                infoItem(); //informações do cad de um item novo
                break;
            case '2':
                buscaInfoItem(); //pesquisa
                break;
            case '3':
                telaAtualizarItem(); //edição
                break;
            case '4':
                excluirItem(); //exclusão
                break;
            case '5':
                entradaItem(); //adição de item
                break;
            case '6':
                saidaItem(); //retirada de item
                break;
            case '7':
                listarItens(); //relatório sem filtro
                break;     
            default:
                printf("Opção inválida\n");
                break;
        }
     
    } while (escolha != '0');

}


//função que chama a tela para o menu itens -> a partir da escolha do usuário
char screenRegisterItem(void)
{
    clear();
    char choice;
    printf("| ========================================================== | \n");
    printf("| ---------------------------------------------------------- | \n");
    printf("| --------------------- ITEMS MENU ------------------------- | \n");
    printf("|                                                            | \n");
    printf("|                 1- Register a new item                     | \n");
    printf("|                 2- Search for an item                      | \n");
    printf("|                 3- Update an item                          | \n");
    printf("|                 4- Delete an item                          | \n");
    printf("|                 5- Add an item                             | \n");
    printf("|                 6- Remove an item                          | \n");
    printf("|                 7- List items                              | \n");
    printf("|                 0- Back to main screen                     | \n");
    printf("|                                                            | \n");
    printf("| ========================================================== | \n");
    printf("| Choose an option: ");
    scanf("%c", &choice);
    getchar();

    return choice;
}


//função para cadastrar um novo item ao estoque
int infoItem(void)
{
    FILE *fp;
    Item *it;
    User *client;
    int inventory, inventoryMax, found;
    char *dateDay;
    char *dateMonth;
    char *dateYear;
    int dayControl, monthControl, yearControl;
    char quantity[20];
    char inventoryMin[20];
    char search[20];

    fp = fopen("user.dat", "rb");

    if (fp == NULL)
    {
        printf("Oops! Error opening file!\n");
        getchar();
        return 0;
    }

    it = (Item *)malloc(sizeof(Item));
    client = (User *)malloc(sizeof(User));

    clear();
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                    Register Item                          | \n");
    printf(" |                                                           | \n");
    printf(" | Please enter your username: ");
    scanf(" %30[^\n]", search);
    getchar();
    found = 0;

    while ((!found) && (fread(client, sizeof(User), 1, fp)))
    {
        if ((strcmp(client->usernameUser, search) == 0) && (client->status == '1'))
        {
                found = 1;
        }
    }

    if (found)
    {

        FILE *fp3;

        fp3 = fopen("itens.dat", "ab");

        if (fp3 == NULL)
        {
                printf("Oops! Error opening file!\n");
                getchar();
                return 0;
        }
        printf(" | Enter product name: ");
        scanf("%30[^\n]", it->productName);
        getchar();

        printf(" | Enter brand name: ");
        scanf("%30[^\n]", it->nameBrand);
        getchar();

        do
        {
                printf(" | Enter product barcode: ");
                scanf("%s", it->barCode);
                getchar();

        } while (!((lerQuantidade(it->barCode)) && (validaCod(it->barCode))));
        do
        {
                printf(" | Enter the minimum inventory of this product: ");
                scanf("%s", inventoryMin);
                getchar();

        } while (!lerQuantidade(inventoryMin));

        inventoryMax = charParaInt(inventoryMin);
        it->minimumInventory = inventoryMin;

        do
        {
                printf(" | Enter expiration date - day: ");
                scanf("%d", &it->day);
                getchar();
                printf(" | Enter expiration date - month: ");
                scanf("%d", &it->month);
                getchar();
                printf(" | Enter expiration date - year: ");
                scanf("%d", &it->year);
                getchar();
        } while (!valida_data(it->day, it->month, it->year));

        it->category = telaEscCategoria();
        it->storageLocation = telaEscLocalArmaz();

        do
        {

                printf(" | Enter the quantity of products: ");
                scanf("%s", quantity);
                getchar();

        } while (!lerQuantidade(quantity));

        inventory = charParaInt(quantity);
        it->quantProduct = inventory;

        char *data;
        data = verDiaMesAno();
        // ... more code

        strcpy(it->dateToday, data);
        printf(" | Registration done on: %s\n", data);
        it->type = 'E';

        dateDay = dividPal(data, 0, 1);
        dateMonth = dividPal(data, 3, 4);
        dateYear = dividPal(data, 6, 7);
        dayControl = charParaInt(dateDay);
        monthControl = charParaInt(dateMonth);
        yearControl = charParaInt(dateYear);
        yearControl += 2000;

        if (it->dia < dayControl && it->mes <= monthControl && it->ano == yearControl)
        {

                printf("| The product is expired, please exchange it");
        }
        else if (it->dia == dayControl && it->mes == monthControl && it->ano == yearControl)
        {

                printf(" | The product expires today, be careful!");
        }
        else if (it->dia > dayControl && it->mes >= monthControl && it->ano == yearControl)
        {

                printf(" | The product is within its validity period!");
        }

        it->status = '1'; // 1 shows it was registered
        gravaItem(it);
        free(it);
        free(dateDay);
        free(dateMonth);
        free(dateYear);
        fclose(fp3);
    }
    else
    {
        printf("User not found");
    }

    printf(" | | \n");
    printf(" | ========================================================= | \n");
    free(client);
    fclose(fp);
    printf(" | Press any key to exit.... ");
    getchar();

    return 0;
}

//função para escolha da categoria
char categoryScreen(void)
{
    char esc;
    clear();
    printf(" | ================== Product Category ================== |\n");
    printf(" |                                                        |\n");
    printf(" |                    1- Personal Hygiene                 |\n");
    printf(" |                    2- Cleaning                         |\n");
    printf(" |                    3- Food                             |\n");
    printf(" |                                                        |\n");
    printf(" | ====================================================== |\n");
    printf(" | Enter an option: ");
    scanf("%c", &esc);
    getchar();

    return esc;
}


//função para escolha do local de armazenamento
char scrennStorageLocation(void)
{
    char esc;
    clear();
    printf(" | ================ Storage Location ================ |\n");
    printf(" |                                                    |\n");
    printf(" |                 1- Refrigerator                    |\n");
    printf(" |                 2- Kitchen Cabinet                 |\n");
    printf(" |                 3- Laundry Area                    |\n");
    printf(" |                 4- Bathroom                        |\n");
    printf(" |                 5- Wardrobe                        |\n");
    printf(" |                                                    |\n");
    printf(" | ================================================== |\n");
    printf(" | Enter your option: ");
    scanf("%c", &esc);
    getchar();

    return esc;
}


//função para gravar no arquivo de item
int saveItem(Item* it) 
{
    FILE* fp3;
    
    fp3 = fopen("itens.dat", "ab");
    
    if (fp3 == NULL) {
        printf("Ops! An error occurred while opening the file!\n");
        
        return 0;

    }  
    fwrite(it, sizeof(Item), 1, fp3);
    fclose(fp3);
    
    return 0;

}


//função de pesquisa a partir do código de barras (id do item)
int searchItemInfo(void) {
    FILE *fp3;
    Item *it;
    int found;
    char searched[15];
    char aux[20];
    char aux2[20];

    fp3 = fopen("itens.dat", "rb");
    if (fp3 == NULL)
    {
        printf("Oops! Error opening file!\n");
        return 0;
    }

    printf("\n\n");
    clear();
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                      Search Item Data                     | \n");
    printf(" | ========================================================= | \n");
    printf("Enter the barcode: ");
    scanf(" %30[^\n]", searched);
    getchar();
    it = (Item *)malloc(sizeof(Item));
    found = 0;

    while ((!found) && (fread(it, sizeof(Item), 1, fp3)))
    {
        printf("Barcode |%s|\n", it->barcode);

        if ((strcmp(it->barcode, searched) == 0) && (it->status == '1'))
        {
                found = 1;
        }
    }

    if (found)
    {

        if (it->category == '1')
        {
                strcpy(aux, "Personal hygiene");
        }
        else if (it->category == '2')
        {
                strcpy(aux, "Cleaning");
        }
        else
        {
                strcpy(aux, "Food");
        }

        if (it->storageLocation == '1')
        {
                strcpy(aux2, "Refrigerator");
        }
        else if (it->storageLocation == '2')
        {
                strcpy(aux2, "Kitchen cabinet");
        }
        else if (it->storageLocation == '3')
        {
                strcpy(aux2, "Laundry area");
        }
        else if (it->storageLocation == '4')
        {
                strcpy(aux2, "Bathroom");
        }
        else
        {
                strcpy(aux2, "Wardrobe");
        }
        clear();
        printf(" | ===================== Item List ==================== |\n");
        printf(" |                                                           |\n");
        printf(" | Product name: %s\n", it->productName);
        printf(" | Brand name: %s\n", it->brandName);
        printf(" | Barcode: %s\n", it->barcode);
        printf(" | Minimum stock of the product: %d\n", it->minStock);
        printf(" | Expiration date: %d/%d/%d\n", it->day, it->month, it->year);
        printf(" | Entry day: %s\n", it->currentDate);
        printf(" | Product category: %s\n", aux);
        printf(" | Storage location: %s\n", aux2);
        printf(" | Product quantity: %d\n", it->quantity);
        printf(" | Status: %c\n", it->status);
        printf(" |                                                           | \n");
        printf(" | ========================================================= | \n");
        getchar();
    }
    else
    {

        printf("The information for the item %s was not found\n", searched);
    }
    free(it);
    fclose(fp3);
    printf(" | Press any key to exit.... ");
    getchar();

    return 0;
}

//função para editar algum item
int updateItemScreen(void)
{

    FILE *fp;
    User *customer;
    char response;
    int found, match, stock, minStock;
    char quantity[20];
    char searched[20];
    char minStockStr[20];
    char search[20];

    scss
        Copy code
            fp = fopen("user.dat", "r+b");

    if (fp == NULL)
    {
        printf("Oops! An error occurred while opening the file!\n");
        return 0;
    }

    customer = (User *)malloc(sizeof(User));

    clear();
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------------- Update item ------------------------ | \n");
    printf(" |                                                           | \n");
    printf(" | Enter your username: ");
    scanf(" %30[^\n]", searched);
    getchar();
    found = 0;

    while ((!found) && (fread(customer, sizeof(User), 1, fp)))
    {
        if ((strcmp(customer->usernameUser, searched) == 0) && (customer->status == '1'))
        {
                found = 1;
        }
    }
    if (found)
    {

        FILE *fp3;
        Item *it;
        it = (Item *)malloc(sizeof(Item));
        fp3 = fopen("items.dat", "r+b");

        if (fp3 == NULL)
        {
                printf("Oops! An error occurred while opening the file!\n");
                return 0;
        }

        printf("Enter the barcode of the item you want to change: ");
        scanf(" %[0-9]", search);
        getchar();
        match = 0;

        while ((!match) && (fread(it, sizeof(Item), 1, fp3)))
        {
                if ((strcmp(it->barcode, search) == 0) && (it->status == '1'))
                {
                    match = 1;
                }
        }

        if (match)
        {
                searchItemInfo();
                response = chooseUpdateItem();
                printf("\n");

                if (response == '1')
                {

                    printf("Enter the new product name (without accents): ");
                    scanf("%30[^\n]", it->productName);
                    getchar();

                    printf(" | Enter the new brand name (without accents): ");
                    scanf("%30[^\n]", it->brandName);
                    getchar();

                    do
                    {
                        printf(" | Enter the minimum stock of this product: ");
                        scanf("%s", minStockStr);
                        getchar();

                    } while (!readQuantity(minStockStr));
                    minStock = charToInt(minStockStr);
                    it->minStock = minStock;

                    do
                    {
                        printf(" | Enter the new expiration date (dd/mm/yyyy): ");
                        scanf("%d", &it->day);
                        getchar();
                        printf(" | Enter the new month: ");
                        scanf("%d", &it->month);
                        getchar();
                        printf(" | Enter the new year: ");
                        scanf("%d", &it->year);
                        getchar();

                    } while (!valid_date(it->day, it->month, it->year));
                    it->category = chooseCategoryScreen();
                    it->storageLocation = chooseStorageLocationScreen();

                    do
                    {
                        printf(" | Enter the quantity of products: ");
                        scanf("%s", quantity);
                        getchar();

                    } while (!readQuantity(quantity));
                    stock = charToInt(quantity);
                    it->quantity = stock;
                }
                else if (response == '2')
                {
                    do
                    {
                        printf("Enter the new product name: ")
                            scanf("%30[^\n]", it->nomeProduto);
                        getchar();

                    } while (!it->nomeProduto);
                }
                else if (resp == '3')
                {
                    do
                    {
                        printf(" | Enter the new brand name: ");
                        scanf("%30[^\n]", it->nomeMarca);
                        getchar();
                    } while (!it->nomeMarca);
                }
                else if (resp == '4')
                {
                    do
                    {
                        printf(" | Enter the minimum stock for this product: ");
                        scanf("%s", estoqueMin);
                        getchar();
                    } while (!lerQuantidade(estoqueMin));
                    estoqueM = charParaInt(estoqueMin);
                    it->estoqueMinimo = estoqueM;
                }
                else if (resp == '5')
                {
                    do
                    {
                        printf(" | Enter the new expiration date: ");
                        scanf("%d", &it->dia);
                        getchar();
                        printf(" | Enter the new expiration month: ");
                        scanf("%d", &it->mes);
                        getchar();
                        printf(" | Enter the new expiration year: ");
                        scanf("%d", &it->ano);
                        getchar();
                    } while (!valida_data(it->dia, it->mes, it->ano));
                }
                else if (resp == '6')
                {
                    it->categoria = telaEscCategoria();
                }
                else if (resp == '7')
                {
                    it->localArmazenamento = telaEscLocalArmaz();
                }
                else if (resp == '8')
                {
                    do
                    {
                        printf(" | Enter the product quantity: ");
                        scanf("%s", quantidade);
                        getchar();
                    } while (!lerQuantidade(quantidade));
                    estoque = charParaInt(quantidade);
                    it->quantProduto = estoque;
                }
                it->status = '1';
                fseek(fp, (-1) * sizeof(Item), SEEK_CUR);
                fwrite(it, sizeof(Item), 1, fp);
                printf(" | | \n");
                printf(" | --------------------------------------------------------- | \n");
                printf("Data edited successfully");
                gravaItem(it);
                free(it);
                fclose(fp3);
        }
        else
        {
                printf("The barcode item %s was not found\n", procurado);
        }
    }
    else
    {
        printf("The user was not found");
    }
    free(cliente);
    fclose(fp);
    printf(" | Press any key to exit.... ");
    getchar();

    return 0;
}

//função para selecionar o que quer atualizar
char escAtualizarItem(void)
{    
    char esc;
    clear();
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------------- Atualizar Item --------------------- | \n");
    printf(" |                                                           | \n");
    printf(" |                1- Editar tudo                             | \n");
    printf(" |                2- Editar nome do produto                  | \n");
    printf(" |                3- Editar nome da marca                    | \n");
    printf(" |                4- Editar estoque mínimo                   | \n");
    printf(" |                5- Editar data de vencimento               | \n");                                                                    
    printf(" |                6- Editar categoria do produto             | \n");                                                                    
    printf(" |                7- Editar local de armazenamento           | \n");                                                                    
    printf(" |                8- Editar quantidade do produto            | \n");                                                                    
    printf(" |                0- Voltar à tela principal                 | \n");    
    printf(" |                                                           | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | Selecione uma opção do que você deseja editar: ");
    scanf("%c", &esc);
    getchar();

    return esc;

}


//função para exclusão lógica
int excluirItem(void)
{
    FILE* fp3;
    Item* it;
    int achou;
    char resp;
    char procurado[20];
    
    fp3 = fopen("itens.dat", "r+b");

    if (fp3 == NULL){
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }

    it = (Item*) malloc(sizeof(Item));  

    clear();
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ------------------------ Excluir item ------------------------ | \n");
    printf(" |                                                                | \n");
    printf(" | Informe o código de barras do item que você deseja excluir: ");
    scanf(" %30[^\n]", procurado);
    getchar();    
    achou = 0;

    while ((!achou) && (fread(it, sizeof(Item), 1, fp3))){
        if ((strcmp(it->codigoBarras, procurado) == 0) && (it->status == '1')){
            achou = 1;
        }
    
    }if (achou){
        listarItens();
        printf("Deseja realmente excluir os dados deste item? (s/n)");
        scanf("%c", &resp);

        if (resp == 's' || resp == 'S'){
            
            it->status = '0';
            fseek(fp3, (-1)*sizeof(Item), SEEK_CUR);
            fwrite(it, sizeof(Item), 1, fp3);
            printf("\nDados do item excluídos com sucesso!");
            gravaItem(it);
            
        }else{
            
            printf("\nTudo bem, os dados não foram alterados!");
        
        }

    }else{     
        printf("O item não foi encontrado!");  
    }
    free(it);
    fclose(fp3);  
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    
    return 0;
    
}


//listar itens - relatório sem filtro
int listarItens(void) 
{
    FILE* fp3;
    Item* it;
    
    fp3 = fopen("itens.dat", "rb");
    
    if (fp3 == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }

    it = (Item*)malloc(sizeof(Item)); 

    while(fread(it, sizeof(Item), 1, fp3)) {
        system(" cls || clear");
        printf(" | ===================== Lista itens ======================= | \n");
        printf(" |                                                           | \n");
        exibeInfoItem(it);
    } 
    free(it);
    fclose(fp3);
       
    return 0;

}


//função para a exibição das informações dos itens
void exibeInfoItem(Item* it) 
{
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

    clear();
    printf(" | ===================== Lista de Itens ==================== |\n");
    printf(" |                                                           |\n");       
    printf(" | Nome do produto: %s\n", it->nomeProduto);    
    printf(" | Nome da marca: %s\n", it->nomeMarca);    
    printf(" | Código de barras: %s\n", it->codigoBarras);    
    printf(" | Estoque mínimo do produto: %d\n", it->estoqueMinimo);
    printf(" | Data de vencimento: %d/%d/%d\n", it->dia, it->mes, it->ano); 
    printf(" | Categoria do produto: %s\n", aux);
    printf(" | Local de armazenamento: %s\n", aux2);
    printf(" | Quantidade do produto: %d\n", it->quantProduto);
    printf(" | Status: %c\n", it->status);
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();

}


//função para adição de produtos à despensa
int entradaItem(void) 
{
    FILE* fp;
    Item* it;
    User* cliente;
    int achou, encontra;
    char resp;
    char procurado[20];
    int estoque, estoque1;
    char quantidade[20];
    
    fp = fopen("user.dat", "rb");

    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        getchar();
        return 0;
    }

    it = (Item*)malloc(sizeof(Item));
    cliente = (User*)malloc(sizeof(User));

    clear();
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                     Entrada Item                          | \n");
    printf(" |                                                           | \n"); 
    printf(" | Informe o seu username: ");
    scanf(" %30[^\n]", procurado);
    getchar();     
    achou = 0;  

    while ((!achou) && (fread(cliente, sizeof(User), 1, fp))){
        if ((strcmp(cliente->usernameUser, procurado) == 0) && (cliente->status == '1')){
            achou = 1;
        }

    }if (achou){
        FILE* fp3;
        char procura[20];
        
        fp3 = fopen("itens.dat", "r+b");
        
        if (fp3 == NULL) {
            printf("Ops! Erro na abertura do arquivo!\n");
            getchar();
            return 0;
        }
               
        printf("Informe o código de barras do produto que deseja adicionar: ");
        scanf(" %30[^\n]", procura);
        getchar();      
        encontra = 0;
    
        while(((!encontra) && (fread(it, sizeof(Item), 1, fp3)))){
            if ((strcmp(it->codigoBarras,  procura) == 0) && (it->status == '1')) {
                encontra = 1;
            }

        } if (encontra){
            do
            {
                printf(" | Informe a quantidade de produto: ");
                scanf("%s", quantidade);             
                getchar();
                
            } while(!lerQuantidade(quantidade));
            estoque = charParaInt(quantidade);
            estoque1 = it->quantProduto + estoque;
            it->quantEntrada = estoque;
            it->quantProduto = estoque1;

            do 
            {        
                printf(" | Informe o dia de vencimento do produto: ");
                scanf("%d", &it->dia);
                getchar();
                printf(" | Informe o mês: ");
                scanf("%d", &it->mes);
                getchar();
                printf(" | Informe o ano: ");
                scanf("%d", &it->ano);
                getchar();
                    
            } while(!valida_data(it->dia, it->mes, it->ano)); 
            
            it->tipo = 'E';
            printf("Tem certeza que deseja adicionar este produto à despensa (s/n? ");
            scanf("%c", &resp); 

                if (resp == 's' || resp == 'S') {
                    
                    fseek(fp3, (-1)*sizeof(Item), SEEK_CUR);
                    fwrite(it, sizeof(Item), 1, fp3);                      
                    printf("Produto adicionado com sucesso!");
                    getchar();
                    free(it);                
                    fclose(fp3);
                
                }      
                else {
                    
                    printf("Operação cancelada!");
                    getchar();         
                
                }
    
    }else{
        
        printf("Produto não encontrado!");
        getchar();

    }  
    free(cliente);
    fclose(fp); 
       
    }

   return 0;

}  


//função para retirada de produto da despensa
int saidaItem(void) 
{
    FILE* fp;
    Item* it;
    User* cliente;
    int achou, encontrou;
    char resp;
    char procurado[20];
    int estoque, estoque1;  
    char quantidade[20];
    char procura[20];  

    fp = fopen("user.dat", "rb");

    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        getchar();
        return 0;
    }

    it = (Item*)malloc(sizeof(Item));
    cliente = (User*)malloc(sizeof(User));

    clear();
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                       Saída Item                          | \n");
    printf(" |                                                           | \n"); 
    printf(" | Informe o seu username: ");
    scanf(" %30[^\n]", procurado);
    getchar();     
    achou = 0;

    while ((!achou) && (fread(cliente, sizeof(User), 1, fp))){
        if ((strcmp(cliente->usernameUser, procurado) == 0) && (cliente->status == '1')){
            achou = 1;
        }
    
    }if (achou){
        FILE* fp3;

        fp3 = fopen("itens.dat", "r+b");

        if (fp3 == NULL) {
            printf("Ops! Erro na abertura do arquivo!\n");
            getchar();
            return 0;
        }
     
            
        printf("Informe o código de barras do produto que deseja retirar: ");
        scanf(" %30[^\n]", procura);
        getchar();     
        encontrou = 0;
    
        while((!encontrou) && (fread(it, sizeof(Item), 1, fp3))) {
            if ((strcmp(it->codigoBarras, procura) == 0) && (it->status == '1')) {
            encontrou = 1;
            }  

        }if (encontrou){

            do
            {
                printf(" | Informe a quantidade de produto: ");
                scanf("%s", quantidade);             
                getchar();
                
            } while(!lerQuantidade(quantidade));
            estoque = charParaInt(quantidade);
            estoque1 = it->quantProduto - estoque;
            it->quantSaida = estoque;
            it->quantProduto = estoque1;

            it->tipo = 'S'; //S indica saída

            printf("Tem certeza que deseja remover este produto da despensa (s/n)? ");
            scanf("%c", &resp); 
            getchar();

                if (resp == 's' || resp == 'S') {
                    
                    fseek(fp3, (-1)*sizeof(Item), SEEK_CUR);
                    fwrite(it, sizeof(Item), 1, fp3);                      
                    printf("Produto removido com sucesso!");
                    getchar();
                   
                }        
                else {
                    
                    printf("Operação cancelada!");
                    getchar();

                }
                free(it);
                fclose(fp3);
             }

        }else{
            
            printf("Produto não encontrado!");
            getchar();
        
        }  
    free(cliente);
    fclose(fp);   
    
    return 0;
    
}


//função para não permitir código de barras iguais
int validaCod(char* item)
{
    FILE* fp3;
    Item* usuarioItem;

    usuarioItem = (Item*)malloc(sizeof(Item));
    
    fp3 = fopen("itens.dat", "rt");
    
    if (fp3 == NULL)
    {
        printf("Gerando arquivo...");
        fclose(fp3);
        return 1;
    }
    while (!feof(fp3))
    {
        fread(usuarioItem, sizeof(Item), 1, fp3);
        if (strcmp(item, usuarioItem->codigoBarras) == 0 && (usuarioItem->status != '0'))
        {
            fclose(fp3);
            return 0;
        }
    }
    fclose(fp3);
 
    return 1;

}