#include <stdio.h>
#include <unistd.h>

#include <signal.h>


void displayProgressBar(int progress, int total) {
    int width = 50;
    float ratio = (float)progress / total;
    int filledWidth = ratio * width;

    printf("\r[");
    for (int i = 0; i < width; ++i) {
        if (i < filledWidth) {
            printf("\033[0;32m█\033[0m");
        } else {
            printf(" ");
        }
    }
    printf("] %d%%", (int)(ratio * 100));
    fflush(stdout);
}


void handler_bit_recived(int signum, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	static int client_pid = 0;
	static int counter = 0;
	static int n = 0;
	
	if(client_pid != info->si_pid)
	{
		counter = 0;
		n = 0;
	
	}
	client_pid = info->si_pid;
	
	if(signum == SIGUSR1)
	{
		n = n * 2 + 1;	
		if(kill(client_pid, SIGUSR1) == -1)
		{
			write(1, "ERROR\n", 5);
		};
	}
	else
	{
		n = n * 2 + 0;
		if(kill(client_pid, SIGUSR2) == -1)
		{
			write(1, "ERROR\n", 5);
		};
	}
		
	counter++;
	
	if(counter == 8)
	{
		write(1, &n, 1);
		counter = 0;
		n = 0;	

	}
	
}

int main(void)
{
	printf("\nSTARTING SERVER...\n");
	usleep(1000);
	int total = 100; 
	for (int i = 0; i <= total; ++i) {
		displayProgressBar(i, total);
		usleep(15000);
	}
	
	printf("\nDone!\n");
	printf("Ola eu sou o Cesaltino Felix 😀, seja bem-vindo ao meu servidor!\n");	
	printf("Server PID: %d\n", getpid());
	
	struct sigaction action;
	action.sa_sigaction = handler_bit_recived;
	action.sa_flags = SA_SIGINFO; 
	
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while(1)
	{
		pause();	
	}
	
	return 0;
}

