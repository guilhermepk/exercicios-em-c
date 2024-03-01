#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// STRUCTS //

typedef struct Tarefa {
    char* pString;
    struct Tarefa* pTarefaAbaixo;
} Tarefa;

typedef struct Pilha {
    Tarefa* pTarefaTopo;
} Pilha;

// FUNÇÕES DA STRUCT PILHA //

Pilha* criarPilha(){
    Pilha* pilha = (Pilha *) malloc(sizeof(Pilha));
    pilha->pTarefaTopo = NULL; 
    return pilha;
}

int pilhaVazia(Pilha* pilha){
    return (pilha->pTarefaTopo == NULL) ? 1 : 0;
}

void empilhar(Pilha* pilha,  Tarefa* tarefa){
    tarefa->pTarefaAbaixo = pilha->pTarefaTopo;
    pilha->pTarefaTopo = tarefa;
}

Tarefa* desempilhar(Pilha* pilha){
    Tarefa* tarefaDesempilhada = pilha->pTarefaTopo;
    pilha->pTarefaTopo = pilha->pTarefaTopo->pTarefaAbaixo;
    return tarefaDesempilhada;
}

Tarefa* topoDaPilha(Pilha* pilha){
    return pilha->pTarefaTopo;
}

// FUNÇÕES DA STRUCT TAREFA //

Tarefa* criarTarefa(char* string){
    Tarefa* tarefa = (Tarefa *) malloc(sizeof(Pilha));
    tarefa->capacidade = 255;
    tarefa->pString = string;
}

void excluirTarefa(Tarefa* tarefa){
    free(tarefa);
}

// FUNÇÕES GERAIS //

void encerrarSistema(int* varControle){
    *varControle = 0;
}

// MAIN //
int main(){
    int rodando = 1;
    char option;

    //char stringTarefa[255];

    while(rodando == 1){
        printf("\nGERENCIADOR DE TAREFAS 2000\n");
        printf("    1 - Inserir nova tarefa\n");
        printf("    2 - Obter última tarefa cadastrada\n");
        printf("    3 - Encerrar sistema\n");

        // fgets(option, 1,  stdin);
        scanf("%c",  &option);

        switch(option) {
            case '1' || '2' ||'3':
                printf("Opção válida");
                encerrarSistema(&rodando);
                break;
            default:
                printf("Opção inválida");
        }
    }
    return 0;
}
