#include <stdio.h>

void clear() {
    printf("\033[2J"); 
    printf("\033[%d;%dH", 0, 0); 
}