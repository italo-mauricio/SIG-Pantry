#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moduloSaidaItens.h"
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
                regSaida = infoSaida();
                gravaSaida(regSaida);
                free(regSaida);
                break;
            case '2':
                cancSaida = infoCancelarSaid();
                gravaCancelamentoSaida(cancSaida);
                free(cancSaida);
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
Saida* infoSaida(void)
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
    printf(" | Press ENTER for exit... ");
    getchar();
    cancs->status = '1'; //o true mostra que foi cadastrado
    return cancs;

}

//Função para gravar no arquivo:
void gravaSaida(Saida* cancs) 
{
    FILE* fp;
    fp = fopen("saida.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        exit(1);
    }
    
    fwrite(cancs, sizeof(Saida), 1, fp);
    fclose(fp);
    
}


//função para o cancelamento da saída de algum item
CancelarSaid* infoCancelarSaid(void)
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
    cancelar->status = '1'; 
    return cancelar;

}


//Função para gravar no arquivo:
void gravaCancelamentoSaida(CancelarSaid* cancelar) 
{
    FILE* fp;
    fp = fopen("cancSaida.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        exit(1);
    }
    
    fwrite(cancelar, sizeof(CancelarSaid), 1, fp);
    fclose(fp);
    
}