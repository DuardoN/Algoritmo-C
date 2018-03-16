//
//  main.c
//  13_003
//
//  Created by Eduardo on 13/03/18.
//  Copyright © 2018 Eduardo. All rights reserved.
//

#include <stdio.h>

void func(int value, int soma){
    int aux;
    
    if (value != 0) {
        aux = value % 10;
        soma = soma + aux;
        value = value / 10;
        func(value, soma);
    }else if(soma > 10){
        func(soma, 0);
    }else{
        printf("%d\n", soma);
    }
}

int main() {
    int n, soma = 0;
    
    while (scanf("%d", &n)) {
        if (n != 0) {
            func(n, soma);
        }else{
            break;
        }
        
    }
}
