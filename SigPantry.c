#include <stdio.h>
#include <stdlib.h>
#include "modulocadastroUsuario.h"
#include "modulocadastroItem.h"
#include "modulolistadeCompras.h"
#include "moduloRelatorio.h"
#include "moduloSobre.h"


// Assinatura das funções
char telacadastroUsuario(void);
char telaCadastroItens(void);
char telaListadeCompras(void);
char telaRelatorio(void);
char telaSobre(void);
char telaPrincipal(void);



int  main (void)
{
    int escolha;
    do {
        escolha = telaPrincipal();
        switch (escolha) {
        case 1:
            telaCadastroUsuario();
            break;
        case 2:
            telaCadastroItens();
            break; 
        case 3:
            telaListadeCompras();
            break;
        case 4:
            telaRelatorio();
            break; 
        case 5:    
            telaSobre ();
            break;
        default:
            printf("Opcao invalida");
            break;
        }        
    }while(escolha != '0');
    return 0;

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
    printf (" |                        1 - Cadastrar usuario                        | \n");
    printf (" |                        2 - Cadastrar itens                          | \n");
    printf (" |                        3 - Lista de compras                         | \n");
    printf (" |                        4 - Relatorio                                | \n");
    printf (" |                        5 - Informacoes                              | \n");
    printf (" |                        0 - Sair                                     | \n");
    printf (" |                                                                     | \n");                                                                      
    printf (" | ------------------------------------------------------------------- | \n");
    printf (" | =================================================================== | \n");
    printf (" | Escolha uma opcao: ");

    scanf ( "%c", &opcao);

    return opcao;
}

