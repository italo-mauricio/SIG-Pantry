#include<stdio.h>
#include<stdlib.h>
#include "modulocadastroItem.h"

char modulocadastroItem(void) {
    int escolha;
    do {
        escolha = telaMenuItens();
        switch(escolha) {
            case 1:
                telaCadastrarItem();
                break;
            case 2:
                telaCategoriadoProduto();
                break;
            case 3: 
                telaLocaldeArmazenamento();
                break;
            case 4:
                telaEstoqueMinimo();
                break;
            case 5:
                telaEditarItem();
                break;
            case 6:
                telaExcluirItem();
                break;
            default:
                printf("Opção inválida\n");
                break;
        } 
     
    } while (escolha != 0);

    return escolha;

}


char telaMenuItens(void)
{
    char esc;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ----------------- SIG-Pantry - MENU ITENS --------------- | \n");
    printf(" |                                                           | \n");
    printf(" |                 1- Cadastrar item                         | \n"); 
    printf(" |                 2- Categoria do produto                   | \n"); 
    printf(" |                 3- Local de armazenamento                 | \n");
    printf(" |                 4- Estoque mínimo do item                 | \n");
    printf(" |                 5- Atualizar itens                        | \n");
    printf(" |                 6- Excluir itens                          | \n");                 
    printf(" |                 0- Voltar à tela principal                | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc);
    getchar();

    return esc;

}


char telaCadastrarItem(void)
{
    char esc;
    char nomeProduto [20];
    char nomeMarca [20];
    char codigoBarras [13];
    char dataValidade [10];
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------- SIG-Pantry - CADASTRAR ITENS ------------- | \n");
    printf(" |                                                           | \n");
    printf(" | Nome do produto: ");
    scanf("%[A-Z a-z]", nomeProduto);
    getchar(); 
    printf(" | Nome da marca: ");
    scanf("%[A-Z a-z]", nomeMarca);
    getchar(); 
    printf(" | Código de barras: ");
    scanf("%[A-Z a-z., 0-9., -]", codigoBarras);
    getchar(); 
    printf(" | Data de validade do produto (dd/mm/aa): ");
    scanf("%[0-9., /]", dataValidade);
    getchar(); 
    printf(" | 0- Voltar à tela de cadastro \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    scanf("%c", &esc); 
    getchar();
    return esc;

}
/*void telaCadastrarAlimento(void) 
{
    char opcao;
    if(opcao == 1){
        printf('Nome do item:\n');
    } if(opcao == 2) {
        printf('Data de validade:\n');
    } if(opcao == 3) {
        //printf('Local de armazenamento:\n'); pensar em puxar as opções: geladeira, armário...
    } else {
        printf('Voltar a tela de Cadastro de Itens');
    }

}
*/

char telaCategoriadoProduto(void)
{
    char esc;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ------------------ CATEGORIA DO PRODUTO ----------------- | \n");
    printf(" |                                                           | \n");    
    printf(" |                 1- Item alimentar                         | \n");
    printf(" |                 2- Item de higiene pessoal                | \n"); 
    printf(" |                 3- Item de limpeza                        | \n");         
    printf(" |                 0- Voltar à tela principal                | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &esc); 
    getchar();
    return esc; 

}

char telaLocaldeArmazenamento(void) 
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ----------------- LOCAL DE ARMAZENAMENTO ---------------- | \n");
    printf(" |                                                           | \n");
    printf(" |                1- Geladeira                               | \n");
    printf(" |                2- Armário da cozinha                      | \n");
    printf(" |                3- Armário da área de serviço              | \n");  
    printf(" |                4- Armário do banheiro                     | \n"); 
    printf(" |                5- Guarda-roupa                            | \n");       
    printf(" |                0- Voltar à tela de cadastro               | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opção: ");
    scanf("%c", &opcao);  
    
    return opcao;

}

char telaEstoqueMinimo(void)
{
    char esc;
    char estoqueMinimo [20];
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ----------- SIG-Pantry - ESTOQUE MÍNIMO DO ITEM --------- | \n");
    printf(" |                                                           | \n");
    printf(" | Estoque mínimo do produto cadastrado: ");
    scanf("%[0-9]", estoqueMinimo);
    getchar(); 
    printf(" | 0- Voltar à tela de cadastro \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    scanf("%c", &esc); 
    getchar();
    return esc;

}

char telaEditarItem(void)
{
    char opcao;
    char nome [20];
    char barras [13];
    char data [10];
    char categoria [20];
    int armazenamento;
    system( " clear || cls");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | --------------------- ATUALIZAR ITENS ------------------------ | \n");
    printf(" |                                                                | \n");
    printf(" |  Atualizar nome: ");
    scanf("%[A-z a-z]", nome);
    getchar();
    printf(" |  Atualizar código de barras: ");
    scanf("%[0-9]", barras);
    printf(" |  Atualizar data de validade: ");
    scanf("%[0-9 / ]", data);
    getchar();
    printf(" |  Atualizar categoria: ");
    scanf("%[A-Z a-z 0-9]", categoria);
    getchar();
    //printf(" |  Atualizar local de armazenamento: ");
    //scanf("%d", armazenamento);
    //getchar();
    printf(" | ------------------------------------------------------------- | \n");
    printf(" | ============================================================= | \n");
    printf( " Press ENTER for continue...");
    scanf("%c", &opcao);
    getchar();
    return opcao;

}

char telaExcluirItem(void)
{
    char opcao;
    char barra [13];
    system( " clear || cls ");
    printf(" | ============================================================== | \n");
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ----------------------- EXCLUIR ITENS ------------------------ | \n");
    printf(" |                                                                | \n");
    printf(" | Digite o código de barras do produto: ");
    scanf("%[0-9]", barra);
    getchar();
    // aqui terá um if se o código de barra for encontrado ele entrará nas opções
    // if barra == (nosso banco de dados);
        // digite a quantidade de itens que deseja excluir;
        // os itens serão removidos.
    printf(" | -------------------------------------------------------------- | \n");
    printf(" | ============================================================== | \n");
    printf(" Press ENTER for continue... ");
    scanf("%c", &opcao);
    getchar();

    return opcao;

}
