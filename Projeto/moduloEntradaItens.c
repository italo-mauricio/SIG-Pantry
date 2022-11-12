#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloEntradaItens.h"
#include "validacoes.h"

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
        /*case '3':
            atualizarEntrada(); //edição
            break;*/
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
    printf(" | -------------- REGISTRAR ENTRADA DE ITEM ---------------- | \n");
    printf(" |                                                           | \n");    
    ent = (Entrada*)malloc(sizeof(Entrada));
    do
    {
        printf(" | Informe o código de barras do item: ");
        scanf("%s", ent->codigodeBarras);
        getchar();
        
    } while(!lerQuantidade(ent->codigodeBarras));

    do {        
        printf(" | Informe o dia de vencimento: ");
        scanf("%d",&ent->dia);
        getchar();
        printf(" | Informe o mês: ");
        scanf("%d",&ent->mes);
        getchar();
        printf(" | Informe o ano: ");
        scanf("%d",&ent->ano);
        getchar();
        
     } while(!valida_data(ent->dia, ent->mes, ent->ano));  
    
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

//A partir do código de barras
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
    system ( " cls " );
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
        exibeEntrada(ent);
    } else {
        printf("Os dados da entrada %s não foram encontrados\n", procurado);
    }
    free(ent);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    
}

//exibe produtos registrados na entrada
void exibeEntrada(Entrada* ent) {
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
    
}

//EDITAR AQUI


//função para exclusão lógica
void excluirEntrada(void)
{
    FILE* fp;
    Entrada* ent;
    int achou;
    char resp;
    char codigodeBarras[20];
    fp = fopen("entrada.dat", "r+b");

    if (fp == NULL){
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
    }
    ent = (Entrada*) malloc(sizeof(Entrada));
    system( " clear || cls ");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ---------------------- EXCLUIR ENTRADA ----------------------- | \n");
    printf(" |                                                                | \n");
    printf(" | Informe o código de barras do produto que você deseja excluir: ");
    scanf("%s", ent->codigodeBarras);
    getchar();  
    achou = 0;
    while ((!achou) && (fread(ent, sizeof(Entrada), 1, fp))){
        if ((strcmp(ent->codigodeBarras, codigodeBarras) == 0) && (ent->status == '0')){
            achou = 1;
        }
    }

   if (achou){
        exibeEntrada(ent);
        getchar();
        printf("Deseja realmente excluir os dados desta entrada? (s/n)");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S'){
            ent->status = '0';
            fseek(fp, (-1)*sizeof(Entrada), SEEK_CUR);
            fwrite(ent, sizeof(Entrada), 1, fp);
            printf("\nDados da entrada excluídos com sucesso!");
        }else{
            printf("\nTudo bem, os dados não foram alterados!");
        }
    }else{
        printf("Os dados não foram encontrados!");
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
    printf("\n\n");
    printf(" | ==================== Exibe entrada ====================== | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    ent = (Entrada*)malloc(sizeof(Entrada));
    while(fread(ent, sizeof(Entrada), 1, fp)) {
        exibeEntrada(ent);
    }
    fclose(fp);
    free(ent);

}