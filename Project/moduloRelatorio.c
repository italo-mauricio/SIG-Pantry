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

// função principal de navegação
char moduleRelatory(void)
{
    char choice;
    NoItem *list;
    do
    {
        choice = relatoryScreen();
        switch (choice)
        {
        case '1':
            menuCategory();
            break;
        case '2':
            menuLocalRelatory();
            break;
        case '3':
            list = ordenedListItens();
            displayOrderItem(list);
            break;
        default:
            printf("Invalid Option!");
            break;
        }

    } while (choice != '0');

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

// navegação da escolha da categoria
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

// função para selecionar uma das categorias
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

// função para retornar o relatório dos itens de higiente
int displayHygieneItens(void)
{
    FILE *fp3;
    Item *it;
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
    it = (Item *)malloc(sizeof(Item));
    found = 0;

    while ((fread(it, sizeof(Item), 1, fp3)))
    {
        if (((it->category == '1')) && (it->status == '1'))
        {
            displayInfoItem(it);
            found = 1;
        }
    }

    if (found)
    {
        return 0;
    }
    else
    {
        printf(" | No report to be displayed");
    }

    free(it);
    fclose(fp3);
    getchar();

    return 0;
}

int displayCleaningItens(void)
{
    FILE *fp3;
    Item *it;
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
    it = (Item *)malloc(sizeof(Item));
    found = 0;

    while ((fread(it, sizeof(Item), 1, fp3)))
    {
        if (((it->category == '2')) && (it->status == '1'))
        {
            displayInfoItem(it);
            found = 1;
        }
    }
    if (found)
    {
        return 0;
    }
    else
    {
        printf(" | No report to display");
    }
    free(it);
    fclose(fp3);
    getchar();

    return 0;
}

int displayFoodItens(void)
{
    FILE *fp3;
    Item *it;
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
    it = (Item *)malloc(sizeof(Item));
    found = 0;

    while ((fread(it, sizeof(Item), 1, fp3)))
    {
        if (((it->category == '3')) && (it->status == '1'))
        {
            displayInfoItem(it);
            found = 1;
        }
    }

    if (found)
    {

        return 0;
    }
    else
    {

        printf(" | No report to be displayed");
    }
    free(it);
    fclose(fp3);
    getchar();

    return 0;
}

void menuLocalRelatory(void)
{
    char choice;
    do
    {
        choice = stockRelatoryLocal();
        switch (choice)
        {
        case '1':
            displayRefrigerator();
            break;
        case '2':
            displayKitchenCabinet();
            break;
        case '3':
            displayServiceArea();
            break;
        case '4':
            displayBathroom();
            break;
        case '5':
            displayCloset();
            break;
        }

    } while (choice != '0');
}

char stockRelatoryLocal(void)
{
    char esc;
    clear();
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ---------------| Reports based on storage location |---------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |                 1- Refrigerator                                      | \n");
    printf(" |                 2- Kitchen cabinet                                   | \n");
    printf(" |                 3- Laundry room                                      | \n");
    printf(" |                 4- Bathroom                                          | \n");
    printf(" |                 5- Wardrobe                                          | \n");
    printf(" |                 0- Back to main menu                                 | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Choose an option: ");
    scanf("%c", &esc);
    getchar();
    return esc;
}

int displayRefrigerator(void)
{
    FILE *fp3;
    Item *it;
    int found;

    fp3 = fopen("items.dat", "rb");

    if (fp3 == NULL)
    {
        printf("Oops! An error occurred while opening the file!\n");
        return 0;
    }

    clear();
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ----------------| Refrigerator Items Report |----------------------- | \n");
    printf(" | | \n");
    it = (Item *)malloc(sizeof(Item));
    found = 0;

    while ((fread(it, sizeof(Item), 1, fp3)))
    {
        if (((it->storageLocation == '1')) && (it->status == '1'))
        {
            displayInfoItem(it);
            found = 1;
        }
    }

    if (found)
    {
        return 0;
    }
    else
    {
        printf(" | No report to display");
    }

    free(it);
    fclose(fp3);
    getchar();
    return 0;
}

int displayKitchenCabinet(void)
{
    FILE *fp3;
    Item *it;
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
    printf(" | -------------| Kitchen cabinet items report |----------------------- | \n");
    printf(" | | \n");
    it = (Item *)malloc(sizeof(Item));
    found = 0;

    while ((fread(it, sizeof(Item), 1, fp3)))
    {
        if (((it->storageLocation == '2')) && (it->status == '1'))
        {
            displayInfoItem(it);
            found = 1;
        }
    }

    if (found)
    {
        return 0;
    }
    else
    {
        printf(" | No report to display");
    }
    free(it);
    fclose(fp3);
    getchar();
    return 0;
}

int displayServiceArea(void)
{
    FILE *fp3;
    Item *it;
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
    printf(" | --------------| Report of items in the laundry room |--------------- | \n");
    printf(" |                                                                      | \n");
    it = (Item *)malloc(sizeof(Item));
    found = 0;

    while ((fread(it, sizeof(Item), 1, fp3)))
    {
        if (((it->storageLocation == '3')) && (it->status == '1'))
        {
            displayInfoItem(it);
            found = 1;
        }
    }

    if (found)
    {

        return 0;
    }
    else
    {
        printf(" | No report to display");
    }
    free(it);
    fclose(fp3);
    getchar();

    return 0;
}

int displayCloset(void)
{
    FILE *fp3;
    Item *it;
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
    printf(" | -----------------------| Wardrobe Item Report |--------------------- | \n");
    printf(" | | \n");
    it = (Item *)malloc(sizeof(Item));
    found = 0;

    while ((fread(it, sizeof(Item), 1, fp3)))
    {
        if (((it->storageLocation == '5')) && (it->status == '1'))
        {
            displayInfoItem(it);
            found = 1;
        }
    }

    if (found)
    {
        return 0;
    }
    else
    {
        printf(" | No report to display");
    }
    free(it);
    fclose(fp3);
    getchar();
    return 0;
}

int displayBathroom(void)
{
    FILE *fp3;
    Item *it;
    int found;

    fp3 = fopen("itens.dat", "rb");

    if (fp3 == NULL)
    {
        printf("Oops! An error occurred while opening the file!\n");
        return 0;
    }

    clear();
    printf(" | =============================================================== | \n");
    printf(" | --------------------------------------------------------------- | \n");
    printf(" | ----------------| Bathroom items report |---------------------- | \n");
    printf(" |                                                                 | \n");
    it = (Item *)malloc(sizeof(Item));
    found = 0;

    while ((fread(it, sizeof(Item), 1, fp3)))
    {
        if (((it->storageLocation == '4')) && (it->status == '1'))
        {
            displayInfoItem(it);
            found = 1;
        }
    }

    if (found)
    {
        return 0;
    }
    else
    {
        printf(" | No report to display");
    }

    free(it);
    fclose(fp3);
    getchar();
    return 0;
}

NoItem *ordenedListItens(void) // adapted by @flgorgonio
{
    FILE *fp3;
    Item *it;
    NoItem *newItem;
    NoItem *list;

    list = NULL;

    fp3 = fopen("itens.dat", "rb");

    if (fp3 == NULL)
    {
        printf("Ops! An error occurred while opening the file!\n");
        return 0;
    }

    it = (Item *)malloc(sizeof(Item));

    while (fread(it, sizeof(Item), 1, fp3))
    {
        if (it->status == '1')
        {
            newItem = (NoItem *)malloc(sizeof(NoItem));
            strcpy(newItem->relatoryProductName, it->productName);
            strcpy(newItem->relatoryBrandName, it->nameBrand);
            strcpy(newItem->relatoryBarCode, it->barCode);
            newItem->relatoryDay = it->day;
            newItem->relatoryMonth = it->month;
            newItem->relatoryYear = it->year;
            newItem->minimumStock = it->minimumInventory;
            newItem->categoryAux = it->category;
            newItem->localStorage = it->storageLocation;
            newItem->status = it->status;
            newItem->quantProductAux = it->quantProduct;

            if (list == NULL)
            {
                list = newItem;
                newItem->prox = NULL;
            }

            else if (strcmp(newItem->relatoryProductName, list->relatoryBrandName) < 0)
            {
                newItem->prox = list;
                list = newItem;
            }

            else
            {
                NoItem *anter = list;
                NoItem *atual = list->prox;

                while ((atual != NULL) && strcmp(atual->relatoryProductName, newItem->relatoryProductName) < 0)
                {
                    anter = atual;
                    atual = atual->prox;
                }

                anter->prox = newItem;
                newItem->prox = atual;
            }
        }
    }

    fclose(fp3);
    free(it);

    return list;
}

void displayOrderItem(NoItem *list)
{
    while (list != NULL)
    {

        Item *it;
        it = (Item *)malloc(sizeof(Item));

        char aux[20];
        char aux2[20];
        if (it->category == '1')
        {
            strcpy(aux, "Personal Hygiene");
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
            strcpy(aux2, "Armário de cozinha");
        }
        else if (it->storageLocation == '3')
        {
            strcpy(aux2, "Kitchen Cabinet");
        }
        else if (it->storageLocation == '4')
        {
            strcpy(aux2, "Bathroom");
        }
        else
        {
            strcpy(aux2, "Closet");
        }

        printf(" | ========================================================= | \n");
        printf(" |                                                           | \n");
        printf(" | Product Name: %s\n", list->relatoryProductName);
        printf(" | Brand Name: %s\n", list->relatoryBrandName);
        printf(" | Bar Code: %s\n", list->relatoryBarCode);
        printf(" | Minimum product stock: %d\n", list->minimumStock);
        printf(" | Due Date: %d/%d/%d\n", list->relatoryDay, list->relatoryMonth, list->relatoryYear);
        printf(" | Product Category: %s\n", aux);
        printf(" | Local Storage: %s\n", aux2);
        printf(" | Product Quantity: %d\n", list->quantProductAux);
        printf(" | Status: %c\n", list->status);
        printf(" |                                                           | \n");
        printf(" | ========================================================= | \n");
        printf(" | Press any key to exit.... ");
        getchar();

        list = list->prox;
    }
}
