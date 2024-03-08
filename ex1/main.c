/*
EX1
Considerando duas pilhas P1 e P2 que contêm números inteiros,
desenvolva um programa que inclua as seguintes funcionalidades:

- [x] Implemente uma função para verificar se as pilhas P1 e P2 são idênticas.

- [x] Se diferirem, identifique qual das duas pilhas possui maior quantidade de elementos.

- [ ] Crie uma função que determine e retorne o valor
    - [x] máximo
    - [x] mínimo
    - [ ] média 
    dos números contidos em uma determinada pilha.

- [ ] Desenvolva uma função que permita mover elementos da pilha P1 para a pilha P2 (funcionalidade de cópia).

- [ ] Elabore uma função que calcule e retorne a quantidade de números ímpares em uma pilha específica.

- [ ] Projete uma função que identifique e conte quantos elementos de uma pilha têm valores pares.
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct Pilha {
    int topo;
    int capacidade;
    int *pElemento;
} Pilha;

Pilha *criarPilha(int capacidade){
    Pilha *novaPilha = (Pilha *) malloc(sizeof(Pilha));
    
    novaPilha->topo = -1;
    novaPilha->capacidade = capacidade;
    novaPilha->pElemento = (int *) malloc(capacidade * sizeof(int));
    
    return novaPilha;
}

int pilhaVazia(Pilha *pilha){
    return (pilha->topo == -1) ? 1 : 0;
}

void empilhar(Pilha *pilha, int valor){
    pilha->topo++;
    pilha->pElemento[pilha->topo] = valor;
}

int *desempilhar(Pilha *pilha){
    if(pilhaVazia(pilha)){
        return NULL;
    }else{
        int *valor = pilha->pElemento+pilha->topo;
        pilha->topo--;
        return valor;
    }
}

int pilhasIdenticas(Pilha *p1, Pilha *p2){
    int p1Vazia = pilhaVazia(p1);
    int p2Vazia = pilhaVazia(p2);

    if(
        (p1->capacidade != p2->capacidade)
        ||
        (p1->topo != p2->topo)
        ||
        (p1Vazia != p2Vazia)
    ){
        return 0;
    }else if(p1Vazia == 1 && p2Vazia == 1){
        return 1;
    }else{
        for(int x = 0; x < p1->capacidade; x++){
            if( p1->pElemento[p1->topo] != p2->pElemento[p2->topo] ){
                return 0;
            }
        }
    }

    return 1;
}

Pilha *maiorPilha(Pilha *p1, Pilha *p2){
    if(p1->topo == p2->topo){
        return NULL;
    }else{
        if(p1->topo > p2->topo){
            return p1;
        }else{
            return p2;
        }
    }
}

void imprimirIdenticasOuMaior(Pilha *p1, Pilha *p2){
    if(pilhasIdenticas(p1, p2)){
        printf("Identicas\n");
    }else{
        Pilha *maior = maiorPilha(p1, p2);
        if(maior == NULL){
            printf("Nao ha maior pilha\n");
        }else{
            (maior == p1) ? printf("P1 eh a maior pilha") : printf("P2 eh a maior pilha");
        }
    }
}

int maiorValorDaPilha(Pilha *pilha){
    int max = pilha->pElemento[pilha->topo];

    for(int x = 0; x < pilha->topo+1; x++){
        if(pilha->pElemento[x] > max){
            max = pilha->pElemento[x];
        }
    }

    return max;
}

int menorValorDaPilha(Pilha *pilha){
    int min = pilha->pElemento[pilha->topo];

    for(int x = 0; x < pilha->topo+1; x++){
        if(pilha->pElemento[x] < min){
            min = pilha->pElemento[x];
        }
    }

    return min;
}

float mediaDosValoresDaPilha(Pilha *pilha){
    int quantidade = pilha->topo+1;
    int total;

    for(int x = 0; x < quantidade; x++){
        total += pilha->pElemento[x];
    }

    float media = ((float)total) / ((float)quantidade);

    printf("\n%d / %d = %f", total, quantidade,  media);

    return (total / quantidade);
}

int main(){
    setlocale(LC_ALL,"Portuguese");
    system("cls");

    Pilha *p1 = criarPilha(5);
    Pilha *p2 = criarPilha(5);

    empilhar(p1, 1);

    empilhar(p2, 10);
    empilhar(p2, 5);

    imprimirIdenticasOuMaior(p1, p2);

    printf("\n%d eh o maior valor da pilha p2", maiorValorDaPilha(p2));
    printf("\n%d eh o menor valor da pilha p2", menorValorDaPilha(p2));
    printf("\n%.2f eh a media dos valores da pilha p2", mediaDosValoresDaPilha(p2));

    return 0;
}
