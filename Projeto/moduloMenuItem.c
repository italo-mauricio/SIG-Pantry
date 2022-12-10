#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloMenuItem.h"
#include "validacoes.h"
#include "modulocadastroUsuario.h"


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
char telaRegistrarItem(void)
{
    char esc;
    system ( " cls || clear " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | --------------------- MENU ITENS ------------------------ | \n");
    printf(" |                                                           | \n");
    printf(" |                 1- Cadastrar um novo item                 | \n");
    printf(" |                 2- Pesquisar item                         | \n");                
    printf(" |                 3- Atualizar item                         | \n");                
    printf(" |                 4- Excluir item                           | \n");                
    printf(" |                 5- Adicionar item                         | \n");
    printf(" |                 6- Retirar item                           | \n"); 
    printf(" |                 7- Listar itens                           | \n");                                                                   
    printf(" |                 0- Voltar à tela principal                | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    getchar();
    return esc;    

}


//função para cadastrar um novo item ao estoque
int infoItem(void)
{
    FILE* fp;
    Item* it;
    Mov* mv;
    Usuario* cliente;
    int estoque;
    int estoqueM;
    int achou;
    char quantidade[20];
    char estoqueMin[20];
    char procurado[20]; 
    
    fp = fopen("usuario.dat", "rb");
    
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        getchar();
        return 0;
    }

    it = (Item*)malloc(sizeof(Item));
    mv = (Mov*)malloc(sizeof(Mov));
    cliente = (Usuario*)malloc(sizeof(Usuario));
    system ( " cls || clear " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                    Cadastrar Item                         | \n");
    printf(" |                                                           | \n");
    printf(" | Por favor, digite o seu username: ");    
    scanf(" %30[^\n]", procurado);
    getchar();     
    achou = 0;  
    

    while ((!achou) && (fread(cliente, sizeof(Usuario), 1, fp))){
        if ((strcmp(cliente->usernameUsuario, procurado) == 0) && (cliente->status == '1')){
            achou = 1;
        }
    }
    if (achou){
        FILE* fp1;
        fp1 = fopen("itens.dat", "ab");
        if (fp1 == NULL) {
            printf("Ops! Erro na abertura do arquivo!\n");
            getchar();
            return 0;
        }
            
            do
            {
                printf(" | Informe o nome do produto (sem acentuação): ");
                scanf("%s", it->nomeProduto);
                getchar();
        
            } while (!lerLetras(it->nomeProduto));
            do
            {
                printf(" | Informe o nome da marca (sem acentuação): ");
                scanf("%s", it->nomeMarca);
                getchar();
        
            } while (!lerLetras(it->nomeMarca));
            do
            {
                printf(" | Informe o código de barras do produto: ");
                scanf("%s", it->codigoBarras);
                getchar();
                
            }while(!((lerQuantidade(it->codigoBarras)) && (validaCod(it->codigoBarras))));
            do
            {
                printf(" | Informe o estoque mínimo desse produto: ");
                scanf("%s", estoqueMin);
                getchar();
                
            } while(!lerQuantidade(estoqueMin));
            
            estoqueM = charParaInt(estoqueMin);
            it->estoqueMinimo = estoqueM;    

            do 
            {        
                printf(" | Informe o dia de vencimento: ");
                scanf("%d", &it->dia);
                getchar();
                printf(" | Informe o mês: ");
                scanf("%d", &it->mes);
                getchar();
                printf(" | Informe o ano: ");
                scanf("%d", &it->ano);
                getchar();              
            } while(!valida_data(it->dia, it->mes, it->ano)); 
            
            it->categoria = telaEscCategoria();
            it->localArmazenamento = telaEscLocalArmaz();

            do
            {
                
                printf(" | Informe a quantidade de produtos: ");
                scanf("%s", quantidade);            
                getchar();
            
            } while(!lerQuantidade(quantidade));    
            
            estoque = charParaInt(quantidade);
            it->quantProduto = estoque; 
            mv->quantMovimento = estoque;
            strcpy(mv->codigoBarras, it->codigoBarras);              
            char *data;

            data = verDiaMesAno();
  
            strcpy(mv->dataAtual, data);
            strcpy(it->dataAtual, data);
            printf("Cadastro realizado na data: %s", data);  
            mv->tipo = 'E';
            
            it->status = '1'; //o 1 mostra que foi cadastrado              
            gravaItem(it);
            gravaMov(mv);
            free(it);
            free(mv);
            fclose(fp1);
                
   

    } else {
        printf("Usuário não encontrado");
    }
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    free(cliente);
    fclose(fp);    
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    return 0;
}



//função para escolha da categoria
char telaEscCategoria(void)
{
    char esc;
    system("cls || clear");
    printf(" | ================= Categoria do produto ================= |\n");
    printf(" |                                                          |\n");
    printf(" |                    1- Higiene pessoal                    |\n");
    printf(" |                    2- Limpeza                            |\n");
    printf(" |                    3- Alimento                           |\n");
    printf(" |                                                          |\n");
    printf(" | ======================================================== |\n");
    printf(" | Digite uma opção: ");
    scanf("%c", &esc);
    getchar();
    return esc;
}



//função para escolha do local de armazenamento
char telaEscLocalArmaz(void)
{
    char esc;
    system("cls || clear");
    printf(" | ================ Local de Armazenamento ================ |\n");
    printf(" |                                                          |\n");
    printf(" |                   1- Geladeira                           |\n");
    printf(" |                   2- Armário da cozinha                  |\n");
    printf(" |                   3- Área de serviço                     |\n");
    printf(" |                   4- Banheiro                            |\n");
    printf(" |                   5- Guarda-roupa                        |\n");
    printf(" |                                                          |\n");
    printf(" | ======================================================== |\n");
    printf(" | Digite a sua opção: ");
    scanf("%c", &esc);
    getchar();
    return esc;
}


//função para gravar no arquivo de item
int gravaItem(Item* it) 
{
    FILE* fp;
    
    fp = fopen("itens.dat", "ab");
    
    if (fp == NULL) {
        printf("Ops! Não é possível continuar o programa...\n");
        return 0;
    }  
    fwrite(it, sizeof(Item), 1, fp);
    fclose(fp);
    
    return 0;

}


// função para gravar no arquivo de movimento
int gravaMov(Mov* mv) 
{
    FILE* fp;
    
    fp = fopen("movimento.dat", "ab");
    
    if (fp == NULL) {
        printf("Ops! Não é possível continuar o programa...\n");
        return 0;
    }   
    fwrite(mv, sizeof(Mov), 1, fp);
    fclose(fp);
    return 0;

}


//função de pesquisa a partir do código de barras (id do item)
int buscaInfoItem(void)
{
    FILE* fp;
    Item* it;
    int achou;
    char procurado[15];
    char aux[20];
    char aux2[20]; 
    fp = fopen("itens.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    printf("\n\n");
    system ( " cls || clear " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                   Buscar dados de Itens                   | \n");
    printf(" | ========================================================= | \n");
    printf("Informe o código de barras: ");
    scanf(" %30[^\n]", procurado);
    getchar();  
    it = (Item*) malloc(sizeof(Item));
    achou = 0;


    while((!achou) && (fread(it, sizeof(Item), 1, fp))) {
        printf("Código de barras |%s|\n", it->codigoBarras);
        
        if ((strcmp(it->codigoBarras, procurado) == 0) && (it->status == '1')) {
            achou = 1;
        }
    
    } 
    if (achou) {

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
        system(" cls || clear");
        printf(" | ===================== Lista de Itens ==================== |\n");
        printf(" |                                                           |\n");       
        printf(" | Nome do produto: %s\n", it->nomeProduto);    
        printf(" | Nome da marca: %s\n", it->nomeMarca);    
        printf(" | Código de barras: %s\n", it->codigoBarras);    
        printf(" | Estoque mínimo do produto: %d\n", it->estoqueMinimo);
        printf(" | Data de vencimento: %d/%d/%d\n", it->dia, it->mes, it->ano);
        printf(" | Dia da entrada: %s\n", it->dataAtual); 
        printf(" | Categoria do produto: %s\n", aux);
        printf(" | Local de armazenamento: %s\n", aux2);
        printf(" | Quantidade do produto: %d\n", it->quantProduto);
        printf(" | Status: %c\n", it->status);
        printf(" |                                                           | \n");
        printf(" | ========================================================= | \n");
        getchar();
        
    } else {
    
        printf("Os dados do item cadastrado %s não foram encontrados\n", procurado);
    
    } 
    free(it);
    fclose(fp);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    return 0;
    
}


//função para editar algum item
int telaAtualizarItem(void)  
{
    FILE* fp2;
    Mov* mv;
    Usuario* cliente;
    char resp;
    int achou;
    int encontrou;
    int estoque;
    int estoqueM;
    char quantidade[20];
    char procurado[20];
    char estoqueMin[20];
    char procura[20];
    
    fp2 = fopen("usuario.dat", "r+b");
    
    if (fp2 == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }
    cliente = (Usuario*)malloc(sizeof(Usuario));

    mv = (Mov*)malloc(sizeof(Mov));
    
    system(" cls || clear");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------------- Atualizar item --------------------- | \n");
    printf(" |                                                           | \n");
    printf(" | Informe o seu username: ");
    scanf(" %30[^\n]", procurado);
    getchar();   
    achou = 0;


    while ((!achou) && (fread(cliente, sizeof(Usuario), 1, fp2))){
        if ((strcmp(cliente->usernameUsuario, procurado) == 0) && (cliente->status == '1')){
            achou = 1;
        }
    }if (achou){

        FILE *fp;
        Item* it;
        it = (Item*)malloc(sizeof(Item));
        fp = fopen("itens.dat", "r+b");
        
        if (fp == NULL) 
        {
            printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
            return 0;
        }
    
        printf("Informe o código de barras do item que deseja alterar: ");
        scanf(" %[0-9]", procura);
        getchar();    
        encontrou = 0;


        while((!encontrou) && (fread(it, sizeof(Item), 1, fp))) {
            if ((strcmp(it->codigoBarras, procura) == 0) && (it->status == '1')) {
                encontrou = 1;
            }
        }
        if (encontrou){

            buscaInfoItem();
            resp = escAtualizarItem();
            printf("\n");

            if (resp == '1'){
                
                do
                {
                    printf("Informe o novo nome do produto (sem acentuação): ");
                    scanf("%s", it->nomeProduto);
                    getchar();

                } while (!lerLetras(it->nomeProduto));
                do
                {
                    printf(" | Informe o novo nome da marca (sem acentuação): ");
                    scanf("%s", it->nomeMarca);
                    getchar();
            
                } while (!lerLetras(it->nomeMarca));           
                do
                {
                    printf(" | Informe o estoque mínimo desse produto: ");
                    scanf("%s", estoqueMin);
                    getchar();
                    
                } while(!lerQuantidade(estoqueMin));          
                estoqueM = charParaInt(estoqueMin);
                it->estoqueMinimo = estoqueM;
                do 
                {        
                    printf(" | Informe o novo dia de vencimento: ");
                    scanf("%d", &it->dia);
                    getchar();
                    printf(" | Informe o mês: ");
                    scanf("%d", &it->mes);
                    getchar();
                    printf(" | Informe o ano: ");
                    scanf("%d", &it->ano);
                    getchar();
                    
                } while(!valida_data(it->dia, it->mes, it->ano));            
                it->categoria = telaEscCategoria();
                it->localArmazenamento = telaEscLocalArmaz();
                do
                {
                    printf(" | Informe a quantidade de produtos: ");
                    scanf("%s", quantidade);           
                    getchar();
                
                } while(!lerQuantidade(quantidade));
                
                estoque = charParaInt(quantidade);
                it->quantProduto = estoque;
                mv->quantMovimento = estoque;
                strcpy(mv->codigoBarras, it->codigoBarras);
            
            }
            else if (resp == '2') {
                
                do
                {
                    printf("Informe o novo nome do produto (sem acentuação): ");
                    scanf("%s", it->nomeProduto);
                    getchar();

                } while (!lerLetras(it->nomeProduto));

            }
            else if (resp == '3') {            
                
                do
                {
                    printf(" | Informe o novo nome da marca (sem acentuação): ");
                    scanf("%s", it->nomeMarca);
                    getchar();
            
                } while (!lerLetras(it->nomeMarca));

            }
            else if (resp == '4'){
                
                do
                {
                    printf(" | Informe o estoque mínimo desse produto: ");
                    scanf("%s", estoqueMin);
                    getchar();
                    
                } while(!lerQuantidade(estoqueMin));
                
                estoqueM = charParaInt(estoqueMin);
                it->estoqueMinimo = estoqueM;

            }
            else if (resp == '5'){
                do
                {        
                    printf(" | Informe o novo dia de vencimento: ");
                    scanf("%d", &it->dia);
                    getchar();
                    printf(" | Informe o novo mês de vencimento: ");
                    scanf("%d", &it->mes);
                    getchar();
                    printf(" | Informe o novo ano de vencimento: ");
                    scanf("%d", &it->ano);
                    getchar();
            
                } while(!valida_data(it->dia, it->mes, it->ano));  

            }
            else if (resp == '6') {
                
                it->categoria = telaEscCategoria();

            }
            else if (resp == '7') {
                
                it->localArmazenamento = telaEscLocalArmaz();

            }
            else if (resp == '8'){
                
                do
                {
                    
                printf(" | Informe a quantidade de produtos: ");
                scanf("%s", quantidade);            
                getchar();
                
                } while(!lerQuantidade(quantidade));
        
                estoque = charParaInt(quantidade);
                it->quantProduto = estoque;
                mv->quantMovimento = estoque;
                strcpy(mv->codigoBarras, it->codigoBarras);

            }
            it->status = '1';      
            fseek(fp, (-1)*sizeof(Item), SEEK_CUR);
            fwrite(it, sizeof(Item), 1, fp);        
            printf(" |                                                           | \n");
            printf(" | --------------------------------------------------------- | \n");
            printf("Dados editados com sucesso");
            gravaItem(it);
            free(it);
            fclose(fp);     
        }else {
            
            printf("O item de código de barras %s não foi encontrado\n", procurado);
        
        }
    
    } else {
    
        printf("O usuário não foi encontrado");
    }

    free(cliente); 
    fclose(fp2);    
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();       
    return 0; 
}


//função para selecionar o que quer atualizar
char escAtualizarItem(void)
{    
    char esc;
    system(" cls || clear");
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
    FILE* fp;
    Item* it;
    int achou;
    char resp;
    char procurado[20];
    
    fp = fopen("itens.dat", "r+b");

    if (fp == NULL){
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }
    it = (Item*) malloc(sizeof(Item));  
    system( " clear || cls ");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ------------------------ Excluir item ------------------------ | \n");
    printf(" |                                                                | \n");
    printf(" | Informe o código de barras do item que você deseja excluir: ");
    scanf(" %30[^\n]", procurado);
    getchar();    
    achou = 0;


    while ((!achou) && (fread(it, sizeof(Item), 1, fp))){
        if ((strcmp(it->codigoBarras, procurado) == 0) && (it->status == '1')){
            achou = 1;
        }
    }if (achou){

        listarItens();
        printf("Deseja realmente excluir os dados deste item? (s/n)");
        scanf("%c", &resp);

        if (resp == 's' || resp == 'S'){
            
            it->status = '0';
            fseek(fp, (-1)*sizeof(Item), SEEK_CUR);
            fwrite(it, sizeof(Item), 1, fp);
            printf("\nDados do item excluídos com sucesso!");
            gravaItem(it);
            
        }else{
            
            printf("\nTudo bem, os dados não foram alterados!");
        
        }

    }else{     
        printf("O item não foi encontrado!");  
    }
    free(it);
    fclose(fp);  
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    return 0;
    
}


//listar itens - relatório sem filtro
int listarItens(void) 
{
    FILE* fp;
    Item* it;
    
    fp = fopen("itens.dat", "rb");
    
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }

    it = (Item*)malloc(sizeof(Item)); 

    while(fread(it, sizeof(Item), 1, fp)) {
        system(" cls || clear");
        printf(" | ===================== Lista itens ======================= | \n");
        printf(" |                                                           | \n");
        exibeInfoItem(it);
    } 
    fclose(fp);
    free(it);
    
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

    system(" cls || clear");
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
    Mov* mv;
    Usuario* cliente;
    int achou;
    char resp;
    char procurado[20];
    int estoque;
    char quantidade[20];
    
    fp = fopen("usuario.dat", "rb");

    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        getchar();
        return 0;
    }
    it = (Item*)malloc(sizeof(Item));
    mv = (Mov*)malloc(sizeof(Mov));    
    cliente = (Usuario*)malloc(sizeof(Usuario));
    system ( " cls || clear " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                     Entrada Item                          | \n");
    printf(" |                                                           | \n"); 
    printf(" | Informe o seu username: ");
    scanf(" %30[^\n]", procurado);
    getchar();     
    achou = 0;  


    while ((!achou) && (fread(cliente, sizeof(Usuario), 1, fp))){
        if ((strcmp(cliente->usernameUsuario, procurado) == 0) && (cliente->status == '1')){
            achou = 1;
        }
    }if (achou){
        
        FILE* fp1;
        FILE* fp2;
        char procura[20];
        fp1 = fopen("itens.dat", "ab");
        if (fp1 == NULL) {
            printf("Ops! Erro na abertura do arquivo!\n");
            getchar();
            return 0;
        }
        fp2 = fopen("movimento.dat", "ab");

        if (fp2 == NULL) {
            printf("Ops! Erro na abertura do arquivo!\n");
            getchar();
            return 0;
        }                 
        printf("Informe o código de barras do produto que deseja adicionar: ");
        scanf(" %30[^\n]", procura);
        getchar();      
        achou = 0;
    
        while((!achou) && (fread(it, sizeof(Item), 1, fp))) {
            if ((strcmp(it->codigoBarras, procura) == 0) && (it->status == '1')) {
            achou = 1;
            }  

        }if (achou){
            do
            {
                printf(" | Informe a quantidade de produto: ");
                scanf("%s", quantidade);             
                getchar();
                
            } while(!lerQuantidade(quantidade));
            estoque = charParaInt(quantidade);
            it->quantProduto =+ estoque;
            mv->quantMovimento = estoque;
            strcpy(mv->codigoBarras, it->codigoBarras);      
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

            printf("Tem certeza que deseja adicionar este produto à despensa? s/n");
            scanf("%c", &resp); 

                if (resp == 's' || resp == 'S') {
                    
                    printf("Produto adicionado com sucesso!");
                    gravaItem(it);
                    gravaMov(mv);
                    free(it);
                    free(mv);
                    fclose(fp1);
                    fclose(fp2);

                }      
                else {
                    
                    printf("Operação cancelada!");         
                }
              }

        }else{
            
            printf("Produto não encontrado!");
        
        }  
    free(cliente);
    fclose(fp); 
    return 0;

}    


//função para retirada de produto da despensa
int saidaItem(void) 
{
    FILE* fp;
    Item* it;
    Mov* mv;
    Usuario* cliente;
    int achou;
    int encontrou;
    char resp;
    char procurado[20];
    int estoque;
    char quantidade[20];
    char procura[20];  
    fp = fopen("usuario.dat", "rb");

    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        getchar();
        return 0;
    }

    it = (Item*)malloc(sizeof(Item));
    mv = (Mov*)malloc(sizeof(Mov));
    cliente = (Usuario*)malloc(sizeof(Usuario));
    system ( " cls || clear " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                       Saída Item                          | \n");
    printf(" |                                                           | \n"); 
    printf(" | Informe o seu username: ");
    scanf(" %30[^\n]", procurado);
    getchar();     
    achou = 0;

    while ((!achou) && (fread(cliente, sizeof(Usuario), 1, fp))){
        if ((strcmp(cliente->usernameUsuario, procurado) == 0) && (cliente->status == '1')){
            achou = 1;
        }
    }if (achou){

        FILE* fp1;
        FILE* fp2;
        fp1 = fopen("itens.dat", "ab");

        if (fp1 == NULL) {
            printf("Ops! Erro na abertura do arquivo!\n");
            getchar();
            return 0;
        }
        fp2 = fopen("movimento.dat", "ab");

        if (fp2 == NULL) {
            printf("Ops! Erro na abertura do arquivo!\n");
            getchar();
            return 0;
        }
            
        printf("Informe o código de barras do produto que deseja retirar: ");
        scanf(" %30[^\n]", procura);
        getchar();     
        encontrou = 0;
    
        while((!encontrou) && (fread(it, sizeof(Item), 1, fp))) {
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
            it->quantProduto =- estoque;
            mv->quantMovimento = estoque;
            strcpy(mv->codigoBarras, it->codigoBarras);

            do {       
                printf(" | Informe o dia da retira: ");
                scanf("%d",&it->diaSaida);
                getchar();
                printf(" | Informe o mês da retirada: ");
                scanf("%d",&it->mesSaida);
                getchar();
                printf(" | Informe o ano da retirada: ");
                scanf("%d",&it->anoSaida);
                getchar();
                    
            } while(!valida_data(it->dia, it->mes, it->ano));  
                
                mv->diaSaida = it->diaSaida;
                mv->mesSaida = it->mesSaida;
                mv->anoSaida = it->anoSaida;
                mv->tipo = 'S'; //S indica saída

            printf("Tem certeza que deseja remover este produto da despensa? s/n");
            scanf("%c", &resp); 

                if (resp == 's' || resp == 'S') {
                    
                    printf("Produto removido com sucesso!");
                    gravaItem(it);
                    gravaMov(mv);
                    free(it);
                    free(mv);
                    fclose(fp1);
                    fclose(fp2);

                }        
                else {
                    
                    printf("Operação cancelada!");
                
                }
             }

        }else{
            
            printf("Produto não encontrado!");
        
        }  
    free(cliente);
    fclose(fp);   
    return 0;
    
}



//função para não permitir código de barras iguais
int validaCod(char* item)
{
    FILE *fp;
    Item *usuarioItem;

    usuarioItem = (Item*)malloc(sizeof(Item));
    
    fp = fopen("itens.dat", "rt");
    
    if (fp == NULL)
    {
        printf("Gerando arquivo...");
        fclose(fp);
        return 1;
    }
    while (!feof(fp))
    {
        fread(usuarioItem, sizeof(Item), 1, fp);
        if (strcmp(item, usuarioItem->codigoBarras) == 0 && (usuarioItem->status != '0'))
        {
            fclose(fp);
            return 0;
        }
    }
    fclose(fp);
    return 1;

}