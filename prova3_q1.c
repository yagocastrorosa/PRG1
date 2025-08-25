#include <stdio.h>

int inserir_string(char *p1, char *p2, int n) {

    char string1[50], string2[50]; //Strings auxiliares para copiarmos os valores dos vetores//
    int i=0, o=0, cont=0;

    //Loop para copiar tudo que está em p1 para uma string auxiliar//
    while (p1[o] != 0){
        string2[i++] = p1[o];
        p1[o++] = 0;
    }

    o = 0;
    i = 0;

    //Loop para copiar a quantidade de caracteres presentes na string2 (p1) para a string1, que será a principal//
    while (string2[o] != 0 && n-- > 0) {
        string1[i++] = string2[o];
        string2[o++] = 0;
    }

    //Loop para copiar o conteúdo de p2 para a string1. Vale ressaltar que este loop será ignorado caso o p2 seja nulo//
    if (p2 != NULL){
    while (*p2 != '\0')
        string1[i++] = *p2++;}

    //Loop para copiar o restante dos caracteres presentes na string2 (p1) para a string1//
    //String2 foi zerada no processo para que não ocorram problemas quando a função for chamada novamente//
    while (string2[o] != 0){
        string1[i++] = string2[o];
        string2[o++] = 0;
    }

    //Aqui é acrescentado um '\0' no final da string para que ela tenha um final//
    string1[i] = '\0';

    //O conteúdo presente na string1 será copiada para o ponteiro p1//
    //Neste loop a string1 será zerada para que não ocorram problemas quando a função for chamada novamente//
    while (string1[cont] != 0) {
        *p1++ = string1[cont];
        string1[cont++] = 0;
    }

    *p1 = '\0';

    //É retornado o valor inteiro contendo a quantidade de caracteres presentes na string//
    return i;
}

int main() {

    char alfa [50] = "Instituto de Santa Catarina";
    char beta [50] = "Ola, . Como você está hoje?";
    char gama [50] = "Bom dia, . Em que eu posso lhe ajudar?";
    int tamanho;

    tamanho = inserir_string(alfa, "Federal ", 10);
    printf ("%s %d\n", alfa, tamanho);

    tamanho = inserir_string(beta, NULL, 5);
    printf("%s %d\n", beta, tamanho);

    tamanho = inserir_string(gama, "Rogério", 9);
    printf("%s %d\n", gama, tamanho);

    return 0;
}