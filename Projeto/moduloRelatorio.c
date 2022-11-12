#include <stdio.h>
#include <stdlib.h>
#include "moduloRelatorio.h"
#include <string.h>
#include "validacoes.h"

char moduloRelatorio (void)
{
    int escolha;
    do {
        escolha = telaRelatorio();
        switch (escolha) {
        case 1:
            estoquedeAlimento();
            break;
        case 2:
            estoquedeHigiene();
            break; 
        case 3:
            estoquedeLimpeza();
            break;
        case 4:
            listasdeCompra();
            break;
        default :
            printf ("Opção inválida!");
            break;
    }

    } while(escolha != 0);

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
    printf(" |                    1- Estoque de alimento                            | \n");
    printf(" |                    2- Estoque de higiene pessoal                     | \n");
    printf(" |                    3- Estoque de limpeza                             | \n");
    printf(" |                    4- Histórico de listas de compra                  | \n");
    printf(" |                    0- Voltar à tela principal                        | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    getchar();

    return esc;
// TIRAR ESSES ESTOQUES POR CATEGORIA E EXIBIR GERAIS...

}


char estoquedeAlimento(void)
{
    char esc;
    system (" Clear||cls ");
    printf(" | ===================================================================== | \n");
    printf(" | --------------------------------------------------------------------- | \n");
    printf(" | --------------------------- | Estoque | ----------------------------- | \n");
    printf(" |                                                                       | \n");
    printf(" |                                                                       | \n");
    printf(" |   Aqui ficará o estoque futuramente                                   | \n");
    printf(" |                                                                       | \n");
    printf(" |                                                                       | \n");
    printf(" |                                                                       | \n");
    printf(" |                                                                       | \n");
    printf(" | ----------------------------------------------------------------------| \n");
    printf(" | ======================== SIG - Pantry =============================== | \n");
    printf(" Press ENTER for exit.....");
    scanf("%c", &esc);

    return esc;

}

char estoquedeHigiene(void)
{
    char esc;
    system (" Clear||cls ");
    printf(" | ===================================================================== | \n");
    printf(" | --------------------------------------------------------------------- | \n");
    printf(" | -------------------------- | Estoque | ------------------------------ | \n");
    printf(" |                                                                       | \n");
    printf(" |                                                                       | \n");
    printf(" |   Aqui ficará o estoque de higiene                                    | \n");
    printf(" |                                                                       | \n");
    printf(" |                                                                       | \n");
    printf(" |                                                                       | \n");
    printf(" |                                                                       | \n");
    printf(" | ----------------------------------------------------------------------| \n");
    printf(" | ======================== SIG - Pantry =============================== | \n");
    printf(" Press ENTER for exit.....");
    scanf("%c", &esc);
    getchar();

    return esc;

}


char estoquedeLimpeza(void)
{
    char esc;
    system (" Clear||cls ");
    printf(" | ===================================================================== | \n");
    printf(" | --------------------------------------------------------------------- | \n");
    printf(" | -------------------------- | Estoque | ------------------------------ | \n");
    printf(" |                                                                       | \n");
    printf(" |                                                                       | \n");
    printf(" |   Aqui ficará o estoque de limpeza                                    | \n");
    printf(" |                                                                       | \n");
    printf(" |                                                                       | \n");
    printf(" |                                                                       | \n");
    printf(" |                                                                       | \n");
    printf(" | ----------------------------------------------------------------------| \n");
    printf(" | ======================== SIG - Pantry =============================== | \n");
    printf(" Press ENTER for exit.....");
    scanf("%c", &esc);
    getchar();

    return esc;

}

char listasdeCompra(void)
{
    char esc;
    system (" Clear||cls ");
    printf(" | ===================================================================== | \n");
    printf(" | --------------------------------------------------------------------- | \n");
    printf(" | ---------------- | HISTÓRICO DAS LISTAS DE COMPRA | ----------------- | \n");
    printf(" |                                                                       | \n");
    printf(" |                                                                       | \n");                         
    printf(" |                                                                       | \n");
    printf(" |                                                                       | \n");
    printf(" |                                                                       | \n");
    printf(" | ----------------------------------------------------------------------| \n");
    printf(" | ======================== SIG - Pantry =============================== | \n");
    printf(" Press ENTER for exit.....");
    scanf("%c", &esc);
    getchar();

    return esc;

}