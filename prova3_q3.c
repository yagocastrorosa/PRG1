#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265359

//
struct retangular{
    double r, i;
};

struct polar{
    double mod, ang;
};

struct polar converter_polar (struct retangular a)
{
    struct polar aux;

    aux.mod = sqrtf(powf(a.r,2) + powf(a.i,2));
    aux.ang = atan(a.i/a.r)*(180/PI);

    return aux;
}

struct polar funcao_potencia (struct polar b,double expoente){

    struct polar aux2;
    double cosseno, seno, potencia;
    double mult1;

    potencia = powf(b.mod,expoente); //Cálculo da potência do módulo//
    mult1 = b.ang * expoente; //Cálculo do ângulo multiplicado pelo valor do expoente//

    mult1 = mult1 * (PI/180);

    cosseno = cos(mult1);
    seno = sin(mult1);

    aux2.mod = potencia * cosseno; //Cálculo para descobrir o valor do número real//

    aux2.ang = potencia * seno; //Cálculo para descorbri o valor do número imaginário//

    return aux2;

}

int main(int argc, char *argv[]) {

    struct retangular x;
    struct polar y, expoente;
    double n = 2;

    if (argc==4){
    x.r = atof(argv[1]);
    x.i = atof(argv[3]);

    //Condição foi criada para caso o usuário insira um número imaginário negativo//
    if(*argv[2] == '-')
        x.i = (x.i * -1);

    y = converter_polar(x);
    expoente = funcao_potencia(y, n);

    if (expoente.ang<0){
        expoente.ang = (expoente.ang * -1);
    printf("%.2f - i%.2f", expoente.mod, expoente.ang);}
    else printf("%.2f + i%.2f", expoente.mod, expoente.ang);}

    else printf("\nDevem ser passados 3 parâmetros!\n");

    return 0;
}
