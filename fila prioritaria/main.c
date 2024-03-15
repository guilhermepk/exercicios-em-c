/*
ToDo:
- [ ] Criar uma fila de pessoas prioritária por idade
    1. Acima de 60 anos
    2. Entre 30 e 59 anos
    3. Menos de 15 anos
    4. Entre 15 e 30 anos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa {
    char nome[100];
    int idade;
    struct Pessoa *proximo;
} Pessoa;

typedef struct Fila {
    Pessoa *inicio;
    Pessoa *fim;
} Fila;

Pessoa *criarPessoa(char nome[], int idade){
    Pessoa *nova = (Pessoa*) malloc(sizeof(Pessoa));
    if(!nova) return NULL;

    strcpy(nova->nome, nome);
    nova->idade = idade;
    nova->proximo = NULL;
    return nova;
}

Fila *criarFila(){
    Fila *nova = (Fila*) malloc(sizeof(Fila));
    if(!nova) return NULL;

    nova->inicio = NULL;
    nova->fim = NULL;
    return nova;
}

int filaVazia(Fila *fila){
    return (fila->inicio == NULL);
}

void inserirPessoaNaFila(Pessoa *pessoa, Fila *fila){
    /*
    1 - Verificar se a fila ta vazia
        sim:
            inicio e fim de fila = pessoa
        nao:
            1.1 - Verificar a idade da pessoa
                >= 60:
                    Pessoa *atual = fila->inicio;
                    if(atual->idade < 60){
                        fila->inicio = pessoa;
                        pessoa->proximo = atual;
                        return;
                    }else if(atual == fila->fim){
                        atual->proximo = pessoa;
                        fila->fim = pessoa;
                        return;
                    }else{
                        int inserido = 0;
                        while( (atual->proximo != NULL) && (inserido == 0) ){
                            if(atual->proximo->idade < 60){
                                pessoa->proximo = atual->proximo;
                                atual->proximo = pessoa;
                                return;
                            }
                            atual = atual->proximo;
                        }
                    }
                >= 30:
                    grupo 2
                < 15:
                    grupo 3
                < 30 (else):
                    grupo 4
    */
}

int main(){
    return 0;
}