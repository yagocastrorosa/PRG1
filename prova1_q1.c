#include <stdio.h>

int main() {
  int f, x, a, b, i, fatorial, quantidade, contador;
  //f = F(x);
  //a = valor inicial do "range" de pontos que serão analisado;
  //b = valor final do "range" de pontos que serão analisados;
  //i = variável necessária para calcularmos o fatorial do número;
  //fatorial = resultado do cálculo fatorial;
  //quantidade = quantidade de pontos que foram analisados;
  //contador = quantidade de vezes em que foram encontrados pontos negativos em F(X);

printf("Seja bem-vindo(a) a calculadora da função F(x)=2(x!)-5.\nVocê irá escolher um intervalo de variação para 'x!' e a calculadora irá lhe dizer quantos números negativos foram encontrados para F(x) no intervalo escolhido.\n\n");

do{
printf("Entre com o valor de 'a':\n");
scanf("%d", &a);
if (a<0) printf("O valor de 'a' não pode sere negativo. Por gentileza digite um valor válido para 'a'.\n");}
while (a<0);
do{
printf("Entre com o valor de 'b':\n");
scanf("%d", &b);
if (b<a) printf("O valor de 'b' deve ser maior do que o de 'a'. Por gentileza digite um valor maior do que %d para 'b'.\n", a);}
while (b<a);

quantidade=b-a+1;
contador=0;

while (b>=a){
 a=a+1;
 for (fatorial=1;a<b;a=a+1){
 fatorial=fatorial*a;}
 f=2*fatorial-5;
 if (f<0) contador++;
 }

printf("Dos %d pontos analisados, %d deles produzem F(x) negativo.\n", quantidade, contador);

  return 0;
}