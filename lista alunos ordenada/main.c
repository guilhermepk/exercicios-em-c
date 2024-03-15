/*
ToDo:
- [ ] Mudar de lista de alunos pra uma lista de numeros inteiros
- [ ] Criar uma função de adicionar por ordenação crescente
- [ ] Criar uma função que ordene uma lista ja criada de forma crescente
- [ ] Fazer o mesmo só que descresente
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct Aluno {
    char nome[100];
    float nota;
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

Aluno *criarAluno(char nome[], float nota){
    Aluno *novo = (Aluno*) malloc(sizeof(Aluno));
    if(!novo) {
        return NULL;
    }

    strcpy(novo->nome, nome);
    novo->nota = nota;
    novo->proximo = NULL;
    novo->anterior = NULL;

    return novo;
}

int listaVazia(Lista *lista){
    return (lista->inicio == NULL);
}

void inserirAlunoNaLista(Aluno *aluno, Lista *lista){
    if(listaVazia(lista)){
        lista->inicio = aluno;
        lista->fim = aluno;
    }else{
        lista->fim->proximo = aluno;
        aluno->anterior = lista->fim;
        lista->fim = aluno;
    }
}

void printarAlunosAprovados(Lista *lista){
    printf("\nAlunos aprovados:\n");
    Aluno *atual = lista->inicio;
    int algumAprovado = 0;
    while(atual != NULL){
        if(atual->nota >= 7){
            algumAprovado = 1;
            printf("Nome: %s\nNota: %.1f\n\n",  atual->nome, atual->nota);
        }
        atual = atual->proximo;
    }
    if (!algumAprovado) {
      printf("Nenhum aluno foi aprovado.\n");
    }
}

void printarAlunosReprovados(Lista *lista){
    printf("\nAlunos reprovados:\n");
    Aluno *atual = lista->inicio;
    int algumReprovado = 0;
    while(atual != NULL){
        if(atual->nota < 7){
            algumReprovado = 1;
            printf("Nome: %s\nNota: %.1f\n\n",  atual->nome, atual->nota);
        }
        atual = atual->proximo;
    }
    if (!algumReprovado) {
      printf("Todos os alunos foram aprovados!.\n");
    }
}

int main(){
    setlocale(LC_ALL,"Portuguese");
    system("cls");

    Lista *lista = criarLista();
    Aluno *a1 = criarAluno("Guilherme", 10);
    Aluno *a2 = criarAluno("Murilo", 3);
    Aluno *a3 = criarAluno("Diogo", 3);
    Aluno *a4 = criarAluno("João", 3);

    inserirAlunoNaLista(a1, lista);
    inserirAlunoNaLista(a2, lista);
    inserirAlunoNaLista(a3, lista);
    inserirAlunoNaLista(a4, lista);

    printarAlunosAprovados(lista);
    printarAlunosReprovados(lista);

    return 0;
}