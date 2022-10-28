#include <stdio.h>
#include<stdlib.h>
#include "moduloSaidaItens.h"
#include <string.h>
#include "validacoes.h"

void moduloSaidaItens(void)
{
    Saida* regSaida;
    CancelarSaid* cancSaida;
    char escolha;
    do {
        escolha = telaSaidaItens();
        switch(escolha) {
            case '1':
                regSaida = infoSaida( );
                break;
            case '2':
                cancSaida = infoCancelarSaid( );
                break;
            default:
                printf("Opção inválida!");
                break;
        } 
     
    } while (escolha != '0');

    free (regSaida);
    free (cancSaida);

}

char telaSaidaItens(void)
{
    char esc;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------- SIG-Pantry - SAÍDA DE ITENS DA DESPENSA -------- | \n");
    printf(" |                                                           | \n");
    printf(" |                  1- Registrar saída                       | \n");
    printf(" |                  2- Cancelar saída                        | \n");                 
    printf(" |                  0- Voltar à tela principal               | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    getchar();

    return esc;    

}

Saida* infoSaida( )
{
    Saida* cancs;
    cancs = (Saida*) malloc(sizeof(Saida));
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ---------------- REGISTRAR SAÍDA DE ITEM ---------------- | \n");
    printf(" |                                                           | \n");    
    do
    {
        printf(" | Informe o código de barras: ");
        scanf("%s", cancs->codigodeBarras);
        getchar();
        
    } while (!lerQuantidade(cancs->codigodeBarras));

    do
    {
        printf(" | Informe a quantidade de produto: ");
        scanf("%s", cancs->QuantProduto);
        getchar();
        
    } while (!lerQuantidade(cancs->QuantProduto));

    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    system("Pause");
    system("cls");

    return cancs;
}

CancelarSaid* infoCancelarSaid( )
{
    CancelarSaid* cancelar;
    cancelar = (CancelarSaid*) malloc(sizeof(CancelarSaid));
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ---------------- REGISTRAR SAÍDA DE ITEM ---------------- | \n");
    printf(" |                                                           | \n");    
    do
    {
        printf(" | Informe o código de barras: ");
        scanf("%s", cancelar->codigodeBarras);
        getchar();
        
    } while (!lerQuantidade(cancelar->codigodeBarras));

    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    getchar();

    return cancelar;

}