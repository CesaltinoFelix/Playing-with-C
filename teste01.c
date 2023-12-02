#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(){

    char senha[50];
    int temM = 0, temm = 0, temN = 0;

    printf("Digite a senha:: ");
    gets(senha);
    printf("\n%s\n", senha);

    int tamanho = strlen(senha);

    if(tamanho < 8)
        return printf("A SENHA DEVE CONTER PELO MENOS 8 CARACTERES!!!");

    for(int i = 0; i < tamanho; i++){

        if(isupper(senha[i]))
            temM = 1;

        if(islower(senha[i]))
            temm = 1;

        if(isdigit(senha[i]))
            temN = 1;

    }

        if(temM == 0)
        return printf("A SENHA DEVE CONTER PELO MENOS UMA LETRA MAUISCULA!!!");

        if(temm == 0)
        return printf("A SENHA DEVE CONTER PELO MENOS UMA LETRA MINUSCULA!!!");
    system("pause");
    return 0;

}
