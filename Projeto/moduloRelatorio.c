#include <stdio.h>
#include <stdlib.h>
#include "moduloRelatorio.h"
#include <string.h>
#include "validacoes.h"
#include "moduloMenuItem.h"
#include "modulolistadeCompras.h"
#include "modulocadastroUsuario.h"


char moduloRelatorio(void)
{
    char escolha;
    do {
        escolha = telaRelatorio();
        switch (escolha) {
            case '1':
                escRelatoriosCategoria(); //com base na categoria selecionada
                break;
            case '2':
                escRelatoriosLocal(); //com base no local selecionado para armazenar
                break; 
            case '3':
                escRelatoriosTipo(); //com base no E e S do menu itens
                break;
           /* case '4':
                itensOrdemAlfabetica();
                break; */
            default :
                printf ("Opção inválida!");
                break;
        }

    } while(escolha != '0');

    return escolha;

}

char telaRelatorio(void)
{
    char esc;
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | -------------------| SIG-Pantry - RELATÓRIOS |---------------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |                 1- Estoque com base na categoria                     | \n");
    printf(" |                 2- Estoque com base no local de armazenamento        | \n");
    printf(" |                 3- Estoque com base no tipo                          | \n");
   // printf(" |                 4- Itens em ordem alfabética                          | \n");
    printf(" |                 0- Voltar à tela principal                           | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    getchar();

    return esc;

}

//navegação da escolha da categoria
void escRelatoriosCategoria(void)
{
    char opcao;
    do
    {
        opcao = relatorioCategoria();
        switch (opcao)
        {
            case '1':
                exibirItensHigiene();
                break; 
            case '2':
                exibirItensLimpeza();
                break;
            case '3':
                exibirItensAlimento();
                break;
        }

    } while (opcao != '0');

} 

//função para selecionar uma das categorias
char relatorioCategoria(void)
{
    char esc;
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ---------------| Relatórios com base na categoria |----------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |               1- Relatório dos itens de higiene pessoal              | \n");
    printf(" |               2- Relatório dos itens de limpeza                      | \n");
    printf(" |               3- Relatório dos itens de alimento                     | \n");
    printf(" |               0- Voltar à tela principal                             | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    getchar();

    return esc;

}

//função para retornar o relatório dos itens de higiente
int exibirItensHigiene(void)
{
    FILE* fp;
    Item* it;

    int achou;

    fp = fopen("itens.dat", "rb");

    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }

    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ------------| Relatório dos itens de higiene pessoal |-------------- | \n");
    printf(" |                                                                      | \n");

    it = (Item*) malloc(sizeof(Item));

    achou = 0;

    while((fread(it, sizeof(Item), 1, fp))){
        if (((it->categoria == '1')) && (it->status == '1')){
            listarItens();
            achou = 1;
        }

    }
    
    if (achou){
        
        return 0;
    
    } else {
        
        printf("ERRO");
        getchar();
    
    }

    free(it);
    fclose(fp);

    return 0;

} 

//função para retornar o relatório dos itens de limpeza
int exibirItensLimpeza(void)
{
    FILE* fp;
    Item* it;

    int achou;

    fp = fopen("itens.dat", "rb");

    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }

    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | -----------------| Relatório dos itens de limpeza |----------------- | \n");
    printf(" |                                                                      | \n");

    it = (Item*) malloc(sizeof(Item));

    achou = 0;

    while((fread(it, sizeof(Item), 1, fp))){
        if (((it->categoria == '2')) && (it->status == '1')){
            listarItens();
            achou = 1;
        }

    }
    
    if (achou){
        
        return 0;
    
    } else {
        
        printf("ERRO");
        getchar();
    
    }

    free(it);
    fclose(fp);

    return 0;
    
} 

//função para retornar o relatório dos itens de alimento
int exibirItensAlimento(void)
{
    FILE* fp;
    Item* it;

    int achou;

    fp = fopen("itens.dat", "rb");

    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }

    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ----------------| Relatório dos itens de alimento |----------------- | \n");
    printf(" |                                                                      | \n");

    it = (Item*) malloc(sizeof(Item));

    achou = 0;

    while((fread(it, sizeof(Item), 1, fp))){
        if (((it->categoria == '3')) && (it->status == '1')){
            listarItens();
            achou = 1;
        }

    }
    
    if (achou){
        
        return 0;
    
    } else {
        
        printf("ERRO");
        getchar();
    
    }

    free(it);
    fclose(fp);

    return 0;
    
} 

//navegação da escolha do local
void escRelatoriosLocal(void)
{
    char opcao;
    do
    {
        opcao = relatorioLocalArmaz();
        switch (opcao)
        {
            case '1':
                exibirGeladeira();
                break; 
            case '2':
                exibirArmarioCozinha();
                break;
            case '3':
                exibirAreaServ();
                break;
            case '4':
                exibirGuardaRoupa();
                break;  
            case '5':
                exibirBanheiro();
                break;      
        }

    } while (opcao != '0');
} 

//criar uma função que irá listar um por um, filtrando 
char relatorioLocalArmaz(void)
{
    char esc;
    system (" Clear||cls ");
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ---------- | Relatórios com base no local de armazenamento | ------- | \n");
    printf(" |                                                                      | \n");
    printf(" |                 1- Geladeira                                         | \n");
    printf(" |                 2- Armário da cozinha                                | \n");
    printf(" |                 3- Área de serviço                                   | \n");
    printf(" |                 4- Guarda-roupa                                      | \n");
    printf(" |                 5- Banheiro                                          | \n");
    printf(" |                 0- Voltar à tela principal                           | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);

    return esc;

}

//função para retornar o relatório dos itens da geladeira
int exibirGeladeira(void)
{
    FILE* fp;
    Item* it;

    int achou;

    fp = fopen("itens.dat", "rb");

    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }

    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ----------------| Relatório dos itens da geladeira |---------------- | \n");
    printf(" |                                                                      | \n");

    it = (Item*) malloc(sizeof(Item));

    achou = 0;

    while((fread(it, sizeof(Item), 1, fp))){
        if (((it->localArmazenamento == '1')) && (it->status == '1')){
            listarItens();
            achou = 1;

        }

    }
    
    if (achou){
        
        return 0;
    
    } else {
        
        printf("ERRO");
        getchar();
    
    }

    free(it);
    fclose(fp);

    return 0;
    
} 

//função para retornar o relatório dos itens do armário da cozinha
int exibirArmarioCozinha(void)
{
    FILE* fp;
    Item* it;

    int achou;

    fp = fopen("itens.dat", "rb");

    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }

    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ----------| Relatório dos itens do armário da cozinha |------------- | \n");
    printf(" |                                                                      | \n");

    it = (Item*) malloc(sizeof(Item));

    achou = 0;

    while((fread(it, sizeof(Item), 1, fp))){
        if (((it->localArmazenamento == '2')) && (it->status == '1')){
            listarItens();
            achou = 1;
            
        }

    }
    
    if (achou){
        
        return 0;
    
    } else {
        
        printf("ERRO");
        getchar();
    
    }

    free(it);
    fclose(fp);

    return 0;
    
}

//função para retornar o relatório dos itens da área de serviço
int exibirAreaServ(void)
{
    FILE* fp;
    Item* it;

    int achou;

    fp = fopen("itens.dat", "rb");

    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }

    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ------------| Relatório dos itens do área de serviço |-------------- | \n");
    printf(" |                                                                      | \n");

    it = (Item*) malloc(sizeof(Item));

    achou = 0;

    while((fread(it, sizeof(Item), 1, fp))){
        if (((it->localArmazenamento == '3')) && (it->status == '1')){
            listarItens();
            achou = 1;
            
        }

    }
    
    if (achou){
        
        return 0;
    
    } else {
        
        printf("ERRO");
        getchar();
    
    }

    free(it);
    fclose(fp);

    return 0;
    
}

//função para retornar o relatório dos itens do guarda-roupa
int exibirGuardaRoupa(void)
{
    FILE* fp;
    Item* it;

    int achou;

    fp = fopen("itens.dat", "rb");

    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }

    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | --------------| Relatório dos itens do guarda-roupa |--------------- | \n");
    printf(" |                                                                      | \n");

    it = (Item*) malloc(sizeof(Item));

    achou = 0;

    while((fread(it, sizeof(Item), 1, fp))){
        if (((it->localArmazenamento == '4')) && (it->status == '1')){
            listarItens();
            achou = 1;
            
        }

    }
    
    if (achou){
        
        return 0;
    
    } else {
        
        printf("ERRO");
        getchar();
    
    }

    free(it);
    fclose(fp);

    return 0;
    
}

//função para retornar o relatório dos itens do banheiro
int exibirBanheiro(void)
{
    FILE* fp;
    Item* it;

    int achou;

    fp = fopen("itens.dat", "rb");

    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }

    system ( " clear||cls " );
    printf(" | ========================================================================= | \n");
    printf(" | ------------------------------------------------------------------------- | \n");
    printf(" | ----------------| Relatório dos itens do banheiro |---------------------- | \n");
    printf(" |                                                                           | \n");

    it = (Item*) malloc(sizeof(Item));

    achou = 0;

    while((fread(it, sizeof(Item), 1, fp))){
        if (((it->localArmazenamento == '5')) && (it->status == '1')){
            listarItens();
            achou = 1;
            
        }

    }
    
    if (achou){
        
        return 0;
    
    } else {
        
        printf("ERRO");
        getchar();
    
    }

    free(it);
    fclose(fp);

    return 0;
    
}

//navegação da escolha do tipo
void escRelatoriosTipo(void)
{
    char opcao;
    do
    {
        opcao = relatoriopeloTipo();
        switch (opcao)
        {
            case '1':
                exibirEntrada();
                break; 
            case '2':
                exibirSaida();
                break;    
        }

    } while (opcao != '0');

} 


//função para exibir os itens que entraram/saíram
char relatoriopeloTipo(void)
{
    char esc;
    system (" Clear||cls ");
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | -------------- | Relatório do estoque com base no tipo | ----------- | \n");
    printf(" |                                                                      | \n");
    printf(" |                    1- Itens que entraram (E)                         | \n");
    printf(" |                    2- Itens que saíram (S)                           | \n");
    printf(" |                    0- Voltar à tela principal                        | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);

    return esc;

}

//função para retornar o relatório dos itens que entraram
int exibirEntrada(void)
{
    FILE* fp;
    Mov* mv;

    int achou;

    fp = fopen("movimento.dat", "rb");

    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }

    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ----------| Relatório dos itens que entraram na despensa |---------- | \n");
    printf(" |                                                                      | \n");

    mv = (Mov*) malloc(sizeof(Mov));

    achou = 0;

    while((fread(mv, sizeof(Item), 1, fp))){
        if (((mv->tipo == '1'))) {
            listarItens();
            achou = 1;
            
        }

    }
    
    if (achou){
        
        return 0;
    
    } else {
        
        printf("ERRO");
        getchar();
    
    }

    free(mv);
    fclose(fp);

    return 0;
    
}

//função para retornar o relatório dos itens que saíram
int exibirSaida(void)
{
    FILE* fp;
    Mov* mv;

    int achou;

    fp = fopen("movimento.dat", "rb");

    if (fp == NULL) 
    {
        printf("Ops! Ocorreu um erro ao abrir o arquivo!\n");
        return 0;
    }

    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | -----------| Relatório dos itens que saíram da despensa |----------- | \n");
    printf(" |                                                                      | \n");

    mv = (Mov*) malloc(sizeof(Mov));

    achou = 0;

    while((fread(mv, sizeof(Item), 1, fp))){
        if (((mv->tipo == '2'))) {
            listarItens();
            achou = 1;
            
        }

    }
    
    if (achou){
        
        return 0;
    
    } else {
        
        printf("ERRO");
        getchar();
    
    }

    free(mv);
    fclose(fp);

    return 0;
    
}