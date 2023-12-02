#include <stdio.h>


int main(){

    int tamanho;

    printf("Digite o tamanho para o vetor:: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    for(int i = 0; i < tamanho; i++){
        scanf("%d", &vetor[i]);
    }

    int *ponteiroVetor = &vetor;

    for(int i = 0; i < tamanho; i++){
        printf("\n Posicao : %d - Endereco: %p - Valor: %d", i, (void*)ponteiroVetor, *ponteiroVetor);
        ponteiroVetor++;
    }
 return 0;
}
