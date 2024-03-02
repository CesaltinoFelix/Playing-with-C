#include <stdio.h>
#include "lib_aritimetica/aritimetica.c"
#include <ctype.h>

int main(){

    int a, b;
    float r;
    char c;

    printf("Digite o primeiro valor: ");
    scanf("%d", &a);

    printf("\nDigite o segundo valor: ");
    scanf("%d", &b);


    printf("\nDigite a operacao (+, -, * ou /): ");
    scanf(" %c", &c);
    switch(c){
        case '+': r = soma(a, b);
        break;
        case '-': r = subtracao(a, b);
        break;
        case '/': r = divisao(a, b);
        break;
        case '*': r = multiplicacao(a, b);
        break;
        default: return printf("OPERACAO INVALIDA!!!");

    }

    printf("\nResultado: %.2f", r);

    }
    return 0;
}
