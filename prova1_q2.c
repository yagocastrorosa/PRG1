#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int dado1, dado2, soma, tentativa, palpite;
  //dado1 = valor da face do primeiro dado;
  //dado2 = valor da face do segundo dado;
  //soma = soma das faces dos dados 1 e 2;
  //tentativa = número de tentativas que o usuários teve;
  //palpite = valor inserido pelo usuário para tentar descobrir a soma dos dados;

printf("Bem-vindo(a) ao jogo dos dados!\nDois dados com faces de 1 até 6 serão jogados e você precisará advinhar qual é a soma destes dados em até 5 tentativas.\n\nOs dados foram jogados.");

srand(time(NULL));
dado1 = (1 + rand()%6); //Gerando número randômico entre 1 e 6;
dado2 = (1 + rand()%6);
soma=dado1+dado2;
tentativa=0;

do { printf("\nEscolha um número que é equivalente a soma da face dos dois dados:\n");
scanf("%d", &palpite);
tentativa++;

if(soma<palpite && tentativa<5)
printf ("\nO número secreto é menor\n");
else {
if (soma>palpite && tentativa<5) 
printf ("O número secreto é maior\n");}
} while (soma!=palpite && tentativa<5);
if (tentativa>=5) printf("\nVocê excedeu o número máximo de tentativas e por conta disso perdeu o jogo. Tente novamente mais tarde!\n\nValor do primeiro dado = %d;\nValor do segundo dado = %d;\nSoma dos dados = %d;\n", dado1, dado2, soma);

if(soma==palpite) printf("\nParabéns, você ganhou! Você advinhou que a soma dos dados era %d!\nPara isto você usou um total de %d tentativas!\n\nValor do primeiro dado = %d;\nValor do segundo dado = %d;\n", soma, tentativa, dado1, dado2);
}