#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *convert_to_bits(char c, int pid)
{
	int i;
	i = 8;
	unsigned char bit;
	
	while (i--)
	{
		bit = (c >> i & 1);
		if(bit)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(800);
	}
	
}

int main(int argc, char **argv)
{
	int i = 0;
	
	while(argv[2][i])
	{	
		convert_to_bits(argv[2][i], atoi(argv[1]));
		i++;
	}
}

