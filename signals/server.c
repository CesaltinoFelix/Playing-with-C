#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


void displayProgressBar(int progress, int total) {
    int width = 50; // Width of the progress bar
    float ratio = (float)progress / total;
    int filledWidth = ratio * width;

    printf("\r[");
    for (int i = 0; i < width; ++i) {
        if (i < filledWidth) {
            printf("\033[0;32m█\033[0m"); // Green color for the filled part
        } else {
            printf(" ");
        }
    }
    printf("] %d%%", (int)(ratio * 100));
    fflush(stdout);
}


void handler_bit_recived(int signum)
{
	static int counter;
	static int n;
	
	if(signum == SIGUSR1)
		n = n * 2 + 1;
	else
		n = n * 2 + 0;

	counter++;
	if(counter == 8)
	{
		int character = n;
		write(1, &character, 1);
		counter = 0;	
	}
			
}

int main(void)
{
	printf("\nSTARTING SERVER...\n");
	usleep(1000);
	int total = 100; // Total steps
	for (int i = 0; i <= total; ++i) {
		displayProgressBar(i, total);
		usleep(15000); // Sleep for 50 milliseconds
	}
	printf("\nDone!\n");
	printf("Ola eu sou o Cesaltino Felix 😀, seja bem-vindo ao meu servidor!\n");	
	printf("Server PID: %d\n", getpid());
	
	
	while(1)
	{
		signal(SIGUSR1, handler_bit_recived);
		signal(SIGUSR2, handler_bit_recived);
		pause();	
	}
	
	return 0;
}

