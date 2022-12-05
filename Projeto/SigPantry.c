#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modulocadastroUsuario.h"
#include "modulolistadeCompras.h"
#include "moduloRelatorio.h"
#include "moduloSobre.h"
#include "moduloMenuItem.h"
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
            moduloMenuItem();
            break; 
        case '3':    
            menuSaidaItens();
            break;
        case '4':
            menulistadeCompras();
            break;
        case '5':
            moduloRelatorio();
            break; 
        case '6':
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
    printf (" |                        2 - Entrada de itens                         | \n");
    printf (" |                        3 - Saída de itens                           | \n");
    printf (" |                        4 - Lista de compras                         | \n");
    printf (" |                        5 - Relatório                                | \n");
    printf (" |                        6 - Informações                              | \n");
    printf (" |                        0 - Sair                                     | \n");
    printf (" |                                                                     | \n");                                                                      
    printf (" | ------------------------------------------------------------------- | \n");
    printf (" | =================================================================== | \n");
    printf (" | Escolha uma opção: ");
    scanf ( "%c", &opcao);
    getchar();

    return opcao;
    
}

