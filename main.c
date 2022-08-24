/*
Para a primeira semana deve-se fazer: 
Crie algumas telas com informações básicas sobre o seu projeto. O código que exibe essas telas deve estar em 
uma função diferente da função main() e deve ser chamada a partir desta. 
MÓDULO PRINCIPAL (NOME DO PROJETO, DISCIPLINA...)
MÓDULO SOBRE O QUE SE TRATA O PROJETO (RESUMO + EQUIPE)
MÓDULO PARA CADASTRAR OS ITENS EXISTENTES NA CASA POR CATEGORIA (ALIMENTOS, HIGIENTE PESSOAL E LIMPEZA)
MÓDULO PARA LISTAR OS ITENS QUE ESTÃO EM FALTA POR CATEGORIA
MÓDULO PARA EXIBIR OS ITENS QUE ESTÃO PRÓXIMOS DO PRAZO DE VENCIMENTO
MÓDULOS DOS ITENS COMPRADOS (ATUALIZAÇÃO)
MÓDULO RELATÓRIO
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

char telaInicial();


char main(telaInicial) {

    system("clear||cls"); 
    printf("| ---------------------------------------------------------------------- |\n");
    printf("| ----- // UNIVERSIDADE FEDERAL DO RIO GRANDE DO NORTE - CERES // ------ |\n");
    printf("| -------- // Departamento de Computacao e Informatica // ---------------|\n");
    printf("| ---------------------------------------------------------------------- |\n");
    printf("|               Disciplina: DCT1106 - PROGRAMACAO - 2022.2               |\n");
    printf("|          Projeto: Sistema de Controle de Despensa Domestica            |\n");
    printf("|            Colaboradores:  Manuelly Victor e Italo Mauricio            |\n"); 
    printf("|                  Docente: Dr Flavius Gorgonio                          |\n");
    printf("|                                                                        |\n");
    printf("| ---------------------------------------------------------------------- |\n");
    printf("| ---------------------- SIG - Pranty - 2022.2 ------------------------- |\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return "c";
   

}



char telaPrincipal(void){

    system("clear||cls"); 
    printf("| ====================================================================== |\n");
    printf("| ====                      SIG - Pranty                            ==== |\n");
    printf("| ====================================================================== |\n");
    printf("| ---------------------------------------------------------------------- |\n");
    printf("|                                                                        |\n");
    printf("|                      1 - Cadastrar Produtos                            |\n");
    printf("|                      2 -                                               |\n"); 
    printf("|                      3 -                                               |\n");
    printf("|                      4 - Sair                                          |\n");
    printf("|                                                                        |\n");
    printf("| ---------------------------------------------------------------------- |\n");
    printf("| ====================================================================== |\n");
    getchar();






}