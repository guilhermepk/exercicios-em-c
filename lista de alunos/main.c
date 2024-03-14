/*
Desenvolva um programa para registrar 5 estudantes, incluindo para cada um
- o nome
- e a nota final.
Guarde esses dados em uma lista duplamente encadeada sem ordenação.
Posteriormente, o programa deve exibir os nomes dos estudantes que foram aprovados, isto é, aqueles que obtiveram nota final igual ou superior a 7. 
Caso não haja nenhum estudante aprovado, o programa deve exibir uma notificação específica.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno {
    char nome[100];
    int nota;
    struct Aluno *proximo;
    struct Aluno *anterior;
} Aluno;

typedef struct Lista {
    Aluno *inicio;
    Aluno *fim;
} Lista;

Lista *criarLista(){
    Lista *nova = (Lista*) malloc(sizeof(Lista));
    if (!nova) return NULL;
    nova->inicio = NULL;
    nova->fim = NULL;
    return nova;
}

Aluno *criarAluno(){
    Aluno *novo = (Aluno*) malloc(sizeof(Aluno));
    if(!novo) return NULL;
    novo->proximo = NULL;
    novo->anterior = NULL;
    return novo;
}

int main(){
    system("cls");

    Lista *lista = criarLista();
    Aluno *a1 = criarAluno();

    return 0;
}