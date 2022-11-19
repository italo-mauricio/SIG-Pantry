#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloEntradaItens.h"
#include "validacoes.h"
#include "modulocadastroUsuario.h"

void menuEntradaItens(void)
{
    char escolha;
    do {
        escolha = telaRegistrarEntrada();
        switch(escolha) {
        case '1':
            infoEntrada(); //informações do item
            break;
        case '2':
            buscaInfoEntrada(); //pesquisa
            break;
        case '3':
            atualizarEntrada(); //edição
            break;
        case '4':
            excluirEntrada(); //exclusão
            break;
        case '5':
            listarEntrada(); //relatório
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
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------- REGISTRAR ENTRADA DE ITENS NA DESPENSA --------- | \n");
    printf(" |                                                           | \n");
    printf(" |                 1- Cadastrar entrada                      | \n");
    printf(" |                 2- Pesquisar entrada                      | \n");
    printf(" |                 3- Editar entrada                         | \n");                 
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
    Entrada* ent;
    system ( " cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------- Registrar entrada de item ---------------- | \n");
    printf(" |                                                           | \n");    
    ent = (Entrada*)malloc(sizeof(Entrada));
    do
    {
        printf(" | Informe o código de barras do produto: ");
        scanf("%s", ent->codigodeBarras);
        getchar();
        
    } while(!lerQuantidade(ent->codigodeBarras));

    do {        
        printf(" | Informe o dia de vencimento: ");
        scanf("%d", &ent->dia);
        getchar();
        printf(" | Informe o mês: ");
        scanf("%d", &ent->mes);
        getchar();
        printf(" | Informe o ano: ");
        scanf("%d", &ent->ano);
        getchar();
        
     } while(!valida_data(ent->dia, ent->mes, ent->ano)); 

    do
    {
        printf(" | Informe a quantidade de produto: ");
        scanf("%s", ent->quantProduto);
        getchar();
        
    } while(!lerQuantidade(ent->quantProduto));

    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    ent->status = '1'; //o 1 mostra que foi cadastrado
    gravaEntrada(ent);
    free(ent);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();

}

//Função para gravar no arquivo
void gravaEntrada(Entrada* ent) 
{
    FILE* fp;
    fp = fopen("entrada.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        exit(1);
    }
    
    fwrite(ent, sizeof(Entrada), 1, fp);
    fclose(fp);
    
}

//função de pesquisa a partir do código de barras
void buscaInfoEntrada(void)
{
    FILE* fp;
    Entrada* ent;
    int achou;
    char procurado[15];
    fp = fopen("entrada.dat", "rb");

    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
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
    ent = (Entrada*) malloc(sizeof(Entrada));
    achou = 0;
    while((!achou) && (fread(ent, sizeof(Entrada), 1, fp))) {
        printf("Código de barras |%s|\n", ent->codigodeBarras);
        if ((strcmp(ent->codigodeBarras, procurado) == 0) && (ent->status == '1')) {
            achou = 1;
        }
    }
    fclose(fp);
    if (achou) {
        system(" cls || clear ");
        printf(" | ================== Entrada encontrada =================== |\n");
        printf(" |                                                           |\n");        printf(" | Código de barras: %s\n", ent->codigodeBarras);    
        printf(" | Código de barras: %s\n", ent->codigodeBarras);    
        printf(" | Quantidade do produto: %s\n", ent->quantProduto);
        printf(" | Dia do vencimento: %d\n", ent->dia); 
        printf(" | Mês do vencimento: %d\n", ent->mes); 
        printf(" | Ano do vencimento: %d\n", ent->ano); 
        printf(" | Status: %c\n", ent->status);
        printf(" |                                                           | \n");
        printf(" | ========================================================= | \n");
        printf(" | Pressione qualquer tecla para sair.... ");
        getchar();

    } else {
        printf("Os dados da entrada %s não foram encontrados\n", procurado);
    }
    free(ent);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    
}

//exibe produtos registrados na entrada
void exibeEntrada(Entrada* ent) {
    system(" cls || clear");
    printf(" | =================== Entrada cadastrada ================== |\n");
    printf(" |                                                           |\n");       
    printf(" | Código de barras: %s\n", ent->codigodeBarras);    
    printf(" | Quantidade de produto: %s\n", ent->quantProduto);
    printf(" | Dia do vencimento: %d\n", ent->dia); 
    printf(" | Mês do vencimento: %d\n", ent->mes); 
    printf(" | Ano do vencimento: %d\n", ent->ano); 
    printf(" | Status: %c\n", ent->status);
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    
}

//função para editar
void atualizarEntrada(void)
{
    FILE *fp;
    Entrada* ent;
    char resp;
    char escolha;
    ent = (Entrada*) malloc(sizeof(Entrada));
    system(" cls || clear");
    printf(" | Digite o código de barras cadastrado: ");
    scanf("%s", ent->codigodeBarras);
    getchar();
    if ((ent == NULL) || (ent->status == '0')) {
        printf("\nEntrada não encontrada\n");
        exit(1);
    }

    fp = fopen("entrada.dat", "r+t");
    if (fp == NULL) {
        printf("Ocorreu um erro na abertura do arquivo");
        exit(1);
    }

    exibeEntrada(ent);
    printf("\nEsta é a entrada que você quer alterar os dados? S/N");
    scanf("%c", &resp);
    getchar();
    system("cls || clear");
    if (resp == 'S' || resp == 's'){
        system(" cls || clear");
        printf(" | ========================================================= | \n");
        printf(" | --------------------------------------------------------- | \n");
        printf(" | ------------------- Atualizar entrada ------------------- | \n");
        printf(" |                                                           | \n");
        printf(" |                 1- Editar código de barras                | \n");
        printf(" |                 2- Editar data de vencimento              | \n");                 
        printf(" |                 3- Editar quantidade                      | \n");
        printf(" |                 0- Voltar à tela principal                | \n");    
        printf(" |                                                           | \n");
        printf(" | --------------------------------------------------------- | \n");
        printf(" | Selecione uma opção: ");
        scanf("%c", &escolha);
        getchar();
        while (escolha != '0')
        {
            switch (escolha){
                case '1':
                do
                {
                    printf(" | Informe o novo código de barras do item: ");
                    scanf("%s", ent->codigodeBarras);
                    getchar();
        
                } while(!lerQuantidade(ent->codigodeBarras));
                printf("\nEntrada editada com sucesso!\n");
                break;

                case '2':
                do {        
                    printf(" | Informe o novo dia de vencimento: ");
                    scanf("%d", &ent->dia);
                    getchar();
                    printf(" | Informe o novo mês: ");
                    scanf("%d", &ent->mes);
                    getchar();
                    printf(" | Informe o novo ano: ");
                    scanf("%d", &ent->ano);
                    getchar();
        
                } while(!valida_data(ent->dia, ent->mes, ent->ano));
                printf("\nEntrada editada com sucesso!\n");
                break;

                case '3':
                do
                {
                    printf(" | Informe a nova quantidade de produto: ");
                    scanf("%s", ent->quantProduto);
                    getchar();
                    
                } while(!lerQuantidade(ent->quantProduto));

                default:
                    printf("\nPor favor, insira uma opção válida.\n");
                    break;
                }

                escolha = '0';
            }
            fseek(fp, (-1) * sizeof(Entrada), SEEK_CUR);
            fwrite(ent, sizeof(Entrada), 1, fp);
        }

    else {
        printf("\nOk, os dados não foram alterados!\n");
    }
    fclose(fp);
    free(ent);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();

}

//função para exclusão lógica
void excluirEntrada(void)
{
    FILE* fp;
    Entrada* ent;
    int achou;
    char resp;
    char procura[20];
    fp = fopen("entrada.dat", "r+b");

    if (fp == NULL){
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
    }
    ent = (Entrada*) malloc(sizeof(Entrada));
    system( " clear || cls ");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ---------------------- Excluir entrada ----------------------- | \n");
    printf(" |                                                                | \n");
    printf(" | Informe o código de barras do produto que você deseja excluir: ");
    scanf(" %30[^\n]", procura);
    getchar();  
    achou = 0;
    while ((!achou) && (fread(ent, sizeof(Entrada), 1, fp))){
        if ((strcmp(ent->codigodeBarras, procura) == 0) && (ent->status == '1')){
            achou = 1;
        }
    }

   if (achou){
        exibeEntrada(ent);
        printf("Deseja realmente excluir os dados desta entrada? (s/n)");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S'){
            ent->status = '0';
            fseek(fp, (-1)*sizeof(Entrada), SEEK_CUR);
            fwrite(ent, sizeof(Entrada), 1, fp);
            printf("\nEntrada excluída com sucesso!");
            gravaEntrada(ent);
            printf(" Pressione qualquer tecla para sair... ");
            getchar();
        }else{
            printf("\nTudo bem, os dados não foram alterados!");
        }
    }else{
        printf("A entrada não foi encontrada!");
    }
    free(ent);
    fclose(fp);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    
}


//listar entradas
void listarEntrada(void) 
{
    FILE* fp;
    Entrada* ent;
    fp = fopen("entrada.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
    }

    ent = (Entrada*)malloc(sizeof(Entrada));
    while(fread(ent, sizeof(Entrada), 1, fp)) {
        system(" cls || clear");
        printf(" | ==================== Lista entrada ====================== | \n");
        printf(" |                                                           | \n");
        exibeEntrada(ent);
    }
    fclose(fp);
    free(ent);

}