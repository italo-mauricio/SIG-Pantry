#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

// Assinatura das funções
char  telaPrincipal (void);
void  telaSobre (void);
void moduloCadastro(void);
char telaCadastroItens(void);
char telaListadeCompras(void);

int  main (void)
{
    char opcao;
    do {
        opcao = telaPrincipal();
        switch (opcao) {
        /* case '1':
            telaCadastroUsuario();
            parar;
        case '2':
            telaCadastroItens();
            break; */
        case  '3':
            telaListadeCompras();
            break;
        case '4':    
            telaSobre ();
            break;
        defaut :
            printf ('Opcao invalida \n');
            break;      
        }  while (opcao != '0');

    }

    return  0 ;
}

char telaListadeCompras(void)
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | -------------------| SIG-Pantry - LISTA DE COMPRAS |---------------- | \n");
    printf(" |                                                                      | \n");
    printf(" | ------------------ 1- Itens próximo ao vencimento ------------------ | \n");
    printf(" | ------------------ 2- Cadastrar item de higiene pessoal ------------ | \n"); 
    printf(" | ------------------ 3- Cadastrar item de limpeza -------------------- | \n");    
    printf(" | ------------------ 0- Voltar a tela principal ---------------------- | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opcao:                                                   | \n");
    printf(" | ==================================================================== | \n");
    scanf("%c", &opcao);

    return opcao;

}


char telaCadastroItens(void)
{
    char opcao;
    system ( " clear||cls " );
    printf(" | ==================================================================== | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | -------------------| SIG-Pantry - CADASTRAR ITENS |----------------- | \n");
    printf(" |                                                                      | \n");
    printf(" | ------------------ 1- Cadastrar item alimentar --------------------- | \n");
    printf(" | ------------------ 2- Cadastrar item de higiene pessoal ------------ | \n"); 
    printf(" | ------------------ 3- Cadastrar item de limpeza -------------------- | \n");    
    printf(" | ------------------ 0- Voltar a tela principal ---------------------- | \n");
    printf(" | -------------------------------------------------------------------- | \n");
    printf(" | ==================================================================== | \n");
    printf(" | Escolha uma opcao:                                                   | \n");
    printf(" | ==================================================================== | \n");
    scanf("%c", &opcao);

    return opcao;

}

// TELA CADASTRO USUÁRIO AQUI

char  telaPrincipal ( void )

{
    char opcao;
    system ( " clear||cls " );
    printf ( " | ================================================================== | \n " );
    printf ( " | ========================| SIG - Pranty |========================== | \n " );
    printf ( " | ================================================================== | \n " );
    printf ( " | ------------------------------------------------------------------ | \n " );
    printf ( " |                                                                    | \n " );
    printf ( " |                       1 - Cadastrar usuario                        | \n " );
    printf ( " |                       2 - Cadastrar itens                          | \n " );
    printf ( " |                       3 - Lista de compras                         | \n " );
    printf ( " |                       4 - Informacoes                              | \n " );
    printf ( " |                       0 - Sair                                     | \n " );
    printf ( " |                                                                    | \n " );                                                                      
    printf ( " | ------------------------------------------------------------------ | \n " );
    printf ( " | ================================================================== | \n " );
    printf ( " | Escolha uma opcao:                                                 | \n " );
    printf ( " | ================================================================== | \n " );
    scanf ( " %c " , &opcao);

    return opcao;

}

void  telaSobre ( void )
{
    system ( " clear||cls " );
    printf ( " | ------------------------------------------------------------------ | \n " );
    printf ( " | ---- // UNIVERSIDADE FEDERAL DO RIO GRANDE DO NORTE - CERES // --- | \n " );
    printf ( " | -------- // Departamento de Computação e Informática // ---------- | \n " );
    printf ( " | ------------------------------------------------------------------ | \n " );
    printf ( " |                                                                    | \n " );                                       
    printf ( " |            Disciplina: DCT1106 - PROGRAMAÇÃO - 2022.2              | \n " );
    printf ( " |         Projeto: Sistema de Controle de Despensa Doméstica         | \n " );
    printf ( " |                    Docente: Dr Flavius Gorgonio                    | \n " );
    printf ( " |                                                                    | \n " );
    printf ( " |  Este programa consiste no controle das atividades de uma despensa | \n " );
    printf ( " |    doméstica, sendo dividida em categorias no intuito de ajudar na | \n " );
    printf ( " |                organização das atividades cotidianas.              | \n " );
    printf ( " |             Equipe: Manuelly Rodrigues e Italo Mauricio            | \n " );
    printf ( " |                                                                    | \n " );
    printf ( " | ------------------------------------------------------------------ | \n " );
    printf ( " | ---------------------- SIG - Pranty - 2022.2 --------------------- | \n " );
}