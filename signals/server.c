#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


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
		character_in_bits[8] = '\0';
		int character = n;
		write(1, &character, 1);
		counter = 0;	
	}
			
}

int main(void)
{
	printf("Ola eu sou o Cesaltino😀!\n");	
	printf("Server PID: %d\n", getpid());
	
	
	while(1)
	{
		signal(SIGUSR1, handler_bit_recived);
		signal(SIGUSR2, handler_bit_recived);
		pause();	
	}
}

