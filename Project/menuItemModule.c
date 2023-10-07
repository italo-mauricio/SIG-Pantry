#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menuItemModule.h"
#include "validacoes.h"
#include "userRegistrationModule.h"
#include "clearScreen.c"

void moduloMenuItem(void)
{
    char choice;
    do
    {
        choice = screenRegisterItem();
        switch (choice)
        {
        case '1':
            infoItem();
            break;
        case '2':
            searchItemInfo();
            break;
        case '3':
            updateItemScreen();
            break;
        case '4':
            deleteItem();
            break;
        case '5':
            entryItem();
            break;
        case '6':
            exitItem();
            break;
        case '7':
            searchItemInfo();
            break;
        default:
            printf("Opção inválida\n");
            break;
        }

    } while (choice != '0');
}

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

        } while (!((readQuantity(it->barCode)) && (validaCod(it->barCode))));
        do
        {
            printf(" | Enter the minimum inventory of this product: ");
            scanf("%s", inventoryMin);
            getchar();

        } while (!readQuantity(inventoryMin));

        inventoryMax = charToInt(inventoryMin);
        it->minimumInventory = inventoryMax;

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

        it->category = categoryScreen();
        it->storageLocation = scrennStorageLocation();

        do
        {

            printf(" | Enter the quantity of products: ");
            scanf("%s", quantity);
            getchar();

        } while (!readQuantity(quantity));

        inventory = charToInt(quantity);
        it->quantProduct = inventory;

        char *data;
        data = verDiaMesAno();
        // ... more code

        strcpy(it->dateToday, data);
        printf(" | Registration done on: %s\n", data);
        it->tipe = 'E';

        dateDay = dividPal(data, 0, 1);
        dateMonth = dividPal(data, 3, 4);
        dateYear = dividPal(data, 6, 7);
        dayControl = charToInt(dateDay);
        monthControl = charToInt(dateMonth);
        yearControl = charToInt(dateYear);
        yearControl += 2000;

        if (it->day < dayControl && it->month <= monthControl && it->year == yearControl)
        {
            printf("| The product is expired, please exchange it");
        }
        else if (it->day == dayControl && it->month == monthControl && it->year == yearControl)
        {
            printf(" | The product expires today, be careful!");
        }
        else if (it->day > dayControl && it->month >= monthControl && it->year == yearControl)
        {
            printf(" | The product is within its validity period!");
        }

        it->status = '1'; // 1 shows it was registered
        saveItem(it);
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

int saveItem(Item *it)
{
    FILE *fp3;

    fp3 = fopen("itens.dat", "ab");

    if (fp3 == NULL)
    {
        printf("Ops! An error occurred while opening the file!\n");

        return 0;
    }
    fwrite(it, sizeof(Item), 1, fp3);
    fclose(fp3);

    return 0;
}

int searchItemInfo(void)
{
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
        printf("Barcode |%s|\n", it->barCode);

        if ((strcmp(it->barCode, searched) == 0) && (it->status == '1'))
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
        printf(" | Brand name: %s\n", it->nameBrand);
        printf(" | Barcode: %s\n", it->barCode);
        printf(" | Minimum stock of the product: %d\n", it->minimumInventory);
        printf(" | Expiration date: %d/%d/%d\n", it->day, it->month, it->year);
        printf(" | Entry day: %d\n", it->dayEntry);
        printf(" | Product category: %s\n", aux);
        printf(" | Storage location: %s\n", aux2);
        printf(" | Product quantity: %d\n", it->quantProduct);
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
            if ((strcmp(it->barCode, search) == 0) && (it->status == '1'))
            {
                match = 1;
            }
        }

        if (match)
        {
            searchItemInfo();
            response = updateItemMenu();
            printf("\n");

            if (response == '1')
            {

                printf("Enter the new product name (without accents): ");
                scanf("%30[^\n]", it->productName);
                getchar();

                printf(" | Enter the new brand name (without accents): ");
                scanf("%30[^\n]", it->nameBrand);
                getchar();

                do
                {
                    printf(" | Enter the minimum stock of this product: ");
                    scanf("%s", minStockStr);
                    getchar();

                } while (!readQuantity(minStockStr));
                minStock = charToInt(minStockStr);
                it->minimumInventory = minStock;

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

                } while (!valida_data(it->day, it->month, it->year));
                it->category = categoryScreen();
                it->storageLocation = scrennStorageLocation();

                do
                {
                    printf(" | Enter the quantity of products: ");
                    scanf("%s", quantity);
                    getchar();

                } while (!readQuantity(quantity));
                stock = charToInt(quantity);
                it->quantEntry = stock;
            }
            else if (response == '2')
            {
                do
                {
                    printf("Enter the new product name: ");
                    scanf("%30[^\n]", it->productName);
                    getchar();

                } while (!it->productName);
            }
            else if (response == '3')
            {
                do
                {
                    printf(" | Enter the new brand name: ");
                    scanf("%30[^\n]", it->nameBrand);
                    getchar();
                } while (!it->nameBrand);
            }
            else if (response == '4')
            {
                do
                {
                    printf(" | Enter the minimum stock for this product: ");
                    scanf("%s", quantity);
                    getchar();
                } while (!readQuantity(quantity));
                minStock = charToInt(quantity);
                it->minimumInventory = minStock;
            }
            else if (response == '5')
            {
                do
                {
                    printf(" | Enter the new expiration date: ");
                    scanf("%d", &it->day);
                    getchar();
                    printf(" | Enter the new expiration month: ");
                    scanf("%d", &it->month);
                    getchar();
                    printf(" | Enter the new expiration year: ");
                    scanf("%d", &it->year);
                    getchar();
                } while (!valida_data(it->day, it->month, it->year));
            }
            else if (response == '6')
            {
                it->category = categoryScreen();
            }
            else if (response == '7')
            {
                it->storageLocation = scrennStorageLocation();
            }
            else if (response == '8')
            {
                do
                {
                    printf(" | Enter the product quantity: ");
                    scanf("%s", quantity);
                    getchar();
                } while (!readQuantity(quantity));
                stock = charToInt(quantity);
                it->minimumInventory = stock;
            }
            it->status = '1';
            fseek(fp, (-1) * sizeof(Item), SEEK_CUR);
            fwrite(it, sizeof(Item), 1, fp);
            printf(" | | \n");
            printf(" | --------------------------------------------------------- | \n");
            printf("Data edited successfully");
            saveItem(it);
            free(it);
            fclose(fp3);
        }
        else
        {
            printf("The barcode item %s was not found\n", searched);
        }
    }
    else
    {
        printf("The user was not found");
    }
    free(customer);
    fclose(fp);
    printf(" | Press any key to exit.... ");
    getchar();

    return 0;
}

char updateItemMenu(void)
{
    char option;
    clear();
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------------- Update Item ------------------------ | \n");
    printf(" |                                                           | \n");
    printf(" |                1- Edit everything                         | \n");
    printf(" |                2- Edit product name                       | \n");
    printf(" |                3- Edit brand name                         | \n");
    printf(" |                4- Edit minimum stock quantity             | \n");
    printf(" |                5- Edit expiration date                    | \n");
    printf(" |                6- Edit product category                   | \n");
    printf(" |                7- Edit storage location                   | \n");
    printf(" |                8- Edit product quantity                   | \n");
    printf(" |                0- Return to main screen                   | \n");
    printf(" |                                                           | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | Select an option of what you wish to edit: ");
    scanf("%c", &option);
    getchar();

    return option;
}

int deleteItem(void)
{
    FILE *fp3;
    Item *it;
    int found;
    char answer;
    char searched[20];

    fp3 = fopen("itens.dat", "r+b");

    if (fp3 == NULL)
    {
        printf("Oops! Error opening file!\n");
        return 0;
    }

    it = (Item *)malloc(sizeof(Item));

    clear();
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ------------------------ Delete Item ------------------------- | \n");
    printf(" |                                                                | \n");
    printf(" | Enter the barcode of the item you wish to delete: ");
    scanf(" %30[^\n]", searched);
    getchar();
    found = 0;

    while ((!found) && (fread(it, sizeof(Item), 1, fp3)))
    {
        if ((strcmp(it->barCode, searched) == 0) && (it->status == '1'))
        {
            found = 1;
        }
    }

    if (found)
    {
        listItems();
        printf("Do you really want to delete this item's data? (y/n)");
        scanf("%c", &answer);

        if (answer == 'y' || answer == 'Y')
        {

            it->status = '0';
            fseek(fp3, (-1) * sizeof(Item), SEEK_CUR);
            fwrite(it, sizeof(Item), 1, fp3);
            printf("\nItem data successfully deleted!");
            saveItem(it);
        }
        else
        {

            printf("\nAlright, the data was not changed!");
        }
    }
    else
    {
        printf("The item was not found!");
    }

    free(it);
    fclose(fp3);
    printf(" | Press any key to exit.... ");
    getchar();

    return 0;
}

int listItems(void)
{
    FILE *fp3;
    Item *it;

    fp3 = fopen("itens.dat", "rb");

    if (fp3 == NULL)
    {
        printf("Oops! Error opening file!\n");
        return 0;
    }

    it = (Item *)malloc(sizeof(Item));

    while (fread(it, sizeof(Item), 1, fp3))
    {
        clear();
        printf(" | ===================== Item List ======================= | \n");
        printf(" |                                                           | \n");
        displayItemInfo(it);
    }
    free(it);
    fclose(fp3);

    return 0;
}

void displayItemInfo(Item *it)
{
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
        strcpy(aux2, "Kitchen Cupboard");
    }
    else if (it->storageLocation == '3')
    {
        strcpy(aux2, "Service Area");
    }
    else if (it->storageLocation == '4')
    {
        strcpy(aux2, "Banheiro");
    }
    else
    {
        strcpy(aux2, "Wardrobe");
    }

    clear();
    printf(" | ===================== Item List ======================== |\n");
    printf(" |                                                           |\n");
    printf(" | Product name: %s\n", it->productName);
    printf(" | Brand name: %s\n", it->nameBrand);
    printf(" | Barcode: %s\n", it->barCode);
    printf(" | Minimum stock level: %d\n", it->minimumInventory);
    printf(" | Expiration date: %d/%d/%d\n", it->day, it->month, it->year);
    printf(" | Product category: %s\n", aux);
    printf(" | Storage location: %s\n", aux2);
    printf(" | Product quantity: %d\n", it->quantProduct);
    printf(" | Status: %c\n", it->status);
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press any key to exit.... ");
    getchar();
}

int entryItem(void)
{
    FILE *fp;
    Item *it;
    User *customer;
    int found, found2;
    char resp;
    char searched[20];
    int stock, stock1;
    char quantity[20];

    fp = fopen("user.dat", "rb");

    if (fp == NULL)
    {
        printf("Oops! Error opening file!\n");
        getchar();
        return 0;
    }

    it = (Item *)malloc(sizeof(Item));
    customer = (User *)malloc(sizeof(User));

    clear();
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                     Item Entry                            | \n");
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
        char search[20];

        fp3 = fopen("items.dat", "r+b");

        if (fp3 == NULL)
        {
            printf("Oops! Error opening file!\n");
            getchar();
            return 0;
        }

        printf("Enter the product barcode you want to add: ");
        scanf(" %30[^\n]", search);
        getchar();
        found2 = 0;

        while (((!found2) && (fread(it, sizeof(Item), 1, fp3))))
        {
            if ((strcmp(it->barCode, search) == 0) && (it->status == '1'))
            {
                found2 = 1;
            }
        }
        if (found2)
        {
            do
            {
                printf(" | Enter the product quantity: ");
                scanf("%s", quantity);
                getchar();

            } while (!readQuantity(quantity));
            stock = charToInt(quantity);
            stock1 = it->quantProduct + stock;
            it->quantEntry = stock;
            it->quantProduct = stock1;

            do
            {
                printf(" | Enter the product expiration day: ");
                scanf("%d", &it->day);
                getchar();
                printf(" | Enter the month: ");
                scanf("%d", &it->month);
                getchar();
                printf(" | Enter the year: ");
                scanf("%d", &it->year);
                getchar();

            } while (!valida_data(it->day, it->month, it->year));

            it->tipe = 'E';
            printf("Are you sure you want to add this product to the pantry (y/n)? ");
            scanf("%c", &resp);

            if (resp == 'y' || resp == 'Y')
            {

                fseek(fp3, (-1) * sizeof(Item), SEEK_CUR);
                fwrite(it, sizeof(Item), 1, fp3);
                printf("Product added successfully!");
                getchar();
                free(it);
                fclose(fp3);
            }
            else
            {

                printf("Operation canceled!");
                getchar();
            }
        }
        else
        {

            printf("Product not found!");
            getchar();
        }
        free(customer);
        fclose(fp);
    }

    return 0;
}


int exitItem(void)
{
    FILE *fp;
    Item *it;
    User *customer;
    int found, found_item;
    char resp;
    char searched[20];
    int stock, new_stock;
    char quantity[20];
    char search[20];

    fp = fopen("user.dat", "rb");

    if (fp == NULL)
    {
        printf("Oops! Error opening file!\n");
        getchar();
        return 0;
    }

    it = (Item *)malloc(sizeof(Item));
    customer = (User *)malloc(sizeof(User));

    clear();
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                       Item Output                         | \n");
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

        fp3 = fopen("items.dat", "r+b");

        if (fp3 == NULL)
        {
            printf("Oops! Error opening file!\n");
            getchar();
            return 0;
        }

        printf("Enter the bar code of the item you want to remove: ");
        scanf(" %30[^\n]", search);
        getchar();
        found_item = 0;

        while ((!found_item) && (fread(it, sizeof(Item), 1, fp3)))
        {
            if ((strcmp(it->barCode, search) == 0) && (it->status == '1'))
            {
                found_item = 1;
            }
        }
        if (found_item)
        {

            do
            {
                printf(" | Enter the quantity of the item: ");
                scanf("%s", quantity);
                getchar();

            } while (!readQuantity(quantity));
            stock = charToInt(quantity);
            new_stock = it->quantProduct - stock;
            it->quantExit = stock;
            it->quantProduct = new_stock;

            it->tipe = 'S'; // S indicates output

            printf("Are you sure you want to remove this item from the pantry (y/n)? ");
            scanf("%c", &resp);
            getchar();

            if (resp == 'y' || resp == 'Y')
            {

                fseek(fp3, (-1) * sizeof(Item), SEEK_CUR);
                fwrite(it, sizeof(Item), 1, fp3);
                printf("Item removed successfully!");
                getchar();
            }
            else
            {

                printf("Operation canceled!");
                getchar();
            }
            free(it);
            fclose(fp3);
        }
    }
    else
    {

        printf("Item not found!");
        getchar();
    }
    free(customer);
    fclose(fp);

    return 0;
}


int validaCod(char *item)
{
    FILE *fp3;
    Item *usuarioItem;

    usuarioItem = (Item *)malloc(sizeof(Item));

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
        if (strcmp(item, usuarioItem->barCode) == 0 && (usuarioItem->status != '0'))
        {
            fclose(fp3);
            return 0;
        }
    }
    fclose(fp3);

    return 1;
}