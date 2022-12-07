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
                relatorioCategoria(); //com base na categoria selecionada
                break;
            case '2':
                relatorioLocalArmaz(); //com base no local selecionado para armazenar
                break; 
            case '3':
                relatorioListasdeCompra(); //resgatar listas excluídas
                break;
            case '4':
                relatoriopeloTipo(); //com base no E e S do menu itens
                break;
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
    printf(" |                 3- Histórico de listas de compra                     | \n");
    printf(" |                 4- Estoque com base no tipo                          | \n");
    printf(" |                 0- Voltar à tela principal                           | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    getchar();

    return esc;

}

//navegação da escolha da categoria
/*void escRelatoriosCategoria(void)
{
    char opcao;
    do
    {
        opcao = relatorioCategoria();
        switch (opcao)
        {
            case '1':
                exibirItensHigiene();
                break; //fazer case 2 para colocar a de limpeza... 
        }

    } while (opcao != '0');

} */

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
/*int exibirItensHigiene(void)
{
    FILE* fp;
    Item* it;

    int listaCategoria;
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

// pedir o CPF aqui e procurar

    it = (Item*) malloc(sizeof(Item));
    
    achou = 0;
    
    while((fread(it, sizeof(Item), 1, fp))){        
        if (((it->categoria == listcargo)) && (it->status == '1')){
            

    
    free(it);   
    fclose(fp);

    return 0;


}*/

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

//função para exibir as listas de compras - procura pelas excluídas
char relatorioListasdeCompra(void)
{
    char esc;
    system (" Clear||cls ");
    printf(" | ===================================================================== | \n");
    printf(" | --------------------------------------------------------------------- | \n");
    printf(" | ---------- | Relatório do histórico das listas de compra | ---------- | \n");
    printf(" |                                                                       | \n");
    printf(" |                                                                       | \n");                         
    printf(" |                                                                       | \n");
    printf(" |                                                                       | \n");
    printf(" |                                                                       | \n");
    printf(" | ----------------------------------------------------------------------| \n");
    printf(" | ========================== SIG - Pantry ============================= | \n");
    printf(" Press ENTER for exit.....");
    scanf("%c", &esc);
    getchar();

    return esc;

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