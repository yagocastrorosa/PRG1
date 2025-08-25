#include <stdio.h>
#include <string.h>

typedef struct {
    char nome [100];
    unsigned int matricula;
} tipo_aluno;

typedef struct {
    char titulo [100];
    char autor [100];
    unsigned int matricula_aluno;
} tipo_livro;

//Estrutura contendo as informações dos alunos. Será utilizada pela função 'encontrar_aluno'//
tipo_aluno alunos[5] = {
        {"Maria", 155},
        {"Joao", 167},
        {"Jose", 313},
        {"Lara", 211},
        {"Silvana", 417},
};

//Estrutura contendo as informações dos livros. Será utilizada pela função 'encontrar_livro'//
tipo_livro livros[5] = {
        {"Macbeth", "Shakespeare",0},
        {"Dom Casmurro", "Machado de Assis", 0},
        {"Iracema", "José de Alencar", 0},
        {"Os Sertões", " Euclides de Cunha", 0},
        {"2001: Uma Odisseia no Espaço", "Arthur C. Clarke", 0},
};

//Função destinada a verificar se o livro foi encontrado na estrutura 'livros' ou não. Caso seja encontrado retornará o índice do livro e caso não for retornará 'NULL'//
tipo_livro *encontrar_livro(char *titulo){

    int i, LivroSistema = 1;
    //LivroSistema será igual a '0' caso tenha encontrado o livro no sistema e '1' caso não tenha sido encontrado//

    for (i=0; i<5 && LivroSistema; i++)
        if (strcmp(titulo, livros[i].titulo)==0)
            LivroSistema = 0;

    if (LivroSistema == 0){
        i--;
        return &livros[i];}
    else return NULL;

}

//Função destinada a verificar se o aluno foi encontrado na estrutura 'alunos' ou não. Caso seja encontrado retornará o índice da matrícula e caso não for retornará 'NULL'//
tipo_aluno *encontrar_aluno(unsigned int matricula){


    int i, AlunoSistema = 1;
    //AlunoSistema será igual a '0' caso tenha encontrado a matrícula no sistema e '1' caso não tenha sido encontrado//

    for (i=0; i<5 && AlunoSistema; i++){
        if (matricula==alunos[i].matricula)
            AlunoSistema = 0;
    }

    if (AlunoSistema == 0){
        i--;
        return &alunos[i];}
    else return NULL;

}

//Funçao que verificara se o aluno ja possui um livro emprestado ou nao//
int verificar_emprestados(unsigned int matricula){

    int i, EmprestimoAluno = 1;

    for (i=0; i<5 && EmprestimoAluno; i++){
        if (matricula == livros[i].matricula_aluno)
            EmprestimoAluno = 0;
    }

    if (EmprestimoAluno == 0)
        return 0;
    else return 1;

}

//Ira chamar cada uma das funções e retornará um inteiro para a funçao main//
int emprestar_livro(char *livro, unsigned int matricula){

    tipo_aluno *p1;
    tipo_livro *p2;
    int emprestados = 0;

    p1 = encontrar_aluno(matricula);
    p2 = encontrar_livro(livro);
    emprestados = verificar_emprestados(matricula);


    if (p2 == NULL)
        return 1;

    if (p2->matricula_aluno != 0)
        return 2;

    if (p1 == NULL)
        return 3;

    if (emprestados == 0)
        return 4;

    if (p1 != NULL && p2 != NULL && emprestados == 1) {
        p2->matricula_aluno = matricula;
        return 0;
    }

}

//Funçao destinada a operar a devoluçao dos livros//
int devolver_livro(char *titulo){

    tipo_livro *p;

    p = encontrar_livro(titulo);

    if (p != NULL){
        p->matricula_aluno = 0;
        return 5;}
    else return 6;

}


int main() {
    char livro[100] = "Macbeth"; unsigned int matricula = 155;
    char livro2[100] = "Macbeth"; unsigned int matricula2 = 167;
    char livro3[100] = "2001: uma viagem ao espaço"; unsigned int matricula3 = 313;
    char livro4[100] = "Macbeth"; unsigned int matricula4 = 155;
    int emprestar= 0;
    int devolver = 0;


    //Primeiro empréstimo: Usuário conseguirá emprestar o livro com sucesso//
    emprestar = emprestar_livro(livro, matricula);
    if (emprestar==0)
        printf("\nO livro '%s' foi emprestado com sucesso!\n", livro);
    if (emprestar==1)
        printf("\nO livro '%s' não existe.\n", livro);
    if (emprestar==2)
        printf("\nO livro '%s' já está emprestado.\n", livro);
    if (emprestar==3)
        printf("\nNão foi possível encontrar nenhum aluno cadastrado com a matrícula %d\n", matricula);
    if (emprestar==4)
        printf("\nVocê já possui um livro emprestado!\n");

    //Segundo empréstimo: Usuário tentará pegar emprestado um livro que já  está com outra pessoa. Cairá no terceiro cenário//
    emprestar = emprestar_livro(livro2, matricula2);
    if (emprestar==0)
        printf("\nO livro '%s' foi emprestado com sucesso!\n", livro2);
    if (emprestar==1)
        printf("\nO livro '%s' não existe.\n", livro2);
    if (emprestar==2)
        printf("\nO livro '%s' já está emprestado.\n", livro2);
    if (emprestar==3)
        printf("\nNão foi possível encontrar nenhum aluno cadastrado com a matrícula %d\n", matricula2);
    if (emprestar==4)
        printf("\nVocê já possui um livro emprestado!\n");

    //Terceiro empréstimo: Usuário irá digitar o título do livro incorretamente. Cairá no segundo cenário//
    emprestar = emprestar_livro(livro3, matricula3);
    if (emprestar==0)
        printf("\nO livro '%s' foi emprestado com sucesso!\n", livro3);
    if (emprestar==1)
        printf("\nO livro '%s' não existe.\n", livro3);
    if (emprestar==2)
        printf("\nO livro '%s' já está emprestado.\n", livro3);
    if (emprestar==3)
        printf("\nNão foi possível encontrar nenhum aluno cadastrado com a matrícula %d\n", matricula3);
    if (emprestar==4)
        printf("\nVocê já possui um livro emprestado!\n");

    devolver = devolver_livro(livro4);
    if (devolver==5)
        printf("\nO livro %s foi devovido com sucesso!\n", livro4);
    else printf("\nNão foi possível devolver o livro.\n");

    return 0;
}
