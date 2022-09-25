#include <stdio.h>
#include <stdlib.h>
#include "modulocadastroUsuario.h"
#include "modulocadastroItem.h"
#include "modulolistadeCompras.h"
#include "moduloRelatorio.h"
#include "moduloSobre.h"
#include "moduloEntradaItens.h"
#include "moduloSaidaItens.h"



int main (void)
{
    char escolha;
    do {
        escolha = telaPrincipal();
        switch (escolha) {
        case '1':
            telaCadastroUsuario();
            break;
        case '2':
            telaCadastroItens();
            break; 
        case '3':
            telaListadeCompras();
            break;
        case '4':
            telaEntradaItens();
            break; 
        case '5':    
            telaSaidaItens();
            break;
        case '6':
            telaRelatorio();
            break; 
        case '7':
            telaSobre();
            break;
        case '0':
            printf("Fim do programa");
            break;
        default:
            printf("Opcao invalida");
            break;
        }  

    }while(escolha != '0');
   
    return escolha;

}

char telaPrincipal (void)
{
    char opcao;
    system ( " clear||cls " );
    printf (" | =================================================================== | \n");
    printf (" | =========================| SIG - Pranty |========================== | \n");
    printf (" | =================================================================== | \n");
    printf (" | ------------------------------------------------------------------- | \n");
    printf (" |                                                                     | \n");
    printf (" |                       1 - Cadastrar usuario                         | \n");
    printf (" |                       2 - Cadastrar itens                           | \n");
    printf (" |                       3 - Lista de compras                          | \n");
    printf (" |                       4 - Entrada de itens                          | \n");
    printf (" |                       5 - Saida de itens                            | \n");
    printf (" |                       6 - Relatorio                                 | \n");
    printf (" |                       7 - Informacoes                               | \n");
    printf (" |                       0 - Sair                                      | \n");
    printf (" |                                                                     | \n");                                                                      
    printf (" | ------------------------------------------------------------------- | \n");
    printf (" | =================================================================== | \n");
    printf (" | Escolha uma opcao: ");
    scanf ( "%c", &opcao);
    getchar();

    return opcao;
    
}

