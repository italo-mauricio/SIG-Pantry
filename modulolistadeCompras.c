#include <stdio.h>
#include <stdlib.h>
#include "modulolistadeCompras.h"

char telaCadastroCompras(void);

/* int  main (void)
{
    char escolha;
    do {
        escolha = telaListadeCompras();
        switch (escolha) {
        case '1':
            telaVisualizarAlimentosproxVencim();
            break;
        case '2':
            telavisualizarHigieneproxVencim();
            break; 
        case  '3':
            telavisualizarLimpezaproxVencim();
            break;
        case '4':
            telaMontarLista();
            break; 
        defaut :
            printf ('Opcao invalida \n');
            break ;
    }

    } while(escolha != '0');

    return  0 ;
} */

char telaListadeCompras(void)
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | -------------------| SIG-Pantry - LISTA DE COMPRAS |---------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |      1- Visualizar itens alimentares proximos do vencimento          | \n");
    printf(" |      2- Visualizar itens de higiene pessoal proximos do vencimento   | \n");
    printf(" |      3- Visualizar itens de limpeza proximos do vencimento           | \n");
    printf(" |      4- Montar a propria listinha                                    | \n");    
    printf(" |      0- Voltar a tela principal                                      | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opcao: \n");
    scanf("%c", &opcao);
    getchar();

    return opcao;

}



char telaproximoVencimento (void)

{

    printf("| ============================================================== | \n");
    printf("| -------------------------------------------------------------- | \n");
    printf("| ------------- | Alimentos próximo ao vencimento | ------------ | \n");
    printf("|                                                                | \n");
    printf("|  Nome do alimento:                                             | \n");
    printf("|  Data de cadastro no sistema:                                  | \n");
    printf("|  Data de vencimento:                                           | \n");
    printf("|                                                                | \n");
    printf("| ============================================================== | \n");
    printf("| Deseja receber uma notificacao quando o alimento estiver proxi | \n");
    printf("| mo do vencimento?                                              | \n");

    // colocariamos aqui uma opcao no futuro

}