/*
EX1
Considerando duas pilhas P1 e P2 que contêm números inteiros,
desenvolva um programa que inclua as seguintes funcionalidades:

- Implemente uma função para verificar se as pilhas P1 e P2 são idênticas.

- Se diferirem, identifique qual das duas pilhas possui maior quantidade de elementos.

- Crie uma função que determine e retorne o valor máximo, mínimo e a média dos números contidos em uma determinada pilha.

- Desenvolva uma função que permita mover elementos da pilha P1 para a pilha P2 (funcionalidade de cópia).

- Elabore uma função que calcule e retorne a quantidade de números ímpares em uma pilha específica.

- Projete uma função que identifique e conte quantos elementos de uma pilha têm valores pares.
*/

#include <stdio.h>

typedef struct Pilha {
    int topo;
    int capacidade;
    int *pElemento;
} Pilha

Pilha *criarPilha(int capacidade){
    Pilha *novaPilha = (Pilha *) malloc(sizeof(Pilha));
    
    novaPilha->topo = -1;
    novaPilha->capacidade = capacidade;
    novaPilha->pElemento = (int *) malloc(capacidade * sizeof(int));
    
    return novaPilha;
}

int main(){
    printf("Hello World");

    return 0;
}
