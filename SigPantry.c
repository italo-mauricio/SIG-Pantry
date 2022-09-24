#include <stdio.h>
#include <stdlib.h>
#include "modulocadastroUsuario.h"
#include "modulocadastroItem.h"
#include "modulolistadeCompras.h"
#include "moduloRelatorio.h"
#include "moduloSobre.h"
#include "moduloEntradaItens.h"
#include "moduloSaidaItens.h"


// Assinatura das funções
char telacadastroUsuario(void);
char telaCadastroItens(void);
char telaListadeCompras(void);
char telaRelatorio(void);
void telaSobre(void);
char telaPrincipal(void);
char telaEntradaItens(void);
char telaSaidaItens(void);

int main (void)
{
    char opcao;
    do {
        opcao = telaPrincipal();
        switch (opcao) {
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
            telaRelatorio();
            break; 
        case '5':    
            telaSobre ();
        /*case '6':
            telaEntradaItens();
            break;
        case '7':
            telaSaidaItens();
            break;*/
        case '0':
            printf("Fim do programa");
            break;
        default:
            printf("Opcao invalida");
            break;
        }  

    }while(opcao != '0');
   
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
// colocar opções de entrada e saída no menu principal e alterar itens no cadastrar itens

