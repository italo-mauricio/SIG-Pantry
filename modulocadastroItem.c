#include<stdio.h>
#include<stdlib.h>
#include "modulocadastroItem.h"

char modulocadastroItem(void) {
    int escolha;
    do {
        escolha = telaCadastroItens();
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
        } 
     
    } while (escolha != 0);

    return escolha;

}


char telaCadastroItens(void)
{
    char esc;
    system ( " clear||cls " );
    printf(" | ========================================================= | \n");
    printf(" | --------------------------------------------------------- | \n");
    printf(" | -------------- SIG-Pantry - CADASTRAR ITENS ------------- | \n");
    printf(" |                                                           | \n");
    printf(" |                 1- Nome do produto                        | \n");
    printf(" |                 2- Nome da marca                          | \n"); 
    printf(" |                 3- Codigo de barras                       | \n"); 
    printf(" |                 4- Data de validade                       | \n");   
    printf(" |                 5- Categoria do produto                   | \n"); 
    printf(" |                 6- Local de armazenamento                 | \n");                 
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
    printf(" | --------------------- NOME DA MARCA --------------------- | \n");
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
