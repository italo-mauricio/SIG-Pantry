#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloMenuItem.h"
#include "validacoes.h"
#include "modulocadastroUsuario.h"


void moduloMenuItem(void)
{
    char escolha;
    do {
        escolha = telaRegistrarItem();
        switch(escolha) {
        case '1':
            infoItem(); //informações da entrada
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
            listarItens(); //relatório
            break;
        case '6':
            entradaItem(); //adição de item
            break;
        case '7':
            saidaItem(); //retirada de item
            break;      
        default:
            printf("Opção inválida\n");
            break;
        }
     
    } while (escolha != '0');

}


char telaRegistrarItem(void)
{
    char esc;
    system ( " cls || clear " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | --------------------- MENU ITENS ------------------------ | \n");
    printf(" |                                                           | \n");
    printf(" |                 1- Cadastrar Item                         | \n");
    printf(" |                 2- Pesquisar Item                         | \n");                
    printf(" |                 3- Atualizar Item                         | \n");                
    printf(" |                 4- Excluir Item                           | \n");                
    printf(" |                 5- Adicionar Item                         | \n");
    printf(" |                 6- Retirar Item                           | \n");                                                                    
    printf(" |                 0- Voltar à tela principal                | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    getchar();

    return esc;    

}

//Função para cadastrar um item ao estoque
void infoItem(void)
{
    Item* it;
    Mov* mv;
    int resp;
    int i;
    int estoque;
    int estoqueM;
    char quantidade[20];
    char estoqueMin[20];

    system ( " cls || clear " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                    Cadastrar Item                         | \n");
    printf(" |                                                           | \n");    
    it = (Item*)malloc(sizeof(Item));
    mv = (Mov*)malloc(sizeof(Mov));

    printf("Informe quantos itens vão ser cadastrados: ");
    scanf("%d", &resp);

        for (i = 1; i <= resp; i++) {
            do
            {
                printf(" | Informe o nome do produto (sem acentuação): ");
                scanf("%s", it->nomeProduto);
                getchar();
        
            } while (!lerLetras(it->nomeProduto));

            do
            {
                printf(" | Informe o nome da marca: ");
                scanf("%s", it->nomeMarca);
                getchar();
        
            } while (!lerLetras(it->nomeMarca));

            do
            {
                printf(" | Informe o código de barras do produto: ");
                scanf("%s", it->codigoBarras);
                getchar();
                
            } while(!lerQuantidade(it->codigoBarras));


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
            
            do //por enquanto será assim
            {
                system("cls || clear");
                printf(" | ================= Categoria do produto ================= |\n");
                printf(" |                                                          |\n");
                printf(" |                      Higiene pessoal                     |\n");
                printf(" |                      Limpeza                             |\n");
                printf(" |                      Alimento                            |\n");
                printf(" |                                                          |\n");
                printf(" | ======================================================== |\n");
                printf(" | Digite a sua opção: ");
                scanf("%[A-Z a-z]", it->categoria);
                getchar();

            } while (!validarLetras(it->categoria, tamanhoString(it->categoria)));

            do 
            {
                system("cls || clear");
                printf(" | ================ Local de Armazenamento ================ |\n");
                printf(" |                                                          |\n");
                printf(" |                   Geladeira                              |\n");
                printf(" |                   Armário da cozinha                     |\n");
                printf(" |                   Área de serviço                        |\n");
                printf(" |                   Banheiro                               |\n");
                printf(" |                   Guarda-roupa                           |\n");
                printf(" |                                                          |\n");
                printf(" | ======================================================== | \n");
                printf(" | Digite a sua opção: ");
                scanf("%[A-Z a-z]", it->localArmazenamento);
                getchar();

            } while (!validarLetras(it->localArmazenamento, tamanhoString(it->localArmazenamento)));

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
        
            
            do {       
                printf(" | Informe o dia do cadastro: ");
                scanf("%d",&it->diaEnt);
                getchar();
                printf(" | Informe o mês do cadastro: ");
                scanf("%d",&it->mesEnt);
                getchar();
                printf(" | Informe o ano do cadastro: ");
                scanf("%d",&it->anoEnt);
                getchar();
                
            } while(!valida_data(it->dia, it->mes, it->ano));  
            mv->diaEnt = it->diaEnt;
            mv->mesEnt = it->mesEnt;
            mv->anoEnt = it->anoEnt;
            mv->tipo = 'E';
        }

    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    it->status = '1'; //o 1 mostra que foi cadastrado
    gravaItem(it);
    gravaMov(mv);
    free(it);
    free(mv);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();

}

//função para gravar no arquivo
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



//função de pesquisa a partir do código de barras
int buscaInfoItem(void)
{
    FILE* fp;
    Item* it;
    int achou;
    char procurado[15];
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
    fclose(fp);
    if (achou) {
        system(" cls || clear ");
        printf(" | ====================== Buscar Item ====================== |\n");
        printf(" |                                                           |\n");         
        printf(" | Nome do produto: %s\n", it->nomeProduto);    
        printf(" | Nome da marca: %s\n", it->nomeMarca);    
        printf(" | Código de barras: %s\n", it->codigoBarras);    
        printf(" | Estoque mínimo do produto: %d\n", it->estoqueMinimo);
        printf(" | Dia do vencimento: %d\n", it->dia); 
        printf(" | Mês do vencimento: %d\n", it->mes);         
        printf(" | Ano do vencimento: %d\n", it->ano); 
        printf(" | Quantidade do produto: %d\n", it->quantProduto);
        printf(" | Dia do cadastro: %d\n", it->diaEnt);
        printf(" | Mês do cadastro: %d\n", it->mesEnt);
        printf(" | Ano do cadastro: %d\n", it->anoEnt);
        printf(" | Status: %c\n", it->status);
        printf(" |                                                           | \n");
        printf(" | ========================================================= | \n");

    } else {
        printf("Os dados do cadastro %s não foram encontrados\n", procurado);
    }
    free(it);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    return 0;
    
}

//função para editar algum item
int telaAtualizarItem(void)  
{
    FILE *fp;
    Item* it;
    Mov* mv;
    char resp;
    int achou;
    int estoque;
    int estoqueM;
    char quantidade[20];
    char procurado[20];
    char estoqueMin[20];

    fp = fopen("itens.dat", "r+b");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }
    system(" cls || clear");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------------- Atualizar item --------------------- | \n");
    printf("Informe o código de barras cadastrado: ");
    scanf(" %[0-9]", procurado);
    getchar();

    it = (Item*) malloc(sizeof(Item));
    mv = (Mov*) malloc(sizeof(Mov));
    achou = 0;
    while((!achou) && (fread(it, sizeof(Item), 1, fp))) {
        if ((strcmp(it->codigoBarras, procurado) == 0) && (it->status == '1')) {
            achou = 1;
        }
    }

    if (achou){

        listarItens();
        resp = escAtualizarItem();
        printf("\n");

        if (resp == '1'){
            do
            {
                printf("Informe o novo nome do produto: ");
                scanf("%s", it->nomeProduto);
                getchar();

            } while (!lerLetras(it->nomeProduto));

            do
            {
                printf(" | Informe o novo nome da marca: ");
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
            
            do //por enquanto será assim
            {
                system("cls || clear");
                printf(" | ================= Categoria do produto ================= |\n");
                printf(" |                                                          |\n");
                printf(" |                      Higiene pessoal                     |\n");
                printf(" |                      Limpeza                             |\n");
                printf(" |                      Alimento                            |\n");
                printf(" |                                                          |\n");
                printf(" | ======================================================== |\n");
                printf(" | Digite a sua opção: ");
                scanf("%[A-Z a-z]", it->categoria);
                getchar();

            } while (!validarLetras(it->categoria, tamanhoString(it->categoria)));

            do 
            {
                system("cls || clear");
                printf(" | ================ Local de Armazenamento ================ |\n");
                printf(" |                                                          |\n");
                printf(" |                   Geladeira                              |\n");
                printf(" |                   Armário da cozinha                     |\n");
                printf(" |                   Área de serviço                        |\n");
                printf(" |                   Banheiro                               |\n");
                printf(" |                   Guarda-roupa                           |\n");
                printf(" |                                                          |\n");
                printf(" | ======================================================== | \n");
                printf(" | Digite a sua opção: ");
                scanf("%[A-Z a-z]", it->localArmazenamento);
                getchar();

            } while (!validarLetras(it->localArmazenamento, tamanhoString(it->localArmazenamento)));

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
                printf("Informe o novo nome do produto: ");
                scanf("%s", it->nomeProduto);
                getchar();

            } while (!lerLetras(it->nomeProduto));

        }

        else if (resp == '3') {            
            do
            {
                printf(" | Informe o novo nome da marca: ");
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
            do //por enquanto será assim
            {
                system("cls || clear");
                printf(" | ================= Categoria do produto ================= |\n");
                printf(" |                                                          |\n");
                printf(" |                      Higiene pessoal                     |\n");
                printf(" |                      Limpeza                             |\n");
                printf(" |                      Alimento                            |\n");
                printf(" |                                                          |\n");
                printf(" | ======================================================== |\n");
                printf(" | Digite a nova categoria: ");
                scanf("%[A-Z a-z]", it->categoria);
                getchar();

            } while (!validarLetras(it->categoria, tamanhoString(it->categoria)));

        }

        else if (resp == '7') {
            do 
            {
                system("cls || clear");
                printf(" | ================ Local de Armazenamento ================ |\n");
                printf(" |                                                          |\n");
                printf(" |                   Geladeira                              |\n");
                printf(" |                   Armário da cozinha                     |\n");
                printf(" |                   Área de serviço                        |\n");
                printf(" |                   Banheiro                               |\n");
                printf(" |                   Guarda-roupa                           |\n");
                printf(" |                                                          |\n");
                printf(" | ======================================================== | \n");
                printf(" | Digite a sua nova opção: ");
                scanf("%[A-Z a-z]", it->localArmazenamento);
                getchar();

            } while (!validarLetras(it->localArmazenamento, tamanhoString(it->localArmazenamento)));
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
    
    }else {
        printf("O item de código de barras %s não foi encontrado\n", procurado);
    }

    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    free(it);
    free(mv);
    fclose(fp);
    gravaItem(it);      
    
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
    }

   if (achou){
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

//listar itens
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
    while(fread(it, sizeof(Item), 1, fp)) 
    {
        system(" cls || clear");
        printf(" | ===================== Lista de Itens ==================== |\n");
        printf(" |                                                           |\n");       
        printf(" | Nome do produto: %s\n", it->nomeProduto);    
        printf(" | Nome da marca: %s\n", it->nomeMarca);    
        printf(" | Código de barras: %s\n", it->codigoBarras);    
        printf(" | Estoque mínimo do produto: %d\n", it->estoqueMinimo);
        printf(" | Dia do vencimento: %d\n", it->dia); 
        printf(" | Mês do vencimento: %d\n", it->mes);         
        printf(" | Ano do vencimento: %d\n", it->ano); 
        printf(" | Quantidade do produto: %d\n", it->quantProduto);
        printf(" | Dia da entrada: %d\n", it->diaEnt);
        printf(" | Mês da entrada: %d\n", it->mesEnt);
        printf(" | Ano da entrada: %d\n", it->anoEnt);
        printf(" | Status: %c\n", it->status);
        printf(" |                                                           | \n");
        printf(" | ========================================================= | \n");
        printf(" | Pressione qualquer tecla para sair.... ");
        getchar();
        
    }

    fclose(fp);
    free(it);
    return 0;

}

//função para adição de produtos à despensa
int entradaItem(void) 
{
    FILE* fp;
    Item* it;
    Mov* mv;
    int achou;
    int resp;
    int i;
    int estoque;
    char quantidade[20];
    char procura[20];
    
    fp = fopen("itens.dat", "rb");

    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }

    fp = fopen("movimento.dat", "rb");
    
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }


    system ( " cls || clear " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                     Entrada Item                          | \n");
    printf(" |                                                           | \n"); 
    printf("Informe o código de barras: ");
    scanf(" %30[^\n]", procura);
    getchar();
    achou = 0;
    while((!achou) && (fread(it, sizeof(Item), 1, fp))) {
        if ((strcmp(it->codigoBarras, procura) == 0) && (it->status == '1')) {
            achou = 1;
        }  
    it = (Item*)malloc(sizeof(Item));
    mv = (Mov*)malloc(sizeof(Mov));

    
    }
    if (achou){
         printf("Informe quantos itens vão entrar: ");
         scanf("%d", &resp);
        for (i = 1; i <= resp; i++) {
            do
            {
                printf(" | Informe o código de barras do produto: ");
                scanf("%s", it->codigoBarras);
                getchar();
                
            } while(!lerQuantidade(it->codigoBarras));

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
        
            
            do {       
                printf(" | Informe o dia da entrada: ");
                scanf("%d",&it->diaEnt);
                getchar();
                printf(" | Informe o mês da entrada: ");
                scanf("%d",&it->mesEnt);
                getchar();
                printf(" | Informe o ano da entrada: ");
                scanf("%d",&it->anoEnt);
                getchar();
                
            } while(!valida_data(it->dia, it->mes, it->ano));  
            mv->diaEnt = it->diaEnt;
            mv->mesEnt = it->mesEnt;
            mv->anoEnt = it->anoEnt;
            mv->tipo = 'E'; //E indica entrada
//tem que perguntar se tem certeza que deseja fazer a entrada, uma vez que n faremos o atualizar entrada
        }
        }else{
            printf("Produto não encontrado!");
        }

    fclose(fp);
    free(it);
    free(mv);

    return 0;
    
}

//função para retirada de produto da despensa
int saidaItem(void) 
{
    FILE* fp;
    Item* it;
    Mov* mv;
    int resp;
    int i;
    int estoque;
    char quantidade[20];
    char procura[20];
    int achou;
    
    fp = fopen("itens.dat", "rb");

    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }

    fp = fopen("movimento.dat", "rb");
    
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        return 0;
    }

    it = (Item*)malloc(sizeof(Item));
    mv = (Mov*)malloc(sizeof(Mov));
    system ( " cls || clear " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                      Saída Item                           | \n");
    printf(" |                                                           | \n");    
    printf("Informe o código de barras: ");
    scanf(" %30[^\n]", procura);
    getchar();
    achou = 0;
    while((!achou) && (fread(it, sizeof(Item), 1, fp))) {
        if ((strcmp(it->codigoBarras, procura) == 0) && (it->status == '1')) {
            achou = 1;
        }  

    
    }
    if (achou){
    
       for (i = 1; i <= resp; i++) {
            printf("Informe quantos itens vão entrar: ");
            scanf("%d", &resp);

            do
            {
                printf(" | Informe o código de barras do produto: ");
                scanf("%s", it->codigoBarras);
                getchar();
                
            } while(!lerQuantidade(it->codigoBarras));

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
                printf(" | Informe o dia de retirada: ");
                scanf("%d",&it->diaSaida);
                getchar();
                printf(" | Informe o mês de retirada: ");
                scanf("%d",&it->mesSaida);
                getchar();
                printf(" | Informe o ano de retirada: ");
                scanf("%d",&it->anoSaida);
                getchar();
                
            } while(!valida_data(it->dia, it->mes, it->ano));  
            mv->diaSaida = it->diaSaida;
            mv->mesSaida = it->mesSaida;
            mv->anoSaida = it->anoSaida;
            mv->tipo = 'S'; //S representa saída
//tem que perguntar se tem certeza que deseja fazer a saída, uma vez que n faremos o atualizar 

        }
    }else{
        printf("Produto não encontrado!");
    }

    fclose(fp);
    free(it);
    free(mv);

    return 0;
    
}
