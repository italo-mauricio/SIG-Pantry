#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloEntradaItens.h"
#include "validacoes.h"
#include "modulocadastroUsuario.h"
#include "modulomenuItem.h"
#include "moduloSaidaItens.h"


void menuEntradaItens(void)
{
    char escolha;
    do {
        escolha = telaRegistrarEntrada();
        switch(escolha) {
        case '1':
            infoEntrada(); //informações da entrada
            break;
        case '2':
            buscaInfoEntrada(); //pesquisa
            break;
        case '3':
            telaAtualizarEntrada(); //edição
            break;
        case '4':
            excluirEntrada(); //exclusão
            break;
        case '5':
            listarEntradas(); //relatório
            break;      
        default:
            printf("Opção inválida\n");
            break;
        }
     
    } while (escolha != '0');

}


char telaRegistrarEntrada(void)
{
    char esc;
    system ( " cls || clear " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------- REGISTRAR ENTRADA DE ITENS NA DESPENSA --------- | \n");
    printf(" |                                                           | \n");
    printf(" |                 1- Cadastrar entrada                      | \n");
    printf(" |                 2- Pesquisar entrada                      | \n");                
    printf(" |                 3- Atualizar entrada                      | \n");                
    printf(" |                 4- Excluir entrada                        | \n");                
    printf(" |                 5- Listar entrada                         | \n");                                                                    
    printf(" |                 0- Voltar à tela principal                | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    getchar();

    return esc;    

}

//Função para cadastrar a entrada de um item ao estoque
void infoEntrada(void)
{
    Item* it;
    int resp;
    int i;
    system ( " cls || clear " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------- Registrar entrada de item ---------------- | \n");
    printf(" |                                                           | \n");    
    it = (Item*)malloc(sizeof(Item));

    printf("Informe quantos itens vão ser adicionados à despensa: ");
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
                scanf("%s", it->estoqueMinimo);
                getchar();
                
            } while(!lerQuantidade(it->estoqueMinimo));

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
                printf(" | Informe a quantidade de produto: ");
                scanf("%s", it->quantProduto);    // adicionar o cálculo de entrada
                getchar();
                
            } while(!lerQuantidade(it->quantProduto));
        }

    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    it->status = '1'; //o 1 mostra que foi cadastrado
    gravaItem(it);
    free(it);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();

}

//função de pesquisa a partir do código de barras
int buscaInfoEntrada(void)
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
    printf(" |                   Buscar dados da entrada                 | \n");
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
        printf(" | ================== Entrada encontrada =================== |\n");
        printf(" |                                                           |\n");         
        printf(" | Nome do produto: %s\n", it->nomeProduto);    
        printf(" | Nome da marca: %s\n", it->nomeMarca);    
        printf(" | Código de barras: %s\n", it->codigoBarras);    
        printf(" | Estoque mínimo do produto: %s\n", it->estoqueMinimo);
        printf(" | Dia do vencimento: %d\n", it->dia); 
        printf(" | Mês do vencimento: %d\n", it->mes);         
        printf(" | Ano do vencimento: %d\n", it->ano); 
        printf(" | Quantidade do produto: %s\n", it->quantProduto);
        printf(" | Status: %c\n", it->status);
        printf(" |                                                           | \n");
        printf(" | ========================================================= | \n");

    } else {
        printf("Os dados da entrada %s não foram encontrados\n", procurado);
    }
    free(it);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    return 0;
    
}

//função para editar algum item
int telaAtualizarEntrada(void)  
{
    FILE *fp;
    Item* it;
    char resp;
    int achou;
    char procurado[20];

    fp = fopen("itens.dat", "r+b");
    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }
    system(" cls || clear");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ------------------- Atualizar entrada ------------------- | \n");
    printf("Informe o código de barras cadastrado: ");
    scanf(" %[0-9]", procurado);
    getchar();

    it = (Item*) malloc(sizeof(Item));
    achou = 0;
    while((!achou) && (fread(it, sizeof(Item), 1, fp))) {
        if ((strcmp(it->codigoBarras, procurado) == 0) && (it->status == '1')) {
            achou = 1;
    }
    if (achou){

        listarEntradas();
        resp = escAtualizarEntrada();
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
                printf("Informe o novo código de barras: ");
                scanf(" %49[^\n]", it->codigoBarras);
                getchar();

            } while(!lerQuantidade(it->codigoBarras));

            do
            {
                printf(" | Informe o novo estoque mínimo desse produto: ");
                scanf("%s", it->estoqueMinimo);
                getchar();
                
            } while(!lerQuantidade(it->estoqueMinimo));

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
                printf(" | Informe a novo quantidade de produto: ");
                scanf("%s", it->quantProduto);    // adicionar o cálculo de entrada
                getchar();
                
            } while(!lerQuantidade(it->quantProduto));

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
                printf("Informe o novo código de barras: ");
                scanf(" %49[^\n]", it->codigoBarras);
                getchar();

            } while(!lerQuantidade(it->codigoBarras));

        }

        else if (resp == '5'){
            do
            {
                printf(" | Informe o novo estoque mínimo desse produto: ");
                scanf("%s", it->estoqueMinimo);
                getchar();
                
            } while(!lerQuantidade(it->estoqueMinimo));

        }

        else if (resp == '6'){
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

        else if (resp == '7') {
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

        else if (resp == '8') {
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

        else if (resp == '9'){
            do
            {
                printf("Informe a nova quantidade de produto: ");
                scanf("%s", it->quantProduto);
                getchar();

            } while(!lerQuantidade(it->quantProduto));

        }
        
        it->status = '1';      
        fseek(fp, (-1)*sizeof(Item), SEEK_CUR);
        fwrite(it, sizeof(Item), 1, fp);        
        printf(" |                                                           | \n");
        printf(" | --------------------------------------------------------- | \n");
        printf("Dados editados com sucesso");
    }
    
    else 
    {
        printf("A entrada de código de barras %s não foi encontrada\n", procurado);
    }
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    free(it);
    fclose(fp);
    gravaItem(it);      
    }

    return 0; 

}

//função para selecionar o que quer atualizar
char escAtualizarEntrada(void)
{    
    char esc;
    system(" cls || clear");
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ------------------- Atualizar entrada ------------------- | \n");
    printf(" |                                                           | \n");
    printf(" |                1- Editar tudo                             | \n");
    printf(" |                2- Editar nome do produto                  | \n");
    printf(" |                3- Editar nome da marca                    | \n");
    printf(" |                4- Editar código de barras                 | \n");
    printf(" |                5- Editar estoque mínimo                   | \n");
    printf(" |                6- Editar data de vencimento               | \n");                                                                    
    printf(" |                7- Editar categoria do produto             | \n");                                                                    
    printf(" |                8- Editar local de armazenamento           | \n");                                                                    
    printf(" |                9- Editar quantidade do produto            | \n");                                                                    
    printf(" |                0- Voltar à tela principal                 | \n");    
    printf(" |                                                           | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | Selecione uma opção do que você deseja editar: ");
    scanf("%c", &esc);
    getchar();

    return esc;

}

//função para exclusão lógica
int excluirEntrada(void)
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
    printf(" | ---------------------- Excluir entrada ----------------------- | \n");
    printf(" |                                                                | \n");
    printf(" | Informe o código de barras da entrada que você deseja excluir: ");
    scanf(" %30[^\n]", procurado);
    getchar();  
    
    achou = 0;

    while ((!achou) && (fread(it, sizeof(Item), 1, fp))){
        if ((strcmp(it->codigoBarras, procurado) == 0) && (it->status == '1')){
            achou = 1;
        }
    }

   if (achou){
        listarEntradas();

        printf("Deseja realmente excluir os dados desta entrada? (s/n)");
        scanf("%c", &resp);

        if (resp == 's' || resp == 'S'){
            it->status = '0';
            fseek(fp, (-1)*sizeof(Item), SEEK_CUR);
            fwrite(it, sizeof(Item), 1, fp);
            printf("\nDados da entrada excluídos com sucesso!");
            gravaItem(it);
            
        }else{
            printf("\nTudo bem, os dados não foram alterados!");
        }

    }else{
        printf("A entrada não foi encontrada!");
    }

    free(it);
    fclose(fp);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    return 0;
    
}

//listar entradas
int listarEntradas(void) 
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
        printf(" | =================== Lista de Entradas =================== |\n");
        printf(" |                                                           |\n");       
        printf(" | Nome do produto: %s\n", it->nomeProduto);    
        printf(" | Nome da marca: %s\n", it->nomeMarca);    
        printf(" | Código de barras: %s\n", it->codigoBarras);    
        printf(" | Estoque mínimo do produto: %s\n", it->estoqueMinimo);
        printf(" | Dia do vencimento: %d\n", it->dia); 
        printf(" | Mês do vencimento: %d\n", it->mes);         
        printf(" | Ano do vencimento: %d\n", it->ano); 
        printf(" | Quantidade do produto: %s\n", it->quantProduto);
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