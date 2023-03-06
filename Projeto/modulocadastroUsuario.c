#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "modulocadastroUsuario.h"
#include "validacoes.h"

/*
              Bem-vindo(a) ao módulo de cadastro de usuários!
        
        Neste módulo serão cadastrados os usuários no programa

*/


// Este é o menu principal deste módulo
void userRegistrationModule(void)
{    
    char op;
    do {
        op = userMenuScreen();
        switch (op) {
        case '1':
            userInfo(); //cadastro
            break;
        case '2':
            searchUserInfo(); //pesquisa
            break;
        case '3':
            updateUser(); //edição
            break;
        case '4':
            deleteUserInfo(); //exclusão
            break; 
        case '5':
            listUserInfo(); //relatório
            break;
        default:
            printf ("Invalid Option! \n");
            break;
        }

    } while(op != '0');
      
}


// tela que será usada para a escolha da navegação 
char userMenuScreen(void)
{
    char option;
    system ( "cls || clear" );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------- SIG-Pantry - USER MENU ------------------- | \n");
    printf(" | | \n");
    printf(" | 1 - Register user | \n");
    printf(" | 2 - Search data | \n");
    printf(" | 3 - Edit registration | \n");
    printf(" | 4 - Delete user | \n");
    printf(" | 5 - List data | \n");
    printf(" | 0 - Back to main menu | \n");
    printf(" | | \n");
    printf(" | ========================================================= | \n");
    printf(" | Choose an option: ");
    scanf("%s",&option);
    getchar();


    return option;
}


//função para cadastro do usuário no programa 
void userInfo(void)
{
    User* client;

    system(" cls || clear");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                   SIG-Pantry registration                 | \n");
    printf(" | ========================================================= | \n");
    printf(" |                                                           | \n");
    client = (User*) malloc(sizeof(User));

    printf(" | Enter your name: ");
    scanf("%30[^\n]", client->usernameUser);
    getchar();

    do {
        printf(" | Enter your email: ");   
        scanf("%s", client->emailUser);
        getchar();

    } while (!readEmail(client->emailUser));

    do {       
        printf(" | Enter your birth day: ");
        scanf("%d",&client->day);
        getchar();
        printf(" | Enter your birth month: ");
        scanf("%d",&client->month);
        getchar();
        printf(" | Enter your birth year: ");
        scanf("%d",&client->year);
        getchar();
        
    } while(!validateDate(client->day, client->month, client->year));  

    do {

        printf(" | Enter your username: "); 
        scanf("%s",client->usernameUser);
        getchar();

    } while(!((readUsername(client->usernameUser)) && (validateUsername(client->usernameUser))));
        char *date;
        date = getDate();
        strcpy(client->userDate, date);
    
        printf(" | User registered on: %s", date);
        
    printf(" | \nUser successfully registered!                           | \n");
    printf(" | ========================================================= | \n");
    client->status = '1'; // 1 indicates that it was registered
    saveUser(client);
    free(client);
    printf(" | Press any key to exit.... ");
    getchar();      
}


//busca a partir do username (id), visto que cada usuário tem o seu, iremos fazer a busca
int searchUserInfo(void) {
    FILE* fp;
    User* client;
    int found;
    char searched[15]; 
    
    fp = fopen("user.dat", "rb");

    if (fp == NULL) {
        printf("Oops! Error opening the file!\n");
        return 0;
    }   
    
    printf("\n\n");
    system(" cls || clear ");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                     Search user data                      | \n");
    printf(" | ========================================================= | \n");
    printf("Enter your username: ");
    scanf(" %30[^\n]", searched);
    getchar();   
    
    client = (User*) malloc(sizeof(User));  
    
    found = 0;  
    while((!found) && (fread(client, sizeof(User), 1, fp))) {
        if ((strcmp(client->usernameUser, searched) == 0) && (client->status == '1')) {
            found = 1;
        }
    }
    
    if (found) {
        system(" cls || clear" );
        printf(" | ================== User found =================== |\n");
        printf(" |                                                           |\n");
        printf(" | Name: %s\n", client->nameUser);
        printf(" | Username: %s", client->usernameUser);    
        printf(" | E-mail: %s\n", client->emailUser);
        printf(" | Birthday day: %d\n", client->day); 
        printf(" | Birthday month: %d\n", client->month); 
        printf(" | Birthday year: %d\n", client->year); 
        printf(" | Registration date: %s\n", client->userDate);
        printf(" | Status: %c\n", client->status);
        printf(" |                                                           | \n");
        printf(" | ========================================================= | \n");
    
    } else {
        printf("The user's data %s could not be found\n", searched);
    }
    free(client);
    fclose(fp); 
    printf(" | Press any key to exit.... ");
    getchar();
    
    return 0; 
}

//função para editar dados do usuário
int updateUser(void) //adapted by @IsaKaillany
{
    FILE* fp;
    User* client;
    char response;
    int found;
    char search[20];

    fp = fopen("user.dat", "r+b");

    if (fp == NULL) 
    {
        printf("Oops! An error occurred while opening the file!\n");
        return 0;
    }  

    client = (User*) malloc(sizeof(User));  

    system("cls || clear");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ------------------- Update User --------------------------| \n");
    printf(" | Enter your username: ");
    scanf(" %s", search);
    getchar();
    found = 0;

    while((!found) && (fread(client, sizeof(User), 1, fp))) 
    {
        if ((strcmp(client->usernameUser, search) == 0) && (client->status == '1')) 
        {
            found = 1;
        }
    }

    if (found)
    {
        showUserInfo(client);
        response = chooseUpdateOption();
        printf("\n");

        if (response == '1')
        {
            printf(" | Enter the new name: ");
            scanf("%30[^\n]", client->nameUser);
            getchar();

            do
            {
                printf(" | Enter the new email: ");
                scanf(" %49[^\n]", client->emailUser);
                getchar();

            } while(!readEmail(client->emailUser));

            do
            {        
                printf(" | Enter the new day of birth: ");
                scanf("%d",&client->day);
                getchar();
                printf(" | Enter the new month of birth: ");
                scanf("%d",&client->month);
                getchar();
                printf(" | Enter the new year of birth: ");
                scanf("%d",&client->year);
                getchar();

            } while(!validate_date(client->day, client->month, client->year));  
        }
        else if (response == '2')
        {
            printf(" | Enter the new name: ");
            scanf("%30[^\n]", client->nameUser);
            getchar();
        }
        else if (response == '3')
        {
            do
            {
                printf(" | Enter the new email: ");
                scanf(" %49[^\n]", client->emailUser);
                getchar();

            } while(!readEmail(client->emailUser));
        }
        else if (response == '4')
        {
            do
            {        
                printf(" | Enter the new day of birth: ");
                scanf("%d",&client->day);
                getchar();
                printf(" | Enter the new month of birth: ");
                scanf("%d",&client->month);
                getchar();
                printf(" | Enter the new year of birth: ");
                scanf("%d",&client->year);
                getchar();

            } while(!validate_date(client->day, client->month, client->year)); 
        }
        client->status = '1';      
        fseek(fp, (-1)*sizeof(User), SEEK_CUR);
        fwrite(client, sizeof(User), 1, fp);        
        printf(" |                                                           | \n");
        printf(" | --------------------------------------------------------- | \n");
        printf("Data edited successfully!");
    }   
    else 
    {   
        printf("The username %s was not found.\n", search);
    }
    printf(" | Press any key to exit... ");
    getchar();
    free(client);
    fclose(fp);      

    return 0;
}

//função para selecionar o que quer atualizar
char updateMenu(void)
{    
    char choice;
    system(" cls || clear");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ------------------- Update User ------------------------- | \n");
    printf(" |                                                           | \n");
    printf(" |                 1- Edit everything                        | \n");
    printf(" |                 2- Edit name                              | \n");
    printf(" |                 3- Edit email                             | \n");
    printf(" |                 4- Edit date of birth                     | \n");                 
    printf(" |                 0- Return to main menu                    | \n");    
    printf(" |                                                           | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | Select an option of what you want to edit: ");
    scanf("%c", &choice);
    getchar();
    
    return choice;
}


//função para gravar no arquivo
int saveUser(User* client) 
{
    FILE* fp;
    fp = fopen("user.dat", "ab");
    if (fp == NULL) {
        printf("Oops! Unable to continue the program...\n");
        return 0;
    }
    
    fwrite(client, sizeof(User), 1, fp);
    fclose(fp);
    
    return 0;
}

//função para remover o cadastro
int deleteUserInfo(void)
{
    FILE* fp;
    User* user;
    int found;
    char response;
    char searched[20];

    fp = fopen("user.dat", "r+b");

    if (fp == NULL) {
        printf("Oops! Error opening file!\n");
        return 0;
    }

    user = malloc(sizeof(User));

    system("clear || cls");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ---------------------- Delete User ---------------------------- | \n");
    printf(" |                                                                | \n");
    printf(" | Enter the username of the user you want to delete: ");
    scanf("%30[^\n]", searched);
    getchar();
    found = 0;

    while ((!found) && (fread(user, sizeof(User), 1, fp))) {
        if ((strcmp(user->usernameUser, searched) == 0) && (user->status == '1')) {
            found = 1;
        }
    }

    if (found) {
        displayUserInfo(user);
        printf("Do you really want to delete this user's data? (y/n) ");
        scanf(" %c", &response);

        if (response == 'y' || response == 'Y') {
            user->status = '0';
            fseek(fp, (-1) * sizeof(User), SEEK_CUR);
            fwrite(user, sizeof(User), 1, fp);
            printf("\nUser successfully deleted!");
            saveUser(user);
            getchar();
        } else {
            printf("\nAlright, data has not been changed!");
        }
    } else {
        printf("User not found!");
    }

    free(user);
    fclose(fp);
    printf(" | Press any key to exit.... ");
    getchar();

    return 0;
}



//função para listar os dados do usuário 
int listUserInfo(void)
{
    FILE* fp;
    User* user;

    fp = fopen("user.dat", "rb");

    if (fp == NULL) {
        printf("Oops! Error opening file!\n");
        return 0;
    }

    user = (User*)malloc(sizeof(User)); 

    while(fread(user, sizeof(User), 1, fp)) {
        system(" cls || clear");
        printf(" | ==================== User List ====================== | \n");
        printf(" |                                                       | \n");
        displayUserInfo(user);
    } 
    fclose(fp);
    free(user);

    return 0;
}


// função para exibir as informações do usuário
void displayUserInfo(User* user) {
    system("cls || clear");
    printf(" | ================== Registered User ================== |\n");
    printf(" | |\n");
    printf(" | Name: %s\n", user->nameUser);
    printf(" | Username: %s\n", user->usernameUser);
    printf(" | Email: %s\n", user->emailUser);
    printf(" | Birth day: %d\n", user->day);
    printf(" | Birth month: %d\n", user->month);
    printf(" | Birth year: %d\n", user->year);
    printf(" | Register date: %s\n", user->userDate);
    printf(" | Status: %c\n", user->status);
    printf(" | | \n");
    printf(" | ===================================================== | \n");
    printf(" | Press any key to exit.... ");
    getchar();
}


//função para verificar se já tem um username cadastrado no arquivo
int validateUser(char* user)
{
    FILE *fp;
    User *fileUser;

    fileUser = (User*)malloc(sizeof(User));
    
    fp = fopen("user.dat", "rt");
    
    if (fp == NULL){
        printf("Generating file...");
        fclose(fp);
        return 1;
    } 

    while (!feof(fp))
    {
        fread(fileUser, sizeof(User), 1, fp);
        if (strcmp(user, fileUser->usernameUser) == 0 && (fileUser->status != '0')){
            fclose(fp);
            return 0;
        }
    }
    fclose(fp);

    return 1;

}