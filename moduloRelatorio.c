#include <stdio.h>
#include <stdlib.h>
#include "moduloRelatorio.h"

int  main (void)
{
    char escolha;
    do {
        escolha = telaRelatorio();
        switch (escolha) {
        case '1':
            estoquedeAlimento();
            break;
        case '2':
            estoquedeHigiene();
            break; 
        case  '3':
            estoquedeLimpeza();
            break;
        defaut :
            printf ('Opcao invalida \n');
            break;
    }

    } while(escolha != '0');

    return  0 ;
}



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
    printf(" | Escolha uma opcao: \n");
    scanf("%c", &opcao);
    getchar();

    return opcao;

}