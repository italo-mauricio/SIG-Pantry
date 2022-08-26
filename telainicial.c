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

#include<stdio.h>
#include<stdlib.h>
#include<locale.h> //necessário para usar setlocale (possibilita a acentuação)


int main(void) {

    setlocale(LC_ALL, "Portuguese");
    printf("___________________________________________________________\n");
    printf(" // UNIVERSIDADE FEDERAL DO RIO GRANDE DO NORTE - CERES // \n");
    printf(" //       DEPARTAMENTO DE COMPUTAÇÃO E TECNOLOGIA       // \n");
    printf("___________________________________________________________\n");
    printf(" //////////// Disciplina: DCT1106 - PROGRAMAÇÃO ///////////\n");
    printf(" /////////////////// Projeto: SIG-Pantry //////////////////\n");

    printf("<<<<<<<<<<<        Projeto: SIG-Pantry            >>>>>>>>>\n");


    system("pause");
    return 0;

}

