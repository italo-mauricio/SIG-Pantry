#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloEntradaItens.h"
#include "validacoes.h"
#include "modulocadastroUsuario.h"
#include "modulocadastroItem.h"


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
    system ( " cls || clear " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------- REGISTRAR ENTRADA DE ITENS NA DESPENSA --------- | \n");
    printf(" |                                                           | \n");
    printf(" |                 1- Cadastrar entrada                      | \n");
    printf(" |                 2- Pesquisar entrada                      | \n");                
    printf(" |                 3- Listar entrada                         | \n");                                                                    
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
                printf(" | Informe o código de barras do produto: ");
                scanf("%s", it->codigoBarras);
                getchar();
                
            } while(!lerQuantidade(it->codigoBarras));

            do {        
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
        printf(" | Código de barras: %s\n", it->codigoBarras);    
        printf(" | Quantidade do produto: %s\n", it->quantProduto);
        printf(" | Dia do vencimento: %d\n", it->dia); 
        printf(" | Mês do vencimento: %d\n", it->mes); 
        printf(" | Ano do vencimento: %d\n", it->ano); 
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


//listar entradas
int listarEntrada(void) 
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
        printf(" | =================== Lista de Entradas =================== |\n");
        printf(" |                                                           |\n");       
        printf(" | Código de barras: %s\n", it->codigoBarras);    
        printf(" | Quantidade de produto: %s\n", it->quantProduto);
        printf(" | Dia do vencimento: %d\n", it->dia); 
        printf(" | Mês do vencimento: %d\n", it->mes); 
        printf(" | Ano do vencimento: %d\n", it->ano); 
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