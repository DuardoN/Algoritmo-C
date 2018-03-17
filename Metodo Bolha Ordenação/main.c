//
//  main.c
//
//  Created by Eduardo on 16/03/18.
//  Copyright © 2018 Eduardo. All rights reserved.
//
//  Ordenação método Bolha

#include <stdio.h>

#define DEBU 0
#define MAX 100

typedef int TChave;
typedef char TInfo[255];
typedef struct {
    TChave chave;
    TInfo info;
} TDado;
typedef TDado TVetor[MAX];

void mostra(TVetor v, int n){
    int i;
    printf("\n-----\n");
    for (i = 0; i < n; i++) {
        printf("%d: %d %s\n", i, v[i].chave, v[i].info);
    }
    printf("\n-----\n");
}

void ordena(TVetor v, int n){
    int i, j;
    TDado x;
    
    mostra(v, n);
    for (i = 1; i < n; i++) {
        for (j = n-1; j >= i ; j--) {
            // Ordem Decrescente. Caso queira deixar Crescente, mudar apenas o sinal de '<' para '>'
            if (v[j-1].chave < v[j].chave) {
                x = v[j-1];
                v[j-1] = v[j];
                v[j] = x;
            }
            mostra(v, n);
        }
    }
    mostra(v, n);
}

int main() {
    FILE *arquivo;
    TVetor v;
    int n, i;

    // Carregar arquivo
    printf("\nAbrindo arquivo..");
    arquivo = fopen("dados.txt", "rt");
    if (!arquivo) {
        printf("\nErro!\n");
        return 1;
    }
    printf("\nArquivo aberto!\n");
    
    // Carregar dados
    printf("\nCarregando Dados...\n");
    i = 0;
    while (!feof(arquivo) && i < MAX) {
        fscanf(arquivo, "%d, %s", &v[i].chave, v[i].info);
        i++;
    }
    n = i;
    if (!feof(arquivo)) {
        printf("\nErro!\n");
        return 1;
    }
    printf("\nDados Carregados!\n");
    
    // Fechar arquivo
    printf("\nFechando arquivo...");
    fclose(arquivo);
    printf("\nFechando aberto!\n");
    
    // Chamar metodo de ordenação
    printf("\nOrdenando...");
    ordena(v, n);
    printf("\nOrdenado!\n");
    
    // Carregar arquivo
    printf("\nAbrindo arquivo..");
    arquivo = fopen("dados.txt", "rt");
    if (!arquivo) {
        printf("\nErro!\n");
        return 1;
    }
    printf("\nArquivo aberto!\n");
    
    // Salvar dados
    printf("\nSalvando Dados...\n");
    for (i = 0; i < n; i++) {
        fprintf(arquivo, "%d, %s", v[i].chave, v[i].info);
        if (i < (n-1)) fprintf(arquivo, "\n");
    }
    printf("\nDados Salvos!\n");
    
    // Fechar arquivo
    printf("\nFechando arquivo..");
    fclose(arquivo);
    printf("\nArquivo fechado!\n");
    
}
