#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int ft_strlen(const char *str)
{
	int	i;
	i = 0;
	while(str[i])
		i++;
	return (i);
}

void handler_bit_recived(int signum) {
    static int counter = 0;
    static int n = 0;

    if (signum == SIGUSR1)
        n = n * 2 + 1;    
    else
        n = n * 2 + 0;
        
    counter++;

    if (counter == 8) {
        write(1, &n, 1);
        counter = 0;
        n = 0;    
    }
}

void convert_to_bits(char c, int pid) {
    int i = 7; 
    unsigned char bit;
    
    while (i >= 0) {
        bit = (c >> i) & 1;
        if (bit) {
            if (kill(pid, SIGUSR1) == -1) {
                write(2, "Error sending SIGUSR1\n", 23);
                exit(EXIT_FAILURE);
            }
        } else {
            if (kill(pid, SIGUSR2) == -1) {
                write(2, "Error sending SIGUSR2\n", 23);
                exit(EXIT_FAILURE);
            }
        }
        i--;
        usleep(500); 
    }
}

void eg_usage(char *str) {
    const char *usage_msg = "Usage: ";
    const char *msg = "Usage: ./client <PID> <message>\n";
    write(2, usage_msg, 7);
    write(2, str, ft_strlen(str));
    write(2, msg, ft_strlen(msg));
}

void invalid_pid(char *str) {
    const char *error_msg = "Easy boy 😀... Your PID must be a (INTEGER) positive value.\n";
    write(2, error_msg, ft_strlen(error_msg));
    eg_usage(str);
}

int main(int argc, char **argv) {
    signal(SIGUSR1, handler_bit_recived);
    signal(SIGUSR2, handler_bit_recived);
    
    if (argc != 3) {
        eg_usage(argv[0]);
        return EXIT_FAILURE;
    }
    
    int pid = atoi(argv[1]);
    int i = 0;
    
    if (pid <= 0) {
        invalid_pid(argv[0]);
        return EXIT_FAILURE;
    }
    while (argv[2][i]) {    
        convert_to_bits(argv[2][i], pid);
        i++;
    }
    convert_to_bits('\n', pid);
    
    return EXIT_SUCCESS;
}

