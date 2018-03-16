//  main.c
//  Exercicio02_03
//
//  Created by Eduardo on 02/03/18.
//  Copyright © 2018 Eduardo. All rights reserved.
//

#include <stdio.h>

#define MAX 12

typedef int TChave;
typedef char TInfo[255];
typedef struct {
    TChave chave;
    TInfo info;
} TDado;
typedef TDado TVetor[MAX];

int busca(TChave x, TVetor v, int n){
    int i;
    // Busca linear
    i = 0;
    while ((i < n) && (v[i].chave != x)) {
        i++;
    }
    return i;
    
    /*
    // Busca linear com dado binario
    int i;
    i = 0;
    while ((i < n) && (v[i].chave < x)) {
        i++;
    }
    return ((i < n) && (v[i].chave == x) ? (i) : (n));*/
    
    /* Busca Binaria
    int esq, dir, meio;
    esq = 0;
    dir = n-1;
    while (esq < dir) {
        meio = (esq + dir) / 2;
        if (v[meio].chave < x) {
            esq = meio + 1;
        } else {
            dir = meio;
        }
    }
    return ((v[dir].chave == x) ? (dir) : (n));*/
}

int main() {
    FILE *arquivo;
    TVetor v;
    int n, pos, i;
    TChave x;
    
    printf("Abrindo Arquivo..\n");
    // RT = reading mode text OR WT = Writing mode text. RB = reading mode binary OR WB = Writing mode binary.
    arquivo = fopen("dados.txt", "rt");
    if(!arquivo){
        printf("Erro\n");
        return 1;
    }
    
    printf("Arquivo Aberto\n");
    printf("Carregando arquivo..\n");
    
    i = 0;
    
    while (!feof(arquivo) && i < MAX){
        fscanf(arquivo, "%d,%s", &v[i].chave, v[i].info);
        i++;
    }
    
    n = i;
    if(!feof(arquivo)){
        printf("Erro\n");
        return 1;
    }
    
    printf("Dados Carregados!\n");
    printf("Fechando arquivo..\n");
    fclose(arquivo);
    printf("Arquivo Fechado\n");

    do{
        printf("Digite a chave a ser buscada ou zero para sair: \n");
        scanf("%d", &x);
        if (x) {
            printf("Buscando..\n");
            pos = busca(x, v, n);
            if (pos == n) {
                printf("Chave não encontrada..\n");
            } else {
                printf("Chave %d encontrada na posição %d !", x,pos);
            }
            printf("fim da busca \n");
        }
    } while (x);

}
