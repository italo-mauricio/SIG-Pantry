#include <stdio.h>


void clear() {
    printf("\033[2J");  // imprime o caractere de controle para limpar a tela
    printf("\033[%d;%dH", 0, 0);  // posiciona o cursor no topo da tela
}