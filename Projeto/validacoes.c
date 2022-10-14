#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "valiacoes.h"

/*int lerEmail(void)
{
/* o que é um e-mail invalido? 

Tem mais de um '@' ou nenhum
Tem somente numerais ou nada nos extremos de '@'
Tem 1 ou mais dots (.) em sequência ou seguido de '@'
Tem parte local [antes do '@'] de tamanho maior que 64 caracteres
Tem espaço "   "
Não tem caixa de entrada. 



}


int lerCPF(void)
{


}


int lerData(void)
{


}


int lerCodigoBarras(void)
{


} */


int lerNome(void)
{
    char tamanho;
    char i;
    char nome [20];
    tamanho = strlen(nome);
    if (tamanho > 1) {
        return 0;
    }
        for (int i = 0; i < tamanho; i++) {
            if (nome[i] == 'a' && nome[i] <= 'z') {
                return 0;
            }
            if (nome[i] == 'A' && nome[i] <= 'Z') {
                return 0;
            } 
            if (nome[i] == ' ') {
                return 0;  
            }         
            if (nome[i] == '.') {
                return 1;
            }
            if (nome[i] == ',') {
                return 1;
            }
            if (nome[i] == '/') {
                return 1;
            }
            if (nome[i] == ';') {
                return 1;
            }
            else {
                return 1;  
            }          
        }  
}
