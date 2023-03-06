#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userRegistrationModule.h"
#include "moduloMenuItem.h"
#include "shoppingListModule.h"
#include "moduloRelatorio.h"
#include "moduloSobre.h"

char telaPrincipal(void);

int main (void)
{
    char escolha;
    do {
        escolha = telaPrincipal();
        switch (escolha) {
        case '1':
            userRegistrationModule();
            break;
        case '2':
            moduloMenuItem();
            break; 
        case '3':    
            shoppingListModule();
            break;
        case '4':
            moduloRelatorio();
            break; 
        case '5':
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

char telaPrincipal(void)
{
    char opcao;
    system ( " clear||cls " );
    printf (" | =================================================================== | \n");
    printf (" | =========================| SIG - Pantry |========================== | \n");
    printf (" | =================================================================== | \n");
    printf (" | ------------------------------------------------------------------- | \n");
    printf (" |                                                                     | \n");
    printf (" |                        1 - Menu usuário                             | \n");
    printf (" |                        2 - Menu item                                | \n");
    printf (" |                        3 - Lista de compras                         | \n");
    printf (" |                        4 - Relatórios                               | \n");
    printf (" |                        5 - Informações                              | \n");
    printf (" |                        0 - Sair                                     | \n");
    printf (" |                                                                     | \n");                                                                      
    printf (" | ------------------------------------------------------------------- | \n");
    printf (" | =================================================================== | \n");
    printf (" | Escolha uma opção: ");
    scanf ( "%c", &opcao);
    getchar();

    return opcao;
    
}

