/*
Desenvolva um código ou explique um programa
[x] que leia o peso e a altura de 7 pessoas, mostrando no final:

[x] Qual foi a média de altura do grupo
[x] Quantas pessoas pesam mais de 90Kg
[] Quantas pessoas que pesam menos de 50Kg tem menos de 1.60m
[] Quantas pessoas que medem mais de 1.90m pesam mais de 100Kg.
*/

// FEITO EM C NO VSCODE

#include <stdio.h>

typedef struct Pessoa {
    float peso;
    float altura;
} Pessoa;

float calcularAlturaMedia(Pessoa * lista, int tamanho){
    float total;
    for(int x = 0; x < tamanho; x++){
        total += (lista+x)->altura;
    }

    return (total / tamanho);
}

int maisPesadosQue(Pessoa * lista, int tamanho, float peso){
    int contador = 0;
    for(int x = 0; x < tamanho; x++){
        if( (lista+x)->peso > peso ){
            contador++;
        }
    }

    return contador;
}

int pesamMenosQueEMedemMenosQue(Pessoa * lista, int tamanho, float peso, float altura){
    int contador = 0;
    for(int x = 0; x < tamanho; x++){
        if( ((lista+x)->peso < peso) && ((lista+x)->altura < altura) ){
            contador++;
        }
    }

    return contador;
}

int pesamMaisQueEMedemMaisQue(Pessoa * lista, int tamanho, float peso, float altura){
    int contador = 0;
    for(int x = 0; x < tamanho; x++){
        if( ((lista+x)->peso > peso) && ((lista+x)->altura > altura) ){
            contador++;
        }
    }

    return contador;
}

int main(){
    int quantidade = 7;
    Pessoa pessoas[quantidade];

    for(int x = 0; x < quantidade; x++){
        Pessoa nova;

        printf("\nDigite o peso da pessoa %d: ", x+1);
        scanf("%f", &nova.peso);
        printf("Digite a altura da pessoa %d: ", x+1);
        scanf("%f", &nova.altura);

        pessoas[x] = nova;
    }

    float alturaMedia = calcularAlturaMedia(pessoas, quantidade);
    int tamanhoGrupo1 = maisPesadosQue(pessoas, quantidade, 90);
    int tamanhoGrupo2 = pesamMenosQueEMedemMenosQue(pessoas, quantidade, 50, 1.6);
    int tamanhoGrupo3 = pesamMaisQueEMedemMaisQue(pessoas, quantidade, 100, 1.9);

    printf("\n%.2f eh a altura media das pessoas.", alturaMedia);
    printf("\n%d pessoa(s) pesam mais que 90kg.", tamanhoGrupo1);
    printf("\n%d pessoa(s) pesam menos de 50kg e tem menos de 1.60m", tamanhoGrupo2);
    printf("\n%d pessoa(s) pesam mais de 100kg e tem mais de 1.90m", tamanhoGrupo3);
}