#include <stdio.h>

//Função para calcular a média do vetor//
float media_vetor(int x[], int tam){
float media;
int i, soma = 0;

i = 0;
while (i<tam){
  soma = soma + x[i];
  i++;
}

media = soma /tam;

return media;
}


//Função que compara o tamanho dos vetores e retornará:
//0 => Caso a média dos vetores seja igual;
//1 => Caso a média do primeiro vetor seja menor do que a do segundo;
//-1 => Caso a média do primeiro vetor seja maior do que a do segundo;//
int compara_vetores(int x[], int y[], int tamanho){
float mediax, mediay;

mediax = media_vetor(x, tamanho);
mediay = media_vetor(y, tamanho);

if (mediax > mediay) return -1;
if (mediax < mediay) return 1;

return 0;
}


//Função principal do programa//
int main() {

  //Média de 'y' é menor do que a média de 'w', então função retornará 1;
  int y[3]={1, 5, 7}, w[3]={5, 9, 1};
  printf("Retorno %d\n", compara_vetores(y, w, 3));

  //Média de 'a' é maior do que a média de 'b', então função retornará -1;
  int a[5]={2, 4, 6, 8, 10}, b[5]={1, 2, 3, 4, 5};
  printf("Retorno %d\n", compara_vetores(a, b, 5));

  //Média de 'c' e 'd' são igual, então a função retornará 0;
  int c[3]={10, 1, 7}, d[3]={5, 6, 7};
  printf("Retorno %d\n", compara_vetores(c, d, 3));

  return 0;
}