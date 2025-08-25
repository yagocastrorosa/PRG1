#include <stdio.h>

//Função responsável por calcular a média geral da matriz e com isto calcular a média da primeira diagonal principal, porém apenas considerando os valores acima da média geral//
float media_matriz(float mat[5][5]){
float media_geral=0, soma_geral=0, soma_matriz=0, media_matriz=0;
int l=0, c=0, x=0, cont=0;

for (l=0; l<5; l++){
  for(c=0; c<5; c++){
    soma_geral = soma_geral + mat[l][c];}
}

  media_geral = soma_geral /25;

for (x=0; x<5; x++){
  if(mat[x][x]>media_geral){
  soma_matriz = soma_matriz + mat[x][x];
  cont++;}
}
  
  media_matriz = soma_matriz /cont;

  return media_matriz; 
}


//Função adicional responsável por calcular a média dos números presentes na coluna 2, porém apenas aqueles que estejam abaixo da média da diagonal principal//
float media_coluna(float matriz[5][5]){
  float media_c, soma_c=0;
  int contador=0, a, b=1;
  float diagonal;

  diagonal = media_matriz(matriz);

  for (a=0; a<5; a++){
    if (matriz[a][b]<diagonal){
      soma_c = soma_c + matriz[a][b];
      contador++;}
  }

  media_c = soma_c /contador;

  return media_c;
}


//Função principal do sistema//
int main() {
  float media, media_col;
  float m[5][5]={1, 2, 3, 4, 5,
                 6, 7, 8, 9, 10,
                 11, 12, 13, 14, 15,
                 16, 17, 18, 19, 20,
                 21, 22, 23, 24, 25};

  media = media_matriz(m);
  printf("A média da soma da primeira diagonal principal da matriz é igual a %.2f.\n", media);

  //Neste caso a coluna será considerada como '2' pois estamos levando em conta que o usuário vê a primeira coluna como número'1', porém como a string inicia-se em '0' coloquei a coluna como '1' no código//
  media_col = media_coluna(m);
  printf("A média da soma dos valores presentes na coluna 2 e que sejam menores do que %.2f é igual a %.2f.\n", media, media_col);
  
  return 0;
}