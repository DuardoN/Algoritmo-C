//
//  main.c
//  Exercicio23_02
//
//  Created by Eduardo on 23/02/18.
//  Copyright © 2018 Eduardo. All rights reserved.


// Exercicio 1 - Recursão
#include <stdio.h>
int soma(int numero) {
    if (numero > 1 ) {
        return numero + soma(numero - 1) ;
    } else {
        return 1;
    }
}

void main() {
    int numero;
    int aux;

    printf("Digite um numero");
    scanf("%i", &numero);

    aux = soma(numero);
    printf("total: %i", aux);
}

// Exercicio 2 - TorreHanoi
void moveDisco(char origem, char destino){
    printf("%c -> %c\n", origem, destino);
}

void torreHanoi(int altura, char origem, char destino, char trabalho){
    if (altura==1) {
        moveDisco(origem, destino);
        return;
    }
    // Aqui faremos a retirada do primeiro disco e movemos ele.
    torreHanoi(altura-1,origem,trabalho,destino);
    // Aqui acontece o movimento.
    moveDisco(origem, destino);
    // Aqui novamente é retirado mais um disco o ciclo continua.
    torreHanoi(altura-1,trabalho,destino,origem);
}

void main(){
    int n;
    printf("\Digite a altura da torre: ");
    scanf("%d", &n);
    torreHanoi(n, 'A', 'B', 'C');
    
    
}
