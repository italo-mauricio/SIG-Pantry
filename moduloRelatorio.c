#include <stdio.h>
#include <stdlib.h>

char telaRelatorio(void)
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | -------------------| SIG-Pantry - RELATORIO |----------------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |                    1- Estoque de alimento                            | \n");
    printf(" |                    2- Estoque de higiene pessoal                     | \n");
    printf(" |                    3- Estoque de limpeza                             | \n");
    printf(" |                    0- Voltar a tela principal                        | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opcao:                                                   | \n");
    printf(" | ==================================================================== | \n");
    scanf("%c", &opcao);
    getchar();

    return opcao;

}