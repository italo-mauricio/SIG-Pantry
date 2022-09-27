#include<stdio.h>
#include<stdlib.h>
#include "modulocadastroItem.h"

char modulocadastroItem(void) {
    int escolha;
    do {
        escolha = telaMenuItens();
        switch(escolha) {
            case 1:
                telaNomeProduto();
                break;
            case 2:
                telaNomeMarca();
                break;
            case 3: 
                telaCodigoBarras();
                break;
            case 4: 
                telaDatadeValidade();
                break;
            case 5: 
                telaCategoriadoProduto();
                break;
            case 6: 
                telaLocaldeArmazenamento();
                break;
            case 7:
                telaEditarItem();
                break;
            case 8:
                telaExcluirItem();
                break;
            default:
                printf("Opcao Invalida\n");
                break;
        } 
     
    } while (escolha != 0);

    return escolha;

}


char telaManuItens(void)
{
    char esc;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | ----------------- SIG-Pantry - MENU ITENS --------------- | \n");
    printf(" |                                                           | \n");
    printf(" |                 1- Nome do produto                        | \n");
    printf(" |                 2- Nome da marca                          | \n"); 
    printf(" |                 3- Codigo de barras                       | \n"); 
    printf(" |                 4- Data de validade                       | \n");   
    printf(" |                 5- Categoria do produto                   | \n"); 
    printf(" |                 6- Local de armazenamento                 | \n");
    printf(" |                 7- Atualizar itens                        | \n");
    printf(" |                 8- Excluir itens                          | \n");                 
    printf(" |                 0- Voltar a tela principal                | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao: ");
    scanf("%c", &esc);
    getchar();

    return esc;

}

char telaNomeProduto(void)
{
    char nomeProduto [20];
    char esc;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | --------------------- NOME DO PRODUTO ------------------- | \n");
    printf(" |                                                           | \n");    
    printf(" |  1- Informe o nome do produto: ");
    scanf("%[A-Z a-z]", nomeProduto);
    getchar(); 
    printf(" |  0- Voltar a tela de cadastro \n");
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

char telaNomeMarca(void)
{
    char nomeMarca [20];
    char esc;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | --------------------- NOME DA MARCA --------------------- | \n");
    printf(" |                                                           | \n");    
    printf(" |  1- Informe o nome da marca: ");
    scanf("%[A-Z a-z]", nomeMarca);
    getchar(); 
    printf(" |  0- Voltar a tela de cadastro \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    scanf("%c", &esc); 
    getchar();
    return esc; 

}

char telaCodigoBarras(void)
{
    char codigoBarras [13];
    char esc;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | --------------------- CODIGO DE BARRAS ------------------ | \n");
    printf(" |                                                           | \n");    
    printf(" |  1- Informe o codigo de barras: ");
    scanf("%[A-Z a-z., 0-9., -]", codigoBarras);
    getchar(); 
    printf(" |  0- Voltar a tela de cadastro \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    scanf("%c", &esc); 
    getchar();
    return esc; 

}

char telaDatadeValidade(void)
{
    char dataValidade [13];
    char esc;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | --------------------- DATA DE VALIDADE ------------------ | \n");
    printf(" |                                                           | \n");    
    printf(" |  1- Informe a data de validade do produto (00/00/0000): ");
    scanf("%[0-9., /]", dataValidade);
    getchar(); 
    printf(" |  0- Voltar a tela de cadastro \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Press ENTER for exit... ");
    scanf("%c", &esc); 
    getchar();
    return esc; 

}

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
    printf(" |                 0- Voltar a tela principal                | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao: ");
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
    printf(" |                 1- Geladeira                              | \n");
    printf(" |                 2- Armario da cozinha                     | \n");
    printf(" |                 3- Armario da area de servico             | \n");  
    printf(" |                 4- Armario do banheiro                    | \n"); 
    printf(" |                 5- Guarda-roupa                           | \n");       
    printf(" |                 0- Voltar a tela de cadastro              | \n");
    printf(" |                                                           | \n");
    printf(" | ========================================================= | \n");
    printf(" | Escolha uma opcao: ");
    scanf("%c", &opcao);  
    
    return opcao;

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
    printf(" |   Atualizar nome: ");
    scanf("%[A-z a-z]", nome);
    getchar();
    printf(" |  Atualizar código de barras: ");
    scanf("%[0-9]", barras);
    printf(" |  Atualizar data de validade: ");
    scanf("%[0-9 / ]", data);
    getchar();
    printf(" |  Atualizar categoria: ");
    scanf("[A-Z a-z 0-9]", categoria);
    getchar();
    printf(" |  Atualizar local de armazenamento: ");
    scanf("%d", &armazenamento);
    getchar();
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
    printf(" | ----------------------- Excluir ITENS ------------------------ | \n");
    printf(" |                                                                | \n");
    printf(" | Digite o código de barra do produto: ");
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
