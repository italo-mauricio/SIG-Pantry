#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "modulolistadeCompras.h"
#include "validacoes.h"
#include "modulocadastroUsuario.h"
#include "modulocadastroItem.h"
#include "moduloSaidaItens.h"

void menulistadeCompras(void)
{
    char escolha;
    do {
        escolha = telaListadeCompras();
        switch (escolha) {
        case '1':
            itensQuantMinima(); //listar estoque mínimo
            break; 
        case '2':
            itensProxVencimento(); //listar itens próximos ao vencimento
            break;
        case '3':
            infoMontarLista(); //preencher a lista
            break;
        case '4':
            buscaLista(); //pesquisa
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
            printf("Opção in válida\n");
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

//função feita para informar a quantid. mínima de itens com base no que foi registrado 
char itensQuantMinima(void)     
{
    FILE *fp;
    Item* it;
    Saida* said;
    int achou;
    char resp;
    char procurado[20];

    fp = fopen("itens.dat", "rt");
    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo");
        exit(1);
    }
    it = (Item*)malloc(sizeof(Item));

    fp = fopen("saida.dat", "rt");
    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo");
        exit(1);
    }
    said = (Saida*)malloc(sizeof(Saida));
        
    system( " clear || cls ");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | --------- Itens com quantidade mínima na despensa ------------ | \n");
    printf(" |              ");


/* [14:04, 19/11/2022] Vinicius: Puxar a informação de
[14:04, 19/11/2022] Vinicius: Número mínimo
[14:04, 19/11/2022] Vinicius: O total de saídas
[14:04, 19/11/2022] Vinicius: Faz a conta
[14:04, 19/11/2022] Vinicius: E retorna o resultado disso
[14:04, 19/11/2022] Vinicius: Aí, acredito que vc tbm teria que verificar o id de cada um
[14:04, 19/11/2022] Vinicius: Pra ver se era esse mesmo */

//tem que pedir o código de barras (id)

}

//Aqui será um relatório/lista
void itensProxVencimento(void)
{
    //criar um ponteiro que puxe a informação com base na data de validade do cadastro de itens
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ----------------- | Itens próximos ao vencimento | ----------------- | \n");
    printf(" |                                                                      | \n");
    printf(" |  Itens próximos ao vencimento: ");
    getchar();
    printf(" |                                                                      | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Pressione qualquer tecla para sair... ");
    getchar();

}

//ver se procura pelo nome da lista ou pelo username do usuário
void infoMontarLista(void)
{
    MontarLista* mtlista;
    Usuario* cliente;
    char resp;
    system ( " cls || clear " );
    printf("| ============================================================= | \n");
    printf("| ------------------------------------------------------------- | \n");
    printf("| ------------- | Montar a sua lista de compras | ------------- | \n");
    printf("|                                                               | \n");
    mtlista = (MontarLista*)malloc(sizeof(MontarLista));
    cliente = (Usuario*) malloc(sizeof(Usuario));
    do
    {
        printf(" | Informe o seu username: "); 
        scanf("%s", cliente->usernameUsuario);
        getchar();
        
    } while (!lerLetras(mtlista->nomeLista));
        
    do
    {
        printf(" | Informe um nome para a sua lista: "); 
        scanf("%s", mtlista->nomeLista);
        getchar();
        
    } while (!lerLetras(mtlista->nomeLista));
    
    do
    {
        printf(" | Informe o nome do produto: "); 
        scanf("%s", mtlista->nome);
        getchar();
        
    } while (!lerLetras(mtlista->nome));

    do 
    {
        printf(" | Informe a quantidade de produto: ");
        scanf("%s", mtlista->quantidadeProduto);
        getchar();
        
    } while (!lerQuantidade(mtlista->quantidadeProduto));

    printf("Deseja adicionar outro produto a lista? s/n");
    scanf("%c", &resp);
    getchar();
    
    if ((resp == 's') || (resp == 'S')) {
        do
        {
            printf(" | Informe o nome do produto: "); 
            scanf("%s", mtlista->nome);
            getchar();
            
        } while (!lerLetras(mtlista->nome));
        
        do
        {
            printf(" | Informe a quantidade de produto: ");
            scanf("%s", mtlista->quantidadeProduto);
            getchar();
            
        } while (!lerQuantidade(mtlista->quantidadeProduto));
        gravaLista(mtlista);
        
        } else {
            printf("Ok! Vamos prosseguir");
        }
    
    printf("|                                                               | \n");
    printf("| ============================================================= | \n");
    mtlista->status = '1';
    gravaLista(mtlista);
    free(mtlista);
    gravaUsuario(cliente);
    free(cliente);
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

//função de pesquisa a partir do username (id do usuário)
void buscaLista(void)
{
    FILE* fp;
    MontarLista* mtlista;
    Usuario* cliente;
    int achou;
    char procurado[15];
    fp = fopen("lista.dat", "rb");

    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
    }
    printf("\n\n");
    system ( " cls  || clear " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" |                   Buscar dados da lista                   | \n");
    printf(" | ========================================================= | \n");
    printf("Informe o seu username: ");
    scanf(" %30[^\n]", procurado);
    getchar();
    mtlista = (MontarLista*) malloc(sizeof(MontarLista));
    cliente = (Usuario*) malloc(sizeof(Usuario));
    achou = 0;
    while((!achou) && (fread(mtlista, sizeof(MontarLista), 1, fp))) {
        printf("Nome da lista |%s|\n", mtlista->nomeLista);
        if ((strcmp(mtlista->nomeLista, procurado) == 0) && (mtlista->status == '1')) {
            achou = 1;
        }
    }
    fclose(fp);
    if (achou) {
        system(" cls || clear");
        printf(" | =================== Lista encontrada ==================== |\n");
        printf(" |                                                           |\n");
        printf(" | Nome da lista: %s\n", mtlista->nomeLista);    
        printf(" | Nome do produto: %s\n", mtlista->nome);
        printf(" | Quantidade do produto: %s\n", mtlista->quantidadeProduto);
        printf(" | Status: %c\n", mtlista->status);
        printf(" |                                                           | \n");
        printf(" | ========================================================= | \n");
        printf(" | Pressione qualquer tecla para sair.... ");
        getchar();
    
    } else {
        printf("Os dados da lista %s não foram encontrados\n", procurado);
    }
    free(mtlista);
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    
}

void exibeListaCompras(MontarLista* mtlista) 
{
    system(" cls || clear");
    printf(" | =================== Lista cadastrada ==================== |\n");
    printf(" |                                                           | \n");
    printf(" | Nome do produto: %s\n", mtlista->nome);
    printf(" | Quantidade do produto: %s\n", mtlista->quantidadeProduto);
    printf(" | Status: %c\n", mtlista->status);
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Pressione qualquer tecla para sair.... ");
    getchar();
    
}

//função para edição
void editarLista(void) 
{

}

//Função para exclusão lógica
void excluirLista(void)
{
    FILE* fp;
    MontarLista* mtlista;
    int achou;
    char resp;
    char procura[20];
    fp = fopen("lista.dat", "r+b");

    if (fp == NULL){
        printf("Ops! Erro na abertura do arquivo!\n");
        exit(1);
    }
    mtlista = (MontarLista*) malloc(sizeof(MontarLista));
    system( " clear || cls ");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ------------------------ Excluir lista ----------------------- | \n");
    printf(" |                                                                | \n");
    printf(" | Informe o seu username para procurar a lista que você deseja excluir: ");
    scanf("%s", procura);
    getchar();  
    achou = 0;
    while ((!achou) && (fread(mtlista, sizeof(MontarLista), 1, fp))){
        if ((strcmp(mtlista->nomeLista, procura) == 0) && (mtlista->status == '1')){
            achou = 1;
        }
    }

   if (achou){
        exibeListaCompras(mtlista);
        getchar();
        printf("Deseja realmente excluir os dados desta saída? (s/n)");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S'){
            mtlista->status = '0';
            fseek(fp, (-1)*sizeof(MontarLista), SEEK_CUR);
            fwrite(mtlista, sizeof(mtlista), 1, fp);
            printf("\nLista excluída com sucesso!");
            gravaLista(mtlista);
            printf(" Pressione qualquer tecla para sair... ");
            getchar();
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