#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modulocadastroUsuario.h"
#include "modulocadastroItem.h"
#include "modulolistadeCompras.h"
#include "moduloRelatorio.h"
#include "moduloSobre.h"
#include "moduloEntradaItens.h"
#include "moduloSaidaItens.h"

char telaPrincipal(void);

int main (void)
{
    char escolha;
    do {
        escolha = telaPrincipal();
        switch (escolha) {
        case '1':
            modulocadastroUsuario();
            break;
        case '2':
            modulocadastroItem();
            break; 
        case '3':
            menulistadeCompras();
            break;
        case '4':
            menuEntradaItens();
            break; 
        case '5':    
            moduloSaidaItens();
            break;
        case '6':
            moduloRelatorio();
            break; 
        case '7':
            telaSobre();
            break;
        case '0':
            printf("Fim do programa!");
            break;
        default:
            printf("Opção inválida!");
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
    printf (" | =========================| SIG - Pantry |========================== | \n");
    printf (" | =================================================================== | \n");
    printf (" | ------------------------------------------------------------------- | \n");
    printf (" |                                                                     | \n");
    printf (" |                        1 - Menu usuário                             | \n");
    printf (" |                        2 - Menu itens                               | \n");
    printf (" |                        3 - Lista de compras                         | \n");
    printf (" |                        4 - Entrada de itens                         | \n");
    printf (" |                        5 - Saída de itens                           | \n");
    printf (" |                        6 - Relatório                                | \n");
    printf (" |                        7 - Informações                              | \n");
    printf (" |                        0 - Sair                                     | \n");
    printf (" |                                                                     | \n");                                                                      
    printf (" | ------------------------------------------------------------------- | \n");
    printf (" | =================================================================== | \n");
    printf (" | Escolha uma opção: ");
    scanf ( "%c", &opcao);
    getchar();

    return opcao;
    
}

