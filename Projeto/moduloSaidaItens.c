#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloSaidaItens.h"
#include "validacoes.h"

void moduloSaidaItens(void)
{
    char escolha;
    do {
        escolha = telaSaidaItens();
        switch(escolha) {
            case '1':
                infoSaida( );
                break;
            case '2':
                infoCancelarSaid( );
                break;
            default:
                printf("Opção inválida!");
                break;
        } 
     
    } while (escolha != '0');


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

//função para informar a saída de algum item
void infoSaida(void)
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

}

//função para o cancelamento da saída de algum item
void infoCancelarSaid(void)
{
    CancelarSaid* cancelar;
    cancelar = (CancelarSaid*) malloc(sizeof(CancelarSaid));
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------- REGISTRAR CANCELAMENTO DE SAÍDA DE ITEM -------- | \n");
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


}

//Função para gravar no arquivo:
void gravaEnt(Saida* cancs) 
{
    FILE* fp;
    fp = fopen("cancs.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        exit(1);
    }
    
    fwrite(cancs, sizeof(Saida), 1, fp);
    fclose(fp);
    
}