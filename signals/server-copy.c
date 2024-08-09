#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <signal.h>

void displayProgressBar(int progress, int total)
{
	int width = 50; // Largura da barra de progresso
	float ratio = (float)progress / total;
	int filledWidth = ratio * width;

	printf("\r[");
	for (int i = 0; i < width; ++i)
	{
		if (i < filledWidth)
		{
			printf("\033[0;32m█\033[0m"); // Cor verde para a parte preenchida
		}
		else
		{
			printf(" ");
		}
	}
	printf("] %d%%", (int)(ratio * 100));
	fflush(stdout);
}

void* show_preloader(void* arg)
{
	while (1)
	{
		printf("\rCarregando   ");
		fflush(stdout);
		usleep(500000);

		printf("\rCarregando.");
		fflush(stdout);
		usleep(500000);

		printf("\rCarregando..");
		fflush(stdout);
		usleep(500000);

		printf("\rCarregando...");
		fflush(stdout);
		usleep(500000);
	}
	return NULL;
}

void handler_bit_recived(int signum)
{
	static int counter = 0; // Inicializa o contador
	static int n = 0;       // Inicializa o valor

	if (signum == SIGUSR1)
		n = n * 2 + 1;
	else
		n = n * 2 + 0;

	counter++;
	if (counter == 8)
	{
		int character = n;
		write(1, &character, 1);
		counter = 0;
		n = 0; // Reinicia o valor de `n` após imprimir o caractere
	}
}

int main(void)
{
	pthread_t preloader_thread;

	// Cria a thread que executa o preloader
	if (pthread_create(&preloader_thread, NULL, show_preloader, NULL) != 0)
	{
		perror("Erro ao criar a thread do preloader");
		return 1;
	}

	// Processo principal continua executando outras tarefas
	sleep(2);

	printf("\nSTARTING SERVER...\n");
	usleep(1000000); // 1 segundo de pausa antes da barra de progresso

	int total = 100; // Total de passos
	for (int i = 0; i <= total; ++i)
	{
		displayProgressBar(i, total);
		usleep(15000); // Dorme por 15 milissegundos
	}

	// Termina a thread do preloader
	pthread_cancel(preloader_thread);
	pthread_join(preloader_thread, NULL); // Espera a thread terminar

	printf("\nDone!\n");
	printf("Ola eu sou o Cesaltino Felix 😀, seja bem-vindo ao meu servidor!\n");
	printf("Server PID: %d\n", getpid());

	// Configura sinais para o servidor
	signal(SIGUSR1, handler_bit_recived);
	signal(SIGUSR2, handler_bit_recived);

	// Mantém o servidor rodando
	while (1)
	{
		pause(); // Aguarda por sinais
	}

	return 0;
}
