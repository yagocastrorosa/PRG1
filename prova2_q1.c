#include <stdio.h>
#include <string.h>

//Função responsável por concatenar a segunda string no início da primera bem como retornar o tamanho completo desta string//
int concat_str(char str1[], char str2[]){
  int a, e, i, tamanho;
  char aux[50];

  a = strlen(str1);
  e = strlen(str2);
  strcpy(aux, str1);
  tamanho = a + e;

  for (i=0; i<e; i++){
  str1[i] = str2[i];
  }

  for (i=0; i<a; i++)
  str1[e+i] = aux[i];

  return tamanho;

}

//Função principal do sistema//
int main() {
  
  char x[50]="sj";
  int tam;
  tam = concat_str(x, "ifsc-");
  printf("A string %s tem tamanho %d.\n", x, tam);
  return 0;
}