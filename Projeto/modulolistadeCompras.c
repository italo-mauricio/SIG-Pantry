#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modulolistadeCompras.h"
#include "validacoes.h"


void menulistadeCompras(void)
{
    MontarLista* itemproduto;
    char escolha;
    do {
        escolha = telaListadeCompras();
        switch (escolha) {
        case '1':
            itemproduto = infoMontarLista();
            break;
        case '2':
            telaItensQuantMinima();
            break; 
        case '3':
            telaItensProxVencimento();
            break;
        case '4':
            telaAdicionarItensaLista();
            break; 
        case '5':
            exibeListaCompras(itemproduto);
            free(itemproduto); 
            break;
        default:
            printf("Opção inválida\n");
            break;
    }

    } while(escolha != '0');
        printf("Obrigado! Volte sempre!");

} 

char telaListadeCompras(void)
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | -------------------| SIG-Pantry - LISTA DE COMPRAS |---------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |          1- Montar sua lista de compras                              | \n");
    printf(" |          2- Visualizar itens no estoque com quantidade mínima        | \n");
    printf(" |          3- Visualizar itens próximos ao vencimento                  | \n");
    printf(" |          4- Adicionar itens à lista                                  | \n"); 
    printf(" |          5- Visualizar itens já cadastrados na lista                 | \n");      
    printf(" |          0- Voltar à tela principal                                  | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &opcao);
    getchar();

    return opcao;

} 

//Aqui será um relatório
void telaItensQuantMinima(void)
{
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ----------- | ITENS NO ESTOQUE COM QUANTIDADE MÍNIMA | ------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |  Itens no estoque com quantidade mínima:  "); //criar função para puxar essa informação
    getchar();
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    system("Pause");
    system("cls");
    getchar();

}

//Aqui será um relatório
void telaItensProxVencimento(void)
{
    //criar um ponteiro que puxe a informação com base na data de validade do cadastro de itens
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ----------------- | ITENS PRÓXIMOS AO VENCIMENTO | ----------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |  Itens próximos ao vencimento: ");
    getchar();
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    system("Pause");
    system(" clear || cls");
    getchar();

}

char telaAdicionarItensaLista(void)
{
    char esc;
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ------------ |    ADICIONAR ITENS À LISTA DE COMPRAS | ------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |           1- Adicionar automaticamente itens que estão acabando      | \n");
    printf(" |           2- Adicionar itens da sua escolha                          | \n"); 
    printf(" |           0- Voltar à tela de lista de compras                       | \n"); 
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    getchar();

    return esc;
// nessa opção de itens à sua escolha cria-se uma outra tela, onde terá nome; quantidade...
}

MontarLista* infoMontarLista(void)
{
    MontarLista* mtlista;
    mtlista = (MontarLista*)malloc(sizeof(MontarLista));
    system (" clear||cls ");
    printf("| ============================================================= | \n");
    printf("| ------------------------------------------------------------- | \n");
    printf("| ------------- | MONTAR A SUA LISTA DE COMPRAS | ------------- | \n");
    printf("|                                                               | \n");
    do
    {
        printf(" | Informe o nome: ");
        scanf("%s", mtlista->nome);
        getchar();
        
    } while (!lerLetras(mtlista->nome));

    do
    {
        printf(" | Informe a categoria do produto: ");
        scanf("%s", mtlista->categoriaProduto);
        getchar();
        
    } while (!lerLetras(mtlista->categoriaProduto));

    do
    {
        printf(" | Informe a quantidade de produto: ");
        scanf("%s", mtlista->quantidadeProduto);
        getchar();
        
    } while (!lerQuantidade(mtlista->quantidadeProduto));
    
    printf("|                                                               | \n");
    printf("| ============================================================= | \n");
    system("Pause");
    system("clear||cls");
    mtlista->status = 't';
    return mtlista;
}

//função para exibir os itens já cadastrados na lista
void exibeListaCompras(MontarLista* mtlista)
{
    char situ [20];
    if((mtlista == NULL) || (mtlista->status == 'x')){
        printf("Item inexistente na lista de compras");
    } else {
        system ( " clear||cls " );
        printf(" | ==================================================================== | \n");
        printf(" | -------------------------------------------------------------------- | \n");
        printf(" | ----------------- | ITENS JÁ CADASTRADOS NA LISTA | ---------------- | \n");
        printf(" |                                                                      | \n");
        printf(" |  Nome dos itens: %s\n", mtlista->nome); 
        printf(" |  Categoria dos itens: %s\n", mtlista->categoriaProduto); 
        printf(" |  Quantidade dos itens: %s\n", mtlista->quantidadeProduto); 
        printf(" |                                                                      | \n");
        printf(" | ==================================================================== | \n");
        system("Pause");
        system("clear||cls");
        getchar();
        
    }
    printf("Situação da lista de compras: %s\n", situ);
}


//função para gravar no arquivo
void gravaLista(MontarLista* mtlista) 
{
    FILE* fp;
    fp = fopen("mtlista.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        exit(1);
    }
    
    fwrite(mtlista, sizeof(MontarLista), 1, fp);
    fclose(fp);
    
}
