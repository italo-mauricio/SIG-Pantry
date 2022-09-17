#include <stdio.h>
#include <stdlib.h>
#include "moduloRelatorio.h"


char telaRelatorio(void);


char telaRelatorio(void);
char estoquedeAlimento(void);
char estoquedeHigiene(void);
char estoquedeLimpeza(void);


char main (void)
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
        default :
            printf ('Opcao invalida ');
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
    printf(" | Escolha uma opcao: ");
    scanf("%c", &opcao);
    getchar();

    return opcao;

}


char estoquedeAlimento(void)
{

    char esc;
    system (" Clear||cls ");
    printf(" | ===================================================================== | \n");
    printf(" | --------------------------------------------------------------------- | \n");
    printf(" | ----------------------- | Estoque | --------------------------------- | \n");
    printf(" |                                                                       | \n");
    printf(" |                                                                       | \n");
    printf(" |   Aqui ficara o estoque futuramente                                   | \n");
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
        printf(" | ----------------------- | Estoque | --------------------------------- | \n");
        printf(" |                                                                       | \n");
        printf(" |                                                                       | \n");
        printf(" |   Aqui ficara o estoque de higiene                                    | \n");
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


char estoquedeLimpeza(void)
{

      char esc;
        system (" Clear||cls ");
        printf(" | ===================================================================== | \n");
        printf(" | --------------------------------------------------------------------- | \n");
        printf(" | ----------------------- | Estoque | --------------------------------- | \n");
        printf(" |                                                                       | \n");
        printf(" |                                                                       | \n");
        printf(" |   Aqui ficara o estoque de limpeza                                    | \n");
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