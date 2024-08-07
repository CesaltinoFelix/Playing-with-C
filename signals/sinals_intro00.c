#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
int number_to_guess;
int hints_given = 0;

void give_hint(int signum) {
    hints_given++;
    if (number_to_guess % 2 == 0) {
        printf("Hint %d: The number is even.\n", hints_given);
    } else {
        printf("Hint %d: The number is odd.\n", hints_given);
    }
}

void valor(int signum)
{
	printf("\nO valor e = %d\n", number_to_guess);
	exit(0);
}

int main() {
    // Obtenha o PID do processo
    pid_t pid = getpid();
    printf("PID do processo: %d\n", pid);

    // Registre o manipulador de sinais
    signal(SIGUSR1, give_hint);
    signal(SIGINT, valor);
    
    // Gere um número aleatório para adivinhar
    srand(time(NULL));
    number_to_guess = rand() % 100 + 1;

    int guess;
    while (1) {
        printf("Adivinhe o número (1-100): ");
        scanf("%d", &guess);

        if (guess == number_to_guess) {
            printf("Parabéns! Você adivinhou o número.\n");
            break;
        } else {
            printf("Palpite errado. Tente novamente.\n");
        }
    }

    return 0;
}
