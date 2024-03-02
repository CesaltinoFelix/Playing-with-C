#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


// Função para verificar se o jogador acertou na dezena do numero sorteado
int acertouDezena(int numeroApostado, int numeroSorteado) {
    return (numeroApostado / 10) == (numeroSorteado / 10);
}

// Função para verificar se o jogador acertou na unidade do numero sorteado
int acertouUnidade(int numeroApostado, int numeroSorteado) {
    return (numeroApostado % 10) == (numeroSorteado % 10);
}

// Função para verificar se o jogador acertou na soma dos dígitos do numero sorteado
int acertouSomaDigitos(int numeroApostado, int numeroSorteado) {
    return ((numeroSorteado / 10) + (numeroSorteado % 10)) == numeroApostado;
}

// Função principal
int main() {
    srand(time(NULL));

    int totalPrejuizo = 0;
    int totalLucro = 0;
    int jogada = 1;

    while (1) {
        int valorApostado, numeroApostado;
        printf("Digite o valor em Kwanzas para a aposta (0 para sair): ");
        scanf("%d", &valorApostado);

        if (valorApostado == 0) {
            break;
        }

        printf("Digite o numero apostado (entre 1 e 50): ");
        scanf("%d", &numeroApostado);

        int numeroSorteado = rand() % 50 + 1;

        printf("\nJogada %d\n", jogada);
        printf("Quantia Apostada: KZ %.2f\n", (float)valorApostado);
        printf("Numero Apostado: %d\n", numeroApostado);
        printf("Numero Sorteado: %d\n", numeroSorteado);

        int premio = 0;

        if (numeroApostado == numeroSorteado) {
            premio = 5 * valorApostado;
            printf("Jogador acertou no numero sorteado ganhou: KZ %.2f\n", (float)premio);
            totalLucro += premio;
        } else if (numeroApostado == ((numeroSorteado / 10)  + (numeroSorteado % 10))) {
            premio = 3 * valorApostado;
            printf("Jogador acertou no numero sorteado na ordem inversa ganhou: KZ %.2f\n", (float)premio);
            totalLucro += premio;
        } else if (acertouDezena(numeroApostado, numeroSorteado)) {
            premio = 2 * valorApostado;
            printf("Jogador acertou na dezena do numero sorteado ganhou: KZ %.2f\n", (float)premio);
            totalLucro += premio;
        } else if (acertouUnidade(numeroApostado, numeroSorteado)) {
            premio = 2 * valorApostado;
            printf("Jogador acertou na unidade do numero sorteado ganhou: KZ %.2f\n", (float)premio);
            totalLucro += premio;
        } else if (acertouSomaDigitos(numeroApostado, numeroSorteado)) {
            premio = 2 * valorApostado;
            printf("Jogador acertou na soma dos dígitos do numero sorteado ganhou: KZ %.2f\n", (float)premio);
            totalLucro += premio;
        } else if ((numeroApostado % 2 == 0 && numeroSorteado % 2 == 0) ||
                   (numeroApostado % 2 != 0 && numeroSorteado % 2 != 0)) {
            printf("Jogador acertou na paridade do numero sorteado: nao ganhou nem lucrou\n");
        } else {
            printf("Jogador nao acertou perdeu: KZ %.2f\n", (float)valorApostado);
            totalPrejuizo += valorApostado;
        }

        printf("Ate agora o Jogador lucrou: KZ %.2f\n", (float)totalLucro);
        printf("Ate agora o Jogador perdeu: KZ %.2f\n", (float)totalPrejuizo);
        jogada++;
    }

    printf("\nApos %d jogadas, o jogador ganhou KZ %.2f\n", jogada - 1, (float)(totalLucro - totalPrejuizo));

    return 0;
}
