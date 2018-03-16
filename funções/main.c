//
//  Funções
//  Exercicio16_02
//
//  Created by Eduardo on 16/02/18.
//  Copyright © 2018 Eduardo. All rights reserved.
//  Dado dois números complexos quaisquer z1 = a + bi e z2 = c + di.

#include <stdio.h>

// Quantidade de numeros complexos
#define QTDNC 2

// Tipo Numero Complexo
typedef struct
{
    float real;
    float imaginaria;
} tipoNC;

void leNC(tipoNC *nc)
{
    float aux;
    printf("\nParte Real: ");
    scanf("%f", &aux);
    (*nc).real = aux;
    printf("Parte Imaginaria: ");
    scanf("%f", &aux);
    (*nc).imaginaria = aux;
}

void escreveNC(tipoNC nc)
{
    printf("\nNumero Complexo: ");
    if((nc.real != 0) || (nc.imaginaria != 0)) {
        printf("%.2f", nc.real);
    }
    
    if (nc.imaginaria != 0) {
        if ((nc.imaginaria > 0) && (nc.real != 0)) {
            printf(" + %.2f", nc.imaginaria);
        }else{
            printf("%.2f", nc.imaginaria);
        }
        printf("i");
    }
    printf("\n");
}

tipoNC somaNC(tipoNC a, tipoNC b)
{
    // z1 = a; z2 = b;
    tipoNC aux;
    aux.real = a.real + b.real;
    aux.imaginaria = a.imaginaria + b.imaginaria;
    
    // z1 + z2 = (a + c) + (b + d)i.
    return aux;
}

tipoNC produtoNC(tipoNC a, tipoNC b)
{
    tipoNC aux;
    aux.real = ((a.real * b.real) + (a.imaginaria * b.imaginaria));
    aux.imaginaria = ((a.real * b.imaginaria) + (a.imaginaria * b.real));
    
    // Portanto, z1 x z2 = (ac + bd) + (ad + bc)I.
    return aux;
}

// Dois números complexos serão iguais se, E SOMENTE SE, respeitarem a seguinte condição:
// Partes imaginárias iguais
// Partes reais iguais
// http://brasilescola.uol.com.br/matematica/oposto-conjugado-igualdade-numeros-complexos.htm
int igualNC(tipoNC a, tipoNC b)
{
    if ((a.real == b.real) && (a.imaginaria == b.imaginaria)) {
        return 1;
    } else {
        return 0;
    }
}
 
tipoNC opostoNC(tipoNC nc)
{
    tipoNC aux;
    printf("Invertendo sinais..");
    aux.real = -1 * nc.real;
    aux.imaginaria = -1 * nc.imaginaria;
    
    return aux;
}

// Para obter um numero conjugado APENAS trocamos o sinal da parte imaginária do número,
// A parte real permanece igual e as imaginárias são simétricas.
// http://mundoeducacao.bol.uol.com.br/matematica/propriedades-conjugado.htm
void conjugadoNC(tipoNC variable)
{
    if (variable.imaginaria <= 0) {
        variable.imaginaria = -(variable.imaginaria);
    }else{
         variable.imaginaria = +(variable.imaginaria);
    }
    
    escreveNC(variable);
}

void main()
{
    int i;
    tipoNC vetNC[QTDNC];
    tipoNC sNC, pNC, oNC, cNC;
   
    for (i=0; i<QTDNC; i++) {
        printf("\n---------");
        printf("\nNumero Complexo %d", i+1);
        printf("\n---------");
        leNC(&vetNC[i]);
        escreveNC(vetNC[i]);
    }
    
    printf("\n---------");
    printf("\nSoma");
    sNC = somaNC(vetNC[0], vetNC[1]);
    escreveNC(sNC);
    printf("\n---------\n");
    
    printf("Produto");
    pNC = produtoNC(vetNC[0], vetNC[1]);
    escreveNC(pNC);
    
    printf("\n---------\n");
    printf("Igualdade");
    if (igualNC(vetNC[0], vetNC[1])){
        printf("\nNumeros Iguais");
    }else{
        printf("\nNumeros não Iguais");
    }
    
    printf("\n\n---------\n");
    printf("Oposto");
    for (i = 0; i < QTDNC; i++) {
        oNC = opostoNC(vetNC[i]);
        escreveNC(oNC);
    }
    
    
    printf("\n\n---------\n");
    printf("Conjugado");
    for (i = 0; i < QTDNC; i++) {
        cNC = vetNC[i];
        conjugadoNC(cNC);
    }
    
    
}
