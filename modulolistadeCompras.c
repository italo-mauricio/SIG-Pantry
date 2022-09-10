#include <stdio.h>
#include <stdlib.h>
#include "modulolistadeCompras.h"

char telaCadastroCompras(void);

int  main (void)
{
    char escolha;
    do {
        escolha = telaListadeCompras();
        switch (escolha) {
        case '1':
            telaAlimentoVencimento();
            break;
        case '2':
            telaAlimentoVencimento();
            break; 
        case  '3':
            telaAlimentoVencimento();
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
} 

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



char telaAlimentoVencimento (void)

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



char telaHigieneVencimento (void)
{

    printf("| ============================================================= | \n");
    printf("| ------------------------------------------------------------- | \n");
    printf("| ------------- | Higiene Proximo ao Vencimento | ------------- | \n");
    printf("|                                                               | \n");
    printf("| Nome do produto:                                              | \n");
    printf("| Data de cadastro do produto:                                  | \n");
    printf("| Data de vencimento:                                           | \n");
    printf("|                                                               | \n");
    printf("| ============================================================= | \n");
    printf("| Deseja ser notificado quando o produto estiver proximo ao ven | \n");
    printf("| cimento?                                                      | \n");


}



char telaLimpezaVencimento (void)
{

    printf("| ============================================================= | \n");
    printf("| ------------------------------------------------------------- | \n");
    printf("| ------------- | Limpeza Proximo ao Vencimento | ------------- | \n");
    printf("|                                                               | \n");
    printf("| Nome do produto:                                              | \n");
    printf("| Data de cadastro do produto:                                  | \n");
    printf("| Data de vencimento:                                           | \n");
    printf("|                                                               | \n");
    printf("| ============================================================= | \n");
    printf("| Deseja ser notificado quando o produto estiver proximo ao ven | \n");
    printf("| cimento?                                                      | \n");




}