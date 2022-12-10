#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacoes.h"
#include <time.h>


//------------------------------------------------------------------//
//                       Validação de Email                         //
//                                                                  //
// Código by: https://pt.stackoverflow.com/users/110948/rogério-dec //
//------------------------------------------------------------------//


// retorna 0 se for false e 1 se for true

int lerEmail(char email[])
{
  int tam=strlen(email);
  int arroba = 0, ponto = 0, antesPonto = 0, depoisPonto = 0, i;

  for (i = 0; i < tam; i++) {
    char c = email[i];
    if(c == '@') {
      if (arroba)
         break; // não pode ter uma segunda @
      arroba++;
      if (i < 3)
        break; // se @ vier antes de 3 caracteres, erro
    }
    else if (arroba) { // se já encontrou @
      if (ponto) { // se já encontrou . depois de @@
        depoisPonto++;
      }
      else if(c == '.') {
        ponto = 1;
        if (antesPonto < 3) {
          break; // se . depois de @ vier antes de 3 caracteres, erro
        }
      }
      else {
        antesPonto++;
      }
    }
  } // for

    if (i == tam && depoisPonto > 1)
        return 1;
    else
        return 0;

}


// --------------------------------------- |
//        Validação de Username            |
// --------------------------------------  |


int lerUsername(char username[]) 
{
  int tamanho = strlen(username);   
  if (tamanho < 4) { //para não ter usuários com só: @ ou a@ ou 12... 
    return 0;
  } else {
    for (int i = 0; i < tamanho; i++) { 
      if ((username[i] == 'a') && (username[i] <= 'z')) { 
        return 0;
      }
      else if ((username[i] == 'A') && (username[i] <= 'Z')) {
        return 0;
      }
      else if ((username[i] == '_') || (username[i] == '-')) {
        return 0;
      }
      else if ((username[i] == '@') || (username[i] == '.')) {
        return 0;
      }
      else if ((username[i] == '0') && (username[i] <= 9)) {
        return 0;
      }   
      else {
        break;  
      }     
    }

    }
    return 1; 
    
} 


// --------------------------------------- |
//        Validação de Letras              |
// --------------------------------------  |


int validarLetras(char letra[], int tamanho){

    char alfabeto[54]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','V','W','X','Y','Z',' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    int cont=0;

    for(int x=0; letra[x] != '\0'; x++){
        for( int y=0;y<=53;y++){
            if(letra[x] == alfabeto[y]){
                cont++;
            }
        }
    }
    if (tamanho==cont){
        return 0;
    }else{
        return 1;
    }
}

int tamanhoString(char a[]){
    int cont;

    for(int i=0; a[i] != '\0'; i++){
        cont++;
    }

    return cont;
}

int lerLetras(char nome[])
{

  int tamanho = strlen(nome);

  if (tamanho < 1) {
      return 0; 
  } else {
      for (int i = 0; i <= (tamanho - 1); i++) 
        if ((nome[i] <= 'z') && (nome[i] >= 'A'))
        {
           if (((nome[i] <= 'a') && (nome[i] <= 'Z')) || (nome[i] == ' ')) {
            return 1;
           }
              if((nome[i] == '@') || (nome[i] == 0) || (nome[i] <= 9)) {
                return 0;
              }
            } else{  
              return 0;
      
              }          
      }
      return 1;    
  }

int meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char decimais[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};



//----------------------------------------------------------------------------------//
//                                  Validação de data                              //
//                                                                                 //
//  Código by: https://www.vivaolinux.com.br/script/Funcao-para-validacao-de-datas //
//---------------------------------------------------------------------------------//


int valida_data(int dia, int mes, int ano) 
    {
    if ((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1900 && ano <= 2100)) //verifica se os numeros sao validos
        {
            if ((dia == 29 && mes == 2) && ((ano % 4) == 0)) //verifica se o ano e bissexto
            {
                return 1;
            }
            if (dia <= 28 && mes == 2) //verifica o mes de feveireiro
            {
                return 1;
            }
            if ((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) //verifica os meses de 30 dias
            {
                return 1;
            }
            if ((dia <=31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes ==8 || mes == 10 || mes == 12)) //verifica os meses de 31 dias
            {
                return 1;
            }
            else
            {
                return 0;
            }
      }
       else
           {
                return 0;
           }
}


// ---------------------------------------- |
//        Validação de números              |
// ---------------------------------------  |

  
int lerQuantidade(char numero[])
{
  int tamanho = strlen(numero);

  if (tamanho < 1) {
      return 0; 
  } else {
      for (int i = 0; i <= (tamanho - 1); i++) 
        if ((numero[i] <= '9') && (numero[i] >= '0'))
        {
              if((numero[i] == '@') || (numero[i] == '.') || (numero[i] == ';')) {
                return 1;
              }
            } else{  
              return 0;      
              }          
      }

      return 1;
}


void deixarTelaLimpa(void) //adaptada by @flgorgonio
{
  if(system("clear") || system("cls")) {
  }
  
}


 int charParaInt(char *num) {
    int soma = 0;
    int tam = strlen(num);
    int aux = tam - 1; 

    if (tam == 1) {
        return num[0] - '0';

    }

    for (int i = 0; i <= tam - 1; i++) {
        
        soma = soma + ((num[i] - '0') * poten(10, aux));

        aux = aux - 1;

    }

    return soma;

}

int poten(int num, int pot) {
    int soma = num;

    if (pot == 0) {
        return 1;
    }

    else if (pot == 1) {
        return num;
    }

    for (int i = 2; i <= pot; i++ ) {
        soma = soma * num;
        
    }

    return soma;

}


// Função inspirado no de Dayane


char* verDiaMesAno(void) {

 
    char* data = (char*) malloc(20 * sizeof(char));

    time_t tempo = time(NULL);

    struct tm* t = localtime(&tempo);

    strftime(data, 50, "%d/%m/%y", t);

    // dia, mes, ano

    return data;

}