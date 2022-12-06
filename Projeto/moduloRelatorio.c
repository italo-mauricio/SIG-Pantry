#include <stdio.h>
#include <stdlib.h>
#include "moduloRelatorio.h"
#include <string.h>
#include "validacoes.h"

char moduloRelatorio (void)
{
    char escolha;
    do {
        escolha = telaRelatorio();
        switch (escolha) {
        case '1':
            estoquedeCategoria(); //com base na categoria selecionada
            break;
        case '2':
            estoquedeLocalArmaz(); //com base no local selecionado para armazenar
            break; 
        case '3':
            listasdeCompra(); //resgatar listas excluídas
            break;
        case '4':
            estoqueTipo(); //com base no E e S do menu itens
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
    printf(" | -------------------| SIG-Pantry - RELATÓRIO |----------------------- | \n");
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
// TIRAR ESSES ESTOQUES POR CATEGORIA E EXIBIR GERAIS...

}


char estoquedeCategoria(void)
{
    char esc;
    system (" Clear||cls ");
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | -------------------- | Estoque da categoria | ---------------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |                      1- Categoria de alimento                        | \n");
    printf(" |                      2- Categoria de higiene pessoal                 | \n");
    printf(" |                      3- Categoria de limpeza                         | \n");
    printf(" |                      0- Voltar à tela principal                      | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);

    return esc;

}

char estoquedeLocalArmaz(void)
{
    char esc;
    system (" Clear||cls ");
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | --------------- | Estoque de local de armazenamento | -------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |                   1- Geladeira                                       | \n");
    printf(" |                   2- Armário da cozinha                              | \n");
    printf(" |                   3- Área de serviço                                 | \n");
    printf(" |                   4- Guarda-roupa                                    | \n");
    printf(" |                   5- Banheiro                                        | \n");
    printf(" |                   0- Voltar à tela principal                         | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);

    return esc;


}


char listasdeCompra(void)
{
    char esc;
    system (" Clear||cls ");
    printf(" | ===================================================================== | \n");
    printf(" | --------------------------------------------------------------------- | \n");
    printf(" | ---------------- | Histórico das listas de compra | ----------------- | \n");
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

char estoqueTipo(void)
{
    char esc;
    system (" Clear||cls ");
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ------------------- | Estoque com base no tipo | ------------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |                      1- Itens que entraram (E)                       | \n");
    printf(" |                      2- Itens retirados (S)                          | \n");
    printf(" |                      0- Voltar à tela principal                      | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);

    return esc;

}
