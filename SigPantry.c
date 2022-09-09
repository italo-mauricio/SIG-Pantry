#include <stdio.h>
#include <stdlib.h>
#include "modulocadastroUsuario.h"
#include "modulocadastroItem.h"
#include "modulolistadeCompras.h"
#include "moduloRelatorio.h"


// Assinatura das funções
char  telaPrincipal (void);
void  telaSobre (void);

char telaPrincipal(void)

{
    char opcao;
    system ( " clear||cls " );
    printf (" | =================================================================== | \n");
    printf (" | =========================| SIG - Pranty |========================== | \n");
    printf (" | =================================================================== | \n");
    printf (" | ------------------------------------------------------------------- | \n");
    printf (" |                                                                     | \n");
    printf (" |                        1 - Cadastrar usuario                        | \n");
    printf (" |                        2 - Cadastrar itens                          | \n");
    printf (" |                        3 - Lista de compras                         | \n");
    printf (" |                        4 - Relatorio                                | \n");
    printf (" |                        5 - Informacoes                              | \n");
    printf (" |                        0 - Sair                                     | \n");
    printf (" |                                                                     | \n");                                                                      
    printf (" | ------------------------------------------------------------------- | \n");
    printf (" | =================================================================== | \n");
    printf (" | Escolha uma opcao:                                                  | \n");
    printf (" | =================================================================== | \n");
    scanf ( "%c", &opcao);
    getchar();

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
    printf ("\t\t\t>>> Tecle <ENTER> para continuar...                              | \n " );
    getchar();

}