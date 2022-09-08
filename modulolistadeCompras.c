#include <stdio.h>
#include <stdlib.h>

char telaCadastroUsuario(void);
char cadastroUsuario(void);
char telaEditar(void);
char telaListar(void);
char telaRemove(void);

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
            telavisualizarAlimentosestoque();
            break; 
        case '5':
            telavisualizarHigieneestoque();
            break; 
        case '6':
            telavisualizarLimpezaestoque();
            break; 
        case '7':
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
    printf(" |      1- Visualizar itens alimentares proximo ao vencimento           | \n");
    printf(" |      2- Visualizar itens de higiene pessoal proximo ao vencimento    | \n");
    printf(" |      3- Visualizar itens de limpeza proximo ao vencimento            | \n");
    printf(" |      4- Visualizar itens alimentares que estao no estoque            | \n");
    printf(" |      5- Visualizar itens de higiente pessoal que estao no estoque    | \n");
    printf(" |      6- Visualizar itens de limpeza que estao no estoque             | \n");
    printf(" |      7- Montar a propria listinha                                    | \n");    
    printf(" |      0- Voltar a tela principal                                      | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opcao:                                                   | \n");
    printf(" | ==================================================================== | \n");
    scanf("%c", &opcao);
    getchar();

    return opcao;

}