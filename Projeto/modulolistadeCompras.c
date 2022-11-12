#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modulolistadeCompras.h"
#include "validacoes.h"

void menulistadeCompras(void)
{
    char escolha;
    do {
        escolha = telaListadeCompras();
        switch (escolha) {
        case '1':
            telaItensQuantMinima(); //listar estoque mínimo
            break; 
        case '2':
            telaItensProxVencimento(); //listar itens próximos ao vencimento
            break;
        case '3':
            infoMontarLista(); //preencher a lista
            break;
        case '4':
            pesquisarLista(); //pesquisa
            break;
        case '5':
            editarLista(); //edição
            break;
        case '6':
            excluirLista(); //exclusão
            break;
        case '7':
            listaComprasPronta(); //exibição da lista pronta (relatório)
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
    printf(" |             1- Visualizar itens no estoque com quantidade mínima     | \n");
    printf(" |             2- Visualizar itens próximos ao vencimento               | \n");
    printf(" |             3- Montar sua lista de compras                           | \n");
    printf(" |             4- Pesquisar lista de compras                            | \n");      
    printf(" |             5- Editar lista de compras                               | \n");      
    printf(" |             6- Excluir lista de compras                              | \n");      
    printf(" |             7- Visualizar itens cadastrados na lista                 | \n");       
    printf(" |             0- Voltar à tela principal                               | \n");
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &opcao);
    getchar();

    return opcao;

} 

//Aqui será um relatório/lista
void telaItensQuantMinima(void)
{
    //criar um ponteiro que puxe a informação com base no estoque mín do cadastro de itens
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ----------- | ITENS NO ESTOQUE COM QUANTIDADE MÍNIMA | ------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |  Itens no estoque com quantidade mínima:  "); 
    getchar();
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    system("Pause");
    system("cls");
    getchar();

}

//Aqui será um relatório/lista
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
//ver se procura pelo nome da lista ou pelo username do usuário
void infoMontarLista(void)
{
    MontarLista* mtlista;
    system ( " cls " );
    printf("| ============================================================= | \n");
    printf("| ------------------------------------------------------------- | \n");
    printf("| ------------- | MONTAR A SUA LISTA DE COMPRAS | ------------- | \n");
    printf("|                                                               | \n");
    mtlista = (MontarLista*)malloc(sizeof(MontarLista));
    do
    {
        printf(" | Informe um nome para a sua lista: "); 
        scanf("%s", mtlista->nomeLista);
        getchar();
        
    } while (!lerLetras(mtlista->nomeLista));
    
    do
    {
        printf(" | Informe o nome do produto: "); //criar condicional "deseja cadastrar mais prod?"
        scanf("%s", mtlista->nome);
        getchar();
        
    } while (!lerLetras(mtlista->nome));

    do
    {
        printf(" | Informe a quantidade de produto: ");
        scanf("%s", mtlista->quantidadeProduto);
        getchar();
        
    } while (!lerQuantidade(mtlista->quantidadeProduto));
    
    printf("|                                                               | \n");
    printf("| ============================================================= | \n");
    printf(" | Press ENTER for exit... ");
    mtlista->status = '1';
    gravaLista(mtlista);
    free(mtlista);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();

}

//função para gravar no arquivo
void gravaLista(MontarLista* mtlista) 
{
    FILE* fp;
    fp = fopen("lista.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        exit(1);
    }
    
    fwrite(mtlista, sizeof(MontarLista), 1, fp);
    fclose(fp);
    
}

//A partir do código de barras
void buscaLista(void)
{
    FILE* fp;
    MontarLista* mtlista;
    int achou;
    char procurado[15];
    fp = fopen("lista.dat", "rb");

    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
    }
    printf("\n\n");
    system ( " cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                   Buscar dados da lista                   | \n");
    printf(" | ========================================================= | \n");
    printf("Informe o nome da lista: ");
    scanf(" %30[^\n]", procurado);
    getchar();
    mtlista = (MontarLista*) malloc(sizeof(MontarLista));
    achou = 0;
    while((!achou) && (fread(mtlista, sizeof(MontarLista), 1, fp))) {
        printf("Nome da lista |%s|\n", mtlista->nomeLista);
        if ((strcmp(mtlista->nomeLista, procurado) == 0) && (mtlista->status == '1')) {
            achou = 1;
        }
    }
    fclose(fp);
    if (achou) {
        exibeListaCompras(mtlista);
    } else {
        printf("Os dados da lista %s não foram encontrados\n", procurado);
    }
    free(mtlista);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    
}

void exibeListaCompras(MontarLista* mtlista) 
{
    printf(" | Nome da lista: %s\n", mtlista->nomeLista);    
    printf(" | Nome do produto: %s\n", mtlista->nome);
    printf(" | Quantidade do produto: %s\n", mtlista->quantidadeProduto);
    printf(" | Status: %c\n", mtlista->status);
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    
}

//EDITAR AQUI


//Função para exclusão lógica
void excluirLista(void)
{
    FILE* fp;
    MontarLista* mtlista;
    int achou;
    char resp;
    char nomeLista[20];
    fp = fopen("lista.dat", "r+b");

    if (fp == NULL){
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
    }
    mtlista = (MontarLista*) malloc(sizeof(MontarLista));
    system( " clear || cls ");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ------------------------ EXCLUIR LISTA ----------------------- | \n");
    printf(" |                                                                | \n");
    printf(" | Informe o nome da lista que você deseja excluir: ");
    scanf("%s", mtlista->nomeLista);
    getchar();  
    achou = 0;
    while ((!achou) && (fread(mtlista, sizeof(MontarLista), 1, fp))){
        if ((strcmp(mtlista->nomeLista, nomeLista) == 0) && (mtlista->status == '0')){
            achou = 1;
        }
    }

   if (achou){
        exibeListaCompras(mtlista);
        getchar();
        printf("Deseja realmente excluir esta lista? (s/n)");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S'){
            mtlista->status = '0';
            fseek(fp, (-1)*sizeof(MontarLista), SEEK_CUR);
            fwrite(mtlista, sizeof(mtlista), 1, fp);
            printf("\nLista excluída com sucesso!");
        }else{
            printf("\nTudo bem, a lista não foi alterada!");
        }
    }else{
        printf("A lista não foi encontrada!");
    }
    free(mtlista);
    fclose(fp);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    
}

//listar a lista pronta
void listaComprasPronta(void) 
{
    FILE* fp;
    MontarLista* mtlista;
    fp = fopen("lista.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
    }
    printf("\n\n");
    printf(" | ===================== Exibe lista ======================= | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    mtlista = (MontarLista*)malloc(sizeof(MontarLista));
    while(fread(mtlista, sizeof(MontarLista), 1, fp)) {
        exibeListaCompras(mtlista);
    }
    fclose(fp);
    free(mtlista);

}